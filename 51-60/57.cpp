/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
static auto xxx=[]{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
    bool static cmp(const Interval& a, const Interval& b) {
        return a.start < b.start;
    }
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end(), cmp);
        vector<Interval> ans;
        int start = intervals[0].start, end = intervals[0].end;
        for(int i = 1 ; i < intervals.size() ; i++)
        {
            end = max(end, intervals[i-1].end);
            if(intervals[i].start <= end)
                continue;
            ans.push_back(Interval(start, end));
            start = intervals[i].start;
        }
        end = max(end, intervals[intervals.size()-1].end);
        ans.push_back(Interval(start, end));
        return ans;
    }
};