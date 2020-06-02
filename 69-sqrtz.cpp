#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        return int(sqrt(x));
    }
};

int main() {
    int x = 4;
    Solution sl;
    cout << sl.mySqrt(x);
}