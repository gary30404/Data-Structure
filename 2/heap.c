#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    int data;
    struct node *left;
    struct node *right;
    struct node *parent;
}node;

void build_heap(node *rt, char *input);
node *insert(node *pt, int data);
void adjust_bottom_up(node *nd);
void adjust_top_down(node *nd);
node *get_next_parent(node *rt);
node *get_last_node(node *rt);
int getHeight(node *rt, int h);

void build_heap(node *rt, char *input){
    int n = strlen(input);
    node *nd = malloc(sizeof(node));
    node *pt = malloc(sizeof(node));
    pt = rt;
    for (int i = 1; i<n; i++){
        nd = insert(pt, input[i]);
        adjust_bottom_up(nd);
        if (pt->left != NULL && pt->right !=NULL && pt->parent != NULL)
            pt = get_next_parent(pt->parent);
        else
            pt = get_next_parent(pt);
    }
}
node *insert(node *pt, int data){
    node *nd = malloc(sizeof(node));
    nd->data = data;
    nd->left = NULL;
    nd->right = NULL;
    if (pt->left == NULL) pt->left = nd;
    else pt->right = nd;
    nd->parent = pt;
    return nd;
}
node *get_next_parent(node *rt){
    node *nd = malloc(sizeof(node));
    nd = rt;
    if (rt->left == NULL || rt->right == NULL) return rt;
    int left_height = 0;
    int right_height = 0;
    left_height = getHeight(rt->left, left_height);
    right_height = getHeight(rt->right, right_height);
    if (left_height == right_height) return get_next_parent(rt->left);
    if (left_height > right_height)  return get_next_parent(rt->right);
    return NULL;
}

node *get_last_node(node *rt){
    node *nd = malloc(sizeof(node));
    nd = rt;
    if (rt->left == NULL) return rt;
    if (rt->right == NULL) return rt->left;
    int left_height = 0;
    int right_height = 0;
    left_height = getHeight(rt->left, left_height);
    right_height = getHeight(rt->right, right_height);
    if (left_height == right_height) return get_last_node(rt->right);
    if (left_height > right_height)  return get_last_node(rt->left);
    return NULL;
}

int getHeight(node *rt, int h){
    if (rt->left != NULL) return getHeight(rt->left, h+1);
    if (rt->right != NULL) return getHeight(rt->right, h+1);
    return h;
}

void adjust_bottom_up(node *nd){
    if (nd->parent == NULL) return;
    if (nd->parent->data > nd->data){
        int tmp = nd->parent->data;
        nd->parent->data = nd->data;
        nd->data = tmp;
        adjust_bottom_up(nd->parent);
    }
}

void adjust_top_down(node *nd){
    int tmp;
    if (nd == NULL) return;
    if (nd->left == NULL && nd->right == NULL) return;
    if (nd->left != NULL && nd->right == NULL){
        if (nd->data > nd->left->data){
            tmp = nd->left->data;
            nd->left->data = nd->data;
            nd->data = tmp;
        }
        return;
    }
    if (nd->right->data > nd->left->data){
        if (nd->data > nd->left->data){
            tmp = nd->left->data;
            nd->left->data = nd->data;
            nd->data = tmp;
            adjust_top_down(nd->left);
        }
    }
    else{
        if (nd->data > nd->right->data){
            tmp = nd->right->data;
            nd->right->data = nd->data;
            nd->data = tmp;
            adjust_top_down(nd->right);
        }
    }
}

int delete(node *rt){
    if (rt->parent == rt) return -1;
    int output = rt->data;
    node *nd = malloc(sizeof(node));
    node *pt = malloc(sizeof(node));
    nd = get_last_node(rt);
    rt->data = nd->data;
    // delete node
    pt = nd->parent;
    if (pt != NULL){ //prevent the last node segmaentation fault
        if (pt->left == nd) pt->left = NULL;
        else pt->right = NULL;
        nd->parent = NULL;
    }
    else{
        nd->parent = nd;
    }
    free(nd);
    adjust_top_down(rt);
    return output;
}

int main(){
    char input[10] = {9,8,7,6,5,4,3,2,1};
    node *rt = malloc(sizeof(node));
    rt->data = input[0];
    rt->left = NULL;
    rt->right = NULL;
    rt->parent = NULL;
    build_heap(rt, input);
    
    
    printf("%d\n", rt->data);
    printf("%d\n", rt->left->data);
    printf("%d\n", rt->right->data);
    
    printf("%d\n", rt->left->left->data);
    printf("%d\n", rt->left->right->data);
    
    printf("%d\n", rt->right->left->data);
    printf("%d\n", rt->right->right->data);
    printf("%d\n", rt->left->left->left->data);
    printf("%d\n", rt->left->left->right->data);
    printf("\n");

    printf("---%d\n", delete(rt));

    printf("---%d\n", delete(rt));

    printf("---%d\n", delete(rt)); //3

    printf("---%d\n", delete(rt));


    printf("---%d\n", delete(rt));


    printf("---%d\n", delete(rt));

    printf("---%d\n", delete(rt));

    printf("---%d\n", delete(rt));
    
    printf("---%d\n", delete(rt));
    printf("---%d\n", delete(rt));

}
