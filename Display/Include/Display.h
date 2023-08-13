//
// Created by User on 13.08.2023.
//
#define GL_SILENCE_DEPRECATION
#ifndef DISPLAY_H
#define DISPLAY_H

#include <windows.h>
#include <gl/glut.h>
#include <thread>
#include <chrono>


void drawAxes()
{
    glLineWidth(2.0);  // Задаем толщину линии осей

    // Ось X (красная)
    glColor3f(1.0, 0.0, 0.0);  // Красный цвет
    glBegin(GL_LINES);
    glVertex2f(-1.0, 0.0);
    glVertex2f(1.0, 0.0);
    glEnd();

    // Ось Y (зеленая)
    glColor3f(0.0, 0.0, 1.0);  // Зеленый цвет
    glBegin(GL_LINES);
    glVertex2f(0.0, -1.0);
    glVertex2f(0.0, 1.0);
    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    glTranslatef(0.0, 0.0, -5.0);  // Перемещаем поле вглубь экрана

    drawAxes();  // Отрисовка осей координат

    glFlush();
}

void renderLoop()
{
    while (true)
    {
        glutPostRedisplay(); // Помечаем окно для перерисовки
        std::this_thread::sleep_for(std::chrono::milliseconds(16)); // Задержка, чтобы обновление происходило примерно каждые 16 миллисекунд
    }
}

void reshape(int width, int height)
{
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);  // Устанавливаем ортографическую проекцию
    glMatrixMode(GL_MODELVIEW);
}

int run(int argc, char** argv)
{
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("OpenGL Window");

    glutDisplayFunc(display);

    glutMainLoop();
    return 0;
}



#endif //DISPLAY_H
