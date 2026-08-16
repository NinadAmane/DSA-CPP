class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        mp = {}
 
        for i in strs:
            key = ''.join(sorted(i))
            if key not in mp:
                mp[key] = []
            if ''.join(sorted(i)) == key:
                mp[key].append(i)
        
        return list(mp.values())