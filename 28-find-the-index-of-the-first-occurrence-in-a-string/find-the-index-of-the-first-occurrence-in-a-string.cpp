class Solution {
public:
    int strStr(string haystack, string needle) {
        int i=0; 
        int n = haystack.length();
        int m = needle.length();
        if(n<m)
            return -1;

        for(int i=0; i<n; i++){
            if(haystack.substr(i,m) == needle){
                return i;
            }
        }
        return -1;
    }
};