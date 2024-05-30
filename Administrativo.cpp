#include "Administrativo.h"

Administrativo::Administrativo()
{
	userId = "";
	password = "";
	idDePaciente = "";
	haPagado = false;
	montoTotal = 0;
}
Administrativo::Administrativo(string _userId, string _password, string _nombre, string _tipo) :Empleado(_userId, _password, _nombre, _tipo)
{
	idDePaciente = "";
	haPagado = false;
	montoTotal = 0;
}
Administrativo::Administrativo(string _userId, string _password, string _nombre, string _tipo, string _idDePaciente, bool _haPagado, float _montoTotal):Empleado(_userId, _password, _nombre, _tipo)
{
	idDePaciente = _idDePaciente;
	haPagado = _haPagado;
	montoTotal = _montoTotal;
}
void Administrativo::setIdDePaciente(string _idDePaciente)
{
	idDePaciente = _idDePaciente;
}
void Administrativo::setHaPagado(bool _haPagado)
{
	haPagado = _haPagado;
}
void Administrativo::setMontoTotal(float _montoTotal)
{
	montoTotal = _montoTotal;
}
string Administrativo::getIdDePaciente()
{
	return idDePaciente;
}
bool Administrativo::getHaPagado()
{
	return haPagado;
}
float Administrativo::getMontoTotal()
{
	return montoTotal;
}
bool Administrativo::checaIdDePaciente(string _idDePaciente)
{
	//checa que si el id del paciete está en el sistema.
	fstream fs;
	bool haEncontrado = false;
	string line;
	fs.open("infoDePago.txt", ios::in);
	if (!fs) 
	{ 
		cout << "Archivo no encontrado" << endl; 
		return false;
	}
	else 
	{
		while (!haEncontrado)
		{
			if (fs.eof()) { break; }
			else
			{
				getline(fs, line, '\t');
				if (line == _idDePaciente)
				{
					getline(fs, line, '\t'); 
					montoTotal = stof(line);
					fs.close();
					haEncontrado = true;
					return true;
				}
				else { getline(fs, line, '\n'); }
			}
		}
		fs.close();
		return false;
	}
}
void Administrativo::guardaInfoDeHaPagado(string _userId, string _idDePaciente, bool _haPagado, float _montoTotal)
{
	//guarda la informacion de que si ha pagado o no con la informacion del administrativo.
	stringstream ss;
	ss << _userId << "_" << "pago.txt";
	fstream fs;
	fs.open(ss.str(), ios::app);
	if (!fs) { cout << "Archivo no encontrado" << endl; }
	else
	{
		fs << _idDePaciente << "t";
		if (_haPagado) { fs << "true" << "t"; }
		fs << std::to_string(_montoTotal) << "\n";
		cout << "¡Datos Guardados Exitosamente!" << endl;
		fs.close();
	}
}

string Administrativo::to_string()
{
	stringstream ss;
	ss << "Bienvenido/a, " << nombre << endl;
	return ss.str();
}
