class MinStack {
public:
    
    // Brute force 
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
    
    
    // Time -O(1)
    //     Space-O(N);
    
     MinStack() {
       
         
         
    }
    vector<pair<int,int>>v;
   
    void push(int val) {
       
        if(v.empty())
            v.push_back({val,val});
        else{
            v.push_back({val,min(v.back().second,val)});
        }
        
    }
    
    void pop() {
       v.pop_back();
    }
    
    int top() {
        return v.back().first;
    }
    
    int getMin() {
        return v.back().second;
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