class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.length() == 0)
            return 0;
        int dp[s.length()]; //下标为i的字符及其之前的最长长度
        memset(dp, 0, sizeof(dp));
        int ans = 0;
        for(int i = 1 ; i < s.length() ; i++)
        {
            if(s[i] == '(')
                continue;
            
            int preIndex = i - dp[i-1] - 1;
            if(s[preIndex] == '(')
            {
                dp[i] = dp[i-1] + 2;
                if(preIndex-1>0)
                    dp[i] += dp[preIndex-1];
            }
            ans = max(dp[i], ans);
        }
        return ans;
    }
};