#include <iostream>
#include <cstdlib>
#include <GL/glut.h>
#include <string>
#include <cmath>

#define SIGN(x) ((x) < 0 ? (-1) : (1))
#define ABS(x) ((x) < 0 ? (-x) : (x))
#define FLOOR(x) ((x) < 0 ? ( (x) -(int)(x) != 0 ? ((int)(x) -1) : ((int)(x))) : (int)(x))
#define FALSE 0
#define TRUE 1

using namespace std;

void setPixelBig(float x, float y)
{
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(x + 0.5, y + 0.5, 0.0);
    glVertex3f(x + 0.5, y  - 0.5, 0.0);    
    glVertex3f(x - 0.5, y  - 0.5, 0.0);
    glVertex3f(x - 0.5, y  + 0.5, 0.0);    

    glEnd();

    glFlush();
}

void setPixel(float x, float y)
{
    glBegin(GL_POINTS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(x, y, 0.0);    
    glEnd();

    glFlush();
}

void digitalDiff(float x0, float y0, float x1, float y1)
{
    float length;
    int i;

    if(ABS((x1 - x0)) >= ABS((y1 - y0)))
    {
        length = ABS((x1 - x0));
    }
    else
    {
        length = ABS((y1 - y0));
    }
    
    float dx = (x1 - x0)/length, dy = (y1 - y0)/length;

    float x = x0 + 0.5 * SIGN (dx);
    float y = y0 + 0.5 * SIGN (dy);
    
    for (i = 0; i < length; i++) 
    {
        setPixelBig(FLOOR(x), FLOOR(y));
        x += dx;
        y += dy;
    }
}

void medianPoint(float x0, float y0, float x1, float y1)
{
    float dx = ABS((x1 - x0)), dy = ABS((y1 - y0)), i;
    int signalx = SIGN ((x1 - x0));
    int signaly = SIGN ((y1 - y0));
    float x = x0, y = y0;
    float tmp;

    if (signalx< 0) x -=1;
    if (signaly< 0) y -= 1; 

    int interchange = FALSE;

    if ( dy> dx) 
    { 
        tmp = dx;
        dx = dy;
        dy = tmp;
        interchange = TRUE;
    }

    float erro = 2*(dy-dx);

    for (i = 0; i < dx; i++) 
    { 
        setPixelBig(x, y);
        while(erro >= 0.0) 
        { 
            if (interchange)  
            x = x + signalx;
            else  
            y = y + signaly;
            erro = erro -2 * dx;
        }
        if (interchange)  
        y = y + signaly;
        else 
        x = x + signalx;
        erro = erro + 2 * dy;
    }
}

void draw()
{
    digitalDiff(-30.0, -40.0, 10.0, 10.0);
    medianPoint(-10.0, -40.0, 20.0, 10.0);   
}

void render()
{
    draw(); 
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);    

    glutInitWindowPosition(0,0);
    glutInitWindowSize(960, 960);    
    glutCreateWindow("Rasterizacao");
    glutDisplayFunc(render);     
      
    gluOrtho2D(-100, 100, -100, 100);        

  

    glutMainLoop();

    return 0;
}