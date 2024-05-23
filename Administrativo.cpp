#include "Administrativo.h"

Administrativo::Administrativo()
{
	userId = "";
	password = "";
	idDePaciente = "";
	haPagado = false;
}
Administrativo::Administrativo(string _userId, string _password) :Empleado(_userId, _password)
{
	idDePaciente = "";
	haPagado = false;
}
Administrativo::Administrativo(string _userId, string _password, string _idDePaciente, bool _haPagado):Empleado(_userId, _password)
{
	idDePaciente = _idDePaciente;
	haPagado = _haPagado;
}
void Administrativo::setIdDePaciente(string _idDePaciente)
{
	idDePaciente = _idDePaciente;
}
void Administrativo::setHaPagado(bool _haPagado)
{
	haPagado = _haPagado;
}
string Administrativo::getIdDePaciente()
{
	return idDePaciente;
}
bool Administrativo::getHaPagado()
{
	return haPagado;
}
bool Administrativo::checaLogInfo(string _userId, string _password)
{
	//checa la info de login. Metodo sobreescrito.
}
bool Administrativo::checaIdDePaciente(string _idDePaciente)
{
	//checa que si el id del paciete está en el sistema.
	return true;
	//si no está en el sistema, regresa falso.
	//return false;
}
float Administrativo::cargaMontoTotal(string _idDePaciente)
{
	//trae el dato del monto total del archivo de texto.
}
void Administrativo::guardaInfoDeHaPagado(string _userId, string _password, string _idDePaciente, bool _haPagado)
{
	//guarda la informacion de que si ha pagado o no con la informacion del administrativo.
}
