class Solution {
public:
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
        int left = m-1;
        int right =n-1;
        int p = n+m-1;

        while(left>=0 && right >= 0){
            if(nums1[left]>nums2[right]){
                nums1[p--] = nums1[left--];
            }
            else{
                nums1[p--] = nums2[right--];
            }
        }
        while(right>=0){
            nums1[p--] = nums2[right--];
        }
       
    }
};