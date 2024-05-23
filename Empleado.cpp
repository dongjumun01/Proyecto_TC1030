#include "Empleado.h"

void Empleado::setUserId(string _userId)
{
	userId = _userId;
}


void Empleado::setPassword(string _password)
{
	password = _password;
}

string Empleado::getUserId()
{
	return userId;
}

string Empleado::getPassword()
{
	return password;
}

bool Empleado::checaLogInfo(string _userId, string _password)
{
	//checa Login Info.
}

