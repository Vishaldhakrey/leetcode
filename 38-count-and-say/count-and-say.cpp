class Solution {
public:
    string countAndSay(int n) {
        if(n==1) {
            return "1";
        }
        string say = countAndSay(n-1);

        string result = "";

        for(int i=0; i<say.size(); i++) {
            int count = 1;
            char ch = say[i];
            while(i<say.size()-1 && say[i] == say[i+1]) {
                count++;
                i++;
            }

            result+=to_string(count) + string(1, ch);
        }

        return result;
    }
};