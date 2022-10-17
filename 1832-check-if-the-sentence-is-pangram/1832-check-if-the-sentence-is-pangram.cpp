class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int>arr(26);
        for(auto it:sentence){
            arr[it-'a']++;
        }
        for(auto it:arr){
            if(it==0) return false;
        }
        return true;
    }
    //using map
    // unordered_map<char>mp(sentence.begin(),sentence.end());
    // return st.size()==26
    // iska mtlb h phle set mei sb store kr do aur agr ab setka size 26 se km h rto false ni to tru
};