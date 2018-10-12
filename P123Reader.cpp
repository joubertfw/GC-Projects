#include <iostream>
#include <cstdlib>
#include <GL/glut.h>
#include <string>
#include <fstream> 

using namespace std;

class Image
{
    private:
    public:
        int height;
        int width;
        int scale;
        int **r, **g, **b;
        string type;
        string comments;

        int readFile(char *);
        void draw();
        void drawRGBN(char band);

        void readP1(ifstream *fp, int x, int y);
        void readP2(ifstream *fp, int x, int y, int scale);
        void readP3(ifstream *fp, int x, int y, int scale);
};


void Image::readP1(ifstream *fp, int x, int y)
{
    int i, j, bit;    

    for (i = 0; i < y; i++)
    {
        for (j = 0; j < x; j++)
        {
            *fp >> bit;
            r[i][j] = g[i][j] = b[i][j] = bit*255;                    
        }
    }   
}

void Image::readP2(ifstream *fp, int x, int y, int scale)
{
    int i, j, byte;

    for (i = 0; i < y; i++)
    {
        for (j = 0; j < x; j++)
        {
            *fp >> byte;
            r[i][j] = g[i][j] = b[i][j] = byte*(256/scale);
        }
    }    
}


void Image::readP3(ifstream *fp, int x, int y, int scale)
{
    int i, j;

    

    for (i = 0; i < y; i++)
    {
        for (j = 0; j < x; j++)
        {
            *fp >> r[i][j] >> g[i][j] >> b[i][j];           

            r[i][j] *= (256/scale);
            g[i][j] *= (256/scale);
            b[i][j] *= (256/scale); 
            
        }
    }    
}

int Image::readFile(char *path)
{
    int i, j, byte;

    ifstream fp;    
    fp.open(path);

    if (!fp.is_open())
    {
        printf("\nNot possible to open the document: %s\n", path);
        return -2;
    }

    fp >> type >>  width >> height;    

    r = (int**)calloc(height, sizeof(int*)); 
    g = (int**)calloc(height, sizeof(int*)); 
    b = (int**)calloc(height, sizeof(int*)); 

    for (i = 0; i < height; i++)
    { 
        r[i] = (int*)calloc(width, sizeof(int));
        g[i] = (int*)calloc(width, sizeof(int));
        b[i] = (int*)calloc(width, sizeof(int));
    }      
    

    if (type != "P1")
    {
        fp >> scale;

        if (type == "P2")        
            readP2(&fp, width, height, scale);        
        else if (type == "P3")        
            readP3(&fp, width, height, scale);        
    }
    else if (type == "P1")   
    {        
        readP1(&fp, width, height);   
    }      

    fp.close();    

    return 0;
}

void Image::draw()
{
    int i, j;

    glClearColor(1.0, 1.0, 1.0, 0);

    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POINTS);

    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            glColor3ub(r[i][j], g[i][j], b[i][j]);
            glVertex2f(j, i);
        }        
    }    
    
    glEnd();
    glFlush();    
}

