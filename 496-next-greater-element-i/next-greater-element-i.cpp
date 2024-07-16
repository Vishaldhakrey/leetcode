class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        

        vector<int>ans;
        int n = nums2.size();
        for(int i=0; i<nums1.size(); i++){
            int j=0;
            while(j<n){
                if(nums1[i] == nums2[j]){
                    int k = j;
                    int flag = 0;
                    while(k<n){
                        if(k+1<n && nums1[i]<nums2[k+1]){
                         ans.push_back(nums2[k+1]);
                         flag = 0;
                         break;
                        }
                        k++;
                        flag = 1;
                    }
                    if(flag == 1){
                        ans.push_back(-1);
                        break;
                    }
                  
                }
                j++;
            }
        }
        return ans;
    }
};