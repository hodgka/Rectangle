# Rectangle
Coding Interview solution for apprenda 

Problem Description:
Implement functionality to determine the intersection points, containment, and adjacency of two rectangles. The implementation was supposed to capture the functionality of a rectangle, as well as the functionality described above.


==============================================================
==============================================================


Rectangle Class README - Alec Hodgkinson - 2/15/16
==============================================================
Running Rectangle.exe:

Rectangle.exe takes 2 command line arguments:
-The filename you want to load rectangle data from
-The name of the function you want to run
i.e. ./rectangle.exe test1.txt intersects

p1,p2 - Point objects 
R1 - Current Rectangle object(*this)
R2 - Generic Rectangle object
A rectangle is defined by the points in the top left(tl) and bottom right(br) corners.

===============================================================
Dependecies:

Written in C++, it relies solely on STL libraries (iostream, fstream, algorithm, etc.)

===============================================================
Functions:


Point Constructor - Point(x,y)
Creates of Point object which is used to create Rectangle objects.

Rectangle Constructor - Rectangle(p1,p2)
Creates a rectangle object with the top left and bottom right corners constraining the rectangle.

Intersection - .intersects(R2) 
Returns a vector of pairs of doubles. Each pair represents the corners of the rectangle formed by the intersection. If there is no intersection, then it returns ((0,0),(0,0)).

Contains - .contains(R2)
Checks if one rectangleis wholly contained inside the other rectangle that it is called on, but not vice versa.
i.e. if Area(R1)<Area(R1), R1.contains(R2) will fail.

Adjacent - adjacent(R2)
Checks for adjacency of two rectangles are adjacent(at least 1 side touching)

Area - .get_area()/.get_area(p1,p2)
1). Gets the area of whatever rectangle it is called on.
2). Get the area enclosed by points p1 and p2.

Distance - .dist(R1, m)
Gets the distance between two rectangles, i.e. distance from intersection rather than distance that the rectangles have been shifted. M is a bool that gives x distance when m = true(default) and y distance when 
m = false.

Offset - .offset(R2)
Gives the euclidean distance between the top left corners of the rectangles.

Inside - .inside(p1)/.inside(p1,m)
A helper function used in .contains and .adjacent. 
1). Checks if a p1 is inside the rectangle.
2). If m = true, then it checks the the x-coords of p1 are within the range of the rectangle. If m = false, it checks the y-coords.

Intersection Area - .intersection_area(R2)
Returns the area of intersection of the two rectangles.

Bigger - .bigger(R2)
Returns a bool declaring which rectangle has a larger area. Returns true if R1 is bigger, false if R2 is bigger.

Get Width - .get_width()
Returns the width of the rectangle

Get Height - .get_height()
Returns the Height of the rectangle

Get Perimeter - .get_perimeter()
Returns the perimeter of the rectangle





Planned Implementation:

I was going to implement the ability to input n rectangles at any given time, the ability to graph/visualize the rectangles, and a line sweep algorithm to calculate the total area due to intersection for n rectangles. Unfortunately I ran out of time before I could implement these. 



