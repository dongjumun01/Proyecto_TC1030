#pragma once
#ifndef DOCTOR_H
#define DOCTOR_H

#include <iostream>
#include <string>
#include <vector>
#include "DatoDePaciente.h"
#include "Empleado.h"

class Doctor:public Empleado
{
private: 
	vector<DatoDePaciente> datoDePaciente;
	int servicio;
public:
	Doctor();
	Doctor(string _userId, string _password); //overloading
	Doctor(string _userId, string _password, DatoDePaciente _datoDePaciente, int _servicio); //overloading
	void setServicio(int _servicio);
	int getServicio();
	vector<DatoDePaciente>& getDatoDePaciente();
	void agregarPaciente(DatoDePaciente _datoDePaciente);
	bool checaLogInfo(string _userId, string _password, int _servicio);
	void guradarInfoDePacientes(string _userId, string _password, int _servicio, DatoDePaciente _datoDePaciente);
	void guradarInfoDePago(string _userId, string _password, int _servicio, DatoDePaciente _datoDePaciente);
};

#endif
