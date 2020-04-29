#include <cstdio>
#include "graphviewer.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>


void exercicio1();
void exercicio2();
void exercicio3();


void exercicio1()
{
  
  //Create a 600*600 window and make the “background.jpg” image the background
  GraphViewer *gv = new GraphViewer(600, 600, true);
  gv->setBackground("background.jpg"); 
  gv->createWindow(600, 600);

  //Configure the vertex color to blue
  gv->defineVertexColor("blue");

  //Configure the edge color to black
  gv->defineEdgeColor("black");

  //Create a vertex with the following attributes: 0 
  gv->addNode(0);
  //gv->rearrange();

  //Create a vertex with the following attributes: 1 
  gv->addNode(1);
  //gv->rearrange();

  //Create an edge between the previously created vertices.
  // for bidirectional edges: gv->addEdge(idEdge,idSourceVertex,idDestinationVertex,EdgeType::UNDIRECTED);
  gv->addEdge(0, 0, 1, EdgeType::UNDIRECTED);
  // for directed edges: gv->addEdge(idEdge, idSourceVertex, idDestinationVertex, EdgeType::DIRECTED);
  //gv->rearrange();

  //Remove vertex 1
  gv->removeNode(1);
  //gv->rearrange();


  //Add a new vertex with the following attributes: 2
  gv->addNode(2);
  //gv->rearrange();

  //Add an edge between the two previously created vertices
  gv->addEdge(0, 0, 2, EdgeType::UNDIRECTED);
  //gv->rearrange();

  //Add a label to vertex 2 with a text of your choosing
  gv->setVertexLabel(2, "This is a vertex");
  //gv->rearrange();

  //Add a label to an edge with a text of your choosing
  gv->setEdgeLabel(0, "This is an edge");
  //gv->rearrange();

  //Make vertex 2 green
  gv->setVertexColor(2, "green");
  //gv->rearrange();
  
  //Make the edges yellow
  gv->setEdgeColor(0, "yellow");

  gv->rearrange();

}

void exercicio2()
{
	//Create a 600*600 window and make the “background.jpg” image the background
  	GraphViewer *gv = new GraphViewer(600, 600, false);
  	gv->setBackground("background.jpg"); 
	gv->createWindow(600, 600);

  	
  	gv->addNode(0, 300, 50);
  	gv->addNode(1, 318, 58);
  	gv->addNode(2, 325, 75);
  	gv->addNode(3, 318, 93);
  	gv->addNode(4, 300, 100);
  	gv->addNode(5, 282, 93);
  	gv->addNode(6, 275, 75);
  	gv->addNode(7, 282, 58);
  	gv->addNode(8, 150, 200);
  	gv->addNode(9, 300, 200);
  	gv->addNode(10, 450, 200);
  	gv->addNode(11, 300, 400);
  	gv->addNode(12, 200, 550);
  	gv->addNode(13, 400, 550);


  	gv->addEdge(0, 0, 1, EdgeType::UNDIRECTED);
  	gv->addEdge(1, 1, 2, EdgeType::UNDIRECTED);
  	gv->addEdge(2, 2, 3, EdgeType::UNDIRECTED);
  	gv->addEdge(3, 3, 4, EdgeType::UNDIRECTED);
  	gv->addEdge(4, 4, 5, EdgeType::UNDIRECTED);
  	gv->addEdge(5, 5, 6, EdgeType::UNDIRECTED);
  	gv->addEdge(6, 6, 7, EdgeType::UNDIRECTED);
  	gv->addEdge(7, 7, 0, EdgeType::UNDIRECTED);
  	gv->addEdge(8, 4, 9, EdgeType::UNDIRECTED);
  	gv->addEdge(9, 9, 8, EdgeType::UNDIRECTED);
  	gv->addEdge(10, 9, 10, EdgeType::UNDIRECTED);
  	gv->addEdge(11, 9, 11, EdgeType::UNDIRECTED);
  	gv->addEdge(12, 11, 12, EdgeType::UNDIRECTED);
  	gv->addEdge(13, 11, 13, EdgeType::UNDIRECTED);

  	for(int i = 0; i < 10; i++)
  	{
  		gv->rearrange();
  		sleep(1);

  		gv->removeNode(12);
  		gv->removeNode(13);

  		gv->addNode(14, 250, 550);
  		gv->addNode(15, 350, 550);

  		gv->rearrange();
  		sleep(1);

  		gv->removeNode(14);
  		gv->removeNode(15);

	  	gv->addNode(12, 200, 550);
	  	gv->addNode(13, 400, 550);

  		gv->addEdge(12, 11, 12, EdgeType::UNDIRECTED);
  		gv->addEdge(13, 11, 13, EdgeType::UNDIRECTED);
  	}
  	
}

void exercicio3()
{
	// To read map files, use relative paths:
	// Vertices data: "../resources/mapa1/nos.txt"
	// Edges data: "../resources/mapa1/arestas.txt"

	unsigned int x, y, idNode, idEdge, idSourceVertex, idDestinationVertex;
	ifstream handle;
	string line;


	//Create a 600*600 window and make the “background.jpg” image the background
  	GraphViewer *gv = new GraphViewer(600, 600, false);
  	gv->setBackground("background.jpg"); 
	gv->createWindow(600, 600);

	handle.open("../resources/mapa1/nos.txt");

	while(getline(handle, line))
	{
		istringstream iss(line);
		string token;
		getline(iss, token, ';');
		idNode = stoi(token);
		getline(iss, token, ';');
		x = stoi(token);
		getline(iss, token, ';');
		y = stoi(token);

  		gv->addNode(idNode, x, y);
	}

	handle.close();

	handle.open("../resources/mapa1/arestas.txt");

	while(getline(handle, line))
	{
		istringstream iss(line);
		string token;
		getline(iss, token, ';');
		idEdge = stoi(token);
		getline(iss, token, ';');
		idSourceVertex = stoi(token);
		getline(iss, token, ';');
		idDestinationVertex = stoi(token);

  		gv->addEdge(idEdge, idSourceVertex, idDestinationVertex, EdgeType::UNDIRECTED);
	}

	handle.close();

	gv->rearrange();
}

int main()
{
    /*
     * Uncomment the line below to run Exercise 1
     */
    //exercicio1();

    /*
      * Uncomment the line below to run Exercise 2
      */
    //exercicio2();

    /*
      * Uncomment the line below to run Exercise 3
      */

	//exercicio3();

	getchar();
	return 0;
}
