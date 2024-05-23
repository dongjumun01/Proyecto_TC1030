#include "DatoDePaciente.h"

DatoDePaciente::DatoDePaciente()
{
	nombre = "";
	sexo = "";
	fechaDeNacimiento = "";
	numDeCama = 0;
	diagnosis = "";
	for (int i = 0; i < 10; i++) { estudio[i] = false; }
	sintoma = "";
	for (int i = 0; i < 10; i++) { tratamiento[i] = false; }
	fechaInicio = "";
	fechaFin = "";
}
DatoDePaciente::DatoDePaciente(string _nombre, string _sexo, string _fechaDeNacimiento, int _numDeCama, string _diagnosis, bool _estudio[], string _sintoma, bool _tratamiento[], string _fechaInicio, string _fechaFin)
{
	nombre = _nombre;
	sexo = _sexo;
	fechaDeNacimiento = _fechaDeNacimiento;
	numDeCama = _numDeCama;
	diagnosis = _diagnosis;
	for (int i = 0; i < 10; i++) { estudio[i] = _estudio[i]; }
	sintoma = _sintoma;
	for (int i = 0; i < 10; i++) { tratamiento[i] = _tratamiento[i]; }
	fechaInicio = _fechaInicio;
	fechaFin = _fechaFin;

}
void DatoDePaciente::setNombre(string _nombre)
{
	nombre = _nombre;
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
void DatoDePaciente::setEstudio()
{

}
void DatoDePaciente::setSintoma(string _sintoma)
{
	sintoma = _sintoma;
}
void DatoDePaciente::setTratamiento()
{

}
void DatoDePaciente::setFechaInicio(string _fechaInicio)
{
	fechaInicio = _fechaInicio;
}
void DatoDePaciente::setFechaFin(string _fechaFin)
{
	fechaFin = _fechaFin;
}
string DatoDePaciente::getNombre()
{
	return nombre;
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
	//crear id para el paciente.
}

