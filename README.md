# PA1-Particle-System
Welcome to the PA1-Particle-System repository! This repository contains a particle system that allows you to explore and visualize various aspects of particles. 
The system provides four different particle simulations, each with its own unique characteristics and behaviors. 
You can interact with the particles using keyboard and mouse inputs to observe and manipulate their properties. 
It was developed with OpenFrameworks as part of a Programming Assignment for the Advanced Programming Course (CIIC4010) at UPRM.

## Setup
1. Clone this project inside an OpenFrameworks installation's "apps/myApps/" directory
   
2. Open a terminal and navigate to the project directory.
   
3. Run the following command to compile the program:
```make```

4. Once the compilation is complete, run the following command to execute the program:
```make run```


## Simulations
To change between the different simulations in the system, you can use the following number keys:

#### 1. Attract to Mouse:
- Press <kbd>1</kbd> to switch to the simulation where particles are attracted to the mouse cursor.
   
#### 2. Repel from Mouse:
- Press <kbd>2</kbd> to switch to the simulation where particles are repelled from the mouse cursor.
   
#### 3. Attract to Nearest Point:
- Press <kbd>3</kbd> to switch to the simulation where particles are attracted to the nearest point on the screen.
   
#### 4. Snowfall:
- Press <kbd>4</kbd> to switch to the snowfall simulation, where particles simulate falling snowflakes.


## Features

The particle system in this repository offers the following features:

- Reset System: Pressing <kbd>space</kbd> resets the particle system.
 
- Particle Color Toggle: Pressing <kbd>t</kbd> toggles the color of all particles in the system. The color sequence follows this pattern: Red → Green → Blue, and then repeats from Red again.
 
- Pause/Resume Particles: Pressing <kbd>s</kbd> toggles the pause state of the particles. When the particles are paused, they are suspended in the air and remain stationary.
 
- Control Velocity: Pressing <kbd>d</kbd> doubles the velocity of all particles in the system. Pressing <kbd>a</kbd> halves the velocity of all particles in the system.

- Draw and Remove Shapes: <kbd>Left-clicking</kbd> and dragging the mouse across the screen creates a rectangle with only borders (no filling). <kbd>Left-clicking</kbd> and dragging again replaces the older rectangle with a new one. <kbd>Right-clicking</kbd> within the boundaries of the rectangle removes the rectangle from the screen.

- Move Shapes: While holding  <kbd>middle-click</kbd> within the bounds of the rectangle, the rectangle will follow your mouse cursor.

- Magnify Particles: Particles that enter the drawn rectangle have their size tripled. Any particle that exits the boundary has its size reverted back to normal. Particles inside the boundary when the rectangle is removed also revert to normal size.

- Record Actions: Pressing <kbd>r</kbd> starts recording all subsequent keys pressed, along with their associated actions. The actions associated with the keys are performed even during recording. An indicator appears when the program is in recording mode.

- Replay Actions: Pressing <kbd>p</kbd> replays all the previously recorded keys and their associated actions at fixed intervals. While in replay mode, the program ignores any further key presses until the replay is finished or canceled. An indicator appears when the program is in replay mode.

- Cancel Replay: Pressing <kbd>c</kbd> cancels a playing replay.

## Student Information
Fabian J. Ruiz Gomez
- Email: fabian.ruiz3@upr.edu
- GitHub username: fabianruiz3

Ingrid M. Caraballo Lopez
- Email: ingrid.caraballo1@upr.edu
- GitHub username: Ingrid1089
