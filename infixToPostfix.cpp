#include <iostream>
#include <stack>
#include <string>

using namespace std;

// 定义运算符的优先级
int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

// 将中缀表达式转换为后缀表达式
string infixToPostfix(const string& infix) {
    string postfix = "";
    stack<char> s;

    for (char ch : infix) {
        // 如果是操作数，则直接添加到后缀表达式中
        if (isalnum(ch))
            postfix += ch;
        // 如果是左括号，压入栈中
        else if (ch == '(')
            s.push(ch);
        // 如果是右括号，将栈中的运算符弹出直到遇到左括号
        else if (ch == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            s.pop(); // 弹出左括号
        }
        // 如果是运算符，将栈中优先级大于等于当前运算符的运算符弹出，然后将当前运算符压入栈中
        else {
            while (!s.empty() && precedence(s.top()) >= precedence(ch)) {
                postfix += s.top();
                s.pop();
            }
            s.push(ch);
        }
    }

    // 将栈中剩余的运算符弹出
    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }

    return postfix;
}

int main() {
    string infix_expression;
    cout << "Enter an infix expression: ";
    getline(cin, infix_expression);

    string postfix_expression = infixToPostfix(infix_expression);
    cout << "Postfix expression: " << postfix_expression << endl;

    return 0;
}