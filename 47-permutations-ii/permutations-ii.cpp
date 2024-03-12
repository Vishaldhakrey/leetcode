#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    void findPermute(int ind, vector<int>& nums, set<vector<int>>& s) {
        if (nums.size() == ind) {
            s.insert(nums);
            return;
        }

        for (int i = ind; i < nums.size(); i++) {
            if (i != ind && nums[i] == nums[ind]) {
                continue;
            }
            swap(nums[ind], nums[i]);
            findPermute(ind + 1, nums, s);
            swap(nums[ind], nums[i]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        set<vector<int>> s;

        sort(nums.begin(), nums.end());
        findPermute(0, nums, s);

        for (auto itr = s.begin(); itr != s.end(); itr++) {
            ans.push_back(*itr);
        }
        return ans;
    }
};
