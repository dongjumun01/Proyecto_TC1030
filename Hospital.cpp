#include "Hospital.h"
#include "Doctor.h"
#include "Administrativo.h"


Hospital::Hospital()
{
	//Doctores
	index = 0;
	empleado[0] = new Doctor("dmltk01", "qlqjsdlf", "Juan Carlos Martinez Rodriguez", "Doctor", 1);
	empleado[1] = new Doctor("dmltk02", "qlqjsdl", "Jose Luis Valero Gonzalez", "Doctor", 2);
	empleado[2] = new Doctor("dmltk03", "qlqjstka", "Aday  Javier Carrasco Garcia", "Doctor", 3);
	empleado[3] = new Doctor("dmltk04", "qlqjstk", "Cesar Roberto Flores Acosta", "Doctor", 4);
	empleado[4] = new Doctor("dmltk05", "qlqjsdh", "Bernat Ayman Neira Oviedo", "Doctor", 5);
	empleado[5] = new Doctor("dmltk06", "qlqjsdbr", "Natalia Marta Aguirre Martinez", "Doctor", 6);
	//Administrativos
	empleado[6] = new Administrativo("rufwp01", "alfghclf", "Victor Pedro Ruiz Medina", "Adminstrativo");
	empleado[7] = new Administrativo("rufwp02", "alfghvkf", "Samir Max Arana Contreras", "Adminstrativo");
	empleado[8] = new Administrativo("rufwp03", "alfghrn", "Patricia Ana Torres Diaz", "Adminstrativo");
	empleado[9] = new Administrativo("rufwp04", "alfghtlq", "Julio Juan Aguirre Sanchez", "Adminstrativo");
}

int Hospital::getIndex()
{
	return index;
}

Empleado* Hospital::getEmpleado(int _index)
{
	return empleado[_index];
}

bool Hospital::buscaEmpleado(string _userId, string _password)
{
	for (int i = 0; i < 10; i++)
	{
		if (empleado[i]->getUserId() == _userId && empleado[i]->getPassword() == _password)
		{
			index = i;
			return true;
		}
	}
	return false;
}
