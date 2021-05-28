#pragma once

#include <iostream>

#include <vector>

using namespace std;



struct  edge{

	int source;

	int destination;



};



class Graph

{

private:

	int** adjacency_matrix;

	int vertices_number;

    void DFSRec(int vertex, vector<bool>& visited);



public:

    Graph(int size);

    ~Graph();

    void addEdge(int source, int destination);

    void addEdge(edge myedge);

    void addcostedEdge(int source, int destination, int cost); // those are for the sake of testing

    void addcostedEdge(edge myedge, int cost);  // those are for the sake of testing

    void deleteEdge(int source, int destination);

    void deleteEdge(edge myedge);

    int sumOfLags();

    int getcost(int source,int destination);

    int getcost(edge myedge);



    int getNumberOfIncomingEdges(int vertex);

    int getNumberOfOutgoingEdges(int vertex);

    vector<int> getIncomingNodes(int vertex);

    bool checkAndDelete(int source, int destination, int cost);

    bool isAllconnected();

    bool isConnected(int vertex);

    void DFS();

    void BFS();

    void print();

    void printWithcosts();

};

