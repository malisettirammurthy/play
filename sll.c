#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct {
    char name[20];
    int id;
} s, *sptr = &s; 

typedef struct node {
    int item;
    struct node *next;
} NODE;

NODE* insert_at_begin(NODE *tmp, int item)
{
    NODE *new;
    new = malloc(sizeof(NODE));
    if (new == NULL){
        puts("malloc failed");
        exit(1);
    }
    new->item = item;
    new->next = NULL;

    if(tmp == NULL)
        tmp = new;
    else {
        new->next = tmp;
        tmp = new;
    }
    return tmp;
}

NODE* delete_at_begin(NODE *root)
{
    NODE *tmp;
    if (root == NULL) {
        //puts("List empty Nothing to delete");
        return root;
    }
    else {
        tmp = root;
        root = root->next;

        tmp->next = NULL;
        free(tmp);
        tmp = NULL;
    }
    return root;
}

void display(NODE *front)
{
    NODE *tmp;

    tmp = front;
    while(tmp != NULL) {
        printf(" %d -> ", tmp->item);
        tmp = tmp->next;
    }
    puts("NULL");
}

NODE* insert_at_end_rec(NODE *root, int item)
{
    NODE *new;
    if (root == NULL){
        new = malloc(sizeof(NODE));
        if (new == NULL){
            puts("malloc failed");
            exit(1);
        }
        new->item = item;
        new->next = NULL;
        return new;
    }
    else {
        root->next = insert_at_end_rec(root->next, item);
        return root;
    }
}

NODE* delete_at_end_rec(NODE *root)
{
    NODE *new;
    if (root == NULL){
        return root;
    }
    else if(root->next == NULL) {
        free(root);
        root = NULL;
        return root;
    }
    else {
        root->next = delete_at_end_rec(root->next);
        return root;
    }
}

NODE* create_node(int item)
{
    NODE *new;
    new = (NODE*) malloc(sizeof(NODE));
    if(new == NULL) {
        puts("malloc failed");
        exit(1);
    }
    new->item = item;
    new->next = NULL;
    return new;
}

NODE* insert_at_any_pos(NODE *root, int pos, int item)
{
    int i = 1;
    NODE *new, *nxt, *prv;

    if(pos < 0) {
        puts("Invalid -ve position");
        return root;
    }

    new = create_node(item);

    if(pos==1 && root==NULL) {
        root = new;
        return root;
    }

    if(pos==1) {
        new->next = root;
        root = new;
        return root;
    }

    nxt = root;
    while(i < pos) {
        prv = nxt;
        if(prv == NULL) {
            puts("Invalid postion, Beyond the size");
            free(new);
            new = NULL;
            return root;
        }
        nxt = prv->next;
        i += 1;
    }
    prv->next = new;
    new->next = nxt;

    return root;
}

NODE* delete_at_any_pos(NODE *root, int pos)
{
    int i=1;
    NODE *prv, *tmp, *cur;
    if(pos < 0) {
        puts("Invalid -ve position");
        return root;
    }

    if(root == NULL) {
        puts("List empty, Notthong to delete");
        return root;
    }

    if(pos==1 && root->next==NULL){
        free(root);
        root = NULL;
        return root;
    }

    if(pos==1){
        tmp = root;
        root = root->next;
        free(tmp);
        tmp = NULL;
        return root;
    }

    cur = root;
    while(i < pos) {
        prv = cur;
        cur = cur->next;
        if(cur == NULL) {
            puts("Deleetion not possibe, Beyond position");
            return root;
        }
        i += 1;
    }
    prv->next = cur->next;
    cur->next = NULL;
    free(cur);
    cur = NULL;
    return root;
}

int main()
{
    NODE *front = NULL;
    int ch, item, pos;

    while(1) {
        puts("0. exit");
        puts("1. Insert at beginning");
        puts("2. delete at beginning");
        puts("3. display");
        puts("4. Insert at end");
        puts("5. delete at end");
        puts("6. insert at any position");
        puts("7. delete at any position");

        printf("Enter one among abobve choices : ");
        scanf("%d", &ch);

        switch(ch) {
            case 0: 
                    puts("Bye.. Bye..");
                    exit(1);
            case 1: 
                    printf("Enter an item to insert in sll: ");
                    scanf("%d", &item);
                    front = insert_at_begin(front, item);
                    break;
            case 2: 
                    front = delete_at_begin(front);
                    display(front);
                    break;
            case 3:
                    display(front);
                    break;
            case 4: 
                    printf("Enter an item to insert in sll: ");
                    scanf("%d", &item);
                    front = insert_at_end_rec(front, item);
                    break;
            case 5: 
                    front = delete_at_end_rec(front);
                    display(front);
                    break;
            case 6:
                    printf("Enter the element to be inserted: ");
                    scanf("%d", &item);
                    printf("Enter the position to insert:");
                    scanf("%d", &pos);
                    front = insert_at_any_pos(front, pos, item);
                    break;
            case 7:
                    printf("Enter the position to delete:");
                    scanf("%d", &pos);
                    front = delete_at_any_pos(front, pos);
                    break;
        }
    }
    return 0;
}
