#pragma once
#ifndef EMPLEADO_H
#define EMPLEADO_H

#include <iostream>
#include "Doctor.h"
#include "Administrativo.h"

using namespace std;


class Empleado
{
protected:
	string userId;
	string password;
public:
	Empleado() : userId(""), password(""){};
	Empleado(string _userId, string _password) : userId(_userId), password(_password){}; 
	void setUserId(string _userId);
	void setPassword(string _password);
	string getUserId();
	string getPassword();
	bool checaLogInfo(string _userId, string _password);
};

#endif