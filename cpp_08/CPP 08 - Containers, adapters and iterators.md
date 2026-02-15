# CPP Module 08 - Resumen Completo

## Tema Central
Contenedores con templates, iteradores y algoritmos de la STL (Standard Template Library)

**Regla del módulo**: Usar contenedores y algoritmos STL tanto como sea posible.

---

# CONTENEDORES

## 1. Contenedores de Secuencia

### vector - Array dinámico
```cpp
std::vector<int> v;
v.push_back(10);        // Añade al final
v.pop_back();           // Elimina el último
v[0];                   // Acceso por índice O(1)
v.at(0);                // Acceso con verificación
v.front();              // Primer elemento
v.back();               // Último elemento
v.size();               // Número de elementos
v.capacity();           // Espacio reservado
v.reserve(100);         // Reservar espacio
v.resize(50);           // Cambiar tamaño
v.empty();              // ¿Está vacío?
v.clear();              // Eliminar todos
```

**Características**:
- ✅ Acceso rápido por índice O(1)
- ✅ Inserción rápida al final O(1) amortizado
- ❌ Inserción lenta al inicio/medio O(n)
- Memoria continua
- Iteradores se invalidan al reasignar

**Cuándo usar**: Acceso aleatorio y añadir al final (opción por defecto)

---

### list - Lista doblemente enlazada
```cpp
std::list<int> lst;
lst.push_back(10);      // Añade al final
lst.push_front(5);      // Añade al inicio
lst.pop_back();         // Elimina el último
lst.pop_front();        // Elimina el primero
lst.front();            // Primer elemento
lst.back();             // Último elemento
lst.insert(it, 15);     // Insertar en posición
lst.erase(it);          // Borrar en posición
lst.remove(10);         // Eliminar por valor
lst.sort();             // Ordenar
lst.reverse();          // Invertir
lst.unique();           // Eliminar duplicados consecutivos
lst.splice(it, lst2);   // Mover elementos entre listas
```

**Características**:
- ❌ Sin acceso por índice
- ✅ Inserción/borrado rápido en cualquier posición O(1)
- ✅ Iteradores estables (excepto el borrado)
- ✅ push_front() y pop_front() eficientes
- Memoria dispersa (nodos)

**Cuándo usar**: Insertar/borrar mucho en medio

---

### deque - Cola de doble extremo
```cpp
std::deque<int> dq;
dq.push_back(10);       // Añade al final
dq.push_front(5);       // Añade al inicio
dq.pop_back();          // Elimina el último
dq.pop_front();         // Elimina el primero
dq[0];                  // Acceso por índice O(1)
dq.at(0);               // Acceso con verificación
dq.front();             // Primer elemento
dq.back();              // Último elemento
```

**Características**:
- ✅ Inserción rápida en ambos extremos O(1)
- ✅ Acceso por índice O(1)
- ❌ Inserción lenta en medio O(n)
- Memoria semi-continua (bloques)

**Cuándo usar**: push_front + push_back + acceso por índice

---

## 2. Contenedores Asociativos
(Ordenados automáticamente, implementados como árboles balanceados Red-Black Tree)

### map - Diccionario (claves únicas)
```cpp
std::map<std::string, int> edades;

// Insertar/modificar
edades["Ana"] = 25;
edades.insert(std::make_pair("Luis", 30));

// Buscar
std::map<std::string, int>::iterator it = edades.find("Ana");
if (it != edades.end()) {
    std::cout << it->first << ": " << it->second;
}

// Verificar existencia
if (edades.count("Ana") > 0) { ... }  // Retorna 0 o 1

// Eliminar
edades.erase("Ana");      // Por clave
edades.erase(it);         // Por iterador

// Iterar (orden alfabético por clave)
for (std::map<std::string, int>::iterator it = edades.begin();
     it != edades.end(); ++it) {
    std::cout << it->first << ": " << it->second;
}
```

