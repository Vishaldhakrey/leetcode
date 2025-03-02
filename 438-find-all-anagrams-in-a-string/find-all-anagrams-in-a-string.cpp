class Solution {
public:
    bool isZero(vector<int>& counter) {
        for (int i=0; i<26; i++){
            if (counter[i] != 0) {
                return false;
            }
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        int n = s.size();
        int m = p.size();
        
        if (n < m) return {};
        vector<int>result;
        vector<int>counter(26, 0);

        for (int i=0; i<m; i++) {
            counter[p[i] - 'a']++;
        }

        int i=0, j=0; 
        while (j < n) {
            counter[s[j] - 'a']--;

            if (j-i+1 == m) {
                if(isZero(counter)) {
                    result.push_back(i);
                }
                counter[s[i]-'a']++;
                i++;
            }
            j++;
        }
        return result;
    }
};