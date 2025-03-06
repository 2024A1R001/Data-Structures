char* removeDuplicates(char* s) {
    int len = strlen(s);
    char* stack = (char*)malloc((len + 1) * sizeof(char)); // Allocate memory (chgpt)
    int top =-1;
    for (int i = 0; i < len; i++){
        char ch = s[i];
        if (top==-1 || ch != stack[top]){
            stack[++top]=ch;
        } else{
            top--;
        }
    }
    stack[top + 1] = '\0';
    return stack;
}
