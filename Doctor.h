/*
	La clase Doctor es una clase herada de la clase Empleado.
	Tiene los constructores, getters y setters, y metodos para 
 	guardar la informacion de los pacientes de un doctor
	y para imprimir la informacion del doctor.
*/
#pragma once
#ifndef DOCTOR_H
#define DOCTOR_H

#include <string>
#include <vector>
#include <fstream>
#include "DatoDePaciente.h"
#include "Empleado.h"

//Declaro clase Doctor que hereda de Empleado
class Doctor:public Empleado
{
//Declaro variables de instancia
private: 
	vector<DatoDePaciente> datoDePaciente;
	int servicio;
//Declaro los constructores y metodos que va a tener el objeto
public:
	Doctor(); //sobrecarga
	Doctor(string _userId, string _password, string _nombre, 
	       string _tipo, int _servicio); //sobrecarga
	Doctor(string _userId, string _password, string _nombre, 
               string _tipo, DatoDePaciente _datoDePaciente, 
               int _servicio); //sobrecarga
	void setServicio(int _servicio);
	int getServicio();
	vector<DatoDePaciente>& getDatoDePaciente();
	void agregarPaciente(DatoDePaciente _datoDePaciente);
	void guradarInfoDePacientes(string _userId, int _servicio, 
                                    int _numDePaciente, 
                                    vector<DatoDePaciente> _datoDePaciente);
	void guradarInfoDePago(string _userId, int _numDePaciente, 
			       vector<DatoDePaciente> _datoDePaciente);
	string to_string (); //sobreescrito
};

#endif
