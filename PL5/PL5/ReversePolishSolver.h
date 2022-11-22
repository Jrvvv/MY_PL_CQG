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
			m_unaryOperations.push_back(Operation<std::function<int(int)>>(name, fn, 1));
		}
		else if (argsCount == 2) {
			m_binaryOperations.push_back(Operation<std::function<int(int, int)>>(name, fn, 1));
		}
		else {
			throw std::exception();
		}
	};


	int Solve(const std::string& expression);

private:
	std::vector<Operation<std::function<int(int, int)>>> m_binaryOperations;
	std::vector<Operation<std::function<int(int)>>> m_unaryOperations;
};


//template <> inline void ReversePolishSolver::RegisterOperator<1>(const std::string& name, std::function<int(int)> fn) {
//	m_unaryOperations.push_back(Operation<std::function<int(int)>>(name, fn, 1));
//}

//template <> inline void ReversePolishSolver::RegisterOperator<2>(const std::string& name, std::function<int(int, int)> fn) {
//	m_binaryOperations.push_back(Operation<std::function<int(int, int)>>(name, fn, 1));
//}