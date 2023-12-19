#include <iostream>
using namespace std;

// Node structure
struct Node {
  char label;
  Node *left, *right, *parent;
};

// Global pointer variables
Node *root, *newNode;

// Create New Tree
void createNewTree(char label) {
  if (root != NULL)
    cout << "\nTree sudah dibuat" << endl;
  else {
    root = new Node();
    root->label = label;
    root->left = NULL;
    root->right = NULL;
    root->parent = NULL;
    cout << "\nNode " << label << " berhasil dibuat menjadi root." << endl;
  }
}

// Insert Left
Node *insertLeft(char label, Node *node) {
  if (root == NULL) {
    cout << "\nBuat tree terlebih dahulu!!" << endl;
    return NULL;
  } else {
    if (node->left != NULL) {
      cout << "\nNode " << node->label << " sudah ada anak kiri!!" << endl;
      return NULL;
    } else {
      newNode = new Node();
      newNode->label = label;
      newNode->left = NULL;
      newNode->right = NULL;
      newNode->parent = node;
      node->left = newNode;
      cout << "\nNode " << label << " berhasil ditambahkan ke anak kiri " << newNode->parent->label << endl;
      return newNode;
    }
  }
}

// Insert Right
Node *insertRight(char label, Node *node) {
  if (root == NULL) {
    cout << "\nBuat tree terlebih dahulu!!" << endl;
    return NULL;
  } else {
    if (node->right != NULL) {
      cout << "\nNode " << node->label << " sudah ada anak kanan!!" << endl;
      return NULL;
    } else {
      newNode = new Node();
      newNode->label = label;
      newNode->left = NULL;
      newNode->right = NULL;
      newNode->parent = node;
      node->right = newNode;
      cout << "\nNode " << label << " berhasil ditambahkan ke anak kanan " << newNode->parent->label << endl;
      return newNode;
    }
  }
}

// Check if Tree is Empty
bool empty() {
  if (root == NULL)
    return true;
  else
    return false;
}

// Update Node Label
void update(char label, Node *node) {
  if (!root) {
    cout << "\nBuat tree terlebih dahulu!!" << endl;
  } else {
    if (!node)
      cout << "\nNode yang ingin diganti tidak ada!!" << endl;
    else {
      char temp = node->label;
      node->label = label;
      cout << "\nLabel node " << temp << " berhasil diubah menjadi " << label << endl;
    }
  }
}

// Retrieve Node Label
void retrieve(Node *node) {
  if (!root) {
    cout << "\nBuat tree terlebih dahulu!!" << endl;
  } else {
    if (!node)
      cout << "\nNode yang ditunjuk tidak ada!!" << endl;
    else
      cout << "\nLabel node : " << node->label << endl;
  }
}

// Find Node Information
void find(Node *node) {
  if (!root) {
    cout << "\nBuat tree terlebih dahulu!!" << endl;
  } else {
    if (!node)
      cout << "\nNode yang ditunjuk tidak ada!!" << endl;
    else {
      cout << "\nLabel Node : " << node->label << endl;
      cout << "Root Node : " << root->label << endl;

      if (!node->parent)
        cout << "Parent Node : (tidak punya orang tua)" << endl;
      else
        cout << "Parent Node : " << node->parent->label << endl;

      if (node->parent != NULL && node->parent->left != node && node->parent->right == node)
        cout << "Saudara : " << node->parent->left->label << endl;
      else if (node->parent != NULL && node->parent->right != node && node->parent->left == node)
        cout << "Saudara : " << node->parent->right->label << endl;
      else
        cout << "Saudara : (tidak punya saudara)" << endl;

      if (!node->left)
        cout << "Anak Kiri Node : (tidak punya anak kiri)" << endl;
      else
        cout << "Anak Kiri Node : " << node->left->label << endl;

      if (!node->right)
        cout << "Anak Kanan Node : (tidak punya anak kanan)" << endl;
      else
        cout << "Anak Kanan Node : " << node->right->label << endl;
    }
  }
}

