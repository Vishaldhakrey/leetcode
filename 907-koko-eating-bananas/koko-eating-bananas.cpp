class Solution {
public:
    long long countHours(int hour , vector<int>&piles, int n) {
        long long totalHours = 0;
        for (int i=0; i<n; i++) {
            totalHours += piles[i]/hour;
            if (piles[i]%hour != 0) {
                totalHours += 1;
            }
        }
        return totalHours;
    }
    int minEatingSpeed(vector<int>& piles, long long h) {
        
        int n = piles.size();
        long long left = 1;
        long long right = *max_element(piles.begin(), piles.end());
        int requiredHours = 0;

        while (left <= right) {
            long long mid = left + (right - left)/2;

            long long neededHour = countHours(mid, piles, n);

            if (neededHour <= h ) {
                requiredHours = mid;
                right = mid-1;
            }
            else {
                left = mid+1;
            }
        }
        return requiredHours;
    }
};