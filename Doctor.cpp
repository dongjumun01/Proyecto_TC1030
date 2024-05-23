#include "Doctor.h"

Doctor::Doctor():Empleado()
{
	servicio = 0;
}
Doctor::Doctor(string _userId, string _password) :Empleado(_userId, _password)
{
	servicio = 0;
}
Doctor::Doctor(string _userId, string _password, DatoDePaciente _datoDePaciente, int _servicio) :Empleado(_userId, _password)
{
	//usando push_back() para asignar el valor(objeto) del vector.
	datoDePaciente.push_back(_datoDePaciente);
	servicio = _servicio;
}
void Doctor::setServicio(int _servicio)
{
	servicio = _servicio;
}
int Doctor::getServicio()
{
	return servicio;
}
vector<DatoDePaciente>& Doctor::getDatoDePaciente()
{
	return datoDePaciente;
}
void Doctor::agregarPaciente(DatoDePaciente _datoDePaciente)
{
	datoDePaciente.push_back(_datoDePaciente);
}
bool Doctor::checaLogInfo(string _userId, string _password, int _servicio)
{
	//checa la info de login. Metodo sobreescrito.
}
void Doctor::guradarInfoDePacientes(string _userId, string _password, int _servicio, DatoDePaciente _datoDePaciente)
{
	//guarda la informacion del paciente con la informacion del doctor. Se usa el metodo creaIdDePaciente() de la clase DatoDePaciente y también se guarda.
}

void Doctor::guradarInfoDePago(string _userId, string _password, int _servicio, DatoDePaciente _datoDePaciente)
{
	//guarda la informacion de pago del paciente con la informacion del doctor. Se usa el metodo creaIdDePaciente() de la clase DatoDePaciente y también se guarda.
}