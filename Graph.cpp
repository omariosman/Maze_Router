#include "Graph.h"







Graph::Graph(int size) {



	vertices_number = size;



	adjacency_matrix = new int* [size];



	for (int i = 0; i < size; i++) 



		adjacency_matrix[i] = new int[size];







	for (int i = 0; i < size; i++)



		for (int j = 0; j < size; j++)



			adjacency_matrix[i][j] = 0;







}



/*

Graph::~Graph() {

	for (int i = 0; i < vertices_number; i++)

		delete[] adjacency_matrix[i];

	delete [] adjacency_matrix;

}

*/



void Graph::addEdge(int source, int destination){







	if (source >= 0 && source < vertices_number && destination >= 0 && destination < vertices_number)



		adjacency_matrix [source][destination] = 1;







}











void Graph::addEdge(edge myedge){







	if (myedge.source >= 0 && myedge.source < vertices_number && myedge.destination >= 0 && myedge.destination < vertices_number)



		adjacency_matrix[myedge.source][myedge.destination] = 1;







}











void Graph::addCostedEdge(int source, int destination, int Cost) {







	if (source >= 0 && source < vertices_number && destination >= 0 && destination < vertices_number)



		adjacency_matrix[source][destination] = Cost;







}







void Graph::deleteEdge(int source, int destination) {







	if (source >= 0 && source < vertices_number && destination >= 0 && destination < vertices_number)



		adjacency_matrix[source][destination] = 0;











}











void Graph::deleteEdge(edge myedge) {



	if (myedge.source >= 0 && myedge.source < vertices_number && myedge.destination >= 0 && myedge.destination < vertices_number)



		adjacency_matrix[myedge.source][myedge.destination] = 0;











}







int Graph::sumOfLags() {



	int sum = 0;



	



	for (int i = 0; i < vertices_number; i++) {



		for (int j = 0; j < vertices_number; j++)



			sum = sum + adjacency_matrix[i][j];



	}











	return sum;



}







int Graph::getCost(int source, int destination) {







	return adjacency_matrix[source][destination];



}







int Graph::getCost(edge myedge){



	return adjacency_matrix[myedge.source][myedge.destination];



}







void Graph::addCostedEdge(edge myedge, int Cost){







	if (myedge.source >= 0 && myedge.source < vertices_number && myedge.destination >= 0 && myedge.destination < vertices_number)



		adjacency_matrix[myedge.source][myedge.destination] = Cost;







}







bool Graph::checkAndDelete(int source, int destination, int Cost) {



	



	for (int i = 0; i < vertices_number; i++) {



		for (int j = 0; j < vertices_number; j++) {



			if (adjacency_matrix[i][j] > Cost)



			{



				deleteEdge(i, j);



				addEdge({source,destination});



				if (isAllconnected())



					return true;







			}







		}







	}







	return false;











}















int Graph::getNumberOfIncomingEdges(int vertex){







	if (vertex < vertices_number && vertex >= 0) {



		



		int count(0);



		for (int i = 0; i < vertices_number; i++) {



			if (adjacency_matrix[i][vertex] > 0)



				count++;







		}



		return count;



	}







	return -1;











}











int Graph::getNumberOfOutgoingEdges(int vertex){







	if (vertex < vertices_number && vertex >= 0) {







		int count(0);



		for (int i = 0; i < vertices_number; i++) {



			if (adjacency_matrix[vertex][i] > 0)



				count++;



		}







		return count;



	}







	return -1;







}







bool Graph::isAllconnected() {



	







	for (int i = 0; i < vertices_number; i++) {



		for (int j = 0; j < vertices_number; j++) {



			if (!isConnected(i))



				return false;



		}



	}







	return true;











}











vector<int> Graph::getIncomingNodes(int vertex){



	vector<int> res;



for (int i=0;i<vertices_number;i++)



	if (adjacency_matrix[i][vertex]==1)



		res.push_back(i);











return res;











}











bool Graph ::isConnected(int vertex) {







	for (int i = 0; i < vertices_number; i++) {



		if (adjacency_matrix[vertex][i] != 0)



			return true;



	}







	return false;







}







void Graph::DFSRec(int vertex, vector<bool>& visited) {







	if (visited[vertex] == true)



		return;



	visited[vertex] = true;



	cout << vertex << " ";







	for (int i = 0; i < vertices_number; i++) {



		



		if (adjacency_matrix[vertex][i] > 0)



			DFSRec(i,visited);







	}















}







void Graph::DFS(){



	



	vector<bool> visited;



	visited.resize(vertices_number, false);



	for (int i = 0; i < vertices_number; i++)



		if (isConnected(i))



			DFSRec(i, visited);







}











void Graph::BFS(){







	vector <bool> visited;



	visited.resize(vertices_number);







	for (int i = 0; i < vertices_number; i++) {







		if (isConnected(i)) {



			if (visited[i] == false) {



				cout << i << " ";



				visited[i] = true;







				for (int j = 0; j < vertices_number; j++) {







					if (adjacency_matrix[i][j] > 0) {







						if (visited[j] == false) {







							cout << j << " ";



							visited[j] = true;



						}



					}







				}











			}







		}







	}















}











void Graph::print(){



	



	for (int i = 0; i < vertices_number; i++) {



	



		if (isConnected(i))



			



			for (int j = 0; j < vertices_number; j++) {



			



				if (adjacency_matrix[i][j]>0)



					cout << "Source: " << i << "    "<< "Destination: "<< j<<endl;



		



			}











	}















}







void Graph::printWithCosts() {



	for (int i = 0; i < vertices_number; i++) {







		if (isConnected(i))







			for (int j = 0; j < vertices_number; j++) {







				if (adjacency_matrix[i][j] > 0)



					cout << "Source: " << i << "    " << "Destination: " << j << "    " <<"Cost: "<< adjacency_matrix[i][j]<< endl;







			}











	}











}
