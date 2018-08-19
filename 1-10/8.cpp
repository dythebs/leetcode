static auto xxx=[]{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    int myAtoi(string str) {
        int start = -1, end = -1;
        bool flag = false;
        for(int i = 0 ; i < str.size() ; i++)
        {
            if(str[i] == '-' || str[i] == '+')
            {
                if(start == -1)
                {
                    start = i;
                    flag = true;
                }
                else
                {
                    end = i-1;
                    break;
                }
            }
            else
            {
                if(str[i] > '9' || str[i] < '0')
                {
                    if(str[i] == ' ' && start == -1)
                    {
                        continue;
                    }
                    else
                    {
                        if(start != -1)
                        {
                            end = i-1;
                        }
                        break;
                    }
                }
                else if(start == -1)
                {
                    start = i;
                }
            }
            
        }
        if(end == -1)
            end = str.size() - 1;
        if( (flag&&start==end) || start == -1)
            str = "0";
        else
            str = str.substr(start,end-start+1);
        try
        {
             return stoi(str);
        }
        catch(...)
        {
            if(str[0] != '-')
                return INT_MAX;
            else 
                return INT_MIN;
        }
    }
};