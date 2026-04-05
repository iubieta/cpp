## Diferencias entre contenedores

**Acceso y navegación:**

| Operación | vector | list |
|---|---|---|
| Acceso por posición | `reference operator[](size_type n)` | No disponible, usar `std::advance` |
| Inicio | `iterator begin()` | `iterator begin()` |
| Fin | `iterator end()` | `iterator end()` |
| Tamaño | `size_type size()` | `size_type size()` |
| Vacío | `bool empty()` | `bool empty()` |
| Avanzar iterador | `it + n` (O(1)) | `void advance(InputIt &it, Distance n)` (O(n)) |
| Distancia | `last - first` (O(1)) | `difference_type distance(InputIt first, InputIt last)` (O(n)) |

**Inserción y eliminación:**

| Operación | vector | list |
|---|---|---|
| Añadir al final | `void push_back(const T &val)` | `void push_back(const T &val)` |
| Insertar uno | `iterator insert(iterator pos, const T &val)` | `iterator insert(iterator pos, const T &val)` |
| Insertar rango | `void insert(iterator pos, InputIt first, InputIt last)` | `void insert(iterator pos, InputIt first, InputIt last)` |
| Eliminar uno | `iterator erase(iterator pos)` | `iterator erase(iterator pos)` |
| Eliminar rango | `iterator erase(iterator first, iterator last)` | `iterator erase(iterator first, iterator last)` |

**Intercambio:**

| Operación | vector | list |
|---|---|---|
| Swap elementos | `void swap(T &a, T &b)` | `void swap(T &a, T &b)` |
| Swap rangos | `ForwardIt2 swap_ranges(ForwardIt1 first1, ForwardIt1 last1, ForwardIt2 first2)` | `ForwardIt2 swap_ranges(ForwardIt1 first1, ForwardIt1 last1, ForwardIt2 first2)` |

**Algoritmos:**

| Operación | vector | list |
|---|---|---|
| Búsqueda binaria | `ForwardIt lower_bound(ForwardIt first, ForwardIt last, const T &val, Compare comp)` O(log n) | `ForwardIt lower_bound(ForwardIt first, ForwardIt last, const T &val, Compare comp)` O(n) |
| Copiar | `OutputIt copy(InputIt first, InputIt last, OutputIt result)` | `OutputIt copy(InputIt first, InputIt last, OutputIt result)` |
| Buscar adyacentes | `ForwardIt adjacent_find(ForwardIt first, ForwardIt last, BinaryPred pred)` | `ForwardIt adjacent_find(ForwardIt first, ForwardIt last, BinaryPred pred)` |
| Mínimo | `const T &min(const T &a, const T &b)` | `const T &min(const T &a, const T &b)` |



## Descripicon de funciones 

**Acceso y navegación:**

| Función | Firma |
|---|---|
| `vec[n]` | `reference operator[](size_type n)` |
| `begin()` | `iterator begin()` |
| `end()` | `iterator end()` |
| `size()` | `size_type size()` |
| `empty()` | `bool empty()` |
| `std::advance` | `void advance(InputIterator &it, Distance n)` |
| `std::distance` | `difference_type distance(InputIterator first, InputIterator last)` |

**Inserción y eliminación:**

| Función | Firma |
|---|---|
| `push_back` | `void push_back(const value_type &val)` |
| `insert` (uno) | `iterator insert(iterator pos, const value_type &val)` |
| `insert` (rango) | `void insert(iterator pos, InputIterator first, InputIterator last)` |
| `erase` (uno) | `iterator erase(iterator pos)` |
| `erase` (rango) | `iterator erase(iterator first, iterator last)` |

**Intercambio:**

| Función | Firma |
|---|---|
| `std::swap` | `void swap(T &a, T &b)` |
| `std::swap_ranges` | `ForwardIt2 swap_ranges(ForwardIt1 first1, ForwardIt1 last1, ForwardIt2 first2)` |

**Algoritmos:**

| Función | Firma |
|---|---|
| `std::lower_bound` | `ForwardIt lower_bound(ForwardIt first, ForwardIt last, const T &value)` |
| `std::lower_bound` (custom) | `ForwardIt lower_bound(ForwardIt first, ForwardIt last, const T &value, Compare comp)` |
| `std::copy` | `OutputIt copy(InputIterator first, InputIterator last, OutputIt result)` |
| `std::adjacent_find` | `ForwardIt adjacent_find(ForwardIt first, ForwardIt last, BinaryPredicate pred)` |
| `std::min` | `const T &min(const T &a, const T &b)` |

Todas están en `<algorithm>` excepto `advance`/`distance` que están en `<iterator>`, y `swap` que está en `<algorithm>` (C++98).
