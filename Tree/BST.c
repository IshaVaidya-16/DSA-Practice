#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left, *right;
};

struct node *createNode(int val)
{
    struct node *newnode = malloc(sizeof(struct node));
    newnode->data = val;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

struct node *insert(struct node *newnode, int val)
{
    if (newnode == NULL)
    {
        return createNode(val);
    }
    if (val < newnode->data)
    {
        newnode->left = insert(newnode->left, val);
    }
    if (val > newnode->data)
    {
        newnode->right = insert(newnode->right, val);
    }
    return newnode;
}

struct node *search(struct node *newnode, int val)
{
    if (newnode == NULL || newnode->data == val)
    {
        return newnode;
    }
    if (val < newnode->data)
    {
        return search(newnode->left, val);
    }
    if (val > newnode->data)
    {
        return search(newnode->right, val);
    }
    return newnode;
}
void inorder(struct node *newnode)
{
    if (newnode == NULL)
    {
        return;
    }
    inorder(newnode->left);
    printf("%d ", newnode->data);
    inorder(newnode->right);
}

int main()
{
    struct node *newnode = NULL;
    int ch, val;
    do
    {
        printf("\n1)insert\n2)search\n3)inorder\n4)exit\n");
        printf("enter choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("enter val:");
            scanf("%d", &val);
            newnode = insert(newnode, val);
            printf("value inserted");
            break;

        case 2:
            printf("enter val to search:");
            scanf("%d", &val);

            if (search(newnode, val) != NULL)
            {

                printf("value found ");
            }
            else
            {
                printf("value not found");
            }
            break;

        case 3:
            printf("Inorder Traversal: ");
            inorder(newnode);
            printf("\n");
            break;

        case 4:

        default:
            printf("Invalid choice.\n");
            break;
        }
    } while (ch != 4);
    return 0;
}
