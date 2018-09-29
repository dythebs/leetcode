static auto xxx=[]{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        
        long absDividend = abs(static_cast<long>(dividend));
        long absDivisor = abs(static_cast<long>(divisor));
        
        int ans = 0;
        
        while(absDividend >= absDivisor)
        {
            long temp = absDivisor, tempa = 1;
            bool flag = false;
            while(absDividend > temp)
                temp <<= 1, tempa <<= 1, flag = true;
            if(flag)
            {
                temp >>= 1, tempa >>= 1;
                ans += tempa, absDividend -= temp;
            }
            else
                break;
        }

        while(absDividend >= absDivisor)
            absDividend -= absDivisor, ans++;

        if(dividend > 0 && divisor < 0 || dividend < 0 && divisor > 0)
            ans = -ans;

        return ans;
        
    }
};