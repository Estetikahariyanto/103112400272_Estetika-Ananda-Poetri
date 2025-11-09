#ifndef STACK_H
#define STACK_H

#define MAX 10

struct Stack {
    int data[MAX];
    int top;
};

void createStack(Stack &S);
bool isEmpty(Stack S);
bool isFull(Stack S);
void push(Stack &S, int x);
void pop(Stack &S, int &x);
void printInfo(Stack S);

void pushAscending(Stack &S, int x);
void balikStack(Stack &S);

#endif