class Solution {
public:
    int compress(vector<char>& chars) {
        
        int index = 0;
        int i=0;
        
        while(i<chars.size()) {
            char ch = chars[i];
            int count = 0;
            while(i < chars.size() && ch == chars[i]) {
                count++;
                i++;
            }

            chars[index] = ch;
            index++;

            if(count>1) {
                string countStr = to_string(count);

                for(auto cha : countStr) {
                    chars[index] = cha;
                    index++;
                }
            }
        }
        return index;
    }
};