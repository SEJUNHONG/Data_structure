#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cmath>
#include <iostream>
#include <utility>
#include <stack>
#include <string.h>
using namespace std;

bool Balanced_parentheses(char* infix)
{
	stack<char> paren;
	for (int i = 0; i < strlen(infix); i++)
	{
		if (infix[i] == '(')
			paren.push(infix[i]);
		else if (infix[i] == '{')
			paren.push(infix[i]);
		else if (infix[i] == '[')
			paren.push(infix[i]);
		else if (infix[i] == ')' )
		{
			if (paren.top() == '(')
			{
				paren.pop();
			}
			else
			{
				printf("Error!: unbalanced parentheses \n");
				return false;
			}
		}
		else if ( infix[i] == '}')
		{
			if (paren.top() == '{')
			{
				paren.pop();
			}
			else
			{
				printf("Error!: unbalanced parentheses \n");
				return false;
			}
		}
		else if (infix[i] == ']')
		{
			if (paren.top() == '[')
			{
				paren.pop();
			}
			else
			{
				printf("Error!: unbalanced parentheses \n");
				return false;
			}
		}
	}
	if (!paren.empty())
	{
		printf("Error!: unbalanced parentheses \n");
		return false;
	}
	else
		return true;
}

void change(char *infix, char *postfix) {
	stack<char> s;
	int k = 0;

	for (int i = 0; i < strlen(infix); i++) {

		if ((infix[i] >= '0' && infix[i] <= '9')||infix[i]=='.') 
		{
			int j;
			for (j = i; ((infix[j] >= '0' && infix[j] <= '9') || infix[j] == '.'); j++)
			{
				postfix[k++] = infix[j];
			}
			postfix[k++] = '$';
			i = j - 1;
		}
		else {
			if (infix[i] == '(' || infix[i] == '{' || infix[i] == '[')
			{
				infix[i] = '(';
				s.push(infix[i]);
			}
			else if (infix[i] == ')' || infix[i] == '}' || infix[i] == ']')
			{
				while (s.top() != '(') {
					postfix[k++] = s.top();
					s.pop();
				}
				s.pop();
			}
			else if (infix[i] == 'E')
			{
				cout << "프로그램을 종료합니다.\n" << endl;
				exit(1);
			}
			else if (infix[i] == '*' || infix[i] == '/') {
				while (!s.empty() && (s.top() == '*' || s.top() == '/')) {
					postfix[k++] = s.top();
					s.pop();
				}
				s.push(infix[i]);
			}
			else {
				while (!s.empty() && s.top() != '(') {
					postfix[k++] = s.top();
					s.pop();
				}
				s.push(infix[i]);

			}
		}
	}

	while (!s.empty()) {
		postfix[k++] = s.top();
		s.pop();
	}
	postfix[k] = '\0';
}

double todouble(char *postfix, int* i) 
{
	int cnt = 0, dot = 0;
	double ret = 0.0;
	double result = 0.0;
	for (; postfix[*i] != '$'; (*i)++) 
	{
		if (postfix[*i] == '.')
		{
			(*i)++;
			dot=cnt;
		}
		ret *= 10;
		ret += postfix[*i] -'0';
		cnt++;
	}
	if ((cnt-dot) == 0||dot==0)
		result = ret;
	else
		result = ret * pow(0.1, (cnt-dot));

	return result;
}

double calculate(char *postfix) 
{
	stack<double> s;
	double num;

	for (int i = 0; i < strlen(postfix); i++) 
	{
		if (postfix[i] >= '0' && postfix[i] <= '9') 
		{
			num = todouble(postfix, &i);
			s.push(num);
		}
		else 
		{
			double num2 = s.top();
			s.pop();
			double num1 = s.top();
			s.pop();

			switch (postfix[i]) 
			{
			case '+':
				num= num1 + num2;
				break;
			case '-':
				num = num1 - num2;
				break;
			case '*':
				num = num1 * num2;
				break;
			case '/':
				if (num2 == 0)
					printf("Error!: divide by zero \n");
				else 
					num = num1 / num2;
				break;
			}
			s.push(num);
		}
	}
	return s.top();
}

int main() 
{
	char infix[10000];
	char postfix[10000];

	while (1)
	{
		printf("식을 입력하세요: ");
		scanf("%s", &infix);

		if (Balanced_parentheses(infix) == 1)
		{
			change(infix, postfix);

			printf("%.3f\n", calculate(postfix));
		}
	}

	return 0;
}
