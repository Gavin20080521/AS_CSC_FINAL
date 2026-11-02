#include <iostream>
#include <sstream>
#include <string>

int main() {
    std::cout << "Calculator (+, -, *, /). Enter q to quit.\n";
    std::cout << "Enter an expression, for example: 12.5 * 4\n";

    std::string input;
    while (std::getline(std::cin, input)) {
        if (input == "q" || input == "Q") {
            break;
        }

        std::istringstream expression(input);
        double left;
        double right;
        char operation;

        if (!(expression >> left >> operation >> right)) {
            std::cout << "Invalid format. Use: number operator number\n";
            continue;
        }

        double result;
        switch (operation) {
            case '+':
                result = left + right;
                break;
            case '-':
                result = left - right;
                break;
            case '*':
                result = left * right;
                break;
            case '/':
                if (right == 0) {
                    std::cout << "Error: cannot divide by zero\n";
                    continue;
                }
                result = left / right;
                break;
            default:
                std::cout << "Unsupported operator. Use +, -, * or /\n";
                continue;
        }

        std::cout << "Result: " << result << "\n";
    }

    return 0;
}