#include <iostream>
#include <stack>

using namespace std;

bool is_balanced(string expression) {
    stack <char> brackets;
    for (char c : expression) {
        if (c == '(' || c == '[' || c == '{')
            brackets.push(c);
        //don't access stack.top is stack is empty else seg fault            
        else if (brackets.empty() == false) { 
            if (c == ')' && brackets.top() == '(')
                brackets.pop();
            else if (c == ']' && brackets.top() == '[')
                brackets.pop();
            else if (c == '}' && brackets.top() == '{')
                brackets.pop();
            else
                return false;                            
            }  
        else
            return false;
        }
    if (brackets.empty() == true)
        return true;
    else 
        return false;
    }
    

int main() {
    int t;
    cin >> t;
    for (int i; i < t; ++i) {
        string exp;
        cin >> exp;
        if (is_balanced(exp) == true)
            cout << "YES\n";
        else
            cout << "NO\n";
        }        
    
    return 0;    
    }
        
