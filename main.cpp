#include <iostream>
using namespace std;

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

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
