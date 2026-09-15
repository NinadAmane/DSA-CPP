class Solution:
    def removeElement(self, nums: list[int], val: int) -> int:
        count = 0
        n = len(nums)
        i = 0
        while i < len(nums):
            if nums[i] == val:
                count += 1
                nums.pop(i)
            else:
                i += 1
        return n - count
