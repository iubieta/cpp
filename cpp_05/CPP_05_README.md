CPP Module 05 — Repetition and Exceptions

## Objetivo general
Introducir **excepciones en C++** y reforzar **POO clásica**: encapsulación, herencia, polimorfismo y diseño correcto de clases.

## Normas clave
- Estándar **C++98**
- Compilar con `-Wall -Wextra -Werror`
- Clases en **Forma Canónica Ortodoxa**
- Nada de STL (containers/algorithms)
- Manejo correcto de memoria y `const`
- Uso obligatorio de **excepciones**

## Conceptos que se aprenden
- Crear y lanzar **excepciones personalizadas**
- Garantizar **invariantes de clase**
- Uso correcto de `const`
- Sobrecarga de operadores (`<<`)
- Clases abstractas e interfaces
- Polimorfismo dinámico
- Patrón **Factory**

## Ejercicios

### ex00 — Bureaucrat
Crea una clase burocrata con los siguientes condicionantes:
- Nombre constante 
- Grado entre [1–150] (max - min)
- Excepciones si el grado es inválido (deben poder recibirse con try catch)
    - Grade too high
    - Grade too low
- Getter: getName() y getGrade()
- Funciones para incrementar/decrementar con control de errores
- Overload de `<<` que imprima: "<name>, bureucrat grade <grade>"
- Tests

### ex01 — Form
- Crea la clase `Form` con:
    - Un nombre constante
    - Un booleano que indique si esta firmado o no
    - Un entero constante que indique el grado necesario para firmar
    - Un entero constante que indique el grado necesario para ejecutar
- Excepciones si el grado es inválido (deben poder recibirse con try catch)
    - Grade too high
    - Grade too low
- Getters para todos los atributos
- Overload de `<<`
- Funcion `beSigned()` que recibe un burocrata como parametro y si su grado es suficiente
firma el formulario. Sino lanza una excepcion
- Añadir funcion `signForm()` a la clase burocrata, que recibe un Form como parametro
e intenta firmalo con  `beSigned()`
    - Si tiene exito imprimir: `<bureaucrat>` signed `<form>`
    - Sino: `<bureaucrat>` couldn’t sign `<form>` because `<reason>`

### ex02 — AForm + Forms concretos
- Convertir Form en clase abstracta AForm. Manteniendo sus atributos protegidos y 
pertenenciendo a la clase base.
- Añade las siguientes subclases:
    - `ShrubberyCreationForm` : 
        - Sign grade = 145, Exec grade = 137
        - Action: Creates a file `<target>_shrubbery` in `cwd` and writes ASCII trees in it
    - `RobotomyRequestForm` : 
        - Sign grade = 72, Exec grade = 45
        - Action: Makes drilling noises, then informs that (50/50): 
        a) `<target>` has been robotomized succesfully , 
        b) robotomy failed
    - `PresidentialPardonForm` : 
        - Sign grade = 25, Exec grade = 5
        - Action: Informs that `<target>`  has been pardoned by Zaphod Beeblebrox
- Todas las subclases obtienen como unico parametro en su constructor su `<target>`
- Añade la funcion `execute(Bureaucrat const & executor) const` a la clase base 
y su implementacion en las subclases. Comprueba siempre que el formulario este firmado
y el grado de ejecucion del executor.
- Añade la funcion `executeForm(AForm const & form) const` a la clase burocrata.
Debe imprimir un mensaje de exito o error adecuado.

### ex03 — Intern
- Crear clase `Intern`: No tiene nombre, grado o atributos especificos.
- Solo tiene la funcion `makeForm()` con los siguientes parametros.
    - Nombre del formulario -> `name`
    - Objetivo del formulario -> `target`
    - Devuelve un puntero a un objeto `AForm` que corresponde con el nombre pasado
    - Si tiene exito imprime `Intern creates <form>"`,
    si el nombre del formulario no existe imprime un mensaje correspondiente
- No usar `if/else` para gestionar la creacion de formularios

## Objetivo final
Pensar en **diseño**, no solo en código:
- ¿Quién valida?
- ¿Quién ejecuta?
- ¿Quién es responsable de qué?

Aprender a escribir código **robusto, extensible y mantenible**.

