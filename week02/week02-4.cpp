/// week02-4.cpp 學習計畫 Basic 地2題
/// LeetCode389. Find the Difference
class Solution {
public:
    char findTheDifference(string s, string t) {
        int U[26] = {}; /// 有26個回收桶, 裡面都是0
        for (char c : s) { /// c++ 進階 for 迴圈寫法
        U[c-'a'] ++; /// 把字母放進「對應」的 回收桶 裡
        }
        for (char c : t) { /// c++ 進階 for 迴圈寫法
            U[c-'a'] --; ///把對應的桶子裡, 拿掉1個字母
            if(U[c-'a'] < 0) return c; /// 如果字母不夠用, 找到兇手
        }
        return 0;
    }
};
