class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int n = s.size();
        int m = spaces.size();

        string result = "";
        int j=0, i=0;
        while (i < n && j<m) {
            if (i == spaces[j]) {
                result += " ";
                j++;
            }
            result += s[i];
            i++;
        }

        return result += s.substr(i);
    }
};