/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
public:
    vector<int> flat_list;
    int curr_index, max_size;
    
    NestedIterator(vector<NestedInteger> &nestedList) {
        flat_list = makeFlat(nestedList);
        curr_index = 0;
        max_size = flat_list.size();
    }

    int next() {        
        int val = flat_list[curr_index];
        curr_index += 1;
        return val;
    }

    bool hasNext() {
        if (curr_index < max_size)
            return true;
        else
            return false;
    }
    
    vector<int> makeFlat(vector<NestedInteger> &nestedList) {
        vector<int> flattened;
        for (int i = 0; i < nestedList.size(); ++i) {
            if (nestedList[i].isInteger()) 
                flattened.push_back(nestedList[i].getInteger());
            else {          
                vector<int> this_list = makeFlat(nestedList[i].getList());
                flattened.insert(flattened.end(), this_list.begin(), this_list.end());
            }
        }
        return flattened;        
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
