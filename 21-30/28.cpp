static auto xxx=[]{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    int match(string &s1, string &s2, int *Next) {
        for(int i = 0 , j = 0 ; i < s1.size() ;)
        {
            if(s1[i] == s2[j])
            {
                i++,j++;
                if(j == s2.size())
                    return i - j;
            }
            else
                if(j == 0)
                    i++;
                else
                    j = Next[j];
        }
        return -1;
    }
    int strStr(string haystack, string needle) {
        if(needle.size() == 0)
            return 0;
        int Next[needle.size()+1];
        Next[0] = Next[1] = 0;
        for(int i = 1 ; i < needle.size() ; i++)
        {
            int k = Next[i];
            while(needle[i] != needle[k] && k)
                k = Next[k];
            Next[i+1] = needle[i] == needle[k] ? k+1 : 0;
        }
        return match(haystack, needle, Next);
    }
};