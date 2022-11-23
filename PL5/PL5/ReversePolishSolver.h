#pragma once
#include <string>
#include <vector>
#include <functional>
#include <stack>
#include <algorithm>
#include <iostream>
#include <optional>
#include "Operation.h"

typedef std::function<int(int)> unFunPtr;
typedef std::function<int(int, int)> binFunPtr;

class ReversePolishSolver
{
public:
	template <size_t argsCount, class T>
	void RegisterOperator(const std::string& name, T fn) {
		if constexpr (argsCount == 1) {
			for (Operation<std::function<int(int)>> oper : m_unaryOperations) {
				if (oper.getName() == name) {
					throw std::logic_error("Function with name " + name + " already exists");
				}
				if (!name.empty() && std::find_if(name.begin(),
					name.end(), [](unsigned char c) { return !std::isdigit(c); }) == name.end()) {
					throw std::logic_error("Function name cant be a number");
				}
			}
			m_unaryOperations.push_back(Operation<unFunPtr>(name, fn, 1));


		} else if constexpr (argsCount == 2) {
			for (Operation<std::function<int(int, int)>> oper : m_binaryOperations) {
				if (oper.getName() == name) {
					throw std::logic_error("Function with name " + name + " already exis");
				}
				if (!name.empty() && std::find_if(name.begin(),
					name.end(), [](unsigned char c) { return !std::isdigit(c); }) == name.end()) {
					throw std::logic_error("Function name cant be a number");
				}
			}
			m_binaryOperations.push_back(Operation<binFunPtr>(name, fn, 2));


		} else {
			throw std::logic_error("argsCount should be 1 or 2");
		}
	}
	int Solve(const std::string& expression);

private:
	std::vector<Operation<binFunPtr>> m_binaryOperations;
	std::vector<Operation<unFunPtr>> m_unaryOperations;
};