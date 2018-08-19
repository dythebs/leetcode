static auto xxx=[]{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.size();
        if(len == 0)
            return "";
        int dp[len][len];
        memset(dp, 0, sizeof(dp));
        //初始化长度为1和2的回文串
        for(int i = 0 ; i < len ; i++)
        {
            dp[i][i] = 1;
            if(i < len - 1 && s[i] == s[i+1])
                dp[i][i+1] = 1;
        }
        //从3开始枚举回文串的长度
        for(int l = 3 ; l <= len ; l++)
        {                  //j的大小不能超过字符串的长度，由于l最小为3，因此不需要限制i+1的大小
            for(int i = 0 ; i + l - 1 < len ; i++)
            {
                int j = i + l - 1;
                if(s[i] == s[j])
                    dp[i][j] = dp[i+1][j-1];
            }
        }
        int a = 0, ans = 1;
        for(int i = 0 ; i < len ; i++)
        {
            for(int j = i ; j < len ; j++)
            {
                if(dp[i][j] == 1 && j - i + 1 > ans)
                {
                    ans = j - i + 1;
                    a = i;
                }
            }
        }
        return s.substr(a,ans);
    }
};