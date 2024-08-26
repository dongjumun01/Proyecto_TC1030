#include "DatoDePaciente.h"
//Constructor default. Sobrecarga
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
//Constrcutor de todos los atributos de DatoDePaciente. Sobrecarga
DatoDePaciente::DatoDePaciente(string _nombreDoc, string _nombrePac, string _sexo, 
			       string _fechaDeNacimiento, int _numDeCama, string _diagnosis, 
                               bool _estudio[], string _sintoma, bool _tratamiento[], 
                               string _fechaInicio, string _fechaFin)
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
/*
	setNombreDoc asigna string valor al atributo nombre_doc

	setter del atributo nombre_doc(nombre del doctor).

	@param string
	@return
*/
void DatoDePaciente::setNombreDoc(string _nombreDoc)
{
	nombre_doc = _nombreDoc;
}
/*
	setNombrePac asigna string valor al atributo nombre_pac

	setter del atributo nombre_pac(nombre del paciente).

	@param string
	@return
*/
void DatoDePaciente::setNombrePac(string _nombrePac)
{
	nombre_pac = _nombrePac;
}
/*
	setSexo asigna string valor al atributo sexo

	setter del atributo sexo

	@param string (m/f)
	@return
*/
void DatoDePaciente::setSexo(string _sexo)
{
	sexo = _sexo;
}
/*
	setFechaDeNacimiento asigna string valor al fechaDeNacimiento

	setter del atributo fechaDeNacimiento

	@param string 
	@return
*/
void DatoDePaciente::setFechaDeNacimiento(string _fechaDeNacimiento)
{
	fechaDeNacimiento = _fechaDeNacimiento;
}
/*
	setNumDeCama asigna int valor al atributo numDeCama

	setter del atributo numDeCama

	@param int
	@return
*/
void DatoDePaciente::setNumDeCama(int _numDeCama)
{
	numDeCama = _numDeCama;
}
/*
	setDiagnosis asigna string valor al atributo diagnosis

	setter del atributo diagnosis

	@param string
	@return
*/
void DatoDePaciente::setDiagnosis(string _diagnosis)
{
	diagnosis = _diagnosis;
}
/*
	setEstudio asigna boolean valor al stributo(arreglo) estudio[]

	setter del atributo estudio[] usando copy() para copiar el arreglo

	@param bool array[]
	@return
*/
void DatoDePaciente::setEstudio(bool _arr[])
{
	copy(_arr, _arr + 5, estudio);
}
/*
	setSintoma asigna string valor al atributo sintoma

	setter del atributo sintoma

	@param string
	@return
*/
void DatoDePaciente::setSintoma(string _sintoma)
{
	sintoma = _sintoma;
}
/*
	setTratmiento asigna boolean valor al stributo(arreglo) tratamiento[]

	setter del atributo tratamiento usando copy() para copiar el arreglo 

	@param bool array[]
	@return
*/
void DatoDePaciente::setTratamiento(bool _arr[])
{
	copy(_arr, _arr + 5, tratamiento);
}
/*
	setFechaInicio asigna string valor al fechaInicio

	setter del atributo fechaInicio

	@param string
	@return
*/
void DatoDePaciente::setFechaInicio(string _fechaInicio)
{
	fechaInicio = _fechaInicio;
}
/*
	setFechaFin asigna string valor al fechaFin

	setter del atributo fechaFin

	@param string
	@return
*/
void DatoDePaciente::setFechaFin(string _fechaFin)
{
	fechaFin = _fechaFin;
}
/*
	getNombreDoc regresa el atributo nombre_doc

	getter del atributo nombre_doc

	@param
	@return string nombre_doc
*/
string DatoDePaciente::getNombreDoc()
{
	return nombre_doc;
}
/*
	getNombrePac regresa el atributo nombre_pac

	getter del atributo nombre_pac

	@param
	@return string nombre_pac
*/
string DatoDePaciente::getNombrePac()
{
	return nombre_pac;
}
/*
	getSexo regresa el atributo sexo

	getter del atributo sexo

	@param
	@return string sexo (m/f)
*/
string DatoDePaciente::getSexo()
{
	return sexo;
}
/*
	getFechaDeNacimiento regresa el atributo fechaDeNacimiento

	getter del atributo fechaDeNacimiento

	@param
	@return string fechaDeNacimiento
*/
string DatoDePaciente::getFechaDeNacimiento()
{
	return fechaDeNacimiento;
}
/*
	getNumDeCama regresa el atributo numDeCama

	getter del atributo numDeCama

	@param
	@return int numDeCama
*/
int DatoDePaciente::getNumDeCama()
{
	return numDeCama;
}
/*
	getDiagnosis regresa el atributo diagnosis

	getter del atributo diagnosis

	@param
	@return string diagnosis
*/
string DatoDePaciente::getDiagnosis()
{
	return diagnosis;
}
/*
	getEstudio regresa el atributo arreglo estudio[]

	getter del atributo arreglo estudio[]

	@param
	@return bool estudio (la direccion)
*/
bool* DatoDePaciente::getEstudio()
{
	return estudio;
}
/*
	getSintoma regresa el atributo sintoma

	getter del atributo sintoma

	@param
	@return string sintoma
*/
string DatoDePaciente::getSintoma()
{
	return sintoma;
}
/*
	getTratamiento regresa el atributo arreglo tratamiento[]

	getter del atributo arreglo tratamiento[]

	@param
	@return bool Tratamiento (la direccion)
*/
bool* DatoDePaciente::getTratamiento()
{
	return tratamiento;
}
/*
	getFechaInicio regresa el atributo fechaInicio

	getter del atributo fechaInicio

	@param
	@return string fechaInicio
*/
string DatoDePaciente::getFechaInicio()
{
	return fechaInicio;
}
/*
	getFechaFin regresa el atributo fechaFin

	getter del atributo fechaFin

	@param
	@return string fechaFin
*/
string DatoDePaciente::getFechaFin()
{
	return fechaFin;
}
/*
	creaIdDePaciente crea un id de paciente basado en el nombre, 
        sexo y la fecha de nacimiento del paciente.

	crea el id de paciente usando el nombre, sexo y fehca de nacimiento 
        del pacinete usando el concepto de ascii code.

	@param string _nombre(para crear el id), string _sexo(para crear el id), 
               string _fechaDeNacimiento(para crear el id)
	@return string(id de paciente)
*/
string DatoDePaciente::creaIdDePaciente(string _nombre, string _sexo, string _fechaDeNacimiento)
{
	string id;
	char c;
	//nombre
	for (int i = 0; i < _nombre.length(); i++)
	{
		//si hay espacio, no hagas nada
		if (_nombre[i] == ' ') {} 
		//si el minuscula del caracter es chiquito que 'm'
		else if (tolower(_nombre[i]) <= 'm') 
		{
			//agrega 13 mas (ascii code) para que todavia sean alfabetos 
			c = tolower(_nombre[i]) + 13; 
			id += c; //concatena c en la variable id.
		}
		else
		{
			//disminuye 13 (ascii code) para que todavia sean alfabetos
			c = tolower(_nombre[i]) - 13; 
			id += c; //concatena c en la variable id.
		}
	}
	//sexo
	id += _sexo;
	//fecha de nacimiento
	for (int i = 0; i < _fechaDeNacimiento.length(); i++)
	{
		if (_fechaDeNacimiento[i] == '/') {} //si hay '/', no hagas nada
		else
		{
			c = _fechaDeNacimiento[i] + 49; //si no, agrega 49 (ascii code)
			id += c; //concatena c en la variable id.
		}
	}
	return id; //regresa id.
}

