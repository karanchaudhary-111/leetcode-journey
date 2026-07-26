/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool solve(ListNode* head, TreeNode* root){
        if(!head) return true;
        if(!root) return false;

        if(root -> val != head -> val){
            return false;
        }

        return solve(head -> next, root -> left) || solve(head -> next, root -> right);

    }

    bool isSubPath(ListNode* head, TreeNode* root) {
        
        if(!root) return false;

        if(solve(head, root)) return true;

        return isSubPath(head, root -> left) || isSubPath(head, root -> right);
    }
};