/*
	La clase Administrativo es una clase herada de la clase Empleado.
	Tiene los constructores, getters y setters, y metodos para guardar la informacion del estado de pago
	y para imprimir la informacion del adminstrativo.
*/
#pragma once
#ifndef ADMINISTRATIVO_H
#define ADMINISTRATIVO_H

#include <fstream>
#include "Empleado.h"
//Declaro clase Administrativo que hereda de Empleado
class Administrativo:public Empleado
{
//Declaro variables de instancia
private:
	string idDePaciente;
	bool haPagado;
	float montoTotal;
//Declaro los constructores y metodos que va a tener el objeto
public:
	Administrativo(); //sobrecarga
	Administrativo(string _userId, string _password, string _nombre, string _tipo); //sobrecarga
	Administrativo(string _userId, string _password, string _nombre, string _tipo, 
		       string _idDePaciente, bool _haPagado, float montoTotal); //sobrecarga
	void setIdDePaciente(string _idDePaciente);
	void setHaPagado(bool _haPagado);
	void setMontoTotal(float _montoTotal);
	string getIdDePaciente();
	bool getHaPagado();
	float getMontoTotal();
	bool checaIdDePaciente(string _idDePaciente);
	void guardaInfoDeHaPagado(string _userId, string _idDePaciente, 
                                  bool _haPagado, float _montoTotal);
	string to_string(); //sobreescrito
};

#endif 

