#include <stdio.h>

void printmatrix(int * matrix, int size) {

	int i;
	for (i = 1; i <= size; ++i) {

		printf("%d ", matrix[i]);
	}
	printf("\n");
}

int main() {

	int m, n, i;

	printf("%s", "Elementos: ");
	scanf("%d", &n);


	int matrix[n + 1], p[n], d[n], count = 0;

	for (i = 0; i <= n; ++i) {
		
		matrix[i] = p[i] = i;
		d[i] = -1;
	}

	d[1] = 0;

	matrix[0] = matrix[n + 1] = m = n + 1;

	while (m != 1) {

		count++;
		printmatrix(matrix, n);

		m = n;

		while ( matrix[p[m] + d[m]] > m) {

			d[m] = -d[m];
			m--;
		}

		{
			int aux = matrix[p[m]];
			matrix[p[m]] = matrix[p[m] + d[m]];
			matrix[p[m] + d[m]] = aux;
		}

		{
			int aux = p[matrix[p[m]]];
			p[matrix[p[m]]] = p[m];
			p[m] = aux;
		}

	}

	printf("\n%d permutaciones\n", count);

}

