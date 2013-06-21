#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;

#define MAX 500
#define INFINITO 10000000

void leer_grafo(void);

bool visitado[MAX] = {false};

int matady[MAX][MAX] = {0};
int distancia[MAX] = {MAX};
int arista[3], a, b;
int vertices, aristas;


int main() {

	queue<int> cola;
	int actual, i, j, k, ver, camino[MAX], minimovalor;
	leer_grafo();
	cola.push(a);
	for (int i = 0; i < vertices; ++i)
	{
		distancia[i] = INFINITO;
	}

	distancia[a] = 0;

	while(!cola.empty()) {

		do {

			actual = cola.front();
			cola.pop();
		} while (visitado[actual] == true || !cola.empty());

		visitado[actual] = true;

		for (int i = 0; i < vertices; ++i) {
			
			if((matady[actual][i] != 0) && (visitado[i]) == false) {

				if ((distancia[actual] + matady[actual][i]) < distancia[i]) {

					distancia[i] = distancia[actual] + matady[actual][i];
					cola.push(i);
				}
			}
		}
	}

	ver =  b;
	k = 0;
	camino[k] = b;

	while(ver != a) {

		for (j = 0; j < vertices; ++j) {
			if(matady[ver][j] != 0) {
				if(distancia[ver] == distancia[j] + matady[ver][j]) {
					break;
				}
			}
		}

		ver = j;
		k++;
		camino[k] = ver;
	}

	for (i = k; i >= 0; i--) {
		
		printf("%d ", camino[i] + 1);
	}

	printf("\n");
}

void leer_grafo(void) {

	int i, j;
	printf("Numero de vertices: ");
	scanf("%d", &vertices);
	printf("Numero de aristas: ");
	scanf("%d", &aristas);
	printf("Extremos a y b del camino mas corto: ");
	scanf("%d %d", &a, &b);
	a--;
	b--;

	for (int i = 0; i < aristas; ++i)
	{
		printf("Arista %d: ", i + 1);
		scanf("%d %d", &arista[0], &arista[1]);
		arista[0]--;
		arista[1]--;

		printf("Valor de la arista: ");
		scanf("%d", &arista[2]);
		matady[arista[0]][arista[1]] = arista[2];
		matady[arista[1]][arista[0]] = arista[2];
	}

	for (int i = 0; i < vertices; ++i)
	{
		for (int j = 0; j < vertices; ++j)
		{
			printf("%d ", matady[i][j]);
		}
		printf("\n");
	}
}

// 5 5

// 0 2 0 0 2
// 2 0 3 0 0
// 0 3 0 2 1
// 0 0 2 0 0
// 2 0 1 0 0


// 1 5 3 4


// Extremos a y b del camino mas corto: 1 4
// Arista 1: 1 2
// Valor de la arista: 2
// Arista 2: 2 3
// Valor de la arista: 3
// Arista 3: 3 4
// Valor de la arista: 2
// Arista 4: 3 5
// Valor de la arista: 1
// Arista 5: 1 5
// Valor de la arista: 2




// // Vertices, aristas
// 8 9
// // Extremos
// 1 6

// 1 2 3
// 1 8 4
// 2 3 6
// 3 4 2
// 4 5 2
// 5 6 3
// 6 7 2
// 7 4 3
// 8 3 5

