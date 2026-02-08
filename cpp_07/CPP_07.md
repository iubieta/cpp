# C++ Module 07 - Templates

## Introducción

El Módulo 07 introduce el concepto de **templates** (plantillas) en C++, una característica fundamental de la programación genérica que permite escribir código que funciona con diferentes tipos de datos.

---

## Conceptos Clave

### ¿Qué son los Templates?

Los templates permiten:
- Escribir código genérico que funciona con múltiples tipos
- Evitar duplicación de código
- Mantener type-safety (seguridad de tipos)
- Crear funciones y clases reutilizables

### Reglas Importantes

1. **Los templates deben definirse en archivos de cabecera** (.hpp, .h, o .tpp)
2. No se pueden implementar en archivos .cpp separados
3. El compilador genera código específico para cada tipo usado (instanciación)

---

## Ejercicios del Módulo

### Exercise 00: Funciones Template Básicas

**Objetivo**: Implementar funciones template simples

**Archivos**: Makefile, main.cpp, whatever.{h, hpp}

**Funciones a implementar**:

1. **swap**: Intercambia los valores de dos argumentos
   - No retorna nada
   - Modifica los valores por referencia

2. **min**: Compara dos valores y retorna el menor
   - Si son iguales, retorna el segundo
   - Retorna por referencia

3. **max**: Compara dos valores y retorna el mayor
   - Si son iguales, retorna el segundo
   - Retorna por referencia

**Requisitos**:
- Ambos argumentos deben ser del mismo tipo
- Los tipos deben soportar operadores de comparación

**Ejemplo de uso**:
```cpp
int a = 2, b = 3;
::swap(a, b);           // a=3, b=2
::min(a, b);            // retorna 2
::max(a, b);            // retorna 3

std::string c = "chaine1", d = "chaine2";
::swap(c, d);
::min(c, d);            // retorna "chaine1"
```

**Sintaxis template**:
```cpp
template <typename T>
void swap(T& a, T& b) {
    T tmp = a;
    a = b;
    b = tmp;
}
```

---

### Exercise 01: iter - Template con Arrays

**Objetivo**: Crear una función template que itera sobre arrays

**Archivos**: Makefile, main.cpp, iter.{h, hpp}

**Firma de la función**:
```cpp
template <typename T>
void iter(T* array, size_t length, void (*f)(T&));
```

**Parámetros**:
1. `array`: Dirección del array
2. `length`: Longitud del array
3. `f`: Función a aplicar a cada elemento

**Características**:
- Debe funcionar con cualquier tipo de array
- El tercer parámetro puede ser una función template instanciada
- No retorna nada

**Conceptos aplicados**:
- Punteros a funciones
- Templates con múltiples parámetros
- Iteración genérica

**Ejemplo conceptual**:
```cpp
template <typename T>
void print(T& x) { std::cout << x << std::endl; }

int array[] = {1, 2, 3, 4, 5};
iter(array, 5, print<int>);
```

---

### Exercise 02: Array - Template de Clase

**Objetivo**: Implementar una clase template `Array<T>` que encapsula un array dinámico

**Archivos**: Makefile, main.cpp, Array.{h, hpp}(, Array.tpp)

**Funcionalidad requerida**:

1. **Constructores**:
   - Constructor por defecto: crea array vacío
   - Constructor parametrizado: `Array(unsigned int n)` - crea array de n elementos
   - Constructor de copia: copia profunda independiente
   
2. **Operador de asignación**:
   - Copia profunda
   - Modificar el original o la copia no afecta al otro

3. **Operador de subscript `[]`**:
   - Acceso a elementos por índice
   - Lanza `std::exception` si el índice está fuera de rango

4. **Función `size()`**:
   - Retorna el número de elementos
   - No modifica el objeto (debe ser `const`)

**Restricciones importantes**:
- DEBE usar `new[]` para asignar memoria
- PROHIBIDA la asignación preventiva
- Nunca acceder a memoria no asignada

**Archivos**:
- `Array.hpp` o `Array.h`
- Opcionalmente `Array.tpp` para implementación

**Sintaxis de clase template**:
```cpp
template <typename T>
class Array {
private:
    T* _array;
    unsigned int _size;
    
public:
    Array();
    Array(unsigned int n);
    Array(const Array& other);
    Array& operator=(const Array& other);
    ~Array();
    
    T& operator[](unsigned int index);
    unsigned int size() const;
};
```

**Tip importante**: Probar `int * a = new int();` y mostrar `*a` para entender la inicialización por defecto.

---

## Conceptos Técnicos Fundamentales

### 1. **Instanciación de Templates**

El compilador genera código específico cuando se usa un template:
```cpp
swap(int1, int2);      // genera swap<int>
swap(str1, str2);      // genera swap<std::string>
```

### 2. **typename vs class**

En C++98, ambas son equivalentes en declaraciones template:
```cpp
template <typename T>  // preferido
template <class T>     // también válido
```

### 3. **Templates y Memoria**

