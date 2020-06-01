//also known as kadane's algorithm
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_so_far = nums[0];
        int max_end_here = nums[0];

        for(int i=1;i<nums.size();i++){
            max_end_here = max(nums[i],max_end_here+nums[i]);
            max_so_far = max(max_so_far,max_end_here);
        }
        return max_so_far;
    }
};

int main() {
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    Solution sl;
    cout << sl.maxSubArray(nums);
}