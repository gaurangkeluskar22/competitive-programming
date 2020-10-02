# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxDepth(self, root: TreeNode) -> int:
        if not root:
            return 0

        answer = 1
        def min_height(node, height):
            nonlocal answer
            if node.left:
                min_height(node.left, height+1)
            if node.right:
                min_height(node.right, height+1)
            if not node.left and not node.right:
                answer = max(answer, height)

        min_height(root, 1)
        return answer