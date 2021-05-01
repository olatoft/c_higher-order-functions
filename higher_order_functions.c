#include <stdio.h>


int add3(int x) {
    return x + 3;
}


void map(int f(int x), int collection[], int n) {
    for (int i = 0; i < n; i++) {
        collection[i] = f(collection[i]);
    }
}


int add(int x, int y) {
    return x + y;
}


int reduce(int f(int x, int y), int collection[], int n) {
    for (int i = 0; i < n - 1; i++) {
        collection[i + 1] = f(collection[i], collection[i + 1]);
    }

    return collection[n - 1];
}


int main() {
    int collection[] = {1, 2, 3};
    int n = 3;
    map(add3, collection, n);

    for (int i = 0; i < n; i++) {
        printf("%d\n", collection[i]);
    }

    int reduction = reduce(add, collection, n);
    printf("%d\n", reduction);

    return 0;
}
