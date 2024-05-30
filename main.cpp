#include "Hospital.h"
#include "Empleado.h"
#include "Doctor.h"
#include "Administrativo.h"
#include "DatoDePaciente.h"

int main()
{
	Hospital hospital; //Carga la info de los empleados
	string userId = "";
	string password = "";

	//crea 3 varaiables para recibir los datos que ingresa el usario.
	string stringValue = "";
	int intValue = 0;
	bool boolValue = false;

	Doctor doctor;
	int servicio = 0;
	DatoDePaciente dato_P;
	bool arr[5];

	Administrativo administrativo;
	int numDePaciente = 0;

	int opcion = 0;
	bool exit = false;
	bool exit_opcion1 = false;
	bool exit_opcion2 = false;

	cout << "¡Bienvenido/a!\n Elige una opcion." << endl;
	while (!exit)
	{
		cout << "1. Guardar el dato de paciente " << endl;
		cout << "2. Checar el monto total de paciente y cambiar el estado de pago de paciente" << endl;
		cout << "3. Salir." << endl;
		cout << ": ";
		cin >> opcion;
		if (opcion == 1)
		{
			exit_opcion1 = false;
			while (!exit_opcion1)
			{				
				cout << "Ingresa tu id: ";
				cin >> userId;
				cout << "Ingresa tu contrasena: ";
				cin >> password;
				cout << "Ingresa en que servicio perteneces (1: Cirugia General, 2: Gineco-Obstetricia, 3: Medicina Interna, 4: Pediatria, 5: Urgencias, 6: Medicina familiar): ";
				cin >> servicio;
				
				//checa que si está en el sistema
				if (hospital.buscaEmpleado(userId, password)) //overriding
				{
					//imprime la info de el/la doctor/a
					cout << endl;
					cout << hospital.getEmpleado(hospital.getIndex())->to_string(); 
					cout << endl;

					boolValue = true;
					while(boolValue)
					{
						//guarda el nombre de el/la doctor/a del objecto hosptial.
						dato_P.setNombreDoc(hospital.getEmpleado(hospital.getIndex())->getNombre());
						//los datos de paciente
						//guarda el nombre de paciente.
						cout << "Ingresa el nombre de paciente: ";
						cin.ignore();
						getline(cin, stringValue);
						dato_P.setNombrePac(stringValue);
						//guarda el sexo del paciente.
						cout << "Ingresa el sexo de paciente (m/f): ";
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
						cin.ignore(); 
						getline(cin, stringValue); 
						dato_P.setDiagnosis(stringValue);
						//guarda los estudios que se realizaron.
						cout << "¿Se realizo el analisis de sangre? (Y/N): ";
						cin >> stringValue;
						if (stringValue == "Y") { arr[0] = true; }
						else { arr[0] = false; }
						cout << "¿Se realizo radiografia? (Y/N): ";
						cin >> stringValue;
						if (stringValue == "Y") { arr[1] = true; }
						else { arr[1] = false; }
						cout << "¿Se realizo ultrasonido? (Y/N): ";
						cin >> stringValue;
						if (stringValue == "Y") { arr[2] = true; }
						else { arr[2] = false; }
						cout << "¿Se realizo tomografia? (Y/N): ";
						cin >> stringValue;
						if (stringValue == "Y") { arr[3] = true; }
						else { arr[3] = false; }
						cout << "¿Se realizo resonancia magnetica? (Y/N): ";
						cin >> stringValue;
						if (stringValue == "Y") { arr[4] = true; }
						else { arr[4] = false; }
						dato_P.setEstudio(arr);
						//guarda el sintoma de paciente.
						cout << "Ingresa el sintoma de paciente: ";
						cin.ignore(); 
						getline(cin, stringValue); 
						dato_P.setSintoma(stringValue);
						//guarda los tratamientos que se realizaron.
						//usando arreglo
						cout << "¿Se uso adrenalina? (Y/N): ";
						cin >> stringValue;
						if (stringValue == "Y") { arr[0] = true; }
						else { arr[0] = false; }
						cout << "¿Se uso dopamina? (Y/N): ";
						cin >> stringValue;
						if (stringValue == "Y") { arr[1] = true; }
						else { arr[1] = false; }
						cout << "¿Se uso dobutamina? (Y/N): ";
						cin >> stringValue;
						if (stringValue == "Y") { arr[2] = true; }
						else { arr[2] = false; }
						cout << "¿Se uso metilprednisolona? (Y/N): ";
						cin >> stringValue;
						if (stringValue == "Y") { arr[3] = true; }
						else { arr[3] = false; }
						cout << "¿Se uso salbutamol? (Y/N): ";
						cin >> stringValue;
						if (stringValue == "Y") { arr[4] = true; }
						else { arr[4] = false; }
						dato_P.setTratamiento(arr);
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
						cout << "¿Deseas guardar mas datos de paciente? (Y/N): ";
						cin >> stringValue;
						while (1)
						{
							if (stringValue == "Y")
							{
								cout << "Elegiste Y. Continua guardando mas datos." << endl;
								cout << endl;
								break;
							}
							else if (stringValue == "N")
							{
								cout << "Elegiste N. Saliendo al menu..." << endl;
								doctor.guradarInfoDePacientes(doctor.getUserId(), doctor.getServicio(), numDePaciente, doctor.getDatoDePaciente()); //guarda la informacion del paciente en un archivo de texto acecdiendo a ith miembro del vector. Tambien se guarda el id del paciente.
								doctor.guradarInfoDePago(doctor.getUserId(), numDePaciente, doctor.getDatoDePaciente()); //guarda la informacion de pago del paciente en un archivo de texto acecdiendo a ith miembro del vector. Tambien se guarda el id del Paciente.

								boolValue = false;
								exit_opcion1 = true;
								numDePaciente = 0;
								break;
							}
							else
							{
								cout << "Ingreso incorrecto." << endl;
							}
						}
					}
				}
				else //sale del ciclo
				{ 
					cout << "User Id o Password incorrecto." << endl;
					boolValue = true;
					while (boolValue)
					{
						cout << "¿Deseas intentar de nuevo? (Y/N): ";
						cin >> stringValue;
						if (stringValue == "Y") { boolValue = false; }
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
				cout << "Ingresa tu contrasena: ";
				cin >> password;
				if (hospital.buscaEmpleado(userId, password)) //Si el user id y la contraseña están en el sistema. overriding
				{
					//imprime la info del empleado
					cout << hospital.getEmpleado(hospital.getIndex())->to_string();
					//guarda la info del usario en el objeto administrativo
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
							cout << "El monto total de paciente es " << administrativo.getMontoTotal() << " (mxn)." << endl;
							while (boolValue)
							{
								cout << "¿Se ha realizado el pago? (Y/N): ";
								cin >> stringValue;
								if (stringValue == "Y")
								{
									administrativo.setHaPagado(true);
									cout << "Se esta gurando el cambio..." << endl;
									administrativo.guardaInfoDeHaPagado(administrativo.getUserId(), administrativo.getIdDePaciente(), administrativo.getHaPagado(), administrativo.getMontoTotal());
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
								cout << "¿Deseas terminar la accion? (Y/N): ";
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
					cout << "User Id o Password incorrecto." << endl;
					boolValue = true;
					while (boolValue)
					{
						cout << "¿Deseas intentar de nuevo? (Y/N): ";
						cin >> stringValue;
						if (stringValue == "Y") { boolValue = false; }
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
