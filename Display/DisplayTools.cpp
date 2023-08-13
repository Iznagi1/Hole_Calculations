//
// Created by User on 13.08.2023.
//

#include <valarray>
#include "DisplayTools.h"

static Field g_field;
static std::vector<Hole> g_holes;
static std::vector<Alarm> g_alarms;


static void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glScaled(2.0, 2.0, 0.0);
    DisplayTools::DrawField();
    DisplayTools::DrawAlarms();
    DisplayTools::DrawHoles();


    glFlush();
}

void reshape(int width, int height) {
    glViewport(0, 0, width, width);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-500.0, 500.0, -500.0, 500.0);
    glMatrixMode(GL_MODELVIEW);

}

void DisplayTools::Run(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(1280, 960);
    glutInitWindowPosition(300, 30);
    glutCreateWindow("OpenGL Setup Test");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glutMainLoop();
}

void DisplayTools::DrawRectangle(const RectangleType &rectangle) {
    Point center = rectangle.GetCenter();
    double height = rectangle.GetHeight(), width = rectangle.GetWidth();
    glBegin(GL_POLYGON);
    glVertex2d(center.x - width / 2, center.y - height / 2);
    glVertex2d(center.x + width / 2, center.y - height / 2);
    glVertex2d(center.x + width / 2, center.y + height / 2);
    glVertex2d(center.x - width / 2, center.y + height / 2);
    glEnd();
}

void DisplayTools::DrawCircle(const CircleType &circle) {
    double radius = circle.GetRadius();
    double centerX = circle.GetCenterX();
    double centerY = circle.GetCenterY();

    glBegin(GL_LINE_LOOP);
    for (int angle = 0; angle <= 360; ++angle) {
        double x = centerX + radius * std::cos(angle * M_PI / 180);
        double y = centerY + radius * std::sin(angle * M_PI / 180);
        glVertex2d(x, y);
    }
    glEnd();
}

void DisplayTools::DrawField() {
    glColor3d(1.0, 1.0, 1.0);
    DrawRectangle(g_field.GetBase());
}

void DisplayTools::DrawAlarms() {
    glColor3d(1.0, 0.0, 0.0);
    for (const auto &alarm: g_alarms) {
        DrawRectangle(alarm.GetBase());
    }
}

void DisplayTools::DrawHoles() {
    glColor3d(0.0, 0.0, 1.0);
    for (const auto &hole: g_holes) {
        DrawCircle(hole.GetInnerCircle());
    }
    glColor3d(0.0, 1.0, 0.0);
    for (const auto &hole: g_holes) {
        DrawCircle(hole.GetExternalCircle());
    }
}


void DisplayTools::FillInfo(Field &&field, std::vector<Alarm> &&alarms, std::vector<Hole> &&holes) {
    g_field = field;
    g_alarms = alarms;
    g_holes = holes;
}
