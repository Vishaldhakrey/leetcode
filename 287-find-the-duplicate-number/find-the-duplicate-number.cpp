class Solution {
public:
    int findDuplicate(vector<int>& arr) {
        int n = arr.size();

        for (int i=0; i<n; i++) {
            while(arr[i] != i+1) {
                if (arr[arr[i]-1] == arr[i] ) {
                    return arr[i];
                }
                swap(arr[arr[i]-1], arr[i]);
            }
        }
        return -1;
    }
};