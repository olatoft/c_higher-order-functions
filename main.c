#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int value;
    struct Node* next;
} Node;


Node* create_internal(int* input, int remaining);


int sum(Node* node) {
    if (node->next == NULL) {
        return node->value;
    } else {
        return node->value + sum(node->next);
    }
}


void push(Node* node, int value) {
    if (node->next == NULL) {
        Node* new_node = malloc(sizeof(Node*));
        new_node->value = value;
        new_node->next = NULL;
        node->next = new_node;
    } else {
        push(node->next, value);
    }
}


Node* create(int nodes[], int n_nodes) {
    return create_internal(nodes, n_nodes);
}


Node* create_internal(int* input, int remaining) {
    if (remaining == 0) {
        return NULL;
    } else {
        Node* node = malloc(sizeof(Node*));
        node->value = *input;
        node->next = create_internal(input + 1, remaining - 1);
        return node;
    }
}


void delete(Node* node) {
    if (node->next != NULL) {
        delete(node->next);
    }

    free(node);
}


int add(int x, int y) {
    return x + y;
}


int multiply(int x, int y) {
    return x * y;
}


int reduce(int f(int x, int y), Node* node) {
    if (node->next == NULL) {
        return node->value;
    } else {
        return f(node->value, reduce(f, node->next));
    }
}


int main() {
    int nodes[] = {1, 2, 3, 4};
    int n_nodes = 4;
    int* malloc_nodes = malloc(sizeof(int) * n_nodes);

    for (int i = 0; i < n_nodes; i++) {
        malloc_nodes[i] = nodes[i];
    }

    Node* node = create(nodes, n_nodes);
    free(malloc_nodes);
    printf("%d\n", sum(node));
    printf("%d\n", reduce(add, node));
    printf("%d\n", reduce(multiply, node));
    free(node);

    return 0;
}
