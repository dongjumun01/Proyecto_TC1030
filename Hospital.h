/*
	La clase hospital define los objetos de apuntador de la clase abstracta Empelado con el constructor.
	Puede buscar los empleados y tiene getter de los empleado.
*/
#pragma once
#ifndef HOSPITAL_H

#include "Empleado.h"

using namespace std;

const int MAX = 100;

class Hospital
{
//Declaro variables de instancia
private:
	Empleado* empleado[MAX];//se define como apuntador para usar polimorfismo
	int index;
//Declaro el constructor y los metodos que va a tener el objeto
public:
	Hospital(); //crea los objetos en Empleado[]
	int getIndex();
	Empleado* getEmpleado(int);
	bool buscaEmpleado(string, string); //para buscar los datos
};

#endif // !HOSPITAL_H

