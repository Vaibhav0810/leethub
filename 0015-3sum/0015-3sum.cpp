class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        vector<vector<int>>ans;
        for(int i=0;i<arr.size();i++){
            if(i>0 && arr[i]==arr[i-1]) continue;
            int j = i+1;
            int k = arr.size()-1;
            
            while(j<k){
                int sum = arr[i]+arr[j]+arr[k];
                if(sum==0){
                    vector<int>check;
                    check.push_back(arr[i]);
                    check.push_back(arr[j]);
                    check.push_back(arr[k]);
                
                j++;
                k--;
                    ans.push_back(check);
                while(j<k && arr[j]==arr[j-1]) j++;
                while (j<k && arr[k]==arr[k+1]) k--;
                }
                
                else{
                    if(sum>0) k--;
                    else j++;
                }
            }
            
        }
        return ans;
        
    }
};