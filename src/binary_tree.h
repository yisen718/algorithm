#pragma once


/*
 * 1）The maximum *number of nodes* at level 'l' of a binary tree is 2^l, like level 0 2^0 = 1, level 1 2^1 = 2
 * 2) Maximun number of nodes in a binary tree of height 'h' is 2^h - 1, height 2 maximum is 2^2 - 1 = 3
 * 3) In a Binary Tree with N nodes, minimum possible height or minimum number of level is log2(N+1).
 */


typedef struct BinaryTree
{
    struct BinaryTree* left_child;
    int data;
    struct BinaryTree* right_child;
}BinaryTree;


typedef struct BinarySiblingTree
{
    struct BinarySiblingTree* left_child;
    int data;
    struct BinarySiblingTree* right_sibling;
}BinarySiblingTree;


BinaryTree* new_binary_node(int data);


BinarySiblingTree* new_binary_sibling_node(int data);
