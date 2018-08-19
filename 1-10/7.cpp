static auto xxx=[]{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
    const static long int Max = 2147483647, Min = -2147483648;
public:
    int reverse(int x) {
        string s = to_string(x);
        std::reverse(s.begin() + (x < 0 ? 1 : 0),s.end());
        long int i = stol(s);
        return (i > Max || i < Min) ? 0 : i;
    }
};