#include <iostream> 
#include <cstring> 
#include <cstdio> 
#include <cstdlib> 
#include <algorithm> 
#include <queue> 
#include <random> 
#include <set> 
#include <vector> 
#include <sstream> 
#include "mazeproject.h" 
#include "mazememberfunc.h"
using namespace std;  
void trimWhiteSpaces(string &s); // just in case there are spaces and correct input mixed together.  
void openingPrompt();  
bool isValidRow(string &rows); 
bool isValidCol(string &cols);  
void getInput(int &rows,int &cols); 
bool isValid(string &s);   
bool wellFormedRow(string s,int rows);
bool wellFormedCol(string s,int cols); 
void getStartingLocation(Maze &mz,int &sx,int &sy,int &gx,int &gy,int rows,int cols);  
bool playAgainPrompt(); 
string toStr(int i);  
int toInt(string s);  
int main(){
	openingPrompt(); 
	while (true){
		int rows,cols;  
		getInput(rows,cols); 
		Maze mz;  
		mz.setDimension(rows,cols);  
		mz.setCell(); 
		mz.printMaze();  
		int sx,sy,gx,gy;  
		getStartingLocation(mz,sx,sy,gx,gy,rows,cols); 
		//cout << sx << " " << sy << " " << gx << " " << gy << endl; 
		mz.solveMaze(sx,sy,gx,gy,rows,cols); 
		if (!playAgainPrompt()){
			break; 
		}
	}	
}
void trimWhiteSpaces(string &s){
	int i,j; 
	for (i = 0; i < s.size(); i++){
		if (s[i] != ' '){
			break; 
		}
	}
	for (j = s.size()-1; j >= 0; j--){
		if (s[j] != ' '){
			break; 
		}
	}	
	s = s.substr(i,j-i+1);  
}
void openingPrompt(){
	cout << "=================== 2D Maze Generator/Solver by Luke Minsuk Kim ===================" << endl; 
	cout << "If you specify the dimensions of a maze, this program will generate a random maze." << endl; 
	cout << "The maze will have empty spaces (denoted as '.') where one can move through, and walls (denoted as '#') where one cannot pass." << endl; 
	cout << "One can move in a total of 8 directions (up,down,left,right,4 diagonals)." << endl; 
	cout << "If you specify the starting coordinate and the ending coordinate of the maze, The program will tell you if there exists a path." << endl; 
	cout << "It will also draw a possible shortest path that connects these two coordinates" << endl; 
	cout << "The maze's location can be specified as (x,y), where (1,1) is the upperleft corner of the maze and (n,m) is the lower right (assuming maze has dimensions nxm)." << endl; 
}
bool isValidRow(string &rows){
	trimWhiteSpaces(rows);  
	set<string> st; 
	for (int i = 3; i <= 50; i++){
		st.insert(toStr(i)); 
	}
	return st.count(rows);  
}
bool isValidCol(string &cols){
	trimWhiteSpaces(cols);  
	set<string> st; 
	for (int i = 3; i <= 50; i++){
		st.insert(toStr(i)); 
	}
	return st.count(cols); 
}
void getInput(int &rows,int &cols){
	cout << "Let us limit the number of rows and cols to be between 3 and 50 inclusive." << endl; 
	cout << "We can make the dimensions larger, but if it's too large, printing out on console may not be pretty :(" << endl; 
	cout << "Please enter integer values for rows, cols and adhere to the format specified for coordinates of starting and ending location." << endl; 
	cout << "Just in case you type some nonsense for input values, I added robustness features. Hopefully they are good enough to prevent weird behaviours due to badly formed input" << endl; 
	cout << "Number of rows: "; 
	string s;  
	getline(cin,s);  
	while (!isValidRow(s)){
		cout << "Enter between 3 and 50 inclusive" << endl; 
		cout << "Number of rows: "; 
		getline(cin,s);  
	}
	rows = toInt(s); 
	cout << "Number of cols: ";  
	getline(cin,s);  
	while (!isValidCol(s)){
		cout << "Enter between 3 and 50 inclusive" << endl; 
		cout << "Number of cols: "; 
		getline(cin,s); 
	}
	cols = toInt(s);  
}
bool isValid(string &s){
	return (s == "y" || s == "n"); 
}
bool wellFormedRow(string s,int rows){
	trimWhiteSpaces(s);  
	set<string> st;  
	for (int i = 1; i <= rows; i++){
		st.insert(toStr(i)); 
	}
	return st.count(s); 
}
bool wellFormedCol(string s,int cols){
	trimWhiteSpaces(s);  
	set<string> st;
	for (int i = 1; i <= cols; i++){
		st.insert(toStr(i)); 
	}
	return st.count(s); 
}
void getStartingLocation(Maze &mz,int &sx,int &sy,int &gx,int &gy,int rows,int cols){
	string s; 
	cout << "Enter starting x location:";  
	getline(cin,s);  
	while (!wellFormedRow(s,rows)){
		cout << "Invalid. Enter between 1 and " << rows << " inclusive:";  
		getline(cin,s); 
	}
	sx = toInt(s);  
	cout << "Enter starting y location:";  
	getline(cin,s); 
	while (!wellFormedCol(s,cols)){
		cout << "Invalid. Enter between 1 and " << cols << " inclusive:"; 
		getline(cin,s); 
	}
	sy = toInt(s); 
	while (mz.isWall(sx,sy)){
		cout << "Sorry, the starting coordinate cannot be a wall. It has to be an empty space (.)" << endl; 
		cout << "Enter starting x location:";  
		getline(cin,s);  
		while (!wellFormedRow(s,rows)){
			cout << "Invalid. Enter between 1 and " << rows << " inclusive:";  
			getline(cin,s); 
		}
		sx = toInt(s);  
		cout << "Enter starting y location:";  
		getline(cin,s); 
		while (!wellFormedCol(s,cols)){
			cout << "Invalid. Enter between 1 and " << cols << " inclusive:"; 
			getline(cin,s); 
		}
		sy = toInt(s); 
	}
	cout << "Enter ending x location:"; 
	getline(cin,s); 
	while (!wellFormedRow(s,rows)){
		cout << "Invalid. Enter between 1 and " << rows << " inclusive:";  
		getline(cin,s); 
	}
	gx = toInt(s);  
	cout << "Enter ending y location:";  
	getline(cin,s); 
	while (!wellFormedCol(s,cols)){
		cout << "Invalid. Enter between 1 and " << cols << " inclusive:"; 
		getline(cin,s); 
	}
	gy = toInt(s); 
	while (mz.isWall(gx,gy)){
		cout << "Sorry, the ending coordinate cannot be a wall. It has to be an empty space (.)" << endl; 
		cout << "Enter ending x location:";  
		getline(cin,s);  
		while (!wellFormedRow(s,rows)){
			cout << "Invalid. Enter between 1 and " << rows << " inclusive:";  
			getline(cin,s); 
		}
		gx = toInt(s);  
		cout << "Enter ending y location:";  
		getline(cin,s); 
		while (!wellFormedCol(s,cols)){
			cout << "Invalid. Enter between 1 and " << cols << " inclusive:"; 
			getline(cin,s); 
		}
		gy = toInt(s); 
	}
}
bool playAgainPrompt(){
	cout << "Want to play again? (yes:y, no:n)" << endl; 
	string response; 
	getline(cin,response); 
	trimWhiteSpaces(response);  
	while (!isValid(response)){
		cout << "Not a valid response" << endl; 
		getline(cin,response); 
		trimWhiteSpaces(response);   
	}
	if (response == "y"){
		cout << "Let's go for another round!" << endl; 
		return true;  
	}
	cout << "Thanks for playing! Bye" << endl; 
	return false; 
}
string toStr(int i){
	stringstream ss; 
	ss << i; 
	return ss.str(); 
}
int toInt(string s){
	stringstream ss (s); 
	int x; 
	ss >> x;  
	return x; 
}