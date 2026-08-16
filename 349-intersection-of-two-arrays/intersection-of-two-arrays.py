class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        st1 = set(nums1)
        st2 = set(nums2)
        ans = []
        for x in st1:
            if(x in st2):
                ans.append(x)
        return ans
        
