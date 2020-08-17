#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <string>

using namespace std;

struct Node{
  int val;
  Node *left;
  Node *right;
  Node(){
    val = 0;
    left = NULL;
    right = NULL;
  }
};

string preord(Node *root){
  string ans = "";
  ans += "V";
  if(root->left){
    ans += "L";
    ans += preord(root->left);
    ans += "l";
  }
  if(root->right){
    ans += "R";
    ans += preord(root->right);
    ans += "r";
  }
  ans += "v";
  return ans;
}

void remove(Node *root){
  if(root->left){
    remove(root->left);
  }
  if(root->right){
    remove(root->right);
  }
  delete root;
}

int n, k;

int main(void){
  scanf("%d %d",&n,&k);
  set<string> bst;
  vector<int> inp(k);
  while(n--){
    for(int i = 0 ; i < k ; i++)
      scanf("%d",&inp[i]);

    Node *root = new Node;
    root->val = inp[0];
    for(int i = 1 ; i < k ; i++){
      Node *cur = root;
      while(true){
        if(cur->val > inp[i]){
          if(cur->left == NULL){
            cur->left = new Node;
            cur->left->val = inp[i];
            break;
          }
          else{
            cur = cur->left;
          }
        }

        else if(cur->val < inp[i]){
          if(cur->right == NULL){
            cur->right = new Node;
            cur->right->val = inp[i];
            break;
          }
          else{
            cur = cur->right;
          }
        }

        else{
          break;
        }
      }
    }


    bst.insert(preord(root));
    remove(root);
  }
  printf("%lu\n",bst.size());
  return 0;
}
/* 생성자 활용
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <set>

using namespace std;

int inp[21];

struct Node{
  int val;
  Node *left;
  Node *right;
  Node(){
    val = 0;
    left = NULL;
    right = NULL;
  }
  Node(int x){
    val = x;
    left = NULL;
    right = NULL;
  }
};

string preord(Node *root){
  string ans = "";
  ans += "V";
  if(root->left){
    ans += "L";
    ans += preord(root->left);
    ans += "l";
  }
  if(root->right){
    ans += "R";
    ans += preord(root->right);
    ans += "r";
  }
  ans += "v";
  return ans;
}

void remove(Node *root){
  if(root->left){
    remove(root->left);
  }
  if(root->right){
    remove(root->right);
  }
  delete root;
}

int main(void){
  int n,k;
  scanf("%d %d",&n,&k);

  set<string> bst;

  while(n--){
    for(int i = 0 ; i < k ; i++)
      scanf("%d",&inp[i]);

    Node *root = new Node(inp[0]);
    for(int i = 1 ; i < k ; i++){
      Node *cur = root;
      while(true){
        if(cur->val > inp[i]){
          if(cur->left == NULL){
            cur->left = new Node(inp[i]);
            break;
          }
          else{
            cur = cur->left;
          }
        }
        else{
          if(cur -> right == NULL){
            cur->right = new Node(inp[i]);
            break;
          }
          else{
            cur = cur -> right;
          }
        }
      }
    }

    bst.insert(preord(root));
    remove(root);
  }

  printf("%lu\n",bst.size());
  return 0;
}
*/
