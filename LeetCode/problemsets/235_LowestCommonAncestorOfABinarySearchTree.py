class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        if root == None or root == p or root == q:
            return root
        
        if root.val > p.val and root.val > q.val:
            left = self.lowestCommonAncestor(root.left, p, q)
            right = None
        elif root.val < p.val and root.val < q.val:
            right = self.lowestCommonAncestor(root.right, p, q)
            left = None
        else:
            return root        

        return left or right
