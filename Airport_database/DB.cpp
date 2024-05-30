#define _CRT_SECURE_NO_WARNINGS

#include "Route.h"

#include <iostream>
#include <stdio.h>
#include "DB.h"

#define MAX_ROUTE_LEN 77
#define ROUTE_PROPERTIES 7

#define TAG_NUM 0
#define TAG_PLANE 1
#define TAG_CITY 2
#define TAG_DAYS_OF_WEEK 3
#define TAG_TIME_FROM 4
#define TAG_TIME_TO 5
#define TAG_PRICE 6

/*
Разработка программного обеспечения для учета данных об авиарейсах № 3 Массив строк «Аэропорт»
1
3 boing777 Moscow 1256 10:30 10:50 16450
###

12 airbus230 Moscow 1256 14:10 14:20 6710
71 boing777 Moscow 125 6:45 6:55 1300
8 boing777 Novosibirsk 234 12:30 13:45 800
24 airbus230 Moscow 1256 21:35 21:50 7600
23 airbus230 Novosibirsk 1467 6:30 7:40 1940
52 boing777 Novosibirsk 2567 17:05 18:10 2500
###
*/


using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

char* getFileName()
{
	return "D:/Andrei/Отчеты/2 семестр/Программирование/летняя_практика/Airport_database/Airport_database/routeDB.txt";
}

char* getRequestFileName()
{
	return "D:/Andrei/Отчеты/2 семестр/Программирование/летняя_практика/Airport_database/Airport_database/request.txt";
}

int validateSell(float sell)
{
	return sell > 0;
}

int validateNum(int num)
{
	return num > 0;
}

int isNumber(String^ str)
{
	int len = str->Length;

	for (int i = 0; i < len; i++)
		if (!((str[i] >= '0' && str[i] <= '9') || str[i] == ','))
			return 0;
	
	return 1;
}

int isTime(String^ str)
{
	array<String^>^ timeArr = str->Split(':');

	if (timeArr->Length == 2)
	{
		if (isNumber(timeArr[0]) && isNumber(timeArr[1]))
		{
			int
				hour = Convert::ToInt32(timeArr[0]),
				minute = Convert::ToInt32(timeArr[1]);
			if (0 <= minute && minute < 60 && 0 <= hour && hour < 24)
				return 1;
			else 
				return 0;
		}
		
	}
	else
		return 0;
}

int validateDays(String^ days)
{
	int len = days->Length;
	
	
	if (len != 0)
	{
		for (int i = 0; i < len; i++)
		{
			if (days[i] < '1' || days[i] > '7') return 0;
			// дня недели не существует

			for (int j = 0; j < i; j++)
				if (days[i] == days[j]) return 0;
			// дни повторяются
		}	

		int intdays = Convert::ToInt32(days);
		if (intdays > 10000000 - 1 || intdays < 1) return 0;
	// дней больше чем есть в недели
	}
	return 1;
}


int serialiseRoute(char* str, Route^ route)
{
	int validData = 1;
	char* word = strtok(str, " ,");

	for (int property = 0; property < ROUTE_PROPERTIES; property++)
	{
		if (word == NULL)
		{
			validData = 0;
			//Error: bad input!
			break;
		}
		else
			switch (property) {
			case TAG_NUM: {
				route->Num = atoi(word);
				break;
			}
			case TAG_PLANE: {
				route->Plane = gcnew System::String(word);
				break;
			}
			case TAG_CITY: {
				route->City = gcnew System::String(word);
				break;
			}
			case TAG_DAYS_OF_WEEK: {
				route->Days= gcnew System::String(word);
				break;
			}
			case TAG_TIME_FROM: {
				route->TimeFrom = gcnew System::String(word);
				break;
			}
			case TAG_TIME_TO: {
				route->TimeTo = gcnew System::String(word);
				break;
			}
			case TAG_PRICE: {
				float price = atof(word);
				if (price && price > 0)
					route->Sell = price;
				else
					route->Sell = 0;
				break;
			}
			default:break;
			}
		word = strtok(NULL, " ,");
	}
	return validData;
}
// ввод рейсов
void addRoute(char* fileName, Route^ route)
{
	FILE* routeDB = fopen(fileName, "r+");
	if (routeDB == NULL) return;

	if (fseek(routeDB, 0, SEEK_END) == 0)
		fprintf(routeDB, "%.10d %10.10s %10.10s %10.10s %10.10s %10.10s %10.2f",
			route->Num, route->Plane, route->City, route->Days,
			route->TimeFrom, route->TimeTo, route->Sell);

	fclose(routeDB);
}

void changeRoute(char* fileName, Route^ route)
{
	char* routeStr = (char*)calloc(100, sizeof(char));
	Route^ curRoute = gcnew Route();

	int num, isFound;

	FILE* routeDB = fopen(fileName, "r+");
	if (routeDB == NULL) return;
	rewind(routeDB);

	fgets(routeStr, MAX_ROUTE_LEN, routeDB);
	while (serialiseRoute(routeStr, curRoute))
	{
		if (route->Num == curRoute->Num)
		{   // нашли маршрут который нужно изменить
			if (fseek(routeDB, -MAX_ROUTE_LEN + 1, SEEK_CUR) == 0)
				fprintf(routeDB, "%.10d %10.10s %10.10s %10.10s %10.10s %10.10s %10.2f",
					route->Num, route->Plane, route->City, route->Days,
					route->TimeFrom, route->TimeTo, route->Sell);
			break;
		}
		fgets(routeStr, MAX_ROUTE_LEN, routeDB);
	}
	fclose(routeDB);
}

