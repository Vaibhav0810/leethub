class Solution {
public:
    // isme hashset mei number store krte chl rhe h aur jb number match ho jayega mtlb loop ho gya h to uss pr false return kr denge aur nhi to sb pura ho gya to true return
    
// bool isHappy(int n) {
//         unordered_set<int>s;
//         int sum=0;
//     while(sum!=1){
//         sum=0;
//         while(n>0){
//             int x=n%10;
//             sum=sum+(x*x);
//             n=n/10;
//         }
//         if(s.find(sum)!=s.end()) return false;
//         else s.insert(sum);
//         n=sum;
//     }
//     return true;
// }
    
    // using floyd tortoise and hair algo
    // in this fast pointer double dpeed se chl rha h to agr vo chlte chlte slow pr aajta h to mtlb h ki loop h 
    
    int next(int n){
        int sum=0;
        while(n>0){
            int x=n%10;
            sum=sum+(x*x);
            n=n/10;
        }
        return sum;
    }
    
    bool isHappy(int n){
        int slow=next(n);
        int fast=next(next(n));
        
        while(slow!=fast){
            slow=next(slow);
            fast=next(next(fast));
            
        }
        return fast==1;
        
    }
    
};