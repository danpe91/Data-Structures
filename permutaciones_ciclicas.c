#include <stdio.h>
#include <sys/time.h>

double timeval_diff(struct timeval * a, struct timeval * b) {
	return
	(double)(a->tv_sec + (double)a->tv_usec/1000000) -
	(double)(b->tv_sec + (double)b->tv_usec/1000000);
}

void printmatrix(int * matrix, int size) {

	int i;
	for (i = 1; i <= size; ++i) {

		printf("%d ", matrix[i]);
	}
	printf("\n");
}

void rotate_elements(int * matrix, int k) {

	int aux = matrix[k];
	int i;
	for (i = k; i > 0; i--) {

		matrix[i] = matrix[i - 1];
	}
	matrix[1] = aux;
}

int main() {

	int n, j, k = 0, count = 0;
	struct timeval tStart, tStop;

	printf("Número de elementos: ");
	scanf("%d", &n);
	
	gettimeofday(&tStart, NULL);

	int matrix[n];

	for (j = 0; j <= n; ++j)
		matrix[j] = j;

	while ( k != 1) {

		count++;
		printmatrix(matrix, n);
		
		k = n;

		rotate_elements(matrix, k);
		
		while( matrix[k] == k && k != 1) {

			k--;
			rotate_elements(matrix, k);

		}
	}


	gettimeofday(&tStop, NULL);
	printf("\n%d permutaciones\n", count);
	printf("Tiempo(ciclicas): %.4lf s\n", timeval_diff(&tStop, &tStart));
}
