class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    node_path = {}

    def helper(self, root: TreeNode, path: List):
        if root.left is None and root.right is None:
            self.node_path[root] = path
            return
        path.append(root)
        if root.left:
            self.helper(root.left, path)
        if root.right:
            self.helper(root.right, path)

    def countPairs(self, root: TreeNode, distance: int) -> int:
        self.helper(root, [])
        ret = 0
        nodes = list(self.node_path.keys())
        for i in range(len(nodes)-1):
            nip = self.node_path[nodes[i]]
            for j in range(i+1, len(nodes)):
                njp = self.node_path[nodes[j]]
                for d in range(min(len(nip), len(njp))):
                    if nip[d] != njp[d]:
                        break
                if len(nip) + len(njp) - 2 * d + 2 <= distance:
                    ret += 1
        return ret
