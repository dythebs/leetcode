static auto xxx=[]{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    string simplifyPath(string path) {
        stringstream ss(path);
        string tmp;
        vector<string> items;
        while(getline(ss, tmp, '/')) {
            if(tmp != "" && tmp != "." && tmp != "..")
                items.push_back(tmp);
            if(tmp == ".." && !items.empty())
                items.pop_back();
        }
        string ans = "";
        for(int i = 0 ; i < items.size() ; i++)
            ans += '/' + items[i];
        return ans == "" ? "/" : ans;
    }
};