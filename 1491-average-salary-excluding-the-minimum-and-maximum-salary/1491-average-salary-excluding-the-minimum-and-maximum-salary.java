class Solution {
    public double average(int[] salary) {
        
    
        if(salary.length<3) return 0;
        
        long mini=0,maxi=0,sum=0;
        Arrays.sort(salary);
        for(int i=1;i<salary.length-1;i++){
            
            
                sum+=salary[i];
            
            
        }
        double ans= (double)sum/(salary.length-2);
        
        return (double)sum/(salary.length-2);
        
    }
}