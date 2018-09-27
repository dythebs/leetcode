static auto xxx=[]{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    bool isValid(string s) {
        stack<char> Stack;
        for(auto c : s)
        {
            if(c == '(' || c == '{' || c == '[')
                Stack.push(c);
            else
            {
                if(Stack.empty())
                    return false;
                if(c == ')' && Stack.top() == '(' || c == '}' && Stack.top() == '{' || c == ']' && Stack.top() == '[' )
                    Stack.pop();
                else
                    return false;
            }
        }
        return Stack.empty();
    }
};