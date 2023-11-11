#include <iostream>
#include <stack>
#include <cstring> // Changed from string.h to cstring for C++ compatibility

using namespace std;

const char *expr1 = "{[()]}";
const char *expr2 = "{{[(]}";
const char *expr3 = "{[()]]}}";

stack<char> s;

bool ispair(char e, char t) {
    if (((t == '[') && (e == ']')) ||
        ((t == '{') && (e == '}')) ||
        ((t == '(') && (e == ')')))
        return true;
    return false;
}

bool balancedParen(const char *exp) { // Changed to const char*
    size_t len = strlen(exp);

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

    cout << " Expr1 = " << expr1 << " is balanced? " << balancedParen(expr1) << endl;
    cout << " Expr2 = " << expr2 << " is balanced? " << balancedParen(expr2) << endl;
    cout << " Expr3 = " << expr3 << " is balanced? " << balancedParen(expr3) << endl;

    return 0;
}
