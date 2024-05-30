#pragma once

char* getFileName();
char* getRequestFileName();

int serialiseRoute(char * str, Route ^ route);

int validateDays(System::String^ days);
int validateSell(float price);
int validateNum(int num);
int isNumber(System::String^ str);
int isTime(System::String^ str);

void addRoute(char* fileName, Route^ route);
void changeRoute(char* fileName, Route^ route);
void deleteRoute(char* fileName, int routeNum);
void requestRoutes(char* fileName, char* requestFileName, Route^ reqParams,
	System::String^ compareSell, System::String^ compareTimeFrom, System::String^ compareTimeTo);


