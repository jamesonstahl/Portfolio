# Map Tracker
This project uses a stack to help find a path through a map. First, a class called Cell is created. A Cell represents a square on a map. 
Every cell has an X and Y coordinate and a cell type: FREE, BLOCKED, START, or END. A Free cell can be traversed, a Blocked cell cannot be traversed, 
a Start cell is a free cell and an entry into the map, and an End cell is a free cell and the final destination in the map. Each cell will 
maintain four Cell pointers to the cells immediately around it to the north, south, east, and west. A cell keeps track if it has been traversed by a 
Tracker and whether the cell is on a dead path.

Next a Map class is created. The main job of the Map class is to read in the map shape from the file and construct the linked cells. 
The format of the Map will come from a file, for example the file map.txt might look like this:
```
B S B F F F
F F B F B B
F B F F F E
F F F B F B
F B B F F B
F F F B F B
```

The goal is to eventually find a path through the map. The Map is able to print the original state and a path from the start to the end.
```
X O X X X X
O O X X X X
O X O O O O
O O O X X X
X X X X X X
X X X X X X
```

The Tracker class maintains a pointer to a the current cell that it is in (initially, it will hold the start cell) in order to find a path to the end. 
A Tracker continues to move through the map until it reaches the end cell. When a Tracker moves it will systematically select a direction and attempt 
to move to the cell in that direction. If the cell to move to is a Blocked cell or if the cell is on a dead path the Tracker will not move to that cell, 
it will select another cell to move to. If the Tracker is ever at a position where it cannot proceed any longer it will backtrack and try to move from the 
previous cell. It repeats this process until it finds the destination. Keeping track of the history involves maintaining a stack of pointers to 
previously visited cells.

A doubly linked list is used to implement the stack. If the user of the stack class attempts to pop/top an empty stack a StackUnderflow exception should be thrown.
