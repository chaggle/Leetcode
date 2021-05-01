/*
 * @lc app=leetcode.cn id=690 lang=cpp
 *
 * [690] 员工的重要性
 */

// @lc code=start
/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    //典型思路 DFS、BFS;
    map<int, Employee*> m;
    int getImportance(vector<Employee*> employees, int id) {
        int n = employees.size();
        for (int i = 0; i < n; i++) 
            m.insert({employees[i] -> id, employees[i]});
        return getVal(id);
    }

    int getVal(int id) {
        Employee* master = m[id];
        int ans = master -> importance;
        for (int & old : master -> subordinates) {
            Employee* other = m[old];
            ans += other -> importance;
            for (int & sub : other -> subordinates) ans += getVal(sub); 
        }
        return ans;
    }
};
// @lc code=end

