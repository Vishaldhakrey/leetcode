class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);

        string token = "";
        s = "";

        while (ss >> token) {
            reverse(token.begin(), token.end());
            s += token + " ";
        }        
        return s.substr(0, s.size()-1);
    }

};