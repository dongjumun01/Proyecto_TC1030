# Proyecto_TC1030 : El programa para registrar los datos de nuevos pacientes y calcular y confirmar el pago
![Proyecto_TC1030](https://github.com/DongjuMun/Proyecto_TC1030/assets/150094637/3e8dec4e-2a4a-4b79-9251-67babb062c93)
Este proyecto es para facilitar el proceso de registrar los datos de los nuevos pacientes de un hospital y el proceso de checar el monto total y cambiar el estaod de pago de paciente. 
# Funcionalidad
El programa muestra un menu que tiene 3 opciones: 1. Guardar el dato de paciente 2. Checar el monto total de paciente y cambiar el estado de pago de paciente 3. Salir. Para registar los datos de pacinete, hay que iniciar sesión ingresando el user id y el password como doctor y luego guarda los datos en el archivo de texto que se llama "userId_pacientes.txt" (userId se refiere a userId de ese doctor) y guarda el id de paciente, el monto total y user Id del doctor de cada paciente en el archivo de texto que se llama "infoDePago.txt". Para checar el monto total y cambiar el estado de pago, hay que iniciar sesión ingresando el user id y el password como administrativo y hay que ingresar el id de paciente. Luego, si el paciente ha pagado, guarda el cambio de estado de pago en el archivo de texto que se llama "userId_pago.txt" (userId se refiere a userId de ese adminstrativo). La última opción es para salir del programa.
# Consideraciones
El programa solo corre en la consola y esta hecho con c++ standard por lo que corre en todos los sistemas operativos

compilar con en window y mac: "g++ main.cpp Hospital.cpp Empleado.cpp Doctor.cpp Administrativo.cpp DatoDePaciente.cpp -o main"
                              "main" - window
                              "./main" - mac/linux





