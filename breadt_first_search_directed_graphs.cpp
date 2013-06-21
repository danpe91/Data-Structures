#include <iostream>
#include <fstream>
#include <queue>

#define qi queue<int>

using namespace std;

void generar_matriz_de_adyacencia(int * matriz_de_adyacencia, int ** arcos, int vertices, int numero_de_arcos) {

	for (int i = 0; i < vertices; ++i) {
		for (int j = 0; j < vertices; ++j) {

			matriz_de_adyacencia[i * vertices + j] = 0;
		}
	}

	for(int i = 0; i < numero_de_arcos; i++) {
		
		int x = (int)arcos[i * 2 + 0];
		int y = (int)arcos[i * 2 + 1];

		matriz_de_adyacencia[(x-1) * vertices + (y-1)] = 1;
	}

}

void breadth_first_search(int * recorrido, int ** matriz_de_adyacencia, int size, int initial_index) {

	int i;
	bool visitados[size];
	qi cola;

	for (int i = 0; i <= size; ++i)
	{
		recorrido[i] = visitados[i] = 0;
	}

	cola.push(initial_index);
	visitados[initial_index] = 1;

	for (int k = 0; k < size, !cola.empty(); ++k) {
		i = cola.front();
		cola.pop();
		visitados[i]=1;
		recorrido[++recorrido[0]] = i + 1;

		for (int j = 0; j < size; ++j) {

			if ((int)matriz_de_adyacencia[i*size+j] && (!visitados[j])) {
				
				cola.push(j);
				visitados[j] = 1;
			}
		}
	}

}

void runner(string filename) {

	cout << "\n\tMetodo: Breadth-first search - iterativo" << endl;
	ifstream fin(filename.c_str());
	
	int size = 0, vertices = 0, numero_de_arcos = 0, search_index = 0, contador_componentes = 0, contador_arboles = 0;

	//cout << "Número de vertices y arcos: ";
	fin >> vertices >> numero_de_arcos;
	
	int arcos[numero_de_arcos][2], matriz_de_adyacencia[vertices][vertices], recorrido[vertices];

	for (int i = 0; i < numero_de_arcos; ++i)
	{
		//cout << "Introduce arco " << i + 1 <<": ";
		fin >> arcos[i][0] >> arcos[i][1];
	}

	generar_matriz_de_adyacencia((int *)matriz_de_adyacencia, (int **)arcos, vertices, numero_de_arcos);

	breadth_first_search(recorrido, (int **)matriz_de_adyacencia, vertices, search_index);

	for (int i = 1; i <= recorrido[0]; ++i)
	{
		cout << recorrido[i] << ((i != (recorrido[0])) ? ' ': '\n');
	}

	
}

int main() {

	runner("graph_1");
}
