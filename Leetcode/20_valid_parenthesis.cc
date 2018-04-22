#include <stack>
class Solution {
public:
    bool isValid(string s) {
        stack<char> checker;
        for (auto c : s) {
            if (c == '{' || c == '[' || c == '(' )
                checker.push(c);
            else if ((checker.size() > 0) && 
                     ((c == '}' && checker.top() == '{') || (c == ']' && checker.top() == '[') || (c == ')' && checker.top() == '(')))
                checker.pop();
            else
                return false;            
        }
    if (checker.size() == 0)
        return true;   
    else
        return false;
    }
};
