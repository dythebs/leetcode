static auto xxx=[]{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> count;
        for(auto word : words)
            count[word]++;
        vector<int> ans;
        if(words.size() == 0 || s.size() == 0)
            return ans;
        for(int i = 0 ; i < s.length() - words.size()*words[0].length() + 1 ; i++)
        {
            unordered_map<string, int> seen;
            int j = 0;
            while(j < words.size())
            {
                string sub = s.substr(i+j*words[0].length(),words[0].length());
                if(count.count(sub))
                {
                    seen[sub]++;
                    if(seen[sub] > count[sub])
                        break;
                }
                else
                    break;
                j++;
            }
            if(j == words.size())
                ans.push_back(i);
        }
        return ans;
    }
};