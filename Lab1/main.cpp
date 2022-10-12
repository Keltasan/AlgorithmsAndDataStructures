#include <iostream>
#include <string>
#include "Stack.h"
#include "functions.h"

void SortStationAlgorithm(std::string input, std::string &output, int &error) {
	int i = 0;

	Stack op;

	while (i < input.size() && !error)
	{
		if (input[i] >= '0' && input[i] <= '9')
		{
			output += input[i];
		}
		else if (input[i] == 's' || input[i] == 'c')
		{
			op.push(input[i]);
			i += 2;
		}
		else if (isOperator(input[i]))
		{
			while (isOperator(op.top()) && (priority(input[i]) <= priority(op.top())) && !op.empty())
			{
				output += " ";
				output += op.top();
				op.pop();
			}

			output += " ";

			op.push(input[i]);
		}
		else if (input[i] == '(')
		{
			op.push(input[i]);
		}
		else if (input[i] == ')')
		{
			while (op.top() != '(')
			{
				output += " ";
				output += op.top();

				op.pop();
				if (op.empty())
				{
					error = 1;
					break;
				}
			}

			op.pop();

			if (op.top() == 's')
			{
				output += " sin";
				op.pop();
			}
			else if (op.top() == 'c')
			{
				output += " cos";
				op.pop();
			}
		}
		++i;
	}

	while (!op.empty())
	{
		if (op.top() == '(')
		{
			error = 1;
		}

		output += ' ';
		output += op.top();
		op.pop();
	}
}

int main(int argc, char* argv[]) {
	std::string inputExpression, outputExpression;
	int errorNum = 0;

	std::cout << "Hi! Please insert your expression:" << std::endl;

	std::cin >> inputExpression;

	SortStationAlgorithm(inputExpression, outputExpression, errorNum);

	std::cout << "Here is your remade expression:" << std::endl;
	
	if (errorNum == 0)
	{
		std::cout << outputExpression << std::endl;

	}
	else if (errorNum == 1)
	{
		std::cout << "Oh shit! You've fucked up with brackets! GTFO from here, you morron!" << std::endl;
	}

	system("pause");
	return 0;
}
