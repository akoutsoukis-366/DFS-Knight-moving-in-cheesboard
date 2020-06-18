#include "myDefines.h"
#include <cstdlib>
int main()
{
	pair < int, int > poss(0, 0);
	std::vector < pair < int, int >> moves =  moveKnight(poss, 7);
	cout << "Expested results  (1 ,2) (2 , 1)" << endl;
	cout << "Actual Results " ;
	for (auto e : moves)
		cout << "(" << e.first << "," << e.second << ")" << "  " ;
	

	cout << ""<< endl << endl;
	
	shared_ptr<Node> node_1 = make_shared < Node>() ;




	pair < int, int >startPoint(0, 0);
	const  pair < int, int >endPoint(1, 2);
	int totalMoves = 1;
	const int chessboardSize = 2;
	findAllPaths(startPoint, endPoint, totalMoves, totalMoves, node_1, chessboardSize);
	cout << "Expected results :  Numer of moves 1 , X cordinate 1  , Y cordinate 2 , True or False 1" << endl;
	cout << "Expected results :  Numer of moves 1 , X cordinate 2  , Y cordinate 2 , True or False 0" << endl << endl;
	for (auto e : node_1->nextNode)
		cout << "Actual Results Numer of moves " << e->nMoves << " , X cordinate  " << e->x << " , Y cordinate " << e->y << " , True or False " << e->success << endl;

	cout << endl << endl;
	std::vector<pair<int, int>> winMoves;
	bool success = false;
	shared_ptr<Node> Node2 = make_shared<Node>();
	Node2->x = 0;
	Node2->y = 0;
	Node2->nMoves = 0;
	shared_ptr<Node> Node2_1 = make_shared<Node>();
	Node2_1->x = 1;
	Node2_1->y = 2;
	Node2_1->nMoves = 1;
	Node2_1->childOf = Node2;
	shared_ptr<Node> Node2_1_1 = make_shared<Node>();
	Node2_1_1->childOf = Node2_1;
	Node2_1_1->x = 2;
	Node2_1_1->y = 4;
	Node2_1_1->success = true;
	Node2_1_1->nMoves = 2;
	shared_ptr<Node> Node2_2 = make_shared<Node>();
	Node2_2->childOf = Node2;
	Node2_2->x = 2;
	Node2_2->y = 4;
	Node2_2->success = true;
	Node2_2->nMoves = 1;

	Node2_1->nextNode.push_back(Node2_1_1);
	Node2->nextNode.push_back(Node2_2);
	Node2->nextNode.push_back(Node2_1);
	
	
	findSuccessfullPath(Node2 , winMoves , success);

	cout << "Excpected results : Wining moves : 2 4" << endl;
	for (int i = 0; i < winMoves.size()  ; i++)
	{
		cout << "Actual Results : Wining moves : " << winMoves.at(i).first << " " << winMoves.at(i).second << endl;
	
	}
	system("pause");
}