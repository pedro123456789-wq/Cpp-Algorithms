using namespace std;
#include <iostream>
#include <map>
#include <list>
#include <string>
#include <vector>


int const INF = 999999999;


class Node{
  private:
    string name;
    string previousNode;
    int distance = INF;
    bool isVisited = false;
    map<string, int> children;
    
  public:
    Node(string newName){
      name = newName;
    }
    
    string getName(){
      return name;
    }
    
    
    string getPreviousNode(){
      return previousNode;
    }
    
    
    void setPreviousNode(string newNode){
      previousNode = newNode;
    }
    
    int getDistance(){
      return distance;
    }
    
    void setDistance(int newDistance){
      distance = newDistance;
    }
    
    bool getVisited(){
      return isVisited;
    }
    
    void setVisited(bool newState){
      isVisited = newState;
    }
    
    void addConnection(string newNode, int connection){
      children[newNode] = connection;
    }
    
    map<string, int> getConnections(bool isShow){
      if (isShow){
        for (auto const &[key, val] : children){
          cout << key << ":" << val << endl;
        }
      }
      
      return children;
    }
};



Node getNode(string name, vector<Node> nodes){
  for (auto &node : nodes){
    if (node.getName() == name){
      return node;
    }
  }
}


Node getNextNode(vector<Node> nodes){
  int minimum = INF;
  string currentNode;
  
  for (auto &node : nodes) {
    int nodeDistance = node.getDistance();
    
    if (nodeDistance < minimum && !node.getVisited()){
      currentNode = node.getName();
      minimum = nodeDistance;
    }
  }
  
  
  return getNode(currentNode, nodes);
}


bool hasNodes(vector<Node> nodes){
  for (auto &node : nodes){
    // cout << node.getName() << ":" << node.getVisited() << endl;
    
    if (!node.getVisited()){
      return true;
    }
  }
  
  cout << "\n\n\n" << endl;
  
  return false;
}

void dikstrasAlgorithm(vector<Node> nodes){
  // set distance to root node as zero
  nodes[0].setDistance(0);
  bool isRunning = true;
  
  while (hasNodes(nodes)){
    cout << "iteration completed" << endl;
    // change nodes list directly to fix bug
    Node parentNode = getNextNode(nodes);
    
    for (auto &[nodeName, distance] : parentNode.getConnections(false)){
      int newDistance = parentNode.getDistance() + distance;
      Node childNode = getNode(nodeName, nodes);
      
      if (newDistance < childNode.getDistance()){
        childNode.setDistance(newDistance);
        childNode.setPreviousNode(parentNode.getName());
      }
    }
    
    parentNode.setVisited(true);
    cout << parentNode.getVisited() << endl;
  }
}



int main(){
  vector<Node> nodes;
  
  Node a = Node("A");
  Node b = Node("B");
  Node c = Node("C");
  Node d = Node("D");
  Node e = Node("E");
  Node f = Node("F");
  
  a.addConnection("B", 7);
  a.addConnection("C", 12);
  
  b.addConnection("D", 9);
  b.addConnection("C", 2);
  
  c.addConnection("E", 10);
  
  d.addConnection("F", 1);
  
  e.addConnection("D", 4);
  e.addConnection("F", 5);
  
  nodes.push_back(a);
  nodes.push_back(b);
  nodes.push_back(c);
  nodes.push_back(d);
  nodes.push_back(e);
  
  cout << nodes[0].getName() << endl;
  dikstrasAlgorithm(nodes);
}
