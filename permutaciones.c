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

int main() {

	int n, r, s, j, i = 1, count = 0;
	struct timeval tStart, tStop;

	printf("Número de elementos: ");
	scanf("%d", &n);

	gettimeofday(&tStart, NULL);

	int matrix[n];

	for (j = 0; j <= n; ++j)
		matrix[j] = j;

	while (i != 0) {
		count++;

		printmatrix(matrix, n);

		i = n - 1;

		while ( matrix[i] > matrix[i + 1]) {
			i--;
		}

		int j = n;

		while ( matrix[i] > matrix[j]) {
			j--;
		}
		
		{
			int aux = matrix[i];
			matrix[i] = matrix[j];
			matrix[j] = aux;
		}

		r = n;
		s = i + 1;

		while (r > s) {

			int aux = matrix[r];
			matrix[r] = matrix[s];
			matrix[s] = aux;

			r--;
			s++;
		}
	}

	gettimeofday(&tStop, NULL);
	printf("\n%d permutaciones\n", count);
	printf("Tiempo(lexicograficas): %.4lf s\n", timeval_diff(&tStop, &tStart));
}