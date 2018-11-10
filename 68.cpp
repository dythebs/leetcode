static auto xxx=[]{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int len = 0;
        vector<string> tmp;
        vector<string> ans;
        for(int i = 0 ; i < words.size() ; i++)
        {
            if(len == 0) {
                len += words[i].size();
                tmp.push_back(words[i]);
            } else {
                if(len + 1 + words[i].size() <= maxWidth) {
                    len += 1 + words[i].size();
                    tmp.push_back(words[i]);
                } else {
                    string t = tmp[0];
                    if(tmp.size() > 1) {
                        int left = maxWidth;
                        for(int i = 0 ; i < tmp.size() ; i++)
                            left -= tmp[i].size();
                        int spn = left / (tmp.size()-1);
                        int ex = left % (tmp.size()-1);
                        for(int i = 1 ; i < tmp.size() ; i++)
                        {
                            if(ex-->0) {
                                string tt(spn+1, ' ');
                                t += tt;
                            } else {
                                string tt(spn, ' ');
                                t += tt;
                            }
                            t += tmp[i];
                        }
                    } else {
                        t += string(maxWidth-t.size(), ' ');
                    }
                    ans.push_back(t);
                    tmp.clear();
                    len = 0;
                    i--;
                }
            }
        }
        
        string t = tmp[0];
        for(int i = 1 ; i < tmp.size() ; i++)
            t += ' ' + tmp[i];
        t += string(maxWidth-t.size(), ' ');
        ans.push_back(t);

        return ans;
    }
};