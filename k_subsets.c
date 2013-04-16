#include <stdio.h>

void printmatrix(int * matrix, int size) {

	int i;
	for (i = 1; i <= size; ++i) {

		printf("%d ", matrix[i]);
	}
	printf("\n");
}

int main() {

	int n, k, i , j;

	scanf("%d %d", &n, &k);

	int c[n];
	c[0] = -1;

	for (i = 1; i <= k; ++i) {
		
		c[i] = i;
	}

	j = 1;

	while (j != 0) {

		printmatrix(c, k);

		j = k;

		while (c[j] == (n - k + j)) {

			j--;
		}

		c[j]++;

		for (i = j + 1; i <= k; ++i) {
			
			c[i] = c[i - 1] + 1;
		}
	}
}
