//Bruteforce Method
//timecomplexity 
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    auto n = nums1.size();
    auto m = nums2.size();
    auto l = 0;
    auto r = 0;
    vector<int> arr;
    while (l < n && r < m) {
        if (nums1[l] <= nums2[r]) {
            arr.push_back(nums1[l]);
            l++;
        } else {
            arr.push_back(nums2[r]);
            r++;
        }
    }
    while (l < n) {
        arr.push_back(nums1[l]);
        l++;
    }
    while (r < m) {
        arr.push_back(nums2[r]);
        r++;
    }
    auto t = arr.size();
    if (t % 2 == 1) {
        return arr[t / 2];
    }
    return (double)(arr[t / 2] + arr[t / 2 - 1]) / 2.0;
    }

};