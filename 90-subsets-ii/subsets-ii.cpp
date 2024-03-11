class Solution {
public:
    void fun(vector < int > & nums, int index, vector < int > ds, set < vector < int >> & res) {
      if (index == nums.size()) {
        sort(ds.begin(), ds.end());
        res.insert(ds);
        return;
      }
      ds.push_back(nums[index]);
      fun(nums, index + 1, ds, res);
      ds.pop_back();
      fun(nums, index + 1, ds, res);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> arr;
        set<vector<int>>ans;
        vector<int>ds;
        fun(nums,0, ds, ans);
        for(auto itr = ans.begin(); itr!=ans.end(); ++itr){
            arr.push_back(*itr);
        }
        return arr;

    }
};