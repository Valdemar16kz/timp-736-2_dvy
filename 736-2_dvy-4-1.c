#include <stdio.h>
#include <stdlib.h>

typedef struct node 
{
	int value;
	struct node *prev;
} node;

typedef node* stack;

int init(stack *root)
{
	*root = NULL;
	return 1;
}

int push(stack *stk, int value)
{
	stack tmp = (stack)malloc(sizeof(node));
	tmp->prev = (*stk);
	tmp->value = value;
	(*stk) = tmp;
	return 1;	
}

int pop(stack *stk)
{
	if (*stk != NULL)
	{		
		stack tmp = *stk;
		(*stk) =(*stk) -> prev;
		int a = tmp -> value;
		free(tmp);
		return a;
	}	
}

int isEmpty(stack stk)
{
	if (stk) return 0;
	else return 1;
}

int print(stack stk) 
{
	stack tmp = stk;
	while (tmp != NULL) 
	{
		printf("%d ", tmp->value);
		tmp = tmp->prev;
	}
	printf("\n");
	return 1;
}
int destroy(stack *top) {
   
    stack x,y;
    x=*top;
    y=*top;
   
    while (x!=NULL)
    {
        y=x->prev;
        free(x);
        x=y;
    }
    free(*top);
    return 1;
                }

int main() 
{
	stack  head;
        init(&head);
        int i, x, n;
        scanf("%d", &n);
       /* if (n > 0) {
                scanf("%d", &x);
                push(&head, x);
        }*/
        stack temp = head;
        for (i = 0; i < n; i++) {
                scanf("%d", &x);
               push(&head, x);
        }
        print(head);
	printf("%d\n", pop(&head));
        print(head);
        destroy(&head);
        return 0;
}
