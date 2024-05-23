#include "Doctor.h"
#include "Administrativo.h"

int main()
{
	int opcion = 0;
	string userId = "";
	string password = "";
	bool exit = false;
	//crea 3 varaiables para recibir los datos que ingresa el usario.
	string stringValue = "";
	int intValue = 0;
	bool boolValue = false;
	Doctor doctor;
	int servicio = 0;
	DatoDePaciente dato_P;
	Administrativo administrativo;
	int numDePaciente = 0;
	bool exit_opcion1 = false;
	bool exit_opcion2 = false;

	cout << "¡Bienvenido/a!\n Elige una opcion." << endl;
	while (!exit)
	{
		cout << "1. Guardar el dato de paciente\n 2. Checar el monto total de paciente y cambiar el estado de pago de paciente\n 3. Salir." << endl;
		cout << ": ";
		cin >> opcion;
		if (opcion == 1)
		{
			exit_opcion1 = false;
			while (!exit_opcion1)
			{				
				cout << "Ingresa tu id: ";
				cin >> userId;
				cout << "Ingresa tu contraseña: ";
				cin >> password;
				//guardar el servicio del doctor.
				cout << "Ingresa en que servicio perteneces (1: , 2: , 3: , 4: , 5: , 6: ): ";
				cin >> servicio;
				//checa que si está en el sistema
				if (doctor.checaLogInfo(userId, password, servicio)) //overriding
				{
					//los datos de paciente
					//guarda el nombre de paciente.
					cout << "Ingresa el nombre de paciente: ";
					cin >> stringValue;
					dato_P.setNombre(stringValue);
					//guarda el sexo del paciente.
					cout << "Ingresa el sexo de paciente (M/F): ";
					cin >> stringValue;
					dato_P.setSexo(stringValue);
					//guarda la fecha de nacimiento del paciente.
					cout << "Ingresa la fecha de nacimiento de paciente (DD/MM/AA): ";
					cin >> stringValue;
					dato_P.setFechaDeNacimiento(stringValue);
					//guarda el numero de cama de paciente.
					cout << "Ingreasa el numer de cama de paciente:";
					cin >> intValue;
					dato_P.setNumDeCama(intValue);
					//guarda el diagnosis de paciente.
					cout << "Ingresa el diagnosis de paciente: ";
					cin >> stringValue;
					dato_P.setDiagnosis(stringValue);
					//guarda los estudios que se realizaron.
					//usando arreglo
					// 
					//guarda el sintoma de paciente.
					cout << "Ingresa el síntoma de paciente: ";
					cin >> stringValue;
					dato_P.setSintoma(stringValue);
					//guarda los tratamientos que se realizaron.
					//usando arreglo
					// 
					//guarda la fecha inicio.
					cout << "Ingresa la fecha inicio (DD/MM/AA): ";
					cin >> stringValue;
					dato_P.setFechaInicio(stringValue);
					//guarda la fecha fin.
					cout << "Ingresa la fecha fin (DD/MM/AA): ";
					cin >> stringValue;
					dato_P.setFechaFin(stringValue);
					//se guarda el login informacion del doctor con el dato de paciente.
					doctor.setUserId(userId);
					doctor.setPassword(password);
					doctor.setServicio(servicio);
					doctor.agregarPaciente(dato_P);
					numDePaciente++; //para saber cuantos pacinetes lleva el doctor.
					cout << "¡Dato guardado exitosamente!" << endl;

					boolValue = true;
					while (boolValue)
					{
						cout << "¿Deseas guardar más datos de paciente? (Y/N): ";
						cin >> stringValue;
						if (stringValue == "Y")
						{
							cout << "Elegiste Y. Continua guardando más datos." << endl;
							boolValue = false;
						}
						else if (stringValue == "N")
						{
							cout << "Elegiste N. Saliendo al menu..." << endl;
							for (int i = 0; i < numDePaciente; i++)
							{
								doctor.guradarInfoDePacientes(doctor.getUserId(), doctor.getPassword(), doctor.getServicio(), doctor.getDatoDePaciente().at(i)); //guarda la informacion del paciente en un archivo de texto acecdiendo a ith miembro del vector. Tambien se guarda el id del paciente.
								doctor.guradarInfoDePago(doctor.getUserId(), doctor.getPassword(), doctor.getServicio(), doctor.getDatoDePaciente().at(i)); //guarda la informacion de pago del paciente en un archivo de texto acecdiendo a ith miembro del vector. Tambien se guarda el id del Paciente.
							}
							boolValue = false;
							exit_opcion1 = true;
							numDePaciente = 0;
						}
						else
						{
							cout << "Ingreso incorrecto." << endl;
						}
					}
				}
				else //sale del ciclo
				{ 
					boolValue = true;
					while (boolValue)
					{
						cout << "User Id o Password incorrecto." << endl;
						cout << "¿Deseas intentar de nuevo? (Y/N): ";
						cin >> stringValue;
						if (stringValue == "Y") {}
						else if (stringValue == "N")
						{
							cout << "Saliendo al menu..." << endl;
							boolValue = false;
							exit_opcion1 = true;
						}
						else
						{
							cout << "Ingreso incorrecto." << endl;
						}
					}
				} 
			}
		}
		else if (opcion == 2)
		{
			exit_opcion2 = false;
			while (!exit_opcion2)
			{
				cout << "Ingresa tu id: ";
				cin >> userId;
				cout << "Ingresa tu contraseña: ";
				cin >> password;
				if (administrativo.checaLogInfo(userId, password)) //Si el user id y la contraseña están en el sistema. overriding
				{
					administrativo.setUserId(userId);
					administrativo.setPassword(password);
					boolValue = true;
					while (boolValue)
					{
						cout << "Ingresa el id del paciente: ";
						cin >> stringValue;

						if (administrativo.checaIdDePaciente(stringValue)) //Si el id de paciente existe en el sistema,
						{
							administrativo.setIdDePaciente(stringValue);
							cout << "El monto total de paciente es " << administrativo.cargaMontoTotal(administrativo.getIdDePaciente()) << " (mxn)." << endl;
							while (boolValue)
							{
								cout << "¿Se ha realizado el pago? (Y/N): ";
								cin >> stringValue;
								if (stringValue == "Y")
								{
									cout << "Se está gurando el cambio..." << endl;
									administrativo.guardaInfoDeHaPagado(administrativo.getUserId(), administrativo.getPassword(), administrativo.getIdDePaciente(), administrativo.getHaPagado());
									cout << "¡Guradado exitosamente!" << endl;
									boolValue = false; //sale de este ciclo y del ciclo afuera.
									cout << "Saliendo al menu..." << endl;
									exit_opcion2 = true;
								}
								else if (stringValue == "N")
								{
									cout << "El pago no se ha realizado." << endl;
									boolValue = false; //sale de este ciclo y del ciclo afuera.
									cout << "Saliendo al menu..." << endl;
									exit_opcion2 = true;
								}
								else
								{
									cout << "Ingreso incorrecto." << endl;
								}
							}
						}
						else
						{
							cout << "Ingreso incorrecto." << endl;
							while (boolValue)
							{
								cout << "¿Deseas terminar la acción? (Y/N): ";
								cin >> stringValue;
								if (stringValue == "Y")
								{
									cout << "Saliendo al menu..." << endl;
									boolValue = false;
									exit_opcion2 = true;
								}
								else if (stringValue == "N")
								{
									boolValue = false;
								}
								else
								{
									cout << "Ingreso incorrecto." << endl;
								}
							}
							if (exit_opcion2) {}
							else { boolValue = true; } // para que no salga del ciclo while afuera.
						}
					}
				}
				else
				{
					boolValue = true;
					while (boolValue)
					{
						cout << "User Id o Password incorrecto." << endl;
						cout << "¿Deseas intentar de nuevo? (Y/N): ";
						cin >> stringValue;
						if (stringValue == "Y") {}
						else if (stringValue == "N")
						{
							cout << "Saliendo al menu..." << endl;
							boolValue = false;
							exit_opcion2 = true;
						}
						else
						{
							cout << "Ingreso incorrecto." << endl;
						}
					}
				}
			}
		}
		else if (opcion == 3)
		{
			cout << "Hasta luego." << endl;
			exit = true;
		}
		else
		{
			cout << "Ingreso incorreto." << endl;
		}
	}

	return 0;
}