- Los templates NO ocupan memoria hasta instanciarse
- Cada instanciación puede aumentar el tamaño del ejecutable
- Importante para entender el "code bloat"

### 4. **Deducción de Tipos**

El compilador puede deducir tipos automáticamente:
```cpp
swap(a, b);           // deduce tipo de a y b
swap<int>(a, b);      // tipo explícito
```

### 5. **Especialización**

Aunque no se requiere en estos ejercicios, es importante saber que los templates pueden especializarse para tipos específicos.

---

## Errores Comunes y Consejos

### ❌ Errores Frecuentes:

1. **Implementar templates en .cpp**
   - Los templates DEBEN estar en headers
   - El compilador necesita ver la implementación

2. **No usar const donde corresponde**
   - `size()` debe ser const
   - Retornar referencias const cuando sea apropiado

3. **Fugas de memoria en Array**
   - Implementar correctamente el destructor
   - Usar delete[] (no delete)

4. **No validar índices**
   - Siempre verificar bounds en operator[]

5. **Copia superficial**
   - Implementar deep copy en constructor de copia
   - Implementar deep copy en operator=

### ✅ Buenas Prácticas:

1. **Usar include guards**
   ```cpp
   #ifndef ARRAY_HPP
   #define ARRAY_HPP
   // código
   #endif
   ```

2. **Separar declaración e implementación (opcionalmente)**
   - Array.hpp para declaración
   - Array.tpp para implementación
   - Include Array.tpp al final de Array.hpp

3. **Verificar auto-asignación**
   ```cpp
   Array& operator=(const Array& other) {
       if (this != &other) {
           // asignación
       }
       return *this;
   }
   ```

4. **Inicializar punteros**
   ```cpp
   Array() : _array(NULL), _size(0) {}
   ```

---

## Relación con Conceptos OOP

### Orthodox Canonical Form con Templates

La clase `Array<T>` debe implementar:
1. Constructor por defecto
2. Constructor de copia
3. Operador de asignación
4. Destructor

### Manejo de Recursos (RAII)

- Adquirir recursos en el constructor
- Liberar recursos en el destructor
- Garantizar exception safety

---

## Herramientas de C++98 Útiles

### Para el Ejercicio 00:
- Referencias (`T&`)
- Operadores de comparación (`<`, `>`, `==`)

### Para el Ejercicio 01:
- Punteros a función
- Templates de función
- Iteración sobre arrays

### Para el Ejercicio 02:
- `new[]` y `delete[]`
- `std::exception` para manejo de errores
- `const` correctness
- Template de clase

---

## Ejemplo Completo: Min Function

```cpp
// whatever.hpp
#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template <typename T>
T const & min(T const & a, T const & b) {
    return (a < b) ? b : a;  // retorna b si son iguales
}

#endif
```

```cpp
// main.cpp
#include <iostream>
#include "whatever.hpp"

int main() {
    int a = 2;
    int b = 3;
    
    std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
    // Output: min(a, b) = 2
    
    return 0;
}
```

---

## Compilación

```bash
c++ -Wall -Wextra -Werror -std=c++98 main.cpp -o program
```

---

## Puntos Clave para Recordar

1. **Templates = Código Genérico**: Un solo código funciona con múltiples tipos
2. **Definición en Headers**: Necesario para que el compilador genere código
3. **Type Safety**: Mantiene verificación de tipos en tiempo de compilación
4. **Instanciación**: El compilador genera código específico para cada tipo usado
5. **RAII**: Especialmente importante en `Array<T>` para gestión de memoria
6. **Deep Copy**: Crítico en clases con recursos dinámicos

---

## Aplicaciones Prácticas

Los templates son fundamentales para:
- **STL (Standard Template Library)**: vector, list, map, etc.
- **Algoritmos genéricos**: sort, find, etc.
- **Smart pointers**: (en C++11+)
- **Type traits**: (en C++11+)
- **Metaprogramación**: técnicas avanzadas

---

## Próximos Pasos

Después del Módulo 07, estarás preparado para:
- **Módulo 08**: STL Containers (vector, list, map, etc.)
- **Módulo 09**: STL Algorithms y más conceptos avanzados
- Comprender mejor la implementación de la biblioteca estándar de C++

---

## Referencias Útiles

Para profundizar en templates:
- Documentación oficial de C++: https://en.cppreference.com/w/cpp/language/templates
- C++98 Standard (ISO/IEC 14882:1998)
- "C++ Templates: The Complete Guide" por Vandevoorde & Josuttis

---

## Resumen Ejecutivo

**El Módulo 07 enseña**:
- Programación genérica mediante templates
- Creación de funciones template reutilizables
- Implementación de clases template
- Gestión de memoria con templates
- Fundamentos necesarios para usar y entender la STL

**Competencias adquiridas**:
- Escribir código type-safe y reutilizable
- Implementar contenedores genéricos
- Comprender la base de la STL
- Aplicar RAII en contextos genéricos
