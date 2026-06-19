#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left, *right;
    int height;
};

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int height(struct node *root)
{
    if (root == NULL)
        return 0;
    return root->height;
}

struct node *createnode(int val)
{
    struct node *newnode = malloc(sizeof(struct node));

    newnode->data = val;
    newnode->left = NULL;
    newnode->right = NULL;
    newnode->height = 1;

    return newnode;
}

int getBalance(struct node *node)
{
    if (node == NULL)
        return 0;

    return height(node->left) - height(node->right);
}

struct node *rightRotate(struct node *y)
{
    struct node *x = y->left;
    struct node *t = x->right;

    x->right = y;
    y->left = t;

    y->height = 1 + max(height(y->left), height(y->right));
    x->height = 1 + max(height(x->left), height(x->right));

    return x;
}

struct node *leftRotate(struct node *x)
{
    struct node *y = x->right;
    struct node *t = y->left;

    y->left = x;
    x->right = t;

    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));

    return y;
}

struct node *insert(struct node *root, int val)
{
    if (root == NULL)
        return createnode(val);

    if (val < root->data)
        root->left = insert(root->left, val);

    else if (val > root->data)
        root->right = insert(root->right, val);

    else
        return root;

    root->height = 1 + max(height(root->left),
                           height(root->right));

    int balance = getBalance(root);

    // LL Case
    if (balance > 1 && val < root->left->data)
        return rightRotate(root);

    // RR Case
    if (balance < -1 && val > root->right->data)
        return leftRotate(root);

    // LR Case
    if (balance > 1 && val > root->left->data)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // RL Case
    if (balance < -1 && val < root->right->data)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void inorder(struct node *root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%d(BF=%d) ", root->data, getBalance(root));
    inorder(root->right);
}

int main()
{
    struct node *root = NULL;
    int val;

    printf("Enter values (-1 to stop):\n");

    while (1)
    {
        scanf("%d", &val);

        if (val == -1)
            break;

        root = insert(root, val);
    }

    printf("\nAVL Tree (Inorder):\n");
    inorder(root);

    return 0;
}