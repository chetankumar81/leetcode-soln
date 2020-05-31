#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        return distance(nums.begin(), lower_bound(nums.begin(),nums.end(),target));
    }
};

int main() {
    vector<int> nums = {1,3,5,6};
    int target = 5;
    Solution sl;
    cout << sl.searchInsert(nums,target);
}