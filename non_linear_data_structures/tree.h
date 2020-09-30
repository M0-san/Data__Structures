//
// Created by moboustt on 9/30/20.
//

#ifndef DATA__STRUCTURES_TREE_H
#define DATA__STRUCTURES_TREE_H
#include <iostream>


template<typename TREE>
class Node {

public:
    using T = typename TREE::ValueType;

public:

    explicit Node(T v) : value{ v }, leftChild { nullptr }, rightChild { nullptr } {}
    Node() = default;
    T value;
    Node *leftChild;
    Node *rightChild;
};

template<typename T>
class Tree {
public:
    using ValueType = T;
    using Node = Node<Tree<T>>;
public:

    Tree();
    ~Tree();
public:

    /*
     * Inserting and Searching in the Tree
     */
    void insert(T item);

    bool find(T item);

    /*
     * Tree Traversal
     */

    void preOrderTraversal();

    void inOrderTraversal();

    void postOrderTraversal();

    void levelOrderTraversal();

    size_t height();

    T min();

private:
    Node *root;

private:
    void preOrderTraversal(Node *rootNode);

    void inOrderTraversal(Node *rootNode);

    void postOrderTraversal(Node *rootNode);

    void levelOrderTraversal(Node *rootNode);

    size_t height(Node *rootNode);

    T min(Node *rootNode);


    bool isLeaf(const Node *rootNode) const;

    bool isLeftLeaf(const Node *current) const;

    bool isRightLeaf(const Node *current) const;
};


#endif //DATA__STRUCTURES_TREE_H