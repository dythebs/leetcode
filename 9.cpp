static auto xxx=[]{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    //反转一半数字和另一半对比
    bool isPalindrome(int x) {
                     //如果最后一位是0反转后没有前置0
        if(x < 0 || (x%10==0 && x!=0))
            return false;
        int half = 0;
        while(half < x)
        {
            half = half*10 + x%10;
            x /= 10;
        }
        //如果位数为偶数，第二个不影响结果，如果位数为奇数，中间位数字
        //一定在反转后的数字上
        return half == x || half/10 == x;
    }
};