**Características**:
- Claves únicas (sobrescribe duplicados)
- Siempre ordenado por clave
- Búsqueda O(log n)
- Cada elemento es `std::pair<Key, Value>`
- `it->first` = clave (const, no modificable)
- `it->second` = valor (modificable)
- `operator[]` crea la entrada si no existe

**Cuándo usar**: Diccionario clave→valor único

**Nota**: Para modificar clave → borrar y reinsertar

---

### multimap - Diccionario (claves duplicadas)
```cpp
std::multimap<std::string, int> notas;

// Insertar (permite duplicados)
notas.insert(std::make_pair("Ana", 8));
notas.insert(std::make_pair("Ana", 9));
notas.insert(std::make_pair("Ana", 7));

// ❌ NO tiene operator[]

// Buscar todas las entradas de una clave
std::pair<iterator, iterator> rango = notas.equal_range("Ana");
for (iterator it = rango.first; it != rango.second; ++it) {
    std::cout << it->second << std::endl;  // 7, 8, 9
}

// Contar ocurrencias
int num = notas.count("Ana");  // 3 (puede ser > 1)
```

**Características**:
- ❌ NO tiene `operator[]` (¿cuál valor retornaría?)
- Permite claves duplicadas
- Usa `equal_range()` para obtener todos los valores de una clave

**Cuándo usar**: Una clave puede tener múltiples valores

---

### set - Conjunto de valores únicos
```cpp
std::set<int> numeros;

// Insertar
numeros.insert(5);
numeros.insert(3);
numeros.insert(5);         // Ignorado (duplicado)

// Buscar
std::set<int>::iterator it = numeros.find(5);
if (it != numeros.end()) { ... }

// Verificar existencia
if (numeros.count(5) > 0) { ... }  // Retorna 0 o 1

// Eliminar
numeros.erase(5);          // Por valor
numeros.erase(it);         // Por iterador

// Iterar (orden ascendente)
for (std::set<int>::iterator it = numeros.begin();
     it != numeros.end(); ++it) {
    std::cout << *it;      // Elementos son const
}
```

**Características**:
- Valores únicos (sin duplicados)
- Siempre ordenado (ascendente por defecto)
- Búsqueda O(log n)
- Elementos son const (no modificables directamente)

**Cuándo usar**: Valores únicos ordenados, eliminar duplicados

**Nota**: Para modificar → borrar y reinsertar

**Eliminar duplicados de vector**:
```cpp
std::set<int> unicos(vec.begin(), vec.end());
```

---

### multiset - Conjunto con duplicados
```cpp
std::multiset<int> numeros;

numeros.insert(5);
numeros.insert(5);         // Permite duplicados
numeros.insert(3);

int cantidad = numeros.count(5);  // 2 (puede ser > 1)

// Contenido ordenado: {3, 5, 5}
```

**Cuándo usar**: Contar frecuencias manteniendo orden

---

## 3. Adaptadores de Contenedor
(Interfaces especiales sobre contenedores, NO son iterables por defecto)

### stack - Pila LIFO (Last In, First Out)
```cpp
std::stack<int> pila;

pila.push(10);          // Apilar
pila.push(20);
pila.top();             // Ver tope (no elimina) → 20
pila.pop();             // Desapilar (elimina, no retorna)
pila.size();            // Número de elementos
pila.empty();           // ¿Está vacío?

// ❌ NO tiene: begin(), end(), operator[], front()
```

**Contenedor base**: `deque` (default), `vector`, `list`
```cpp
std::stack<int> s1;                        // Usa deque
std::stack<int, std::vector<int> > s2;     // Usa vector
std::stack<int, std::list<int> > s3;       // Usa list
```

**Cuándo usar**: LIFO (deshacer, parsear, DFS, verificar paréntesis)

---

