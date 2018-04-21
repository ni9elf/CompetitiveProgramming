class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end(), greater<int>());
        int index = 0;
        for (int i = 0; i < citations.size(); ++i)
            if (citations[i] >= i+1)
                index += 1;        
        return index;
    }
};
