// week10-4.cpp 學習計畫 Math 第7題
// LeetCode 43. Multiply Strings
class Solution {
public:
    vector<int> myStrVec(string num) {
        vector<int> ans;
        for (int i = num.length() - 1; i >= 0; i--) { // 倒過來
            ans.push_back(num[i] - '0'); // 字母-字母,變數字
        }
        return ans;
    }

    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0"; // 任何數乘 0 就變 0

        vector<int> a = myStrVec(num1); // 把字串, 變陣列
        vector<int> b = myStrVec(num2);

        vector<int> ans(a.size() + b.size(), 0); // 用來放答案的格子

        for (int i = 0; i < a.size(); i++) { // a[i]
            for (int j = 0; j < b.size(); j++) { // b[j]
                ans[i + j] += a[i] * b[j];
            }
        }

        // 統一處理所有的進位
        int carry = 0;
        for (int i = 0; i < ans.size(); i++) {
            ans[i] += carry;
            carry = ans[i] / 10;
            ans[i] %= 10;
        }

        // 把倒過來的陣列, 變成字串
        string ans2 = "";
        bool leadingZero = true;
        for (int i = ans.size() - 1; i >= 0; i--) {
            if (leadingZero && ans[i] == 0) {
                continue; // 如果最前面「是0」避開它
            }
            leadingZero = false;
            ans2 += ('0' + ans[i]);
        }

        return ans2.empty() ? "0" : ans2; // 多了最高位的 0 怎麼辦？
    }
};
