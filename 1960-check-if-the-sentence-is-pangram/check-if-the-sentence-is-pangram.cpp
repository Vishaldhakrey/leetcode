class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int>ans(26, 0);

        for(int i=0; i<sentence.size(); i++) {
            int pos = sentence[i] - 'a';

            ans[pos] = 1;
        }

        for(int i=0; i<26; i++) {
            if(ans[i] != 1) {
                return false;
            }
        }
        return true;
    }
};