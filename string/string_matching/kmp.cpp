#include <bits/stdc++.h>
using namespace std;

vector<int> kmp(vector<int> &s)
{
    int n = s.size();
    vector<int> lps(n, 0);
    for (int i = 1, len = 0; i < n; i++)
    {
        while (len > 0 && s[i] != s[len])
            len = lps[len - 1];
        len = lps[i] = len + (s[i] == s[len]);
    }
    return lps;
}