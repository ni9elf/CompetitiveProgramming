class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map <char, int> char_to_index;       
        map <int, int> index_to_freq;    
        //for (int i = 97; i <= 122; ++i)
        //    char_to_index[i] = -1;
        for (int i = 0; i < s.length(); ++i) {
            if (char_to_index.find(s[i]) == char_to_index.end()) {
                char_to_index[s[i]] = i;        
                index_to_freq[char_to_index[s[i]]] = 1;   
            }
            else
                index_to_freq[char_to_index[s[i]]] += 1;            
        }
        //for (auto pair : freq) 
        //    cout << pair.first << " " << pair.second << endl;
        
        for (auto pair : index_to_freq) {            
            if (pair.second == 1)
                return pair.first;
        }
        return -1;
    }
};
