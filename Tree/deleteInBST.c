#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int data;
    struct node *left;
    struct node *right;
};

void findKey(struct node *root, int key, struct node **keynode);
void getDeepest(struct node *root, struct node **deepestNode);
void deleteDeepest(struct node *root, struct node *deepest);

struct node *createNode(int val)
{
    struct node *newnode = malloc(sizeof(struct node));
    newnode->data = val;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

struct node* insert(struct node* root, int val)
{
    if(root == NULL)
        return createNode(val);

    if(val < root->data)
        root->left = insert(root->left, val);

    else if(val > root->data)
        root->right = insert(root->right, val);

    return root;
}

void findKey(struct node *root, int key, struct node **keynode)
{
    if(root == NULL)
        return;

    if(root->data == key)
    {
        *keynode = root;
        return;
    }

    findKey(root->left, key, keynode);
    findKey(root->right, key, keynode);
}

void getDeepest(struct node *root, struct node **deepestNode)
{
    if(root == NULL)
        return;

    if(root->left == NULL && root->right == NULL)
    {
        *deepestNode = root;
        return;
    }

    getDeepest(root->left, deepestNode);
    getDeepest(root->right, deepestNode);
}

void deleteDeepest(struct node *root, struct node *deepest)
{
    if(root == NULL)
        return;

    if(root->left == deepest)
    {
        free(root->left);
        root->left = NULL;
        return;
    }

    if(root->right == deepest)
    {
        free(root->right);
        root->right = NULL;
        return;
    }

    deleteDeepest(root->left, deepest);
    deleteDeepest(root->right, deepest);
}

struct node* deleteNode(struct node* root, int key)
{
    if(root == NULL)
        return NULL;

    struct node *keynode = NULL;
    struct node *deepest = NULL;

    findKey(root, key, &keynode);

    if(keynode == NULL)
        return root;

    getDeepest(root, &deepest);

    keynode->data = deepest->data;

    deleteDeepest(root, deepest);

    return root;
}

// Inorder traversal
void inorder(struct node *root)
{
    if(root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main()
{
    struct node *root = NULL;
    int val, ch;

    do
    {
        printf("\n1. Insert\n2. Delete\n3. Inorder\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                root = insert(root, val);
                break;

            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &val);
                root = deleteNode(root, val);
                break;

            case 3:
                inorder(root);
                printf("\n");
                break;
        }

    } while(ch != 4);

    return 0;
}