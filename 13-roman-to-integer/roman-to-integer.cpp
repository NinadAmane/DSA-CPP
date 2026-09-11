class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> mp;
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;

        int result = 0;
        int i=0;
        while(i!=s.size()){
            int a = mp[s[i]];
            int b = mp[s[i+1]];
            if(b>a){
                result += (b-a);
                i+=2;
            }
            else{
                result += a;
                i++;
            }
        }
        // for(int i=0;i<s.size();i++){
        //     int a = mp[s[i]];
        //     int b = mp[s[i+1]];
        //     if(b>a){
        //         result += (b-a);
        //     }
        //     else{
        //         result+= a;
        //     }
        // }
        return result;
    }
};