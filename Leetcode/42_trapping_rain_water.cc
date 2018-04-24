class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() == 0)
            return 0;
        int left = height[0];
        int sum_w = 0;
        vector<int> curr;
        int h;
        for (int i = 0; i < height.size(); ++i) {
            h = height[i];
            if (h < left) {
                curr.push_back(h);
            }
            else {                
                sum_w += add_water(curr, min(left, h));
                left = h;
                curr.clear();
            }                            
        }
        //only one reverse pass till first increase
        int left_rev = height[height.size()-1];
        curr.clear();
        for (int i = height.size()-1; i >= 0; --i) {
            h = height[i];
            if (h < left_rev) {
                curr.push_back(h);
            }
            else {                
                sum_w += add_water(curr, min(left_rev, h));
                left_rev = h;
                curr.clear();
            }    
            if (h == left)
                break;
        }                
        return sum_w;
    }
    
    int add_water(vector<int>& curr, int pillar) {
        int sum_curr = 0;
        for (auto h : curr) 
            sum_curr += (pillar - h);
        return sum_curr;
    }
};
