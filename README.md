# mazegeneratorandpathfinder
Made by Luke Minsuk Kim for educational purposes and for fun. 
To be run on console with standard I/O. 
Uses standard BFS algorithm on a nxm grid (time complexity = O(8nm) = O(nm)).  
Uses Object Oriented Programming concept. This is why we have 3 files. 
mazeproject.cpp contains executable main function with other helper functions.  
mazeproject.h defines the class. 
mazememberfunc.h has implementation of member functions of the class. 
Below is a sample output on my terminal. 

=================== 2D Maze Generator/Solver by Luke Minsuk Kim ===================
If you specify the dimensions of a maze, this program will generate a random maze.
The maze will have empty spaces (denoted as '.') where one can move through, and walls (denoted as '#') where one cannot pass.
One can move in a total of 8 directions (up,down,left,right,4 diagonals).
If you specify the starting coordinate and the ending coordinate of the maze, The program will tell you if there exists a path.
It will also draw a possible shortest path that connects these two coordinates
The maze's location can be specified as (x,y), where (1,1) is the upperleft corner of the maze and (n,m) is the lower right (assuming maze has dimensions nxm).
Let us limit the number of rows and cols to be between 3 and 50 inclusive.
We can make the dimensions larger, but if it's too large, printing out on console may not be pretty :(
Please enter integer values for rows, cols and adhere to the format specified for coordinates of starting and ending location.
Just in case you type some nonsense for input values, I added robustness features. Hopefully they are good enough to prevent weird behaviours due to badly formed input
Number of rows: 30
Number of cols: 40
##.....#....#..####.......#...#####....#
...#..#.#.......#..##......#...#.#.#....
..##..#...##.#.##...#.#...#.##...#...###
#...###.#...#...##...####..##.##.##..#..
...#.##.#.##.#.#...##.#..#....#.#.....#.
##..##.##.......#....#...#.......#.####.
#.......#.##.#..###........##......##..#
.#......##....#...#.#.....#..#......##..
#.........##.##..#...#...##..#...###.##.
.#...#...#...###......#.#.#..........#.#
#........#..#..#.#.#.#.#..#..#.#.#..#...
.###.....##...#..#...##...##.#..#.####.#
.#....##.####..#...#...#...#..##...#...#
....##..##...##...........#....##...#.#.
.......#....##.#.#.##...##..#...#...#...
....##..#...#....#..#...####.........##.
##..#..##..#...#.....#....#..#.#.#####..
.#..#.#.......#......##..##.#.#..#.....#
..#.#...#.......#....###.....#........#.
.......###.#.##......##.##..#..#....#.##
#..#........#..#...#..###...#.........#.
.#.#...#......#.#.#...#..##.##...###....
..#..........#.#...#..#.#..#....#.######
#............#.#.##..##..............##.
......##..#..#.....#..##...#...#.....#..
###.#.......##..##.##.##.#.........#....
#..###.....##....#...#..###....#.#..##..
..........#.###.#....##......#.#.#..##.#
..#.....#...#...#.#.#.##.###.####.#...#.
...###..#....#..#...#......###.....##...
Enter starting x location:1
Enter starting y location:3
Enter ending x location:30
Enter ending y location:40
The end coordinate can be reached!
Distance of the path = 39
Let me print the path for you! The path is indicated with a 'M' symbol.
##MMMMM#....#..####.......#...#####....#
...#..#M#.......#..##......#...#.#.#....
..##..#.MM##.#.##...#.#...#.##...#...###
#...###.#.MM#...##...####..##.##.##..#..
...#.##.#.##M#.#...##.#..#....#.#.....#.
##..##.##....M..#....#...#.......#.####.
#.......#.##.#M.###........##......##..#
.#......##....#M..#.#.....#..#......##..
#.........##.##.M#...#...##..#...###.##.
.#...#...#...###.M....#.#.#..........#.#
#........#..#..#.#M#.#.#..#..#.#.#..#...
.###.....##...#..#.M.##...##.#..#.####.#
.#....##.####..#...#M..#...#..##...#...#
....##..##...##......M....#....##...#.#.
.......#....##.#.#.##.M.##..#...#...#...
....##..#...#....#..#..M####.........##.
##..#..##..#...#.....#..M.#..#.#.#####..
.#..#.#.......#......##.M##.#.#..#.....#
..#.#...#.......#....###.M...#........#.
.......###.#.##......##.##M.#..#....#.##
#..#........#..#...#..###..M#.........#.
.#.#...#......#.#.#...#..##M##...###....
..#..........#.#...#..#.#..#MMM.#.######
#............#.#.##..##........M.....##.
......##..#..#.....#..##...#...#M....#..
###.#.......##..##.##.##.#.......M.#....
#..###.....##....#...#..###....#.#M.##..
..........#.###.#....##......#.#.#.M##.#
..#.....#...#...#.#.#.##.###.####.#.MM#.
...###..#....#..#...#......###.....##.MM
Want to play again? (yes:y, no:n)
n
Thanks for playing! Bye

