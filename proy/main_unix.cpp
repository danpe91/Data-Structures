#include <iostream>
#include <sys/time.h>
#include "breadt_first_search_directed_graphs.h"
#include "depth_first_search_directed_graphs.h"
#include "depth_first_search_recursive_directed_graphs.h"

using namespace std;

/* retorna "a - b" en segundos */
double timeval_diff(struct timeval *a, struct timeval *b) {
	return
	(double)(a->tv_sec + (double)a->tv_usec/1000000) -
	(double)(b->tv_sec + (double)b->tv_usec/1000000);
}

int main() {

	struct timeval t_ini[3], t_fin[3];
	double secs[3];

	gettimeofday(&t_ini[0], NULL);
	breadth_runner("graph_1");
	breadth_runner("graph_2");
	breadth_runner("graph_3");
	breadth_runner("graph_4");
	gettimeofday(&t_fin[0], NULL);

	
	gettimeofday(&t_ini[1], NULL);
	depth_iterative_runner("graph_1");
	depth_iterative_runner("graph_2");
	depth_iterative_runner("graph_3");
	depth_iterative_runner("graph_4");
	gettimeofday(&t_fin[1], NULL);

	
	gettimeofday(&t_ini[2], NULL);
	depth_recursive_runner("graph_1");
	depth_recursive_runner("graph_2");
	depth_recursive_runner("graph_3");
	depth_recursive_runner("graph_4");
	gettimeofday(&t_fin[2], NULL);

	cout << endl << "A continuacion se muestra el tiempo que tardaron los metodos que tardaron\nen realizar el recorrido de los 4 grafos.\n"
	<< "El tiempo que se muestra es el tiempo en que cada metodo tardo en recorrer los 4 grafos,\ncada metodo se pone por separado con su respectivo tiempo\n\n";

	secs[0] = timeval_diff(&t_fin[0], &t_ini[0]);
	secs[1] = timeval_diff(&t_fin[1], &t_ini[1]);
	secs[2] = timeval_diff(&t_fin[2], &t_ini[2]);
	
	printf("\tRecorrido en anchura: \t\t\t\t%.16g milliseconds\n", secs[0] * 1000.0);
	printf("\tRecorrido en profundidad(iterativo): \t\t%.16g milliseconds\n", secs[1] * 1000.0);
	printf("\tRecorrido en profundidad(recursivo): \t\t%.16g milliseconds\n", secs[2] * 1000.0);
}
