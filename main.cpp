#include "myDefines.h"

int totalMoves = 0;

int main ()
{

	try{
cout << "For simplicity reasons the chessboard is marked with numbers from 0 to size of chessboard :" << endl << endl; 
  pair < int, int >start;
  pair < int, int >end;
  shared_ptr<Node> Path = make_shared<Node>();
  //Node* path = new Node;
  int chessboardSize;
  cout << "Please define size of chessboard : " ;
  std::cin >> chessboardSize;
  //Get start Point
  cout << "Please give start point X : " ;
  std::cin >> start.first;
  cout << "Please give start point Y : " ;
  std::cin >> start.second;

  //Get end point
  cout << "Please give end point X   : " ;
  std::cin >> end.first;
  cout << "Please give end point Y   : ";
  std::cin >> end.second;

  // Get allowed moves
  cout << "Max allowed moves         : " ;
  cin >> totalMoves;
  
 
  bool currentFatherMoveFound = false;
  findAllPaths (start, end, totalMoves, totalMoves, Path , chessboardSize);
 
  printShortestPath(Path);

  
	}
	catch (exception e)
	{
		cout << "Exception " << e.what() << endl;
	}
	int c = getchar();
}

