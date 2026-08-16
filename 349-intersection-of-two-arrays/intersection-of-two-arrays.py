class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        st1 = set(nums1)
        st2 = set(nums2)
        ans = []
        for x in st1:
            for y in st2:
                if(x == y):
                    ans.append(x)
        return ans
        
