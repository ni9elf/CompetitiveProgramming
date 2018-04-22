class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        string ans;
        for (int i = 0; i < S.length(); ++i) {
            if (S[i] == '-')
                continue;
            else
                ans += string(1, toupper(S[i]));
        }
        if (ans.size() == 0)
            return "";
        else if(ans.length() <= K)
            return ans;
        else {
            int size_first_group = ans.length() % K;
            if (size_first_group == 0)
                size_first_group = K;
            ans.insert(size_first_group, "-");
            int loc = size_first_group + K + 1;
            while (loc < ans.size()) {
                ans.insert(loc, "-");
                loc += K+1;
            }            
        return ans;
        }
    }
};
