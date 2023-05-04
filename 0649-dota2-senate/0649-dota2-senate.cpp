class Solution {
public:
    string predictPartyVictory(string senate) {
        
        queue<int>rq,dq;
        int n=senate.size();
        for(int i=0;i<n;i++){
            if(senate[i]=='R') rq.push(i);
            else dq.push(i);
        }
        // && and is same
        // || or is same
        while(rq.size()!=0 && dq.size()!=0){
            int fr=rq.front();
            int fd=dq.front();
            rq.pop();
            dq.pop();

            fr<fd ? rq.push(fr+n) : dq.push(fd+n);
            
            
            
        }
        
        if(rq.size()>dq.size()) return "Radiant";
        else return "Dire";
        
    }
};