### queue - Cola FIFO (First In, First Out)
```cpp
std::queue<int> cola;

cola.push(10);          // Encolar (al final)
cola.push(20);
cola.front();           // Ver frente → 10
cola.back();            // Ver final → 20
cola.pop();             // Desencolar (elimina del frente)
cola.size();
cola.empty();

// ❌ NO tiene: begin(), end(), operator[], top()
```

**Contenedor base**: `deque` (default), `list` (NO `vector`)
```cpp
std::queue<int> q1;                      // Usa deque
std::queue<int, std::list<int> > q2;     // Usa list
// std::queue<int, std::vector<int> > q3;  // ❌ ERROR (no tiene pop_front)
```

**Cuándo usar**: FIFO (tareas, mensajes, BFS, buffers)

---

### priority_queue - Cola con prioridad
```cpp
std::priority_queue<int> pq;

pq.push(5);
pq.push(10);
pq.push(3);
pq.top();               // 10 (mayor prioridad)
pq.pop();               // Elimina el 10
pq.top();               // 5 (ahora el mayor)

// Orden inverso (menor tiene prioridad)
std::priority_queue<int, std::vector<int>, std::greater<int> > pq_min;
pq_min.push(5);
pq_min.push(10);
pq_min.top();           // 5 (el menor)
```

**Contenedor base**: `vector` (default), `deque`

**Cuándo usar**: Procesamiento por prioridad (Dijkstra, scheduler, eventos)

---

## Cómo funcionan los adaptadores

Los adaptadores **envuelven** un contenedor y **restringen** su interfaz:

```cpp
// Simplificación de std::stack
template <typename T, typename Container = std::deque<T> >
class stack {
protected:
    Container c;  // Contenedor subyacente
    
public:
    void push(const T& val) {
        c.push_back(val);  // Delega al contenedor
    }
    
    void pop() {
        c.pop_back();
    }
    
    T& top() {
        return c.back();
    }
    
    // NO expone: begin(), end(), operator[]
};
```

---

## Tabla Comparativa Rápida

### Contenedores de Secuencia
| Contenedor | Acceso `[i]` | `push_front` | `push_back` | Insertar medio | Memoria |
|------------|--------------|--------------|-------------|----------------|---------|
| **vector** | ✅ O(1)      | ❌ O(n)      | ✅ O(1)*    | ❌ O(n)        | Continua |
| **list**   | ❌           | ✅ O(1)      | ✅ O(1)     | ✅ O(1)        | Dispersa |
| **deque**  | ✅ O(1)      | ✅ O(1)      | ✅ O(1)     | ❌ O(n)        | Bloques |

### Contenedores Asociativos
| Contenedor | Claves únicas | Ordenado | Búsqueda | `operator[]` |
|------------|---------------|----------|----------|--------------|
| **map**        | ✅ Sí     | ✅ Sí    | O(log n) | ✅ Sí        |
| **multimap**   | ❌ No     | ✅ Sí    | O(log n) | ❌ No        |
| **set**        | ✅ Sí     | ✅ Sí    | O(log n) | ❌ No        |
| **multiset**   | ❌ No     | ✅ Sí    | O(log n) | ❌ No        |

### Adaptadores
| Adaptador | Acceso | Orden salida | Base típica | Iterable |
|-----------|--------|--------------|-------------|----------|
| **stack** | Tope | LIFO (inverso) | deque | ❌ |
| **queue** | Frente/Final | FIFO (igual) | deque | ❌ |
| **priority_queue** | Mayor | Por prioridad | vector | ❌ |

---

# ITERADORES

## Concepto
Objetos que apuntan a elementos en contenedores, similares a punteros pero funcionan con cualquier contenedor.

```cpp
std::vector<int> vec;
vec.push_back(10);
vec.push_back(20);
vec.push_back(30);

std::vector<int>::iterator it = vec.begin();  // Primer elemento
std::cout << *it;                             // 10 (desreferenciar)
++it;                                         // Avanzar
std::cout << *it;                             // 20
```

