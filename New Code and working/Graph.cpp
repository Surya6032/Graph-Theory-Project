// Program to find Dijkstra's shortest path using 
// priority_queue in STL 
#include<bits/stdc++.h> 
#include <iostream> 
#include <fstream>
#include <unordered_map>   //Add this in your compiler seperately by putting -std=c++11 in the compiler settings 
using namespace std; 

  


template<typename T>
class Graph{
    unordered_map<T, list<pair<T,int> > > m;   //m is the hash map
    
public:

//**********************************************************************************************************
//Function: addEdge
//Purpose:  This function adds edges 
//Incoming: u,v,dist,bidir    //bidir->bi directional, edge starts at u and ends at v
//Outgoing: None
//Return:   choice
//********************************************************************************************************
    void addEdge(T u,T v,int dist,bool bidir=false){
        m[u].push_back(make_pair(v,dist)); 
        if(bidir){
            m[v].push_back(make_pair(u,dist));
        }
        
    }
//**********************************************************************************************************
//Function: printAdj
//Purpose:  This function prints the adjacency list
//Incoming: None
//Outgoing: None
//Return:   None
//********************************************************************************************************
    void printAdj(){
        // print the adj list
        //Iterate over all the key value pairs in the map 
        for(auto j:m){											// Range based for loop
            
            cout<<j.first<<"->";								//Revers to the first key which is Surya
            
            //Iterater over the list of friends
            for(auto l: j.second){
                    cout<<"("<<l.first<<","<<l.second<<")";   //l.first gives the friends name and l.second gives the weight
                
            }
            cout<<endl;
        }
    
    }

//**********************************************************************************************************
//Function: dijstraSSSP
//Purpose:  This function implements Dijstra algorithm
//Incoming: T src
//Outgoing: None
//Return:   None
//********************************************************************************************************
    void dijsktraSSSP(T src){
        
        unordered_map<T,int> dist;
        
        //Set all distance to infinity
        for(auto j:m){
            dist[j.first] =1000;
        }
        
        //Make a set to find a out node with the minimum distance
        set<pair<int, T> > s;
        
        dist[src] = 0;					//Distance of starting node or the source node will be zero
        s.insert(make_pair(0,src));
        
        while(!s.empty()){
            
            //Find the pair at the front.
            auto p =   *(s.begin());
            T node = p.second;         //denotes the node
            
            int nodeDist = p.first;
            s.erase(s.begin());
            
            
            //Iterate over neighbours/children of the current node
            for(auto childPair: m[node]){
                
                if(nodeDist + childPair.second < dist[childPair.first]){
                    
                    
                    //In the set updation of a particular is not possible
                    // we have to remove the old pair, and insert the new pair to simulation updation
                    T dest = childPair.first;
                    auto f = s.find( make_pair(dist[dest],dest));
                    if(f!=s.end()){
                        s.erase(f);
                    }
                    
                    //Insert the new pair
                    dist[dest] = nodeDist + childPair.second;
                    s.insert(make_pair(dist[dest],dest));
                    
                }
                
            }
        }
        //Lets print distance to all other node from src
        for(auto d:dist){
            
            cout<<d.first<<" distance from Node: "<<d.second<<endl;
        }
        
        
    }
	 
//**********************************************************************************************************
//Function: Menu
//Purpose:  This function creates a menu
//Incoming: None
//Outgoing: None
//Return:   None
//********************************************************************************************************
    void menu()
	{
    	cout<<"Enter choice"<<endl;
    	cout<<"1: Print people on the network"<<endl;
    	cout<<"2: Print the shortest paths between friends"<<endl;
    	cout<<"3: Print the adjacency list"<<endl;
    	cout<<"9: Exit"<<endl;
    
	}


};
