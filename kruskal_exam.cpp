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

void printaristas(const arista * array, const int size) {

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

int calcularpeso(const arista * arbol, const int size) {

	int weigth = 0;

	for (int i = 0; i < size; ++i) {
		weigth += arbol[i].weigth;
	}

	return weigth;
}

bool arista_igual(const arista first, const arista second) {

	return first.origin == second.origin && first.destiny == second.destiny && first.weigth == second.weigth;
}

bool contiene_arista(arista * arbol, const int size, arista elemento) {

	for (int i = 0; i < size; ++i) {
		
		if (arista_igual(arbol[i], elemento)) {
			return true;
		}
	}
	
	return false;
}

void generar_aristas_segundo_arbol(arista * aristas, const int numero_aristas, arista * arbol, const int aristas_arbol, arista * grafo_resultante) {

	int index = 0;

	for (int i = 0; i < numero_aristas; ++i)
	{
		if (!contiene_arista(arbol, aristas_arbol, aristas[i])) {
			grafo_resultante[index++] = aristas[i];
		}
	}
}

int main(int argc, char const *argv[])
{
	int numero_aristas = 0, numero_vertices = 0, numero_aristas_segundo_grafo = 0;

	cin >> numero_vertices >> numero_aristas;

	numero_aristas_segundo_grafo = numero_aristas - (numero_vertices - 1);
	arista aristas[numero_aristas], arbol_minimo[numero_vertices - 1], aristas_segundo_grafo[numero_aristas_segundo_grafo], segundo_arbol_minimo[numero_vertices - 1];

	for (int i = 0; i < numero_aristas; ++i)
	{
		cin >> aristas[i].origin >> aristas[i].destiny >> aristas[i].weigth;
	}
	
	cout << "Grafo inicial\n";
	printaristas(aristas, numero_aristas);
	size_t structs_len = sizeof(aristas) / sizeof(struct arista);
	qsort (aristas, structs_len, sizeof(struct arista), compare);
	cout << "Grafo ordenado\n";
	printaristas(aristas, numero_aristas);
	generararbol_expansionminima(arbol_minimo, aristas, numero_vertices);
	cout << "Arbol de expansion minima, peso: " << calcularpeso(arbol_minimo, numero_vertices - 1) << endl;
	printaristas(arbol_minimo, numero_vertices - 1);

	generar_aristas_segundo_arbol(aristas, numero_aristas, arbol_minimo, numero_vertices - 1, aristas_segundo_grafo);
	
	cout << "Segundo grafo inicial\n";
	printaristas(aristas_segundo_grafo, numero_aristas_segundo_grafo);
	size_t structs_len2 = sizeof(aristas_segundo_grafo) / sizeof(struct arista);
	qsort (aristas_segundo_grafo, structs_len2, sizeof(struct arista), compare);
	cout << "Segundo grafo ordenado\n";
	printaristas(aristas_segundo_grafo, numero_aristas_segundo_grafo);
	generararbol_expansionminima(segundo_arbol_minimo, aristas_segundo_grafo, numero_vertices);
	cout << "Segundo arbol de expansion minima, peso: " << calcularpeso(segundo_arbol_minimo, numero_vertices - 1) << endl;
	printaristas(segundo_arbol_minimo, numero_vertices - 1);

}
