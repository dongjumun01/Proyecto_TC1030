#pragma once
#ifndef DATODEPACIENTE_H
#define DATODEPACIENTE_H

#include <iostream>
#include <algorithm>

using namespace std;

class DatoDePaciente
{
private:
	string nombre_doc;
	string nombre_pac;
	string sexo;
	string fechaDeNacimiento;
	int numDeCama;
	string diagnosis;
	bool estudio[5];
	string sintoma;
	bool tratamiento[5];
	string fechaInicio;
	string fechaFin;

public:
	DatoDePaciente();
	DatoDePaciente(string _nombreDoc, string _nombrePac, string _sexo, string _fechaDeNacimiento, int _numDeCama, string _diagnosis, bool _estudio[], string _sintoma, bool _tratamiento[], string _fechaInicio, string _fechaFin); //overloading
	void setNombreDoc(string _nombreDoc);
	void setNombrePac(string _nombrePac);
	void setSexo(string _sexo);
	void setFechaDeNacimiento(string _fechaDeNacimiento);
	void setNumDeCama(int _numDeCama);
	void setDiagnosis(string _diagnosis);
	void setEstudio(bool _arr[]);
	void setSintoma(string _sintoma);
	void setTratamiento(bool _arr[]);
	void setFechaInicio(string _fechaInicio);
	void setFechaFin(string _fechaFin);
	string getNombreDoc();
	string getNombrePac();
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
