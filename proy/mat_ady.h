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
