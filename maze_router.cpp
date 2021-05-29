#include<iostream>
#include "Graph.h"
using namespace std;
#define SIZE 20000

/*
    This function takes a coordinate pair of X,Y in the grid (this will be input from the user and we need to convert it work on our graph)
    It returns the number of the node in the graph by this equation: 100 * Y + X
*/
int take_pair_return_node(int X, int Y){
    int node;    
    node = 100 * Y + X;
    return node;
}





/*
    This function takes a node number from the user and returns its coordinates on the plane and returns the layer number
    Logic:
        It makes mod%100 to get the X-coordinate 
        and it counts how many 100s in the number to get the Y-coordinate
    And it decides on the layer accroding to whether Y is > 00 or not
     
    This function will be used after the djikstra gets the shortest path to display it to the user
*/
void take_node_return_pair(int num, int &X, int &Y, int &layer){
    X = num % 100;
    
    int counter = 0;
    while(num>=100){
        num = num - 100;
        counter++;       
    }
    Y = counter;
    

    //Decide layer 1 or layer 2
    layer = 1;
    if (Y > 100){
        layer = 2;
    }

}

/*
    Function
    Input: takes the source node 
    It traverses the other nodes in the graph and set the costs on them
*/

void establish_cost_network(Graph grid_network){
    for(int node = 0;node<20000;node++){
        
    for (int i = 0; i < SIZE; i++){
    //cout << "INSIDE LOOP: " << i << endl;
        if (node < 10000){
            if ((!(node % 99 == 0)) || node == 0){
                grid_network.addCostedEdge(node, node+1, 1);
            }
            if (!(node % 100 == 0)){
                grid_network.addCostedEdge(node, node-1, 1);
            }
            if (node < 9900){
                grid_network.addCostedEdge(node, node+100, 10);
            }
            if (node < 99){
                grid_network.addCostedEdge(node, node-100, 10);
            }   
            grid_network.addCostedEdge(node, node+10000, 10);

        } else if (node >= 10000){
            if (!(node % 99 == 0)){
                grid_network.addCostedEdge(node, node+1, 10);
            }
            if (!(node % 100 == 0)){
                grid_network.addCostedEdge(node, node-1, 10);
            }
            if (node < 10099) {            
                grid_network.addCostedEdge(node, node-100, 1);
            }
            if (node < 19900){
                grid_network.addCostedEdge(node, node+100, 1);
            }
            


            grid_network.addCostedEdge(node, node-10000, 10);
        }
     }
    
}}


int main(){

   
       	//take the input from the user [source, target]

    cout << "Enter the source coordinates: " << endl;
    int x,y;
    cin >> x;
    cin >> y;

    int source_node = take_pair_return_node(x,y);    


    cout << "Enter the target coordinates: " << endl;
    
    cin >> x;
    cin >> y;

    int target_node = take_pair_return_node(x,y);    


    cout << "src: " << source_node << endl << "dest: " << target_node << endl;

//Create Graph [20000 = (100 * 100) * 2]
    Graph grid_network(SIZE);
    establish_cost_network(grid_network);
    //grid_network.addCostedEdge(1,0, 10);
    grid_network.printWithCosts();
}
