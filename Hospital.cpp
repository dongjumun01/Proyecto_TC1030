#include "Hospital.h"
#include "Doctor.h"
#include "Administrativo.h"

/*
	Hospital genera objetos en Empleado[]

	genera objetos de Doctor y Administrativo, y los
	guarda en la varibale de instancia en empleado[] (arreglo de empleados)
	para poder confimar las informaciones de login del usario (que si existe
	en el sistema su userId y password)

	@param
	@return
*/
Hospital::Hospital()
{
	//new crea el objeto en tiempo de ejecución para usar polimorfismo
	//Doctores
	index = 0;
	empleado[0] = new Doctor("dmltk01", "qlqjsdlf", "Juan Carlos Martinez Rodriguez", "Doctor", 1);
	empleado[1] = new Doctor("dmltk02", "qlqjsdl", "Jose Luis Valero Gonzalez", "Doctor", 2);
	empleado[2] = new Doctor("dmltk03", "qlqjstka", "Aday Javier Carrasco Garcia", "Doctor", 3);
	empleado[3] = new Doctor("dmltk04", "qlqjstk", "Cesar Roberto Flores Acosta", "Doctor", 4);
	empleado[4] = new Doctor("dmltk05", "qlqjsdh", "Bernat Ayman Neira Oviedo", "Doctor", 5);
	empleado[5] = new Doctor("dmltk06", "qlqjsdbr", "Natalia Marta Aguirre Martinez", "Doctor", 6);
	//Administrativos
	empleado[6] = new Administrativo("rufwp01", "alfghclf", "Victor Pedro Ruiz Medina", "Adminstrativo");
	empleado[7] = new Administrativo("rufwp02", "alfghvkf", "Samir Max Arana Contreras", "Adminstrativo");
	empleado[8] = new Administrativo("rufwp03", "alfghrn", "Patricia Ana Torres Diaz", "Adminstrativo");
	empleado[9] = new Administrativo("rufwp04", "alfghtlq", "Julio Juan Aguirre Sanchez", "Adminstrativo");
}
/*
	getIndex regresa el atributo index

	utiliza para regresar el index que se usa para el metodo getEmpleado().
	En la variable index, se guarda el index de la informacion 

	@param
	@return int index
*/
int Hospital::getIndex()
{
	return index;
}
/*
	getEmpleado regresa el objeto empleado[]

	utiliza para regresar el objeto empleado[] con 
	el index que recibe.

	@param int index usando el metodo getIndex()
	@return regresa el objeto empelado[_index] (la direccion/Empleado*)
*/
Empleado* Hospital::getEmpleado(int _index)
{
	return empleado[_index];
}
/*
	buscaEmpleado regresa el valor booleano que indica que si esta la informacion de login en el sistema o no.

	utiliza para regresar el valor booleano para confirmar la existencia de el userId y password
	usando ciclo for busca estos userId y password de los objetos empleado[], un index por un index.
	si encuentra la informacion, assigna ese valor de i a la variable index y regresa true.
	si no, regresa false.

	@param string userId, string password para confirmar que estos datos estan en el sistema.
	@return regresa el valor booleano para confirmar.
*/
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
