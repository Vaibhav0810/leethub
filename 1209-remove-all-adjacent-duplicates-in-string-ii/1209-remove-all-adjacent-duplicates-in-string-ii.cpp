class Solution {
public:
    
        string removeDuplicates(string& s, int k) {
	vector<pair<char, short> > stk {{'#', 0}}; // vector required to rebuild ans at end - will function same as stack elsewhere
	for(const auto c : s){
		if(stk.back().first == c) ++stk.back().second;
		else stk.push_back({c, 1});
		// if consecutive count equals k, then delete from stack, so we won't include it while rebuilding string at end
		if(stk.back().second == k) stk.pop_back();
	}
	s.clear();
	for(const auto& [character, count] : stk) s.append(count, character);
	return s;
}
    
};