#include <bits/stdc++.h>
using namespace std;

vector<int> z_algorithm(string &s)
{
    // if pattern then str = p + "#" + s;

    int n = s.size(), l = 0, r = 0;
    vector<int> z(n);

    for (int i = 1; i < n; i++)
    {
        if (i > r)
        {
            l = r = i;
            while (r < n && s[r] == s[r - l])
                r++;
            z[i] = r - l;
            r--;
        }
        else
        {
            int cur = i - l;
            if (z[cur] + i < r + 1)
                z[i] = z[cur];
            else
            {
                l = i;
                while (r < n && s[r] == s[r - l])
                    r++;
                z[i] = r - l;
                r--;
            }
        }
    }
    return z;
}