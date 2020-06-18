#include "myDefines.h"


 int minMoves = 0;
 

vector < pair < int, int >> moveKnight(const pair < int, int >currentPossition  ,const int chessboardSize)
{
	// All possible moves in the x and y direction for aknght
	array < int, 8 > possibleMoves_x = { -2, -2, -1, -1, 1, 1, 2, 2 };
	array < int, 8 > possibleMoves_y = { -1, 1, -2, 2, -2, 2, -1, 1 };

	// Add all the possible movements to the current possition of the horse
	for (auto it = possibleMoves_x.begin(); it != possibleMoves_x.end(); it++)
	{
		*it = *it + currentPossition.first;

	}
	for (auto it = possibleMoves_y.begin(); it != possibleMoves_y.end(); it++)
	{
		*it = *it + currentPossition.second;

	}
//find all the movements that are inside the chesboard
	vector < pair < int, int >>nextMoves;
	for (int i = 0; i < possibleMoves_x.size(); i++)
		if (possibleMoves_x.at(i) >= 0 && possibleMoves_x.at(i) <= chessboardSize
			&& possibleMoves_y.at(i) >= 0 && possibleMoves_y.at(i) <= chessboardSize)
		{
			pair < int, int >myPair;
			myPair.first = possibleMoves_x.at(i);
			myPair.second = possibleMoves_y.at(i);
			nextMoves.push_back(myPair);

		}
	return nextMoves;

}

void printShortestPath(shared_ptr<Node> allPaths ) 
{

	pair < int, int > point;

	bool success = false;

	vector < pair < int, int > > winMoves;
	
	findSuccessfullPath(allPaths, winMoves , success );

	if (success) {
		cout << "Path found with " << minMoves << " moves" << endl;

		// Print start point
		cout << "Starting point: " << allPaths->x << " " << allPaths->y << endl;

		//Print the moves
		

		
		for (int i = winMoves.size() - 1 ; i >= 0 ; i-- ) 
{
			cout << "Move: " << winMoves.size() - i   << endl;
			cout << winMoves[i].first << " " << winMoves[i].second << endl;
		}
		
	}
	else {
		cout << " No path found" << endl;
	}

}

void findAllPaths(const pair < int, int > startPoint,const  pair < int, int >endPoint, int totalMoves , const int totMoves, shared_ptr<Node> path , const int chessboardSize)
{
	
	
	//Set the coordinates of the first node. This will alays contain the coordinates of the starting point 
	path->x = startPoint.first;
	path->y = startPoint.second;
	path->nMoves = totMoves - totalMoves;
	
	// while there are still moves left
	while (  0 < totalMoves)
	{
		
		
		// find all the possible moves from the current possition
		auto findPossiblePossitions = moveKnight(startPoint , chessboardSize);
	
		


		//Subtract number of moves
		totalMoves--;
		
		for (int i = 0; i < findPossiblePossitions.size(); i++)
		{
			shared_ptr<Node> currentNode = make_shared<Node>();
			//Set the  coordinates of the node we are currently in
			currentNode->x = findPossiblePossitions.at(i).first;
			currentNode->y = findPossiblePossitions.at(i).second;
			currentNode->nMoves = totMoves - totalMoves;
			
			// If it is a wining path
			if (findPossiblePossitions.at(i) == endPoint )
			{
				
				// Set the pointer of the father to the childOf of the child
				currentNode->childOf = path;
				//Save the found path and set it to a wining path
				currentNode->success = true;
				path->nextNode.push_back(currentNode);
				
			}
			else
			{
		
				
				currentNode->childOf = path;
	
				// Save the path and set it to loosing path
				currentNode->success = false;
				path->nextNode.push_back(currentNode);
				// Now run the same function but the father node ill be the node that we are in, the current node
				findAllPaths(findPossiblePossitions.at(i), endPoint, totalMoves, totMoves, currentNode, chessboardSize);
			}
		}

		
		
	}

	
}




pair <int, int>currentPair;
void findSuccessfullPath(shared_ptr<Node> Path , vector <pair <int , int>>& vec , bool& success)
{
	
	

	if (Path->success)
	{
		if (minMoves > Path->nMoves || minMoves == 0)
		{
			vec.clear();
			Path->childOf-> childSucces = true;
			currentPair.first = Path->x;
			currentPair.second = Path->y;

			vec.push_back(currentPair);
			success = true;
			minMoves = Path->nMoves;

		}
	}
	else
	{

			for (int i = 0; i < Path->nextNode.size(); i++)
			{
				
				findSuccessfullPath(Path->nextNode[i], vec, success);

				// If the leaf has a child that has a succes than its father has a leaf that is a success. 
				if (Path->childSucces && Path ->nMoves > 0)
				{
					
					Path->childOf->childSucces = true;
					
					
					// add the coordinates of the Nodes that have a child that has a success
					currentPair.first = Path->x;
					currentPair.second = Path->y;
					vec.push_back(currentPair);
				}
				Path->childSucces = false;
				

			}	
	
	}

}
