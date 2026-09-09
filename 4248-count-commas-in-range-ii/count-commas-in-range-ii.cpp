class Solution {
public:
    long long countCommas(long long n) {
        if(n<=999){
            return 0;
        }
    
        long long res = 0;
        if(n > 999 && n < pow(10,6)){
            return n-999;
        }

        if(n > 999999 && n < pow(10,9)){
            res = 2*(n-999999);
            res += 999999 - 999;
            return res;
        }

        if(n > 999999999 && n < pow(10,12)){
            res = 3 * (n - 999999999);
            res += 2 * (999999999 - 999999);
            res += 999999 - 999;
            return res;
        }
        if(n==pow(10,15)){
            res+=5;
            n-=1;
        }

        if(n > 999999999999 && n < pow(10,15)){
            res += 4 * (n-999999999999);
            res += 3 * (999999999999 - 999999999);
            res += 2 * (999999999 - 999999);
            res += 999999 - 999;
            return res;
        }



        return n-999;
    }
};