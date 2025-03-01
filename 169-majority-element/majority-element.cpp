class Solution {
public:
    int majorityElement(vector<int>& arr) {
        int n = arr.size();
        
        int ele = -1;
        int count = 0;
        for (int i=0; i<n; i++) {
            if (count == 0) {
                count = 1;
                ele = arr[i];
            }
            else if (arr[i] == ele) {
                count++;
            }
            else {
                count--;
            }
        }
        
        return ele;
    }
};