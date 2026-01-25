class RandomizedSet {
public:
    unordered_map<int, int> mp;
    vector<int> v;
    RandomizedSet() {}

    bool insert(int val) {
        if (mp.find(val) == mp.end()) {
            // mp.insert(val);
            v.push_back(val);
            mp[val] = v.size() - 1;
            return true;
        }
        return false;
    }

    bool remove(int val) {
        if (mp.find(val) == mp.end()) {
            return false;
        }
        int idx = mp[val];      // index of val
        int lastVal = v.back(); // last element

        // Move last element to idx
        v[idx] = lastVal;
        mp[lastVal] = idx;

        // Remove last element
        v.pop_back();
        mp.erase(val);
        return true;
    }

    int getRandom() {
        // return *mp.begin();
        return v[rand() % v.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */