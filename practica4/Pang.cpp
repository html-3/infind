#include "freeglut.h"
#include "World.h"

#include <iostream>

// Game Objects
World world;

// Initial render
void display() {
    world.draw();
}

// Update callback function
static void update(int value) {
    world.updateState();

    // Recursion
    glutPostRedisplay();
    glutTimerFunc(16, update, 0);
}

// Player input
void OnKeyboardDown(unsigned char key, int x_t, int y_t) {
    world.playerMovement(key);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Pang");

    world.init();
    glutDisplayFunc(display);
    glutTimerFunc(16, update, 0);
    glutKeyboardFunc(OnKeyboardDown);
    glutMainLoop();
    return 0;
}
