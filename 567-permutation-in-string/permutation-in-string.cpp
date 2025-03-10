class Solution {
public:
    
    bool checkInclusion(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();

        sort(s1.begin(), s1.end());

        for(int i=0; i<=n-m; i++) {
            string str = s2.substr(i, m);
            sort(str.begin(), str.end());
            if (s1 == str) {
                return true;
            }
        }
        return false;
    }
};