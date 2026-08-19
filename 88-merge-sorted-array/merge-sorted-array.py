class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        totallen = m + n
        
        i = m
        j=0
        while i < totallen and j <= n - 1:
            nums1[i] = nums2[j]
            i+=1
            j+=1

        
        
        

        

        for l in range(totallen):
            for r in range(totallen):
                if nums1[l] < nums1[r]:
                    nums1[l], nums1[r] = nums1[r], nums1[l]

        print(nums1)