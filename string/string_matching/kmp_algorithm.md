<h2 style="color:orange;"> Pattern Matching (String Matching) Algorithm : KMP Algorithm </h2>

##### Time Complexity : `O(m + n)`;

##### Space Complexity : `O(m + n)`;

---

#### Code

```cpp
vector<int> kmp(string &str, string &pattern) {
    string ttl = pattern + "#" + str;
    int n = ttl.size(), m = pattern.size();

    vector<int> lps(n, 0), pattern_match;
    for (int i = 1, len = 0; i < n; i++) {
        while (len > 0 && ttl[i] != ttl[len])
            len = lps[len - 1];
        len = lps[i] = len + (ttl[i] == ttl[len]);
        if(lps[i] == m) pattern_match.push_back(i - 2*m);
    }
    return pattern_match;
}

```
