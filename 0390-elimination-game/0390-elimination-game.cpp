class Solution {
public:
    int lastRemaining(int n) {
        bool direction = true;// going left to right
        int step=1,head=1;
        while(n>1){
            if(direction){
                head+=step;
            }
            else{
                head+=n%2==0?0:step;
            }
            step*=2;
            n=n/2;
            direction = !direction;
        }
        return head;
    }
};