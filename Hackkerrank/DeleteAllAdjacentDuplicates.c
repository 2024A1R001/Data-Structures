#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_SIZE 100
int main(){
    char stack[MAX_SIZE]; 
    int top = -1 ;
    char ch = getc(stdin);
    for (int i = 0; ch != '\n' && ch != EOF; i++){
        if (top==-1 || ch != stack[top]){
            stack[++top]=ch;
        } else {
            top--;
        }
        ch = getc(stdin);
    }
    stack[++top]='\0';
    for (int i = 0; stack[i]!='\0';i++){
        printf("%c",stack[i]);
    }
}
