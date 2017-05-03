#include <map> 
#include <cstring>
#include <utility> 
using namespace std; 
class Maze{
public: 
	void setDimension(int rows,int cols);  
	void setCell(); // set cell to a wall. 
	void printMaze();  
	void solveMaze(int sx,int sy,int gx,int gy,int rows,int cols);  
	bool isWall(int x,int y); 
	bool inRange(int r,int c);  
	int randomRange(int lb,int ub); 
private:
	char maze[55][55];  
	map< pair<int,int>, pair<int,int> > parent; 
	int n,m; // dimensions of the maze.  
}; 
