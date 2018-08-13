static auto xxx=[]{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    void f(string&ans, int num, char _1, char _5, char _10)
    {
        if(num == 9)
            ans = ans + _1 + _10;
        else if(num == 4)
            ans = ans + _1 + _5;
        else
        {
            if(num >= 5)
                num -= 5, ans += _5;
            while(num--)
                ans += _1;
        }
    }
    string intToRoman(int num) {
        string ans = "";
        f(ans, num/1000%10, 'M', '\0', '\0');
        f(ans, num/100%10, 'C', 'D', 'M');
        f(ans, num/10%10, 'X', 'L', 'C');
        f(ans, num%10, 'I', 'V', 'X');
        return ans;
    }
};