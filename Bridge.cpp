//
//  Bridge.cpp
//  Project6
//
//  Created by Tommy Campion on 4/6/18.
//  Copyright © 2018 Tommy Campion. All rights reserved.
//

#include "Bridge.hpp"
#include <iostream>
#include <limits.h>
#include <list>
#include <fstream>
#include <queue>
#include <vector>
#include <stack>
#include "d_except.h"
#include "matrix.h"
#include <boost/graph/adjacency_list.hpp>


bridge::bridge(std::ifstream &fin)
// Initializes a maze by reading values from fin.  Assumes that the
// number of rows and columns indicated in the file are correct.
{
    fin >> rows; // reads rows from file
    fin >> cols; // reads cols from file
    
    char x; // variable to hodl values
    
    value.resize(rows,cols); // resize the matrix
    for (int i = 0; i <= rows-1; i++)//  traverse matrix to store bool values
        for (int j = 0; j <= cols-1; j++)
        {
            fin >> x;
            if (x == 'O')// checks to see if spot is empty. Not a wall
                value[i][j] = true;
            else
                value[i][j] = false;// make false if X is detected
        }
    
}

void clearVisited(graph &g){
    // Mark all nodes in g as not visited.
    typedef boost:: graph_traits<graph>::vertex_iterator vertex_iter;
    std::pair<vertex_iter, vertex_iter> vertexPair;
    for(vertexPair=vertices(g); vertexPair.first != vertexPair.second; ++vertexPair.first)
        g[*vertexPair.first].visited=false;
}


bool bridge::isConnected(graph &g){
// Returns true if the graph g is connected. Otherwise returns false.
    
}
bool bridge::isCyclic(graph &g){
// Returns true if the graph g contains a cycle. Otherwise, returns false.
    
}
void bridge::findSpanningForest(graph &g1, graph &sf){
// Create a graph sf that contains a spanning forest on the graph g.
    
}

void bridge::DFSS(Graph &g){// passes down the graph by reference and finds a path using DFS
    Graph:: vertex_descriptor Dr;
    Graph:: vertex_descriptor first;
    first= graphM[0][0];
    
    if (!g[first].visited){// checks if the first node has been visited
        DFS.push(first);// pushes it into the stack
        while(!DFS.empty()){// checks if the stack is empty
            Dr= DFS.pop();
            if(!g[Dr].visited){
                //visit(DR)
                g[Dr].visted= true;
                std::pair<adjacency_iterator, adjacency_iterator> neighbors =
                boost::adjacent_vertices(vertex(Dr,g), g);
                for(neighbors.first != neighbors.second; ++neighbors.first)// loop that checks the neighbors around vertex Dr
                {
                    if(!g[*neighbors.first].visited){
                        DFS.push(*neighbors.first);
                        g[*neighbors.first].predecessor=Dr;// sets the predecessor to the parent node
                    }
                }
                
            }
            
            
            
        }
    }
}
