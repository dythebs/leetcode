static auto xxx=[]{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    double myPow(double x, long n) {
        if(n < 0)
            x = 1.0/x, n = -n;
        double ans = 1;
        while(n)
        {
            if(n&1)
                ans *= x;
            x *= x;
            n >>= 1;
        }
        return ans;
    }
};