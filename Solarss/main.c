#include <GL/glut.h>
#include <cmath>

// Constants
const int numPlanets = 9;
const float PI = 3.14159265358979323846;

// Planet colors
float planetColors[numPlanets][3] = {
    {0.5f, 0.5f, 0.5f},  // Mercury
    {1.0f, 0.5f, 0.0f},  // Venus
    {0.0f, 0.0f, 1.0f},  // Earth
    {1.0f, 0.0f, 0.0f},  // Mars
    {1.0f, 1.0f, 0.5f},  // Jupiter
    {0.9f, 0.6f, 0.3f},  // Saturn
    {0.2f, 0.4f, 1.0f},  // Uranus
    {0.0f, 0.0f, 0.5f},  // Neptune
    {0.6f, 0.4f, 0.2f}   // Pluto
};

// Planet radii for orbits
float planetRadii[numPlanets] = {
    0.2f, 0.3f, 0.4f, 0.5f, 0.6f, 0.7f, 0.8f, 0.9f, 1.0f
};

// Function to draw a circle (used for orbits and planets)
void drawCircle(float radius, int segments) {
    glBegin(GL_LINE_LOOP);
    for(int i = 0; i < segments; i++) {
        float angle = 2.0f * PI * float(i) / float(segments);
        float x = radius * cosf(angle);
        float y = radius * sinf(angle);
        glVertex2f(x, y);
    }
    glEnd();
}

// Function to draw a filled circle (used for planets and moon)
void drawFilledCircle(float radius, int segments) {
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(0.0f, 0.0f);
    for(int i = 0; i <= segments; i++) {
        float angle = 2.0f * PI * float(i) / float(segments);
        float x = radius * cosf(angle);
        float y = radius * sinf(angle);
        glVertex2f(x, y);
    }
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw the Sun
    glColor3f(1.0f, 1.0f, 0.0f);
    drawFilledCircle(0.1f, 100);

    // Draw the planets
    for(int i = 0; i < numPlanets; i++) {
        glColor3fv(planetColors[i]);
        glPushMatrix();
        glRotatef(glutGet(GLUT_ELAPSED_TIME) * 0.01f * (i + 1), 0.0f, 0.0f, 1.0f);
        glTranslatef(planetRadii[i], 0.0f, 0.0f);
        drawFilledCircle(0.05f, 100);
        glPopMatrix();
    }

    // Draw the Earth's moon
    glColor3f(0.8f, 0.8f, 0.8f);
    glPushMatrix();
    glRotatef(glutGet(GLUT_ELAPSED_TIME) * 0.01f * 3, 0.0f, 0.0f, 1.0f); // Earth's orbit
    glTranslatef(planetRadii[2], 0.0f, 0.0f); // Position of Earth
    glRotatef(glutGet(GLUT_ELAPSED_TIME) * 0.05f, 0.0f, 0.0f, 1.0f); // Moon's orbit
    glTranslatef(0.1f, 0.0f, 0.0f); // Distance of moon from Earth
    drawFilledCircle(0.02f, 100); // Draw the moon
    glPopMatrix();

    glutSwapBuffers();
}

void init() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.5, 1.5, -1.5, 1.5);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 800);
    glutCreateWindow("Solar System");
    init();
    glutDisplayFunc(display);
    glutIdleFunc(display);
    glutMainLoop();
    return 0;
}
