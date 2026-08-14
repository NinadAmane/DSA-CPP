# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    
    def longestZigZag(self, root: Optional[TreeNode]) -> int:
        maxi = 0
        def dfs(root, count, lastmove):
            nonlocal maxi
            if not root:
                return 
            maxi = max(maxi , count)
            if(lastmove):
                if root.left:
                    dfs(root.left, 1, True)
                if(root.right):
                    dfs(root.right, count + 1, not lastmove)
            else:
                if root.left:
                    dfs(root.left, count + 1, not lastmove)
                if(root.right):
                    dfs(root.right, 1, False)

        if(root.left):
            dfs(root.left, 1, True)

        if(root.right):
            dfs(root.right, 1, False)

        return maxi
        