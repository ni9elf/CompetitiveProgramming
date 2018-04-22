class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1, value;
        for (int i = digits.size()-1; i >= 0; --i) {
            value = digits[i] + carry;
            carry = value / 10;
            value = value % 10;
            digits[i] = value;            
        }
        if (carry > 0)
            digits.insert(digits.begin(), carry);            
        return digits;
    }
};
