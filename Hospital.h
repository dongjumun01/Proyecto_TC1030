#pragma once
#ifndef HOSPITAL_H

#include "Empleado.h"

using namespace std;

const int MAX = 100;

class Hospital
{
private:
	Empleado* empleado[MAX] = {0};
	int index;

public:
	Hospital();
	int getIndex();
	Empleado* getEmpleado(int);
	bool buscaEmpleado(string, string); //para buscar los datos
};

#endif // !HOSPITAL_H

