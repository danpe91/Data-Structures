// Counting in base 2 to generate all n-bit strings

#include <stdio.h>
#include <sys/time.h>

double timeval_diff(struct timeval * a, struct timeval * b) {
	return
	(double)(a->tv_sec + (double)a->tv_usec/1000000) -
	(double)(b->tv_sec + (double)b->tv_usec/1000000);
}

void printmatrix(int * matrix, int size) {

	int i;
	for (i = size - 1; i >= 0; --i) {

		// printf("%d ", matrix[i]? i+1 : matrix[i]);
		printf("%d ", matrix[i]);
	}
	printf("\n");
}

int main() {

	int n, i;
	struct timeval tStart, tStop;
	scanf("%d", &n);
	//gettimeofday(&tStart, NULL);
	int b[n];

	for (i = 0; i <= n; ++i) {
		b[i] = 0;
	}

	while( b[n] != 1) {

		printmatrix(b, n);

		i = 0;

		while (b[i] == 1) {

			b [i] = 0;
			i++;
		}

		b[i] = 1;
	}
	//gettimeofday(&tStop, NULL);
	//printf("\nTiempo(lexicograficas): %.4lf s\n", timeval_diff(&tStop, &tStart));
}