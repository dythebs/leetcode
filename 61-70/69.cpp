static auto xxx=[]{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    using ll = long long int;
    int check(ll t, ll x)
    {
        return t*t <= x;
    }
    int mySqrt(int x) {
        ll l = 0, r = x;
        while(l < r)
        {
            ll mid = l + (r-l+1)/2; //1100
            //cout<<mid<<endl;
            if(check(mid, x))
                l = mid;
            else r = mid-1;
        }
        return l;
    }
};