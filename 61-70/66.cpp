static auto xxx=[]{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        digits[digits.size()-1] += 1;
        int carry = 0;
        for(int i = digits.size()-1 ; i >= 0 ; i--)
        {
            digits[i] += carry;
            if(digits[i] >= 10)
            {
                digits[i] %= 10;
                carry = 1;
            }
            else carry = 0;
        }
        if(carry)
            digits.insert(digits.begin(), 1);
        return digits;
    }
};