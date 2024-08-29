class Solution {
public:
    int parent[20002];
    int find_parent(int u){
        if(parent[u] < 0) return u;
        return parent[u] = find_parent(parent[u]);
    }

    void do_union(int x, int y){
        int px = find_parent(x);
        int py = find_parent(y);
        if(px == py) return;
        if(parent[px] > parent[py]) swap(px, py);
        parent[px] += parent[py];
        parent[py] = px;
    }

    int removeStones(vector<vector<int>>& stones) {
        memset(parent, -1, sizeof parent);    

        for(vector<int> &v: stones)
            do_union(v[0], v[1] + 10001);        

        unordered_set<int> st;
        for(auto v: stones){
            int pv = find_parent(v[0]);
            if(st.count(pv) == 0)
                st.insert(pv);
        }

        return stones.size() - st.size();
    }
};