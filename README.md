# Proyecto_TC1030 : El programa para registrar los datos de nuevos pacientes y calcular y confirmar el pago

Este proyecto es para facilitar el proceso de registrar los datos de los nuevos pacientes de un hospital y el proceso de calcular el monto total y confirmar el pago.

![Proyecto2 drawio](https://github.com/DongjuMun/Proyecto_TC1030/assets/150094637/118aae5e-59a9-468f-9bfa-43455e69fc38)

Primero, en la super clase, tenemos 'Empleado'. Empleado tiene dos atributos protegidos que se llaman userId y password. En los metodos, tiene dos constructores y setters y getteres de los atributos. 

En las subclases de la super clase 'Empleado', tenemos la clase 'Doctor' y 'Administrativo'. Doctor tiene dos atributos. El primero es el arreglo de objetos de la clase 'DatoDePaciente' y el segundo es el 'servicio' de tipo integer. El atributo 'servicio' es para distringuir en que serivicio está el/la doctor/a. La clase igual tiene dos constructores y setter y getter para el atributo 'servicio'. Ya que la clase 'DatoDePaciente' está en la relacion de composición con la clase 'Doctor', el constructor de 'Doctor' con parametros recibe el objeto de 'DatoDePaciente' como parametro. También recibe el 'userId' y el 'password' de la super clase 'Empleado', y el atributo 'servicio'. La clase 'Administrativo' tiene dos atributos; 'idDePaciente' y 'haPagado'. 'idDePaciente' es para identificar el id del paciente y buscar su monto total con ese id. El atributo 'haPagado' es para guardar la información de la que el paciente sí lo ha pagado o no. La 'Administrativo' también tiene dos constructores. En el constructor, recibe 'userId' y 'password' de la super clase, 'idDePaciente' y 'haPagado' como parametros. La clase tiene setters y getteres para sus atributos y un método que se llama 'guardarInfoDeHaPagado'. Ese método recibe 'idDePaciente' y 'haPagado' como parametros y guarda estos datos en un archivo de texto. 

