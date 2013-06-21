#include <iostream>
#include <fstream>
#include <stack>

#ifndef OUTLINE
	#include "mat_ady.h"
	#define OUTLINE
#endif

#define si stack<int>

using namespace std;

void depth_first_search(int * recorrido, int ** matriz_de_adyacencia, int size, int initial_index) {


	int actual = 0;
	si pila;

	bool visitados[size], flag = 1;
	recorrido[0] = 0;

	for (int i = 0; i < size; ++i) {

		visitados[i] = 0;
	}

	pila.push(initial_index);
	int cont = 0;
	while(!pila.empty()) {
		
		actual = pila.top();
		
		if (!visitados[actual]) {
			recorrido[++recorrido[0]] = actual + 1;
		}

		visitados[actual] = 1;
		flag = 1;

		for (int i = 0; i < size; ++i) {

			if (matriz_de_adyacencia[actual * size + i] > 0 && !visitados[i]) {
				
				pila.push(i);
				flag = 0;
				break;
			}
		}

		if (flag) {
			pila.pop();
		}
	}
}

void depth_iterative_runner(string filename) {

	
	cout << "\n\tMetodo: Depth-first search - iterativo" << endl;
	ifstream fin(filename.c_str());
	
	int size = 0, vertices = 0, numero_de_arcos = 0, search_index = 0, contador_componentes = 0, contador_arboles = 0;

	// cout << "Número de vertices y arcos: ";
	fin >> vertices >> numero_de_arcos;
	
	int arcos[numero_de_arcos][2], matriz_de_adyacencia[vertices][vertices], recorrido[vertices];

	for (int i = 0; i < numero_de_arcos; ++i)
	{
		// cout << "Introduce arco " << i + 1 <<": ";
		fin >> arcos[i][0] >> arcos[i][1];
	}

	generar_matriz_de_adyacencia((int *)matriz_de_adyacencia, (int **)arcos, vertices, numero_de_arcos);

	depth_first_search(recorrido, (int **)matriz_de_adyacencia, vertices, search_index);

	for (int i = 1; i <= recorrido[0]; ++i)
	{
		cout << recorrido[i] << ((i != (recorrido[0])) ? ' ': '\n');
	}

}