## Operaciones Básicas

```cpp
// Obtener iteradores
container.begin();     // Primer elemento
container.end();       // DESPUÉS del último (no es el último)
container.rbegin();    // Último elemento (reverse)
container.rend();      // Antes del primero (reverse)

// Desreferenciar
*it;                   // Acceder al valor
it->member;            // Acceder a miembro (si es objeto)

// Avanzar/Retroceder
++it;                  // Pre-incremento (PREFERIDO, más eficiente)
it++;                  // Post-incremento (crea copia temporal)
--it;                  // Pre-decremento
it--;                  // Post-decremento

// Comparar
it == it2;             // ¿Iguales?
it != it2;             // ¿Diferentes?

// Random access (solo vector, deque)
it += 5;               // Saltar 5 posiciones
it -= 3;               // Retroceder 3
it[2];                 // Acceso como array
it < it2;              // Comparar posiciones
```

## Importante: .end() NO es el último elemento

```cpp
std::vector<int> vec = {10, 20, 30};

// Visualización:
// [10] [20] [30] [end()]
//  ↑         ↑     ↑
// begin()  último  end()

vec.begin();   // Apunta a 10
vec.end();     // Apunta DESPUÉS de 30 (posición inválida)
vec.back();    // Retorna 30 (valor, no iterador)

// Para obtener iterador al último:
std::vector<int>::iterator last = vec.end();
--last;        // Ahora apunta a 30
```

**Razón**: Permite iteración consistente `[begin, end)` (rango semiabierto)

```cpp
for (iterator it = vec.begin(); it != vec.end(); ++it) {
    // Se detiene ANTES de end(), accede correctamente al último
}
```

## Pre-incremento vs Post-incremento

```cpp
// Pre-incremento (++it) - PREFERIDO
iterator& operator++() {
    advance();
    return *this;      // Retorna referencia (sin copia)
}

// Post-incremento (it++) - MENOS EFICIENTE
iterator operator++(int) {
    iterator temp = *this;  // CREA COPIA
    advance();
    return temp;            // Retorna copia
}

// En bucles, ambos dan el MISMO resultado
// Pero ++it no crea copias innecesarias
for (iterator it = begin(); it != end(); ++it) {  // ✅ USAR ESTO
    // ...
}
```

**Regla**: Siempre usa `++it` en bucles (mismo resultado, más eficiente)

## Tipos de Iteradores

```cpp
std::vector<int>::iterator it;              // Lectura/escritura
std::vector<int>::const_iterator it;        // Solo lectura
std::vector<int>::reverse_iterator it;      // Recorrer al revés
```

### Ejemplo con const_iterator
```cpp
const std::vector<int> vec_const;
std::vector<int>::const_iterator it = vec_const.begin();
std::cout << *it;  // ✅ Leer OK
*it = 20;          // ❌ ERROR: no puedes modificar
```

### Ejemplo con reverse_iterator
```cpp
std::vector<int> vec;
vec.push_back(10);
vec.push_back(20);
vec.push_back(30);

for (std::vector<int>::reverse_iterator it = vec.rbegin();
     it != vec.rend(); ++it) {
    std::cout << *it;  // 30, 20, 10
}
```

## Categorías de Iteradores

| Categoría | Leer | Escribir | `++` | `--` | `+n` | `[]` | Ejemplo |
|-----------|------|----------|------|------|------|------|---------|
| **Input** | ✅ | ❌ | ✅ | ❌ | ❌ | ❌ | istream |
| **Output** | ❌ | ✅ | ✅ | ❌ | ❌ | ❌ | ostream |
| **Forward** | ✅ | ✅ | ✅ | ❌ | ❌ | ❌ | forward_list |
| **Bidirectional** | ✅ | ✅ | ✅ | ✅ | ❌ | ❌ | list, set, map |
| **Random Access** | ✅ | ✅ | ✅ | ✅ | ✅ | ✅ | vector, deque |

