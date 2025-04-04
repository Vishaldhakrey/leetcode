class Solution {
public:
    vector<string> getToken(string &version) {
        stringstream ss (version);

        string token = "";
        vector<string>tokens;

        while (getline(ss, token, '.')) {
            tokens.push_back(token);
        }

        return tokens;
    }
    int compareVersion(string version1, string version2) {
        vector<string>stringToken1 = getToken(version1);
        vector<string>stringToken2 = getToken(version2);
        
        int m = stringToken1.size();
        int n = stringToken2.size();
        int i=0;
        while ( i < m || i < n) {
            int a = (i < m) ? stoi(stringToken1[i]) : 0;
            int b = (i < n) ? stoi(stringToken2[i]) : 0;

            if (a > b) return 1;
            else if (b > a) return -1;
            else i++;
        }
        return 0;
    }
};