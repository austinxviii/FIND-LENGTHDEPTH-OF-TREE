#include <iostream>
#include <queue>
using namespace std;

class Node{
  public:
    int data;
    Node* left;
    Node* right;

  Node(int data){
    this->data = data;
    this->left = NULL;
    this->right = NULL;
  }
};

Node* buildTree(Node* root){
  int data;
  cin >> data;
  root = new Node(data);

  if(data == -1){
    return NULL;
  }

  root->left = buildTree(root);
  root->right = buildTree(root);

  return root;
}

void print(Node* root){
  queue<Node*> q;
  q.push(root);
  q.push(NULL);

  while(!q.empty()){
    Node* temp = q.front();
    q.pop();
    
    if(temp == NULL){
      cout << endl;
      if(!q.empty()){
        q.push(NULL);
      }
    }
    else{
      cout << temp->data << " ";
      if(temp->left){
        q.push(temp->left);
      }
      if(temp->right){
        q.push(temp->right);
      }
    }
  }
}

int height(Node* root){
  if(root == NULL){
    return 0;
  }
  int left = height(root->left);
  int right = height(root->right);

  return max(left, right) + 1;
}

int main() {
  Node* root = NULL;
  root = buildTree(root);
  cout << "Length of tree: " << height(root);
}