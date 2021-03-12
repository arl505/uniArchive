#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <queue>
#include <unordered_map>
using namespace std;

void generateRandomGraph(vector<vector<int>> &graph,
   int graph_size,
   int num_connections)
{
   //uncomment to allow for "random" graph generation
   //srand(time(NULL));

   //zero out graph and ensure that graph is 
  //large enough
   if (graph.size() < graph_size)
   {
      graph.resize(graph_size);
   }
   for (int i = 0; i < graph.size(); i++)
   {
      if (graph[i].size() < graph_size)
      {
         graph[i].resize(graph_size);
      }
      for (int j = 0; j < graph[i].size(); j++)
      {
         graph[i][j] = 0;
      }
   }
   for (int i = 0; i < num_connections; i++)
   {
      int x = rand() % graph_size;
      int y = rand() % graph_size;
      graph[x][y] = 1;
   }

   //zero out diagonal (do not allow self-connections)
   for (int i = 0; i < graph_size; i++)
   {
      graph[i][i] = 0;
   }
}
bool dfsConnectedSearch(vector<vector<int>>& graph, int start, int end);

bool dfsConnectedSearch(vector<vector<int>>& graph, int start, int end, vector<int>& visited)
{
    if(start == end)
    {
        return true;
    }
    visited[start] = 1;
    for(int i = 0; i < graph[start].size(); i++)
    {
        if(visited[i] == 1)
        {
            continue;
        }
        if(graph[start][i] == 1)
        {
            if(dfsConnectedSearch(graph, i, end, visited) == true)
            {
                return true;
            }
        }
        
    }
    return false;
}

bool dfsConnectedSearch(vector<vector<int>>& graph, int start, int end)
{
    vector<int> found{};
    found.resize(graph.size());
    return dfsConnectedSearch(graph, start, end, found);
}

bool bfsConnectedSearch(vector<vector<int>>& graph, int start, int end)
{
    if(start == end)
    {
        return true;
    }
    queue<int> bfsQueue;
    vector<bool> visited(graph.size(), false);
    
    bfsQueue.push(start);
    
    while(bfsQueue.empty() == false)
    {
        int top = bfsQueue.front();
        bfsQueue.pop();
        for(int i = 0; i < graph[top].size(); i++)
        {
            if(graph[top][i] == 1 && visited[i] != true)
            {
                if(i == end)
                {
                    return true;
                }
                visited[i] = true;
                bfsQueue.push(i);
            }
        }
    }
    return false;
}

int main(void)
{
   cout << boolalpha;
   vector<vector<int>> graph{};
   generateRandomGraph(graph, 10, 25);
   cout << "DFS (4,0): " << dfsConnectedSearch(graph, 4, 0) << endl;
   cout << "BFS (4,0): " << bfsConnectedSearch(graph, 4, 0) << endl << endl;
   
   cout << "DFS (7,9): " << dfsConnectedSearch(graph, 7, 9) << endl;
   cout << "BFS (7,9): " << bfsConnectedSearch(graph, 7, 9) << endl;
   return 0;
}
