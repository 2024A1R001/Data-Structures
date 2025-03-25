//Leetcode #2390
char* removeStars(char* s) {
    int n = strlen(s);
    char* stack = (char*)malloc((n+1)*sizeof(char));
    int top = -1;
    for (int i = 0; i < n; i++){
        char ch = s[i];
        if (ch != '*'){
            stack[++top] = ch;
        } else if (ch == '*' && top > -1){
            top--;
        }
    }
    stack[++top] = '\0';
    return stack;
}