// Traversal
// PreOrder
void preOrder(Node *node = root) {
  if (!root)
    cout << "\nBuat tree terlebih dahulu!!" << endl;
  else {
    if (node != NULL) {
      cout << node->label << ", ";
      preOrder(node->left);
      preOrder(node->right);
    }
  }
}

// InOrder
void inOrder(Node *node = root) {
  if (!root)
    cout << "\nBuat tree terlebih dahulu!!" << endl;
  else {
    if (node != NULL) {
      inOrder(node->left);
      cout << node->label << ", ";
      inOrder(node->right);
    }
  }
}

// PostOrder
void postOrder(Node *node = root) {
  if (!root)
    cout << "\nBuat tree terlebih dahulu!!" << endl;
  else {
    if (node != NULL) {
      postOrder(node->left);
      postOrder(node->right);
      cout << node->label << ", ";
    }
  }
}

// Delete Entire Tree
void deleteTree(Node *node) {
  if (!root)
    cout << "\nBuat tree terlebih dahulu!!" << endl;
  else {
    if (node != NULL) {
      if (node != root) {
        node->parent->left = NULL;
        node->parent->right = NULL;
      }
      deleteTree(node->left);
      deleteTree(node->right);

      if (node == root) {
        delete root;
        root = NULL;
      } else {
        delete node;
      }
    }
  }
}

// Delete Subtree
void deleteSub(Node *node) {
  if (!root)
    cout << "\nBuat tree terlebih dahulu!!" << endl;
  else {
    deleteTree(node->left);
    deleteTree(node->right);
    cout << "\nSubtree node " << node->label << " berhasil dihapus." << endl;
  }
}

// Clear Entire Tree
void clear() {
  if (!root)
    cout << "\nBuat tree terlebih dahulu!!" << endl;
  else {
    deleteTree(root);
    cout << "\nTree berhasil dihapus." << endl;
  }
}

// Calculate Size of Tree
int size(Node *node = root) {
  if (!root) {
    cout << "\nBuat tree terlebih dahulu!!" << endl;
    return 0;
  } else {
    if (!node)
      return 0;
    else
      return 1 + size(node->left) + size(node->right);
  }
}

// Calculate Height of Tree
int height(Node *node = root) {
  if (!root) {
    cout << "\nBuat tree terlebih dahulu!!" << endl;
    return 0;
  } else {
    if (!node)
      return 0;
    else {
      int heightLeft = height(node->left);
      int heightRight = height(node->right);

      if (heightLeft >= heightRight)
        return heightLeft + 1;
      else
        return heightRight + 1;
    }
  }
}

// Display Characteristics of Tree
void characteristics() {
  cout << "\nSize Tree : " << size() << endl;
  cout << "Height Tree : " << height() << endl;
  cout << "Average Node of Tree : " << size() / height() << endl;
}

int main() {
  createNewTree('A');

  Node *nodeB, *nodeC, *nodeD, *nodeE, *nodeF, *nodeG, *nodeH, *nodeI, *nodeJ;

  nodeB = insertLeft('B', root);
  nodeC = insertRight('C', root);
  nodeD = insertLeft('D', nodeB);
  nodeE = insertRight('E', nodeB);
  nodeF = insertLeft('F', nodeC);
  nodeG = insertLeft('G', nodeE);
  nodeH = insertRight('H', nodeE);
  nodeI = insertLeft('I', nodeG);
  nodeJ = insertRight('J', nodeG);

  cout << "Tree empty? : " << empty() << endl;

  update('Z', nodeC);
  update('C', nodeC);

  retrieve(nodeC);

  find(nodeC);

  cout << "\nPreOrder :" << endl;
  preOrder(nodeE);
  cout << "\n" << endl;
  cout << "InOrder :" << endl;
  inOrder(nodeE);
  cout << "\n" << endl;
  cout << "PostOrder :" << endl;
  postOrder(nodeE);
  cout << "\n" << endl;

  characteristics();

  deleteSub(nodeE);
  cout << "\nPreOrder :" << endl;
  preOrder();
  cout << "\n" << endl;

  characteristics();
}
