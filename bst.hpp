#ifndef BST_HPP_
#define BST_HPP_

#include <initializer_list>

template <typename T>
class BST
{
public:
    BST(); // Default constructor

    BST(const BST<T>& other); // Copy constructor
    BST<T>& operator=(const BST<T>& other); // Copy assignment operator

    BST(BST<T>&& other); // Move constructor
    BST<T>& operator=(BST<T>&& other); // Move assignment operator

    BST(std::initializer_list<T> init_list);  // Constructor with initializer list

    ~BST(); // Destructor

public:
    // Public functions for basic operations

    void insert(const T& value); // Insert a value into the BST
    void remove(const T& value);  // Remove a value from the BST

    const T& find_max() const; // Find the maximum value in the BST
    const T& find_min() const; // Find the minimum value in the BST

    bool search(const T& value); // Search for a value in the BST
    int get_height() const; // Get the height of the BST

    // Traversal functions
    void inorder(); // Perform an inorder traversal of the BST
    void preorder(); // Perform a preorder traversal of the BST
    void postorder(); // Perform a postorder traversal of the BST

private:
    // Private TreeNode structure for the tree nodes
    template <typename>
    struct TreeNode
    {
        TreeNode(const T& value = T(), TreeNode* left = nullptr, TreeNode* right = nullptr)
            : m_value(value)
            , m_left(left)
            , m_right(right)
        {
        }

        T m_value;
        TreeNode<T>* m_left;
        TreeNode<T>* m_right;
    };

    TreeNode<T>* m_root;

private:
    // Private helper functions

    void insert(const T& value, TreeNode<T>*& root); // Recursive insert function
    void remove(TreeNode<T>*& root, const T& value); // Recursive remove function
    void copy(TreeNode<T>* src_tree, TreeNode<T>*& dest_tree); // Recursive copy function for deep copying a tree
    void clear(TreeNode<T>* root); // Recursive clear function for deallocating memory
    bool search(TreeNode<T>* root, const T& value); // Recursive search function

    int get_height(TreeNode<T>* root) const; // Recursive function to calculate the height of the tree

    TreeNode<T>* find_max(TreeNode<T>* root) const; // Recursive function to find the maximum value in the tree
    TreeNode<T>* find_min(TreeNode<T>* root) const; // Recursive function to find the minimum value in the tree

    void inorder(TreeNode<T>* root); // Recursive inorder traversal function
    void preorder(TreeNode<T>* root); // Recursive preorder traversal function
    void postorder(TreeNode<T>* root); // Recursive postorder traversal function
};

#include "bst_impl_.hpp"

#endif // BST_HPP_