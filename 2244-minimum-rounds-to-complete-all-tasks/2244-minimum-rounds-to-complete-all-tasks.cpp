class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        int ans=0;
        unordered_map<int,int>mp1;
        
        for(auto it:tasks){
            mp1[it]++;
        }
        int count=0;
//         for(auto it:mp1){
            
            
            
//             if(it.second%3==0){
//                 int c=it.second/3;
//                 ans=ans+c;
//                 it.second=0;
//             }
//             else if(it.second%2==0 && it.second!=0){
//                 int c=it.second/2;
//                 ans=ans+c;
//                 it.second=0;
//             }
            
//             else{
//                 int x=it.second;
//                 while(x%3!=0 && x>0){
//                     x=x-2;
                    
//                     count++;
//                 }
//                 if(x%3==0 && x>=0){
//                     int c=x/3;
//                     ans=ans+c+count;
//                     count=0;
//                 }
//                 else return -1;
//             }

            
//        }
        
//         If the frequency of a number is only 1, then it is not possible to solve this question, so we return -1.
// If the frequency is directly divided by 3, then we return the frequency/3.
// If the remainder of dividing the number by 3 is 1 or 2 then, again there can be two cases:
// If remainder is 1, i.e, lets take 7 frequency, then o o o o o o o the groups are something like this "ooo" "ooo" "o", i.e, one o is left alone so the solution is to break the second last group into two parts of 2 and 1 so that it becomes like: "ooo" "oo" "oo", i.e, one is added to the division by 3.
// If remainder is 2, i.e, lets take 8 frequency, then o o o o o o o o the groups are something like this "ooo" "ooo" "oo", i.e, two o are left so the solution is to just add 1,i.e, one group of two to the solution.
        
        for(auto it:mp1){
            if(it.second==1) return -1;
            
            else if(it.second%3==0){
                int c=it.second/3;
                ans+=c;
            }
            else{
                int c=it.second;
                ans+=c/3+1;
            }
        }
        
        return ans;
    }
};