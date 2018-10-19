// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7
static auto xxx=[]{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    int rand10() {
        int t = 0;
        while((t = rand7()+(rand7()-1)*7)>40);
        return t%10 + 1;
    }
};