#include<cmath>
class Solution {
public:
    int minimumChairs(string s) {
        int max_chair = 0;
        int res = 0;

        for(char ch : s){
            if(ch == 'E'){
                res++;
            }
            else{
                max_chair = max(max_chair, res);
                res--;
            }
        }
        max_chair = max(max_chair, res);
        return max_chair;
    }
};