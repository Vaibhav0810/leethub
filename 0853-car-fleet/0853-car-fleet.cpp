class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        
        if(position.size()==0 || position.size()==1) return position.size();
        
        // isme phle ik vector pair bnayenge jiss se sort krne mei dikkt na aaye bdd mei bcoz agr posotion sort kr denge to speed rhh jayegi
        // to pair bnane ke bdd decresing order mei sort krenge ye r.begin isilie used h
        // uske bdd ik stack mei push krenge
        // agr starting mei stack empty h to daaldo jo bhi time h
        // ni to jo time uske andr present h uss se bda time hi daalna h
        // bcoz jo uss se km time lega ya equal lega vo 1 fleet mei hi aajayega
        
        // aisa krke  eg1 mei 10,8 1 fleet mei ho jaayenge
        // 5 3 dusri mei 
        // 1 teesri mei
        
        // ye kaise socha
        
        // basically isme de rkha h jo car aage h agr uss se peeche vali car jyada speed pr rhegi to bhi overtake ni krpayegi uske peeche hi rhegi
        // to hmne jo car sbse aage h usse sort krke sbse aage rkh dia
        // ab uske peeche check kr rhe h agr peeche vali car target tk same time mei phch rhi h to 1 fleet ni to diff fleet
        
        //time comp - O(N logN)  // space -O(2N);
        
        vector<pair<int,int>>car(position.size());
        for(int i=0;i<speed.size();i++){
            car[i]={position[i],speed[i]};
        }
        
        sort(car.rbegin(),car.rend());
        stack<double>st;
        for(auto it:car){
            
            double dist=target-it.first;
            double time=dist/it.second;
            
            if(st.empty()|| time>st.top()){
                st.push(time);
            }
        }
        return st.size();
        
        
    }
};