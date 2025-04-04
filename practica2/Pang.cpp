#include "freeglut.h"
#include "Ball.h"
#include "World.h"
#include "Player.h"
#include <iostream>

// Game Objects
World world{};
Player player{};
Ball ball1{};
Ball ball2{};

// Initial render
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    world.render();
    player.render();
    ball1.render();
    ball2.render();

    glutSwapBuffers();
}

// Update callback function
static void update(int value) {
    player.worldGravity(world.gravity);
    player.worldCollision(world.height, world.width);
    player.updateState();

    ball1.worldGravity(world.gravity);
    ball1.worldCollision(world.height, world.width);
    ball1.updateState();

    ball2.worldGravity(world.gravity);
    ball2.worldCollision(world.height, world.width);
    ball2.updateState();

    // Recursive
    glutPostRedisplay();
    glutTimerFunc(16, update, 0);
}

// Don't know what this is
void init() {
    glClearColor(0.5f, 0.8f, 1.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-0.7, 0.7, -0.7, 0.7);
    glMatrixMode(GL_MODELVIEW);
}

void OnKeyboardDown(unsigned char key, int x_t, int y_t)
{
    if (key == 'w') player.movement(0.0, 0.01);
    if (key == 'a') player.movement(-0.1, 0.0);
    if (key == 's') player.movement(0.0, -0.01);
    if (key == 'd') player.movement(0.1, 0.0);

    if (key == 'r') player.setColor(255, 0, 0);
    if (key == 'g') player.setColor(0, 255, 0);
    if (key == 'b') player.setColor(0, 0, 255);

}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    
    glutCreateWindow("Pang");

    world.setSize(0.6, 1.0);
    world.setColor(50, 50, 50);
    world.setGravity(0.001);
    player.setRadius(0.05);
    player.setColor(200, 50, 50);

    ball1.setRadius(0.02);
    ball2.setRadius(0.02);
    ball1.setColor(50, 50, 100);
    ball2.setColor(50, 50, 100);
    ball1.setInitialState(0.2, 0.2, 0.02, 0.01);
    ball2.setInitialState(-0.3, 0.1, -0.02, 0.01);

    init();
    glutDisplayFunc(display);
    glutTimerFunc(16, update, 0);
    glutKeyboardFunc(OnKeyboardDown);
    glutMainLoop();
    return 0;
}
