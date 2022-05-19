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
    string previousNode = "null";
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



class Graph{
  private:
    vector<Node> nodes;

    int getNode(string name, vector<Node> nodes){
      int index = 0;
  
      for (auto &node : nodes){
        if (node.getName() == name){
          return index;
        }
        
        index ++;
      }
      
      return -1;
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
      
      return nodes[getNode(currentNode, nodes)];
    }
    
    
    bool hasNodes(vector<Node> nodes){
      for (auto &node : nodes){
        if (!node.getVisited()){
          return true;
        }
      }
  
      return false;
    }
    
    
    string reverseString(string target){
      string reversed;
      
      for(int n = target.length() -1 ; n >= 0; n--){
        reversed.push_back(target[n]);
      }
      
      return reversed;
    }
  
  
  public:
    void dikstrasAlgorithm(vector<Node> nodes){
      // set distance to root node as zero
      nodes[0].setDistance(0);
      bool isRunning = true;
      
      while (hasNodes(nodes)){
        // change nodes list directly to fix bug
        Node parentNode = getNextNode(nodes);
        int parentIndex = getNode(parentNode.getName(), nodes);
        
        for (auto &[nodeName, distance] : parentNode.getConnections(false)){
          int newDistance = parentNode.getDistance() + distance;
          int nodeIndex = getNode(nodeName, nodes);
          
          Node childNode = nodes[nodeIndex];
          
          if (newDistance < childNode.getDistance()){
            nodes[nodeIndex].setDistance(newDistance);
            nodes[nodeIndex].setPreviousNode(parentNode.getName());
          }
        }
        nodes[parentIndex].setVisited(true);
      }
      
      
      // output paths and distances
      for (int i = 0; i < 6; i ++){
        cout << "Node: " << nodes[i].getName() << endl;
        cout << "Minimum Distance: " << nodes[i].getDistance() << endl;
        
        string pathString;
        Node currentNode = nodes[i];
        bool hasPrevious = true;
        
        while (hasPrevious){
          pathString.append(currentNode.getName());
          
          int previousIndex = getNode(currentNode.getPreviousNode(), nodes);
          
          if (previousIndex != -1){
            currentNode = nodes[getNode(currentNode.getPreviousNode(), nodes)];
          }else{
            hasPrevious = false;
          }
        }
        
        cout << reverseString(pathString) << "\n" << endl;
      }
    }
};



















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
  nodes.push_back(f);
  
  Graph graph = Graph();
  graph.dikstrasAlgorithm(nodes);
}
