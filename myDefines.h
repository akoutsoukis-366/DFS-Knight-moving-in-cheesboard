#pragma once

#include <iostream>
#include <vector>
#include <array>
#include <memory>
using namespace std;
struct Node {


	int x;
	int y;
	int nMoves;
	bool success = false;
	shared_ptr<Node> childOf ;
	bool childSucces = false;
	vector<shared_ptr<Node> > nextNode;

};


vector < pair < int, int >> moveKnight(const pair < int, int >, const int );
void findSuccessfullPath(shared_ptr<Node> , vector <pair <int, int>>& , bool& );
void findAllPaths(const pair < int, int >, const pair < int, int >, int , const int, shared_ptr<Node>  , const int );
void printShortestPath( shared_ptr<Node>);

