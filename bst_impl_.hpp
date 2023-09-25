#ifndef BST_IMPL_HPP_
#define BST_IMPL_HPP_

#include <iostream>

// Default constructor
template <typename T>
BST<T>::BST()
 : m_root(nullptr)
{
}

// Copy constructor
template <typename T>
BST<T>::BST(const BST<T>& other)
    : m_root(nullptr)
{
    copy(other.m_root, m_root);
}

// Copy assignment operator
template <typename T>
BST<T>& BST<T>::operator=(const BST<T>& other)
{
    if (this != &other) {
        copy(other.m_root, m_root);
    }
    return *this;
} 

// Move constructor
template <typename T>
BST<T>::BST(BST<T>&& other)
    : m_root(nullptr)
{
    m_root = other.m_root;
    other.m_root = nullptr;
}

// Move assignment operator
template <typename T>
BST<T>& BST<T>::operator=(BST&& other)
{
    if (this != &other) {
        m_root = other.m_root;
        other.m_root = nullptr;
    }
    return *this;
}

// Constructor with initializer list
template <typename T>
BST<T>::BST(std::initializer_list<T> init_list)
    : m_root(nullptr)
{
    for (auto elem : init_list) {
        insert(elem);
    }
}

// Dtor
template <typename T>
BST<T>::~BST()
{
    clear(m_root);
}


// Clean up the memory by deleting all nodes in the tree
template <typename T>
void BST<T>::clear(TreeNode<T>* root)
{
    if (!root) {
        return;
    }

    clear(root->m_left);
    clear(root->m_right);
    delete root;
}

// Copy tree
template <typename T>
void BST<T>::copy(TreeNode<T>* src_tree, TreeNode<T>*& dest_tree)
{
    if (!src_tree) {
        dest_tree = nullptr;
        return;
    }

    dest_tree = new TreeNode<T>(src_tree->m_value); // Copy the current node's value

    // Recursively copy the left and right subtrees
    copy(src_tree->m_left, dest_tree->m_left);
    copy(src_tree->m_right, dest_tree->m_right);
}

// Public insert function: inserts a value into the BST
template <typename T>
void BST<T>::insert(const T& value)
{
    insert(value, m_root);
}

// Private insert
template <typename T>
void BST<T>::insert(const T& value, TreeNode<T>*& root)
{
    if (!root) {
        // If the current node is nullptr, create a new node with the value
        root = new TreeNode<T>(value, nullptr, nullptr);
    }

    if (value < root->m_value) {
        insert(value, root->m_left); // Recursively insert into the left subtree
    } else if (value > root->m_value) { 
        insert(value, root->m_right); // Recursively insert into the right subtree
    }
}

 // Public remove function: removes a value from the BST
template <typename T>
void BST<T>::remove(const T& value)
{
    remove(m_root, value);
}

// Private remove
template <typename T>
void BST<T>::remove(TreeNode<T>*& root, const T& value)
{
    if (!root) {
        return;
    }

    if (value > root->m_value) {
        // Recursively remove from the right subtree
        remove(root->m_right, value);
    } else if (value < root->m_value) {
        // Recursively remove from the left subtree
        remove(root->m_left, value);
    } else if (root->m_left && root->m_right) {
        // If the node to be removed has two children, replace it with the minimum value in the right subtree
        root->m_value = find_min(root->m_right)->m_value;
        remove(root->m_right, root->m_value);
    } else {
        // If the node to be removed has one or no children, update the parent node's link accordingly
        TreeNode<T>* tmp = root;
        root = (root->m_left) ? root->m_left : root->m_right;
        delete tmp;
    }
}

// Public search function: searches for a value in the BST
template <typename T>
bool BST<T>::search(const T& value)
{
    return search(m_root, value);
}

template <typename T>
bool BST<T>::search(TreeNode<T>* root, const T& value)
{
    if (!root) {
        return false; // Not found
    }

    if (root->m_value == value) {
        return true; // Found the value
    } else if (value < root->m_value) {
        return search(root->m_left, value); // Search in the left subtree
    } else {
        return search(root->m_right, value); // Search in the right subtree
    }      
}

// Public get_height function: calculates the height of the BST
template <typename T>
int BST<T>::get_height() const
{
    return get_height(m_root);
}

template <typename T>
int BST<T>::get_height(TreeNode<T>* root) const
{
    if (!root) {
        return -1; // Empty tree
    }

    // Recursively calculate the height of the left and right subtrees.
    int left_height = get_height(root->m_left);
    int right_height = get_height(root->m_right);

    // The height of the tree is the maximum of the left and right subtree heights, plus 1 for the current node.
    return std::max(left_height, right_height) + 1;
}

template <typename T>
const T& BST<T>::find_min() const
{
    return find_min(m_root)->m_value;
}

template <typename T>
BST<T>::TreeNode<T>* BST<T>::find_min(TreeNode<T>* root) const
{
    if (!root) {
        return nullptr;
    }

    if (!root->m_left) {
        return root;
    }

    return find_min(root->m_left);
}

// Public find_max function: finds the maximum value in the BST
template <typename T>
const T& BST<T>::find_max() const
{
    return find_max(m_root)->m_value;
}

// Private find_max
template <typename T>
BST<T>::TreeNode<T>* BST<T>::find_max(TreeNode<T>* root) const
{
    if (!root) {
        return nullptr;
    }

    if (!root->m_right) {
        return root;
    }

    return find_max(root->m_right);
}

// Public inorder function: performs an inorder traversal of the BST
template <typename T>
void BST<T>::inorder()
{
    inorder(m_root);
}

template <typename T>
void BST<T>::inorder(TreeNode<T>* root)
{
    if (!root) {
        return;
    }

    // left subtree, current node, right subtree
    inorder(root->m_left);
    std::cout << root->m_value << " ";
    inorder(root->m_right);
}

// Public preorder function: performs a preorder traversal of the BST
template <typename T>
void BST<T>::preorder()
{
    preorder(m_root);
}

template <typename T>
void BST<T>::preorder(TreeNode<T>* root)
{
    if (!root) {
        return;
    }

    //current node, left subtree, right subtree
    std::cout << root->m_value << " ";
    preorder(root->m_left);
    preorder(root->m_right);
}

// Public postorder function: performs a postorder traversal of the BST
template <typename T>
void BST<T>::postorder()
{
    postorder(m_root);
}

template <typename T>
void BST<T>::postorder(TreeNode<T>* root)
{
    if (!root) {
        return;
    }

    // left subtree, right subtree, current node
    postorder(root->m_left);
    postorder(root->m_right);
    std::cout << root->m_value << " ";
}

#endif // BST_IMPL_HPP_