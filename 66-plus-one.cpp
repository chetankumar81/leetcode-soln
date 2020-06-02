#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        bool done = false;
        for (int i = digits.size() - 1; i > -1; i--)
        {
            if (digits[i] == 9)
            {
                digits[i] = 0;
            }
            else
            {
                digits[i] += 1;
                done = true;
                break;
            }
        }

        if (done)
            return digits;

        vector<int> res(digits.size() + 1);
        res[0] = 1;
        return res;
    }
};

int main()
{
    vector<int> digits = {9, 9, 9};
    Solution sl;
    for (const auto i : sl.plusOne(digits))
        cout << i << " ";
}