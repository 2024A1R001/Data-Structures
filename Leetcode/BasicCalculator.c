//Leetcode 224
int calculate(char* s) {
    int stack[1000];
    int top = -1;
    int num = 0;
    int sign = 1;
    int result = 0;
    while (*s) {
        if (isdigit(*s)) {
            num = num * 10 + (*s - '0');
        } else if (*s == '+') {
            result += sign * num;
            num = 0;
            sign = 1;
        } else if (*s == '-') {
            result += sign * num;
            num = 0;
            sign = -1;
        } else if (*s == '(') {
            stack[++top] = result; //save result and sign 
            stack[++top] = sign;
            result = 0;
            sign = 1;
        } else if (*s == ')') {
            result += sign * num;
            num = 0;
            result *= stack[top--];
            result += stack[top--];
        }
        s++;
    }
    return result + sign * num;
}
