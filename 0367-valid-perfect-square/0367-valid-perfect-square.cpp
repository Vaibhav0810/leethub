class Solution {
public:
    
    void search(int start,int end,bool &ans,int num){
        if(start<=end){
        long long mid = (start+end)/2;
        if(mid*mid == num){
            ans=true;
            return;
        }
        else if(mid*mid > num){
            search(start,mid-1,ans,num);
        }
        else{
            search(mid+1,end,ans,num);
        }
        }
        else{
            ans= false;
        }
    }
    
    bool isPerfectSquare(int num) {
        bool ans=false;
        if(num==1) return true;
        search(1,(num/2),ans,num);
        
        return ans;
    }
};