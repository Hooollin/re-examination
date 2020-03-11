#include <stdio.h>
#define MAX_SIZE 1000

void build_tree(int arr[], int tree[], int node, int start ,int end){
    if(start == end){
        tree[node] = arr[start];
        return;
    }
    int mid = (start + end) / 2;
    int left_node = node * 2 + 1;
    int right_node = node * 2 + 2;
    build_tree(arr, tree, left_node, start, mid);
    build_tree(arr, tree, right_node, mid + 1, end);
    tree[node] = tree[left_node] + tree[right_node];
}

void update_tree(int arr[], int tree[], int node, int start, int end, int idx, int val){
    if(start == end){
        if(idx == start){
            arr[idx] = val;
            tree[node] = val;
        }
        return;
    }
    int mid = (start + end) / 2;
    int left_node = node * 2 + 1;
    int right_node = node * 2 + 2;
    update_tree(arr, tree, left_node, start, mid, idx, val); 
    update_tree(arr, tree, right_node, mid + 1, end, idx, val);
    tree[node] = tree[left_node] + tree[right_node];
}


int main(){
    int arr[] = {1, 2, 3, 4, 5};
    int tree[MAX_SIZE] = {0};
    build_tree(arr, tree, 0, 0, 4);
    update_tree(arr, tree, 0, 0, 4, 3, 10);
    for(int i = 0; i < 20; i++){
        printf("%d ", tree[i]);
    }
    return 0;
}
