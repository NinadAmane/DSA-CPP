class Solution {
public:
    bool checkDivisibility(int n) {
        int x = n;
        int nn =n;
        int sum = 0;
        while(x){
            sum += x%10;
            x = x/10;
        }
        int prod = 1;
        while(nn){
            prod *= nn%10;
            nn = nn/10;
        }

        long long prodsum = prod + sum;
        

        return n % prodsum == 0;
    }
};