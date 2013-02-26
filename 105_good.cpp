#include <iostream>
#include <vector>
#include <limits>
#include <stdio.h>

using namespace std;

typedef double number_type;

void build(const vector<number_type>& arr, vector<number_type>& segment_tree,
	   int vertex, int first, int last) {
    if (first == last) {
	segment_tree[vertex] = arr[first];
    } else {
	const int middle = (first + last) / 2;
	build(arr, segment_tree, 2*vertex, first, middle);
	build(arr, segment_tree, 2*vertex + 1, middle + 1, last);
	segment_tree[vertex] = min(segment_tree[2*vertex],
				   segment_tree[2*vertex + 1]);
    }
}

number_type minimum(const vector<number_type>& segment_tree,
	       int first, int last,
               int current_vertex, int current_first, int current_last) {
    if (last < first) {
	return numeric_limits<number_type>::infinity();
    }
    if ((first == current_first) && (last == current_last)) {
	return segment_tree[current_vertex];
    }
    const int middle = (current_first + current_last) / 2;
    return min(
	minimum(segment_tree, first, min(last, middle), 2*current_vertex, current_first, middle),
	minimum(segment_tree, max(first, middle + 1), last, 2*current_vertex + 1, middle + 1, current_last));
}	

int main() {
    int N;
    scanf("%d", &N);

    vector<number_type> arr(N, numeric_limits<number_type>::infinity());
    for (unsigned int i = 0; i < N; ++i) {
	scanf("%lf", &arr[i]);
    }

    vector<number_type> segment_tree(4*N, numeric_limits<number_type>::infinity());
    build(arr, segment_tree, 1, 0, N - 1);

    int M;
    scanf("%d", &M);
    for (unsigned int i = 0; i < M; ++i) {
	int begin, end;
	scanf("%d %d", &begin, &end);
	number_type result = minimum(segment_tree, begin, end - 1, 1, 0, N - 1);
	printf("%f ", result);
    }
    printf("\n");
    return 0;
}