void Image::drawRGBN(char band)
{
    int i, j;

    glClearColor(1.0, 1.0, 1.0, 0);

    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POINTS);

    switch (band)
    {
        case 'R':
            for (i = 0; i < height; i++)
            {
                for (j = 0; j < width; j++)
                {
                    glColor3ub(r[i][j], 0, 0);
                    glVertex2f(j, i);
                }        
            } 
        break;
        case 'G':
            for (i = 0; i < height; i++)
            {
                for (j = 0; j < width; j++)
                {
                    glColor3ub(0, g[i][j], 0);
                    glVertex2f(j, i);
                }        
            } 
        break;
        case 'B':
            for (i = 0; i < height; i++)
            {
                for (j = 0; j < width; j++)
                {
                    glColor3ub(0, 0, b[i][j]);
                    glVertex2f(j, i);
                }        
            } 
        break;
         case 'N':
            for (i = 0; i < height; i++)
            {
                for (j = 0; j < width; j++)
                {
                    glColor3ub(255-r[i][j], 255-g[i][j], 255-b[i][j]);
                    glVertex2f(j, i);
                }        
            } 
        break;
        case 'I':
            int red, gre, blu;
            for (i = 0; i < height; i++)
            {
                for (j = 0; j < width; j++)
                {
                    red = r[i][j]-(r[i][j]/10);
                    gre = g[i][j]-(g[i][j]/10);
                    blu = b[i][j]+(b[i][j]/2);

                    blu = (blu > 255) ? 255 : blu;

                    glColor3ub(red, gre, blu);
                    glVertex2f(j, i);
                }        
            } 
        break;
          case 'M':
          int byte;
            for (i = 0; i < height; i++)
            {
                for (j = 0; j < width; j++)
                {
                    byte = (r[i][j] + g[i][j] + b[i][j])/3;
                    glColor3ub(byte, byte, byte);
                    glVertex2f(j, i);
                }        
            } 
        break;
          case 'P':    
            int byteP;      
            for (i = 0; i < height; i++)
            {
                for (j = 0; j < width; j++)
                {
                    byte = (r[i][j] + g[i][j] + b[i][j])/3;
                    byte = (byte > 127) ? 255 : 0;
                    glColor3ub(byte, byte, byte);
                    glVertex2f(j, i);
                }        
            } 
        break;
    }
    
    glEnd();
    glFlush();    
}

Image original, processada;
char band = 'R';

void render()
{
    original.draw();
}

void renderProcessed()
{    
    original.drawRGBN(band);
}
        
void menuMain(int op)
{

}

void MoveMouseBotaoPressionado(int x, int y)
{     
     glutPostRedisplay();
}

void MoveMouse(int x, int y)
{ 
     glutPostRedisplay();
}


void menuBand(int op)
{
   switch(op) {
            case 0:
                band = 'R';                     
                break;
            case 1:
                band = 'G';                     
                break;
            case 2:
                band = 'B';                     
                break;
            case 3:
                band = 'N';                     
                break;
            case 4:
                band = 'I';                     
                break;
            case 5:
                band = 'M';                     
                break;
            case 6:
                band = 'P';                     
                break;
    }
    glutPostRedisplay();
} 

void menuCreate() 
{
    int menu, submenu;


    submenu = glutCreateMenu(menuBand);
    glutAddMenuEntry("Banda R", 0);
    glutAddMenuEntry("Banda G", 1);
    glutAddMenuEntry("Banda B", 2);    
    glutAddMenuEntry("Negativo", 3);
    glutAddMenuEntry("Filtro Instagram", 4);
    glutAddMenuEntry("Monocromatico", 5);
    glutAddMenuEntry("P&B", 6);

    menu = glutCreateMenu(menuMain);
    
    glutAddSubMenu("Bandas e Negativo", submenu);
    
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void GerenciaMouse(int button, int state, int x, int y)
{        
    if (button == GLUT_RIGHT_BUTTON)
         if (state == GLUT_DOWN) 
            menuCreate();
         
    glutPostRedisplay();
}


int main(int argc, char *argv[])
{
    original.readFile(argv[1]);

    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);    

    glutInitWindowPosition(50,50);
    glutInitWindowSize(original.width, original.height);    
    glutCreateWindow("Foto Original");
    glutDisplayFunc(render);     
    glutMotionFunc(MoveMouseBotaoPressionado); 
    glutPassiveMotionFunc(MoveMouse);
    glutMouseFunc(GerenciaMouse);        
    gluOrtho2D(0, original.width, original.height, 0);        

    glutInitWindowPosition(original.width + 100, 50);
    glutInitWindowSize(original.width, original.height);    
    glutCreateWindow("Foto Processada");
    glutDisplayFunc(renderProcessed);     

    gluOrtho2D(0, original.width, original.height, 0);    

    glutMainLoop();

    return 0;
}
