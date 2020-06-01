#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        stringstream str(s);
        string temp;
        int n = 0;
        while (str >> temp)
        {
            n = temp.size();
        }
        return n;
    }
};

int main()
{
    string s = "a hello";
    Solution sl;
    cout << sl.lengthOfLastWord(s);
}