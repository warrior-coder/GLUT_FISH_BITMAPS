#include <stdlib.h>
#include <time.h>
#include <GLUT/glut.h>

#define FISHES_COUNT 20

// ������ ��������� ������� ���� 27x11, �� ��� ������ ������ ���� ������ 8 �����, ������� ������ 32x11.
const GLubyte imageData[] = {
    0b00000000, 0b01100000, 0b00000001, 0b00000000,
    0b00000000, 0b10010000, 0b00000001, 0b00000000,
    0b00000011, 0b11111000, 0b00000010, 0b10000000,
    0b00011100, 0b00110111, 0b11100100, 0b01000000,
    0b00100000, 0b01000000, 0b00011000, 0b01000000,
    0b11000000, 0b01000000, 0b01111000, 0b10000000,
    0b01100001, 0b00110111, 0b10000100, 0b10000000,
    0b00011100, 0b00011010, 0b00000100, 0b10000000,
    0b00000011, 0b11100010, 0b00000010, 0b01000000,
    0b00000000, 0b00010001, 0b00000001, 0b01000000,
    0b00000000, 0b00001111, 0b00000000, 0b11100000
};

// ���������� ��������� float � ��������� �� 0.0 �� 1.0
GLfloat RandomFloat()
{
    return (GLfloat)rand() / (GLfloat)RAND_MAX;
}

// ��� ��������� �������� ���� ������������ ������������� �������� � �������� ������������ �� 0 �� 1 � ������������ x � y
void ReshapeFunc(int width, int height)
{
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 1, 0, 1);
}

// ������� 20 ��������� ����������� ���� ���������� ����� �� ��������� �����������
void DisplayFunc()
{
    glClear(GL_COLOR_BUFFER_BIT);

    for (int i = 0; i < FISHES_COUNT; ++i)
    {
        glColor3f(RandomFloat(), RandomFloat(), RandomFloat());
        glRasterPos2f(RandomFloat(), RandomFloat());

        glBitmap(
            27,
            11,
            0.0f,
            0.0f,
            0.0f,
            0.0f,
            imageData
        );
    }
    glFlush();
}

// ����� ����� GLUT-����������
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowSize(256, 256);
    glutCreateWindow("GLUT Fishes");

    glutReshapeFunc(ReshapeFunc);
    glutDisplayFunc(DisplayFunc);

    srand(time(NULL));

    glutMainLoop();
}