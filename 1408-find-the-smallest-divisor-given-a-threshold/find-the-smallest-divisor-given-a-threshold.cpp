class Solution {
public:
    long long isPossible(vector<int>&nums, int threshold, int divisor) {
        int n = nums.size();

        long long division_sum = 0;

        for (int i=0; i<n; i++) {
            division_sum += (nums[i]/divisor);
            if ((nums[i]%divisor)) {
                division_sum++;
            }
        }

        return division_sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {

        long long maxDivisor = *max_element(nums.begin(), nums.end());
        long long left = 1, right = maxDivisor;
        int Divisor = -1;
        while (left <= right) {
            long long mid = left + (right-left)/2;

            int currDivisorSum = isPossible(nums, threshold, mid);

            if (currDivisorSum <= threshold) {
                Divisor = mid;
                right = mid-1;
            }
            else {
                left = mid+1;
            }
        }
        return Divisor;
    }
};