#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> st;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == ')' || s[i] == '}' || s[i] == ']')
            {
                char x = st.empty() ? '#' : st.top();
               if((s[i] == ')' && x != '(') || (s[i] == '}' && x != '{') || (s[i] == ']' && x != '[')){
                    return false;
               }
               st.pop();
            }
            else
            {
                st.push(s[i]);
            }
        }
        return st.empty();
    }
};

int main()
{
    string s = "()[]{}";
    Solution *sol = new Solution();
    cout << sol->isValid(s) << endl;
}