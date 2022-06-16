class UnionFind {
public: 
    UnionFind(int sz) {
        count = sz;
        rank = vector<int> (sz);
        root = vector<int> (sz);
        for(int i=0;i<sz;i++) {
            root[i]=i;
            rank[i]=1;
        }
    }
    
    int find(int x) {
        while(x!=root[x]) {
            x=root[x];
        }
        return x;
    }
    
    bool isConnect(int x,int y) {
        return find(x) == find(y);
    }
    
    void union_(int x,int y) {
        int rootX = find(x);
        int rootY = find(y);
        if(rootX != rootY) {
            if(rank[rootX] > rank[rootY]) {
                root[rootY] = rootX;
            } else if(rank[rootX] < rank[rootY]) {
                root[rootX] = rootY;
            } else {
                rank[rootX]+=1;
                root[rootY] = rootX;
            }
            count--;
        }
    }
    
    int getCount() {
        return count;
    }
    
private:
    vector<int> rank;
    vector<int> root;
    int count;    
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        if(isConnected.size() == 0) {
            return 0;
        } 
        int n=isConnected.size();
        UnionFind uf(n);
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(isConnected[i][j]) {
                    uf.union_(i,j);
                }
            }
        }
        return uf.getCount();
    }
};