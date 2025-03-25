class Solution {
private:
    bool canShipWithCapacity(vector<int>& weights, int days, int capacity) {
        int currentWeight = 0, requiredDays = 1;

        for (int weight : weights) {
            if (weight > capacity) return false; // A single package exceeds capacity

            if (currentWeight + weight > capacity) {
                requiredDays++;
                currentWeight = 0;
            }
            currentWeight += weight;
        }

        return requiredDays <= days;
    }

public:
    int shipWithinDays(vector<int>& weights, int days) {
        int left = *max_element(weights.begin(), weights.end()); 
        int right = accumulate(weights.begin(), weights.end(), 0);
        int minCapacity = right;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canShipWithCapacity(weights, days, mid)) {
                minCapacity = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return minCapacity;
    }
};
