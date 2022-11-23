#include <iostream>
#include <string>

#include "Operation.h"
#include "ReversePolishSolver.h"


class FooBinarMinus {
public:
    int operator()(int x, int y) { return x - y; }
};


int main() {
    char enter;
    // ___________________________________TEST_1__________________________OK
    ReversePolishSolver solver;
    std::cout << "press any key to try solver.RegisterOperator<1>"
                 "(\"square\", [](int x) {return x * x; });" << std::endl;
    std::cin >> enter;
    try {
        solver.RegisterOperator<1>("square", [](int x) {return x * x; });
        std::cout << "OK" << std::endl;;
    }
    catch (std::exception& ex) {
        std::cout << ex.what() << std::endl;;
    }

    // ___________________________________TEST_2__________________________OK
    std::cout << "press any key to try solver.RegisterOperator<2>"
                 "(\"-\", FooBinarMinus());" << std::endl;
    std::cin >> enter;
    try {
        solver.RegisterOperator<2>("-", FooBinarMinus());
        std::cout << "OK" << std::endl;;
    }
    catch (std::exception& ex) {
        std::cout << ex.what() << std::endl;;
    }

    // ___________________________________TEST_3__________________________EXCEPTION
    std::cout << "press any key to try solver.RegisterOperator<3>"
                 "(\")\", FooBinarMinus());" << std::endl;
    std::cin >> enter;
    try {
        solver.RegisterOperator<3>(")", FooBinarMinus());
        std::cout << "OK" << std::endl;;
    }
    catch (std::exception& ex) {
        std::cout << ex.what() << std::endl;;
    }

    // ___________________________________TEST_4__________________________EXCEPTION
    std::cout << "press any key to try solver.RegisterOperator<2>"
                 "(\"-\", FooBinarMinus());" << std::endl;
    std::cin >> enter;
    try {
        solver.RegisterOperator<2>("-", FooBinarMinus());
        std::cout << "OK" << std::endl;;
    }
    catch (std::exception& ex) {
        std::cout << ex.what() << std::endl;;
    }

    // ___________________________________TEST_5__________________________EXCEPTION
    std::cout << "press any key to try solver.RegisterOperator<2>"
        "(\"2\", FooBinarMinus());" << std::endl;
    std::cin >> enter;
    try {
        solver.RegisterOperator<2>("2", FooBinarMinus());
        std::cout << "OK" << std::endl;;
    }
    catch (std::exception& ex) {
        std::cout << ex.what() << std::endl;;
    }

    
    std::cout << solver.Solve("5 square 2 -");

    return 0;
}
