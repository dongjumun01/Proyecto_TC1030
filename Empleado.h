/*
	La clase Empleado es una clase abstracta que esta 
 	en la relacion de herencia con la clase Doctor 
  	y Administrativo.
	Tiene getters y setters de sus atributos.
*/
#pragma once
#ifndef EMPLEADO_H
#define EMPLEADO_H

#include <iostream>
#include <sstream>

using namespace std;

//Declaracion de clase empleado que es abstracta
class Empleado
{
//Declaro variables de instancia
protected:
	string userId;
	string password;
	string nombre;
	string tipo;
//Declaro los constructores y metodos que va a tener el objeto
public:
	Empleado() : userId(""), password(""), nombre(""), tipo("") {}; //sobrecarga
	Empleado(string _userId, string _password, string _nombre, string _tipo) : userId(_userId), password(_password), nombre(_nombre), tipo(_tipo){}; //sobrecarga
	void setUserId(string _userId);
	void setPassword(string _password);
	void setNombre(string _nombre);
	void setTipo(string _tipo);
	string getUserId();
	string getPassword();
	string getNombre();
	string getTipo();
	virtual string to_string() = 0; //método abstracto será sobreescrito
};

#endif
