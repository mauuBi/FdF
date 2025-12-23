FdF

FdF is a 42 school project that consists of creating a simple 3D wireframe renderer in C using the MiniLibX graphical library.

The program reads a map describing a 3D landscape and displays it as a wireframe representation in a window.

📌 Description

FdF takes as input a map file containing height values arranged in rows and columns.
Each number represents the altitude of a point in a grid.

The program projects this 3D map onto a 2D plane (most commonly using isometric projection) and draws a wireframe connecting all points.

✨ Features

Parsing of .fdf map files

3D wireframe rendering

Isometric and/or parallel projection

Zoom in / zoom out

Translation (move the map)

Rotation (depending on implementation)

Color interpolation based on height

Keyboard event handling

Window management with MiniLibX

🖼️ Screenshots
Isometric projection example

Example of a 3D wireframe rendered using isometric projection.

🛠️ Technologies

Language: C

Graphics library: MiniLibX

OS: Linux

Build tool: Makefile

📂 Map Format

Example of a valid map file:

0  0  0  0
0  5  5  0
0  5 10  0
0  0  0  0

▶️ Usage
Compilation
make

Execution
./fdf maps/example.fdf

⌨️ Controls (example)

Arrow keys → Move the map

+ / - → Zoom in / out

W / A / S / D → Rotate

ESC → Quit

📏 Constraints

Only authorized functions are used

Memory is properly managed

Project follows the 42 coding norm

📚 Learning Outcomes

Basics of computer graphics

3D to 2D projections

Event-driven programming

Mathematics for graphics

🏫 Author

Project developed as part of the 42 curriculum.
