#include <stdio.h>
#include <stdlib.h>

typedef struct list
{
	int value;
	int key;
	struct list *left;
	struct list *right;
} list;

typedef list* tree;

int init(tree *root)
{
	*root = NULL;
	return 1;
}

int addnote(int key, int x, tree *root)
{
	tree temp = (*root);
	tree tmp = (tree)malloc(sizeof(list));
	tmp->key = key;
	tmp->value = x;
	tmp->left = NULL;
	tmp->right = NULL;

	if ((*root) == NULL)
	{
		(*root) = tmp;
		return 1;
	}
	while (1)
	{
		if (key > temp->key)
		{
			if (temp->right == NULL)
			{
				temp->right = tmp;
				return 1;
			}
			temp = temp->right;
		}
		else if (key < temp->key)
		{
			if (temp->left == NULL)
			{
				temp->left = tmp;
				return 1;
			}
			temp = temp->left;
		}
		else return 1;
	}
}
int obhod (list *tree) {
if (tree != NULL)
{
    if (tree-> value)  printf("%d ", tree -> value);

    obhod(tree -> left);
    obhod(tree -> right);}
return 0;
}
int main()
{
	tree head;
	init(&head);
	int i, x, key, n;

	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &key);
		scanf("%d", &x);
		addnote(key, x, &head);
	}
	
	
	tree temp = head;
	obhod(head);
	return 0;
}
