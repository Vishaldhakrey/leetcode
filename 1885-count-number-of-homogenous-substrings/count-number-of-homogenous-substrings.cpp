class Solution {
public:
    int mod = 1e9+7;
    int countHomogenous(string s) {
        int n = s.size();

        int result = 0;
        int i=0; 
        int j=0;
        while (j < n) {
            if (s[i] != s[j]) {
                i = j;
            }
            else {
                result = (result + (j-i+1))% mod;
                j++;
            }
        }
        return result;
    }
};