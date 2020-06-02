#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string addBinary(string a, string b)
    {
        string result = "";
        int sum = 0;

        int i = a.length() - 1, j = b.length() - 1;
        while (i >= 0 || j >= 0 || sum == 1)
        {

            sum += ((i >= 0) ? a[i] - '0' : 0);
            sum += ((j >= 0) ? b[j] - '0' : 0);

            result = char(sum % 2 + '0') + result;

            sum /= 2;

            i--;
            j--;
        }
        return result;
    }
};

int main()
{
    string a = "1010", b = "1011";
    Solution sl;
    cout << sl.addBinary(a, b) << endl;
}