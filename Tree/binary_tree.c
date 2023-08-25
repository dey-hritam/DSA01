#include <stdio.h>
#include <stdlib.h>

struct Node *create_tree();
void inorder(struct Node *);
void preorder(struct Node *);
void postorder(struct Node *);
int height_tree(struct Node *);
int size_node(struct Node *);
int maximum_node(struct Node *);
int minimum_node(struct Node *);
void print_level(struct Node *, int);
int count_leaf(struct Node *);

struct Node
{
    struct Node *left;
    struct Node *right;
    int data;
};

int main(void)
{
    char ch;
    int height, size, max, min, i, count;
    struct Node *root = NULL;
    while (1)
    {
        printf("\n 1.Create a Tree \n 2.In Order \n 3.Pre Order \n 4.Post Order \n 5.Height of the Tree \n 6.Number of nodes \n 7.Greatest Node \n 8. Lowest Node \n 9.Level order \n 10.Number of leaf \n 11.Exit");
        printf("\nEnter the choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            root = create_tree();
            break;
        case 2:
            printf("In order is:\n");
            inorder(root);
            break;
        case 3:
            printf("\npre order is:\n");
            preorder(root);
            break;
        case 4:
            printf("\npost order is:\n");
            postorder(root);
            break;
        case 5:
            height = height_tree(root);
            printf("\nheight of the tree is: %d\n", height);
            break;
        case 6:
            size = size_node(root);
            printf("there are %d number of nodes in the tree\n", size);
            break;
        case 7:
            max = maximum_node(root);
            printf("The node which has the maximum value is:%d", max);
            break;
        case 8:
            min = minimum_node(root);
            printf("\nThe node which has the maximum value is:%d", min);
            break;
        case 9:
            printf("Level order is:");
            for (i = 0; i < height; i++)
            {
                print_level(root, i);
            }
            break;
        case 10:
            count = count_leaf(root);
            printf("\nNumber of leaf is: %d", count);
            break;
        case 11:
            exit(1);
        }
    }
}

struct Node *create_tree()
{
    int val;
    struct Node *newnode;
    newnode = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter the data:");
    scanf("%d", &val);
    if (val == -1)
    {
        return 0;
    }
    newnode->data = val;
    printf("Enter the left node for %d:\n", val);
    newnode->left = create_tree();
    printf("Enter the right node for %d:\n", val);
    newnode->right = create_tree();
    return newnode;
}

void inorder(struct Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    printf("%d  ", root->data);
    inorder(root->right);
}

void preorder(struct Node *root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d  ", root->data);
    inorder(root->left);
    inorder(root->right);
}

void postorder(struct Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    inorder(root->right);
    printf("%d  ", root->data);
}

int height_tree(struct Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int left_height = height_tree(root->left);
    int right_height = height_tree(root->right);
    if (left_height >= right_height)
        return left_height + 1;
    else
        return right_height + 1;
}

int size_node(struct Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return (size_node(root->left) + size_node(root->right) + 1);
}

int maximum_node(struct Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int left_node = maximum_node(root->left);
    int right_node = maximum_node(root->right);
    int data = root->data;
    if (left_node > right_node)
    {
        if (left_node > data)
        {
            return left_node;
        }
        else
        {
            return data;
        }
    }
    else
    {
        if (right_node > data)
        {
            return right_node;
        }
        else
        {
            return data;
        }
    }
}

int minimum_node(struct Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int left_node = minimum_node(root->left);
    int right_node = minimum_node(root->right);
    int data = root->data;
    if (left_node < right_node)
    {
        if (left_node < data)
        {
            return left_node;
        }
        else
        {
            return data;
        }
    }
    else
    {
        if (right_node < data)
        {
            return right_node;
        }
        else
        {
            return data;
        }
    }
}

void print_level(struct Node *root, int level)
{
    if (root == NULL)
    {
        return;
    }
    if (level == 1)
    {
        printf(" %d  ", root->data);
    }
    else if (level > 1)
    {
        print_level(root->left, level - 1);
        print_level(root->right, level - 1);
    }
}

int count_leaf(struct Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root->left == NULL && root->right == NULL)
    {
        return 1;
    }
    return (count_leaf(root->left) + count_leaf(root->right));
}

