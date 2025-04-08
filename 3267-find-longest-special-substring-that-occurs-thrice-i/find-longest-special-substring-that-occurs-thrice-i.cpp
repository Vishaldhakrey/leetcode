class Solution {
public:
//TimeComplexity of this is O(n3)
    int maximumLength(string s) {
        int n = s.size();

        map<pair<char, int>, int>mp;

        for (int i=0; i<n; i++) { //O(n)
            int len = 0;
            for (int j=i; j<n; j++) { //O(n)
                if (s[j] == s[i]) {
                    len += 1;
                    mp[{s[j], len}]++; //To copy string O(n)
                }
                else {
                    break;
                }
            }
        }
        int result = 0;
        for (auto &it : mp) {
            int str_size = it.first.second;
            int cnt = it.second;
            if (cnt >= 3 && str_size > result) {
                result = str_size;
            }
        }

        return result != 0 ? result : -1;
    }
};