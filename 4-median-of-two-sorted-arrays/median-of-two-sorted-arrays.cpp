//better approach
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        auto n = nums1.size();
        auto m = nums2.size();

        if(n == 0 && m == 0) return 0;

               
        vector<int>temp;

        auto left = 0;
        auto right = 0;
        

        while(left<n && right<m){
            if(nums1[left] <= nums2[right]){
                temp.push_back(nums1[left]);
                left++;
            }
            else{
                temp.push_back(nums2[right]);
                right++;
                
            }
        }

        while(left<n){
            temp.push_back(nums1[left]);
            left++;
        }
        while(right<m){
            temp.push_back(nums2[right]);
            right++;
        }
        int size = temp.size();

        if(size%2 == 0){
            int ind1 = size/2;
            int ind2 = size/2-1;
            return (temp[ind1]+temp[ind2])/2.0;
        }
        return temp[size/2];
    }

};