class Solution {
    public int areaOfMaxDiagonal(int[][] dimensions) {
        int maxi=0;
        double d=0;
        double maxiD=0;
        int maxiArea=0;

        for(int i=0;i<dimensions.length;i++){
            d=Math.sqrt(dimensions[i][0]*dimensions[i][0] + dimensions[i][1]*dimensions[i][1]);
            if(d>maxiD){
                maxiD=d;
                maxi=i;
                maxiArea=dimensions[i][0]*dimensions[i][1];
            }
            else if(d==maxiD){
                maxiArea=Math.max(maxiArea, dimensions[i][0]*dimensions[i][1]);
            }
        }
        return maxiArea;
    }
}