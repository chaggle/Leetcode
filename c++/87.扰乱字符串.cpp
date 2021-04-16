/*
 * @lc app=leetcode.cn id=87 lang=cpp
 *
 * [87] 扰乱字符串
 */

// @lc code=start
class Solution {
public:
    /* //两种方法，1：记忆化搜索 
    vector<vector<vector<int>>> cache;
    string s1, s2;
    int n;
    int NO = -1, YES = 1, EMPTY = 0;

    bool isScramble(string _s1, string _s2) {
        s1 = _s1, s2 = _s2;
    	if(s1 == s2) return true;
    	if(s1.size() != s2.size()) return false;
    	n = s1.size();
    	cache.resize(n, vector<vector<int>>(n, vector<int>(n+1, 0)));

    	return dfs(0, 0, n);
    }

    bool dfs(int i, int j, int len) {
        if (cache[i][j][len] != EMPTY)  return cache[i][j][len] == YES;

        string a = s1.substr(i, len), b = s2.substr(j, len);

        if (a == b) return cache[i][j][len] = YES || true;

        if (!check(a, b))   return cache[i][j][len] = NO && false;

        for (int k = 1; k < len; k++) {
            if (dfs(i, j, k) && dfs(i + k, j + k, len - k))     return cache[i][j][len] = YES || true;
            if (dfs(i, j + len - k, k) && dfs(i + k, j, len - k))   return cache[i][j][len] = YES || true;
        }
        cache[i][j][len] = NO;
        return false;
    }

    bool check(string s1, string s2) {
        if (s1.size() != s2.size())  return false;
        vector<int>cnt1(26, 0), cnt2(26, 0);
        for (auto c : s1)   cnt1[c - 'a']++;
        for (auto c : s2)   cnt2[c - 'a']++;
        return cnt1 == cnt2;
    } */
    //2：区间dp的方法
    bool isScramble(string s1, string s2) {
    	if(s1 == s2) return true;
    	if(s1.size() != s2.size()) return false;

    	int n = s1.size();
    	vector<vector<vector<int>>> f(n, vector<vector<int>>(n, vector<int>(n+1, 0)));

    	// 先处理长度为 1 的情况
    	for(int i = 0; i < n; i++) {
    		for(int j = 0; j < n; j++) {
    			if(s1[i] == s2[j])
    				f[i][j][1] = 1;
    		}
    	}

    	// 再处理其余长度情况
    	for(int len = 2; len <= n; len++) {
    		for(int i = 0; i+len <= n; i++) {
    			for(int j = 0; j+len <= n; j++) {
    				for(int k = 1; k < len; k++) {
    					bool a = f[i][j][k] && f[i+k][j+k][len-k];
    					bool b = f[i][j+len-k][k] && f[i+k][j][len-k];
    					if(a || b) 
    						f[i][j][len] = true;
    				}
    			}
    		}
    	}
    	return f[0][0][n];
    }
};
// @lc code=end

