#include "Empleado.h"

void Empleado::setUserId(string _userId)
{
	userId = _userId;
}


void Empleado::setPassword(string _password)
{
	password = _password;
}

void Empleado::setNombre(string _nombre)
{
	nombre = _nombre;
}

void Empleado::setTipo(string _tipo)
{
	tipo = _tipo;
}

string Empleado::getUserId()
{
	return userId;
}

string Empleado::getPassword()
{
	return password;
}

string Empleado::getNombre()
{
	return nombre;
}

string Empleado::getTipo()
{
	return tipo;
}
