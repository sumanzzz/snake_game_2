
# Snake Game 2

A classic Snake game built with C++ and SFML, featuring real-time rendering, food generation, snake growth, and collision detection.

##  Demo

![Snake Game 2 Demo](demo.gif)

##  Features

* Grid-based snake movement
* Random food spawning
* Dynamic snake growth
* Self-collision detection
* Wall collision detection
* Real-time rendering using SFML
* Keyboard controls (W/A/S/D)

##  Controls

| Key | Action     |
| --- | ---------- |
| W   | Move Up    |
| A   | Move Left  |
| S   | Move Down  |
| D   | Move Right |

##  Technologies Used

* C++
* SFML
* STL (`vector`, `pair`)
* Object-Oriented Programming
* Game Loop Architecture

##  Implementation Details

* The game board is represented using a 2D vector.
* Snake segments are stored using a dynamic vector of coordinate pairs.
* Food is generated at random valid positions on the board.
* Collision detection handles both wall impacts and self-collisions.
* Movement updates occur on a fixed timer using `sf::Clock`.

##  What I Learned

* Event handling with SFML
* Real-time rendering and game loops
* Working with 2D grids
* Collision detection techniques
* Managing dynamic game objects using STL containers

##  Project Progression

This project is the second stage in my Snake game series:

1. **Snake Game 1** — Console Version
2. **Snake Game 2** — SFML Graphics Version
3. **Snake Game 3** — Raylib 3D Version with a BFS-powered AI opponent

