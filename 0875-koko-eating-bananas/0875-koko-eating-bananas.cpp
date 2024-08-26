class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1, right = *max_element(piles.begin(), piles.end());
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            int hours = 0;
            
            for (int pile : piles) {
                hours += (pile + mid - 1) / mid; // Equivalent to ceil(pile / mid)
            }
            
            if (hours <= h) {
                right = mid; // Try a smaller speed
            } else {
                left = mid + 1; // Need a larger speed
            }
        }
        
        return left; // The minimum speed to eat all bananas within h hours
    }
};
