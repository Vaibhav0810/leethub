class Solution {
public:
    // VVIMP Q
    void rotate(vector<vector<int>>& arr) {
        int n=arr.size();
        int a=0,b=n-1;
        
        while(a<b){
            for(int i=0;i<(b-a);i++){
                swap(arr[a][a+i],arr[a+i][b]);
                swap(arr[a][a+i],arr[b][b-i]);
                swap(arr[a][a+i],arr[b-i][a]);
            }
            a++;
            b--;
        }
        
    }
};