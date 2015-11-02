#include <iostream>
#include <fstream>

using namespace std;

char board[8][9];


bool isObstructed(int i, int j) {
	if(board[i][j] == 'W') {
		for(int ii = 0; ii < i; ++ii) {
			if(board[ii][j] != '.') {
				return true;
			}
		}
		return false;
	}
	else if(board[i][j] == 'B') {
		for(int ii = i+1; ii < 8; ++ii) {
			if(board[ii][j] != '.') {
				return true;
			}
		}
		return false;
	}
}

int main() {
	#ifndef ONLINE_JUDGE
	ifstream cin("testinput.txt");
	#endif

	for(int i = 0; i < 8; ++i) {
		for(int j = 0; j < 8; ++j) {
			cin.get(board[i][j]);
		}
		char ignore;
		cin.get(ignore);
	}

	int closest_white = 8;
	int closest_black = 8;

	for(int i = 0; i < 8; ++i) {
		for(int j = 0; j < 8; ++j) {
			if(board[i][j] == 'W') {
				if(!isObstructed(i,j)) {
					closest_white = min(closest_white,i);
				}
			}
			else if(board[i][j] == 'B') {
				if(!isObstructed(i,j)) {
					closest_black = min(closest_black,8-i);
				}
			}
		}
	}

	if(closest_white < closest_black) {
		cout << "A\n";
	}
	else {
		cout << "B\n";
	}
}