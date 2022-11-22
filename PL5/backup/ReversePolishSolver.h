#pragma once
#include <string>
#include <vector>
#include <functional>
#include <stack>
#include <algorithm>
#include <iostream>

#include "Operation.h"


class ReversePolishSolver
{
public:
	
	template <size_t argsCount, class T>
	void RegisterOperator(const std::string& name, T fn) {
		if (argsCount == 1) {
			m_operations.push_back(Operation(name, fn, nullptr, argsCount));
		}
		else if (argsCount == 2) {
			m_operations.push_back(Operation(name, nullptr, fn, argsCount));
		}
		else {
			throw std::exception("Incorrect argsCounter, use 1 or 2");
		}
	}

	int Solve(std::string& expression);

private:
	std::vector<Operation> m_operations;

};