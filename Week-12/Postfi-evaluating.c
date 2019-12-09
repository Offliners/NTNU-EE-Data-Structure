#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 100
#define MAXSIZE_EXPRESSION_SIZE 100

typedef enum
{
	plus,minus,times,divide,mod,eos,operand
}precedence;

precedence get_token(char *symbol,char *expr,int *n);
void push(int *stack,int *top,int item);
int pop(int *stack,int *top);
void stackFull();
void stackEmpty();
int eval(char *expr, int *stack);
void outputStack(int *stack,int top);

void main()
{
	int stack[MAXSIZE];
	char expr[MAXSIZE_EXPRESSION_SIZE];

	printf("Enter a postfix expression :\n");
	scanf("%s",expr);
	printf("The evaluation result = %d",eval(expr,stack));
}

precedence get_token(char *symbol,char *expr,int *n)
{
	*symbol = expr[(*n)++];
	switch(*symbol)
	{
		case '+':
			return plus;
			break;
		case '-':
			return minus;
			break;
		case '*':
			return times;
			break;
		case '/':
			return divide;
			break;
		case '%':
			return mod;
			break;
		case '\0':
			return eos;
			break;
		default:
			return operand;
			break;
	}
}

void push(int *stack,int *top,int item)
{
	if(*top >= MAXSIZE - 1)
		stackFull();
	else
	{
		(*top)++;
		stack[(*top)] = item;
	}
}

int pop(int *stack,int *top)
{
	if(*top == -1)
		stackEmpty();
	else
		return stack[(*top)--];
}

void stackFull()
{
	printf("Stack full!\n");
	exit(1);
}

void stackEmpty()
{
	printf("Stack empty!\n");
	exit(1);
}

int eval(char *expr, int *stack)
{
	precedence token;
	char symbol;
	int op1,op2;
	int n = 0;
	int top = -1;

	token = get_token(&symbol,expr,&n);
	while(token != eos)
	{
		if(token == operand)
		{
			push(stack,&top,symbol - '0');
			outputStack(stack,top);
		}
		else
		{
			op2 = pop(stack,&top);
			outputStack(stack,top);
			op1 = pop(stack,&top);
			if(top != -1)
				outputStack(stack,top);
			else
				printf("\n\n");
			switch(token)
			{
				case plus:
					push(stack,&top,op1+op2);
					break;
				case minus:
					push(stack,&top,op1-op2);
					break;
				case times:
					push(stack,&top,op1*op2);
					break;
				case divide:
					push(stack,&top,op1/op2);
					break;
				case mod:
					push(stack,&top,op1%op2);
					break;
			}
			outputStack(stack,top);
		}
		token = get_token(&symbol,expr,&n);
	}
	return pop(stack,&top);
}

void outputStack(int *stack,int top)
{
	if(top == -1)
		stackEmpty();
	else
	{
		printf("\n");
		for(int i = 0;i <= top;i++)
			printf("%d ",stack[i]);
		printf("\n");
	}
}
