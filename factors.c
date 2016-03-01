#include <stdio.h>
#include "stack.h"

#define string char*

int input(string query) {
    int x;

    printf("%s: ", query);
    scanf("%d", &x);
    printf("\n");

    return x;
}

Stack* get_prime_factors(int x) {
    Stack* stack = create_stack();
    int is_prime = 1;

    for (int i = 2; i < x; i++) {
        while (x % i == 0) {
            is_prime = 0;

            push(stack, i);
            x /= i;
        }
    }

    if (!is_prime && x != 1) {
        push(stack, x);
    }

    return stack;
}

Stack* get_next_factors(Stack* stack) {

    if (is_empty(stack)) {
        return NULL;
    }

    int factor1 = pop(stack);

    if (is_empty(stack)) {
        return NULL;
    }

    int factor2 = pop(stack);

    int x = factor1 * factor2;
    
    for (factor2++; factor2 < x; factor2++) {
        if (factor1 != factor2) {
            while (x % factor2 == 0) {
                x /= factor2;
                if (x < factor2) {
                    factor2 *= x;
                }
                push(stack, factor2);
            }
        }
    }

    if (factor2 == x && ! is_empty(stack)) {
        push(stack, factor2);
    }

    return stack;
}

int main() {
    int x = input("Enter number");

    Stack* factors = get_prime_factors(x);

    if (is_empty(factors)) {
        printf("0\n");
        return 1;
    }

    int all_factors_count = 1; // including prime factors

    print(factors);
    printf("\n");

    while ((factors = get_next_factors(factors)) != NULL && !is_empty(factors) && top(factors) != x) {
        all_factors_count++;
        print(factors);
        printf("\n");
    }

    printf("\n%d\n", all_factors_count);

    return 0;
}

