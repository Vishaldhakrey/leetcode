class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();

        int left = 0;
        int right = n-1;
        int minEle = INT_MAX;

        while (left <= right) {
            int mid = left + (right -left) / 2;
            
            //CHECKING SORTED PART
            if (nums[mid] < nums[right]) {
                minEle = min(nums[mid], minEle);
                right = mid-1;
            }
            //UNOSERTED PART
            else {
                minEle = min(nums[left], minEle);
                left = mid+1;               
            }
        }
        return minEle;
    }
};