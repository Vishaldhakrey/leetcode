class Solution {
  public:
    void findSubset(vector < int > & nums, int ind, vector < int > ds, vector < vector < int >> & res) {
      res.push_back(ds);
      for (int i = ind; i < nums.size(); i++) {
            if (i != ind && nums[i] == nums[i - 1]) continue;
            ds.push_back(nums[i]);
            findSubset(nums, i+1, ds, res);
            ds.pop_back();
         }
    }
  vector < vector < int >> subsetsWithDup(vector < int > & nums) {
    vector < vector < int >> res;
    vector < int > ds;
    sort(nums.begin(), nums.end());
    findSubset(nums, 0, ds, res);
    return res;
  }
};