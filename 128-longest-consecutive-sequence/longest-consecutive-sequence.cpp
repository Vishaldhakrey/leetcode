class Solution {
public:

    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();

        if(n==0) return 0;
        
        unordered_set<int>us;
        int longestSeq = 1;
    
        for(int i=0; i<n; i++){
            us.insert(nums[i]);
        }

        for(auto &itr : us){
            if(us.find(itr-1) == us.end()){
                int cnt = 1;
                int it = itr;
                while(us.find(it+1) != us.end()){
                    it = it+1;
                    cnt++;
                }
                longestSeq = max(longestSeq, cnt);
            }
        }
        return longestSeq;
    }
};