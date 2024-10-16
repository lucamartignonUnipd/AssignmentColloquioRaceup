# AssignmentColloquioRaceup

The solution I chose for this exercise is an implementation of the A* algorithm.

The Node class represents a node of the graph created by the algorithm, and contains its position in the maze, the cost of the path to reach it, its distance from the exit, and a pointer to its parent.
The Maze class is the class containing the maze's data, like the start and exit position and the maze itself.
The MazeSolver class contains all the functions and data structures to implement the A* algorithm.

To solve a maze with this program, simply paste the maze in the MazeInput.txt file.
To compile the code type in the terminal "g++ -o main main.cpp MazeSolver.cpp Node.cpp Maze.cpp", and to execute it type "./main".
