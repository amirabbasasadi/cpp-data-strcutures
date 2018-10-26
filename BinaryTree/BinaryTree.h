// Implementing Binary Tree
#ifndef BINARY_TREE_GUARD
#define BINARY_TREE_GUARD
#include <functional>
/// C++ Data Structures Namesapce
namespace CXXDS {
/// \class Binary Tree Node
template <class T> class BinaryTreeNode {
public:
  explicit BinaryTreeNode(T data, BinaryTreeNode<T> *left = nullptr,
                          BinaryTreeNode<T> *right = nullptr)
      : _data(data), _left(left), _right(right) {
    // Node constructor
  }
  /// node data
  T data() { return _data; }
  /// left child
  inline BinaryTreeNode<T> *left() { return _left; }
  /// right child
  inline BinaryTreeNode<T> *right() { return _right; }
  /// set left child
  inline void setLeft(BinaryTreeNode<T> *node) { _left = node; }
  /// set right child
  inline void setRight(BinaryTreeNode<T> *node) { _right = node; }

private:
  BinaryTreeNode<T> *_left;
  BinaryTreeNode<T> *_right;
  T _data;
};
template <class T> class BinaryTree {
public:
  // number of tree nodes
  static unsigned int number_of_nodes(BinaryTreeNode<T> *root) {
    if (root)
      return 1 + number_of_nodes(root->left()) + number_of_nodes(root->right());
    return 0;
  }
  // Inorder Traverse
  static void inorderTraverse(BinaryTreeNode<T> *root,
                              std::function<void(BinaryTreeNode<T> *)> lambda) {
    if (root) {
      inorderTraverse(root->left(), lambda);
      lambda(root);
      inorderTraverse(root->right(), lambda);
    }
  }
  // Preorder Traverse
  static void inorderTraverse(BinaryTreeNode<T> *root,
                              std::function<void(BinaryTreeNode<T> *)> lambda) {
    if (root) {
      lambda(root);
      inorderTraverse(root->left(), lambda);
      inorderTraverse(root->right(), lambda);
    }
  }
  // Inorder Traverse
  static void postorderTraverse(BinaryTreeNode<T> *root,
                              std::function<void(BinaryTreeNode<T> *)> lambda) {
    if (root) {
      inorderTraverse(root->left(), lambda);
      inorderTraverse(root->right(), lambda);
      lambda(root);
    }
  }
};
} // namespace CXXDS
#endif /* end of include guard: BINARY_TREE_GUARD */
