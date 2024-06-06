#include "Empleado.h"
/*
	setUserId asigna string valor al atributo userId

	setter del atributo userId

	@param string
	@return 
*/
void Empleado::setUserId(string _userId)
{
	userId = _userId;
}
/*
	setPassword asigna string valor al atributo password

	setter del atributo password

	@param string 
	@return
*/
void Empleado::setPassword(string _password)
{
	password = _password;
}
/*
	setNombre asigna string valor al atributo nombre

	setter del atributo nombre

	@param string
	@return
*/
void Empleado::setNombre(string _nombre)
{
	nombre = _nombre;
}
/*
	setTipo asigna string valor al atributo tipo

	setter del atributo tipo

	@param string: Doctor, Administrativo
	@return
*/
void Empleado::setTipo(string _tipo)
{
	tipo = _tipo;
}
/*
	getUserId regresa el atributo userId

	getter del atributo userId

	@param
	@return string userId
*/
string Empleado::getUserId()
{
	return userId;
}
/*
	getPassword regresa el atributo password

	getter del atributo password

	@param
	@return string password
*/
string Empleado::getPassword()
{
	return password;
}
/*
	getUserId regresa el atributo nombre

	getter del atributo nombre

	@param
	@return string nombre
*/
string Empleado::getNombre()
{
	return nombre;
}
/*
	getUserId regresa el atributo tipo

	getter del atributo tipo

	@param
	@return string tipo: Doctor, Administrativo
*/
string Empleado::getTipo()
{
	return tipo;
}
