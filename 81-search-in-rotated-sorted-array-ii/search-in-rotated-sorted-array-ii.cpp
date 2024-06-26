class Solution {
public:
    bool search(vector<int>& nums, int target) {
       int l=0; 
        int r = nums.size()-1;
        
        while(l<=r){
           
           int mid = (l+r)/2;

           if(nums[mid] == target){
                return true;
           }

           if(nums[l] == nums[mid] && nums[mid] == nums[r]){
                l = l+1;
                r = r-1;
                continue;
           }

           else if(nums[l] <= nums[mid]){
                if(nums[l] <= target && target <= nums[mid]){
                    r = mid-1;
                }
                else{
                    l = mid+1;
                }
           }
           
           else{
                if(target >= nums[mid] &&  target <= nums[r])
                {
                    l = mid+1;
                }
                else{
                    r = mid -1;
                }
           }
        }
        return false; 
    }
};