int calPoints(char** A, int n) {
    int ans[n], top = -1, i;
    for(int i = 0; i<n ;i++){
        if (strcmp(A[i], "+") == 0){
           ans[++top] = ans[top] + ans[top-1];
        }
        else if (strcmp(A[i],"C")==0){
            top--;
        }
        else if (strcmp(A[i],"D")== 0){
            ans[++top] = 2* ans[top];
        }
        else{
            ans[++top] = atoi(A[i]);    
        }
    }
    int sum = 0; 
    while(top != -1){
        sum+=ans[top--];
    }
    return sum;
}
