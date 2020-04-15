#include <cstdio>
#include "graphviewer.h"
#include <fstream>
#include <iostream>
#include <sstream>


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
  gv->rearrange();

  //Create a vertex with the following attributes: 1 
  gv->addNode(1);
  gv->rearrange();

  //Create an edge between the previously created vertices.
  // for bidirectional edges: gv->addEdge(idEdge,idSourceVertex,idDestinationVertex,EdgeType::UNDIRECTED);
  gv->addEdge(0, 0, 1, EdgeType::UNDIRECTED);
  // for directed edges: gv->addEdge(idEdge, idSourceVertex, idDestinationVertex, EdgeType::DIRECTED); 

  //Remove vertex 1
  gv->removeNode(1);

  //Add a new vertex with the following attributes: 2
  gv->addNode(2);
  gv->rearrange();

  //Add an edge between the two previously created vertices
  gv->addEdge(0, 0, 2, EdgeType::UNDIRECTED);

  //Add a label to vertex 2 with a text of your choosing
  gv->setVertexLabel(2, "This is a vertex");

  //Add a label to an edge with a text of your choosing
  gv->setEdgeLabel(0, "This is an edge");

  //Make vertex 2 green
  gv->setVertexColor(2, "green");

  //Make the edges yellow
  gv->setEdgeColor(0, "yellow");

  gv->rearrange();

}

void exercicio2()
{
// TODO: Implement here exercise 2!
// ...
}

void exercicio3()
{
// TODO: Implement here exercise 3!
// To read map files, use relative paths:
// Vertices data: "../resources/mapa1/nos.txt"
// Edges data: "../resources/mapa1/arestas.txt"
// ...
}

int main() {
    /*
     * Uncomment the line below to run Exercise 1
     */
    exercicio1();

    /*
      * Uncomment the line below to run Exercise 2
      */
    //exercicio2();

    /*
      * Uncomment the line below to run Exercise 3
      */
	//
	//exercicio3();

	getchar();
	return 0;
}
