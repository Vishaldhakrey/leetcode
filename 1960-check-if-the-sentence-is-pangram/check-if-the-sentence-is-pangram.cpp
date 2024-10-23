class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int>ans(26, 0);
        int count = 0;
        for(int i=0; i<sentence.size(); i++) {
            int pos = sentence[i] - 'a';

            if(ans[pos] == 0) {
                ans[pos]++;
                count++;
            }
        }

        return count==26 ? true : false;
    }
};