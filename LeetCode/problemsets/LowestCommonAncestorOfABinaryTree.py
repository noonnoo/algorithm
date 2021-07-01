class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        
        def dfs(cur, parent, depth):
            if cur is None: return
            parents[cur] = parent
            depths[cur] = depth            
            dfs(cur.left, cur, depth + 1)
            dfs(cur.right, cur, depth + 1)        
        
        depths = dict()
        parents = dict()
        
        dfs(root, None, 0)
        
        if depths[p] > depths[q]:
            while(depths[p] != depths[q]):
                p = parents[p]
        elif depths[q] > depths[p]:
            while(depths[p] != depths[q]):
                q = parents[q]
                
        while(q != p):
            q = parents[q]
            p = parents[p]
        
        return p
