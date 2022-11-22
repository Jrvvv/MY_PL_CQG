#include "Operation.h"

Operation::Operation(const std::string& name,
					 const std::function<int(int)>& funcUnary,
					 const std::function<int(int, int)>& funcBinary,
					 int argsCounter) : m_operationName(name),
										m_functionUnary(funcUnary),
										m_functionBinary(funcBinary),
										m_isBinary(argsCounter) {}


const std::function<int(int)>& Operation::getFunctionUnary() {
	return m_functionUnary;
}

const std::function<int(int, int)>& Operation::getFunctionBinary() {
	return m_functionBinary;
}





const std::string& Operation::getName() {
	return m_operationName;
}

const int Operation::isBinary() {
	return m_isBinary;
}