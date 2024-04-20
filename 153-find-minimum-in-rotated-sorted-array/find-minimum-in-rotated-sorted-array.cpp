class Solution {
public:
    int findMin(vector<int>& nums) {
        int minEle = INT_MAX;;

        int l=0; 
        int r=nums.size()-1;

        while(l<=r){
            int mid = (l+r)/2;

            if(nums[l] <= nums[mid]){
                minEle = min(minEle, nums[l]);
                l=mid+1;
            }
            else{
                minEle = min(minEle, nums[mid]);
                r = mid-1;
            }
        }
        return minEle;
    }
};