#include <bits/stdc++.h>

using namespace std;

//1st soln
class Solution {
public:
    int romanToInt(string s) {
        int num = 0;
        map<char,int> mp;
        mp['I'] = 1;mp['V'] = 5;mp['X'] = 10;mp['L'] = 50;mp['C'] = 100;mp['D'] = 500;mp['M'] = 1000;
        int len = s.length();
        for(int i=0;i<len;i++){
            if (i< len-1 && ((s[i] == 'I' && s[i+1] == 'V') || (s[i] == 'I' && s[i+1] == 'X') || (s[i] == 'X' && s[i+1] == 'L') || (s[i] == 'X' && s[i+1] == 'C') || (s[i] == 'C' && s[i+1] == 'D') || (s[i] == 'C' && s[i+1] == 'M'))) {
                num += (mp[s[i+1]] - mp[s[i]]);
                i++;
            } else {
                num += mp[s[i]];
            }
            
        }
        return num;
    }
};

//2nd soln
class Solution {
public:
    int romanToInt(string s) {
        int num = 0;
        map<char,int> mp;
        mp['I'] = 1;mp['V'] = 5;mp['X'] = 10;mp['L'] = 50;mp['C'] = 100;mp['D'] = 500;mp['M'] = 1000;
        int len = s.length();
        for(int i=0;i<len;i++){
            int curr = mp[s[i]];
            if (i+1 < len) {
                int next = mp[s[i+1]];
                if (next > curr) {
                    num += (next - curr);
                    i++;
                }  else {
                    num += curr;
                }
            } else {
                  num += curr;
            }
        }
        return num;
    }
};