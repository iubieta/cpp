# CPP 06 - Conversion entre tipos de datos

### [Subject](CPP_06.pdf)

## Ejercicios

### ex00
- Escribe una clase `ScalarConverter`
- Esta clase no debe guardar nada por lo tanto no debe ser instanciable
- Con una funcion estatica `convert` que coja un string que represente un literal 
en su forma mas comun de C++ y lo devuelva como: 
    - char      ->  'a', 'b', 'c'
    - int       ->  0, -42, 42
    - float     ->  0.0f, -42.0f, 42.0f (incluir: +inff, -inff, nanf)
    - double    ->  0.0, -42.0, 42.0 (incluir: +inf, -inf, nan)
- Se usara notacion decimal exceptuando para los caracteres
- Escribe un programa que testee la funcion:
    - Recoge un literal como argument
    - Detecta el tipo correspondiente
    - Lo convierte de string a ese tipo
    - Despues lo convierte explicitamente al resto de tipos
    - Si no tiene sentido o crea indica que la conversion es imposible
    - Incluye los headers necesarios para gestionar los limites numericos 
    y valores excepcionales

> [!WARNING]
> No se usaran caracteres no imprimible como entrada

### ex01
- Escribe una clase `Serializer`
- No debe poder inicializarse
- Tiene que tener los siguientes metodos estaticos:
    - `uintptr_t serialize(Data* ptr)`: coge un puntero y lo convierte al tipo unsigned int `uintptr_t`
    - `Data *deserialize(uintptr_t raw)`: coge un unsigned int y lo convierte a un puntero a Data
- Crea una estructuta `Data` que no este vacia
- Escribe un programa que serialice la direccion del objeto Data y deserialice su resultado. 
El resultado final debe ser igual al puntero original.

### ex02
- Implementa una clase `Base` que solo tenga un destructor virtual publico
- Crea 3 clases vacias A, B y C que hereden de Base
- Añade estas funiones:
    - `Base *generate(void)`: inicializa aleatoriamente un objeto A, B o C y devuelbe un puntero a Base del mismo
    - `void identify(Base *p)`: imprime el tipo del objeto. A, B o C.
    - `void identify(Base &p)`: imprime el tipo del objeto pero en esta funcion esta prohibido usar punteros.

> [!WARNING]
> No hace falta usar la forma canonica en este jercicio
> Incluir el header `typeinfo` esta prohibido

## Referencias:

### Geeks4Geeks

Explicaciones mas sencillas y directas con ejemplos claros

- [Funciones Estaticas](https://www.geeksforgeeks.org/cpp/static-member-function-in-cpp/)

- [Conjversion entre tipo C++](https://www.geeksforgeeks.org/cpp/type-conversion-in-c/)
- [static_cast](https://www.geeksforgeeks.org/cpp/static_cast-in-cpp/)
- [dynamic_cast](https://www.geeksforgeeks.org/cpp/dynamic-_cast-in-cpp/)
- [const_cast](https://www.geeksforgeeks.org/cpp/const_cast-in-c-type-casting-operators/)
- [reinterpret_cast](https://www.geeksforgeeks.org/cpp/reinterpret_cast-in-c-type-casting-operators/)

### cppreference

Referencia principal de c++

- [implicit conversion](https://en.cppreference.com/w/cpp/language/implicit_conversion.html)
- [static_cast](https://en.cppreference.com/w/cpp/language/static_cast.html)
- [dynamic_cast](https://www.en.cppreference.com/w/cpp/language/dynamic_cast.html)
- [const_cast](https://www.en.cppreference.com/w/cpp/language/const_cast.html)
- [reinterpret_cast](https://en.cppreference.com/w/cpp/language/reinterpret_cast.html)

