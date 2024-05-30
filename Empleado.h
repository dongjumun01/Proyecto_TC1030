#pragma once
#ifndef EMPLEADO_H
#define EMPLEADO_H

#include <iostream>
#include <sstream>

using namespace std;


class Empleado
{
protected:
	string userId;
	string password;
	string nombre;
	string tipo;
public:
	Empleado() : userId(""), password(""), nombre(""), tipo("") {};
	Empleado(string _userId, string _password, string _nombre, string _tipo) : userId(_userId), password(_password), nombre(_nombre), tipo(_tipo){}; 
	void setUserId(string _userId);
	void setPassword(string _password);
	void setNombre(string _nombre);
	void setTipo(string _tipo);
	string getUserId();
	string getPassword();
	string getNombre();
	string getTipo();
	virtual string to_string() { return ""; } //sobreescritura
	virtual void agregarPaciente() {}
};

#endif
