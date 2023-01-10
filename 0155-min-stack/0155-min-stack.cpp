class MinStack {
public:
    
        // Brute force O(N) Time
//     MinStack() {
        
//     }
//     stack<int> st;
//     stack<int> ans;
//     void push(int val) {
//         st.push(val);   
//     }
    
//     void pop() {
//         st.pop();
//     }
    
//     int top() {
//         return st.top();
//     }
    
//     int getMin() {
//         int min=INT_MAX;
//         while(!st.empty()){
//             if(st.top()<min){
//                 min=st.top();
//             }
//             ans.push(st.top());
//             st.pop();
//         }
//         while(!ans.empty()){
//             st.push(ans.top());
//             ans.pop();
//         }
//         return min;
//     }
    
    // using preffix array time O(1) bcoz popping from back in vector is O(1)
    // Space O(2N)
//     MinStack() {
        
//     }
//     vector<int>v;
//         stack<int>st;
//     void push(int val) {
//         st.push(val);
//         if(v.size()==0) v.push_back(val);
//         else{
//             int mini=v[v.size()-1];
//             if(val<mini){
//                 v.push_back(val);
//             }
//             else v.push_back(mini);
//         }
//     }
    
//     void pop() {
//         st.pop();
//         v.pop_back();
//     }
    
//     int top() {
//         return st.top();
//     }
    
//     int getMin() {
//         return v[v.size()-1];
//     }
    
    
    // Time -O(1)
    //     Space-O(N);
    // upr vale ki trh hi h bs ik vector of pair lelio 2 alg cheezo ki jgh
    
    MinStack() {
        
    }
    // val min
    vector<pair<int,int>>vp;
    void push(int val) {
        if(vp.size()==0) vp.push_back({val,val});
        else{
            vp.push_back({val,min(vp.back().second,val)});
        }
    }
    
    void pop() {
        vp.pop_back();
    }
    
    int top() {
        return vp.back().first;
    }
    
    int getMin() {
        return vp.back().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */