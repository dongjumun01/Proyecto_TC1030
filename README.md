# Proyecto_TC1030 : El programa para registrar los datos de nuevos pacientes y calcular y confirmar el pago

Este proyecto es para facilitar el proceso de registrar los datos de los nuevos pacientes de un hospital y el proceso de calcular el monto total y confirmar el pago.

![Proyecto2(1) drawio](https://github.com/DongjuMun/Proyecto_TC1030/assets/150094637/ce640048-cbd2-437e-856f-b040eef80cbe)


Primero, en la super clase, tenemos 'Empleado'. Empleado tiene dos atributos protegidos que se llaman userId y password. En los metodos, tiene dos constructores y setters y getteres de los atributos. 

En las subclases de la super clase 'Empleado', tenemos la clase 'Doctor' y 'Administrativo'. Doctor tiene dos atributos. El primero es el arreglo de objetos de la clase 'DatoDePaciente' y el segundo es el 'servicio' de tipo integer. El atributo 'servicio' es para distringuir en que serivicio está el/la doctor/a. La clase igual tiene dos constructores y setter y getter para el atributo 'servicio'. Ya que la clase 'DatoDePaciente' está en la relacion de agregación con la clase 'Doctor', el constructor de 'Doctor' con parametros recibe el objeto de 'DatoDePaciente' como parametro. También recibe el 'userId' y el 'password' de la super clase 'Empleado', y el atributo 'servicio'. La clase 'Administrativo' tiene dos atributos; 'idDePaciente' y 'haPagado'. 'idDePaciente' es para identificar el id del paciente y buscar su monto total con ese id. El atributo 'haPagado' es para guardar la información de la que el paciente sí lo ha pagado o no. La 'Administrativo' también tiene dos constructores. En el constructor, recibe 'userId' y 'password' de la super clase, 'idDePaciente' y 'haPagado' como parametros. La clase tiene setters y getteres para sus atributos y un método que se llama 'guardarInfoDeHaPagado'. Ese método recibe 'idDePaciente' y 'haPagado' como parametros y guarda estos datos en un archivo de texto. 

En la clase de 'DatoDePaciente' que está en la relación de agregación con la clase 'Doctor', hay 9 atributos. Solo mencionaré algunos atributos que necesitan explicaciones. El atributo 'fechaDeNacimiento', 'fechaInicio' y 'fechaFin' se van a guardar como '16/05/2024' y por eso su tipo es string. El atributo 'diagnosis' y 'sintoma' van a ser como las notas de los doctores. El atributo 'estudio' y 'tratamiento' son arreglos porque ya hay una lista de los estudios/tratamientos( o medicamentos) y de base de estas listas van a agregar los datos booleanes en los arreglos. Por ejemplo, si estudio[3] es estudio de sangre y el paciente lo necesitó, entonces el valor de 'estudio[3]' va a ser 'true'. Ya que estos arreglos no pueden recibir los valores booleanes una vez, en el setter de estos dos atributos recibe nada como parametro (void) y dentro de los setteres va a preguntar los valores booleanes usando ciclo for. También la clase tiene un objeto de la clase 'InfoDePago' y lo va a recibir en el constructor. 

La clase 'DatoDePaciente' tiene 2 constructores como las otras y setteres y getteres de los atributos. En el constructor con parametros va a recibir el atributo 'nombre', 'sexo', 'fechaDeNacimiento', 'numDeCama', 'diagnosis', 'estudio'(como arreglo), 'sintoma', 'tratamiento'(como arreglo), 'fechaInicio', 'fechaFin' y el objeto 'infoDePago' de la clase 'InfoDePago'. Ya que la clase 'InfoDePago' está en relación de composición con la clase 'DatoDePaciente', en el constructor con parametros, va a crear un objeto nuevo que recibe el parametro 'estudio', 'tratamiento', 'fechaInicio', y 'fechaFin' y va a asignar ese objeto al objeto 'infoDePago'. El método 'creaIdDePaciente' va a regresar el Id de paciente usando una cierta ley que utiliza los datos del atributo 'nombre', 'sexo', y 'fechaDeNacimiento' para crear el Id de paciente. Ese método se va a utilizar para el atributo 'idDePaciente' de la clase 'Administrativo'. El método 'guardarDatoDePaciente' es para guardar el dato de un paciente en un archivo de texto y sus parametros son el id de Paciente usando el método 'crearIdDePaciente', el atributo 'numDeCama', 'diagnosis', 'estudio', 'sintoma', 'tratamiento', 'fechaInicio', y 'fechaFin'. El último método 'guardarInfoDePago' recibe el Id de paciente usando el método 'crearIdDePaciente' y el monto total del paciente usando el método 'getMontoTotal' de la clase 'InfoDePago' y guarda estos datos en un archivo de texto. Este archivo se revisa con el método 'cargaMontoTotal' de la clase 'Administrativo' que regresa el monto total del archivo de texto. 

La clase 'InfoDePago' tiene 4 atributos que son atributos de la clase 'DatoDepaciente'; 'estudio', 'tratamiento', 'fechaInicio' y 'fechaFinal'. La clase tiene dos constructores y un cosntructor con parametros se usa en el constructor de la clase 'DatoDePaciente' para recibir esos atributos. La clase 'InfoDePago' tiene setteres y getteres de los atributos y tiene un método que se llama 'getMontoTotal'. El método recibe los atributos 'listaDeEstudios', 'listaDeTratamiento', 'fechaInicial' y 'fechaFinal' y con estos datos va a decidir el monto total del paciente y va a regresar ese valor como floatante.

Cuando el programa corre, el menu se imprime y le va a pedir al usario que acción quiere. Habrá 3 opciones: 1. Guardar el dato de paciente 2. Checar el monto total de paciente y cambiar el estado de pago de paciente 3. Salir. Luego el programa le va a pedir al usario el userId y el password y si es correcto (depende de que sí es doctor o administrativo, se va a llevar a cabo esa cierta acción. 

# Cambio del avance 2

![Proyecto2_2_1](https://github.com/DongjuMun/Proyecto_TC1030/assets/150094637/1b1841c7-1a2a-4c6c-8b24-66b2af693927)

El gran cambio que podemos ver en el nuevo diagrama es la falta de una clase. Eliminé la clase "InfoDePago" ya que puedo realizar los metodos en el método "guardarInfoDePago" de la clase "Doctor" sin la necesidad de crear una clase nueva, asignar sus atributos y calcular el monto total. En ese método "guardarInfoDePago" de la clase Doctor, vamos a guardar no solo las informaciones del paciente y el monto total, sino también vamos a añadir el login información del doctor para que si pase algun problema con el pago, puedan preguntarle al doctor que se encarga de ese paciente. Por el mismo razón, moví el método "guardarInfoDePaciente" que estaba en la clase de DatoDePaciente a la clase de Doctor, para guardar la información del doctor también. 

El otro cambio que podemos ver es el atributo "datoDePaciente" de la clase "Doctor". Usé vector para que aunque no sepamos cuantos pacientes vamos a añadir, usando vector pudieramos añadir datos de pacientes sin tener limitación. Así que usando el nuevo método "agregarDatoDePaciente" vamos a agregar elementos al vector atributo "datoDePaciente" de la clase Doctor. También creé un getter para el vector "getDatoDePaciente".

Para la parte de sobreescritura, añadí 3 métodos nuevos que se llaman "checaLogInfo" en la clase madre "Empleado", en la clase hija "Doctor" y "Administrativo". El método "checaLogInfo" de la clase "Doctor" recibe 3 parametros (userId, password, servicio) para checar que si la login información del usario (doctor) está en el sistema y, al contrario, el de la clase "Administrativo" recibe 2 parametros (userId, password) para checar su login información. Ya que es sobreescritura, en la clase madre "Empleado" también existe ese método. 

Para la parte de sobrecarga, en la clase "Doctor" y la clase "Administrativo", hay 3 constructores y uno de ellos reciben solo el "userId" y "password" como parametros y otro recibe todos los atributos de cada clase.

Otros pequeños cambios fueron el tipo de return de "getEstudio()" y "getTratamiento()" de la clase "DatoDePaciente". Ahora van a regresar el puntador (la dirección de los arreglos). El otro fue agregar el método "checaIdDePaciente" de la clase "Adminstrativo". Lo creé para checar que si ese id del paciente existe en el sistema.
# Cambio del avance 3

![Proyecto2_3 drawio](https://github.com/DongjuMun/Proyecto_TC1030/assets/150094637/4bbe8922-938b-41e5-8ff1-54ae4225f74c)

El mayor cambio fue añadir la clase "Hospital" para guardar los objetos de la clase "Doctor" y "Administrativo" con "new" (para guardar estos datos de heap) a un arreglo de la clase "Empleado". En el main, para aceder a los métodos "to_string()" de las clases hijas ("Doctor" y "Administrativo") usamos "virtual" en el método "to_string()" de la clase madre "Empleado" (polimorfismo). 

Para probar el programa dejo los casos de preuba.

- caso 1
intput : 1 //opcion 1
intput : dmltk05 //id
input : qlqjsdh //pw
input : 5 //servicio
output : Bienvenido/a, doctor/a ----
output : Servicio: Urgencias
input : Pol Manolo Salinas Lopez //nombre del paciente
input : m //sexo
input : 17/01/1989 //fecha de nacimiento
input : 120 //num de cama
input : Paciente varón de 35 años, sin alergias farmacológicas conocidas y en tratamiento con olanzapina
por trastorno depresivo, derivado a urgencias por
deterioro del estado general. Según refiere la familia, presenta cuadro febril y malestar general de
aproximadamente un mes de evolución, de posible
origen urinario, que ha sido tratado con antitérmicos y posteriormente con levofloxacino. Pese a
ello, persiste clínica y empeoramiento progresivo,
presentando disnea a mínimos esfuerzos, tos no
productiva y dolor intenso en MMII. //diagnosis
input : Y
input : Y
input : N
input : N
input : N
input : Se realiza extracción de muestra para hemocultivos (positivos para Streptococcus agalactiae en 2
muestras sucesivas separadas por 3 días) y se
administra tratamiento antitérmico. Al recibir el resultado de la radiografía de tórax, se inicia tratamiento antibiótico de amplio espectro con amoxicilina-clavulánico más claritromicina. //sintoma
input : Y
input : N
input : N
input : Y
input : N
input : 19/05/2024
input : 29/05/2024
 
