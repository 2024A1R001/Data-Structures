#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#define MAX_SIZE 100
char stack[MAX_SIZE]; int top = -1;

bool isEmpty(){
    return top == -1;
}
bool isFull(){
    return top == MAX_SIZE-1;
}
void push(char value){
    if (!isFull())
        stack[++top]= value;
}
int pop(){
    if (!isEmpty()){
        int a = stack[top];
        stack[top--]= '\0';
        return a;
    }
    return INT_MIN;
}
int main() {
    char st[MAX_SIZE];
    fgets(st,MAX_SIZE,stdin);
    for (int i = 0; st[i]!='\0';i++){
        char value = st[i];
        if (value=='('|| value=='[' || value=='{'){
            push(value);
        }
        else if ((isEmpty())||(value == ')'&& stack[top]!='(')||
                (value == ']'&& stack[top]!='[')||
                (value =='}' && stack[top]!= '{')){
                    printf("False");
            return 0;
        }else{
                pop();
            }
        }
    if (!isEmpty()) {
    printf("False");
    return 0;
}
    printf("True");
    return 0;
}
