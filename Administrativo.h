#pragma once
#ifndef ADMINISTRATIVO_H
#define ADMINISTRATIVO_H

#include <iostream>
#include "Empleado.h"

class Administrativo:public Empleado
{
private:
	string idDePaciente;
	bool haPagado;
public:
	Administrativo();
	Administrativo(string _userId, string _password); //sobrecarga
	Administrativo(string _userId, string _password, string _idDePaciente, bool _haPagado); //sobrecarga
	void setIdDePaciente(string _idDePaciente);
	void setHaPagado(bool _haPagado);
	string getIdDePaciente();
	bool getHaPagado();
	bool checaLogInfo(string _userId, string _password); //sobreescritura
	bool checaIdDePaciente(string _idDePaciente);
	float cargaMontoTotal(string _idDePaciente);
	void guardaInfoDeHaPagado(string _userId, string _password, string _idDePaciente, bool _haPagado);
};

#endif

