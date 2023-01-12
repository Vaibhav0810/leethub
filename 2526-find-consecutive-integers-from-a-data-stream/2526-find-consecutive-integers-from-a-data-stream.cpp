class DataStream {
public:
    int val,n=0,m;
    DataStream(int value, int k) {
        val=value;
        m=k;
        
    }
    
    bool consec(int num) {
        if(num==val) n++;
        else n=0;
        
        if(n>=m) return true;
        return false;
        
    }
    
    
    
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */