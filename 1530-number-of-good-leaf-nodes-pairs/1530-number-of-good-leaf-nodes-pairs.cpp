/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*, vector<TreeNode*>> adj;
    unordered_set<TreeNode*> st;

    void makeGraph(TreeNode* root, TreeNode* prev){
        if(!root) return ;

        if(root -> left == NULL && root -> right == NULL){
            st.insert(root);
        }

        if(prev != NULL){
            adj[root].push_back(prev);
            adj[prev].push_back(root);
        }

        makeGraph(root -> left, root);
        makeGraph(root -> right, root);
    }

    int countPairs(TreeNode* root, int distance) {

        makeGraph(root, NULL);
        int count = 0;

        for(auto & leaf : st){
            queue<TreeNode*> q;
            unordered_set<TreeNode*> visited;

            q.push(leaf);
            visited.insert(leaf);
            int level = 0;

            while(level <= distance){
                int n = q.size();

                while(n--){
                    TreeNode* temp = q.front();
                    q.pop();

                    if(temp -> left == NULL && temp  -> right == NULL && temp != leaf){
                        count++;
                    }

                    for(auto & nbr : adj[temp]){
                        if(!visited.count(nbr)){
                            q.push(nbr);
                            visited.insert(nbr);
                        }
                    }
                }
                level++;
            }
        }

        return count/2;
    }
};