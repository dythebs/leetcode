static auto xxx=[]{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    bool isNumber(string s) {
        int nume = 0, indexe = -1;
        int numd = 0, indexd = -1;
        int start = -1 , end = s.size();
        while(s[++start] == ' ');
        while(s[--end] == ' ');
        for(int i = start ; i <= end ; i++)
            if(s[i] != 'e' && s[i] != '.' && s[i] != '-' && s[i] != '+' &&(s[i] < '0' || s[i] > '9'))
                return false;
            else if(s[i] == 'e')
                nume++, indexe = i;
            else if(s[i] == '.')
                numd++, indexd = i;
            else if(s[i] == '-' || s[i] == '+')
            {
                if(i == end)
                    return false;
                if(i != start && s[i-1] != 'e')
                    return false;
            }
        
        if(indexd != -1 && indexe != -1 && indexd > indexe)
            return false;
        if(numd > 1) return false;
        if(nume > 1) return false;
        
        if(indexe == start || indexe == end)
            return false;
        
        if(nume == 1){
            try{
                stod(s.substr(start, indexe-start+1));
                stod(s.substr(indexe+1, end-indexe+1));
                return true;
            } catch(...) {
                return false;
            }
        }
        
        try{
            stod(s);
            return true;
        } catch(...) {
            return false;
        }
    }
};