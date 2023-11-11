#include <bits/stdc++.h>

using namespace std;

string expr1 = "{[()]}";
string expr2 = "{{[(]}";
string expr3 = "{[()]]}}";

stack<char> s;

bool ispair(char e, char t) {
    if (((t == '[') && (e == ']')) ||
        ((t == '{') && (e == '}')) ||
        ((t == '(') && (e == ')')))
        return true;
    return false;
}

bool balancedParentheses(string exp) { // Changed to const char*
    size_t len = exp.length();

    for (int i = 0; i < len; i++) {
        if (exp[i] == '[' || exp[i] == '{' || exp[i] == '(') {
            s.push(exp[i]);
        } else if (exp[i] == ']' || exp[i] == '}' || exp[i] == ')') {
            if (s.empty()) {
                return false;
            } else {
                char t = s.top();
                if (!ispair(exp[i], t)) {
                    return false;
                } else {
                    s.pop();
                }
            }
        }
    }
    return s.empty();
}

int main() {

    cout << " Expr1 = " << expr1 << " is " << (balancedParentheses(expr1) ? "balanced" : "not balanced") << endl;
    cout << " Expr2 = " << expr2 << " is " << (balancedParentheses(expr2) ? "balanced" : "not balanced") << endl;
    cout << " Expr3 = " << expr3 << " is " << (balancedParentheses(expr3) ? "balanced" : "not balanced") << endl;

    return 0;
}
