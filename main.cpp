#include <iostream>


float parseAndCalculate(std::string& expression) {
    float a = 0.f;
    float b = 0.f;
    float result = 0.f;
    bool seenOperand = false;
    char operand;

    for (const auto& x : expression) {

        if (isdigit(x)) {
            if(!seenOperand) {
                a = a * 10 + (x - '0');
            } else {
                b = b * 10 + (x - '0');
            }
        }

        if (x == '+' || x == '-' || x == '/' || x == '*') {
            seenOperand = true;
            operand = x;
        }

    }
    
    switch (operand)
    {
    case '+':
        result = a + b;
        return static_cast<int>(result);

    case '-':
        result = a - b;
        return static_cast<int>(result);
        break;

    case '/':
        result = a / b;
        return result;
        break;

    case '*':
        result = a * b;
        return result;
        break;
    
    default:
        std::cout << "Invalid Operand: " << operand << std::endl;
        break;
    }

    return 0;
}

int main() {
    std::string expression;

    std::cout << "Enter equation: " << std::endl;
    getline(std::cin, expression);

    auto result = parseAndCalculate(expression);

    std::cout << result << std::endl;

    return 0;
}
