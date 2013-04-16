#include <iostream>
#include <queue>

#define qi queue<int>

using namespace std;

bool contiene_elemento(int ** arista, int index, int * recorrido) {

	for (int i = 1; i <= recorrido[0]; ++i)
	{
		if ((int)arista[index * 2 + 0] == recorrido[i] || (int)arista[index * 2 + 1] == recorrido[i])
			return true;
	}

	return false;
}

bool es_arbol(int ** aristas, int numero_de_aristas, int * recorrido) {

	int contador_de_aristas = 0;

	for (int i = 0; i < numero_de_aristas; ++i)
	{
		if (contiene_elemento(aristas, i,recorrido)) {
			contador_de_aristas++;
		}
	}
	
	return ((contador_de_aristas + 1) == recorrido[0])? true : false;

}

bool es_bosque(int numero_de_componentes, int numero_de_arboles) {

	return numero_de_componentes > 1 && numero_de_componentes == numero_de_arboles;
}

void generar_matriz_de_adyacencia(int * matriz_de_adyacencia, int ** aristas, int vertices, int numero_de_aristas) {

	for (int i = 0; i < vertices; ++i) {
		for (int j = 0; j < vertices; ++j) {

			matriz_de_adyacencia[i * vertices + j] = 0;
		}
	}

	for(int i = 0; i < numero_de_aristas; i++) {
		
		int x = (int)aristas[i * 2 + 0];
		int y = (int)aristas[i * 2 + 1];

		matriz_de_adyacencia[(x-1) * vertices + (y-1)] = 1;
		matriz_de_adyacencia[(y-1) * vertices + (x-1)] = 1;
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

int main() {

	cout << "Metodo" << endl;
	cout << "Breadth" << endl;
	
	int size = 0, vertices = 0, numero_de_aristas = 0, search_index = 0, contador_componentes = 0, contador_arboles = 0;

	//cout << "Número de vertices y aristas: ";
	cin >> vertices >> numero_de_aristas;
	
	int aristas[numero_de_aristas][2], matriz_de_adyacencia[vertices][vertices], recorrido[vertices];

	for (int i = 0; i < numero_de_aristas; ++i)
	{
		//cout << "Introduce arista " << i + 1 <<": ";
		cin >> aristas[i][0] >> aristas[i][1];
	}

	generar_matriz_de_adyacencia((int *)matriz_de_adyacencia, (int **)aristas, vertices, numero_de_aristas);


	while (search_index < vertices) {

		breadth_first_search(recorrido, (int **)matriz_de_adyacencia, vertices, search_index);
		
		if (es_arbol((int **)aristas, numero_de_aristas, (int *)recorrido)) {
			contador_arboles++;
		}

		cout << endl << "Componente: " << ++contador_componentes << endl << '\t';
		for (int i = 1; i <= recorrido[0]; ++i)
		{
			search_index = (recorrido[i] > search_index) ? recorrido[i] : search_index;
			cout << recorrido[i] << ((i != (recorrido[0])) ? ' ': '\n');
		}

	}
	
	cout << ((recorrido[0] == vertices) ? ("Es conexo") : ("No es conexo")) << endl;
	cout << (( ((numero_de_aristas + 1) == vertices) && (recorrido[0] == vertices)) ? ("Es arbol") : ("No es arbol")) << endl;
	cout << "Componentes: " << contador_componentes << endl;
	cout << ((es_bosque(contador_componentes, contador_arboles))  ? ("Es bosque") : ("No es bosque")) << endl;

}

