#include <iostream>
#include <string>
using namespace std;

const int MAX = 20;

class Stack {
    int top;
    string a[MAX];
public:
    Stack() { top = -1; }

    bool push(string x) {
        if (top >= (MAX - 1)) {
            cout << "Stack overflow" << endl;
            return false;
        } else {
            a[++top] = x;
            return true;
        }
    }

    string pop() {
        if (top < 0) {
            cout << "Stack underflow" << endl;
            return "";
        } else {
            string x = a[top--];
            return x;
        }
    }

    string peek() {
        if (top < 0) {
            return "";
        } else {
            return a[top];
        }
    }

    bool isEmpty() {
        return (top < 0);
    }
};

int precedence(char c) {
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

string infixToPostfix(string infix) {
    Stack s;
    string postfix = "";

    for (int i = 0; i < infix.length(); i++) {
        char c = infix[i];

        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')){
            postfix += c;
        }else if (c == '('){
            s.push(string(1, c));
        }else if (c == ')') {
            while (!s.isEmpty() && s.peek() != "(") {
                postfix += s.pop();
            }
            if (!s.isEmpty() && s.peek() == "(")
                s.pop();
        }else {
            while (!s.isEmpty() && precedence(c) <= precedence(s.peek()[0])) {
                postfix += s.pop();
            }
            s.push(string(1, c));
        }
    }

    while (!s.isEmpty()) {
        postfix += s.pop();
    }

    return postfix;
}

int main() {
    string infix = "(A+B/C*(D+C)-F)";
    cout << "Infix Expression: " << infix << endl;
    string postfix = infixToPostfix(infix);
    cout << "Postfix Expression: " << postfix << endl;
    return 0;
}
