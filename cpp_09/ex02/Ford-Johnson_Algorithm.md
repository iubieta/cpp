# Algoritmo de ordenacion Ford-Johnson

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
