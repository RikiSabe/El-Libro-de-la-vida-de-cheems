#include <algorithm>
#define all(v) v.begin(),v.end()

// Verifica si un elemento está presente en una secuencia ordenada
bool found = binary_search(all(v), value)
// Cuenta el número de ocurrencias de un valor en un rango
int count = count(all(v), value)
// Cuenta ocurrencias dependiendo la condicion
int count = count_if(all(v), condicion)
// ejemplo 1 condicion unica
// Funcion
// Cuenta todas las ocurrencias mayores a "range"
int range = (int);
int count = count_if(all(v), [range](int x) {
		return x > range;
}) 
// ejemplo 2 complex
// Funcion
int minx = (int), maxx = (int);
int count = count_if(all(v), [minx, maxx](int x){
		return x > minx && x < maxx;
})
// ejemplo 3 condicion bool
// Funcion
bool isEven(int x) {
    return x % 2 == 0;
}
// Cuenta todas las ocurrencias pares
int count = count_if(all(v), isEven)
// Retorna el minimo elemento de un conjunto
int min_e = *min_element(all(v));
// Retorna el maximo elemento de un conjunto
int max_e = *max_element(all(v));
// Llena el vector con datos consecutivos
iota(all(v),(int)) //(int) corresponde al valor inicio de la secuencia
// Combina dos conjuntos Ordenados "a" y "b" en "c"
merge(all(a),all(b),result.begin())
// Une dos conjuntos Ordenados con elementos unicos de ambos
auto it = set_union(all(a),all(b),result.begin())
result.resize(it - result.begin())
// Une dos conjuntos Ordenados con elementos que esten presentes en ambos conjuntos
auto it = set_intersection(all(a),all(b),result.begin())
result.resize(it - result.begin())
// Une dos conjuntos Ordenados con elementos que solo esten
// en el primer conjuntos y no en el segundo
auto it = set_difference(all(a),all(b),result.begin())
result.resize(it - result.begin())
// Une dos conjuntos Ordenados con elementos que esten en un conjuntos y no en ambos
auto it = set_symmetric_difference(all(a),all(b),result.begin())
result.resize(it - result.begin())
// Verifica si un conjunto estan incluido en otro conjunto
bool in = includes(all(a),all(b))
// Eliminar elementos duplicados de un conjunto
v.resize(unique(all(v)) - v.begin())