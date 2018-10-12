
#include <iostream>
#include <cstdlib>
#include <GL/glut.h>
#include <string>
#include <cmath>

//primitives
void Quad(float xScale, float yScale, float xOfsset, float yOfsset, float initialColor, float endColor);
void Trapeze(float xScale, float yScale, float xOfsset, float yOfsset, float initialColor, float endColor, float angulation);
void Triangle(float xScale, float yScale, float xOfsset, float yOfsset, float initialColor, float endColor);
void Line(float xScale, float xOfsset, float yOfsset, float initialColor, float endColor);

using namespace std;

class Rocket
{
    private:
    public:
    int height;
    int width;
    int scale; 
    string type;
    string comments;


    void draw(); 

    void flag();
    void M1();
    void M2(); 
    void M3(); 
};

class Cenary
{
    private:
    public:
    void draw();
    void cloud(float x, float y, float radius, int k);
};

void Quad(float xScale, float yScale, float xOfsset, float yOfsset, float initialColor, float endColor)
{
    glColor3f(initialColor, initialColor, initialColor);
    glVertex3f(-xScale + xOfsset, yScale + yOfsset, 0.0);
    glVertex3f(-xScale + xOfsset, -yScale + yOfsset, 0.0);
    glColor3f(endColor, endColor, endColor);
    glVertex3f(xScale + xOfsset, -yScale + yOfsset, 0.0);
    glVertex3f(xScale + xOfsset, yScale + yOfsset, 0.0); 
}

void Line(float xScale, float xOfsset, float yOfsset, float initialColor, float endColor)
{
    float yScale = 1.0;
    glColor3f(initialColor, initialColor, initialColor);
    glVertex3f(-xScale + xOfsset, yScale + yOfsset, 0.0);
    glVertex3f(-xScale + xOfsset, -yScale + yOfsset, 0.0);
    glColor3f(endColor, endColor, endColor);
    glVertex3f(xScale + xOfsset, -yScale + yOfsset, 0.0);
    glVertex3f(xScale + xOfsset, yScale + yOfsset, 0.0); 
}

void Triangle(float xScale, float yScale, float xOfsset, float yOfsset, float initialColor, float endColor)
{
    glColor3f(initialColor, initialColor, initialColor);
    glVertex3f(xScale + xOfsset, -yScale + yOfsset, 0.0); 
    glColor3f(endColor, endColor, endColor);
    glVertex3f(-xScale + xOfsset, -yScale + yOfsset, 0.0); 
    glVertex3f(-xScale + xOfsset, yScale + yOfsset, 0.0); 
}

void Trapeze(float xScale, float yScale, float xOfsset, float yOfsset, float initialColor, float endColor, float angulation)
{
    glColor3f(initialColor, initialColor, initialColor);
    glVertex3f(-xScale + xOfsset + angulation, yScale + yOfsset, 0.0);
    glVertex3f(-xScale + xOfsset, -yScale + yOfsset, 0.0); 
    glColor3f(endColor, endColor, endColor);
    glVertex3f(xScale + xOfsset, -yScale + yOfsset, 0.0);
    glVertex3f(xScale + xOfsset - angulation, yScale + yOfsset, 0.0); 
}

