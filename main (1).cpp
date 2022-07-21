/*
   This program demonstrates a simple robot (called "roomba")
   wandering around in a simulated room. the robot can move in any of
   four directions (forward, backward, left or right) within a "grid"
   so that any move changes the robot's location by one grid square.
   for example, if the robot starts at location (0,0) and moves forward,
   it will end up at location (0,1).
   Also, enter '0' for a little fun.
*/

// section 1: include C++ library definitions
#include <iostream>
using namespace std;

// Global variables?! Why not...?
int xPosition = 0;
int yPosition = 0;
const int XMAX = 10;       // const int variables to account for dimensions
const int YMAX = 10;       // of the room (10 x 10).
const int XMIN = 0;
const int YMIN = 0;

// Function prototypes. Condensed for space.
void display();
void moveForward(), moveBackward(), moveLeft(), moveRight(); 
void moveNorth(), moveSouth(), moveEast(), moveWest();

// Main. 'Nuff said.
int main() 
{
    char command;

    cout << "ATTENTION!\tATTENTION!\tATTENTION!\n"
         << "Roomba Commander! Tell roomba where to go.\n"
         << "Enter n, s, w, or e to move by one space towards compass direction.\n"
         << "Enter N, S, W, or E to move nonstop towards compass direction.\n"
         << "To quit, enter Q.\nEnter command: ";
    cin >> command;

    // Created if/if else/else branches for valid and invalid inputs.
    while (command != 'Q' && command != 'q')
    {
        if (command == 'n')
        {
            moveForward();
            display();
            cout << "Enter command: ";
            cin >> command;
        }
        else if (command == 'N')
        {
            moveNorth();
            display();
            cout << "Enter command: ";
            cin >> command;
        }
        else if (command == 's')
        {
            moveBackward();
            display();
            cout << "Enter command: ";
            cin >> command;
        }
        else if (command == 'S')
        {
            moveSouth();
            display();
            cout << "Enter command: ";
            cin >> command;
        }
        else if (command == 'w')
        {
            moveLeft();
            display();
            cout << "Enter command: ";
            cin >> command;
        }
        else if (command == 'W')
        {
            moveWest();
            display();
            cout << "Enter command: ";
            cin >> command;
        }
        else if (command == 'e')
        {
            moveRight();
            display();
            cout << "Enter command: ";
            cin >> command;
        }
        else if (command == 'E')
        {
            moveEast();
            display();
            cout << "Enter command: ";
            cin >> command;
        }
        else if (command == '0')          // For fun.
        {
            cout << "(EXPLOSION) Oh. Well... the Roomba exploded.";
            break;
        }
        else                             // To account for invalid inputs.
        {
            cout << "INVALID ENTRY. TRY AGAIN.\n";
            cout << "Enter command: ";
            cin >> command;
        }
    }
    cout << "\nPROGRAM ENDED\n";
    return 0;
}


// section 3: declare methods
void display() {
  cout << "The roomba is at location (";
  cout << xPosition;
  cout << ",";
  cout << yPosition;
  cout << ")\n";
} // end of display()

void moveForward() {
    cout << "Roomba moving forward...\n";
    if (yPosition < YMAX)
        yPosition += 1;
    else
        cout << "OBSTACLE DETECTED (NORTH WALL).\n";
} // end of moveForward()

void moveBackward() {
    cout << "Roomba moving backward...\n";
    if (yPosition > YMIN)
        yPosition -= 1;
    else
        cout << "OBSTACLE DETECTED (SOUTH WALL).\n";
} // end of moveBackward()

void moveLeft() {
    cout << "Roomba moving left...\n";
    if (xPosition > XMIN)
        xPosition -= 1;
    else
        cout << "OBSTACLE DETECTED (WEST WALL).\n";
} // end of moveLeft()

void moveRight() {
    cout << "Roomba moving right...\n";
    if (xPosition < XMAX)
        xPosition += 1;
    else
        cout << "OBSTACLE DETECTED (EAST WALL).\n";
} // end of moveRight()


// Following functions are for Roomba moving nonstop in compass position,
// at least until it hits an obstacle. 

void moveNorth() {
    cout << "Roomba moving North...\n";
    for (int i = yPosition; i < YMAX; i++)
        yPosition++;
    cout << "OBSTACLE DETECTED (NORTH WALL)\n";
} // end of moveNorth

void moveSouth() {
    cout << "Roomba moving South...\n";
    for (int i = yPosition; i > YMIN; i--)
        yPosition--;
    cout << "OBSTACLE DETECTED (SOUTH WALL)\n";
} // end of moveSouth

void moveEast() {
    cout << "Roomba moving East...\n";\
    for (int i = xPosition; i < XMAX; i++)
        xPosition++;
    cout << "OBSTACLE DETECTED (EAST WALL)\n";
} // end of moveEast

void moveWest() {
    cout << "Roomba moving West...\n";
    for (int i = xPosition; i > XMIN; i--)
        xPosition--;
    cout << "OBSTACLE DETECTED (WEST WALL)\n";
} // end of moveWest