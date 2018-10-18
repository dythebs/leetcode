static auto xxx=[]{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
    vector<string> ans;
public:
    Solution() {
        ans.push_back("1");
        for(int i = 1 ; i < 30 ; i++)
        {
            int num = 0;
            char c = '\0';
            string temp = "";
            for(int j = 0 ; j < ans[i-1].length() ; j++)
            {
                if(num == 0)
                    c = ans[i-1][j];
                num++;
                if(j+1 < ans[i-1].length() && ans[i-1][j+1] == ans[i-1][j])
                    continue;
                temp += '0' + num;
                temp += c;
                num = 0;
            }
            ans.push_back(temp);
            
        }
    }
    string countAndSay(int n) {
        return ans[n-1];
    }
};