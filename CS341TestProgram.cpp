/*
Moving a robot along a cartesian plane bounded by (0,0) (0,20) (20,0) (20,20)
Allowable directions to move are North, South, East and West. Robot cannot move
outside the boundary and can only take a unit step at a time.
At the end of the journey, the travelling information is produced.
Author - Dinesh.
*/
#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
	const int STOP = -1;
	const int STEP = 1;
	const int Ax = 0, Ay = 20, Bx = 20, By = 20, Cx = 20, Cy = 0, Dx = 0, Dy = 0; //vertex position in x,y coordinates
	const int North = 1, South = 3, East = 2, West = 4;

	int start_pos_x, start_pos_y;
	int current_pos_x, current_pos_y;
	int command = 1;
	int countN = 0, countE = 0, countS = 0, countW = 0;
	int distance = 0;

	cout << "Robot Program" << endl << endl;

	cout << "Please enter start position of Robot. [x y]: ";
	cin >> start_pos_x >> start_pos_y;

	//check if position specified is within boundary.
	while (!(start_pos_x >= Dx && start_pos_x <= Cx &&
		start_pos_y >= Dy && start_pos_y <= Ay))
	{
		cout << "Start Position specified is outside of boundary.\n";
		cout << "Please enter start position of Robot again. [x y]: ";
		cin >> start_pos_x >> start_pos_y;
	}

	current_pos_x = start_pos_x;
	current_pos_y = start_pos_y;

	while (command != STOP) {
		cout << "\nBoundary is specified as:" << endl;
		cout << "\tA----------B\tA = [0,20]\n"
			<< "\t|          |\tB = [20,20]\n"
			<< "\t|          |\tC = [20,0]\n"
			<< "\tD----------C\tD = [0,0]\n";
		cout << "\nCurrent Position of Robot is: ["
			<< current_pos_x << ", " << current_pos_y << "]\n";

		cout << "\nEnter Command: ";
		cin >> command;

		switch (command) {
		case (North):    //Going North   affects y coord
						 //check if trying to cross boundary AB
			if (current_pos_y + STEP > Ay) {
				cout << "\n******Cannot cross boundary -AB-.*******\n";
				if (current_pos_x == Ax && current_pos_y == Ay)
					cout << "Available directions to move are: 2(East) and 3(South)\n";
				else if (current_pos_x == Bx && current_pos_y == By)
					cout << "Available directions to move are: 4(West) and 3(South)\n";
				else
					cout << "Available directions to move are: 2(East), 3(South) and 4(West)\n";
			}
			else {
				current_pos_y += STEP;
				countN++;
			}
			break;
		case (East):    //Going East    affects x coord
						//check if trying to cross boundary -BC-
			if (current_pos_x + STEP > Bx) {
				cout << "\n******Cannot cross boundary -BC-.*******\n";
				if (current_pos_x == Bx && current_pos_y == By)
					cout << "Available directions to move are: 4(West) and 3(South)\n";
				else if (current_pos_x == Cx && current_pos_y == Cy)
					cout << "Available directions to move are: 1(North) and 4(West)\n";
				else
					cout << "Cannot cross boundary -BC-.\n"
					<< "Available directions to move are: 1(North), 3(South) and 4(West)\n";
			}
			else {
				current_pos_x += STEP;
				countE++;
			}
			break;
		case (South):    //Going South    affects y coord
						 //check if trying to cross boundary -CD-
			if (current_pos_y - STEP < Dy) {
				cout << "\n******Cannot cross boundary -CD-.*******\n";
				if (current_pos_x == Cx && current_pos_y == Cy)
					cout << "Available directions to move are: 1(North) and 4(West)\n";
				else if (current_pos_x == Dx && current_pos_y == Dy)
					cout << "Available directions to move are: 1(North) and 2(East)\n";
				else
					cout << "Available directions to move are: 1(North), 2(East) and 4(West)\n";
			}
			else {
				current_pos_y -= STEP;
				countS++;
			}
			break;

		case (West):    //Going West     affects x coord
						//check if trying to cross boundary -AD-
			if (current_pos_x - STEP < Dx) {
				cout << "\n******Cannot cross boundary -AD-.*******\n";
				if (current_pos_x == Ax && current_pos_y == Ay)
					cout << "Available directions to move are: 2(East) and 3(South)\n";
				else if (current_pos_x == Dx && current_pos_y == Dy)
					cout << "Available directions to move are: 1(North) and 2(East)\n";
				else
					cout << "Available directions to move are: 1(North), 2(East) and 3(South)\n";
			}
			else {
				current_pos_x -= STEP;
				countW++;
			}
			break;
		}
	}

	//do analysis
	cout << "\n\n\t--- Summary ---\n"
		<< "------------------------------------\n";
	cout << "1) Start Position of robot is: [" << start_pos_x << ", " << start_pos_y << "]\n";
	cout << "2) Robot has stopped at: [" << current_pos_x << ", " << current_pos_y << "]\n";
	cout << "3) Total Travel distance = " << (countN + countE + countS + countW) << endl;
	cout << "4) Distance d = "
		<< sqrt((current_pos_x - start_pos_x)*(current_pos_x - start_pos_x) +
		(current_pos_y - start_pos_y)*(current_pos_y - start_pos_y))
		<< " meters" << endl;
	cout << "5) # of times Robot turned North: " << countN << endl
		<< "   # of times Robot turned East: " << countE << endl
		<< "   # of times Robot turned South: " << countS << endl
		<< "   # of times Robot turned West: " << countW << endl;

	return 0;
	system("PAUSE");
}
