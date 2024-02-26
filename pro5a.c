#include<stdio.h>
#include<math.h>
#include<ctype.h>

float eval(char postfix[]);
float oper(char symb, float op1, float op2);
void push(float x);
float pop();

int main()
{
    char postfix[50];
    int choice;
    float res;

    do {
        printf("Enter postfix expression:\n");
        scanf("%s", postfix);
        res = eval(postfix);
        printf("Result = %f\n", res);
        printf("Do you want to enter another expression? (1/0): ");
        scanf("%d", &choice);
    } while (choice != 0);

    return 0;
}

float eval(char postfix[])
{
    float op1, op2, value;
    char ch;
    int i = 0;

    while ((ch = postfix[i]) != '\0')
    {
        if (isdigit(ch))
            push(ch - '0');
        else
        {
            op2 = pop();
            op1 = pop();
            value = oper(ch, op1, op2);
            push(value);
        }
        i++;
    }
    return pop();
}

float oper(char symb, float op1, float op2)
{
    int ans=1;
    switch (symb)
    {
    case '$':
    case '^':
        for(int i=0;i<op2;i++){
            ans*=op1;
        }
        return ans;
    case '*':
        return op1 * op2;
    case '/':
        return op1 / op2;
    case '+':
        return op1 + op2;
    case '-':
        return op1 - op2;
    default:
        printf("Invalid operator encountered: %c\n", symb);
        return 0;
    }
}

float stack[50];
int top = -1;

void push(float x)
{
    stack[++top] = x;
}

float pop()
{
    if (top == -1)
    {
        printf("Error: Stack underflow\n");
        return 0;
    }
    return stack[top--];
}
