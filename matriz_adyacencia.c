#include <cstdio>

int main() {

	int vertices, aristas;
	printf("Número de vertices y aristas: ");
	scanf("%d %d",&vertices, &aristas);

	int matrizady[vertices][vertices];
	for (int i = 0; i < vertices; ++i)
	{
		for (int j = 0; j < vertices; ++j)
		{
			matrizady[i][j] = 0;
		}
	}

	for(int i = 0; i < aristas; i++) {
		
		int x, y;
		scanf("%d %d", &x, &y);
		matrizady[x-1] [y-1] = 1;
		matrizady[y-1] [x-1] = 1;
	}
	
	for(int i = 0; i < vertices; i++) {
		for(int j = 0; j < vertices;j++)

			printf("%d%c",matrizady[i][j], ((j != (vertices - 1)) ? ' ': '\n'));
	}
}
