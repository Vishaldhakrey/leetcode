class Solution {
public:
    void KMP(string &b, vector<int>&prefix, int n) {
        int len = 0;
        int i = 1;
        prefix[0] = 0;
        while (i < n) {
            if (b[i] == b[len]) {
                len++;
                prefix[i] = len;
                i++;
            }
            else if (len != 0) {
                len = prefix[len-1];
            }
            else {
                prefix[i] = 0;
                i++;
            } 
        }
    }
    bool KMPContain(string str, string pat, vector<int>prefix) {
        int m = str.size();
        int n = pat.size();

        int i=0, j=0;
        while (i < m) {
            if (str[i] == pat[j]) {
                j++;
                i++;
                if (j == n) {
                    return true;
                }
            }
            else if(j > 0) {
                j = prefix[j-1];
            }
            else {
                i++;
            }
        }
        return false;
    }
    int repeatedStringMatch(string a, string b) {
        int m = a.size();
        int n = b.size();

        int repeat = (n+m - 1)/m;
        string s;
        s.reserve((repeat + 1) * m);
        for(int i=0; i<repeat; i++) {
            s +=a;
        }
        vector<int>prefix(n, 0);
        KMP(b, prefix, n);
       if (KMPContain(s, b, prefix)) {
        return repeat;
       }
       s += a;
       if (KMPContain(s, b, prefix)) {
        return repeat+1;
       }
       return -1;
    }
};