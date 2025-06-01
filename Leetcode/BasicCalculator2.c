int operand[1000], top1= -1,top2 = -1;
char operator[1000];
int precedence (char ch){
    if (ch == '+'|| ch == '-')  return 1;
    if (ch == '*' || ch == '/') return 2;
    return 0;
}
void doProcess(){
    if (top1 < 1 || top2 < 0)   return;
    int x = operand[top1--], y = operand[top1--];
    char ch = operator[top2--]; int res;
    switch(ch){
        case '+':   res = y+x; break;
        case '-':   res = y-x; break;
        case '*':   res = y*x; break;
        case '/':   res = y/x; break;
    }
    operand[++top1] = res;
}
int calculate(char* s) {
    int n = strlen(s);
    for (int i = 0; i < n ; i++){
        char ch = s[i];
        if (isdigit(ch)){
            long int num = 0;
            while (isdigit(s[i])){
                num = num*10 + s[i]-'0';
                i++;
            }
            i--;
            operand[++top1] = num;
        }
        else if (ch == '+' ||ch == '-' ||ch == '*' ||ch == '/'){
            while (top2 != -1 && precedence(ch) <= precedence(operator[top2])){
                doProcess();
            }
            operator[++top2] = ch;
        }
        else if (ch == '('){
            operator[++top2] = ch;
        }
        else if (ch == ')'){
            while (operator[top2] != '('){
                doProcess();
            }
            top2--;
        }
    }
    while (top2 != -1){
        doProcess();
    }
    return operand[top1];
}
