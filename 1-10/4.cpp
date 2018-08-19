static auto xxx=[]{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int merged[nums1.size()+nums2.size()];
        int k = 0;
        for(int i = 0, j = 0 ; i < nums1.size() || j < nums2.size() ; ){
            if(i < nums1.size() && j < nums2.size())
                if(nums1[i] < nums2[j])
                    merged[k++] = nums1[i++];
                else
                    merged[k++] = nums2[j++];
            else if(i < nums1.size())
                merged[k++] = nums1[i++];
            else if(j < nums2.size())
                merged[k++] = nums2[j++];
        }
        if(k&1)
            return merged[k>>1];
        else
            return (merged[k>>1] + merged[(k>>1) - 1]) / 2.;
    }
};