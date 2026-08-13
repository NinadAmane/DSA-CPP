class Solution {
public: 
    struct Node{
        int pre=0;
        int suff=0;
        int maxlen=0;
        char leftchar;
        char rightchar;
    };

    vector<Node> segTree;

    void buildSegTree(int i, int l, int r, string& s){
        if(l == r){
            segTree[i] = {1,1,1,s[l], s[l]};
            return;
        }
        int mid = l + (r-l)/2;
        buildSegTree(2*i + 1, l, mid, s);
        buildSegTree(2*i + 2, mid + 1, r, s);
        segTree[i] = Merge(segTree[2*i+1], segTree[2*i + 2], mid - l + 1, r - mid);
    }

    Node Merge(Node L, Node R, int leftlen, int rightlen){
        Node result;
        result.leftchar = L.leftchar;
        result.rightchar = R.rightchar;

        result.pre = L.pre;
        if(L.pre == leftlen && L.rightchar == R.leftchar){
            result.pre = L.pre + R.pre;
        }

        result.suff = R.suff;
        if(R.suff == rightlen && L.rightchar == R.leftchar){
            result.suff = L.suff + R.suff;
        }
        result.maxlen = max(L.maxlen, R.maxlen);
        if(L.rightchar == R.leftchar){
            result.maxlen = max(result.maxlen, L.suff + R.pre);
        }

        return result;
    }


    void update(int i, int l, int r, int pos, char ch){
        if(l==r){
            segTree[i] = {1,1,1,ch,ch};
            return;
        }

        int mid = l + (r-l)/2;

        if(pos<=mid){
            update(2*i+1, l, mid, pos, ch);
        }
        else{
            update(2*i+2, mid + 1, r, pos , ch);
        }


        segTree[i] = Merge(segTree[2*i+1], segTree[2*i + 2], mid - l + 1, r - mid);
    }
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        int n = s.size();
        segTree.assign(4*n, Node());
        buildSegTree(0,0,n-1,s);

        int k = queryIndices.size();
        vector<int> result(k);
        for(int i=0;i<k;i++){
            int pos = queryIndices[i];
            char ch = queryCharacters[i];
            update(0,0,n-1,pos,ch);

            result[i] = segTree[0].maxlen;
        }

        return result;
    }
};