class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();

        vector<int>missingsNum;

        for (int i=0; i<n; i++) {
            if (arr[i] <= k) {
                k++;
                }
            else {
                break;
            }
        }
        return k;
    }
};