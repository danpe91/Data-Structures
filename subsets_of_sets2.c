// Subset generation by counting in base 2
#include <stdlib.h>
#include <stdio.h>

void printmatrix(int * matrix, int size) {

	int i;
	for (i = 0; i < size; ++i) {

		printf("%d ", matrix[i]? i+1 : matrix[i]);
		//printf("%d ", matrix[i]);
	}
	printf("\n");
}

bool contains(int * matrix, int element, int size) {

	int i;
	for (i = 0; i <= size; ++i) {
		
		if ( matrix[i] == element)
			return true;
	}

	return false;
}

int * remove(int * matrix, int element, int size) {

	bool removed = false;
	int i, index;
	int returnmatrix[size - 1];

	for (i = 0, index = 0; i <= size; ++i) {
		
		if (matrix[i] != element) {

			returnmatrix[index++] = matrix[i];
		} else {
			removed = true;
		}
	}

	return removed ? returnmatrix : matrix;
}

int main() {

	int n, i;

	scanf("%d", &n);

	int * s;
	int a[n + 1];

	for (i = 0; i <= n; ++i) {
		s[i] = 0;
		a[i] = i;
	}

	a[n + 1] = n + 1;

	while(!contains(s, a[n + 1], n)) {

		printmatrix(s, n);

		i = 1;

		while ( contains(s, a[i], n)) {

			s = remove(s, a[i], n);
			i++;
		}

		//s = s + a[i];
	}

	
}