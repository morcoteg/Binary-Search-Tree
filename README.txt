BINARY SEARCH TREE implementation:

1. Insert: Inserts an item into the tree. No need to balance the tree. In fact,
dont balance your tree because this would generate inconsistent result.
This should be O(h) where h is height of the tree.
2. InorderTraverse: Traverses the tree in order. In addition, there is another
parameter: vector. The vector is expected to have all elements in the tree
by the same order as visited by each recursion. This should be O(n).
3. DeleteNode: Deletes an element of the tree. This should be O(h).
4. Filter: Deletes all nodes that do not have the desired property keeping
only ones with the property. This should be O(n). Provide an memory
ecient implementation, i.e., O(1) space.
5. ForEachInerval: perform some function to each node of the tree in range
of interval [a; b] where a; b are parameters of the method. Provide an
memory ecient implementation, i.e., O(1) space.
6. VerifyBinraySearchTree: returns true if the tree has properties of binary
search tree, e.g., value of left child node is less than that of its parent.
Return false otherwise. This should be O(n). Provide an memory ecient
implementation, i.e., O(1) space.