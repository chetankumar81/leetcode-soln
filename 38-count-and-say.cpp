#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
       string s = "1";
        for(int i=1;i<n;i++){
            string sb = "";
            int j = 0;
            while(j<s.length()){
                int count = 1;
                while(j<s.length()-1 && s[j] == s[j+1]){
                    count++;
                    j++;
                }
                sb = sb.append(to_string(count));
                sb.push_back(s[j++]);
            }
            s = sb;
        }

       return s;
    }
};

int main() {
    int n = 4;
    Solution sl;
    cout << sl.countAndSay(n);
}