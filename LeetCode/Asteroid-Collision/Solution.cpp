class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        for(int i=0;i<asteroids.size();i++){
            if(asteroids[i]>0){
                st.push(asteroids[i]);
            }
            else{
                while(!st.empty()&&st.top()<abs(asteroids[i])&&st.top()>0){
                    st.pop();
                }
                if(!st.empty()&&st.top()==abs(asteroids[i])){
                    st.pop();
                }
                else if(st.empty()||st.top()<0){
                    st.push(asteroids[i]);
                }
            }
        }
        int n = st.size();
        vector<int>res(n);
        for(int i=n-1;i>=0;i--){
            res[i]=st.top();
            st.pop();
        }
        return res;
    }
};