static auto xxx=[]{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
    int jiecheng[10];
    int used[10];
public:
    Solution() {
        jiecheng[0] = 1;
        for(int i = 1 ; i <= 9 ; i++)
            jiecheng[i] = jiecheng[i-1]*i;
    }
    int getN(int n) {
        int k = 0, i = 1;
        while(1)
        {
            if(used[i++])
                continue;
            if(++k == n)
            {
                used[i-1] = 1;
                return i-1;
            }
        }
    }
    string getPermutation(int n, int k) {
        memset(used, 0, sizeof(used));
        string ans = "";
        while(n>1) {
            int b = jiecheng[n-1];
            int rank = (k-1)/b;
            k -= rank*b;n--;
            ans += '0' + getN(rank+1);
        }
        ans += '0' + getN(1);
        return ans;
    }
};