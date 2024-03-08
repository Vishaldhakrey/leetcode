class Solution {
public:
    void findSubset(int ind, vector<int>&ds, set<vector<int>>&s, vector<int>&arr){
        if(ind == arr.size()){
            s.insert(ds);
            return;
        }
        ds.push_back(arr[ind]);
        findSubset(ind+1, ds, s, arr);
        ds.pop_back();
        findSubset(ind+1, ds, s, arr);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        set<vector<int>>s;
        vector<int>ds;
        findSubset(0,ds,s,nums);
        vector<vector<int>>arr(s.begin(), s.end());
        return arr;
    }
};