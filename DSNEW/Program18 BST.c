#include <stdio.h>
#include <stdlib.h>
struct tnode
{
    int data;
    struct tnode *right;
    struct tnode *left;
};

struct tnode *CreateBST(struct tnode *, int);
void Inorder(struct tnode *);
void Preorder(struct tnode *);
void Postorder(struct tnode *);
struct tnode *insertBST(struct tnode *, int);
struct tnode *minValueNode(struct tnode *node);
struct tnode *deleteNode(struct tnode *root, int key);
int searchNode(struct tnode *head, int key);
void printFile(struct tnode *root);

int main()
{
    struct tnode *root = NULL;
    int choice, n, item, i, flag;
    do
    {
        printf("\n\nBinary Search Tree Operations\n");
        printf("\n1. Creation of BST");
        printf("\n2. Traverse in Inorder");
        printf("\n3. Traverse in Preorder");
        printf("\n4. Traverse in Postorder");
        printf("\n5. Insert in BST");
        printf("\n6. delete in BST");
        printf("\n7. Search in BST");
        printf("\n8. Create file and Exit\n");
        printf("\nEnter Choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            root = NULL;
            printf("\nBinary search tree creation\n");
            printf("\n*********************************\n");
            printf("\nEnter number of nodes in binary search tree: \n");
            scanf("%d", &n);
            for (i = 1; i <= n; i++)
            {
                printf("\nEnter data for node %d : ", i);
                scanf("%d", &item);
                root = CreateBST(root, item);
            }
            printf("\nBST with %d nodes is ready to Use!!\n", n);
            break;
        case 2:
            printf("\nBST Traversal in INORDER \n");
            printf("\n*****************\n");
            Inorder(root);
            break;
        case 3:
            printf("\nBST Traversal in PREORDER \n");
            printf("\n*****************\n");
            Preorder(root);
            break;
        case 4:
            printf("\nBST Traversal in POSTORDER \n");
            printf("\n*****************\n");
            Postorder(root);
            break;
        case 5:
            printf("\nInsert in BST\n");
            printf("\n*****************\n");
            printf("\nEnter data to insert : ");
            scanf("%d", &item);
            root = insertBST(root, item);
            break;
        case 6:
            printf("\nDelete in BST\n");
            printf("\n*****************\n");
            printf("\nEnter data to delete : ");
            scanf("%d", &item);
            root = deleteNode(root, item);
            break;
        case 7:
            printf("\nSearch in BST\n");
            printf("\n*****************\n");
            printf("\nEnter data to be searched : ");
            scanf("%d", &item);
            flag = searchNode(root, item);
            if (flag == 1)
            {
                printf("Key %d found in tree!!\n", item);
            }
            else
            {
                printf("Key %d not found in tree!!\n", item);
            }
            break;
        case 8:
            printf("\n\n Printing the file and then exiting!!! \n\n");
            printFile(root);
            exit(0);
            break;
        default:
            printf("\n\nInvalid Option !!! Try Again !! \n\n");
            break;
        }
    } while (choice != 8);
    return 0;
}

struct tnode *CreateBST(struct tnode *root, int item)
{
    
    if (root == NULL)
    {
        root = (struct tnode *)malloc(sizeof(struct tnode));
        root->left = root->right = NULL;
        root->data = item;
        
        return root;
    }
    else
    {
        if (item < root->data)
            root->left = CreateBST(root->left, item);
        else if (item > root->data)
            root->right = CreateBST(root->right, item);
        else
            printf(" Duplicate Element !! Not Allowed !!!");

        return (root);
    }
}

void Inorder(struct tnode *root)
{
    if (root != NULL)
    {
        Inorder(root->left);
        printf(" %d ", root->data);
        Inorder(root->right);
    }
}

void Preorder(struct tnode *root)
{
    if (root != NULL)
    {
        printf(" %d ", root->data);
        Preorder(root->left);
        Preorder(root->right);
    }
}

void Postorder(struct tnode *root)
{
    if (root != NULL)
    {
        Postorder(root->left);
        Postorder(root->right);
        printf(" %d ", root->data);
    }
}

struct tnode *insertBST(struct tnode *root, int item)
{
    if (root == NULL)
    {
        root = (struct tnode *)malloc(sizeof(struct tnode));
        root->left = root->right = NULL;
        root->data = item;
        return root;
    }
    else
    {
        if (item < root->data)
            root->left = CreateBST(root->left, item);
        else if (item > root->data)
            root->right = CreateBST(root->right, item);
        else
            printf(" Duplicate Element !! Not Allowed !!!");

        return (root);
    }
}

// Deleting a node
struct tnode *deleteNode(struct tnode *root, int key)
{
    // Return if the tree is empty
    if (root == NULL)
        return root;

    // Find the node to be deleted
    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);

    else
    {
        // If the node is with only one child or no child
        if (root->left == NULL)
        {
            struct tnode *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct tnode *temp = root->left;
            free(root);
            return temp;
        }

        // If the node has two children
        struct tnode *temp = minValueNode(root->right);

        // Place the inorder successor in position of the node to be deleted
        root->data = temp->data;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }
    printf("Deletion complete...!");
    return root;
}

// Find the inorder successor
struct tnode *minValueNode(struct tnode *node)
{
    struct tnode *current = node;

    // Find the leftmost leaf
    while (current && current->left != NULL)
        current = current->left;

    return current;
}

int searchNode(struct tnode *root, int key)
{
    while (root != NULL)
    {
        if (key > root->data)
        {
            return searchNode(root->right, key);
        }
        else if (key < root->data)
        {
            return searchNode(root->left, key);
        }
        else
        {
            return 1;
        }
    }
    return 0;
}
void printFile(struct tnode *root)
{
    FILE *fp ;
    fp = fopen("BSTFile.txt", "w");
    struct tnode *current, *pre;
 
    if (root == NULL)
        return;
 
    current = root;
    while (current != NULL) {
 
        if (current->left == NULL) {
            fprintf(fp,"%d ", current->data);
            current = current->right;
        }
        else {
 
            /* Find the inorder predecessor of current */
            pre = current->left;
            while (pre->right != NULL
                   && pre->right != current)
                pre = pre->right;
 
            /* Make current as the right child of its
               inorder predecessor */
            if (pre->right == NULL) {
                pre->right = current;
                current = current->left;
            }
 
            /* Revert the changes made in the 'if' part to
               restore the original tree i.e., fix the right
               child of predecessor */
            else {
                pre->right = NULL;
                fprintf(fp,"%d ", current->data);
                current = current->right;
            } /* End of if condition pre->right == NULL */
        } /* End of if condition current->left == NULL*/
    }
    printf("\n File Printed successfully!!! \n");
    fclose(fp);
}
