class Solution {
public:
    
    
    int countPalindromicSubsequence(string s) {
        int n = s.size();

        vector<pair<int,int>> indices(26, {-1, -1});

        for (int i=0; i<n; i++) {
            int idx = s[i] - 'a';

            if (indices[idx].first == -1) {
                indices[idx].first = i;
            }
            indices[idx].second = i;
        }

        int result = 0;

        for (int i=0; i<26; i++) {

            int first_idx = indices[i].first;
            int last_idx = indices[i].second;

            unordered_set<char>middle_chars;
            for (int middle = first_idx+1; middle <= last_idx-1; middle++) {
                middle_chars.insert(s[middle]);
            }

            result += middle_chars.size();
 
        }

        return result;
    }
};