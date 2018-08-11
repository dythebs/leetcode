static auto xxx=[]{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    int hash[130];
    int lengthOfLongestSubstring(string s) {
        memset(hash,0,sizeof(hash));
        int lastI = 0;
        int ans = 0;
        for(int i = 0; i < s.size() ; i++)
        {
            if(hash[s[i]])  //判断与s[i]重复的字符是否在当前窗口范围内
                lastI = max(hash[s[i]], lastI);
            ans = max(ans, i-lastI+1);
            hash[s[i]] = i + 1;
        }
        return ans;
    }
};