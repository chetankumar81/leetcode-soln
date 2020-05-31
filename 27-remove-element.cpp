#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        return distance(nums.begin(),remove(nums.begin(),nums.end(),val));
    }
};

int main() {
    vector<int> nums = {0,1,2,2,3,0,4,2};
    int val = 2;
    Solution sl;
    cout << sl.removeElement(nums,val);
}