# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def widthOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        q = deque()
        q.append((root,0))
        maxlen = 0
        while q:
            size = len(q)
            first = q[0][1]
            last = q[-1][1]
            maxlen = max(maxlen, last - first  + 1) 
            for _ in range(size):
                node, index = q.popleft()
                if node.left:
                    q.append((node.left, index*2))
                if node.right:
                    q.append((node.right, index*2 + 1))
        
        return maxlen

