#pragma once
#ifndef DATODEPACIENTE_H
#define DATODEPACIENTE_H

#include <iostream>

using namespace std;

class DatoDePaciente
{
private:
	string nombre;
	string sexo;
	string fechaDeNacimiento;
	int numDeCama;
	string diagnosis;
	bool estudio[10];
	string sintoma;
	bool tratamiento[10];
	string fechaInicio;
	string fechaFin;

public:
	DatoDePaciente();
	DatoDePaciente(string _nombre, string _sexo, string _fechaDeNacimiento, int _numDeCama, string _diagnosis, bool _estudio[], string _sintoma, bool _tratamiento[], string _fechaInicio, string _fechaFin); //overloading
	void setNombre(string _nombre);
	void setSexo(string _sexo);
	void setFechaDeNacimiento(string _fechaDeNacimiento);
	void setNumDeCama(int _numDeCama);
	void setDiagnosis(string _diagnosis);
	void setEstudio();
	void setSintoma(string _sintoma);
	void setTratamiento();
	void setFechaInicio(string _fechaInicio);
	void setFechaFin(string _fechaFin);
	string getNombre();
	string getSexo();
	string getFechaDeNacimiento();
	int getNumDeCama();
	string getDiagnosis();
	bool* getEstudio();
	string getSintoma();
	bool* getTratamiento();
	string getFechaInicio();
	string getFechaFin();
	string creaIdDePaciente(string _nombre, string _sexo, string _fechaDeNacimiento);
};	



#endif
