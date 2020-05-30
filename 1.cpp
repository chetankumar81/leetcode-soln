#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]] = i;
        }
        
        for(int i=0;i<nums.size();i++){
            int comp = target - nums[i];
            auto itr = mp.find(comp);
            if (itr != mp.end() && itr->second != i){
                result.push_back(i);
                result.push_back(mp[comp]);
                break;
            }
        }
        return result;
    }
};