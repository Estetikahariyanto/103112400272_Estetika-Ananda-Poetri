#ifndef STACK_H
#define STACK_H
#define MAX 50

struct Stack {
    char isi[MAX];
    int top;
};

void createStack(Stack &S);
bool isFull(Stack S);
bool isEmpty(Stack S);
void push(Stack &S, char data);
void pop(Stack &S, char &data);
void printInfo(Stack S);
void balikStack(Stack &S);
void getInputStream(Stack &S);

#endif