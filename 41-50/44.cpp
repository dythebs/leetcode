static auto xxx=[]{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
    unordered_map<long long int, int> Map;
public:
    bool match(string &s, string &p, int si, int pi) {
        long long int temp = si;
        temp = (temp << 32) + pi;
        if(Map.count(temp))
            return false;
        Map[temp] = 1;
        if(si == s.size() && pi == p.size())
            return true;
        if(si != s.size() && pi == p.size())
            return false;
        if(p[pi] == '*')
        {
            if(si == s.size())
                return match(s, p, si, pi+1);
            return match(s, p, si, pi+1) || match(s, p, si+1, pi);
        }
        else
        {
            if(si == s.size())
                return false;
            if(p[pi] == '?')
                return match(s, p, si+1, pi+1);
            else
            {
                if(p[pi] == s[si])
                    return match(s, p, si+1, pi+1);
                else
                    return false;
            }
        }
        
    }
    bool isMatch(string s, string p) {
        Map.clear();
        return match(s, p, 0 ,0);
    }
};