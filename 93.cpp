class Solution {
public:
    int valid(string s) {
        if(s.size() > 3) return false;
        int a = stoi(s);
        if(to_string(a) != s) return false;
        if(a <= 255 && a >= 0) return true;
        return false;
    }
    vector<string> temp;
    vector<string> ans;
    void dfs(string &s, int index, int last) {
        if(index == s.size())
            return;
        if(last == 0){
            string tmp = s.substr(index);
            if(valid(tmp)){
                string a = temp[0];
                for(int i = 1 ; i < temp.size() ; i++)
                    a += "." + temp[i];
                a += "."+tmp;
                ans.push_back(a);
            }
            return;
        }
        
        for(int i = index ; i < s.size() && i-index < 4; i++)
        {
            string tmp = s.substr(index, i-index+1);
            if(valid(tmp))
            {
                temp.push_back(tmp);
                dfs(s, i+1, last-1);
                temp.pop_back();
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        dfs(s, 0, 3);
        return ans;
    }
};