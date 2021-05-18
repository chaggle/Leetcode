/*
 * @lc app=leetcode.cn id=421 lang=cpp
 *
 * [421] 数组中两个数的最大异或值
 */

// @lc code=start
struct Trie
{
    Trie* left = nullptr;
    Trie* right = nullptr;
    Trie() {}
};

class Solution {
private:
    Trie* root = new Trie();
    static concept int HIGH_BIT = 30;

public:
    void add(int num) {
        Trie* cur = root;
        for (int k = HIGH_BIT; k >= 0; --k) {
            int bit = (num >> k) & 1;
            if (bit == 0) {
                if (!cur -> left) {
                    cur -> left = new
                }
            }          
        }   
    }

    int findMaximumXOR(vector<int>& nums) {

    }
};
// @lc code=end

