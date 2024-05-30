#include "DatoDePaciente.h"

DatoDePaciente::DatoDePaciente()
{
	nombre_doc = "";
	nombre_pac = "";
	sexo = "";
	fechaDeNacimiento = "";
	numDeCama = 0;
	diagnosis = "";
	for (int i = 0; i < 5; i++) { estudio[i] = false; }
	sintoma = "";
	for (int i = 0; i < 5; i++) { tratamiento[i] = false; }
	fechaInicio = "";
	fechaFin = "";
}
DatoDePaciente::DatoDePaciente(string _nombreDoc, string _nombrePac, string _sexo, string _fechaDeNacimiento, int _numDeCama, string _diagnosis, bool _estudio[], string _sintoma, bool _tratamiento[], string _fechaInicio, string _fechaFin)
{
	nombre_doc = _nombreDoc;
	nombre_pac = _nombreDoc;
	sexo = _sexo;
	fechaDeNacimiento = _fechaDeNacimiento;
	numDeCama = _numDeCama;
	diagnosis = _diagnosis;
	for (int i = 0; i < 5; i++) { estudio[i] = _estudio[i]; }
	sintoma = _sintoma;
	for (int i = 0; i < 5; i++) { tratamiento[i] = _tratamiento[i]; }
	fechaInicio = _fechaInicio;
	fechaFin = _fechaFin;

}
void DatoDePaciente::setNombreDoc(string _nombreDoc)
{
	nombre_doc = _nombreDoc;
}
void DatoDePaciente::setNombrePac(string _nombrePac)
{
	nombre_pac = _nombrePac;
}
void DatoDePaciente::setSexo(string _sexo)
{
	sexo = _sexo;
}
void DatoDePaciente::setFechaDeNacimiento(string _fechaDeNacimiento)
{
	fechaDeNacimiento = _fechaDeNacimiento;
}
void DatoDePaciente::setNumDeCama(int _numDeCama)
{
	numDeCama = _numDeCama;
}
void DatoDePaciente::setDiagnosis(string _diagnosis)
{
	diagnosis = _diagnosis;
}
void DatoDePaciente::setEstudio(bool _arr[])
{
	copy(_arr, _arr + 5, estudio);
}
void DatoDePaciente::setSintoma(string _sintoma)
{
	sintoma = _sintoma;
}
void DatoDePaciente::setTratamiento(bool _arr[])
{
	copy(_arr, _arr + 5, tratamiento);
}
void DatoDePaciente::setFechaInicio(string _fechaInicio)
{
	fechaInicio = _fechaInicio;
}
void DatoDePaciente::setFechaFin(string _fechaFin)
{
	fechaFin = _fechaFin;
}
string DatoDePaciente::getNombreDoc()
{
	return nombre_doc;
}
string DatoDePaciente::getNombrePac()
{
	return nombre_pac;
}
string DatoDePaciente::getSexo()
{
	return sexo;
}
string DatoDePaciente::getFechaDeNacimiento()
{
	return fechaDeNacimiento;
}
int DatoDePaciente::getNumDeCama()
{
	return numDeCama;
}
string DatoDePaciente::getDiagnosis()
{
	return diagnosis;
}
bool* DatoDePaciente::getEstudio()
{
	return estudio;
}
string DatoDePaciente::getSintoma()
{
	return sintoma;
}
bool* DatoDePaciente::getTratamiento()
{
	return tratamiento;
}
string DatoDePaciente::getFechaInicio()
{
	return fechaInicio;
}
string DatoDePaciente::getFechaFin()
{
	return fechaFin;
}
string DatoDePaciente::creaIdDePaciente(string _nombre, string _sexo, string _fechaDeNacimiento)
{
	string id;
	char c;
	//nombre
	for (int i = 0; i < _nombre.length(); i++)
	{
		if (_nombre[i] == ' ') {}
		else if (tolower(_nombre[i]) <= 'm')
		{
			c = tolower(_nombre[i]) + 13;
			id += c;
		}
		else
		{
			c = tolower(_nombre[i]) - 13;
			id += c;
		}
	}
	//sexo
	id += _sexo;
	//fecha de nacimiento
	for (int i = 0; i < _fechaDeNacimiento.length(); i++)
	{
		if (_fechaDeNacimiento[i] == '/') {}
		else
		{
			c = _fechaDeNacimiento[i] + 49;
			id += c;
		}
	}
	return id;
}

