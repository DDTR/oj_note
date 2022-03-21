/*
76. 最小覆盖子串
给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 "" 。

 

注意：

对于 t 中重复字符，我们寻找的子字符串中该字符数量必须不少于 t 中该字符数量。
如果 s 中存在这样的子串，我们保证它是唯一的答案。
 

示例 1：

输入：s = "ADOBECODEBANC", t = "ABC"
输出："BANC"
示例 2：

输入：s = "a", t = "a"
输出："a"
示例 3:

输入: s = "a", t = "aa"
输出: ""
解释: t 中两个字符 'a' 均应包含在 s 的子串中，
因此没有符合条件的子字符串，返回空字符串。

*/
class Solution {
public:
    string minWindow(string s, string t) {
        int cnt = t.length();
        unordered_map<char, int> m;
        for (char ch : t) {
            m[ch]++;
        }
        int l = 0;
        int r = 0;
        string res = "";
        while (r < s.length()) {
            if (m.find(s[r]) != m.end()) {
                if (m[s[r]] > 0) {
                    cnt--;
                } 
                m[s[r]]--;
            }
            if (cnt == 0) {
                while (l < r && (m.find(s[l]) == m.end() || (m.find(s[l]) != m.end() && m[s[l]] < 0))) {
                    if (m.find(s[l]) != m.end() && m[s[l]] < 0) {
                        m[s[l]]++;
                    }
                    l++;
                }
                if (res == "" || res.length() > (r - l + 1)) {
                    res = s.substr(l, r - l + 1);
                }
                m[s[l]]++;
                l++;
                cnt++;
            }
            r++;
        }
        return res;
    }
};