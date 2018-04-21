class Solution {
public:
    bool isPowerOfTwo(int n) {
        //how many bits to allocate?
        bitset<10000> bin(n);
        if (bin.count() == 1)
            return true;
        else
            return false;
    }
};
