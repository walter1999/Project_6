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


class bridge{
public:
    bridge(ifstream &fin);
    
    bool isConnected(Graph &g);
    // Returns true if the graph g is connected. Otherwise returns false.
    bool isCyclic(Graph &g)
    // Returns true if the graph g contains a cycle. Otherwise, returns false.
    void findSpanningForest(Graph &g1, Graph &sf)
    // Create a graph sf that contains a spanning forest on the graph g.
    void DFS(vertex::descriptor start, Graph &g)
    
private:
    int rows;
    int cols;
    



#endif /* Bridge_hpp */