### Por contenedor:
```cpp
// Random Access (más potentes)
std::vector<int>::iterator       // ✅ Todo: ++, --, +n, []
std::deque<int>::iterator        // ✅ Todo

// Bidirectional (no saltos)
std::list<int>::iterator         // ✅ ++, -- | ❌ +n, []
std::set<int>::iterator          // ✅ ++, -- | ❌ +n, []
std::map<int, int>::iterator     // ✅ ++, -- | ❌ +n, []

// Sin iteradores
std::stack<int>                  // ❌ Sin iteradores
std::queue<int>                  // ❌ Sin iteradores
```

## Patrón de Iteración Estándar

```cpp
// Vector
std::vector<int> vec;
for (std::vector<int>::iterator it = vec.begin(); 
     it != vec.end(); 
     ++it) {
    std::cout << *it << std::endl;
}

// List
std::list<int> lst;
for (std::list<int>::iterator it = lst.begin(); 
     it != lst.end(); 
     ++it) {
    std::cout << *it << std::endl;
}

// Map (acceso a pair)
std::map<std::string, int> m;
for (std::map<std::string, int>::iterator it = m.begin(); 
     it != m.end(); 
     ++it) {
    std::cout << it->first << ": " << it->second << std::endl;
}
```

## Operaciones Avanzadas

```cpp
#include <iterator>

// advance() - Avanzar n posiciones
std::list<int>::iterator it = lst.begin();
std::advance(it, 3);  // Avanza 3 posiciones
// O(1) para Random Access, O(n) para Bidirectional

// distance() - Distancia entre iteradores
int dist = std::distance(it1, it2);

// next() y prev() (C++11, no en C++98)
```

## Invalidación de Iteradores

### Vector - Se invalidan al reasignar
```cpp
std::vector<int> vec;
vec.push_back(10);
std::vector<int>::iterator it = vec.begin();

vec.push_back(20);  // Puede reasignar memoria
// ⚠️ it podría estar invalidado

vec.reserve(100);   // Evita reasignaciones
it = vec.begin();   // Seguro
vec.push_back(30);  // it sigue válido (hay capacity)
```

### List - Estables excepto el borrado
```cpp
std::list<int> lst;
lst.push_back(10);
std::list<int>::iterator it = lst.begin();

lst.push_back(20);  // ✅ it sigue válido
lst.erase(it);      // ❌ it ahora inválido
```

## Borrar mientras iteras

```cpp
std::vector<int> vec;
vec.push_back(10);
vec.push_back(20);
vec.push_back(30);

// ❌ INCORRECTO
for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
    if (*it == 20) {
        vec.erase(it);  // it queda invalidado, ++it falla
    }
}

// ✅ CORRECTO
for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ) {
    if (*it == 20) {
        it = vec.erase(it);  // erase() retorna siguiente válido
    } else {
        ++it;
    }
}
```

---

# ALGORITMOS STL

Se encuentran en `<algorithm>` (mayoría) y `<numeric>` (numéricos).

Operan sobre **rangos de iteradores** `[begin, end)`.

## 1. Algoritmos de Búsqueda

### find() - Buscar un valor
```cpp
#include <algorithm>

std::vector<int> vec;
vec.push_back(10);
vec.push_back(20);
vec.push_back(30);

std::vector<int>::iterator it = std::find(vec.begin(), vec.end(), 20);

if (it != vec.end()) {
    std::cout << "Encontrado: " << *it << std::endl;
} else {
    std::cout << "No encontrado" << std::endl;
}
```

**Para Ex00 del módulo**:
```cpp
template<typename T>
typename T::iterator easyfind(T& container, int value) {
    return std::find(container.begin(), container.end(), value);
}
```

### find_if() - Buscar con predicado
```cpp
bool es_par(int n) {
    return n % 2 == 0;
}

std::vector<int>::iterator it = std::find_if(vec.begin(), vec.end(), es_par);
```

