class Solution {
public:
    bool checkRecord(string s) {
        int total_a = 0;
        int total_l = 0;
        for (auto ch : s) {
            if(ch == 'A') {
                total_a += 1;
                total_l = 0;
                if (total_a > 1)
                    return false;
            }
            else if(ch == 'L') {
                total_l += 1;
                if (total_l > 2)
                    return false;
            }
            else
                total_l = 0;            
        }
        return true;
    }
};
