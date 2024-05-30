#pragma once
#include "MainForm.h"
#include "Route.h"
#include "DB.h"
#include <iostream>
#include <stdio.h>

#define MAX_ROUTE_LEN 77

using namespace System::Collections::Generic;



void Airportdatabase::MainForm::RefillGrid()
{
	FILE* routeDB = fopen(getFileName(), "r");

	if (routeDB == 0) return;
	rewind(routeDB);

	char* str = (char*)calloc(MAX_ROUTE_LEN, sizeof(char));
	Route^ route = gcnew Route();



	// Здесь работаем точно также как с strtok
	fgets(str, MAX_ROUTE_LEN, routeDB);
	while (serialiseRoute(str, route))
	{
		routes->Add(route);

		fgets(str, MAX_ROUTE_LEN, routeDB);
		route = gcnew Route();
	}
	fclose(routeDB);

	RoutesGrid->DataSource = routes;
}



