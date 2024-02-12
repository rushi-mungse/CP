<h2 style="color:orange;"> Pattern Matching (String Matching) Algorithm : Z Algorithm </h2>

##### Time Complexity : `O(m + n)`;

##### Space Complexity : `O(m + n)`;

---

#### Code

```cpp
vector<int> z_algorithm(string &str, string &pattern) {
    string ttl = pattern + "#" + str;
    int n = ttl.size(), m = pattern.size(), l = 0, r = 0;
    vector<int> z(n), pattern_match;

    for (int i = 1; i < n; i++) {
        if (i > r) {
            l = r = i;
            while (r < n && ttl[r] == ttl[r - l]) r++;
            z[i] = r - l;
            r--;
        }
        else {
            int cur = i - l;
            if (z[cur] + i < r + 1) z[i] = z[cur];
            else {
                l = i;
                while (r < n && ttl[r] == ttl[r - l]) r++;
                z[i] = r - l;
                r--;
            }
        }
        if(z[i] == m) pattern_match.push_back(i - m - 1);
    }
    return pattern_match;
}
```
