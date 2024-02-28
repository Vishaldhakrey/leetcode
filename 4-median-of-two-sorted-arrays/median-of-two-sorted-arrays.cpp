//better approach
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    auto n = nums1.size();
    auto m = nums2.size();
    auto l = 0;
    auto r = 0;
    auto t = (n+m);
    auto med1 = t/2;
    auto med2 = t/2-1;
    auto count = 0;
    auto indel1 = -1;
    auto indel2 = -1;
    while (l < n && r < m) {
        if (nums1[l] <= nums2[r]) {
            if(count == med1) indel1 = nums1[l];
            if(count == med2) indel2 = nums1[l];
            l++;
            count++;
        } else {
            if(count == med1) indel1 = nums2[r];
            if(count == med2) indel2 = nums2[r];
            r++;
            count++;
        }
    }
    while (l < n) {
        if(count == med1) indel1 = nums1[l];
        if(count == med2) indel2 = nums1[l];
        l++;
        count++;
    }
    while (r < m) {
        if(count == med1) indel1 = nums2[r];
        if(count == med2) indel2 = nums2[r];
        r++;
        count++;
    }
    if (t % 2 == 1) {
        return indel1;
    }
    return (double)(indel1+indel2) / 2.0;
    }

};