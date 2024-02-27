class Solution {
public:
    int trap(vector<int>& height) {
        auto left = 0;
        auto n = height.size();
        auto right = n-1;
        auto leftmax = height[0];       //used for storing of leftmax 
        auto rightmax = height[n-1];    //storing right max
        auto result = 0;
        while(left<right){
            if(leftmax<=rightmax){
                left++;
                leftmax = max(leftmax, height[left]);   // it will calculate the leftmax 
                result += (leftmax-height[left]); 
            }
            else{
                right--;
                rightmax = max(rightmax, height[right]); // it will calculate right max and storing it
                result += (rightmax-height[right]);
            }
        }
        return result;
    }
};