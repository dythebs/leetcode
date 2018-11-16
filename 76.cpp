static auto xxx=[]{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    bool check(unordered_map<char, int> &a, unordered_map<char, int> &b) {
        for(char i = 'A' ; i <= 'Z' ; i++)
            if(a[i] > b[i]) 
                return false;
        for(char i = 'a' ; i <= 'z' ; i++)
            if(a[i] > b[i]) 
                return false;
        return true;
    }
    bool leftMove(int &l, unordered_map<char, int> &tmp, string &s) {
        if(l == s.size()-1)
            return false;
        tmp[s[l]]--;
        l++;
        return true;
    }
    bool rightMove(int &r, unordered_map<char, int> &tmp, string &s) {
        if(r == s.size()-1)
            return false;
        tmp[s[r+1]]++;
        r++;
        return true;
    }
    string minWindow(string s, string t) {
        string ans = "";
        unordered_map<char, int> t_map;
        for(int i = 0 ; i < t.size() ; i++)
            t_map[t[i]]++;
        unordered_map<char, int> tmp;
        int l = 0, r = 0;
        tmp[s[0]] = 1;
        while(1)
        {
            //向右直到找到一个包含t的子串
            while(!check(t_map, tmp)) {
                if(!rightMove(r, tmp, s))
                    goto endlabel;
            }
            //向左尝试缩小范围
            while(check(t_map, tmp)) {
                if(!leftMove(l, tmp, s))
                    break;
            }
            if(check(t_map, tmp))
            {
                if(r-l+1<ans.size() || ans == "")
                    ans = s.substr(l, r-l+1);
                break;
            }
            else
            {
                if(r-l+2<ans.size() || ans == "")
                    ans = s.substr(l-1, r-l+2);
            }
        }
        endlabel:;
        return ans;
    }
};