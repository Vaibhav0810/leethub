class Solution {
public:
    // Time - O(N*26) Space - O(N)
    //     string smallestEquivalentString(string s1, string s2, string baseStr)
    //     { vector<int> arr(26, -1);

    //     for (int i = 0; i < s1.size(); i++) {
    //         int store1 = s1[i] - 'a';
    //         int store2 = s2[i] - 'a';

    //         // if not set yet, their group is themselves
    //         if (arr[store1] == -1) arr[store1] = store1;
    //         if (arr[store2] == -1) arr[store2] = store2;

    //         int old1 = arr[store1];
    //         int old2 = arr[store2];
    //         int mini = min(old1, old2);

    //         // Update all members that were in old1 or old2 to mini
    //         for (int j = 0; j < 26; j++) {
    //             if (arr[j] == old1 || arr[j] == old2) {
    //                 arr[j] = mini;
    //             }
    //         }
    //     }

    //     // Build the answer
    //     string ans = "";
    //     for (char c : baseStr) {
    //         int idx = c - 'a';
    //         if (arr[idx] == -1) ans.push_back(c); // not in any mapping
    //         else ans.push_back(arr[idx] + 'a');
    //     }
    //     return ans;
    // }

    // Union Find
    // Rank vala union find ni lenge bcoz it can also give 'z' a greater rank than 'a'
    // so then it will chose 'z' as parent
    // so we will get wrong ans
    // so instead we will choose smallest as parent
    vector<int> parent;
    // vector<int> rank;
    int find(int x) {
        if (x == parent[x])
            return x;
        return parent[x] = find(parent[x]);
    }

    void Union(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px == py)
            return;
        if (px < py)
            parent[py] = px;
        else
            parent[px] = py;
    }

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        parent.resize(26);
        int n = s1.size();
        // rank.resize(26, 0);
        for (int i = 0; i < 26; i++) {
            parent[i] = i;
        }

        for (int i = 0; i < n; i++) {
            if (s1[i] != s2[i]) {
                Union(s1[i] - 'a', s2[i] - 'a');
            }
        }
        for (int i = 0; i < baseStr.size(); i++) {
            baseStr[i] = find(baseStr[i] - 'a') + 'a';
        }
        return baseStr;
    }
};