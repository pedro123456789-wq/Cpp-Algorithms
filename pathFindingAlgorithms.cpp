#include <iostream>
#include <map>
#include <list>
#include <string>
using namespace std;

const int INF = 999999999;

class Node{
  private:
    string name;
    string previousNode;
    int distance = INF;
    boolean isVisited = false;
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
      distance = newDistance
    }
    
    boolean getVisited(){
      return isVisited;
    }
    
    void setVisited(boolean newState){
      isVisited = newState;
    }
    
    void addConnection(string newNode, int connection){
      children[newNode] = connection;
    }
    
    map<string, int> getConnections(){
      for (auto const& [key, val] : children){
        cout << key << ":" << val << endl;
      }
      
      return children;
    }
};


void getNextNode(list<Node> nodes){
  int minimum = INF;
  
  for (auto const& i : nodes) {
    
  }
}
void dikstrasAlgorithm(list<Node> nodes){
  nodes[0].setDistance(0);
  
  
}


int main(){
  list<Node> nodes;
  
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
  
  
  
  a.getConnections();
}
