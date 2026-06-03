class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();

        int nxt = 1;   // dp[n]
        int nxt2 = 0;  // dp[n+1] dummy

        for (int i = n - 1; i >= 0; i--) {
            int curr = 0;

            if (s[i] != '0') {
                curr = nxt;

                if (i + 1 < n) {
                    int num = (s[i] - '0') * 10 + (s[i + 1] - '0');
                    if (num >= 10 && num <= 26)
                        curr += nxt2;
                }
            }

            nxt2 = nxt;
            nxt = curr;
        }

        return nxt;
    }
};