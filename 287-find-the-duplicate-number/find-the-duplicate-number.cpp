class Solution {
public:
    int findDuplicate(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int>freq_map;
        for (auto &num : arr) {
            freq_map[num]++;
            if (freq_map[num] > 1) {
                return num;
            }
        }

        return -1;
    }
};