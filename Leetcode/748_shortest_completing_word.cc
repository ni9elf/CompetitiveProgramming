class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        unordered_map<char, int> p_freq;
        for (auto ch : licensePlate)   
            if ((ch >= 97 && ch <= 122) || (ch >= 65 && ch <= 90)) {
                ch = tolower(ch);
                if (p_freq.find(ch) == p_freq.end())
                    p_freq[ch] = 1;
                else
                    p_freq[ch] += 1;
            }
        for (auto pair : p_freq)
            cout << pair.first << " " << pair.second << endl;
        unordered_map<char, int> w_freq;
        bool flag_ans = true;
        vector<string> possible_words;
        for (auto word : words) {   
            w_freq.clear();
            for (auto ch : word)
                if (w_freq.find(ch) == w_freq.end())
                    w_freq[ch] = 1;
                else
                    w_freq[ch] += 1;  
            cout << word << endl;
            for (auto pair : w_freq)
                cout << pair.first << " " << pair.second << endl;            
            for (auto pair : p_freq)
                if (w_freq.find(pair.first) == w_freq.end()) {
                    flag_ans = false;
                    break;
                }
                else if (w_freq[pair.first] < pair.second) {
                    flag_ans = false;
                    break;
                }
            if (flag_ans == true)
                possible_words.push_back(word);
            else
                flag_ans = true;
            
        }
        int min_len = possible_words[0].length();
        string ans = possible_words[0];
        for (auto word : possible_words)
            if (word.length() < min_len) {
                min_len = word.length();
                ans = word;
            }
        return ans;                
    }
};
