class Solution {
public:
    vector<string> shortestSubstrings(vector<string>& arr) {

        unordered_map<string, int>mp;

        for (auto &str : arr) {
            unordered_set<string>st;
            for (int i=0; i<str.size(); i++) {
                for (int j=i+1; j<=str.size(); j++) {
                    string subString = str.substr(i, j-i);

                    if (st.find(subString) == st.end()) {
                        st.insert(subString);
                        mp[subString]++;
                    }
                }
            }
        }

        vector<string>result;

        for (auto &str : arr) {
            int n = str.size();
            string shortest = "";
            for (int i=0; i<n; i++) {
                for (int j=i+1; j<=n; j++ ) {
                    
                    string subString = str.substr(i, j-i);

                    if (mp[subString] == 1 && 
                        ((shortest == "" || shortest.length() > subString.length())
                        || (shortest.size() == subString.size() && shortest > subString)) ) {
                            shortest = subString;
                        }
                }
            }
            result.push_back(shortest);
        }

        return result;
    }
};