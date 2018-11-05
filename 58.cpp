static auto xxx=[]{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    int lengthOfLastWord(string s) {
        bool flag = false;
        int end = s.size()-1;
        s = ' ' + s;
        for(int i = s.size()-1 ; i >= 0 ; i--)
        {
            if(s[i] != ' ' && !flag)
                flag = true, end = i;
            if(s[i] == ' ' && flag)
            {
                return end-i;
            }
        }
        return 0;
    }
};