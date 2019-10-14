#include "BtsNode.h"

int main()
{
	BstNode* root = NULL;
	string s;
	string p;
	int i, j = -1;

	cout << "Please enter a string of text: ";

	getline(cin, s);

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == ' ')
		{
			p = s.substr(j + 1, i - j - 1);
			j = i;
			root = Insert(root, p);
		}
	}

	p = s.substr(j + 1, i - j);

	root = Insert(root, p);

	cout << "Post Order Traversal is: " << endl;
	PostOrder(root);
	cout << endl << "Pre Order Traversal is: " << endl;
	PreOrder(root);
	cout << endl << "In Order Traversal is: " << endl;
	InOrder(root);
	cout << endl << "Height of tree is: " << FindHeight(root);
	cout << endl << "No. of leaf nodes in tree is: " << getLeafCount(root) << endl;
	system("pause");
	return 0;
}