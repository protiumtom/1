#define NULL 0
#include<stdio.h>
#include<stdlib.h>

// 定义二叉树的节点结构
struct TreeNode {
    char data;
    struct TreeNode *left;
    struct TreeNode *right;
};

// 初始化一个新的二叉树节点
struct TreeNode* createNode(char data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// 使用递归的方式创建二叉树
struct TreeNode* createBinaryTree() {
    char data;
    printf("Enter data (enter '0' for NULL): ");
    scanf(" %c", &data); // 注意加一个空格，消耗换行符

    if (data == '0') {
        return NULL; // 返回空指针表示该节点为NULL
    }

    struct TreeNode* newNode = createNode(data);
    printf("Enter left child of %c:\n", data);
    newNode->left = createBinaryTree(); // 递归创建左子树
    printf("Enter right child of %c:\n", data);
    newNode->right = createBinaryTree(); // 递归创建右子树

    return newNode;
}

// 先序遍历二叉树
void preorderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        printf("%c ", root->data); // 先输出当前节点的值
        preorderTraversal(root->left); // 然后递归遍历左子树
        preorderTraversal(root->right); // 最后递归遍历右子树
    }
}



int main() {
    // 创建二叉树
    struct TreeNode* root = createBinaryTree();

    printf("先序遍历结果：");
    preorderTraversal(root);
    printf("\n");

    // 释放内存
    free(root);

    return 0;
}