void Rocket::flag()
{
    float xOfsset = 0.0, yOfsset = 0.0;
    float xScale = 0.0, yScale = 0.0;

    glBegin(GL_QUADS);

    xOfsset = -10.0; 
    yOfsset = -180.0;
    xScale = 15.0; 
    yScale = 14.0;

    glColor3f(0.8, 0.15, 0.15);
    glVertex3f(-xScale + xOfsset, yScale + yOfsset, 0.0);
    glVertex3f(-xScale + xOfsset, -yScale + yOfsset, 0.0);    
    glVertex3f(xScale + xOfsset, -yScale + yOfsset, 0.0);
    glVertex3f(xScale + xOfsset, yScale + yOfsset, 0.0);

    xOfsset = -10.0; 
    yOfsset = -167.0;
    xScale = 15.0; 
    yScale = 2.0;

    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-xScale + xOfsset, yScale + yOfsset, 0.0);
    glVertex3f(-xScale + xOfsset, -yScale + yOfsset, 0.0);    
    glVertex3f(xScale + xOfsset, -yScale + yOfsset, 0.0);
    glVertex3f(xScale + xOfsset, yScale + yOfsset, 0.0);

    yOfsset = -176.0;

    glVertex3f(-xScale + xOfsset, yScale + yOfsset, 0.0);
    glVertex3f(-xScale + xOfsset, -yScale + yOfsset, 0.0);    
    glVertex3f(xScale + xOfsset, -yScale + yOfsset, 0.0);
    glVertex3f(xScale + xOfsset, yScale + yOfsset, 0.0);

    yOfsset = -184.0;

    glVertex3f(-xScale + xOfsset, yScale + yOfsset, 0.0);
    glVertex3f(-xScale + xOfsset, -yScale + yOfsset, 0.0);    
    glVertex3f(xScale + xOfsset, -yScale + yOfsset, 0.0);
    glVertex3f(xScale + xOfsset, yScale + yOfsset, 0.0);

    yOfsset = -192.0;

    glVertex3f(-xScale + xOfsset, yScale + yOfsset, 0.0);
    glVertex3f(-xScale + xOfsset, -yScale + yOfsset, 0.0);    
    glVertex3f(xScale + xOfsset, -yScale + yOfsset, 0.0);
    glVertex3f(xScale + xOfsset, yScale + yOfsset, 0.0);

    xOfsset = -18.0; 
    yOfsset = -172.0;
    xScale = 7.0; 
    yScale = 6.5;

    glColor3f(0.15, 0.15, 0.8);
    glVertex3f(-xScale + xOfsset, yScale + yOfsset, 0.0);
    glVertex3f(-xScale + xOfsset, -yScale + yOfsset, 0.0);    
    glVertex3f(xScale + xOfsset, -yScale + yOfsset, 0.0);
    glVertex3f(xScale + xOfsset, yScale + yOfsset, 0.0);

    glEnd();

}

void Rocket::M1()
{ 
    float xOfsset = 0.0, yOfsset = 0.0;
    float xScale = 0.0, yScale = 0.0;

    //Rockets
    glBegin(GL_TRIANGLES);
    xOfsset = -20.0;
    yOfsset = -407.0;
    xScale = 6.0; 
    yScale = 22.0;
    
    Triangle( xScale, yScale, xOfsset, yOfsset, 0.15, 0.15);
    xOfsset = xOfsset - (xScale*2); 
    xScale = -xScale; 

    Triangle( xScale, yScale, xOfsset, yOfsset, 0.15, 0.15);

    xOfsset = -6.0;
    Triangle( xScale, yScale, xOfsset, yOfsset, 0.15, 0.15);
    xOfsset = xOfsset - (xScale*2); 
    xScale = -xScale; 

    Triangle( xScale, yScale, xOfsset, yOfsset, 0.15, 0.15);

    xOfsset = 32.0;
    Triangle( xScale, yScale, xOfsset, yOfsset, 0.15, 0.15);
    xOfsset = xOfsset - (xScale*2); 
    xScale = -xScale; 

    Triangle( xScale, yScale, xOfsset, yOfsset, 0.15, 0.15);

    glEnd();

    //Tanque
    glBegin(GL_QUADS);

    xOfsset = 0.0; 
    yOfsset = -180.0;
    xScale = 35.0; 
    yScale = 220.0;

    Quad(xScale, yScale, xOfsset, yOfsset, 1.0, 0.4);

    xOfsset = 0.0; 
    yOfsset = -250.0;
    xScale = 35.0; 
    yScale = 6.0;

    Quad(xScale, yScale, xOfsset, yOfsset, 0.2, 0.0);

    xOfsset = 18.0; 
    yOfsset = -328.0;
    xScale = 10.0; 
    yScale = 72.0;

    Quad(xScale, yScale, xOfsset, yOfsset, 0.2, 0.0); 

    xOfsset = -30.0; 
    yOfsset = -328.0;
    xScale = 5.0; 
    yScale = 72.0;

    Quad(xScale, yScale, xOfsset, yOfsset, 0.2, 0.1);

    //encima
    xOfsset = 0.0; 
    yOfsset = 0.0;
    xScale = 35.0; 
    yScale = 6.0;

    Line(xScale, xOfsset, yOfsset, 0.2, 0.0);

    xOfsset = 18.0; 
    yOfsset = 20.0;
    xScale = 10.0; 
    yScale = 20.0;

    Quad(xScale, yScale, xOfsset, yOfsset, 0.2, 0.0); 

    xOfsset = -30.0; 
    yOfsset = 20.0;
    xScale = 5.0; 
    yScale = 20.0;

    Quad(xScale, yScale, xOfsset, yOfsset, 0.2, 0.1);
    
    glEnd();

    //Asa1
    glBegin(GL_TRIANGLES);
    xOfsset = 47.8;
    yOfsset = -370.0;
    xScale = 13.0; 
    yScale = 30.0;
    
    Triangle( xScale, yScale, xOfsset, yOfsset, 0.1, 0.28);

    //Asa2
    xOfsset = -xOfsset; 
    xScale = -xScale; 
    Triangle( xScale, yScale, xOfsset, yOfsset, 0.9, 0.9);
    
    glEnd();
}

