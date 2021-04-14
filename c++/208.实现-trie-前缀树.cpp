/*
 * @lc app=leetcode.cn id=208 lang=cpp
 *
 * [208] 实现 Trie (前缀树)
 */

// @lc code=start
class Trie {
private:
    Trie* son[26]; //以边存储字符，点记录单词结尾
    bool isWord;
public:
    //c++ 使用树节点注意内存泄漏的问题
    /** Initialize your data structure here. */
    Trie() {
        isWord = false;
        for (int i = 0; i < 26; i++)    son[i] = nullptr;    
    }

    ~Trie() {
        for (int i = 0; i < 26; i++)    delete son[i];
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* root = this;
        for (char x : word) {
            int cur = x - 'a';
            if (root -> son[cur] == nullptr)    root -> son[cur] = new Trie();
            root = root -> son[cur];
        }
        root -> isWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie* root = this;
        for (char x : word) {
            int cur = x - 'a';
            if(root->son[cur] == nullptr)   return false;
            root = root -> son[cur];
        }
        return root -> isWord;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie* root = this;
        for (char x: prefix) {
            int cur = x - 'a';
            if (root -> son[cur] == nullptr) return false;
            root = root -> son[cur];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end

