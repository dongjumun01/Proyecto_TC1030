# Proyecto_TC1030 : El programa para registrar los datos de nuevos pacientes y calcular y confirmar el pago
Este proyecto es para facilitar el proceso de registrar los datos de los nuevos pacientes de un hospital y el proceso de checar el monto total y cambiar el estaod de pago de paciente.  
# Funcionalidad
El programa muestra un menu que tiene 3 opciones: 1. Guardar el dato de paciente 2. Checar el monto total de paciente y cambiar el estado de pago de paciente 3. Salir. Para registar los datos de pacinete, hay que iniciar sesión ingresando el user id y el password como doctor y luego guarda los datos en el archivo de texto que se llama "userId_pacientes.txt" (userId se refiere a userId de ese doctor) y guarda el id de paciente, el monto total y user Id del doctor de cada paciente en el archivo de texto que se llama "infoDePago.txt". Para checar el monto total y cambiar el estado de pago, hay que iniciar sesión ingresando el user id y el password como administrativo y hay que ingresar el id de paciente. Luego, si el paciente ha pagado, guarda el cambio de estado de pago en el archivo de texto que se llama "userId_pago.txt" (userId se refiere a userId de ese adminstrativo). La última opción es para salir del programa. En la clase de Hospital tiene los objetos de Empleado como puntadores para polimorfismo y crean los datos de empleados(Doctor/Administrativo). Doctor tiene DatoDePaciente y sus atributos propios y se guardan sus datos en los archivos de texto. De ese archivo de texto (infoDePago.txt) se busca el id de paciente desde la clase Administrativo y si está ahí, depende de que ha pagado el paciente, el cambio se aplica y se guarda en el archivo de texto.
# Consideraciones 
Para inciar sesión, hay que ingresar ciertos userIds y passwords:

<Doctor>

1. userId: dmltk01 | password: qlqjsdlf | servicio: 1
  
2. userId: dmltk02 | password: qlqjsdl | servicio: 2
 
3. userId: dmltk03 | password: qlqjstka | servicio: 3
 
4. userId: dmltk04 | password: qlqjstk | servicio: 4
 
5. userId: dmltk05 | password: qlqjsdh | servicio: 5
 
6. userId: dmltk06 | password: qlqjsdbr | servicio: 6


<Administrativo>

1. userId: rufwp01 | password: alfghclf

2. userId: rufwp02 | password: alfghvkf

3. userId: rufwp03 | password: alfghrn

4. userId: rufwp04 | password: alfghtlq


Hay que tener mucho cuidado con los datos que ingreses. Si el programa pide entre 'm' y 'f', hay que ingresar 'm' o 'f' (minúscula). Si el programa pide entre 'Y' o 'N', hay que ingresar 'Y' o 'N' (mayúscula). Si el programa pide "DD/MM/YY" forma, hay que ingresar, por ejemplo, "24/05/2024". Si uno de ellos no cumplen, en el archivo de texto, se va a guardar un valor de basura y así que el programa no va a correr bien hasta que borres los valores de basura manualmente y se corra el programa de nuevo.

Para la opción 2 del programa, para ingresar el id de paciente, hay que abrir el archivo de texto "infoDePago.txt" para checar los nuevos datos recién guardados. Si no, el programa no va a correr. Los primeros letras que están separados de los otros datos en el archivo de texto son los ids.
 
El programa solo corre en la consola y esta hecho con c++ standard por lo que corre en todos los sistemas operativos

compilar con en window y mac: 
                              
                              "g++ main.cpp Hospital.cpp Empleado.cpp Doctor.cpp Administrativo.cpp DatoDePaciente.cpp -o main"

                              
                              "main" - window

                              
                              "./main" - mac/linux


# Cambios
El primer cambio eliminar la clase "InfoDePago" ya que puedo realizar los metodos en el método "guardarInfoDePago" de la clase "Doctor" sin la necesidad de crear una clase nueva, asignar sus atributos y calcular el monto total.
El otro cambio fue el atributo "datoDePaciente" de la clase "Doctor". Usé vector para que aunque no sepamos cuantos pacientes vamos a añadir, usando vector pudieramos añadir datos de pacientes sin tener limitación. Así que usando el nuevo método "agregarDatoDePaciente" vamos a agregar elementos al vector atributo "datoDePaciente" de la clase Doctor.
Ultimamente, agregé una clase "Hospital" para guardar los objetos de la clase "Doctor" y "Administrativo" con "new" (para guardar estos datos de heap) a un arreglo de puntadores de la clase "Empleado". En el main, para aceder a los métodos "to_string()" de las clases hijas ("Doctor" y "Administrativo") usamos "virtual" en el método "to_string()" de la clase madre "Empleado" (polimorfismo). 

