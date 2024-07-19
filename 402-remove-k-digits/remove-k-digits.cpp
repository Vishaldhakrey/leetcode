class Solution {
public:
    string removeKdigits(string num, int k) {
        string result = ""; //work as a monotonic stack

        for(int i=0; i<num.length(); i++){
            while(result.length() > 0 &&  result.back()>num[i] && k>0){
                result.pop_back();
                k--;
            }


            if(result.length()>0 || num[i] != '0'){
                result.push_back(num[i]);

            }
        }

        while(k>0 && result.length() > 0){
            result.pop_back();
            k--;
        }

        if(result.empty()){
            return "0";
        }
        return result;
    }
};