class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int i=0;
        int index = 0;
        while(i<n){
            char curr = chars[i];
            int count = 0;
            while(i<n && curr == chars[i]){
                count++;
                i++;
            }
            
            chars[index] = curr;
            index++;

            if(count > 1){
                for(char &ch: to_string(count)){
                    chars[index] = ch;
                    index++;
                }
            }
           
            
        }

        return index;
    }
};