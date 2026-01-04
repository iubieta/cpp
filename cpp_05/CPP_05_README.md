# CPP Module 05 — Repetition and Exceptions

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
- Interacción entre objetos
- Un `Bureaucrat` firma un `Form`
- Control de permisos mediante excepciones

### ex02 — AForm + Forms concretos
- Clase abstracta `AForm`
- Ejecución polimórfica
- Separar **validación** de **acción**
- Tres forms con comportamientos distintos

### ex03 — Intern
- Crear objetos sin conocer su tipo concreto
- Factory sin `if/else` gigantes
- Manejo de errores si el form no existe

## Objetivo final
Pensar en **diseño**, no solo en código:
- ¿Quién valida?
- ¿Quién ejecuta?
- ¿Quién es responsable de qué?

Aprender a escribir código **robusto, extensible y mantenible**.

