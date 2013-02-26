#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);
    for (int stripe_index = 0; stripe_index < N; ++stripe_index) {
	for (int line_index = 0; line_index < N; ++line_index) {
	    for (int column_index = 0; column_index < N*N; ++column_index) {
		printf("%d ", (stripe_index + line_index*N + column_index) % (N*N) + 1);
	    }
	    printf("\n");
	}
    }
    return 0;
}
