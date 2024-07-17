class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
       

       stack<int>st;

       for(int a : asteroids){
            while(!st.empty() && a<0 && st.top()>0){
                int sum = a+st.top();

                if(sum<0){
                    st.pop();
                }
                else if(sum>0){
                    a=0;

                }
                else{
                    st.pop();
                    a = 0;
                }
            }

            if(a!=0){
                st.push(a);
            }
       }

        
       int n = st.size();
       vector<int>res(n);
       int i = n-1;
       while(i>=0){
        res[i] = st.top();
        st.pop();
        i--;
       }

       return res;
    }
};