### count() - Contar ocurrencias
```cpp
int cantidad = std::count(vec.begin(), vec.end(), 10);
std::cout << "Aparece " << cantidad << " veces" << std::endl;
```

### count_if() - Contar con predicado
```cpp
int pares = std::count_if(vec.begin(), vec.end(), es_par);
```

### binary_search() - Búsqueda binaria
**Requiere contenedor ordenado**
```cpp
std::sort(vec.begin(), vec.end());  // Debe estar ordenado
bool existe = std::binary_search(vec.begin(), vec.end(), 20);  // O(log n)
```

---

## 2. Algoritmos de Modificación

### copy() - Copiar elementos
```cpp
std::vector<int> origen;
origen.push_back(10);
origen.push_back(20);

std::vector<int> destino(2);  // Debe tener espacio
std::copy(origen.begin(), origen.end(), destino.begin());
```

### fill() - Rellenar con valor
```cpp
std::vector<int> vec(5);
std::fill(vec.begin(), vec.end(), 42);  // [42, 42, 42, 42, 42]
```

### replace() - Reemplazar valores
```cpp
std::replace(vec.begin(), vec.end(), 10, 99);  // Cambia 10 por 99
```

### replace_if() - Reemplazar con predicado
```cpp
std::replace_if(vec.begin(), vec.end(), es_par, 0);  // Pares → 0
```

### remove() - "Eliminar" valores
**Importante**: NO elimina realmente, reorganiza el contenedor
```cpp
std::vector<int> vec;
vec.push_back(10);
vec.push_back(20);
vec.push_back(10);

std::vector<int>::iterator new_end = std::remove(vec.begin(), vec.end(), 10);
vec.erase(new_end, vec.end());  // Elimina realmente

// O en una línea (erase-remove idiom):
vec.erase(std::remove(vec.begin(), vec.end(), 10), vec.end());
```

### unique() - Eliminar duplicados consecutivos
**Solo elimina duplicados consecutivos, ordena primero si necesitas todos**
```cpp
std::vector<int> vec;
vec.push_back(10);
vec.push_back(10);
vec.push_back(20);
vec.push_back(10);

// Solo elimina consecutivos
std::vector<int>::iterator new_end = std::unique(vec.begin(), vec.end());
vec.erase(new_end, vec.end());  // vec: [10, 20, 10]

// Para eliminar TODOS los duplicados:
std::sort(vec.begin(), vec.end());
vec.erase(std::unique(vec.begin(), vec.end()), vec.end());
```

### reverse() - Invertir orden
```cpp
std::reverse(vec.begin(), vec.end());
```

---

## 3. Algoritmos de Ordenamiento

### sort() - Ordenar
**Requiere Random Access Iterators** (vector, deque)
```cpp
std::vector<int> vec;
vec.push_back(30);
vec.push_back(10);
vec.push_back(20);

std::sort(vec.begin(), vec.end());  // [10, 20, 30]

// Orden descendente
std::sort(vec.begin(), vec.end(), std::greater<int>());  // [30, 20, 10]
```

**No funciona con list** (usar `lst.sort()`):
```cpp
std::list<int> lst;
// std::sort(lst.begin(), lst.end());  // ❌ ERROR
lst.sort();  // ✅ OK
```

### stable_sort() - Ordenar manteniendo orden relativo
```cpp
std::stable_sort(vec.begin(), vec.end());
// Elementos iguales mantienen su orden original
```

### partial_sort() - Ordenar solo los primeros N
```cpp
std::partial_sort(vec.begin(), vec.begin() + 3, vec.end());
// Solo los 3 primeros están ordenados
```

### max_element() / min_element()
```cpp
std::vector<int>::iterator max_it = std::max_element(vec.begin(), vec.end());
std::cout << "Máximo: " << *max_it << std::endl;

std::vector<int>::iterator min_it = std::min_element(vec.begin(), vec.end());
std::cout << "Mínimo: " << *min_it << std::endl;
```

