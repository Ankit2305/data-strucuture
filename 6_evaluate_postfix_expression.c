#include<stdio.h>
#include<string.h>
#include<math.h>

void view(int array[], int tos){
    int i;
    printf("Stack : ");
    for(i=0;i<=tos;i++)
        printf("%d ", array[i]);
    printf("\n");
}

int push(int array[], int tos, int element){
    array[++tos] = element;
    return tos;
}

int pop(int array[], int tos){
    return tos-1;
}

char peek(int array[], int tos){
    return array[tos];
}

int empty(int array[], int tos){
    if(tos==-1)
        return 1;
    return 0;
}

int type(char element){
    if(element>47 && element<58)
        return 0;
    else if(element == ' ')
        return 1;
    return 2;
}

int stringToInt(int num, char element){
    int newNum = element-48;
    return 10*num+newNum;
}

int evaluate(int a, int b, char element){
    int result;
    switch(element){
    case '+':
        result = a+b;
        break;
    case '-':
        result = a-b;
        break;
    case '*':
        result = a*b;
        break;
    case '/':
        result = a/b;
        break;
    case '^':
        result = pow(a,b);
        break;
    }
    return result;
}

int main(){
    char postfix[50];
    int stack[25], tos=-1, len, i=0, result, num, ptype;
    printf("Enter Postfix expression : ");
    gets(postfix);
    len = strlen(postfix);
    postfix[len] = '#';
    postfix[++len] = '\0';
    num=0;
    while(postfix[i]!='#'){
        char input = postfix[i];
        if(type(input) == 0){
            num=stringToInt(num, input);
            ptype = 0;
        }
        else if(type(input) == 1){
            if(ptype==0){
                tos = push(stack, tos, num);
        view(stack, tos);
                num=0;
            }
            ptype = 1;
        }
        else{
            int b = peek(stack, tos);
            tos = pop(stack, tos);
            int a = peek(stack, tos);
            tos = pop(stack, tos);
            num = evaluate(a,b,input);
            tos = push(stack, tos, num);
        view(stack, tos);
            num = 0;
            ptype = 2;
        }
        i++;
    }
    result = stack[0];
    printf("\nResult : %d", result);

    return 0;
}

