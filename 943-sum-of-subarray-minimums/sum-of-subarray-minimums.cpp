class Solution {
public:
    vector<int>getNSL(vector<int>&arr, int n){
        stack<int>st;
        vector<int>result(n);

        for(int i=0; i<n; i++){

            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(st.empty()){
                result[i] = -1;
            }
            else{
                result[i] = st.top();
            }

            st.push(i);
        }
        return result;
    }
    vector<int>getNSR(vector<int>&arr, int n){
         stack<int>st;
        vector<int>result(n);

        for(int i=n-1; i>=0; i--){

            while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop();
            }
            if(st.empty()){
                result[i] = n;
            }
            else{
                result[i] = st.top();
            }

            st.push(i);
        }
        return result;
    }
    int sumSubarrayMins(vector<int>& arr) {

        int n = arr.size();
        vector<int>NSL = getNSL(arr, n);
        vector<int>NSR = getNSR(arr, n);

        long long ans = 0;
        int Mod = 1e9+7;



        for(int i=0; i<n; i++){
            long long ls = i - NSL[i];
            long long rs = NSR[i] - i;

            long long totalWays = rs*ls;
            long long totalSum = arr[i]*totalWays;
            ans = (ans + totalSum)%Mod;
        }
        return ans;
    }
};