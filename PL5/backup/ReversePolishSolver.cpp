#include "ReversePolishSolver.h"

int ReversePolishSolver::Solve(std::string& expression) {

	std::stack<int> operands;
	std::stack<std::string> operations;

	std::string delimiter = " ";

	// _______________PARSING_EXPRESSION_PUSHING_STACKS_______________
	size_t pos = 0;
	std::string token;
	while ((pos = expression.find(delimiter)) != std::string::npos) {
		token = expression.substr(0, pos);

		int nonDigit;
		int isOperation = 0;
		bool operationIsDone = false;

		nonDigit = std::count_if(token.begin(), token.end(),
			[](unsigned char c) {
				if (!isdigit(c)) return false; });	// counting non-digits

		if (nonDigit == 0) {						// if only digits in token
			operands.push(std::stoi(token));		// push converted number
		} else {
			for (Operation oper : m_operations) {	// if non-digits found check for operation
				if (oper.getName() == token) {					
 					isOperation++;
					
					int last;
					int first;
					int second;

					if (oper.isBinary() == 1) {			// CHECK FOR UNARY

						if (operands.empty() != 0) {	// check if stack is empty
							last = operands.top();
							operands.pop();				// pop from top
						} 
						else {
							last = 0;
						}
						auto f = oper.getFunctionUnary();
						operands.push(f(last));			// pushing new operand
					}
					else if (oper.isBinary() == 2) {	// CHECK FOR BINARY

						if (operands.empty() != 0) {	// check if stack is empty
							second = operands.top();
							operands.pop();				// pop second from top
						}
						else {
							second = 0;
						}
						if (operands.empty() != 0) {	// check if stack is empty
							first = operands.top();
							operands.pop();				// pop first from top
						}
						else {
							first = 0;
						}
						auto f = oper.getFunctionBinary();
						operands.push(f(first, second));
					}
					break;
				}
			} 
		}

		if (isOperation == 0) {						//if no operation with token's name throw exception
			std::string error = "Operation " + token + " doesn't exist";
			throw std::exception(error.c_str());
		}

		expression.erase(0, pos + delimiter.length());
	}
	return 0;
}