#include <stdio.h>
#include <assert.h>
#include <stdlib.h> 

struct node {
    struct node *left;
    int info;
    struct node *right;
};

typedef struct node NODE;

NODE* create_node(int info)
{
    NODE *new;
    new = malloc(sizeof(NODE));

    if(new == NULL) {
        puts("malloc failed");
        exit(1);
    }
    new->right = NULL;
    new->info = info;
    new->right = NULL;

    return new;
}

NODE* insert(NODE *root, int info)
{
    NODE *nn;
    if(root == NULL)
        root = create_node(info);
    else if(info < root->info)
        root->left = insert(root->left, info);
    else
        root->right = insert(root->right, info);
    return root;
}

void inorder(NODE *root)
{
    if(root != NULL) {
        inorder(root->left);
        printf("%3d", root->info);
        inorder(root->right);
    }
}

void preorder(NODE *root)
{
    if(root != NULL) {
        printf("%3d", root->info);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(NODE *root)
{
    if(root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%3d", root->info);
    }
}

NODE* free_tree(NODE *root)
{
    if(root == NULL)
        return root;

    root->left = free_tree(root->left);
    root->right = free_tree(root->right);
    free(root);
    root = NULL;
    return root;
}

int main(int argc, char **argv)
{
    NODE *root=NULL;
    int choice, element;

    while(1) {
        puts("0.exit");
        puts("1.insert");
        puts("2.inorder");
        puts("3.preorder");
        puts("4.postorder");
        puts("5.tree free");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 0: 
                    root = free_tree(root);
                    puts("Exiting from the program");
//                    exit(0);
                    break;
            case 1:
                    printf("Enter an element to insert in tree : ");
                    scanf("%d", &element);
                    root = insert(root, element);
                    break;
            case 2:
                    printf("inorder :");
                    inorder(root);
                    puts("");
                    break;
            case 3:
                    printf("preorder :");
                    preorder(root);
                    puts("");
                    break;
            case 4:
                    printf("postorder :");
                    postorder(root);
                    puts("");
                    break;
            case 5:
                    puts("Clearing the list");
                    root = free_tree(root);
                    break;
        }
    }

    return 0;
}