class Solution {
public:
    bool isEqual(vector<int>& p_freq, vector<int>& s_freq) {
        return p_freq == s_freq;
    }
    vector<int> findAnagrams(string s, string p) {
        int n = s.size();
        int m = p.size();
        
        if (n < m) return {};
        vector<int>result;
        vector<int>p_freq(26, 0), s_freq(26, 0);

        for (int i=0; i<m; i++) {
            p_freq[p[i] - 'a']++;
            s_freq[s[i] - 'a']++;
        }
        if (isEqual(p_freq, s_freq)) {
            result.push_back(0);
        }

        int i=0, j=m; 
        while (j < n) {
            s_freq[s[j++] - 'a']++;
            s_freq[s[i++] - 'a']--;

            if (isEqual(p_freq, s_freq)) {
                result.push_back(i);
            }
        }
        return result;
    }
};