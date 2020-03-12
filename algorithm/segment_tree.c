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
        arr[idx] = val;
        tree[node] = val;
        return;
    }
    int mid = (start + end) / 2;
    int left_node = node * 2 + 1;
    int right_node = node * 2 + 2;

    if(mid >= idx){
        update_tree(arr, tree, left_node, start, mid, idx, val); 
    }else{
        update_tree(arr, tree, right_node, mid + 1, end, idx, val);
    }
    
    tree[node] = tree[left_node] + tree[right_node];
}

int query_tree(int arr[], int tree[], int node, int start, int end, int L, int R){
    if(end < L || start > R){
        return 0;
    }
    if(start == L && end == R){
        return tree[node];
    }
    if(start == end){
        return tree[node];
    }
            
    int mid = (start + end) / 2;
    int left_node = node * 2 + 1;
    int right_node = node * 2 + 2;
    
    int left_sum = query_tree(arr, tree, left_node, start, mid, L, R);
    int right_sum = query_tree(arr, tree, right_node, mid + 1, end, L, R);

    return left_sum + right_sum;
}

int main(){
    int L = 0, R = 4;
    scanf("%d %d", &L, &R);

    int arr[] = {1, 2, 3, 4, 5};
    int tree[MAX_SIZE] = {0};
    build_tree(arr, tree, 0, 0, 4);
    printf("%d", query_tree(arr, tree, 0, 0, 4, L, R));
    return 0;
}
