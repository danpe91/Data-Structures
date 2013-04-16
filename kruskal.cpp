#include <iostream>
#include <algorithm>

using namespace std;

struct arista
{
	int origin, destiny, weigth;
};

int compare(const void *a, const void *b) 
{ 
	struct arista *ia = (struct arista *)a;
	struct arista *ib = (struct arista *)b;

    return (int)(ia->weigth - ib->weigth);
} 

void printaristas(const arista * array, int size) {

	for (int i = 0; i < size; ++i)
	{
		cout << array[i].origin << ", " << array[i].destiny << " - " << array[i].weigth << endl;
	}
	cout << endl;
}

void generararbol_expansionminima(arista * arbol, const arista * aristas, const int numero_vertices) {

	int arista_arbol = 0, num_aristas = 0, nodo_origen = 0, nodo_destino = 0;

	int recorrido_kruskal[numero_vertices];
	arista arista_temporal;

	for (int i = 0; i < numero_vertices; ++i)
	{
		recorrido_kruskal[i] = i;
	}

	while (arista_arbol < numero_vertices - 1) {
		
		arista_temporal = aristas[num_aristas];
		nodo_origen = arista_temporal.origin - 1;

		while (recorrido_kruskal[nodo_origen] != nodo_origen) {
			nodo_origen = recorrido_kruskal[nodo_origen];
		}
		
		nodo_destino = arista_temporal.destiny - 1;

		while (recorrido_kruskal[nodo_destino] != nodo_destino) {
			nodo_destino = recorrido_kruskal[nodo_destino];
		}
		
		if (nodo_origen != nodo_destino) {

			if (nodo_origen < nodo_destino) {
				recorrido_kruskal[nodo_destino] = nodo_origen;
			} else {
				recorrido_kruskal[nodo_origen] = nodo_destino;
			}
			arbol[arista_arbol] = arista_temporal;
			arista_arbol++;
		}
		num_aristas++;
	}
	
}

int main(int argc, char const *argv[])
{
	int numero_aristas = 0, numero_vertices = 0;

	cin >> numero_vertices >> numero_aristas;

	arista aristas[numero_aristas], arbol_minimo[numero_vertices - 1];

	for (int i = 0; i < numero_aristas; ++i)
	{
		cin >> aristas[i].origin >> aristas[i].destiny >> aristas[i].weigth;
	}
	
	printaristas(aristas, numero_aristas);
	size_t structs_len = sizeof(aristas) / sizeof(struct arista);
	qsort (aristas, structs_len, sizeof(struct arista), compare);
	printaristas(aristas, numero_aristas);
	generararbol_expansionminima(arbol_minimo, aristas, numero_vertices);
	printaristas(arbol_minimo, numero_vertices - 1);

}

// 6 7
// 1 2 1
// 1 4 2
// 2 3 3
// 2 4 1
// 3 4 3
// 4 5 1
// 5 6 4


// Salida
// 1 2 1
// 2 4 1
// 2 3 3
// 4 5 1
// 5 6 4
