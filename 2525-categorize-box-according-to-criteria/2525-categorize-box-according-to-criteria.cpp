class Solution {
public:
    string categorizeBox(int length, int width, int height, int mass) {
        
        long long product = (long long)length* (long long)width* (long long)height;
        
        if(length >=10000 || width>=10000 || height >= 10000 || product>=1e9){
            if(mass>=100) return "Both";
            else return "Bulky";
        }
        
        
    else if(mass>=100) return "Heavy";
    else return "Neither";
    }
};