**Útil para Ex01 (Span)**: `shortestSpan()` y `longestSpan()`

---

## 4. Algoritmos Numéricos
Están en `<numeric>`

### accumulate() - Sumar elementos
```cpp
#include <numeric>

std::vector<int> vec;
vec.push_back(10);
vec.push_back(20);
vec.push_back(30);

int suma = std::accumulate(vec.begin(), vec.end(), 0);  // 60
//                                                  ↑
//                                            valor inicial
```

---

## 5. Algoritmos de Conjunto
**Requieren contenedores ordenados**

### set_union() - Unión
```cpp
std::vector<int> v1;  // [1, 2, 3]
std::vector<int> v2;  // [2, 3, 4]
std::vector<int> resultado(6);

std::vector<int>::iterator it = std::set_union(
    v1.begin(), v1.end(),
    v2.begin(), v2.end(),
    resultado.begin()
);
resultado.erase(it, resultado.end());
// resultado: [1, 2, 3, 4]
```

### set_intersection() - Intersección
```cpp
std::vector<int>::iterator it = std::set_intersection(
    v1.begin(), v1.end(),
    v2.begin(), v2.end(),
    resultado.begin()
);
resultado.erase(it, resultado.end());
// resultado: [2, 3]
```

### set_difference() - Diferencia (ASIMÉTRICO)
```cpp
// Elementos en v1 que NO están en v2
std::vector<int>::iterator it = std::set_difference(
    v1.begin(), v1.end(),
    v2.begin(), v2.end(),
    resultado.begin()
);
resultado.erase(it, resultado.end());
// resultado: [1]  (solo elementos de v1 que no están en v2)
```

**IMPORTANTE**: `set_difference(v1, v2)` solo retorna elementos de v1 que no están en v2.
Para obtener elementos de v2 que no están en v1, usa `set_difference(v2, v1)`.

### set_symmetric_difference() - Diferencia simétrica
```cpp
// Elementos que están en uno u otro pero NO en ambos
std::vector<int>::iterator it = std::set_symmetric_difference(
    v1.begin(), v1.end(),
    v2.begin(), v2.end(),
    resultado.begin()
);
resultado.erase(it, resultado.end());
// resultado: [1, 4]
```

**Visualización**:
```
v1 = {1, 2, 3}
v2 = {2, 3, 4}

set_union:                  {1, 2, 3, 4}
set_intersection:           {2, 3}
set_difference(v1, v2):     {1}
set_difference(v2, v1):     {4}
set_symmetric_difference:   {1, 4}
```

---

## 6. Otros Algoritmos Útiles

### for_each() - Aplicar función
```cpp
void imprimir(int n) {
    std::cout << n << " ";
}

std::for_each(vec.begin(), vec.end(), imprimir);
```

### transform() - Transformar elementos
```cpp
int duplicar(int n) {
    return n * 2;
}

std::vector<int> origen;  // [10, 20, 30]
std::vector<int> destino(3);

std::transform(origen.begin(), origen.end(), destino.begin(), duplicar);
// destino: [20, 40, 60]
```

### swap() - Intercambiar
```cpp
int a = 5, b = 10;
std::swap(a, b);  // a = 10, b = 5
```

---

## Predicados y Functores

### Predicado - Función que retorna bool
```cpp
bool es_mayor_que_10(int n) {
    return n > 10;
}

std::find_if(vec.begin(), vec.end(), es_mayor_que_10);
```

### Functor - Objeto función
```cpp
class EsMayorQue {
    int valor;
public:
    EsMayorQue(int v) : valor(v) {}
    bool operator()(int n) const {
        return n > valor;
    }
};

EsMayorQue mayor_que_15(15);
std::find_if(vec.begin(), vec.end(), mayor_que_15);
```

