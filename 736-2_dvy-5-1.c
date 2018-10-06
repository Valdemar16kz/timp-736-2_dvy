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

int main()
{
	tree head;
	init(&head);
	int i, x, key, n, count, bol = 1, a;

	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &key);
		scanf("%d", &x);
		addnote(key, x, &head);
	}

	tree temp = head;
	for (i = 0; i < 3; i++)
	{		
		scanf("%d", &a);
		count = 0;
		bol = 1;
		while (bol != 0)
		{
			if (temp != NULL)
			{
				if (temp->key == a)
				{
					printf("%d ", count);
					printf("%d ", temp->value);
					bol = 0;
				}
				else
				{
					if (temp->key > a) temp = temp->left;
					if (temp->key < a) temp = temp->right;
					count++;
				}
			}
			else
			{
				printf("%d ", -1);
				bol = 0;
			}
		}		
		printf("\n");
	}	
	return 0;
}
