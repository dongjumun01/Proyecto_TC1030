#pragma once
#ifndef ADMINISTRATIVO_H
#define ADMINISTRATIVO_H

#include <fstream>
#include "Empleado.h"

class Administrativo:public Empleado
{
private:
	string idDePaciente;
	bool haPagado;
	float montoTotal;
public:
	Administrativo();
	Administrativo(string _userId, string _password, string _nombre, string _tipo); //sobrecarga
	Administrativo(string _userId, string _password, string _nombre, string _tipo, string _idDePaciente, bool _haPagado, float montoTotal); //sobrecarga
	void setIdDePaciente(string _idDePaciente);
	void setHaPagado(bool _haPagado);
	void setMontoTotal(float _montoTotal);
	string getIdDePaciente();
	bool getHaPagado();
	float getMontoTotal();
	bool checaIdDePaciente(string _idDePaciente);
	void guardaInfoDeHaPagado(string _userId, string _idDePaciente, bool _haPagado, float _montoTotal);
	string to_string(); //sobreescritura
};

#endif 

