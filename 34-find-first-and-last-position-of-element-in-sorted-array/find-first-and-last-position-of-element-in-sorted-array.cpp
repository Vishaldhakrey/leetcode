class Solution {
public:

    int firstOccurances(vector<int>&nums, int n, int target){

        int first = -1;
        int left = 0;
        int right = n-1;

        while(left<=right){

            int mid = (left+right)/2;

            if(nums[mid] == target){
                right = mid-1;
                first = mid;
            }
            else if(target < nums[mid]){
                right = mid-1;
            }
            else{
                left = mid+1;
            }
        }
        return first;
    }

     int lastOccurances(vector<int>&nums, int n, int target){

        int last = -1;
        int left = 0;
        int right = n-1;

        while(left<=right){

            int mid = (left+right)/2;

            if(nums[mid] == target){
                left = mid+1;
                last = mid;
            }
            else if(target < nums[mid]){
                right = mid-1;
            }
            else{
                left = mid+1;
            }
        }
        return last;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        
     int first = firstOccurances(nums, nums.size(), target);
     if(first == -1){
        return {-1, -1};
     }
     int second = lastOccurances(nums, nums.size(), target);

     return {first, second};   
     
    }
};