#include <iostream>
#include <limits.h>
#include <vector>
#include <list>
#include <fstream>
#include <queue>
#include " bridge.hpp"

#include <boost/graph/adjacency_list.hpp>

using namespace boost;
using namespace std;

struct VertexProperties;
struct EdgeProperties;

typedef adjacency_list<vecS, vecS, bidirectionalS, VertexProperties, EdgeProperties> Graph;

struct VertexProperties
{
   
   int  *pred; // predecessor node
   int  weight;
   bool visited;
   bool marked;
};

// Create a struct to hold properties for each edge
struct EdgeProperties
{
   int  weight;
   bool visited;
   bool marked;
};

typedef adjacency_list<vecS, vecS, bidirectionalS, VertexProperties, EdgeProperties> Graph;

// typedef property<edge_weight_t, int> EdgeProperty;



   
int main()
{
   try
   {
      ifstream fin;

      // Read the maze from the file.
      string fileName = "yourpath/maze1.txt";
      
      fin.open(fileName.c_str());
      if (!fin)
      {
         cerr << "Cannot open " << fileName << endl;
         exit(1);
      }
      
      Graph g;
      Graph sf;
      bridge m(fin,g );
      fin.close();
      bridge.findSpanningForest(g,sf);
      if(bridge.isCyclic(g))
      std::cout<<" The graph contains cycles "<<std:endl;
      else 
      std::cout<<" The graph does not contain any cycles "<<std:endl;
     

     
   }
}