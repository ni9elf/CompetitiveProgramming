class Solution {
public:
    string addStrings(string num1, string num2) {
        string result;
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        int carry = 0, val;
        int l1 = num1.length();
        int l2 = num2.length();
        int lim = max(l1, l2);
        for (int i = 0; i < lim; ++i) {
            if (i >= l1)
                val = carry + (num2[i] - '0');
            else if (i >= l2)
                val = carry + (num1[i] - '0');
            else
                val = carry + (num1[i] - '0') + (num2[i] - '0');
            carry = val / 10;
            val = val % 10;
            result += to_string(val);
        }
    if (carry > 0) 
        result += to_string(carry);
    reverse(result.begin(), result.end());
    return result;
    }
};
