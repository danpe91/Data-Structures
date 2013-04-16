#include <stdio.h>
#include <sys/time.h>

double timeval_diff(struct timeval * a, struct timeval * b) {
	return
	(double)(a->tv_sec + (double)a->tv_usec/1000000) -
	(double)(b->tv_sec + (double)b->tv_usec/1000000);
}

void printmatrix(short * matrix, int size) {

	int i;
	for ( i = size; i > 0; i--) {

		printf("%d ", matrix[i]);
	}
	printf("\n");
}

int main() {

	int i, j, n;
	struct timeval tStart, tStop;
	
	scanf("%d", &n);
	gettimeofday(&tStart, NULL);
	
	short t[n], g[n];
	for (j = 0; j <= n + 1;  j++) {

		g[j] = 0;
		t[j] = j + 1;
	}
	i = 0;

	while (i < (n + 1)) {

		printmatrix(g, n);

		i = t[0];
		g[i] = g[i] ? 0 : 1;
		t[0] = 1;
		t[i - 1] = t[i];
		t[i] = i + 1;
	}
	gettimeofday(&tStop, NULL);
	printf("Tiempo(ciclicas): %.4lf s\n", timeval_diff(&tStop, &tStart));
}
