#include <stdio.h>
#include <stdlib.h>


enum OptionKind {
    Some,
    None
};


struct Option {
    enum OptionKind kind;

    union {
        int someValue;
        void* noneValue;
    };
};


struct Option* pure(int x) {
    struct Option* o = malloc(sizeof(struct Option));
    o->kind = Some;
    o->someValue = x;
    return o;
}


struct Option* map(struct Option* o, int f(int x)) {
    struct Option* newO = malloc(sizeof(struct Option));

    switch (o->kind) {
        case Some:
            newO->kind = Some;
            newO->someValue = f(o->someValue);
            return newO;

        case None:
            newO->kind = None;
            return newO;
    }
}


int add1(int x) {
    return x + 1;
}


int main() {
    struct Option* o = pure(2);
    struct Option* newO = map(o, add1);
    free(o);
    printf("%d\n", newO->someValue);
    free(newO);
    return 0;
}
