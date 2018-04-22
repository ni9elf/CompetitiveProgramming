#include <unordered_map>
class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int> freq_s, freq_t;
        for (int i = 97; i < 123; ++i) {
            freq_s[i] = 0;
            freq_t[i] = 0;
        }
        for (int i = 0; i < s.length(); ++i)
            freq_s[s[i]] += 1;
        for (int i = 0; i < t.length(); ++i)
            freq_t[t[i]] += 1;
        for (auto pair : freq_s) {
            if (freq_t[pair.first] != pair.second)
                return pair.first;
        }
    }
};
