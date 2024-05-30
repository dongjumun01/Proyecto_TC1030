#pragma once
#ifndef DOCTOR_H
#define DOCTOR_H

#include <string>
#include <vector>
#include <fstream>
#include "DatoDePaciente.h"
#include "Empleado.h"

class Doctor:public Empleado
{
private: 
	vector<DatoDePaciente> datoDePaciente;
	int servicio;
public:
	Doctor();
	Doctor(string _userId, string _password, string _nombre, string _tipo, int _servicio); //sobrecarga
	Doctor(string _userId, string _password, string _nombre, string _tipo, DatoDePaciente _datoDePaciente, int _servicio); //sobrecarga
	void setServicio(int _servicio);
	int getServicio();
	vector<DatoDePaciente>& getDatoDePaciente();
	void agregarPaciente(DatoDePaciente _datoDePaciente);
	void guradarInfoDePacientes(string _userId, int _servicio, int _numDePaciente, vector<DatoDePaciente> _datoDePaciente);
	void guradarInfoDePago(string _userId, int _numDePaciente, vector<DatoDePaciente> _datoDePaciente);
	string to_string (); //sobreescritura
};

#endif
