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

	int n, k, i , j, count = 0;
	struct timeval tStart, tStop;
	scanf("%d", &n);
	gettimeofday(&tStart, NULL);
	int c[n];

	for (k = 0; k <= n; k++) {

		c[0] = -1;

		for (i = 1; i <= k; ++i) {

			c[i] = i;
		}

		j = 1;

		while (j != 0) {
count++;
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
	//gettimeofday(&tStop, NULL);
	//printf("\nTiempo(lexicograficas): %.4lf s\n", timeval_diff(&tStop, &tStart));
	printf("%d\n", count);
}
