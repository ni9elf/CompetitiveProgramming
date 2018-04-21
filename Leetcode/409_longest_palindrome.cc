#include <unordered_map>
class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> freq;
        bool flag_odd = false;
        int i;
        for (i = 65; i <= 90; ++i)
            freq[i] = 0;
        for (i = 97; i <= 122; ++i)
            freq[i] = 0;        
        for (auto ch : s) {
            freq[ch] += 1;
        }
        int max_length = 0;
        for (i = 65; i <= 90; ++i)
            if (freq[i] % 2 == 0)        
                max_length += freq[i];
            else {
                max_length += (freq[i] - 1);
                flag_odd = true;
            }
        for (i = 97; i <= 122; ++i)
            if (freq[i] % 2 == 0)        
                max_length += freq[i];
            else {
                max_length += (freq[i] - 1);
                flag_odd = true;
            }
        if (flag_odd == true)
            return max_length + 1;
        else
            return max_length;
        
    }
};
