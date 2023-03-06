class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int i=0,j=0;
        
        while(k>=0){
            if(i<arr.size() && arr[i]==j+1){
                i++;
                j++;
            }
            else if(i==arr.size() && k!=0){
                k--;
                j++;
            }
            else{
                k--;
                j++;
            }
            if(k==0){
                return j;
            }
        }
        return 0;
    }
};