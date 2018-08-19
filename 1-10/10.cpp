static auto xxx=[]{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    inline bool check(char a, char b)
    {
        return b == '.' ? true : a == b;
    }
    inline bool match(string &s, int sIdx, string &p, int pIdx) {
        if(sIdx >= s.size() && pIdx >= p.size())
            return true;
        if(sIdx != s.size() && pIdx >= p.size())
            return false;
        if(pIdx + 1 < p.size() && p[pIdx+1] == '*')
        {
            if(sIdx >= s.size())
                return match(s, sIdx, p, pIdx+2);
            if(check(s[sIdx],p[pIdx]))
                return match(s, sIdx, p, pIdx+2) || match(s, sIdx+1, p, pIdx+2) || match(s, sIdx+1, p, pIdx);
            else
                return match(s, sIdx, p, pIdx+2);
        }
        else
        {
            if(sIdx >= s.size())
                return false;
            if(check(s[sIdx],p[pIdx]))
                return match(s, sIdx+1, p, pIdx+1);
            else
                return false;
        }
    }
    bool isMatch(string s, string p) {
        return match(s, 0, p, 0);
    }
};