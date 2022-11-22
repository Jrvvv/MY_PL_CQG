#include <iostream>
#include <string>

#include "Operation.h"
#include "ReversePolishSolver.h"

class FooUnar {
public:
    int operator()(int value) { return value * value; }
};

class FooBinar {
public:
    int operator()(int x, int y) { return x - y; }
};


int main() {

    //Operation oper1 = Operation("double", [](int x)->int {return x * 2;}, nullptr, 1);
    //Operation oper2 = Operation("plus", nullptr, std::bind(std::plus<int>(), std::placeholders::_1, std::placeholders::_2), 2);

    //auto f1 = oper1.getFunctionUnary();
    //std::cout << f1(5) << std::endl;
    //auto f2 = oper2.getFunctionBinary();
    //std::cout << f2(5, 7) << std::endl;

    //Operation oper3 = Operation("double", FooUnar(), nullptr, 1);
    //Operation oper4 = Operation("plus", nullptr, FooBinar(), 2);

    //auto f3 = oper3.getFunctionUnary();
    //std::cout << f3(5) << std::endl;
    //auto f4 = oper4.getFunctionBinary();
    //std::cout << f4(5, 7) << std::endl;

    ReversePolishSolver solver;

    solver.RegisterOperator<1>("square", FooUnar());
    solver.Solve("5 square");

    return 0;
}
