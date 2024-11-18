#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int precedence(char c){
    if(c=='^')
    return 3;
    else if(c =='/' || c=='*')
    return 2;
    else if(c=='+' || c=='-')
    return 1;
    else
    return -1;

}
char associativity(char c){
    if (c=='^')
    return 'R';
    else
    return 'L';
}
void reverse(char* exp){
    int len=strlen(exp);
    for(int i=0;i<len/2;i++){
        char temp=exp[i];
        exp[i]=exp[len-i-1];
        exp[len-i-1]=temp;
    }

}

void infixToPostFix(char s[],char result[]){
   
    int resultIndex=0;
    char stack[1000];
    int stackIndex=-1;
    int len=strlen(s);

    for(int i=0;i<len;i++){
        char c=s[i];

        if((c>='a' && c<='z' || c>='A' && c<='Z' || c>='0' && c<='9')){
            result[resultIndex++]=c;
        }
        else if(c=='('){
            stack[++stackIndex]=c;
        }
        else if(c==')'){
            while(stackIndex>=0 && stack[stackIndex]!='('){
                result[resultIndex++]=stack[stackIndex--];
            }
            stackIndex--;
        }
        else{
            while(stack[stackIndex]>=0 &&
            (
                (precedence(c)<precedence(stack[stackIndex])) ||
                (precedence(c)==precedence(stack[stackIndex]) && associativity(s[i])=='L')))
            
        
            {
                result[resultIndex++]=stack[stackIndex--];
            }
              stack[++stackIndex]=c;
               
            
        }
       
    
    }
    // sabb pop krna rhta hai toh ham ye krte haii theek?
    while(stackIndex>=0){
        result[resultIndex++]=stack[stackIndex--];
    }
    result[resultIndex]='\0';

}

void infixtoPrefix(char infix[]){
    reverse(infix);
    for(int i=0;i<strlen(infix);i++){
        if(infix[i]=='('){
            infix[i]=')';

        }
        else if(infix[i]==')'){
            infix[i]='(';
        }
    }
    char postfix[1000];
    infixToPostFix(infix,postfix);
    reverse(postfix);
    printf("%s\n",postfix);
}
int main(){
        char exp[] = "a+b*(c^d-e)^(f+g*h)-i";
           infixtoPrefix(exp);
    return 0;
}




