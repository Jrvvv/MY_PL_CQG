#include "ReversePolishSolver.h"

int ReversePolishSolver::Solve(const std::string& expression) {
	
	std::string expr = expression;

	std::stack<int> operands;
	std::stack<std::string> operations;

	std::string delimiter = " ";

	// _______________PARSING_EXPRESSION_PUSHING_STACKS_______________
	size_t pos = 0;
	std::string tok;
	std::vector<std::string> parsed;
	while ((pos = expr.find(delimiter)) != std::string::npos) {
		tok = expr.substr(0, pos);
		parsed.push_back(tok);
		expr.erase(0, pos + delimiter.length());
	}
	parsed.push_back(expr);

	for(auto token : parsed) {
		int nonDigit;
		int isOperation = 0;
		bool operationIsDone = false;

		nonDigit = std::count_if(token.begin(), token.end(),
			[](unsigned char c) {
				if (!isdigit(c)) return true; else return false; });	// counting non-digits

		if (nonDigit == 0) {						// if only digits in token
			operands.push(std::stoi(token));		// push converted number

		} else {									// if non-digits found check for unaryoperation
			
			for (Operation<std::function<int(int)>> oper : m_unaryOperations) {	
				if (oper.getName() == token) {
					isOperation++;
					int last;	
					if (operands.empty() == false) {	// check if stack is empty
						last = operands.top();
						operands.pop();				// pop from top
					}
					else {
						last = 0;
					}
					auto f = oper.getFunction();
					operands.push((f(last)));			// pushing new operand
					break;
				}
			} 

			if (isOperation == 0) {					// no unary operations were found with this name
				int first;
				int second;
				for (Operation<std::function<int(int, int)>> oper : m_binaryOperations) {
					if (oper.getName() == token) {
						isOperation++;
						if (operands.empty() == false) {	// check if stack is empty
							second = operands.top();
							operands.pop();				// pop second from top
						}
						else {
							second = 0;
						}
						if (operands.empty() == false) {	// check if stack is empty
							first = operands.top();
							operands.pop();				// pop first from top
						}
						else {
							first = 0;
						}
						auto f = oper.getFunction();
						operands.push(f(first, second));
						break;
					}
				}
			}
		} 
		if (isOperation == 0 && nonDigit != 0) {		//if no operation with token's name throw exception
			std::string error = "Operation " + token + " doesn't exist";
			throw std::logic_error(error.c_str());
		}

		
	}
	return operands.top();
}