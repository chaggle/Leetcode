/*
 * @lc app=leetcode.cn id=1603 lang=cpp
 *
 * [1603] 设计停车系统
 */

// @lc code=start
// class ParkingSystem {
// public:
//     最常见的解法
//     int b, m, s;
//     ParkingSystem(int big, int medium, int small) {
//         b = big;
//         m = medium;
//         s = small;
//     }
    
//     bool addCar(int carType) {
//         if (carType == 1)
//         {
//             if (b > 0)
//             {
//                 b--;
//                 return true;
//             }
//         }
//         else if  (carType == 2)
//         {
//             if (m > 0)
//             {
//                 m--;
//                 return true;
//             }
//         }
//         else if  (carType == 3)
//         {
//             if (s > 0)
//             {
//                 s--;
//                 return true;
//             }
//         }
//         return false;
//     } 
//       第二种拓展很强大的思路，来源于宫水三叶姐。
//       方法为：位运算 + CAS 对标的是 高并发加锁。
//       java 能通过但c++不行，思想未能完全理解，仍需继续学习研究
//     
//     int cnt;
//     ParkingSystem(int big, int medium, int small) {
//        for (int i = 0; i < 30; i++)
//        {
//            int cur = 0;
//            if (i < 10)
//            {
//                cur = (big >> 1) & 1;
//            }
//            else if(i < 20)
//            {
//                cur = (medium >> (i-10)) & 1;
//            }
//            else if(i < 30)
//            {
//                cur = (small >> (i-20)) & 1;
//            }
//            cnt += cur == 1 ? (1 << i) : 0;
//        }
//     }

//     bool addCar(int carType) 
//     {
//         int cur = countOfType(carType);
//         if (cur > 0)
//         {
//             setCount(carType, cur - 1);
//             return true;
//         }
//         return false;
//     }

//     int countOfType(int carType)
//     { 还是有些问题，等到自己能够消化这些进阶的知识，再来，现在消化吸收的效果与效率不够高！！
//         int ans = 0;
//         int start = --carType * 10, end = start + 10;
//         for (int i = start; i < end; i++)
//         {
//             if(((cnt >> 1) & 1) == 1)
//             {
//                 ans += (1 << (i - start));
//             }
//         }
//         return ans;
//     }

//     void setCount(int carType, int pc)
//     {
//         int start = --carType * 10, end = start + 10;
//         for (int i = start; i < end; i++)
//         {
//             if(((pc >> (i - start)) & 1) == 1)
//             {
//                 cnt = cnt | (1 << i);
//             }
//             else
//             {
//                 cnt = cnt &(~(1 << i));
//             }
//         }
//     }
// };
class ParkingSystem {
private:
    unordered_map<int, int> hash;
public:
    ParkingSystem(int big, int medium, int small)
    {
        hash[1] = big;
        hash[2] = medium;
        hash[3] = small;
    }

    bool addCar(int carType)
    {
        if (hash[carType] > 0)
        {
            hash[carType]--;
            return true;
        }
        else
            return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */
// @lc code=end