void Rocket::M2()
{ 
    float xOfsset = 0.0, yOfsset = 0.0;
    float xScale = 0.0, yScale = 0.0;
    float angulationT = 0.0;

    //Rockets
    glBegin(GL_TRIANGLES);
    xOfsset = -16.0;
    yOfsset = 40.0;
    xScale = 6.0; 
    yScale = 22.0;
    
    Triangle( xScale, yScale, xOfsset, yOfsset, 0.15, 0.15);
    xOfsset = xOfsset - (xScale*2); 
    xScale = -xScale; 

    Triangle( xScale, yScale, xOfsset, yOfsset, 0.15, 0.15);

    xOfsset = -6.0;
    Triangle( xScale, yScale, xOfsset, yOfsset, 0.15, 0.15);
    xOfsset = xOfsset - (xScale*2); 
    xScale = -xScale; 

    Triangle( xScale, yScale, xOfsset, yOfsset, 0.15, 0.15);

    xOfsset = 28.0;
    Triangle( xScale, yScale, xOfsset, yOfsset, 0.15, 0.15);
    xOfsset = xOfsset - (xScale*2); 
    xScale = -xScale; 

    Triangle( xScale, yScale, xOfsset, yOfsset, 0.15, 0.15);

    glEnd();

    //tanque
    glBegin(GL_QUADS);

    xOfsset = 0.0; 
    yOfsset = 160.0;
    xScale = 35.0; 
    yScale = 120.0;

    Quad(xScale, yScale, xOfsset, yOfsset, 1.0, 0.4);

    //preto

    xOfsset = 0.0; 
    yOfsset = 76.0;
    xScale = 35.0; 
    yScale = 6.0;

    Quad(xScale, yScale, xOfsset, yOfsset, 0.2, 0.0);

    xOfsset = 18.0; 
    yOfsset = 55.0;
    xScale = 10.0; 
    yScale = 15.0;

    Quad(xScale, yScale, xOfsset, yOfsset, 0.2, 0.0); 

    xOfsset = -30.0; 
    yOfsset = 55.0;
    xScale = 5.0; 
    yScale = 15.0;

    Quad(xScale, yScale, xOfsset, yOfsset, 0.2, 0.1);

    //preto
    xOfsset = 0.0; 
    yOfsset = 265.0;
    xScale = 35.0; 
    yScale = 15.0;

    Quad(xScale, yScale, xOfsset, yOfsset, 0.2, 0.0);

    xOfsset = 0.0; 
    yOfsset = 308.0;
    xScale = 35.0; 
    yScale = 28.0;

    angulationT = 15.0;

    Trapeze(xScale, yScale, xOfsset, yOfsset, 1.0, 0.4, angulationT); 

    glEnd();
}

void Rocket::M3()
{
    float xOfsset = 0.0, yOfsset = 0.0;
    float xScale = 0.0, yScale = 0.0;
    float angulationT = 0.0;

    //Rocket
    glBegin(GL_TRIANGLES); 
    
    xOfsset = 6.0;
    yOfsset = 325.0;
    xScale = 6.0; 
    yScale = 22.0;

    Triangle( xScale, yScale, xOfsset, yOfsset, 0.15, 0.15);
    xOfsset = xOfsset - (xScale*2); 
    xScale = -xScale; 

    Triangle( xScale, yScale, xOfsset, yOfsset, 0.15, 0.15);

    glEnd();

    //tanque
    glBegin(GL_QUADS);

    xOfsset = 0.0; 
    yOfsset = 415.0;
    xScale = 20.0; 
    yScale = 80.0;

    Quad(xScale, yScale, xOfsset, yOfsset, 1.0, 0.4);

    //preto
    xOfsset = 0.0; 
    yOfsset = 450.0;
    xScale = 20.0; 
    yScale = 8.0;

    Quad(xScale, yScale, xOfsset, yOfsset, 0.2, 0.0);

    xOfsset = 0.0; 
    yOfsset = 535.0;
    xScale = 20.0; 
    yScale = 40.0;

    angulationT = 10.0;

    Trapeze(xScale, yScale, xOfsset, yOfsset, 1.0, 0.4, angulationT);

    xOfsset = 0.0; 
    yOfsset = 635.0;
    xScale = 10.0; 
    yScale = 60.0;

    Quad(xScale, yScale, xOfsset, yOfsset, 1.0, 0.4);

    xOfsset = 0.0; 
    yOfsset = 715.0;
    xScale = 10.0; 
    yScale = 20.0;

    angulationT = 8.5;

    Trapeze(xScale, yScale, xOfsset, yOfsset, 1.0, 0.4, angulationT);

    glEnd();

}

