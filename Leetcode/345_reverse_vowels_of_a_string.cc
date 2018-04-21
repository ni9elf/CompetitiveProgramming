class Solution {
public:
    string reverseVowels(string s) {
        string vowels;
        for (auto ch : s)    
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
                vowels += string(1, ch);
        reverse(vowels.begin(), vowels.end());
        int j = 0;
        for (int i = 0; i < s.length(); ++i) 
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U') {
                s[i] = vowels[j];
                j += 1;
            }
        return s;
    }
};
