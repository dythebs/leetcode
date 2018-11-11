static auto xxx=[]{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    string addBinary(string a, string b) {
        string& longer = a.size() >= b.size() ? a : b;
        string& shorter = a.size() < b.size() ? a : b;
        string ans = "";
        int cha = longer.size() - shorter.size();
        int carry = 0;
        for(int i = shorter.size()-1 ; i >= 0 ; i--)
        {
            int tmp = carry + (longer[i+cha] - '0') + (shorter[i] - '0');
            carry = 0;
            if(tmp > 1)
                tmp %= 2, carry = 1;
            ans = static_cast<char>(tmp + '0') + ans; 
        }
        for(int i = cha-1 ; i >= 0 ; i--)
        {
            int tmp = carry + (longer[i] - '0');
            carry = 0;
            if(tmp > 1)
                tmp %= 2, carry = 1;
            ans = static_cast<char>(tmp + '0') + ans; 
        }
        if(carry)
            ans = '1' + ans;
        return ans;
    }
};