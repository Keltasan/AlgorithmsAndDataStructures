#include <string>
#include "Stack.h"
#include "functions.h"

char priority(char op) {
	switch (op) {
	case '^':
		return 3;
		break;
	case '*':
	case '/':
		return 2;
		break;
	case '+':
	case '-':
		return 1;
		break;
	default:
		return op;
		break;
	}
}

bool isOperator(char op) {
	if (op == '-' || op == '+' || op == '*' || op == '/' || op == '^')
	{
		return true;
	}
	else
	{
		return false;
	}
}

