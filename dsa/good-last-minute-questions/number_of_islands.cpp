// number of islands in a tree with zeros and ones.
// time complexity - o(n);
// space complexity - o(log n) - stack space.
int numberOfIslands(Node* root ,bool isParentOne){
	if(root == NULL) return 0;
	
	int islands = 0;
	if(root->val == 1 && isParentOne == false){
		islands = 1;
	}

	islands += numberOfIslands(root->left, root->val);
	islands += numberOfIslands(root->right, root->val);

	return islands;
}


       0
	/  \               answer for this tree = 2;
	1   0 
     /\   /\
    1  0 0  1
