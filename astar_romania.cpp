#include <bits/stdc++.h> // for min and max functions and others 
using namespace std;  

#define DISCONNECTED -1 // for the matrix of the graph  (disconnected)  
int num_of_node,num_of_edge,graph[30][30],pathCost[30]; // for the graph  (num_of_node = number of nodes, num_of_edge = number of edges) 
void init_Heuristic(); // for the heuristic function  (init_Heuristic = initialization of the heuristic function)

struct Node{  // for the node  
    int from,to; // for the node's from and to  
    int cost;   // for the node's cost   
};
struct CompareNode{ // for the compare function 
    bool operator()(Node& n1, Node& n2){ // for the compare function  (n1 = node 1, n2 = node 2)
        if(n1.cost > n2.cost)return true;
        else return false;  
        return false; 
    }
};
map<int,int>Heuristic; // for the heuristic function  
priority_queue<Node, vector<Node>, CompareNode> PQ; // for the priority queue  (PQ = priority queue)
vector<Node>path; 
void AStarSearch(int source,int destination){ // for the A* search algorithm  (AStarSearch = A* search algorithm)

    init_Heuristic(); // initialization of the heuristic function
    for(int i = 1; i <= num_of_node; i++){ // for the nodes 
        if(graph[source][i] != DISCONNECTED){ // if the edge is not disconnected
            Node n; // for the node    
            n.from = source; // the source node  
            n.to = i; // the destination node   
            n.cost = graph[source][i] + Heuristic[i]; //  the cost of the edge  = the cost of the edge + the heuristic function
            pathCost[i] = graph[source][i]; // the cost of the path from the source node to the destination node  = the cost of the edge  
            PQ.push(n); // push the node to the priority queue  (PQ = priority queue)  (n = node)  (push = push the node to the priority queue)  (push = push the node to the priority queue)  
        }
    }
    while(!PQ.empty()){ // while the priority queue is not empty  (PQ = priority queue)  (empty = empty)  
        Node tmp = PQ.top(); // for the node  (tmp = node)  (top = top of the priority queue)  (top = top of the priority queue)  
        path.push_back(tmp); // push the node to the path  (path = path)  (push_back = push the node to the path)  (push_back = push the node to the path)  (tmp = node)  
        if(tmp.to == destination)break; //  if the destination node is reached  (tmp.to = destination)  (break = break)  (break = break)   
        PQ.pop(); // pop the node from the priority queue  (PQ = priority queue)  (pop = pop the node from the priority queue)  (pop = pop the node from the priority queue)
        for(int i = 1; i <= num_of_node; i++){ // for the nodes  
            if(graph[tmp.to][i] != DISCONNECTED){ // if the edge is not disconnected   
                Node n; // for the node     
                n.from = tmp.to; // the source node = the destination node of the previous node    
                n.to = i; // the destination node    
                n.cost = pathCost[tmp.to] + graph[tmp.to][i] + Heuristic[i]; // the cost of the edge = the cost of the path from the source node to the destination node + the cost of the edge + the heuristic function  
                pathCost[i] = pathCost[tmp.to] + graph[tmp.to][i]; // the cost of the path from the source node to the destination node = the cost of the path from the source node to the destination node + the cost of the edge     
                PQ.push(n); // push the node to the priority queue  (PQ = priority queue)  (n = node)  (push = push the node to the priority queue)  (push = push the node to the priority queue)   
            }
        }
    }
}
int main(){ // for the main function  

    int a,b,c,source,destination;  // for the nodes  (a = node, b = node, c = cost, source = source node, destination = destination node)  

    cout << "Enter Node: " << endl; // enter the node 
    cin >> num_of_node; // enter the node  (num_of_node = number of nodes) 
    cout << "Enter Edge: " << endl; // enter the edge  (num_of_edge = number of edges)  
    cin >> num_of_edge; // enter the edge  
    for(int i=1; i<=num_of_node; i++) 
  for(int j=1; j<=num_of_node; j++) 
   graph[i][j] = DISCONNECTED; // 

    for(int i = 0; i < num_of_edge; i++){ //  for the edges   
        cin >> a >> b >> c; // enter the edge  (a = node, b = node, c = cost)  
        graph[a][b] = graph[b][a] = c; // the cost of the edge = the cost of the edge 
    }
    cout << "Enter source: " << endl; // enter the source node  (source = source node)   
    cin >> source; // enter the source node 
    cout << "Enter destination: " << endl; // enter the destination node  (destination = destination node)
    cin >> destination; // enter the destination node  
    AStarSearch(source,destination); 
    for(int i = 0; i < path.size(); i++) // for the path  
        cout << path.at(i).from << " -> " << path.at(i).to << " = " << path.at(i).cost << endl; // print the path  
    return 0; 
}
void init_Heuristic(){ 

    //straight line distance //

    Heuristic[1] = 380;  // Oradea
    Heuristic[2] = 374;  // Zerind
    Heuristic[3] = 253;  // Sibiu
    Heuristic[4] = 366;   // Arad
    Heuristic[5] = 329;   // Timisoara
    Heuristic[6] = 193;   // Rimnicu Vilcea
    Heuristic[7] = 176;   // Fagaras
    Heuristic[8] = 244;   // Lugoj
    Heuristic[9] = 241;   // Mehadia
    Heuristic[10] = 242;   // Drobeta
    Heuristic[11] = 160;   // Craiova
    Heuristic[12] = 100;   // Pitesti
    Heuristic[13] = 0;    // Bucharest
    Heuristic[14] = 77; // Giurgiu
    Heuristic[15] = 80; // Urziceni
    Heuristic[16] = 151; // Hirsova
    Heuristic[17] = 161; // Eforie
    Heuristic[18] = 199; // Vaslui
    Heuristic[19] = 226; // Iasi
    Heuristic[20] = 234; // Neamt
}
/* THE INPUT VALUES FOR THE MAP OF ROMANIA ARE AS FOLLOWS: - 
/*
20 23
1 2 71
1 3 151
2 4 75
3 6 80
3 7 99
3 4 140
4 5 118
5 8 111
6 11 146
6 12 97
7 13 211
8 9 70
9 10 75
10 11 120
11 12 138
12 13 101
13 14 90
13 15 85
15 16 98
15 18 142
16 17 86
18 19 92
19 20 87
*/


