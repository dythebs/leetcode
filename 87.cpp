class Solution {
public:
    bool scramble(string& s1, int f1, int t1, string& s2, int f2, int t2) {
        if(t1-f1 != t2-f2) return false;
        if(t1==f1) return s1[f1] == s2[f2];
        int letters[26];
        memset(letters, 0, sizeof(letters));
        for(int i = f1 ; i <= t1 ; i++)
            letters[s1[i]-'a']++;
        for(int i = f2 ; i <= t2 ; i++)
            letters[s2[i]-'a']--;
        for(int i = 0 ; i < 26 ; i++)
            if(letters[i] != 0)
                return false;
        for(int i = 0 ; i < t1-f1 ; i++) //枚举左半边长度-1
        {
            //s1左半边和s2左半边互为扰乱字符串
            if(scramble(s1, f1, f1+i, s2, f2, f2+i) && scramble(s1, f1+i+1, t1, s2, f2+i+1, t2))
                return true;
            //s1左半边和s2右半边互为扰乱字符串
            if(scramble(s1, f1, f1+i, s2, t2-i, t2) && scramble(s1, f1+i+1, t1, s2, f2, t2-i-1))
                return true;
        }
        return false;
                
    }
    bool isScramble(string s1, string s2) {
        return scramble(s1, 0, s1.size()-1, s2, 0, s2.size()-1);
    }
};