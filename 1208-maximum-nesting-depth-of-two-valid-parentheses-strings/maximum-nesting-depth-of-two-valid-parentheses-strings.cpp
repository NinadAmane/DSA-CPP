class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        
        int depthA = 0;
        int depthB = 0;
        int n = seq.size();
        vector<int> ans(n);
        int depth = 0;
        for(int i=0;i<n;i++){
            if(seq[i] == '('){
                depth++;
                if(depthA  <= depthB){
                    ans[i] = 0;
                    depthA++;
                }
                else{
                    ans[i] = 1;
                    depthB++;
                }
            }
            else{
                if(depth%2==0){
                    ans[i] = 1;
                    depthB--;
                }
                else{
                    ans[i] = 0;
                    depthA--;
                }
                depth--;
                
            }
        }
        return ans;
    }
};