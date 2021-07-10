/*
 * @lc app=leetcode.cn id=981 lang=cpp
 *
 * [981] 基于时间的键值存储
 */

// @lc code=start
class TimeMap {
public:
    /** Initialize your data structure here. */
    unordered_map<string, map<int, string>> m;
    TimeMap() {

    }
    
    void set(string key, string value, int timestamp) {
        m[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        if(m.count(key) == 0 || timestamp < m[key].begin() -> first) return "";
        return prev(m[key].upper_bound(timestamp)) -> second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
// @lc code=end

