//
//  Bridge.hpp
//  Project6
//
//  Created by Tommy Campion on 4/6/18.
//  Copyright © 2018 Tommy Campion. All rights reserved.
//

#ifndef Bridge_hpp
#define Bridge_hpp

#include <stdio.h>
#include <iostream>
#include <limits.h>
#include <list>
#include <fstream>
#include <queue>
#include <vector>
#include <stack>
#include <boost/graph/adjacency_list.hpp>
#include "d_except.h"
#include "matrix.h"

class bridge
{
  public:
    bridge(ifstream &fin, Graph &g);
    
    bool isConnected(graph &g);
    // Returns true if the graph g is connected. Otherwise returns false.
    bool isCyclic(graph &g);
    // Returns true if the graph g contains a cycle. Otherwise, returns false.
    void findSpanningForest(graph &g1, graph &sf);
    // Create a graph sf that contains a spanning forest on the graph g.
    void DFS();
    bool allNodesVisited(Graph g);

    bool dfs(Graph::vertex_descriptor start, Graph &g, Graph::vertex_descriptor previous); 
private:
   bool isCyclicUtil(int v, bool visited[], bool *rs);  // used by isCyclic()
   list<int> *adj;// Pointer to an array containing adjacency lists

};
#endif /* Bridge_hpp */
