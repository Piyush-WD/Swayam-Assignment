1class Solution {
2public:
3    int myAtoi(string s) {
4        int i = 0, n = s.size();
5        while (i < n && s[i] == ' ')
6            i++;
7        bool neg = false;
8        if (i < n && (s[i] == '+' || s[i] == '-')) {
9            if (s[i] == '-') neg = true;
10            i++;
11        }
12        long long result = 0;
13        while (i < n && isdigit(s[i])) {
14            int digit = s[i] - '0';
15            if (result > (INT_MAX - digit) / 10) {
16                return neg ? INT_MIN : INT_MAX;
17            }
18            result = result * 10 + digit;
19            i++;
20        }
21        return neg ? -result : result;
22    }
23};
24