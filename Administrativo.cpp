#include "Administrativo.h"
//Constructor default. Sobrecarga
Administrativo::Administrativo():Empleado()
{
	idDePaciente = "";
	haPagado = false;
	montoTotal = 0;
}
//Constructor sin los datos de los atributos( de Adminstrativo (idDePaciente, haPagado, montoTotal). Sobrecarga
Administrativo::Administrativo(string _userId, string _password, string _nombre, string _tipo) :Empleado(_userId, _password, _nombre, _tipo)
{
	idDePaciente = "";
	haPagado = false;
	montoTotal = 0;
}
//Constructor con los datos de los atributos de Administrativo. Sobrecarga
Administrativo::Administrativo(string _userId, string _password, string _nombre, string _tipo, string _idDePaciente, bool _haPagado, float _montoTotal):Empleado(_userId, _password, _nombre, _tipo)
{
	idDePaciente = _idDePaciente;
	haPagado = _haPagado;
	montoTotal = _montoTotal;
}
/*
	setIdDePaciente asigna string valor al atributo idDePaciente

	setter del atributo idDePaciente.

	@param string
	@return
*/
void Administrativo::setIdDePaciente(string _idDePaciente)
{
	idDePaciente = _idDePaciente;
}
/*
	setHaPagado asigna boolean valor al atributo haPagado

	setter del atributo haPagado.

	@param bool: true false
	@return
*/
void Administrativo::setHaPagado(bool _haPagado)
{
	haPagado = _haPagado;
}
/*
	setMontoTotal asigna float valor al atributo montoTotal

	setter del atributo montoTotal.

	@param float
	@return
*/
void Administrativo::setMontoTotal(float _montoTotal)
{
	montoTotal = _montoTotal;
}
/*
	getIdDePaciente regresa el atributo idDePaciente

	getter del atributo idDePaciente

	@param
	@return string (id de paciente)
*/
string Administrativo::getIdDePaciente() 
{
	return idDePaciente;
}
/*
	getHaPagado regresa el atributo haPagado

	getter del atributo haPagado

	@param
	@return bool: true false
*/
bool Administrativo::getHaPagado()
{
	return haPagado;
}
/*
	getMontoTotal regresa el atributo montoTotal

	getter del atributo montoTotal

	@param
	@return float (montoTotal)
*/
float Administrativo::getMontoTotal()
{
	return montoTotal;
}
/*
	checaIdDePaciente checa que si el id de paciente esta en el archivo de texto "infoDePago.txt"

	abre el archivo de texto "infoDePago.txt" y busca el id de paciente.
	si no esta, regresa false
	si esta, regresa true

	@param string (_idDePaciente): para checar que si esta en el archivo de texto.
	@return bool: true(si esta en el archivo), false(no esta en el archivo)
*/
bool Administrativo::checaIdDePaciente(string _idDePaciente)
{
	//checa que si el id del paciete está en el sistema.
	fstream fs;
	bool haEncontrado = false; //para salir del ciclo while
	string line;
	fs.open("infoDePago.txt", ios::in);
	if (!fs) //no se abre
	{ 
		cout << "Archivo no encontrado" << endl; 
		return false;
	}
	else //se abre
	{
		while (!haEncontrado)
		{
			if (fs.eof()) { break; } //si es el final del archivo sale de ciclo
			else //si no
			{
				getline(fs, line, '\t'); //lee el archivo hasta que salga un tab y guarda estos datos en la variable line.
				if (line == _idDePaciente) //si ese line es igual _idDePaciente
				{
					getline(fs, line, '\t'); //lee mas hasta que salga un tab y guarda estos datos en la variable line.
					montoTotal = stof(line); //convierta lo que esta en la variable line en floatante y lo asigna en la varibale montoTotal
					fs.close(); //se cierra el archivo
					haEncontrado = true; //para salir del ciclo
					return true; //regresa true
				}
				else { getline(fs, line, '\n'); } //si no lee el archivo hasta que salga un line change y guarda estos datos en la variable line.
			}
		}
		fs.close(); //si no lo encuentra, se cierra el archivo de texto
		return false; //regresa false(no se ha encontrado el id de paciente)
	}
}
/*
	guardaInfoDeHaPagado guarda el id de paciente, haPagado y montoTotal en el archivo de texto de ese adminstrativo.

	gurada la informacion del id de paciente, haPagado y montoTotal. 
	se abre el archivo de texto de ese adminstrativo (userId_pago.txt) usando stringstream.
	guarda estos datos. 


	@param string _userId(para el nombre del archivo del texto), string _idDePaciente(para guardarlo), bool _haPagado(para guardarlo), float _montoTotal(para guardarlo)
	@return
*/
void Administrativo::guardaInfoDeHaPagado(string _userId, string _idDePaciente, bool _haPagado, float _montoTotal)
{
	//guarda la informacion de que si ha pagado o no con la informacion del administrativo.
	stringstream ss;
	ss << _userId << "_" << "pago.txt"; //el nomrbe de archivo de texto de ese adminstrativo
	fstream fs;
	fs.open(ss.str(), ios::app);
	if (!fs) { cout << "Archivo no encontrado" << endl; } //si no se abre
	else //si se abre
	{
		fs << _idDePaciente << "\t"; //se guarda el id de paciente y le da un espacio de tab.
		if (_haPagado) { fs << "true" << "\t"; } //si ha pagado, se escribe "true" en el archivo de texto y le da un tab. si no ha pagado, no se usa esa funcion.
		fs << std::to_string(_montoTotal) << "\n"; //convierte montoTotal(float) a string. lo guarda y le da un cambio de linea
		fs.close(); //se cierra el file
	}
}
/*
	to_string imprime el dato del adminstrativo.

	imprime la informacion de login de un adminstrativo: nombre.
	usando stringstream

	@param
	@return string con los valores y texto concatenado.
*/
string Administrativo::to_string()
{
	stringstream ss;
	ss << "Bienvenido/a, " << nombre << endl;
	return ss.str();
}
