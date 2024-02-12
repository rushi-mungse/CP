<h2 style="color:orange;"> Pattern Matching (String Matching) Algorithm : Rabin Karp (Rolling Hash) Algorithm </h2>

##### Time Complexity : `O(m + n)`;

##### Space Complexity : `O(m + n)`;

---

#### Code

```cpp
vector<int> rolling_hash(string &text, string &pattern) {
    long long mod = 1E9 + 9, base = 31;
    int m = pattern.size(), n = text.size();

    vector<long long> power(max(m, n), 1);
    for(int i = 1; i < n; i++) power[i] = (power[i - 1] * base) % mod;


    long long pattern_hash = 0;
    for(int i = 0; i < m; i++)
        pattern_hash = (pattern_hash + (pattern[i] - 'a' + 1) * power[i]) % mod;

    vector<long long> text_hash(n + 1);
    for(int i = 0; i < n; i++)
        text_hash[i + 1] = (text_hash[i] + (text[i] - 'a' + 1) * power[i]) % mod;

    vector<int> pattern_match;
    for(int i = 0; i <= n - m; i++) {
        long long cur_hash = (text_hash[i + m] - text_hash[i] + mod) % mod;
        if(cur_hash == (pattern_hash * power[i]) % mod) pattern_match.push_back(i);
    }

    return pattern_match;
}
```
