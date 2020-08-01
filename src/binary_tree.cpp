#include <stdlib.h>
#include "binary_tree.h"

BinaryTree* new_node(int data)
{
    BinaryTree* node = (BinaryTree*)malloc(sizeof(BinaryTree));
    node->data = data;
    node->left_child = NULL;
    node->right_child = NULL;
    return NULL;
}
