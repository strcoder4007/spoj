#include <iostream>
#include <map>
using namespace std;
class node{
public:
  int value;
  node *left;
  node *right;
};

int *A,*B,*C;
map<int,int> m1;
map<int,int> m2;
map<int,int> m3;

bool makeTree( node *curr, int inStart, int inEnd, int preStart, int preEnd ){
  if(inEnd-inStart!=preEnd-preStart)
    return false;
  bool b1,b2;
  b1=b2=true;
  curr->value = A[preStart];
  curr->left = NULL;
  curr->right = NULL;
  if(preStart==preEnd)
    return true;
  if( m3[A[preStart]]!=inStart ){
    curr->left= new node;
    b1 = makeTree(curr->left,inStart,m3[A[preStart]]-1,preStart+1,m1[C[m3[A[preStart]]-1]]);
  }
  if(m3[A[preStart]]!=inEnd){
    curr->right = new node;
    b2 = makeTree(curr->right,m3[A[preStart]]+1,inEnd,m1[C[m3[A[preStart]]+1]],preEnd);
  }
  return b1 && b2;
}

bool postOrder(node *curr){
  static int counter=0;
  bool b1,b2;
  b1=b2=true;
  if(curr->left!=NULL)
    b1=postOrder(curr->left);
  if(curr->right!=NULL)
    b2=postOrder(curr->right);
  return curr->value==B[counter++] && b1 && b2;
}

int main(){
  int N,i,j,k;
  node *root;
  cin>>N;
  A = new int[N];
  B = new int[N];
  C = new int[N];
  for(i=0;i<N;i++){
    cin>>A[i];
    m1[A[i]]=i;
  }
  for(i=0;i<N;i++){
    cin>>B[i];
    m2[B[i]]=i;
  }
  for(i=0;i<N;i++){
    cin>>C[i];
    m3[C[i]]=i;
  }
  root = new node;
  if(!makeTree(root,0,N-1,0,N-1)){
    cout<<"no"<<endl;
    return 0;
  }
  if(postOrder(root))
    cout<<"yes"<<endl;
  else
    cout<<"no"<<endl; 
  return 0;
}