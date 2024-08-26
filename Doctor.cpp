#include "Doctor.h"
//Constructor default. Sobrecarga 
Doctor::Doctor():Empleado()
{
	servicio = 0;
}
//Constructor sin datoDePaciente. Sobrecarga
Doctor::Doctor(string _userId, string _password, string _nombre, 
	       string _tipo, int _servicio) :Empleado(_userId, 
                                                      _password, 
                                                      _nombre, _tipo)
{
	servicio = _servicio;
}
//Constructor con un datoDePaciente para un miembro del vector. Sobrecarga
Doctor::Doctor(string _userId, string _password, string _nombre, 
               string _tipo, DatoDePaciente _datoDePaciente, 
               int _servicio) :Empleado(_userId, _password, _nombre, _tipo)
{
	//usando push_back() para asignar el valor(objeto) del vector.
	datoDePaciente.push_back(_datoDePaciente);
	servicio = _servicio;
}
/*
	setServicio asigna int valor al atributo servicio

	setter del atributo servicio.

	@param int: 1~5 (1: Cirugia General, 2: Gineco-Obstetricia,
 			 3: Medicina Interna, 4: Pediatria, 
     			 5: Urgencias, 6: Medicina familiar)
	@return
*/
void Doctor::setServicio(int _servicio)
{
	servicio = _servicio;
}
/*
	getServicio regresa el atributo servicio

	getter del atributo servicio

	@param
	@return int servicio: 1~5 (1: Cirugia General, 
 			           2: Gineco-Obstetricia, 
	       			   3: Medicina Interna, 
	      			   4: Pediatria, 
	     			   5: Urgencias, 
	    			   6: Medicina familiar)
*/
int Doctor::getServicio()
{
	return servicio;
}
/*
	getServicio regresa el atributo datoDePaciente (vector)

	getter del atributo datoDePaciente (vector)

	@param
	@return vector<DatoDepaciente> : datoDePaciente(vector)
*/
vector<DatoDePaciente>& Doctor::getDatoDePaciente()
{
	return datoDePaciente;
}
/*
	agregarPaciente agrega un miembro del vector datoDePaciente

	agrega un miembro del vector datoDePaciente usando push_back(_datoDepaciente)

	@param un objeto de DatoDePaciente: _datoDePaciente
	@return
*/
void Doctor::agregarPaciente(DatoDePaciente _datoDePaciente)
{
	datoDePaciente.push_back(_datoDePaciente);
}
/*
	guardaInfoDePaciente guarda la informacion de los pacientes 
 	de un doctor en el archivo de texto de ese doctor.

	gurada la informacion de los pacientes de todos los miembros 
 	del vector datoDePaciente en el archivo de texto que se llama 
  	"userId_pacientes.txt"
	(Aqui userId se refiere al userId de ese doctor.)

	@param string _userId(para el nombre del archivo del texto),
 	       int _servicio(para guardar su servicio), 
	       int _numDePaciente(para aceder a los miembros 
				  del vector datoDePaciente usando at()), 
      	       vector<DatoDePaciente> _datoDePaciente (vector)
	@return
*/
void Doctor::guradarInfoDePacientes(string _userId, int _servicio, 
				    int _numDePaciente, 
				    vector<DatoDePaciente> _datoDePaciente)
{
	stringstream ss;
	ss << _userId << "_" << "pacientes.txt"; //para abrir ese archivo de texto de ese doctor.
	fstream fs;
	fs.open(ss.str(), ios::app);
	if (!fs) { cout << "Archivo no encontrado" << endl; } //si no abre
	else //si abre
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
/*
	guardaInfoDePaciente guarda el Id del paciente, 
 	el monto total y userId del doctor en el archivo de texto "infoDePago.txt".

	gurada el Id de paciente usando el metodo creaIdDePaciente de DatoDePaciente. 
	gurada el monto total usando los datos del atributo estudio[] y tratamiento[].
	guarda el userId del doctor.
	todos se guardan en el archivo de texto que se llama "infoDePago.txt"

	@param string _userId(para guardar), 
 	       int _numDePaciente(para aceder a los 
	 			  miembros del vector 
       				  datoDePaciente usando at()), 
	       vector<DatoDePaciente> _datoDePaciente (vector)
	@return
*/
void Doctor::guradarInfoDePago(string _userId, int _numDePaciente, 
			       vector<DatoDePaciente> _datoDePaciente)
{
	fstream fs;
	float montoTotal = 0;
	fs.open("infoDePago.txt", ios::app);
	if (!fs) { cout << "Archivo no encontrado" << endl; } //si no abre
	else //si abre
	{
		for (int i = 0; i < _numDePaciente; i++)
		{
			fs << _datoDePaciente.at(i).creaIdDePaciente(_datoDePaciente.at(i).getNombrePac(),
								     _datoDePaciente.at(i).getSexo(), 
								     _datoDePaciente.at(i).getFechaDeNacimiento()) 
			   << "\t"; //se guarda el id de paciente.
			//calcular el monto total (estudios)
			//analisis de sangre
			if (_datoDePaciente.at(i).getEstudio()[0] == true) { montoTotal += 328; } 
			//radiografia
			if (_datoDePaciente.at(i).getEstudio()[1] == true) { montoTotal += 350; } 
			//ultrasonido
			if (_datoDePaciente.at(i).getEstudio()[2] == true) { montoTotal += 652; } 
			//tomografia
			if (_datoDePaciente.at(i).getEstudio()[3] == true) { montoTotal += 2759; } 
			//resonancia magnetica
			if (_datoDePaciente.at(i).getEstudio()[4] == true) { montoTotal += 5338; } 
			//calcular el monto total (tratamiento)
			//adrenalina
			if (_datoDePaciente.at(i).getTratamiento()[0] == true) { montoTotal += 113; }
			//dopamina
			if (_datoDePaciente.at(i).getTratamiento()[1] == true) { montoTotal += 225; }
			//dobutamina
			if (_datoDePaciente.at(i).getTratamiento()[2] == true) { montoTotal += 120; }
			//metilprednisolona
			if (_datoDePaciente.at(i).getTratamiento()[3] == true) { montoTotal += 111; } 
			//salbutamol
			if (_datoDePaciente.at(i).getTratamiento()[4] == true) { montoTotal += 78; } 
			fs << std::to_string(montoTotal) << "\t"; // se guarda el monto total.
			fs << _userId << "\n"; //se guarda el userId del doctor.
		}
		cout << "¡Datos Guardados Exitosamente!" << endl;
		fs.close();
	}
}
/*
	to_string imprime los datos del doctor.

	imprime la informacion de login de un doctor: nombre, servicio.
	usando stringstream

	@param 
	@return string con los valores y texto concatenado.
*/
string Doctor::to_string()
{
	stringstream ss;
	ss << "Bienvenido/a, doctor/a " << nombre << endl;
	if (servicio == 1) { ss << "Servicio: Cirugia General" << endl; }
	else if (servicio == 2) { ss << "Servicio: Gineco-Obstetricia" << endl; }
	else if (servicio == 3) { ss << "Servicio: Medicina Interna" << endl; }
	else if (servicio == 4) { ss << "Servicio: Pediatria" << endl; }
	else if (servicio  == 5) { ss << "Servicio: Urgencias" << endl; }
	else { ss << "Servicio: Medicina familiar" << endl; }

	return ss.str();
}
