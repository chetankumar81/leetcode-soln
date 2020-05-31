#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        //auto ip = unique(nums.begin(), nums.end());
       /*  nums.resize(distance(nums.begin(),ip));
        return nums.size(); */
        return distance(nums.begin(),unique(nums.begin(), nums.end()));
    }
};

int main()
{
    vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    Solution sl;
    cout << sl.removeDuplicates(nums) << endl;
    return 0;
}