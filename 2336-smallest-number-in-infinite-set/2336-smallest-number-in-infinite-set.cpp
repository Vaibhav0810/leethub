class SmallestInfiniteSet {
public:
    
    // with pq and set
//      priority_queue<int,vector<int>,greater<int>>pq;
//     set<int>st;
    
//     SmallestInfiniteSet() {
//         for(int i=1;i<=1000;i++) {
//             pq.push(i); 
//             st.insert(i);
//         }
//     }
    
//     int popSmallest() {
//         int x=pq.top();
//         pq.pop();
//         st.erase(x);
//         return x;
//     }
    
//     void addBack(int num) {
//         if(st.find(num)==st.end()){
//             pq.push(num);
//             st.insert(num);
//         }
//         else{
            
//         }
         
//     }
    
    // with only set
    
    int cur = 1;
    set<int> added; 
    
    SmallestInfiniteSet(){
        
    }
    
    int popSmallest() {
        if (!added.empty()) {
            int res = *begin(added);
            added.erase(begin(added));
            return res;
        }
        return cur++;
    }
    void addBack(int num) {
        if (num < cur)
            added.insert(num);
    }
    
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */