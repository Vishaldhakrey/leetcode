class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();

        int left = 0;
        int right = n-1;
        int minEle = INT_MAX;
        int indx = -1;
        while (left < right) {
            int mid = left + (right -left) / 2;
            
            //CHECKING SORTED PART
            if (nums[mid] < nums[right]) {
                if (minEle > nums[mid]) {
                    indx = mid;
                    minEle = nums[mid];
                }
                right = mid;
            }
            //UNOSERTED PART
            else if (nums[mid] > nums[right]) {
                if (minEle > nums[left]) {
                    indx = mid;
                    minEle = nums[left];
                }
                left = mid+1;               
            }
            else {
                right--;
            }
        }
        cout<<indx;
        return min(minEle, nums[left]);
    }
};