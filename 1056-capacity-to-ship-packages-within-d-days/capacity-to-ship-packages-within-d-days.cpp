class Solution {
private :
    bool isPossible(vector<int>&weights, int days, int weight) {
        int n = weights.size();
        int sum = 0;
        int requiredDays = 0;
        for (int i=0; i<n; i++) {
            if (weights[i] <= weight) {
                sum += weights[i];
                if (sum > weight) {
                    requiredDays++;
                    sum = weights[i];
                }
            }
            else {
                return false;
            }
        }
        if (sum <= weight) {
            requiredDays++;
        }
        return (requiredDays <= days);
    }

public:
    int shipWithinDays(vector<int>& weights, int days) {
        int totalWeight = accumulate(weights.begin(), weights.end(), 0);

        int leftWeight = 1, rightWeight = totalWeight;
        int minCapacityOfShip = -1;

        while (leftWeight <= rightWeight) {
            int mid = leftWeight + (rightWeight - leftWeight)/2;
            bool ans = isPossible(weights, days, mid);
            if (ans) {
                minCapacityOfShip = mid;
                rightWeight = mid-1;
            }
            else {
                leftWeight = mid+1;
            }
        }
        return minCapacityOfShip;
         
        return -1;
    }
};