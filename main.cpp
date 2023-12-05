#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
const double pi = M_PI;
template <typename T>
class Stack {
private:
    vector<T> data;

public:
    bool empty() const {
        return data.empty();
    }

    size_t size() const {
        return data.size();
    }

    T& top() {
        if (empty()) {
            throw std::runtime_error("Stack is empty.");
        }
        return data.back();
    }

    const T& top() const {
        if (empty()) {
            throw std::runtime_error("Stack is empty.");
        }
        return data.back();
    }

    void push(const T& value) {
        data.push_back(value);
    }

    void pop() {
        if (empty()) {
            throw std::runtime_error("Stack is empty.");
        }
        data.pop_back();
    }
};
int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    if (op == '^')
        return 3;
    return 0;
}

bool is_operator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '!' ||
           c == 's' || c == 'c' || c == 't' || c == 'l' || c == 'q' || c == 'x';
}

double factorial(double n) {
    if (n == 0)
        return 1;
    return n * factorial(n - 1);
}

double my_sin(double x) {
    x = fmod(x, 2 * pi);
    double result = 0.0;
    double term = x;
    double power = x;
    double n = 1.0;
    while (abs(term) > 1e-15) {
        result += term;
        power *= -1 * x * x / ((2 * n) * (2 * n + 1));
        term = power / factorial(2 * n + 1);
        n += 1.0;
    }
    return result;
}

double my_cos(double x) {
    x = fmod(x, 2 * pi);
    double result = 1.0;
    double term = 1.0;
    double power = 1.0;
    double n = 1.0;
    while (abs(term) > 1e-15) {
        power *= -1 * x * x / ((2 * n - 1) * (2 * n));
        term = power / factorial(2 * n);
        result += term;
        n += 1.0;
    }
    return result;
}

double my_tan(double x) {
    return my_sin(x) / my_cos(x);
}
double my_sqrt(double x) {
    if (x < 0) {
        throw runtime_error("Cannot take square root of a negative number");
    }
    double guess = x / 2;
    double prevGuess = 0.0;
    while (abs(guess - prevGuess) > 1e-15) {
        prevGuess = guess;
        guess = (guess + x / guess) / 2;
    }
    return guess;
}

double my_log(double x) {
    if (x <= 0) {
        throw runtime_error("Logarithm is undefined for non-positive numbers");
    }
    double result = 0.0;
    double term = (x - 1) / (x + 1);
    double power = term;
    double n = 1.0;
    while (abs(power) > 1e-15) {
        result += power / n;
        power *= term * term;
        n += 2.0;
    }
    return 2 * result;
}

double my_log10(double x) {
    return my_log(x) / my_log(10);
}



double apply_operator(char op, double a, double b) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        case '^': return pow(a, b);
        case '!': return factorial(a);
        case 's': return my_sin(a);
        case 'c': return my_cos(a);
        case 't': return my_tan(a);
        case 'l': return my_log(a);
        case 'q': return my_sqrt(a);
        case 'x': return my_log10(a);
        default: throw runtime_error("Unknown operator");
    }
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
