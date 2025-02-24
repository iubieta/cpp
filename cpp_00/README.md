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
requires to include the `<algorithm>` header) excepto en el modulo 08 y 09

### Requisitos
- Evitar leaks de memoria
- Clases diseñadas en `Orthodox Canonical Form` excepto si se indica lo contrario
- Prohibidas las funciones en archivos de cabecera
- Los archivos de cabecera deben ser independientes y autonomos
- Se debe evitar la doble inclusion con `include guards`

# Ejercicios

## ex00
Replicar el siguiente comportamiento:

    $>./megaphone "shhhhh... I think the students are asleep..."
    SHHHHH... I THINK THE STUDENTS ARE ASLEEP...
    $>./megaphone Damnit " ! " "Sorry students, I thought this thing was off."
    DAMNIT ! SORRY STUDENTS, I THOUGHT THIS THING WAS OFF.
    $>./megaphone
    * LOUD AND UNBEARABLE FEEDBACK NOISE *

## ex01
Simular una agenda de contactos

    
     Write a program that works as a phonebook:

     Two classes:

        - PhoneBook:
            - Array of contacts
            - Maximum of 8 contacts. Trying t add a 9th one, it will replace the oldest one.
            - Dynamic allocation is forbidden.

        - Contact:
            - Fields:
                - First name
                - Last name
                - Nickname
                - Phone number
                - Darkest secret
            - A contact cant have empty fields

     Program commands:

        - ADD:prompts input for contact info one field at a time.
        - SEARCH:
            - Display contact list:
                - 4 columns (index, first name, last name, nickname)
                - Each column 10 char wide, separated by '|'. 
                    If the text > 10 char it must be truncated and last char must be replaced by '.'
            - Then prompt input for contact selection by index:
                - Wrong (> 9): relevant behaviour
                - Right (< 9): display contact info one field per line
        - EXIT: program quits and contacts deleted.

        * Discard wrong commands

## ex02

