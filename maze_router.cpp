#include<iostream>
using namespace std;


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

int main(){
/*
    int X, Y, layer = 0;
    take_node_return_pair(9999, X, Y, layer);
    cout << "X: " << X << endl << "Y: " << Y << endl << "layer: " << layer << endl;
*/
    int X = 2;
    int Y = 1;
    
    cout << take_pair_return_node(X, Y);
}
