#include "Doctor.h"

Doctor::Doctor():Empleado()
{
	servicio = 0;
}
Doctor::Doctor(string _userId, string _password, string _nombre, string _tipo, int _servicio) :Empleado(_userId, _password, _nombre, _tipo)
{
	servicio = _servicio;
}
Doctor::Doctor(string _userId, string _password, string _nombre, string _tipo, DatoDePaciente _datoDePaciente, int _servicio) :Empleado(_userId, _password, _nombre, _tipo)
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
void Doctor::guradarInfoDePacientes(string _userId, int _servicio, int _numDePaciente, vector<DatoDePaciente> _datoDePaciente)
{
	stringstream ss;
	ss << _userId << "_" << "pacientes.txt";
	fstream fs;
	fs.open(ss.str(), ios::app);
	if (!fs) { cout << "Archivo no encontrado" << endl; }
	else
	{
		for (int i = 0; i < _numDePaciente; i++)
		{
			fs << _datoDePaciente.at(i).getNombrePac() << "\t";
			fs << _datoDePaciente.at(i).getSexo() << "\t";
			fs << _datoDePaciente.at(i).getFechaDeNacimiento() << "\t";
			fs << _datoDePaciente.at(i).getNumDeCama() << "\t";
			fs << _datoDePaciente.at(i).getDiagnosis() << "\t";
			//fs << _datoDePaciente.at(i).getEstudio() << "\t";
			fs << _datoDePaciente.at(i).getSintoma() << "\t";
			//fs << _datoDePaciente.at(i).getTratamiento() << "\t";
			fs << _datoDePaciente.at(i).getFechaInicio() << "\t";
			fs << _datoDePaciente.at(i).getFechaFin() << "\t";
			fs << _servicio << "\n";
		}
		cout << "¡Datos Guardados Exitosamente!" << endl;
		fs.close();
	}
}

void Doctor::guradarInfoDePago(string _userId, int _numDePaciente, vector<DatoDePaciente> _datoDePaciente)
{
	fstream fs;
	float montoTotal = 0;
	fs.open("infoDePago.txt", ios::app);
	if (!fs) { cout << "Archivo no encontrado" << endl; }
	else
	{
		for (int i = 0; i < _numDePaciente; i++)
		{
			fs << _datoDePaciente.at(i).creaIdDePaciente(_datoDePaciente.at(i).getNombrePac(), _datoDePaciente.at(i).getSexo(), _datoDePaciente.at(i).getFechaDeNacimiento()) << "\t";
			//calcular el monto total (estudios)
			if (_datoDePaciente.at(i).getEstudio()[0] == true) { montoTotal += 328; } //analisis de sangre
			if (_datoDePaciente.at(i).getEstudio()[1] == true) { montoTotal += 350; } //radiografia
			if (_datoDePaciente.at(i).getEstudio()[2] == true) { montoTotal += 652; } //ultrasonido
			if (_datoDePaciente.at(i).getEstudio()[3] == true) { montoTotal += 2759; } //tomografia
			if (_datoDePaciente.at(i).getEstudio()[4] == true) { montoTotal += 5338; } //resonancia magnetica
			//calcular el monto total (tratamiento)
			if (_datoDePaciente.at(i).getTratamiento()[0] == true) { montoTotal += 113; } //adrenalina
			if (_datoDePaciente.at(i).getTratamiento()[1] == true) { montoTotal += 225; } //dopamina
			if (_datoDePaciente.at(i).getTratamiento()[2] == true) { montoTotal += 120; } //dobutamina
			if (_datoDePaciente.at(i).getTratamiento()[3] == true) { montoTotal += 111; } //metilprednisolona
			if (_datoDePaciente.at(i).getTratamiento()[4] == true) { montoTotal += 78; } //salbutamol
			fs << std::to_string(montoTotal) << "t";
			fs << _userId << "\n";
		}
		cout << "¡Datos Guardados Exitosamente!" << endl;
		fs.close();
	}
}

string Doctor::to_string()
{
	stringstream ss;
	ss << "Bienvenido/a, doctor/a " << nombre << endl;
	if (servicio == 1) { ss << "Servicio: Cirugia General" << endl; }
	else if (servicio == 2) { ss << "Servicio: Gineco-Obstetricia" << servicio << endl; }
	else if (servicio == 3) { ss << "Servicio: Medicina Interna" << servicio << endl; }
	else if (servicio == 4) { ss << "Servicio: Pediatria" << servicio << endl; }
	else if (servicio  == 5) { ss << "Servicio: Urgencias" << servicio << endl; }
	else { ss << "Servicio: Medicina familiar" << servicio << endl; }

	return ss.str();
}
