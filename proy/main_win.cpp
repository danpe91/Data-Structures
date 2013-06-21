#include <iostream>
#include <windows.h>
#include "breadt_first_search_directed_graphs.h"
#include "depth_first_search_directed_graphs.h"
#include "depth_first_search_recursive_directed_graphs.h"

using namespace std;

/* retorna "a - b" en segundos */
double performancecounter_diff(LARGE_INTEGER *a, LARGE_INTEGER *b) {

  LARGE_INTEGER freq;
  QueryPerformanceFrequency(&freq);
  return (double)(a->QuadPart - b->QuadPart) / (double)freq.QuadPart;
}

int main() {
	
	LARGE_INTEGER t_ini[3], t_fin[3];
	double secs[3];

	QueryPerformanceCounter(&t_ini[0]);
	breadth_runner("graph_1");
	breadth_runner("graph_2");
	breadth_runner("graph_3");
	breadth_runner("graph_4");
	QueryPerformanceCounter(&t_fin[0]);

	
	QueryPerformanceCounter(&t_ini[1]);
	depth_iterative_runner("graph_1");
	depth_iterative_runner("graph_2");
	depth_iterative_runner("graph_3");
	depth_iterative_runner("graph_4");
	QueryPerformanceCounter(&t_fin[1]);

	
	QueryPerformanceCounter(&t_ini[2]);
	depth_recursive_runner("graph_1");
	depth_recursive_runner("graph_2");
	depth_recursive_runner("graph_3");
	depth_recursive_runner("graph_4");
	QueryPerformanceCounter(&t_fin[2]);

	cout << endl << "A continuacion se muestra el tiempo que tardaron los metodos que tardaron\nen realizar el recorrido de los 4 grafos.\n"
	<< "El tiempo que se muestra es el tiempo en que cada metodo tardo en recorrer los 4 grafos,\ncada metodo se pone por separado con su respectivo tiempo\n\n";

	secs[0] = performancecounter_diff(&t_fin[0], &t_ini[0]);
	secs[1] = performancecounter_diff(&t_fin[1], &t_ini[1]);
	secs[2] = performancecounter_diff(&t_fin[2], &t_ini[2]);
	
	printf("\tRecorrido en anchura: \t\t\t\t%.16g milliseconds\n", secs[0] * 1000.0);
	printf("\tRecorrido en profundidad(iterativo): \t\t%.16g milliseconds\n", secs[1] * 1000.0);
	printf("\tRecorrido en profundidad(recursivo): \t\t%.16g milliseconds\n", secs[2] * 1000.0);
	system("PAUSE");
}
