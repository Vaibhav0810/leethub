class Solution {
public:
    
    // agr ye upr vala function use ni krna to aise bhi likh skte h
    // push ke tym
    // pq.push(ceil((double)x/3));
    
    int ceill(int val){
        if(val%3==0) return val/3;
        else return val/3+1;
    }
    
    long long maxKelements(vector<int>& nums, int k) {
        
        priority_queue<int>pq(nums.begin(),nums.end());
        
        long long sum=0;
        while(k--){
            
            sum+=pq.top();
            int x=pq.top();
            pq.pop();
            pq.push(ceill(x));
            
        }
        return sum;      
    }
};