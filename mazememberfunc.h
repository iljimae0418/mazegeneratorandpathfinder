// implementing member functions in the class maze. 
void Maze::setDimension(int rows,int cols){
	n = rows, m = cols; 
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			maze[i][j] = '.';  
		}
	}
}
void Maze::setCell(){
	int chosen[n+1][m+1]; 
	memset(chosen,0,sizeof(chosen));  
	int cnt = 0;  
	while (cnt < n*m/3){
		int i = randomRange(1,n+1); 
		int j = randomRange(1,m+1);  
		if (!chosen[i][j]){
			chosen[i][j] = 1;  
			maze[i][j] = '#'; 
			cnt++;  
		}else{
			continue;  
		}
	} 
}
void Maze::printMaze(){
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			cout << maze[i][j]; 
		}
		cout << endl; 
	}
}
void Maze::solveMaze(int sx,int sy,int gx,int gy,int rows,int cols){
	typedef pair<int,int> P;  
	int dx[8] = {0,-1,-1,-1,0,1,1,1}, dy[8] = {-1,-1,0,1,1,1,0,-1}; // up,down,left,right and diagonals. 
	// init parent map  
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			parent[P(i,j)].first = -1;  
			parent[P(i,j)].second = -1; 
		}
	}
	int dist = -1;  
	bool solved = false;  
	int visited[55][55]; 
	memset(visited,0,sizeof(visited));  
	queue< pair< P,int> > que;  
	visited[sx][sy] = 1;  
	que.push(make_pair(P(sx,sy),0));  
	while (!que.empty()){
		pair<P,int> pi = que.front(); que.pop();  
		int x = pi.first.first, y = pi.first.second; 
		dist = pi.second; 
		if (x == gx && y == gy){
			cout << "The end coordinate can be reached!" << endl; 
			cout << "Distance of the path = " << dist << endl; 
			solved = true; 
			break; 
		}
		for (int i = 0; i < 8; i++){
			int nx = x+dx[i], ny = y+dy[i];  
			if (inRange(nx,ny) && !visited[nx][ny] && maze[nx][ny] == '.'){ // if the coordinate we are moving to satisfies the three conditions: 
				// 1) it is within the appropriate range. 
				// 2) it is not visited/seen yet. 
				// 3) it is an empty space we can pass through.  
				visited[nx][ny] = 1; 
				que.push(make_pair(P(nx,ny),dist+1)); 
				// store parent for reconstruction later. 
				parent[P(nx,ny)].first = x; 
				parent[P(nx,ny)].second = y; 
			}
		}
	}
	/*cout << "Printing parent" << endl; 
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			cout << "(" << i << "," << j << "):" << parent[P(i,j)].first << " " << parent[P(i,j)].second << endl; 
		}
	} */  
	if (!solved){
		cout << "Sorry, it is impossible to reach the goal coordinate from the start coordinate" << endl; 
	}else{
		vector<P> info;  
		int curx = gx, cury = gy;  
		while (true){
			//cout << curx << " " << cury << endl; 
			info.push_back(P(curx,cury));  
			int next_x = parent[P(curx,cury)].first; 
			int next_y = parent[P(curx,cury)].second;   
			curx = next_x, cury = next_y;  
			if (curx == -1 && cury == -1) break; 
		}
		cout << "Let me print the path for you! The path is indicated with a 'M' symbol." << endl; 
		//cout << info.size() << endl; 
		for (int i = 0; i < info.size(); i++){
			maze[info[i].first][info[i].second] = 'M';  
		}
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= m; j++){
				cout << maze[i][j]; 
			}
			cout << endl; 
		}
	}	
}
bool Maze::isWall(int x,int y){
	return maze[x][y] == '#';  
}
bool Maze::inRange(int r,int c){
	return (r >= 1 && r <= n && c >= 1 && c <= m);  
}
int Maze::randomRange(int lb,int ub){ // returns random double value in range [lb,ub]
	random_device rd; 
	default_random_engine generator(rd()); 
	uniform_real_distribution<double> distribution(lb,ub);  
	return distribution(generator); 
}