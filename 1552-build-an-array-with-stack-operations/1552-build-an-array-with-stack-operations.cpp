class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string>ans;
        int curr=1;
        for(int i=0;i<target.size();){
            if(target[i]==curr){
                ans.push_back("Push");
                i++;
            }
            else{
                ans.push_back("Push");
                ans.push_back("Pop");
            }
            curr++;
        }

        return ans;
    }
};