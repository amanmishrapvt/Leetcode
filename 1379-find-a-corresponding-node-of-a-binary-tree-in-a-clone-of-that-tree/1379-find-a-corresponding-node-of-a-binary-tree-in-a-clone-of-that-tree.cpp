class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        // Base case: agar original null hai, matlab yahan kuch nahi hai
        if (original == NULL) return NULL;

        // Agar current original node hi target hai, toh cloned ka current node return kar do
        if (original == target) return cloned;

        // Left subtree mein dhundo
        TreeNode* leftResult = getTargetCopy(original->left, cloned->left, target);
        if (leftResult != NULL) return leftResult;

        // Right subtree mein dhundo
        TreeNode* rightResult = getTargetCopy(original->right, cloned->right, target);
        return rightResult;
    }
};