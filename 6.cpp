static const auto ____ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows < 2 || s.size() == 0)
            return s;
        char str[s.size()+1];
        int k = 0;
        int interval = ((numRows - 2) << 1) + 2;
        for(int i = 0 ; i < numRows ; i++)
        {
            int subInterval = interval - (i << 1);
            for(int j = i ; j < s.size() ; j += interval)
            {
                str[k++] = s[j];
                if(i != 0 && i != numRows-1)
                {
                    if(j+subInterval < s.size())
                        str[k++] = s[j+subInterval];
                }
            }
        }
        str[k] = '\0';
        return str;
    }
};