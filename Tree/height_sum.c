#include<stdio.h>
#include<stdlib.h>
struct node 
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNode(int val)
{
    struct node  *newnode=malloc(sizeof(struct node));
    newnode->data=val;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}
struct node* insert(struct node* root, int val)
{
    if(root == NULL)
    {
        return createNode(val);
    }

    if(val < root->data)
    {
        root->left = insert(root->left, val);
    }

    else if(val > root->data)
    {
        root->right = insert(root->right, val);
    }

    return root;
}


void inorder(struct node *newnode)
{
    if(newnode==NULL)
    {
        return;
    }
    inorder(newnode->left);
    printf("%d ",newnode->data);
    inorder(newnode->right);
}

int height(struct node *newnode)
{
    if(newnode==NULL){
        return -1;
    }
    int leftHeight=height(newnode->left);
    int rightHeight=height(newnode->right);

    if (leftHeight>rightHeight)
    {
        return 1+leftHeight;
    }
    else
    {
        return 1+rightHeight;
    }
}

int depth(struct node *newnode,int val,int level)
{
    if(newnode==NULL)
    {
        return -1;
    }
    if(newnode->data==val)
    {
        return level;
    }
    if(val<newnode->data)
    {
        return depth(newnode->left,val,level+1);
    }
    else
    {
        return depth(newnode->right,val,level+1);
    }
}
    int sumOfNodes(struct node *newnode)
    {
        if(newnode==NULL)
        {
            return 0;
        }
        return newnode->data+sumOfNodes(newnode->left)+sumOfNodes(newnode->right);  
    }

int main()
{
    struct node* root = NULL;

    int ch, val;

    do
    {
        printf("\n--- MENU ---");
        printf("\n1. Insert");
        printf("\n2. Inorder");
        printf("\n3. Height of Tree");
        printf("\n4. Depth of Node");
        printf("\n5. Sum of Nodes");
        printf("\n6. Exit");

        printf("\nEnter choice: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:

                printf("Enter value: ");
                scanf("%d", &val);

                root = insert(root, val);

                printf("Node inserted\n");

                break;

            case 2:

                printf("Inorder Traversal: ");
                inorder(root);

                printf("\n");

                break;

                case 3:
                printf("height of treee: %d ",height(root));
                break;

                 case 4:

                printf("Enter node value: ");
                scanf("%d", &val);

                int d = depth(root, val, 0);

                if(d == -1)
                    printf("Node not found\n");
                else
                    printf("Depth of node = %d\n", d);

                break;

            case 5:

                printf("Sum of all nodes = %d\n", sumOfNodes(root));

                break;

            case 6:

                printf("Exiting...\n");

                break;

            default:

                printf("Invalid choice\n");
        }

    } while(ch != 6);

    return 0;
}
