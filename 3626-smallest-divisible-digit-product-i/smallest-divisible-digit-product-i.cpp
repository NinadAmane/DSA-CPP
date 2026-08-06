class Solution {
public:
    int smallestNumber(int n, int t) {
        
        while(1){
            int temp = n;
            int prod = 1;

            while(temp){
                prod = prod * (temp%10);
                temp = temp/10;
            }

            if(prod%t == 0) return n;

            n++;
        }

        return n;
        
    }
};