### Functores estándar (`<functional>`)
```cpp
std::sort(vec.begin(), vec.end(), std::greater<int>());  // Descendente
std::sort(vec.begin(), vec.end(), std::less<int>());     // Ascendente
```

---

# TABLA RESUMEN DE ALGORITMOS COMUNES

| Algoritmo | Header | Complejidad | Uso |
|-----------|--------|-------------|-----|
| `find()` | `<algorithm>` | O(n) | Buscar valor |
| `find_if()` | `<algorithm>` | O(n) | Buscar con predicado |
| `count()` | `<algorithm>` | O(n) | Contar ocurrencias |
| `binary_search()` | `<algorithm>` | O(log n) | Buscar en ordenado |
| `sort()` | `<algorithm>` | O(n log n) | Ordenar |
| `reverse()` | `<algorithm>` | O(n) | Invertir |
| `copy()` | `<algorithm>` | O(n) | Copiar |
| `fill()` | `<algorithm>` | O(n) | Rellenar |
| `replace()` | `<algorithm>` | O(n) | Reemplazar |
| `remove()` | `<algorithm>` | O(n) | Reorganizar (erase-remove) |
| `unique()` | `<algorithm>` | O(n) | Eliminar duplicados consecutivos |
| `max_element()` | `<algorithm>` | O(n) | Encontrar máximo |
| `min_element()` | `<algorithm>` | O(n) | Encontrar mínimo |
| `accumulate()` | `<numeric>` | O(n) | Sumar elementos |
| `for_each()` | `<algorithm>` | O(n) | Aplicar función |
| `transform()` | `<algorithm>` | O(n) | Transformar |
| `set_union()` | `<algorithm>` | O(n) | Unión de conjuntos |
| `set_intersection()` | `<algorithm>` | O(n) | Intersección |
| `set_difference()` | `<algorithm>` | O(n) | Diferencia (asimétrico) |

---

# CONSEJOS GENERALES

## Elección de Contenedor

```
¿Necesitas acceso por índice?
    SÍ → ¿Insertas al inicio?
        SÍ → deque
        NO → vector (opción por defecto)
    NO → ¿Insertas en medio frecuentemente?
        SÍ → list
        NO → ¿Buscas por clave?
            SÍ → ¿Claves únicas?
                SÍ → map (clave-valor) o set (solo valores)
                NO → multimap o multiset
            NO → ¿Necesitas LIFO o FIFO?
                LIFO → stack
                FIFO → queue
                Por prioridad → priority_queue
```

## Buenas Prácticas

1. **Usa `++it` en lugar de `it++`** en bucles (más eficiente)
2. **Reserva espacio en vector** si conoces el tamaño (`vec.reserve(n)`)
3. **Usa algoritmos STL** en lugar de bucles manuales cuando sea posible
4. **Verifica `!= end()`** siempre después de `find()`
5. **Erase-remove idiom** para eliminar elementos de vector
6. **Ordena antes de `unique()`** si quieres eliminar todos los duplicados
7. **Ordena antes de algoritmos de conjunto** (`set_union`, etc.)
8. **`list` no funciona con `std::sort()`**, usa `lst.sort()`

## Estándar C++98

Este resumen se basa en C++98. Características de estándares posteriores:
- ❌ No hay `auto` (C++11)
- ❌ No hay range-based for `for (int x : vec)` (C++11)
- ❌ No hay `unordered_map`/`unordered_set` (C++11)
- ❌ No hay inicialización con listas `{1, 2, 3}` (C++11)
- ❌ No hay lambdas (C++11)

---

# REFERENCIAS

- Documentación oficial de C++: https://cplusplus.com/reference/
- STL containers: https://cplusplus.com/reference/stl/
- Algorithms: https://cplusplus.com/reference/algorithm/
- Numeric: https://cplusplus.com/reference/numeric/

---

**Última actualización**: Febrero 2026
**Módulo**: CPP_08 - Templated containers, iterators, algorithms
