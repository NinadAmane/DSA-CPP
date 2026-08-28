class Solution {
public:
    struct comp{
        unordered_map<int,int>& freq;

        comp(unordered_map<int,int>& f) : freq(f){}

        bool operator()(int a, int b) const {
            if(freq[a] != freq[b])
                return freq[a] < freq[b];
            return a > b;
        }
    };
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int,int> mp;
        int n = nums.size();

        for(int i=0;i<n;i++){
            if(nums[i]%2==0)
                mp[nums[i]]++;
        }
        if(mp.empty()) return -1;
        comp c(mp);
        priority_queue<int , vector<int>, comp> pq(c);

        for(auto& [num, freq] : mp){
            pq.push(num);
        }
        cout << pq.top() << endl;

        // auto [freq, number] = pq.top();

        return pq.top();


    }
};