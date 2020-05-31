#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        //with stl
        //return haystack.find(needle);

        //without stl
        int len1 = haystack.length();
        int len2 = needle.length();

        for (int i = 0; i <= len1 - len2; i++)
        {
            int j;
            for (j = 0; j < len2; j++)
                if (haystack[i + j] != needle[j])
                    break;

            if (j == len2)
                return i;
        }
        return -1;
    }
};

int main()
{
    string haystack = "aaabaa", needle = "aab";
    Solution sl;
    cout << sl.strStr(haystack, needle);
}