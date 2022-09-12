class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        
        sort(tokens.begin(),tokens.end());
        int score=0;
        int i=0;
        int n=tokens.size();
        int j=n-1;
        int maxi=0;
        while(i<=j){
            if(power>=tokens[i]){
                power=power-tokens[i];
                score++;
                i++;
                maxi=max(maxi,score);
                
            }
            else{
                if(score>0){
                power=power+tokens[j];
                score--;
                j--;
                }
                else{
                    i++;
                }
            }
        }
        return maxi;
    }
};