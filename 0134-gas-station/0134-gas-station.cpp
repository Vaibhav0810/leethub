class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int j =0;
        for(int i=0;i<n;i++){
            int tank = 0;
            int stop = 0,j=i;
            while(stop<n){
                tank+=gas[j%n]-cost[j%n];
                if(tank<0) break;
                stop++;
                j++;
            }
            if(tank>=0 && stop==n) return i;
            else i=j;
        }
        return -1;
    }
};