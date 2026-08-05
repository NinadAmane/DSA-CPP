// class Solution {
// public:
//     int candy(vector<int>& ratings) {
//         int n = ratings.size();
//         if(n==0) return 0;
//         vector<int> left(n,1);
//         vector<int> right(n,1);
//         for(int i =1;i<n;i++){
//             if(ratings[i] > ratings[i-1]){
//                 left[i] = left[i-1] + 1;
//             }
//         }

//         for(int i=n-2;i>=0;i--){
//             if(ratings[i] > ratings[i+1]){
//                 right[i] = right[i+1] + 1;
//             }
//         }

//         for(auto& x: left){
//             cout << x << " ";
//         }
//         cout << endl;
//         for(auto& x: right){
//             cout << x << " ";
//         }
//         int ans =0 ;
//         for(int i=0;i<n;i++){
//             ans += max(left[i], right[i]);
//         }
//         return ans;
//     }
// };

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        // if(n==0) return 0;
        int sum =1;
        int i = 1;
        int peak = 1;
        int down = 0;
        while(i<n){

            if(ratings[i] == ratings[i-1]){
                peak = 1;
                down = 0;
                sum += 1;
                i++;
                continue;
            }

            //upward slope
            peak = 1;
            while(i<n && ratings[i] > ratings[i-1]){
                peak+=1;
                sum += peak;
                down = 0;
                i++;
            }

            while(i<n && ratings[i] < ratings[i-1]){
                down+=1;
                sum += down;
                if(down >= peak){
                    sum ++;
                }
                i++;
            }


        }



        return sum;
    }
};