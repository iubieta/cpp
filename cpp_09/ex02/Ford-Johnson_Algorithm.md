# Algoritmo de ordenacion Ford-Johnson

## Implementacion real

## Resumen del algoritmo Ford-Johnson

**Estructura general:** Una función recursiva que opera sobre un solo contenedor, con `groupSize` como parámetro que se duplica en cada nivel.

**Llamada inicial:** `fordJohnson(container, 1)`

**Caso base:** `container.size() / groupSize < 2` (no se pueden formar parejas)

**Fase 1 — Emparejar y comparar:**
Recorres el contenedor de 2 en 2 grupos (stride = `2 * groupSize`). Comparas los representantes (último elemento de cada grupo). Si el primero es mayor, haces swap del bloque entero de `groupSize` elementos. Si hay un número impar de grupos, el último es el straggler.

**Fase 2 — Recursión:**
`fordJohnson(container, groupSize * 2)`. Los pends viajan con sus winners automáticamente porque forman un bloque contiguo.

**Fase 3 — Inserción:**
Al volver de la recursión:
1. Copias winners y pends a **estructuras auxiliares** separadas (bloques de `groupSize`).
2. `pend₁` va directamente al inicio de la main chain (sin coste de comparación).
3. El resto de pends se insertan con **búsqueda binaria** en el orden dado por **Jacobsthal** (1, 3, 2, 5, 4, 11, 10, 9, 8, 7, 6...).
4. Para cada `pend_k`, la búsqueda binaria solo abarca desde el inicio de la main chain hasta la posición de `win_k` (no incluido).
5. El straggler se inserta al final con búsqueda binaria sobre toda la main chain.
6. Se copia el resultado de vuelta al contenedor original.

**Claves de implementación:**
- Se comparan siempre los representantes (último elemento del grupo).
- Se mueven siempre bloques completos de `groupSize`.
- `container.insert(pos, first, last)` para insertar rangos sin bucle.
- Jacobsthal indexa sobre los pends lógicos, la traducción a posición real en el contenedor es `(k-1) * 2 * groupSize`.
- No se hace erase sobre el contenedor original; se trabaja con copias auxiliares.

## Aplicacion con vectores
1. Función recursiva que recibe un vector.
2. Separa en dos vectores: principales (mayor de cada pareja) y secundarios 
(menor de cada pareja). Si hay elemento impar, va al final de secundarios.
3. Llamada recursiva con principales — devuelve principales ordenados.
4. Insertar secundarios en el vector principal ordenado, grupo a grupo según 
Jacobsthal, empezando por el índice más alto de cada grupo y terminando por 
el más bajo. Cada inserción usa búsqueda binaria acotada por el principal 
correspondiente. El elemento impar si existe se inserta al final sin techo.
5. Caso base: si el vector tiene 1 o 2 elementos, ordenarlos directamente y retornar.

## Aplicacion con listas
Con list la lógica del algoritmo es la misma que con vector, con estas diferencias:

1. No hay acceso por índice — usas iteradores.
2. Para llegar al punto medio usas `std::advance` desde el inicio del rango actual, 
con coste O(n) en lugar de O(1).
3. List es bidireccional por lo que `std::advance` acepta valores negativos, 
pero no compensa la complejidad — siempre partes desde el inicio del rango actual.
4. El algoritmo es estructuralmente idéntico pero con peor rendimiento real debido 
al coste de desplazar iteradores.