void Rocket::draw()
{    
    M3();
    glFlush(); 
    M2();
    glFlush(); 
    M1(); 
    glFlush();  
    flag();
    glFlush(); 
}

void Cenary::cloud(float x, float y, float radius, int k)
{
    int i;
        int triangleAmount = 20;    
        
        float twicePi = 2.0 * 3.1415926535;

    glColor3f(1.0, 1.0, 1.0);

    for (; k; k--)
    {
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    
    for(i = 0; i <= triangleAmount;i++) 
    { 
    glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),y + (radius * sin(i * twicePi / triangleAmount)));
    }

    glEnd();
    x += radius;

    }
}

void Cenary::draw()
{
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.4);
    glVertex3f(-550, 900, 0.0);
    glColor3f(0.1, 0.3, 0.7);
    glVertex3f(-550 , -500, 0.0);
    glVertex3f(550, -500, 0.0);
    glColor3f(0.1, 0.3, 0.7);
    glVertex3f(550, 900, 0.0); 

    glColor3f(0.1, 0.6, 0.1);
    glVertex3f(-550, -300, 0.0); 
    glVertex3f(-550 , -500, 0.0);
    glVertex3f(550, -500, 0.0); 
    glVertex3f(550, -300, 0.0); 

    glColor3f(0.4, 0.4, 0.4); 
    glVertex3f(150, 800, 0.0); 
    glVertex3f(150 , -460, 0.0);
    glVertex3f(-150, -460, 0.0); 
    glVertex3f(-150, 800, 0.0); 

    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(-150, -410, 0.0); 
    glVertex3f(-150 , -460, 0.0);
    glVertex3f(150, -460, 0.0); 
    glVertex3f(150, -410, 0.0); 

    glColor3f(0.5, 0.5, 0.5); 
    glVertex3f(-150, 800, 0.0); 
    glVertex3f(-150 , -460, 0.0);
    glVertex3f(-170, -460, 0.0); 
    glVertex3f(-170, 800, 0.0);

    glColor3f(0.5, 0.5, 0.5); 
    glVertex3f(150, 800, 0.0); 
    glVertex3f(150 , -460, 0.0);
    glVertex3f(170, -460, 0.0); 
    glVertex3f(170, 800, 0.0); 

    glColor3f(0.6, 0.6, 0.6); 
    glVertex3f(-150, -250, 0.0); 
    glVertex3f(-150 , -270, 0.0);
    glVertex3f(150, -270, 0.0); 
    glVertex3f(150, -250, 0.0);

    glColor3f(0.6, 0.6, 0.6); 
    glVertex3f(-150, 150, 0.0); 
    glVertex3f(-150 , 130, 0.0);
    glVertex3f(150, 130, 0.0); 
    glVertex3f(150, 150, 0.0); 

    glColor3f(0.6, 0.6, 0.6); 
    glVertex3f(-150, 600, 0.0); 
    glVertex3f(-150 , 580, 0.0);
    glVertex3f(150, 580, 0.0); 
    glVertex3f(150, 600, 0.0); 
    glEnd();

    cloud(300.0, 600.0, 60.0, 3);
    cloud(-400.0, 500.0, 30.0, 5);
    cloud(-500.0, 200.0, 20.0, 4);
    cloud(400.0, 100.0, 10.0, 5);

    glFlush();

}

Rocket r;
Cenary c;

void render()
{
    c.draw();
    r.draw();
}


int main(int argc, char *argv[])
{
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 

    glutInitWindowPosition(0,0);
    glutInitWindowSize(960, 720); 
    glutCreateWindow("Kennedy Space Center Command Module");
    glutDisplayFunc(render); 
    
    gluOrtho2D(-550, 550, -500, 900); 

    

    glutMainLoop();

    return 0;
}
