#pragma once
#include <string>
#include <vector>
#include <functional>
#include <exception>

//template <class F>
//class Operation
//{
//public:
//	Operation(const std::string& name = "",
//			  const F& func = nullptr,
//			  int argsCounter = 0) : m_operationName(name),
//									 m_function(func),
//									 m_isBinary(argsCounter) {}
//
//	const F& getFunction() {
//		return m_function;
//	}
//	const std::string& getName();
//	const int isBinary();
//
//private:
//	F m_function;
//	std::string m_operationName;
//	int m_isBinary;
//};



class Operation
{
public:
	Operation(const std::string& name = "",
			  const std::function<int(int)>& funcUnary = nullptr,
			  const std::function<int(int, int)>& funcBinary = nullptr,
			  int argsCounter = 0);

	const std::function<int(int)>& getFunctionUnary();
	const std::function<int(int, int)>& getFunctionBinary();
	const std::string& getName();
	const int isBinary();

private:
	std::function<int(int)> m_functionUnary;
	std::function<int(int, int)> m_functionBinary;
	std::string m_operationName;
	int m_isBinary;
};

