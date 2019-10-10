#include <iostream>
#include <vector>
#include <utility>

using namespace std;

class Node{
private:
public:
  int v;
  bool plag;
  vector<int> child;
  void push(int n){
    child.push_back(n);
  }
  int pop(){
    int n = child.front();
    child.erase(child.begin());
    return n;
  }
  void print(){
    for(auto itr = child.begin(); itr != child.end(); itr++){
      cout<<*itr<<" ";
    }
  }

  Node(int _v){
    v = _v;
    plag = false;
  }
  Node(){}
  
};

void dfs(vector<Node> *node, int v);
void bfs(vector<Node> *node, int v);

int main(){
  int N, M, V;
  vector<Node> node;

  cin>>N>>M>>V;

  for(int i=0;i<M;i++){
    node.push_back(Node(i+1));
  }

  for(int i=0;i<M;i++){
    int v1, v2;
    cin>>v1>>v2;
    node.at(v1-1).push(v2);
  }

  // dfs(&node, V);
  // cout<<endl;
  bfs(&node, V);
  cout<<endl;

  return 0;
}

void dfs(vector<Node> *vec, int v){
  cout<<(*vec).at(v-1).v<<" ";
  (*vec).at(v-1).plag = true;

  while(!(*vec).at(v-1).child.empty()){
    int next = (*vec).at(v-1).pop();
    if(!(*vec).at(next-1).plag)
      dfs(vec, next);
  }
}

void bfs(vector<Node> *vec, int v){
  if(!(*vec).at(v-1).plag) cout<<v<<" ";
  (*vec).at(v-1).plag = true;
  Node q = Node();

  while(!(*vec).at(v-1).child.empty()){
    int next = (*vec).at(v-1).pop();
    if(!(*vec).at(next-1).plag){
      q.push(next);
      cout<<next<<" ";
      (*vec).at(next-1).plag = true;
    }
  }
  while(!q.child.empty()){
    bfs(vec, q.pop());
  }
}

/**
4 5 1
1 2
1 3
1 4
2 4
3 4
*/