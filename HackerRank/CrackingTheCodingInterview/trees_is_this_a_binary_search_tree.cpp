/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.  

The Node struct is defined as follows:
   struct Node {
      int data;
      Node* left;
      Node* right;
   }
*/

#include <vector>

vector<Node*> collect_nodes(Node *curr_node, vector<Node*> nodes) {
    if (curr_node->left != NULL)
        nodes = collect_nodes(curr_node->left, nodes);
    nodes.push_back(curr_node);
    if (curr_node->right != NULL)
        nodes = collect_nodes(curr_node->right, nodes);
    return nodes;
}

bool checkBST(Node* root) {
    vector <Node*> nodes;
    nodes = collect_nodes(root, nodes);
    int val1, val2;
    for (vector <Node*>::iterator it = nodes.begin(); it != nodes.end(); ++it) {
        if (it+1 == nodes.end())
            break;
        val1 = (*it)->data;
        val2 = (*(it+1))->data;
        if (val1 >= val2)
            return false;
    }
    return true;    
}
