//LeetCode 150
int evalRPN(char **tokens, int tokensSize) {
    int stack[100000], top = -1;

    for (int i = 0; i < tokensSize; i++) {
        if (strlen(tokens[i]) == 1 && (*tokens[i] < '0' || *tokens[i] > '9')) {
            int b = stack[top--];
            int a = stack[top--];
            switch (tokens[i][0]) {
                case '+': stack[++top] = a + b; break;
                case '-': stack[++top] = a - b; break;
                case '*': stack[++top] = a * b; break;
                case '/': stack[++top] = a / b; break;
            }
        } else {
            stack[++top] = atoi(tokens[i]);
        }
    }
    
    return stack[top];
}
