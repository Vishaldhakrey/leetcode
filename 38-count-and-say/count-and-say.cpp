class Solution {
public:
    string countAndSay(int n) {
        
        if (n == 1) {
            return "1";
        }
        string res = countAndSay(n-1);

        string temp = "";
        int i=0, len = res.size();
        while(i < len) {
            char ch = res[i];
            int j = i;
            while (j < len && (ch == res[j])) ++j;

            int count = j - i;
            temp += to_string(count);
            temp += ch;
            i = j;
        }
        return temp;
    }
};