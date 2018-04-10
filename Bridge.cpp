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

#include <boost/graph/adjacency_list.hpp>


bridge::bridge(std::ifstream &fin)
// Initializes a maze by reading values from fin.  Assumes that the
// number of rows and columns indicated in the file are correct.
{
 

    EdgeProperties e;
            
    int n, i, j;
    fin >> n;
            Graph::vertex_descriptor v;
            
            // Add nodes.
            for (int i = 0; i < n; i++)
            {
                v = add_vertex(g);
            }
            
            while (fin.peek() != '.')
            {
                fin >> i >> j >> e.weight;
                add_edge(i,j,e,g);
            }
    
}

void clearVisited(Graph &g){
    // Mark all nodes in g as not visited.
    typedef boost:: graph_traits<Graph>::vertex_iterator vertex_iter;
    std::pair<vertex_iter, vertex_iter> vertexPair;
    for(vertexPair=vertices(g); vertexPair.first != vertexPair.second; ++vertexPair.first)
        g[*vertexPair.first].visited=false;
}


bool bridge::isConnected(Graph &g){
// Returns true if the graph g is connected. Otherwise returns false.
    clearVisited(g);
    
    depth_first_search(g, visitor(vis).root_vertex(root_vertex_descriptor));
    
    allNodesVisited(g);
    
}


void bridge::findSpanningForest(graph &g1, graph &sf){
// Create a graph sf that contains a spanning forest on the graph g.
    
    
}

void bridge::DFS(Graph &g){// passes down the graph by reference and finds a path using DFS
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

bool bridge::isCyclic(Graph &g){
    // Returns true if the graph g contains a cycle. Otherwise, returns false.
    // Mark all the vertices as not visited and not part of recursion
    // stack
    bool *visited = new bool[V];
    bool *recStack = new bool[V];
    for(int i = 0; i < V; i++)
    {
        visited[i] = false;
        recStack[i] = false;
    }
    
    // Call the recursive helper function to detect cycle in different
    // DFS trees
    for(int i = 0; i < V; i++)
        if (isCyclicUtil(i, visited, recStack))
            return true;
    
    return false;
}

void bridge::allNodesVisited(graph &g){
    int visited=0;
    
    for (Graph::vertex_iterator vItr= vItrRange.first; vItr != vItrRange.second; ++vItr){
        if(vItr.visited) visited++;
        
        else return false;
    
}
    if(visited == num_vertices(g)) return true;
}


bool isCyclicUtil(int v, bool visited[], bool *recStack)
{
    if(visited[v] == false)
    {
        // Mark the current node as visited and part of recursion stack
        visited[v] = true;
        recStack[v] = true;
        
        // Recur for all the vertices adjacent to this vertex
        list<int>::iterator i;
        for(i = adj[v].begin(); i != adj[v].end(); ++i)
        {
            if ( !visited[*i] && isCyclicUtil(*i, visited, recStack) )
                return true;
            else if (recStack[*i])
                return true;
        }
        
    }
    recStack[v] = false;  // remove the vertex from recursion stack
    return false;
}

void  bridge::findSpanningForest(Graph &g, Graph &sf){
    // Perform a breadth-first search of unvisited nodes in graph g
    // starting at the start node.
    // Add edges to graph sf as they are discovered.
    int s=0;
    bool *visited = new bool[V];
    for(int i = 0; i < V; i++)
        visited[i] = false;
    
    // Create a queue for BFS
    list<int> queue;
    
    // Mark the current node as visited and enqueue it
    visited[s] = true;
    queue.push_back(s);
    
    // 'i' will be used to get all adjacent
    // vertices of a vertex
    list<int>::iterator i;
    
    while(!queue.empty())
    {
        // Dequeue a vertex from queue and print it
        s = queue.front();
        cout << s << " ";
        queue.pop_front();
        
        // Get all adjacent vertices of the dequeued
        // vertex s. If a adjacent has not been visited,
        // then mark it visited and enqueue it
        for (i = adj[s].begin(); i != adj[s].end(); ++i)
        {
            if (!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
                boost::add_edge(s,*i, sf);
            }
        }
    }
    
    
    
    
    
}
