/*

       CSS 355
       Fall Semester, 2019

       Project on graoh theory


       Programmed by: Surya,Kirstie,Mary
       Due: 26 November 2019

*/
#include<bits/stdc++.h> 
#include <iostream> 
#include <fstream>
#include <unordered_map>		//Add this in your compiler seperately by putting -std=c++11 in the compiler settings 
#include "Graph.cpp"
using namespace std; 
int main(){	
   
   
   int choice=0;
   
   
   Graph<string> friends;
   friends.menu();
   cin>>choice;
    string friendss[10]={"Surya","Phil","Kirstie","Mary","Luke","Judson"};
    friends.addEdge(friendss[0],friendss[1],2);
    friends.addEdge(friendss[0],friendss[2],8);
    friends.addEdge(friendss[2],friendss[3],1);
    friends.addEdge(friendss[1],friendss[4],2);
    friends.addEdge(friendss[4],friendss[5],3);
    friends.addEdge(friendss[0],friendss[5],4);
    friends.addEdge(friendss[3],friendss[5],5);
    
    do{
    switch(choice)
	{
	case 1:friends.dijsktraSSSP("Surya");   //Node starts from here
		   break;
    case 2:friends.printAdj();
    	   break;
	case 9:cout<<"Thank You"<<endl;
		   exit(0);
		   break;
	default:cout<<"Wrong choice"<<endl;
		
	}
friends.menu();
cin>>choice;
	}while(choice!=9);


 return 0;
}

