class Solution {
public:

    // in this we will start by putting changing one char in a string then checking if its present
    // in bank or not. If its present we will increase the level the start changing other chars

    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> bankset(bank.begin(), bank.end());
        queue<string> q;
        q.push(startGene);
        unordered_set<string> visi;
        visi.insert(startGene);
        int level = 0;
        while (!q.empty()) {
            int n = q.size();
            while (n--) {
                string curr = q.front();
                q.pop();
                if (curr == endGene)
                    return level;
                for (char ch : "ACGT") {
                    for (int i = 0; i < curr.length(); i++) {
                        string neigh = curr;
                        neigh[i] = ch;
                        if (visi.find(neigh) == visi.end() &&
                            bankset.find(neigh) != bankset.end()) {
                            visi.insert(neigh);
                            q.push(neigh);
                        }
                    }
                }
            }
            level++;
        }
        return -1;
    }
};