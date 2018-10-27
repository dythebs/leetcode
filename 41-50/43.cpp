static auto xxx=[]{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    string multiply(string num1, string num2) {
        vector<int> res = {0};
        for(int i = num2.size()-1 ; i >= 0 ; i--)
        {
            int temp2 = num2[i] - '0';
            int carry = 0;
            vector<int> tempres;
            for(int j = num1.size()-1 ; j >=0 ; j--)
            {
                int temp1 = num1[j] - '0';
                int tempans = temp1 * temp2 + carry;
                carry = tempans / 10;
                tempans %= 10;
                tempres.push_back(tempans);
            }
            if(carry)
                tempres.push_back(carry);
            carry = 0;
            int add = num2.size() - i - 1;
            for(int j = 0 ; j < tempres.size() ; j++)
            {
                if(add + j >= res.size())
                    res.push_back(0);
                int tempans = tempres[j] + res[add+j] + carry;
                carry = tempans / 10;
                tempans %= 10;
                res[add+j] = tempans;
            }
            if(carry)
                res.push_back(carry);
        }
        bool flag = false;
        string resStr = "";
        for(int i = res.size()-1 ; i >= 0 ; i--)
        {
            if(res[i] != 0)
                flag = true;
            if(flag)
                resStr += res[i]+'0';
        }
        return resStr == "" ? "0" : resStr;
    }
};