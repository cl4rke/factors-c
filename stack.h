#include <string.h>
#include <stdlib.h>

typedef struct Stack Stack;
typedef struct Node Node;

struct Stack {
    Node* top;
};

struct Node {
    Node* next;
    int value;
};

Stack* create_stack() {
    Stack* stack = malloc(sizeof(Stack));
    
    stack->top = NULL;

    return stack;
}

Node* create_node(Node* next, int value) {
    Node* node = (Node*) malloc(sizeof(Node));

    node->next = next;
    node->value = value;

    return node;
}

void push(Stack* stack, int value) {
    stack->top = create_node(stack->top, value);
}

int top(Stack* stack) {
    return stack->top->value;
}

int pop(Stack* stack) {
    Node* top = stack->top;
    int value = top->value;

    stack->top = top->next;

    free(top);

    return value;
}

int is_empty(Stack* stack) {
    return stack->top == NULL;
}

void print(Stack* stack) {
    if ( ! is_empty(stack)) {
        int x = pop(stack);
        print(stack);
        printf("%d ", x);
        push(stack, x);
    }
}

