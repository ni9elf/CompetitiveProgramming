class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int split_index = 0, no_chunks = 0;
        for (int i = 0; i < arr.size(); ++i) {
            if (split_index == i && arr[i] <= split_index) {
                no_chunks += 1;
                split_index += 1;
            }
            else if (arr[i] > split_index)
                split_index = arr[i];
        }
        return no_chunks;
    }
};
