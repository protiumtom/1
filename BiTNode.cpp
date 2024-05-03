#define NULL 0
#include<stdio.h>
#include<stdlib.h>

// ����������Ľڵ�ṹ
struct TreeNode {
    char data;
    struct TreeNode *left;
    struct TreeNode *right;
};

// ��ʼ��һ���µĶ������ڵ�
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

// ʹ�õݹ�ķ�ʽ����������
struct TreeNode* createBinaryTree() {
    char data;
    printf("Enter data (enter '0' for NULL): ");
    scanf(" %c", &data); // ע���һ���ո����Ļ��з�

    if (data == '0') {
        return NULL; // ���ؿ�ָ���ʾ�ýڵ�ΪNULL
    }

    struct TreeNode* newNode = createNode(data);
    printf("Enter left child of %c:\n", data);
    newNode->left = createBinaryTree(); // �ݹ鴴��������
    printf("Enter right child of %c:\n", data);
    newNode->right = createBinaryTree(); // �ݹ鴴��������

    return newNode;
}

// �������������
void preorderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        printf("%c ", root->data); // �������ǰ�ڵ��ֵ
        preorderTraversal(root->left); // Ȼ��ݹ����������
        preorderTraversal(root->right); // ���ݹ����������
    }
}



int main() {
    // ����������
    struct TreeNode* root = createBinaryTree();

    printf("������������");
    preorderTraversal(root);
    printf("\n");

    // �ͷ��ڴ�
    free(root);

    return 0;
}