void deleteRoute(char* fileName, int routeNum)
{
	const char deleteName[] = "routeDB_old.txt";
	char* str = (char*)calloc(MAX_ROUTE_LEN, sizeof(char));
	Route^ route = gcnew Route();

	int isFind;


	isFind = 0;

	int renameResult = rename(fileName, deleteName);

	FILE* oldRouteDB = fopen(deleteName, "r");
	FILE* newRouteDB = fopen(fileName, "w");
	if (oldRouteDB == NULL || newRouteDB == NULL || renameResult != 0) return;
	rewind(oldRouteDB);
	rewind(newRouteDB);

	fgets(str, MAX_ROUTE_LEN, oldRouteDB);
	while (serialiseRoute(str, route))
	{
		if (route->Num != routeNum) // копируем все, кроме которого хотим удалить
		{
			fprintf(newRouteDB, "%.10d %10.10s %10.10s %10.10s %10.10s %10.10s %10.2f",
				route->Num, route->Plane, route->City, route->Days,
				route->TimeFrom, route->TimeTo, route->Sell);
		}
		fgets(str, MAX_ROUTE_LEN, oldRouteDB);
	}

	fclose(newRouteDB);
	fclose(oldRouteDB);
	remove(deleteName);
}



int compareFloat(char* cmp, float p1, float p2)
{
	if (strcmp(cmp, ">") == 0) return p1 > p2;
	else if (strcmp(cmp, "<") == 0) return p1 < p2;
	else if (strcmp(cmp, ">=") == 0) return p1 >= p2;
	else if (strcmp(cmp, "<=") == 0) return p1 <= p2;
	else if (strcmp(cmp, "=") == 0) return p1 == p2;
	else return 0;
}
int compareTime(String^ cmp, String^ t1, String^ t2)
{
	array<String^>^ timeArr1 = t1->Split(':');
	array<String^>^ timeArr2 = t2->Split(':');
	int
		hour1 = Convert::ToInt32(timeArr1[0]),
		hour2 = Convert::ToInt32(timeArr2[0]),
		minute1 = Convert::ToInt32(timeArr1[1]),
		minute2 = Convert::ToInt32(timeArr2[1]);
	
	if (cmp == ">") return hour1 > hour2 || hour1 == hour2 && minute1 > minute2;
	else if (cmp == "<") return hour1 < hour2 || hour1 == hour2 && minute1 < minute2;
	else if (cmp == ">=") return hour1 > hour2 || hour1 == hour2 && minute1 >= minute2;
	else if (cmp == "<=") return hour1 < hour2 || hour1 == hour2 && minute1 <= minute2;
	else if (cmp == "=") return hour1 == hour2 && minute1 == minute2;
	else return 0;
}

int checkDay(int day, char days[10])
{
	int len = strlen(days);
	for (int i = 0; i < len; i++)
		if (day == int(days[i]) - 48)
			return 1;
	return 0;
}

int CompareIntByStr(String^ cmp, int p1, int p2)
{
	if (cmp == "<") return p1 < p2;
	else if (cmp == "<=") return p1 <= p2;
	else if (cmp == "=") return p1 = p2;
	else if (cmp == ">=") return p1 >= p2;
	else if (cmp == ">") return p1 > p2;
	else return 0;
}

int CompareFloatByStr(String^ cmp, float p1, float p2)
{
	if (cmp == "<") return p1 < p2;
	else if (cmp == "<=") return p1 <= p2;
	else if (cmp == "=") return p1 = p2;
	else if (cmp == ">=") return p1 >= p2;
	else if (cmp == ">") return p1 > p2;
	else return 0;
}


int isStrIncludeStr(String^ child, String^ parent)
{
	int childLen = child->Length,
		parentLen = parent->Length,
		flag = 1;
	
	for (int i = 0; i < childLen && flag == 1; i++)
	{
		flag = 0;
		for (int j = 0; j < parentLen && flag == 0; j++)
			if (child[i] == parent[j])
				flag = 1;
	}

	return flag;
}

void requestRoutes(char* fileName, char* requestFileName, Route^ reqParams, 
	String^ compareSell, String^ compareTimeFrom, String^ compareTimeTo)
{
	FILE* routeDB = fopen(fileName, "r+");
	if (routeDB == NULL) return;
	rewind(routeDB);

	FILE* requestRouteDB = fopen(requestFileName, "w");
	if (requestRouteDB == NULL) return;
	rewind(requestRouteDB);

	char* str = (char*)calloc(MAX_ROUTE_LEN, sizeof(char));
	Route^ route = gcnew Route();

	fgets(str, MAX_ROUTE_LEN, routeDB);
	while (serialiseRoute(str, route))
	{
		if (
			(reqParams->City == "" || reqParams->City == route->City) &&
			(reqParams->Plane == "" || reqParams->Plane == route->Plane) &&
			(reqParams->Days == "" || isStrIncludeStr(reqParams->Days, route->Days)) &&
			(reqParams->Num == -1 || route->Num == reqParams->Num) &&
			(reqParams->Sell == -1 || CompareFloatByStr(compareSell, route->Sell, reqParams->Sell)) &&
			(reqParams->TimeFrom == "" || compareTime(compareTimeFrom, route->TimeFrom, reqParams->TimeFrom)) &&
			(reqParams->TimeTo == "" || compareTime(compareTimeTo, route->TimeTo, reqParams->TimeTo))
		)
		{ // сохраняем в новый файл соответсвующие запросу рейсы
			fprintf(requestRouteDB, "%.10d %10.10s %10.10s %10.10s %10.10s %10.10s %10.2f",
				route->Num, route->Plane, route->City, route->Days,
				route->TimeFrom, route->TimeTo, route->Sell);
		}
		fgets(str, MAX_ROUTE_LEN, routeDB);
	}
	


	fclose(requestRouteDB);
	//remove(requestFileName);
	fclose(routeDB);
}