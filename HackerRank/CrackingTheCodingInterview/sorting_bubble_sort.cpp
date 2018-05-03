#include <iostream>
#include <vector>

using namespace std;

vector<int> swap(int i1, int i2, vector<int> nums) {
    int temp = nums[i1];
    nums[i1] = nums[i2];
    nums[i2] = temp;
    return nums;
    }


int main () {
    int n;
    cin >> n;
    vector<int> nums;
    int num;
    for (int i = 0; i < n; ++i) {
        cin >> num;
        nums.push_back(num);
        }
    
    int swap_count = 0;
    for (int i = 0; i < nums.size(); ++i)
        for (int j = 0; j < nums.size()-1; ++j)
            if (nums[j] > nums[j+1]) {
                swap_count += 1;
                nums = swap(j, j+1, nums);
                }  
                              
    cout << "Array is sorted in " << swap_count << " swaps." << endl;
    cout << "First Element: " << nums.front() << endl;
    cout << "Last Element: " << nums.back() << endl;
        
    return 0;
    }
