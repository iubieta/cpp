# Normas

### Compilacion
- c++
- flags : -Wall -Wextra - Werror (-std=c++98)

### Formato
- Class names in UpperCamelCase
- Archivo que contengan clases : NombreDeLaClase.extension
- Mensajes de salida seguidos de un salto de linea siempre
- NO HAY NORMINETTE!

### Funciones permitidas y prohibidas
- Cualquier funcion de la libreria estandar esta permitida
- Cualquier otra funcion o libreria esta prohibida
- Tambien esta prohibido :
    - printf()
    - alloc()
    - free()
- Prohibido el uso de `using namespace <>` y `friend`
- Prohibido los `Containers` (vector/list/map/...) y `Algorithms` (anything that
requires to include the <algorithm> header) excepto en el modulo 08 y 09

### Requisitos
- Evitar leaks de memoria
- Clases diseñadas en `Orthodox Canonical Form` excepto si se indica lo contrario
- Prohibidas las funciones en archivos de cabecera
- Los archivos de cabecera deben ser independientes y autonomos
- Se debe evitar la doble inclusion con `include guards`

# Modulos

## CPP_00

### ex00
Replicar el siguiente comportamiento:

    $>./megaphone "shhhhh... I think the students are asleep..."
    SHHHHH... I THINK THE STUDENTS ARE ASLEEP...
    $>./megaphone Damnit " ! " "Sorry students, I thought this thing was off."
    DAMNIT ! SORRY STUDENTS, I THOUGHT THIS THING WAS OFF.
    $>./megaphone
    * LOUD AND UNBEARABLE FEEDBACK NOISE *

