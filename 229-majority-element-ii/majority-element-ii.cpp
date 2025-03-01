class Solution {
public:
    vector<int> majorityElement(vector<int>& arr) {
        int n = arr.size();

        vector<int>result;
        for (int i=0; i<n; i++) {
            int count = 0;
            for (int j=0; j<n; j++) {
                if (arr[i] == arr[j]) {
                    count++;
                }
            }
            if (count > n/3) {
                if (!result.empty() && arr[i] == result.back()) {
                    continue;
                }
                result.push_back(arr[i]);
                if (result.size() > 1) {
                    return result;
                }
            }
        }
        return result;
    }
};