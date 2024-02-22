#include <windows.h>  // for MS Windows
#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#include<math.h>>
#include <stdio.h>
#include <mmsystem.h>
#include <string>
# define PI           3.14159265358979323846



#include <iostream>

using namespace std;

int triangleAmount = 1000;//for first scenario tree
GLfloat twicePi = 2.0f * PI;


//writing character
char* c;

void renderBitmapString(float x, float y, float z, void* font, const std::string& string) {
    glRasterPos3f(x, y, z);
    for (char c : string) {
        glutBitmapCharacter(font, c);
    }
}

//###########3##################################33
//#### shape for vehicles #######################
//#############################################


void DrawCircle(float x, float y, float radius, int triangleAmount)
{
    float twicePi = 2.0f * 3.1415926f;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for (int i = 0; i <= triangleAmount;i++) {
        glVertex2f(
            x + (radius * cos(i * twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

}


void DrawQuad(GLfloat ax, GLfloat ay, GLfloat bx, GLfloat by, GLfloat cx, GLfloat cy, GLfloat dx, GLfloat dy, GLfloat cr, GLfloat cg, GLfloat cb, GLfloat ca = 1.0)
{
    glBegin(GL_QUADS);
    glColor4f(cr, cg, cb, ca);
    glVertex2f(ax, ay);
    glVertex2f(bx, by);
    glVertex2f(cx, cy);
    glVertex2f(dx, dy);
    glEnd();
}



void DrawTriangle(GLfloat ax, GLfloat ay, GLfloat bx, GLfloat by, GLfloat cx, GLfloat cy, GLfloat cr, GLfloat cg, GLfloat cb, GLfloat ca = 1.0)
{
    glBegin(GL_TRIANGLES);
    glColor4f(cr, cg, cb, ca);
    glVertex2f(ax, ay);
    glVertex2f(bx, by);
    glVertex2f(cx, cy);
    glEnd();
}

void coxbazar(int val);
void mid(int val);



GLfloat position = -0.35f;//for the train
GLfloat speed = 0.00f;

GLfloat position2 = 0.0f;//for the 2nd boat of river///vehicles
GLfloat speed2 = 0.025f;//for the 2nd boat of river////vehicles


GLfloat position3 = 0.0f;//for the 3rd boat of river
GLfloat speed3 = 0.002f;//for the 3rd boat of river


GLfloat position4 = 0.0f;//for the 1st boat of river
GLfloat speed4 = -0.001f;//for the 1st boat of river



GLfloat position5 = 0.0f;//for the 1st boat of river
GLfloat speed5 = -0.025f;//for the 1st boat of river


GLfloat position6 = 0.0f;//for the 3rd boat of river
GLfloat speed6 = 0.0005f;//for the 3rd boat of river

GLfloat position7 = 0.0f;//for the 3rd boat of river
GLfloat speed7 = 0.005f;//for the 3rd boat of river


GLfloat car1Pos = 0.0f;
GLfloat car1speed = 0.05f;

GLfloat car2Pos = 0.0f;
GLfloat car2speed = 0.05f;

GLfloat car3Pos = 0.0f;
GLfloat car3speed = 0.05f;

GLfloat car4Pos = 0.0f;
GLfloat car4speed = 0.05f;

GLfloat bus1Pos = 0.0f;
GLfloat bus1speed = 0.05f;



GLfloat position8 = 0.0f;//for the text


GLfloat flag = 0.0f;

int flag1 = 0;
int flag2 = 0;


void update(int value)
{

    if (flag1 == 0 && position > 2.4)
    {
        position = -0.7f;
        flag1 = 1;
        glutTimerFunc(0, mid, 0);

    }

    if (flag1 == 1 && position >= 2.4)
    {

        position = -0.7f;
        flag1 = 2;
        glutTimerFunc(0, coxbazar, 0);
        //speed = 0.00f;
        //PlaySound(NULL, NULL, 0);
    }


    if (flag1 == 2 && position >= 0.9)
    {
        speed = 0.01f;

    }

    if (flag1 == 2 && position >= 1.2)
    {
        speed = 0.0f;
        PlaySound(NULL, NULL, 0);
    }

    position += speed;
    flag += speed;

    glutPostRedisplay();



    glutTimerFunc(100, update, 0);
}






void update2(int value)
{

    if (position2 > 2.4)
    {
        position2 = -1.1;

    }

    position2 += speed2;

    glutPostRedisplay();
    glutTimerFunc(100, update2, 0);
}



void update3(int value)
{

    if (position3 > 4.4)
    {
        position3 = position3;

    }

    position3 += speed3;

    glutPostRedisplay();
    glutTimerFunc(100, update3, 0);
}




void update4(int value)
{

    if (position4 > -4.4)
    {
        position4 = position4;

    }

    position4 += speed4;

    glutPostRedisplay();
    glutTimerFunc(100, update4, 0);
}




void update5(int value)
{

    if (position5 < -2.4)
    {
        position5 = 1.1;

    }

    position5 += speed5;

    glutPostRedisplay();
    glutTimerFunc(100, update5, 0);
}


void update6(int value)
{

    if (position6 > 4.4)
    {
        position6 = position6;

    }

    position6 += speed6;

    glutPostRedisplay();
    glutTimerFunc(100, update6, 0);
}


void update7(int value)
{

    if (position7 > -2.4)
    {
        position7 = 1.1;

    }

    position7 += speed7;

    glutPostRedisplay();
    glutTimerFunc(100, update7, 0);
}




void updateVehicles(int value)
{



    car1Pos += car1speed;
    car2Pos += car2speed;
    car3Pos += car3speed;
    car4Pos += car4speed;
    bus1Pos += bus1speed;

    glutPostRedisplay();
    glutTimerFunc(100, updateVehicles, 0);
}






void Idle()
{
    glutPostRedisplay();//// marks the current window as needing to be redisplayed
}










void information(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.929f, 0.925f, 0.831f, 1.0f);

    glColor3f(1.0, 0.0, 0.0);
    renderBitmapString(-0.3f, 0.91f, 0.0, GLUT_BITMAP_TIMES_ROMAN_24, "Cox's Bazar Railway Station : Changes in nature");
    renderBitmapString(-0.14, 0.84, 0.0, GLUT_BITMAP_TIMES_ROMAN_24, "Computer Graphics [E]");
    renderBitmapString(-0.88, 0.82, 0.0, GLUT_BITMAP_TIMES_ROMAN_24, "Group Member :");
    glLineWidth(4);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.88, 0.8);
    glVertex2f(0.88, 0.8);
    glEnd();
    renderBitmapString(-0.78, 0.74, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "ID");
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.85, 0.73);
    glVertex2f(-0.67, 0.73);
    glEnd();
    renderBitmapString(-0.05, 0.74, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Name");
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.24, 0.73);
    glVertex2f(0.24, 0.73);
    glEnd();


    renderBitmapString(-0.84, 0.66, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "22-46797-1");
    renderBitmapString(-0.22, 0.66, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Kamruzzaman Sony");


    renderBitmapString(-0.84, 0.58, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "22-46410-1");
    renderBitmapString(-0.22, 0.58, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Md. Abdullah Shishir");


    renderBitmapString(-0.84, 0.50, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "22-46611-1");
    renderBitmapString(-0.22, 0.50, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Md. Rifat Al Mostakim");


    renderBitmapString(-0.84, 0.42, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "20-41920-1");
    renderBitmapString(-0.22, 0.42, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Tanvir Anzoom");


    renderBitmapString(-0.84, 0.35, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "21-44991-2");
    renderBitmapString(-0.22, 0.35, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Minhazul Islam Shoikat");


    glLineWidth(4);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.88, 0.27);
    glVertex2f(0.88, 0.27);
    glEnd();
    glPushMatrix();
    glTranslatef(0.0, -0.5, 0.0);
    renderBitmapString(-0.1, 0.28, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Supervised by :");
    renderBitmapString(-0.13, 0.21, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Mahfujur Rahman");
    renderBitmapString(-0.07, 0.15, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Lecturer");
    renderBitmapString(-0.22, 0.09, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Department of Computer Science");
    renderBitmapString(-0.23, 0.01, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Faculty of Science and Technology");
    renderBitmapString(-0.34, -0.05, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "American International University-Bangladesh(AIUB)");
    glPopMatrix();
    glFlush();

}

void display1() {

    glClearColor(0.0f, 0.8f, 0.0f, 0.0f); // Set background color to green and opaque
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer (background)



    glBegin(GL_QUADS);// sky //// sky //// sky //// sky //
    glColor3ub(155, 206, 235);//135,206,235
    glVertex2f(1, 1);
    glVertex2f(-1, 1);
    glVertex2f(-1, .5);
    glVertex2f(1, .5);
    glEnd();



    // cloud
    glPushMatrix();

    glTranslatef(-0.32f, -0.0f, 0.0f); //cloud
    glPushMatrix();
    glScalef(0.790, 0.90, 1);
    glTranslatef(1.3, 0.17, 0);
    {
        glLineWidth(1);

        GLfloat x = -0.92f;
        GLfloat y = .725f;
        GLfloat radius = .055f;

        int lineAmount = 100;

        GLfloat twicePi = 2.0f * PI;

        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(208, 222, 236);
        for (int i = 0; i <= lineAmount; i++)
        {
            glVertex2f(
                x + (radius * cos(i * twicePi / lineAmount)),
                y + (radius * sin(i * twicePi / lineAmount))
            );
        }
        glEnd();


        glLineWidth(1);

        x = -0.765f;
        y = .725f;
        radius = .045f;

        lineAmount = 100;

        twicePi = 2.0f * PI;

        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(208, 222, 236);
        for (int i = 0; i <= lineAmount; i++)
        {
            glVertex2f(
                x + (radius * cos(i * twicePi / lineAmount)),
                y + (radius * sin(i * twicePi / lineAmount))
            );
        }
        glEnd();

        glLineWidth(1);

        x = -0.85f;
        y = .75f;
        radius = .08f;

        lineAmount = 100;

        twicePi = 2.0f * PI;

        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(208, 222, 236);
        for (int i = 0; i <= lineAmount; i++)
        {
            glVertex2f(
                x + (radius * cos(i * twicePi / lineAmount)),
                y + (radius * sin(i * twicePi / lineAmount))
            );
        }
        glEnd();
    }

    glPopMatrix();



    glTranslatef(0.5f, +0.0, 0.0f); //cloud 2
    glPushMatrix();
    glScalef(0.790, 0.90, 1);
    glTranslatef(1.3, 0.17, 0);
    {
        glLineWidth(1);

        GLfloat x = -0.92f;
        GLfloat y = .725f;
        GLfloat radius = .055f;

        int lineAmount = 100;

        GLfloat twicePi = 2.0f * PI;

        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(208, 222, 236);
        for (int i = 0; i <= lineAmount; i++)
        {
            glVertex2f(
                x + (radius * cos(i * twicePi / lineAmount)),
                y + (radius * sin(i * twicePi / lineAmount))
            );
        }
        glEnd();


        glLineWidth(1);

        x = -0.765f;
        y = .725f;
        radius = .045f;

        lineAmount = 100;

        twicePi = 2.0f * PI;

        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(208, 222, 236);
        for (int i = 0; i <= lineAmount; i++)
        {
            glVertex2f(
                x + (radius * cos(i * twicePi / lineAmount)),
                y + (radius * sin(i * twicePi / lineAmount))
            );
        }
        glEnd();

        glLineWidth(1);

        x = -0.85f;
        y = .75f;
        radius = .08f;

        lineAmount = 100;

        twicePi = 2.0f * PI;

        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(208, 222, 236);
        for (int i = 0; i <= lineAmount; i++)
        {
            glVertex2f(
                x + (radius * cos(i * twicePi / lineAmount)),
                y + (radius * sin(i * twicePi / lineAmount))
            );
        }
        glEnd();
    }

    glPopMatrix();


    glTranslatef(-1.0f, +0.1, 0.0f); //cloud 3
    glPushMatrix();
    glScalef(0.790, 0.90, 1);
    glTranslatef(1.3, 0.17, 0);
    {
        glLineWidth(1);

        GLfloat x = -0.92f;
        GLfloat y = .725f;
        GLfloat radius = .055f;

        int lineAmount = 100;

        GLfloat twicePi = 2.0f * PI;

        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(208, 222, 236);
        for (int i = 0; i <= lineAmount; i++)
        {
            glVertex2f(
                x + (radius * cos(i * twicePi / lineAmount)),
                y + (radius * sin(i * twicePi / lineAmount))
            );
        }
        glEnd();


        glLineWidth(1);

        x = -0.765f;
        y = .725f;
        radius = .045f;

        lineAmount = 100;

        twicePi = 2.0f * PI;

        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(208, 222, 236);
        for (int i = 0; i <= lineAmount; i++)
        {
            glVertex2f(
                x + (radius * cos(i * twicePi / lineAmount)),
                y + (radius * sin(i * twicePi / lineAmount))
            );
        }
        glEnd();

        glLineWidth(1);

        x = -0.85f;
        y = .75f;
        radius = .08f;

        lineAmount = 100;

        twicePi = 2.0f * PI;

        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(208, 222, 236);
        for (int i = 0; i <= lineAmount; i++)
        {
            glVertex2f(
                x + (radius * cos(i * twicePi / lineAmount)),
                y + (radius * sin(i * twicePi / lineAmount))
            );
        }
        glEnd();
    }

    glPopMatrix();

    glPushMatrix();
    glScalef(0.790, 0.90, 1);
    glTranslatef(1.3, 0.17, 0);
    {
        glLineWidth(1);

        GLfloat x = -0.92f;
        GLfloat y = .725f;
        GLfloat radius = .055f;

        int lineAmount = 100;

        GLfloat twicePi = 2.0f * PI;

        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(208, 222, 236);
        for (int i = 0; i <= lineAmount; i++)
        {
            glVertex2f(
                x + (radius * cos(i * twicePi / lineAmount)),
                y + (radius * sin(i * twicePi / lineAmount))
            );
        }
        glEnd();


        glLineWidth(1);

        x = -0.765f;
        y = .725f;
        radius = .045f;

        lineAmount = 100;

        twicePi = 2.0f * PI;

        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(208, 222, 236);
        for (int i = 0; i <= lineAmount; i++)
        {
            glVertex2f(
                x + (radius * cos(i * twicePi / lineAmount)),
                y + (radius * sin(i * twicePi / lineAmount))
            );
        }
        glEnd();

        glLineWidth(1);

        x = -0.85f;
        y = .75f;
        radius = .08f;

        lineAmount = 100;

        twicePi = 2.0f * PI;

        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(208, 222, 236);
        for (int i = 0; i <= lineAmount; i++)
        {
            glVertex2f(
                x + (radius * cos(i * twicePi / lineAmount)),
                y + (radius * sin(i * twicePi / lineAmount))
            );
        }
        glEnd();
    }

    glPopMatrix();
    glPopMatrix();
    glLoadIdentity();









    glPopMatrix();










    //hill01
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.4f, 0.0f);
    // if(night)
    // {
     //    glColor3f(0.09, 0.20, 0.09);
    // }
    glVertex2f(-1.0f, 0.5f);
    glVertex2f(-1.0f, 0.65f);


    glVertex2f(-1.0f, 0.65f);
    glVertex2f(-0.97f, 0.68f);

    glVertex2f(-0.97f, 0.68f);
    glVertex2f(-0.95f, 0.66f);

    glVertex2f(-0.95f, 0.66f);
    glVertex2f(-0.9f, 0.75f);

    glVertex2f(-0.9f, 0.75f);
    glVertex2f(-0.87f, 0.73f);

    glVertex2f(-0.87f, 0.73f);
    glVertex2f(-0.84f, 0.66f);

    glVertex2f(-0.84f, 0.66f);
    glVertex2f(-0.8f, 0.7f);

    glVertex2f(-0.8f, 0.7f);
    glVertex2f(-0.78f, 0.68f);

    glVertex2f(-0.78f, 0.68f);
    glVertex2f(-0.73f, 0.73f);

    glVertex2f(-0.73f, 0.73f);
    glVertex2f(-0.68f, 0.64f);

    glVertex2f(-0.68f, 0.64f);
    glVertex2f(-0.65f, 0.67f);

    glVertex2f(-0.65f, 0.67f);
    glVertex2f(-0.58f, 0.58f);

    glVertex2f(-0.58f, 0.58f);
    glVertex2f(-0.55f, 0.6f);

    glVertex2f(-0.55f, 0.6f);
    glVertex2f(-0.5f, 0.5f);



    glEnd();







    //hill6

    glPushMatrix();
    glTranslatef(1.3f, 0.0f, 0.0f);

    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.3f, 0.0f);
    //    if(night)
    //    {
    //        glColor3f(0.00, 0.20, 0.00);
    //    }

    glVertex2f(-0.65f, 0.5f);
    glVertex2f(-0.63f, 0.55f);

    glVertex2f(-0.63f, 0.55f);
    glVertex2f(-0.61f, 0.53f);

    glVertex2f(-0.61f, 0.53f);
    glVertex2f(-0.55f, 0.65f);

    glVertex2f(-0.55f, 0.65f);
    glVertex2f(-0.52f, 0.63f);

    glVertex2f(-0.52f, 0.63f);
    glVertex2f(-0.5f, 0.68f);

    glVertex2f(-0.5f, 0.68f);
    glVertex2f(-0.47f, 0.66f);

    glVertex2f(-0.47f, 0.66f);
    glVertex2f(-0.44f, 0.73f);

    glVertex2f(-0.44f, 0.73f);
    glVertex2f(-0.4f, 0.7f);

    glVertex2f(-0.4f, 0.7f);
    glVertex2f(-0.35f, 0.62f);

    glVertex2f(-0.35f, 0.62f);
    glVertex2f(-0.3f, 0.66f);

    glVertex2f(-0.3f, 0.66f);
    glVertex2f(-0.28f, 0.63f);

    glVertex2f(-0.28f, 0.63f);
    glVertex2f(-0.24f, 0.69f);

    glVertex2f(-0.24f, 0.69f);
    glVertex2f(-0.18f, 0.58f);

    glVertex2f(-0.18f, 0.58f);
    glVertex2f(-0.15f, 0.6f);

    glVertex2f(-0.15f, 0.6f);
    glVertex2f(-0.11f, 0.55f);

    glVertex2f(-0.11f, 0.55f);
    glVertex2f(-0.1f, 0.5f);

    glEnd();

    glPopMatrix();

    ///////////////////////////////
    ////////////building///////////
     ///////////////////////////



    glPushMatrix(); // Save the current matrix

    glTranslatef(0.0, 0.5, 0.0); // Translate one unit to the right
    glScalef(0.7, 1.0, 1.0);      // Scale by a factor of 2 in both x and y

    {



        ///////////////////////////////////////////////////////////
        glBegin(GL_POLYGON);
        glColor3ub(123, 203, 7);
        glVertex2f(0.8f, 0.0f);
        glVertex2f(0.97f, 0.0f);
        glVertex2f(0.97f, 0.3f);
        glVertex2f(0.8f, 0.3f);
        glEnd();
        glBegin(GL_POLYGON);
        glColor3ub(123, 180, 27);
        glVertex2f(0.77f, 0.0f);
        glVertex2f(0.8f, 0.0f);
        glVertex2f(0.8f, 0.3f);
        glVertex2f(0.77f, 0.28f);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3f(0.0f, .7f, .8f);
        glVertex2f(0.82f, 0.02f);
        glVertex2f(0.875f, 0.02f);
        glVertex2f(0.875f, 0.12f);
        glVertex2f(0.82f, 0.12f);
        glEnd();
        glBegin(GL_POLYGON);
        glColor3f(0.0f, .7f, .8f);
        glVertex2f(0.82f, 0.16f);
        glVertex2f(0.875f, 0.16f);
        glVertex2f(0.875f, 0.28f);
        glVertex2f(0.82f, 0.28f);
        glEnd();
        glBegin(GL_POLYGON);
        glColor3f(0.0f, .7f, .8f);
        glVertex2f(0.895f, 0.02f);
        glVertex2f(0.95f, 0.02f);
        glVertex2f(0.95f, 0.12f);
        glVertex2f(0.895f, 0.12f);
        glEnd();
        glBegin(GL_POLYGON);
        glColor3f(0.0f, .7f, .8f);
        glVertex2f(0.895f, 0.16f);
        glVertex2f(0.95f, 0.16f);
        glVertex2f(0.95f, 0.28f);
        glVertex2f(0.895f, 0.28f);
        glEnd();
        //////////////////////////////////////////////////////////////
        glBegin(GL_POLYGON);
        glColor3ub(117, 112, 74);
        glVertex2f(0.62f, 0.0f);
        glVertex2f(0.75f, 0.0f);
        glVertex2f(0.75f, 0.4f);
        glVertex2f(0.62f, 0.4f);
        glEnd();
        glBegin(GL_POLYGON);
        glColor3ub(87, 83, 57);
        glVertex2f(0.60f, 0.0f);
        glVertex2f(0.62f, 0.0f);
        glVertex2f(0.62f, 0.4f);
        glVertex2f(0.60f, 0.38f);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3f(0.0f, .7f, .8f);
        glVertex2f(0.64f, 0.04f);
        glVertex2f(0.73f, 0.04f);
        glVertex2f(0.73f, 0.14f);
        glVertex2f(0.64f, 0.14f);
        glEnd();
        glBegin(GL_POLYGON);
        glColor3f(0.0f, .7f, .8f);
        glVertex2f(0.64, 0.16f);
        glVertex2f(0.73f, 0.16f);
        glVertex2f(0.73f, 0.26f);
        glVertex2f(0.64f, 0.26f);
        glEnd();
        glBegin(GL_POLYGON);
        glColor3f(0.0f, .7f, .8f);
        glVertex2f(0.64f, 0.28f);
        glVertex2f(0.73f, 0.28f);
        glVertex2f(0.73f, 0.38f);
        glVertex2f(0.64f, 0.38f);
        glEnd();
        /////////////////////////////////////////////////////////
        glBegin(GL_POLYGON);
        glColor3ub(122, 17, 28);
        glVertex2f(0.4f, 0.0f);
        glVertex2f(0.58f, 0.0f);
        glVertex2f(0.58f, 0.24f);
        glVertex2f(0.4f, 0.24f);
        glEnd();
        glBegin(GL_POLYGON);
        glColor3ub(84, 19, 56);
        glVertex2f(0.38f, 0.0f);
        glVertex2f(0.4f, 0.0f);
        glVertex2f(0.4f, 0.24f);
        glVertex2f(0.38f, 0.21f);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3f(0.0f, .7f, .8f);
        glVertex2f(0.42f, 0.02f);
        glVertex2f(0.48f, 0.02f);
        glVertex2f(0.48f, 0.11f);
        glVertex2f(0.42f, 0.11f);
        glEnd();
        glBegin(GL_POLYGON);
        glColor3f(0.0f, .7f, .8f);
        glVertex2f(0.50f, 0.13f);
        glVertex2f(0.56f, 0.13f);
        glVertex2f(0.56f, 0.22f);
        glVertex2f(0.50f, 0.22f);
        glEnd();
        glBegin(GL_POLYGON);
        glColor3f(0.0f, .7f, .8f);
        glVertex2f(0.50f, 0.02f);
        glVertex2f(0.56f, 0.02f);
        glVertex2f(0.56f, 0.11f);
        glVertex2f(0.50f, 0.11f);
        glEnd();
        glBegin(GL_POLYGON);
        glColor3f(0.0f, .7f, .8f);
        glVertex2f(0.42f, 0.13f);
        glVertex2f(0.48f, 0.13f);
        glVertex2f(0.48f, 0.22f);
        glVertex2f(0.42f, 0.22f);
        glEnd();
        //////////////////////////////////////////////////////////////
        glBegin(GL_POLYGON);
        glColor3ub(74, 6, 122);
        glVertex2f(0.22f, 0.0f);
        glVertex2f(0.36f, 0.0f);
        glVertex2f(0.36f, 0.35f);
        glVertex2f(0.22f, 0.35f);
        glEnd();
        glBegin(GL_POLYGON);
        glColor3ub(38, 4, 61);
        glVertex2f(0.20f, 0.0f);
        glVertex2f(0.22f, 0.0f);
        glVertex2f(0.22f, 0.35f);
        glVertex2f(0.20f, 0.33f);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3f(.0f, .7f, .8f);
        glVertex2f(0.24f, 0.02f);
        glVertex2f(0.34f, 0.02f);
        glVertex2f(0.34f, 0.11f);
        glVertex2f(0.24f, 0.11f);
        glEnd();
        glBegin(GL_POLYGON);
        glColor3f(0.0f, .7f, .8f);
        glVertex2f(0.24f, 0.13f);
        glVertex2f(0.34f, 0.13f);
        glVertex2f(0.34f, 0.22f);
        glVertex2f(0.24f, 0.22f);
        glEnd();
        glBegin(GL_POLYGON);
        glColor3f(0.0f, .7f, .8f);
        glVertex2f(0.24f, 0.24f);
        glVertex2f(0.34f, 0.24f);
        glVertex2f(0.34f, 0.33f);
        glVertex2f(0.24f, 0.33f);
        glEnd();
        ///////////////////////////////////////////////////////////////
        glBegin(GL_POLYGON);
        glColor3ub(131, 131, 133);
        glVertex2f(0.15f, 0.0f);
        glVertex2f(0.18f, 0.0f);
        glVertex2f(0.18f, 0.37f);
        glVertex2f(0.15f, 0.4f);
        glEnd();
        glBegin(GL_POLYGON);
        glColor3ub(203, 203, 187);
        glVertex2f(-0.1f, 0.0f);
        glVertex2f(0.15f, 0.0f);
        glVertex2f(0.15f, 0.4f);
        glVertex2f(-0.1f, 0.4f);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3f(0.0f, .7f, .8f);
        glVertex2f(-0.08f, 0.02f);
        glVertex2f(0.01f, 0.02f);
        glVertex2f(0.01f, 0.19f);
        glVertex2f(-0.08f, 0.19f);
        glEnd();
        glBegin(GL_POLYGON);
        glColor3f(0.0f, .7f, .8f);
        glVertex2f(0.03f, 0.02f);
        glVertex2f(0.13f, 0.02f);
        glVertex2f(0.13f, 0.19f);
        glVertex2f(0.03f, 0.19f);
        glEnd();
        glBegin(GL_POLYGON);
        glColor3f(0.0f, .7f, .8f);
        glVertex2f(-0.08f, 0.21f);
        glVertex2f(0.01f, 0.21f);
        glVertex2f(0.01f, 0.38f);
        glVertex2f(-0.08f, 0.38f);
        glEnd();
        glBegin(GL_POLYGON);
        glColor3f(0.0f, .7f, .8f);
        glVertex2f(0.03f, 0.21f);
        glVertex2f(0.13f, 0.21f);
        glVertex2f(0.13f, 0.38f);
        glVertex2f(0.03f, 0.38f);
        glEnd();
        ////////////////////////////////////////////////////////////
        glBegin(GL_POLYGON);
        glColor3ub(22, 33, 130);
        glVertex2f(-0.24f, 0.0f);
        glVertex2f(-0.12f, 0.0f);
        glVertex2f(-0.12f, 0.45f);
        glVertex2f(-0.24f, 0.45f);
        glEnd();
        glBegin(GL_POLYGON);
        glColor3ub(11, 18, 77);
        glVertex2f(-0.26f, 0.0f);
        glVertex2f(-0.24f, 0.0f);
        glVertex2f(-0.24f, 0.45f);
        glVertex2f(-0.26f, 0.43f);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3f(0.0f, .7f, .8f);
        glVertex2f(-0.22f, 0.03f);
        glVertex2f(-0.14f, 0.03f);
        glVertex2f(-0.14f, 0.15f);
        glVertex2f(-0.22f, 0.15f);
        glEnd();
        glBegin(GL_POLYGON);
        glColor3f(0.0f, .7f, .8f);
        glVertex2f(-0.22f, 0.17f);
        glVertex2f(-0.14f, 0.17f);
        glVertex2f(-0.14f, 0.29f);
        glVertex2f(-0.22f, 0.29f);
        glEnd();
        glBegin(GL_POLYGON);
        glColor3f(0.0f, .7f, .8f);
        glVertex2f(-0.22f, 0.31f);
        glVertex2f(-0.14f, 0.31f);
        glVertex2f(-0.14f, 0.43f);
        glVertex2f(-0.22f, 0.43f);
        glEnd();
        ////////////////////////////////////////////////////////////
        glBegin(GL_POLYGON);
        glColor3ub(90, 145, 138);
        glVertex2f(-0.48f, 0.0f);
        glVertex2f(-0.31f, 0.0f);
        glVertex2f(-0.31f, 0.37f);
        glVertex2f(-0.48f, 0.37f);
        glEnd();
        glBegin(GL_POLYGON);
        glColor3ub(56, 92, 87);
        glVertex2f(-0.31f, 0.0f);
        glVertex2f(-0.28f, 0.0f);
        glVertex2f(-0.28f, 0.34f);
        glVertex2f(-0.31f, 0.37f);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3f(0.0f, .7f, .8f);
        glVertex2f(-0.46f, 0.02f);
        glVertex2f(-0.41f, 0.02f);
        glVertex2f(-0.41f, 0.12f);
        glVertex2f(-0.46f, 0.12f);
        glEnd();
        glBegin(GL_POLYGON);
        glColor3f(0.0f, .7f, .8f);
        glVertex2f(-0.46f, 0.14f);
        glVertex2f(-0.41f, 0.14f);
        glVertex2f(-0.41f, 0.24f);
        glVertex2f(-0.46f, 0.24f);
        glEnd();
        glBegin(GL_POLYGON);
        glColor3f(0.0f, .7f, .8f);
        glVertex2f(-0.46f, 0.26f);
        glVertex2f(-0.41f, 0.26f);
        glVertex2f(-0.41f, 0.36f);
        glVertex2f(-0.46f, 0.36f);
        glEnd();
        glBegin(GL_POLYGON);
        glColor3f(0.0f, .7f, .8f);
        glVertex2f(-0.38f, 0.02f);
        glVertex2f(-0.33f, 0.02f);
        glVertex2f(-0.33f, 0.12f);
        glVertex2f(-0.38f, 0.12f);
        glEnd();
        glBegin(GL_POLYGON);
        glColor3f(0.0f, .7f, .8f);
        glVertex2f(-0.38f, 0.14f);
        glVertex2f(-0.33f, 0.14f);
        glVertex2f(-0.33f, 0.24f);
        glVertex2f(-0.38f, 0.24f);
        glEnd();
        glBegin(GL_POLYGON);
        glColor3f(0.0f, .7f, .8f);
        glVertex2f(-0.38f, 0.26f);
        glVertex2f(-0.33f, 0.26f);
        glVertex2f(-0.33f, 0.36f);
        glVertex2f(-0.38f, 0.36f);
        glEnd();
        ///////////////////////////////////////////////////////////////
        glBegin(GL_POLYGON);
        glColor3ub(117, 112, 74);
        glVertex2f(-0.52f, 0.0f);
        glVertex2f(-0.50f, 0.0f);
        glVertex2f(-0.50f, 0.48f);
        glVertex2f(-0.52f, 0.5f);
        glEnd();
        glBegin(GL_POLYGON);
        glColor3ub(117, 112, 100);
        glVertex2f(-0.66f, 0.0f);
        glVertex2f(-0.52f, 0.0f);
        glVertex2f(-0.52f, 0.5f);
        glVertex2f(-0.66f, 0.5f);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3f(0.f, .7f, .8f);
        glVertex2f(-0.64f, 0.02f);
        glVertex2f(-0.54f, 0.02f);
        glVertex2f(-0.54f, 0.12f);
        glVertex2f(-0.64f, 0.12f);
        glEnd();
        glBegin(GL_POLYGON);
        glColor3f(0.f, .7f, .8f);
        glVertex2f(-0.64f, 0.14f);
        glVertex2f(-0.54f, 0.14f);
        glVertex2f(-0.54f, 0.24f);
        glVertex2f(-0.64f, 0.24f);
        glEnd();
        glBegin(GL_POLYGON);
        glColor3f(0.f, .7f, .8f);
        glVertex2f(-0.64f, 0.26f);
        glVertex2f(-0.54f, 0.26f);
        glVertex2f(-0.54f, 0.36f);
        glVertex2f(-0.64f, 0.36f);
        glEnd();
        glBegin(GL_POLYGON);
        glColor3f(0.f, .7f, .8f);
        glVertex2f(-0.64f, 0.38f);
        glVertex2f(-0.54f, 0.38f);
        glVertex2f(-0.54f, 0.48f);
        glVertex2f(-0.64f, 0.48f);
        glEnd();
        ////////////////////////////////////////////////////////////////
        glBegin(GL_POLYGON);
        glColor3ub(22, 33, 130);
        glVertex2f(-0.7f, 0.0f);
        glVertex2f(-0.68f, 0.0f);
        glVertex2f(-0.68f, 0.18f);
        glVertex2f(-0.7f, 0.2f);
        glEnd();
        glBegin(GL_POLYGON);
        glColor3ub(22, 33, 130);
        glVertex2f(-0.83f, 0.0f);
        glVertex2f(-0.7f, 0.0f);
        glVertex2f(-0.7f, 0.2f);
        glVertex2f(-0.83f, 0.2f);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3f(0.f, .7f, .8f);
        glVertex2f(-0.81f, 0.02f);
        glVertex2f(-0.775f, 0.02f);
        glVertex2f(-0.775f, 0.09f);
        glVertex2f(-0.81f, 0.09f);
        glEnd();
        glBegin(GL_POLYGON);
        glColor3f(0.f, .7f, .8f);
        glVertex2f(-0.755f, 0.02f);
        glVertex2f(-0.72f, 0.02f);
        glVertex2f(-0.72f, 0.09f);
        glVertex2f(-0.755f, 0.09f);
        glEnd();
        glBegin(GL_POLYGON);
        glColor3f(0.f, .7f, .8f);
        glVertex2f(-0.81f, 0.11f);
        glVertex2f(-0.775f, 0.11f);
        glVertex2f(-0.775f, 0.18f);
        glVertex2f(-0.81f, 0.18f);
        glEnd();
        glBegin(GL_POLYGON);
        glColor3f(0.f, .7f, .8f);
        glVertex2f(-0.755f, 0.11f);
        glVertex2f(-0.72f, 0.11f);
        glVertex2f(-0.72f, 0.18f);
        glVertex2f(-0.755f, 0.18f);
        glEnd();
        //////////////////////////////////////////////////////////////////////
        glBegin(GL_POLYGON);
        glColor3ub(179, 168, 50);
        glVertex2f(-0.87f, 0.0f);
        glVertex2f(-0.85f, 0.0f);
        glVertex2f(-0.85f, 0.23f);
        glVertex2f(-0.87f, 0.25f);
        glEnd();
        glBegin(GL_POLYGON);
        glColor3ub(196, 183, 41);
        glVertex2f(-0.97f, 0.0f);
        glVertex2f(-0.87f, 0.0f);
        glVertex2f(-0.87f, 0.25f);
        glVertex2f(-0.97f, 0.25f);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3f(0.f, .7f, .8f);
        glVertex2f(-0.95f, 0.03f);
        glVertex2f(-0.89f, 0.03f);
        glVertex2f(-0.89f, 0.12f);
        glVertex2f(-0.95f, 0.12f);
        glEnd();
        glBegin(GL_POLYGON);
        glColor3f(0.f, .7f, .8f);
        glVertex2f(-0.95f, 0.14f);
        glVertex2f(-0.89f, 0.14f);
        glVertex2f(-0.89f, 0.23f);
        glVertex2f(-0.95f, 0.23f);
        glEnd();

    }

    glPopMatrix();





    //house 1//house 1//house 1//house 1//house 1//house 1//house 1//house 1//house 1

    glPushMatrix();
    glScalef(0.4, 0.9, 1);
    glTranslatef(0.5, -0.438, 0);
    {


        glBegin(GL_QUADS);//Large Building//Large Building//Large Building//Large Building//Large Building
        glColor3ub(203, 203, 187);
        glVertex2f(0.5, 0.65);
        glVertex2f(-0.0, 0.65);
        glVertex2f(-0.0, 0.25);
        glVertex2f(0.5, 0.25);
        glEnd();


        glBegin(GL_LINES);//black 1st line
        glColor3f(0, 0, 0);
        glVertex2f(0.5, 0.65);
        glVertex2f(0.0, 0.65);
        glEnd();

        glBegin(GL_LINES);//black 2nd line
        glColor3f(0, 0, 0);
        glVertex2f(0.5, 0.5);
        glVertex2f(0.0, 0.5);
        glEnd();

        glBegin(GL_LINES);//black 3rd line
        glColor3f(0, 0, 0);
        glVertex2f(0.5, 0.35);
        glVertex2f(0.0, 0.35);
        glEnd();

        glBegin(GL_LINES);//black y axis  line
        glColor3f(0, 0, 0);
        glVertex2f(0.25, 0.65);
        glVertex2f(0.25, 0.35);
        glEnd();


        glBegin(GL_QUADS);//door
        glColor3ub(205, 153, 130);
        glVertex2f(0.32, 0.33);
        glVertex2f(0.17, 0.33);
        glVertex2f(0.17, 0.25);
        glVertex2f(0.32, 0.25);
        glEnd();




        glEnable(GL_LIGHTING);//Enable Light Effect

        GLfloat global_ambient[] = { 5,5,0.0, 0.1 };//ambient RGBA intensity of light
        glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient);//A lighting model parameter.
        //lighting

        glEnable(GL_LIGHTING);//Enable Light Effect


        glBegin(GL_QUADS);//mini window 1
        glColor3ub(228, 228, 228);
        glVertex2f(0.14, 0.59);
        glVertex2f(0.07, 0.59);
        glVertex2f(0.07, 0.54);
        glVertex2f(0.14, 0.54);
        glEnd();


        glBegin(GL_QUADS);//mini window 2
        glColor3ub(228, 228, 228);
        glVertex2f(0.43, 0.59);
        glVertex2f(0.36, 0.59);
        glVertex2f(0.36, 0.54);
        glVertex2f(0.43, 0.54);
        glEnd();


        glBegin(GL_QUADS);//mini window 3
        glColor3ub(228, 228, 228);
        glVertex2f(0.14, 0.44);
        glVertex2f(0.07, 0.44);
        glVertex2f(0.07, 0.39);
        glVertex2f(0.14, 0.39);
        glEnd();

        glBegin(GL_QUADS);//mini window 4
        glColor3ub(228, 228, 228);
        glVertex2f(0.43, 0.44);
        glVertex2f(0.36, 0.44);
        glVertex2f(0.36, 0.39);
        glVertex2f(0.43, 0.39);
        glEnd();

        glDisable(GL_LIGHTING);//disable Light Effect

    }
    glPopMatrix();

    //house 1 end



    //house 2 //house 2//house 2//house 2//house 2




    glPushMatrix();
    glScalef(0.4, 0.9, 1);
    glTranslatef(1.9, -0.438, 0);
    {
        glBegin(GL_QUADS);//mini Building//mini Building//mini Building//mini Building//mini Building
        glColor3ub(204, 93, 83);
        glVertex2f(-0.05, 0.5);
        glVertex2f(-0.5, 0.5);
        glVertex2f(-0.5, 0.25);
        glVertex2f(-0.05, 0.25);
        glEnd();

        glBegin(GL_LINES);//black 1st line
        glColor3f(0, 0, 0);
        glVertex2f(-0.05, 0.5);
        glVertex2f(-0.5, 0.5);
        glEnd();

        glBegin(GL_LINES);////black 2nd  line
        glColor3f(0, 0, 0);
        glVertex2f(-0.05, 0.35);
        glVertex2f(-0.5, 0.35);
        glEnd();

        glBegin(GL_LINES);//black y axis  line
        glColor3f(0, 0, 0);
        glVertex2f(-0.27, 0.5);
        glVertex2f(-0.27, 0.35);
        glEnd();


        glBegin(GL_QUADS);//door
        glColor3ub(205, 153, 130);
        glVertex2f(-0.19, 0.31);
        glVertex2f(-0.34, 0.31);
        glVertex2f(-0.34, 0.25);
        glVertex2f(-0.19, 0.25);
        glEnd();



        glEnable(GL_LIGHTING);
        glBegin(GL_QUADS);//mini window 1
        glColor3ub(228, 228, 228);
        glVertex2f(-0.37, 0.44);
        glVertex2f(-0.44, 0.44);
        glVertex2f(-0.44, 0.39);
        glVertex2f(-0.37, 0.39);
        glEnd();

        glBegin(GL_QUADS);//mini window 2
        glColor3ub(228, 228, 228);
        glVertex2f(-0.12, 0.44);
        glVertex2f(-0.19, 0.44);
        glVertex2f(-0.19, 0.39);
        glVertex2f(-0.12, 0.39);
        glEnd();

        glDisable(GL_LIGHTING);
    }
    glPopMatrix();

    //house mini end



    //#######################################
//##########ROAD--1##############################33
//#######################################

     //road only //road only //road only //road only //road only
    glBegin(GL_QUADS);
    glColor3ub(58, 58, 62);
    glVertex2f(1, 0.5);
    glVertex2f(-1, 0.5);
    glVertex2f(-1, 0.2);
    glVertex2f(1, 0.2);
    glEnd();

    //road side white line
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2f(1, 0.48);
    glVertex2f(-1, 0.48);
    glVertex2f(-1, 0.50);
    glVertex2f(1, 0.50);
    glEnd();

    //road side black line
    float c1, c2, increment2;
    c1 = -1.0;
    c2 = -0.95;
    increment2 = 0;

    for (int i = 0; i < 40; i++)
    {

        glBegin(GL_QUADS);
        glColor3ub(0, 0, 0);
        glVertex2f(c1 + increment2, 0.48);
        glVertex2f(c2 + increment2, 0.48);
        glVertex2f(c2 + increment2, 0.50);
        glVertex2f(c1 + increment2, 0.50);
        glEnd();
        increment2 = increment2 + 0.1;

    }






    //road down side white line
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2f(1, 0.20);
    glVertex2f(-1, 0.20);
    glVertex2f(-1, 0.22);
    glVertex2f(1, 0.22);
    glEnd();

    //road down side black line
    //float c1,c2,increment2;
    c1 = -1.0;
    c2 = -0.95;
    increment2 = 0;

    for (int i = 0; i < 40; i++)
    {

        glBegin(GL_QUADS);
        glColor3ub(0, 0, 0);
        glVertex2f(c1 + increment2, 0.20);
        glVertex2f(c2 + increment2, 0.20);
        glVertex2f(c2 + increment2, 0.22);
        glVertex2f(c1 + increment2, 0.22);
        glEnd();
        increment2 = increment2 + 0.1;

    }





    //road white line//road white line//road white line
    //float c1,c2,increment2;
    c1 = -0.89;
    c2 = -0.97;
    increment2 = 0;

    for (int i = 0; i < 20; i++)
    {

        glBegin(GL_QUADS);
        glColor3ub(255, 255, 255);
        glVertex2f(c1 + increment2, 0.33);
        glVertex2f(c2 + increment2, 0.33);
        glVertex2f(c2 + increment2, 0.37);
        glVertex2f(c1 + increment2, 0.37);
        glEnd();
        increment2 = increment2 + 0.2;

    }




    //#######################################
    //##########ROAD--2##############################33
    //#######################################

         //road only //road only //road only //road only //road only
    glBegin(GL_QUADS);
    glColor3ub(58, 58, 62);
    glVertex2f(1, -0.17);
    glVertex2f(-1, -0.17);
    glVertex2f(-1, -0.47);
    glVertex2f(1, -0.47);
    glEnd();

    //road side white line
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2f(1, -0.19);
    glVertex2f(-1, -0.19);
    glVertex2f(-1, -0.17);
    glVertex2f(1, -0.17);
    glEnd();

    //road side black line
    //float c1,c2,increment2;
    c1 = -1.0;
    c2 = -0.95;
    increment2 = 0;

    for (int i = 0; i < 40; i++)
    {

        glBegin(GL_QUADS);
        glColor3ub(0, 0, 0);
        glVertex2f(c1 + increment2, -0.19);
        glVertex2f(c2 + increment2, -0.19);
        glVertex2f(c2 + increment2, -0.17);
        glVertex2f(c1 + increment2, -0.17);
        glEnd();
        increment2 = increment2 + 0.1;

    }






    //road down side white line
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2f(1, -0.47);
    glVertex2f(-1, -0.47);
    glVertex2f(-1, -0.45);
    glVertex2f(1, -0.45);
    glEnd();

    //road down side black line
    //float c1,c2,increment2;
    c1 = -1.0;
    c2 = -0.95;
    increment2 = 0;

    for (int i = 0; i < 40; i++)
    {

        glBegin(GL_QUADS);
        glColor3ub(0, 0, 0);
        glVertex2f(c1 + increment2, -0.47);
        glVertex2f(c2 + increment2, -0.47);
        glVertex2f(c2 + increment2, -0.45);
        glVertex2f(c1 + increment2, -0.45);
        glEnd();
        increment2 = increment2 + 0.1;

    }





    //road white line//road white line//road white line
    //float c1,c2,increment2;
    c1 = -0.89;
    c2 = -0.97;
    increment2 = 0;

    for (int i = 0; i < 20; i++)
    {

        glBegin(GL_QUADS);
        glColor3ub(255, 255, 255);
        glVertex2f(c1 + increment2, -0.34);
        glVertex2f(c2 + increment2, -0.34);
        glVertex2f(c2 + increment2, -0.30);
        glVertex2f(c1 + increment2, -0.30);
        glEnd();
        increment2 = increment2 + 0.2;

    }





    //car1 left to right:
    glPushMatrix();
    glScalef(.7, .7, 1);
    glTranslated(position2, -0.2f, 0.0f);
    glBegin(GL_POLYGON);

    glColor3f(0.0f, .75f, .50f);
    glVertex2f(-.75, -.09);
    glVertex2f(-.80, -.09);
    glVertex2f(-.80, -0.15);
    glVertex2f(-.50, -0.15);
    glVertex2f(-.50, -.11);
    glVertex2f(-.60, -.09);
    glVertex2f(-.65, -.04);
    glEnd();
    glColor3f(1.0f, 1.f, 1.0f);
    DrawCircle(-.72, -.15, .03, 200);
    DrawCircle(-.60, -.15, .03, 200);
    glPopMatrix();


    //car1 end:


    //car2 left to right:

    glPushMatrix();
    glTranslated(position2, -0.27f, 0.0f);
    glScalef(0.7, 0.7, 1);
    glBegin(GL_POLYGON);
    glColor3f(0.50f, .0f, .75f);
    glVertex2f(.50, -.09);
    glVertex2f(.45, -.09);
    glVertex2f(.45, -0.15);
    glVertex2f(.75, -0.15);
    glVertex2f(.75, -.11);
    glVertex2f(.65, -.09);
    glVertex2f(.55, -.04);
    glEnd();
    glColor3f(1.0f, 1.f, 1.0f);
    DrawCircle(.52, -.15, .03, 200);
    DrawCircle(.65, -.15, .03, 200);
    glPopMatrix();
    //car2 end



    //bus left to right:


    glPushMatrix();
    glTranslated(position2, -0.27f, 0.0f);
    glScalef(0.7, 0.7, 1);
    DrawQuad(-.35f, -.04f, -.35f, -.18f, .10f, -.18f, .10f, -.04f, 1.0f, 0.0f, 0.0f);
    DrawQuad(-.30f, -.11f, -.30f, -.06f, -.33f, -.06f, -.33f, -.11f, 0.75f, 0.50f, 0.35f);
    DrawQuad(-.27f, -.11f, -.27f, -.06f, -.24f, -.06f, -.24f, -.11f, 0.75f, 0.50f, 0.35f);
    DrawQuad(-.21f, -.11f, -.21f, -.06f, -.18f, -.06f, -.18f, -.11f, 0.75f, 0.50f, 0.35f);
    DrawQuad(-.15f, -.11f, -.15f, -.06f, -.12f, -.06f, -.12f, -.11f, 0.75f, 0.50f, 0.35f);
    DrawQuad(-.09f, -.11f, -.09f, -.06f, -.06f, -.06f, -.06f, -.11f, 0.75f, 0.50f, 0.35f);
    DrawQuad(-.03f, -.11f, -.03f, -.06f, -0.0f, -.06f, -0.0f, -.11f, 0.75f, 0.50f, 0.35f);
    DrawQuad(.03f, -.11f, .03f, -.06f, .06f, -.06f, .06f, -.11f, 0.75f, 0.50f, 0.35f);
    glColor3f(1.0f, 1.f, 1.0f);
    DrawCircle(-.20, -.18, .03, 200);
    DrawCircle(0.0, -.18, .03, 200);


    glPopMatrix();
    //bus end


    //car-3 right to left"

    glPushMatrix();
    glTranslated(position5, 0.57f, 0.0f);
    glScalef(0.7, 0.7, 1);

    glBegin(GL_POLYGON);
    glColor3f(1.0f, .50f, .0f);
    glVertex2f(-.60, -.35);
    glVertex2f(-.65, -.35);
    glVertex2f(-.70, -0.42);
    glVertex2f(-.40, -0.42);
    glVertex2f(-.40, -.35);
    glVertex2f(-.45, -.35);
    glVertex2f(-.50, -.31);
    glEnd();
    glColor3f(1.0f, 1.f, 1.0f);
    DrawCircle(-.60, -.42, .03, 200);
    DrawCircle(-.45, -.42, .03, 200);

    glPopMatrix();





    //car-4 right to left"


    glPushMatrix();
    glTranslatef(0.5f, 0.0f, 0.0f); {
        glPushMatrix();
        glTranslated(position5, 0.73f, 0.0f);
        glScalef(0.7, 0.7, 1);

        glBegin(GL_POLYGON);
        glColor3f(0.0f, 0.50f, .0f);
        glVertex2f(-.60, -.35);
        glVertex2f(-.65, -.35);
        glVertex2f(-.70, -0.42);
        glVertex2f(-.40, -0.42);
        glVertex2f(-.40, -.35);
        glVertex2f(-.45, -.35);
        glVertex2f(-.50, -.31);
        glEnd();
        glColor3f(1.0f, 1.f, 1.0f);
        DrawCircle(-.60, -.42, .03, 200);
        DrawCircle(-.45, -.42, .03, 200);

        glPopMatrix();

    }

    glPopMatrix();









    //trreee









    glPushMatrix();
    glTranslatef(.30f, -.75f, 0.0f);
    glScalef(1, 1, 1);
    {


        glBegin(GL_QUADS);
        glColor3f(0.4f, 0.0f, 0.0f);
        glVertex2f(-0.64f, 0.2f);
        glVertex2f(-0.64f, 0.3f);
        glVertex2f(-0.65f, 0.3f);
        glVertex2f(-0.65f, 0.2f);
        glEnd();


        glBegin(GL_TRIANGLES);

        glColor3f(0.0f, 0.2f, 0.0f);
        glVertex2f(-0.645f, 0.2f);
        glVertex2f(-0.645f, 0.25f);
        glVertex2f(-0.64f, 0.2f);

        glColor3f(0.0f, 0.2f, 0.0f);
        glVertex2f(-0.645f, 0.2f);
        glVertex2f(-0.655f, 0.26f);
        glVertex2f(-0.658f, 0.2f);


        glColor3f(0.0f, 0.5f, 0.0f);
        glVertex2f(-0.645f, 0.2f);
        glVertex2f(-0.635f, 0.26f);
        glVertex2f(-0.638f, 0.2f);


        glEnd();


        glPushMatrix();
        glTranslatef(-0.01f, 0.01f, 0.0f);
        glBegin(GL_TRIANGLES);

        glColor3f(0.0f, 0.2f, 0.0f);
        glVertex2f(-0.645f, 0.2f);
        glVertex2f(-0.645f, 0.25f);
        glVertex2f(-0.64f, 0.2f);

        glColor3f(0.0f, 0.2f, 0.0f);
        glVertex2f(-0.645f, 0.2f);
        glVertex2f(-0.655f, 0.26f);
        glVertex2f(-0.658f, 0.2f);


        glColor3f(0.0f, 0.5f, 0.0f);
        glVertex2f(-0.645f, 0.2f);
        glVertex2f(-0.635f, 0.26f);
        glVertex2f(-0.638f, 0.2f);


        glEnd();


        glPopMatrix();










        GLfloat xf1 = -0.645f;
        GLfloat yf1 = 0.3f;
        GLfloat radiusf1 = 0.039f;
        glColor3f(0.0f, 0.2f, 0.0f);
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(xf1, yf1);
        GLfloat twice1Pi = 1.0f * PI;
        for (int i = 0; i <= triangleAmount; i++)
        {
            glVertex2f(xf1 + (radiusf1 * cos(i * twice1Pi / triangleAmount)),
                yf1 + (radiusf1 * sin(i * twice1Pi / triangleAmount)));
        }
        glEnd();


        GLfloat xf2 = -0.645f;
        GLfloat yf2 = 0.33f;
        GLfloat radiusf2 = 0.034f;
        glColor3f(0.0f, 0.2f, 0.0f);
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(xf2, yf2);
        for (int i = 0; i <= triangleAmount; i++)
        {
            glVertex2f(xf2 + (radiusf2 * cos(i * twice1Pi / triangleAmount)),
                yf2 + (radiusf2 * sin(i * twice1Pi / triangleAmount)));
        }
        glEnd();

        GLfloat xf3 = -0.645f;
        GLfloat yf3 = 0.36f;
        GLfloat radiusf3 = 0.029f;
        glColor3f(0.0f, 0.2f, 0.0f);
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(xf3, yf3);
        for (int i = 0; i <= triangleAmount; i++)
        {
            glVertex2f(xf3 + (radiusf3 * cos(i * twice1Pi / triangleAmount)),
                yf3 + (radiusf3 * sin(i * twice1Pi / triangleAmount)));
        }
        glEnd();

        glLoadIdentity();


    }

    glPopMatrix();






    //brown line


    // Set brown color
    glColor3f(0.647, 0.165, 0.165); // RGB values for brown

    // Draw a brown rectangle within the specified range
    glBegin(GL_POLYGON);
    glVertex2f(-1.0, -0.47);
    glVertex2f(1.0, -0.47);
    glVertex2f(1.0, -0.48);
    glVertex2f(-1.0, -0.48);
    glEnd();





    //upper road


    //upper road //upper road //upper road //upper road //upper road
    glBegin(GL_QUADS);
    glColor3ub(150, 149, 148);
    glVertex2f(1, -0.475);
    glVertex2f(-1, -0.475);
    glVertex2f(-1, -1);
    glVertex2f(1, -1);
    glEnd();



    /////////////////////////////////////////////////////
//////////////////////////////////////////////////////    
    ///railway platform
/////////////////////////////////////////////////////
   /////////////////////////////////////////////////////

    glPushMatrix();
    glTranslatef(-0.63, 0.14, 0);
    glBegin(GL_QUADS);//  railway platform up baseds 
    glColor3ub(250, 250, 250);
    glVertex2f(-0.3, -0.15);
    glVertex2f(0.27, -0.15);
    glVertex2f(0.27, 0.00);
    glVertex2f(-0.3, 0.0);
    glEnd();

    glPopMatrix();



    glPushMatrix();
    glScalef(1.2, 1.2, 0);
    glTranslatef(0.1, 0.2, 0.0);


    glPushMatrix();
    glScalef(0.5, 0.5, 0.5);
    glTranslatef(-1.5, -0.8, 0); {


        glPushMatrix();
        glTranslatef(-0.95f, 0.0f, 0.0f);
        glBegin(GL_QUADS);//  railway platform up
        glColor3ub(11, 11, 71);
        glVertex2f(0.7f, -0.15f);
        glVertex2f(0.695f, 0.4f);
        glVertex2f(0.725f, 0.4f);
        glVertex2f(0.73f, -0.15f);
        glEnd();
        glPopMatrix();

        glBegin(GL_QUADS);//  railway platform up
        glColor3ub(50, 107, 115);
        glVertex2f(0.7f, -0.15f);
        glVertex2f(0.695f, 0.4f);
        glVertex2f(-0.225f, 0.4f);
        glVertex2f(-0.22f, -0.15f);
        glEnd();



        glBegin(GL_QUADS);//  railway platform
        glColor3ub(102, 87, 73);
        glVertex2f(-0.315f, -0.3f);
        glVertex2f(0.62f, -0.3f);
        glVertex2f(0.6f, -0.25f);
        glVertex2f(-0.3f, -0.25f);
        glEnd();

        glBegin(GL_QUADS);//  railway platform
        glColor3ub(102, 87, 73);
        glVertex2f(0.62f, -0.3f);
        glVertex2f(0.685f, -0.1f);
        glVertex2f(0.66f, -0.1f);
        glVertex2f(0.6f, -0.25f);
        glEnd();

        glBegin(GL_QUADS);//  railway platform base
        glColor3ub(171, 173, 97);
        glVertex2f(-0.3f, -0.25f);
        glVertex2f(-0.21f, -0.1f);
        glVertex2f(0.66f, -0.1f);
        glVertex2f(0.6f, -0.25f);
        glEnd();


        glBegin(GL_QUADS);//  railway platform roof
        glColor3ub(171, 173, 7);
        glVertex2f(-0.19f, 0.25f);
        glVertex2f(-0.29f, 0.1f);
        glVertex2f(0.7f, 0.1f);
        glVertex2f(0.66f, 0.25f);
        glEnd();

        glBegin(GL_QUADS);//  railway platform piller
        glColor3ub(105, 105, 107);
        glVertex2f(0.28f, -0.25f);
        glVertex2f(0.27f, 0.1f);
        glVertex2f(0.32f, 0.1f);
        glVertex2f(0.3f, -0.25f);
        glEnd();


        glPushMatrix();
        glTranslatef(+0.25f, 0.0f, 0.0f);
        glBegin(GL_QUADS);//  railway platform piller
        glColor3ub(105, 105, 107);
        glVertex2f(0.28f, -0.25f);
        glVertex2f(0.27f, 0.1f);
        glVertex2f(0.32f, 0.1f);
        glVertex2f(0.3f, -0.25f);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(-0.25f, 0.0f, 0.0f);
        glBegin(GL_QUADS);//  railway platform piller
        glColor3ub(105, 105, 107);
        glVertex2f(0.28f, -0.25f);
        glVertex2f(0.27f, 0.1f);
        glVertex2f(0.32f, 0.1f);
        glVertex2f(0.3f, -0.25f);
        glEnd();


        glTranslatef(-0.25f, 0.0f, 0.0f);
        glBegin(GL_QUADS);//  railway platform piller
        glColor3ub(105, 105, 107);
        glVertex2f(0.28f, -0.25f);
        glVertex2f(0.27f, 0.1f);
        glVertex2f(0.32f, 0.1f);
        glVertex2f(0.3f, -0.25f);
        glEnd();
        glPopMatrix();


        glBegin(GL_QUADS);//  railway platform up top
        glColor3ub(250, 250, 250);
        glVertex2f(0.49f, 0.25f);
        glVertex2f(0.49f, 0.4f);
        glVertex2f(0.45f, 0.4f);
        glVertex2f(0.45f, 0.25f);
        glEnd();


        glPushMatrix();
        glTranslatef(-0.25f, 0.0f, 0.0f);

        glBegin(GL_QUADS);//  railway platform up top
        glColor3ub(250, 250, 250);
        glVertex2f(0.49f, 0.25f);
        glVertex2f(0.49f, 0.4f);
        glVertex2f(0.45f, 0.4f);
        glVertex2f(0.45f, 0.25f);
        glEnd();


        glTranslatef(-0.25f, 0.0f, 0.0f);
        glBegin(GL_QUADS);//  railway platform up top
        glColor3ub(250, 250, 250);
        glVertex2f(0.49f, 0.25f);
        glVertex2f(0.49f, 0.4f);
        glVertex2f(0.45f, 0.4f);
        glVertex2f(0.45f, 0.25f);
        glEnd();

        glPopMatrix();



        glBegin(GL_POLYGON);//  railway platform up top des
        glColor3ub(69, 66, 62);
        glVertex2f(0.695f, 0.4f);
        glVertex2f(0.595f, 0.53f);
        glVertex2f(0.495f, 0.4f);
        // glVertex2f(-0.225f, 0.4f);
        // glVertex2f(-0.22f, -0.15f);
        glEnd();

        glPushMatrix();

        glTranslatef(-0.25f, 0.0f, 0.0f);
        glBegin(GL_POLYGON);//  railway platform up top des
        glColor3ub(69, 66, 62);
        glVertex2f(0.695f, 0.4f);
        glVertex2f(0.595f, 0.53f);
        glVertex2f(0.495f, 0.4f);
        // glVertex2f(-0.225f, 0.4f);
        // glVertex2f(-0.22f, -0.15f);
        glEnd();


        glTranslatef(-0.25f, 0.0f, 0.0f);
        glBegin(GL_POLYGON);//  railway platform up top des
        glColor3ub(69, 66, 62);
        glVertex2f(0.695f, 0.4f);
        glVertex2f(0.595f, 0.53f);
        glVertex2f(0.495f, 0.4f);
        // glVertex2f(-0.225f, 0.4f);
        // glVertex2f(-0.22f, -0.15f);
        glEnd();


        glTranslatef(-0.25f, 0.0f, 0.0f);
        glBegin(GL_POLYGON);//  railway platform up top des
        glColor3ub(69, 66, 62);
        glVertex2f(0.695f, 0.4f);
        glVertex2f(0.595f, 0.53f);
        glVertex2f(0.495f, 0.4f);
        // glVertex2f(-0.225f, 0.4f);
        // glVertex2f(-0.22f, -0.15f);
        glEnd();

        glPopMatrix();


        glBegin(GL_QUADS);//  railway platform up top diamond
        glColor3ub(97, 96, 95);
        glVertex2f(0.47f, 0.42f);
        glVertex2f(0.57f, 0.55f);
        glVertex2f(0.47f, 0.62f);
        glVertex2f(0.37f, 0.55f);
        glEnd();

        glPushMatrix();
        glTranslatef(-0.25f, 0.0f, 0.0f);
        glBegin(GL_QUADS);//  railway platform up top diamond
        glColor3ub(97, 96, 95);
        glVertex2f(0.47f, 0.42f);
        glVertex2f(0.57f, 0.55f);
        glVertex2f(0.47f, 0.62f);
        glVertex2f(0.37f, 0.55f);
        glEnd();

        glTranslatef(-0.25f, 0.0f, 0.0f);
        glBegin(GL_QUADS);//  railway platform up top diamond
        glColor3ub(97, 96, 95);
        glVertex2f(0.47f, 0.42f);
        glVertex2f(0.57f, 0.55f);
        glVertex2f(0.47f, 0.62f);
        glVertex2f(0.37f, 0.55f);
        glEnd();

        glTranslatef(-0.23f, 0.0f, 0.0f);
        glBegin(GL_QUADS);//  railway platform up top diamond
        glColor3ub(69, 66, 62);
        glVertex2f(0.47f, 0.42f);
        glVertex2f(0.57f, 0.55f);
        glVertex2f(0.47f, 0.62f);
        glVertex2f(0.47f, 0.62f);
        glEnd();

        glPopMatrix();

        glPushMatrix();
        glTranslatef(0.23f, 0.0f, 0.0f);
        glBegin(GL_QUADS);//  railway platform up top diamond
        glColor3ub(69, 66, 62);
        glVertex2f(0.47f, 0.42f);
        glVertex2f(0.47f, 0.42f);
        glVertex2f(0.47f, 0.62f);
        glVertex2f(0.37f, 0.55f);
        glEnd();
        glPopMatrix();


        glBegin(GL_QUADS);//  railway platform up top top[]
        glColor3ub(107, 93, 78);
        glVertex2f(0.7f, 0.62f);
        glVertex2f(0.61f, 0.68f);
        glVertex2f(-0.17f, 0.68f);
        glVertex2f(-0.27f, 0.62f);
        glEnd();

        // railway platform door
        glPushMatrix();
        glScalef(0.3, 0.4, 0);
        glTranslatef(-0.7f, 0.35f, 0.0f);
        glColor3ub(191, 55, 98);
        glBegin(GL_POLYGON);
        glVertex2f(0.4, -0.6);
        glVertex2f(0.6, -0.6);
        glVertex2f(0.6, -0.2);
        glVertex2f(0.4, -0.2);
        glEnd();


        glTranslatef(0.8f, 0.0f, 0.0f);
        glColor3ub(191, 55, 98);
        glBegin(GL_POLYGON);
        glVertex2f(0.4, -0.6);
        glVertex2f(0.6, -0.6);
        glVertex2f(0.6, -0.2);
        glVertex2f(0.4, -0.2);
        glEnd();

        glTranslatef(0.8f, 0.0f, 0.0f);
        glColor3ub(191, 55, 98);
        glBegin(GL_POLYGON);
        glVertex2f(0.4, -0.6);
        glVertex2f(0.6, -0.6);
        glVertex2f(0.6, -0.2);
        glVertex2f(0.4, -0.2);
        glEnd();

        glPopMatrix();


    }

    glPopMatrix();
    glPopMatrix();
    glLoadIdentity();



    //human

    glPushMatrix();
    glScalef(0.8, 0.8, 0.0);

    // human 1
    glTranslatef(-0.62f, -0.36, 0.0f);//head
    glPushMatrix();
    glColor3f(0.7, 0.4, 1.0);
    glutSolidSphere(0.03, 100, 100);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.025f, 0.0, 0.0f);//body
    glColor3f(0.54, 0.27, 0.07);
    glBegin(GL_POLYGON);
    glVertex2f(-0.01, -0.03);
    glVertex2f(-0.04, -0.08);
    glVertex2f(-0.04, -0.03);
    glVertex2f(-0.01, -0.08);
    glEnd();
    glPopMatrix();

    // human 2
    glTranslatef(-0.09f, 0.0, 0.0f);//head
    glPushMatrix();
    glColor3f(0.7, 0.4, 0.3);
    glutSolidSphere(0.03, 100, 100);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.025f, 0.0, 0.0f);//body
    glColor3f(0.1, 0.7, 0.47);
    glBegin(GL_POLYGON);
    glVertex2f(-0.01, -0.03);
    glVertex2f(-0.04, -0.08);
    glVertex2f(-0.04, -0.03);
    glVertex2f(-0.01, -0.08);
    glEnd();
    glPopMatrix();

    // human 3
    glTranslatef(-0.1f, 0.0, 0.0f);//head
    glPushMatrix();
    glColor3f(0.2, 0.9, 0.6);
    glutSolidSphere(0.03, 100, 100);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.025f, 0.0, 0.0f);//body
    glColor3f(0.1, 0.7, 0.47);
    glBegin(GL_POLYGON);
    glVertex2f(-0.01, -0.03);
    glVertex2f(-0.04, -0.08);
    glVertex2f(-0.04, -0.03);
    glVertex2f(-0.01, -0.08);
    glEnd();
    glPopMatrix();

    // human 4
    glTranslatef(-0.08f, 0.0, 0.0f);//head
    glPushMatrix();
    glColor3f(0.4, 0.4, 0.2);
    glutSolidSphere(0.03, 100, 100);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.025f, 0.0, 0.0f);//body
    glColor3f(0.1, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(-0.01, -0.03);
    glVertex2f(-0.04, -0.08);
    glVertex2f(-0.04, -0.03);
    glVertex2f(-0.01, -0.08);
    glEnd();
    glPopMatrix();

    // human 5
    glTranslatef(-0.1f, 0.0, 0.0f);//head
    glPushMatrix();
    glColor3f(0.2, 0.1, 0.3);
    glutSolidSphere(0.03, 100, 100);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.025f, 0.0, 0.0f);//body
    glColor3f(0.9, 0.0, 0.7);
    glBegin(GL_POLYGON);
    glVertex2f(-0.01, -0.03);
    glVertex2f(-0.04, -0.08);
    glVertex2f(-0.04, -0.03);
    glVertex2f(-0.01, -0.08);
    glEnd();
    glPopMatrix();

    // human 6
    glTranslatef(-0.08f, 0.01, 0.0f);//head
    glPushMatrix();
    glColor3f(0.4, 0.1, 0.3);
    glutSolidSphere(0.03, 100, 100);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.025f, 0.0, 0.0f);//body
    glColor3f(0.0, 0.0, 0.47);
    glBegin(GL_POLYGON);
    glVertex2f(-0.01, -0.03);
    glVertex2f(-0.04, -0.08);
    glVertex2f(-0.04, -0.03);
    glVertex2f(-0.01, -0.08);
    glEnd();
    glPopMatrix();

    glPopMatrix();




    //rail line//rail line//rail line//rail line//rail line//rail line
    glBegin(GL_QUADS);
    glColor3ub(64, 54, 44);
    glVertex2f(1, -0.60);
    glVertex2f(-1, -0.60);
    glVertex2f(-1, -0.62);
    glVertex2f(1, -0.62);
    glEnd();

    //rail sand///rail sand///rail sand///rail sand/
    glBegin(GL_QUADS);
    glColor3ub(194, 165, 135);
    glVertex2f(1, -0.62);
    glVertex2f(-1, -0.62);
    glVertex2f(-1, -0.72);
    glVertex2f(1, -0.72);
    glEnd();


    //rail line wood//rail line wood//rail line wood//rail line wood//rail line wood
    /*
    //rail line wood
    glBegin(GL_QUADS);
    glColor3ub(90,92,72);
    glVertex2f(-0.85, -0.7);
    glVertex2f(-0.9,-0.7);
    glVertex2f(-0.9,-0.713);
    glVertex2f(-0.85,-0.713);
    glEnd();
    */
    //rail line wood//rail line wood//rail line wood//rail line wood//rail line wood
    float a1, a2, increment;
    a1 = -0.85;
    a2 = -0.9;
    increment = 0;

    for (int i = 0; i < 15; i++)
    {

        glBegin(GL_QUADS);
        glColor3ub(90, 92, 72);
        glVertex2f(a1 + increment, -0.62);
        glVertex2f(a2 + increment, -0.62);
        glVertex2f(a2 + increment, -0.633);
        glVertex2f(a1 + increment, -0.633);
        glEnd();
        increment = increment + 0.15;

    }











    //////////////tree 01 copy.01..................




    glPushMatrix();
    glTranslatef(.30f, -.75f, 0.0f);
    glScalef(1, 1, 1);
    {


        glBegin(GL_QUADS);
        glColor3f(0.4f, 0.0f, 0.0f);
        glVertex2f(-0.64f, 0.2f);
        glVertex2f(-0.64f, 0.3f);
        glVertex2f(-0.65f, 0.3f);
        glVertex2f(-0.65f, 0.2f);
        glEnd();


        glBegin(GL_TRIANGLES);

        glColor3f(0.0f, 0.2f, 0.0f);
        glVertex2f(-0.645f, 0.2f);
        glVertex2f(-0.645f, 0.25f);
        glVertex2f(-0.64f, 0.2f);

        glColor3f(0.0f, 0.2f, 0.0f);
        glVertex2f(-0.645f, 0.2f);
        glVertex2f(-0.655f, 0.26f);
        glVertex2f(-0.658f, 0.2f);


        glColor3f(0.0f, 0.5f, 0.0f);
        glVertex2f(-0.645f, 0.2f);
        glVertex2f(-0.635f, 0.26f);
        glVertex2f(-0.638f, 0.2f);


        glEnd();


        glPushMatrix();
        glTranslatef(-0.01f, 0.01f, 0.0f);
        glBegin(GL_TRIANGLES);

        glColor3f(0.0f, 0.2f, 0.0f);
        glVertex2f(-0.645f, 0.2f);
        glVertex2f(-0.645f, 0.25f);
        glVertex2f(-0.64f, 0.2f);

        glColor3f(0.0f, 0.2f, 0.0f);
        glVertex2f(-0.645f, 0.2f);
        glVertex2f(-0.655f, 0.26f);
        glVertex2f(-0.658f, 0.2f);


        glColor3f(0.0f, 0.5f, 0.0f);
        glVertex2f(-0.645f, 0.2f);
        glVertex2f(-0.635f, 0.26f);
        glVertex2f(-0.638f, 0.2f);


        glEnd();


        glPopMatrix();










        GLfloat xf1 = -0.645f;
        GLfloat yf1 = 0.3f;
        GLfloat radiusf1 = 0.039f;
        glColor3f(0.0f, 0.2f, 0.0f);
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(xf1, yf1);
        GLfloat twice1Pi = 1.0f * PI;
        for (int i = 0; i <= triangleAmount; i++)
        {
            glVertex2f(xf1 + (radiusf1 * cos(i * twice1Pi / triangleAmount)),
                yf1 + (radiusf1 * sin(i * twice1Pi / triangleAmount)));
        }
        glEnd();


        GLfloat xf2 = -0.645f;
        GLfloat yf2 = 0.33f;
        GLfloat radiusf2 = 0.034f;
        glColor3f(0.0f, 0.2f, 0.0f);
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(xf2, yf2);
        for (int i = 0; i <= triangleAmount; i++)
        {
            glVertex2f(xf2 + (radiusf2 * cos(i * twice1Pi / triangleAmount)),
                yf2 + (radiusf2 * sin(i * twice1Pi / triangleAmount)));
        }
        glEnd();

        GLfloat xf3 = -0.645f;
        GLfloat yf3 = 0.36f;
        GLfloat radiusf3 = 0.029f;
        glColor3f(0.0f, 0.2f, 0.0f);
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(xf3, yf3);
        for (int i = 0; i <= triangleAmount; i++)
        {
            glVertex2f(xf3 + (radiusf3 * cos(i * twice1Pi / triangleAmount)),
                yf3 + (radiusf3 * sin(i * twice1Pi / triangleAmount)));
        }
        glEnd();

        glLoadIdentity();


    }

    glPopMatrix();



    // left shop start


    // Apply transformations
    glPushMatrix();

    // Scaling
    glScalef(0.3, 0.3, 1.0);

    // Translating
    glTranslatef(1.0, -2.06, 0.0); {


        glBegin(GL_POLYGON); // body
        glColor3ub(255, 255, 255);
        glVertex2f(-1.95f, 0.5f);
        glVertex2f(-1.95f, 0.75f);
        glVertex2f(-1.55f, 0.75f);
        glVertex2f(-1.55f, 0.5f);
        glEnd();
        glBegin(GL_POLYGON); // roof
        glColor3ub(128, 0, 0);
        glVertex2f(-1.95f, 0.75f);
        glVertex2f(-1.95f, 0.85f);
        glVertex2f(-1.55f, 0.85f);
        glVertex2f(-1.55f, 0.75f);
        glEnd();

        glBegin(GL_POLYGON); // shelter
        glColor3ub(255, 0, 0);
        glVertex2f(-2.0f, 0.65f);
        glVertex2f(-1.5f, 0.65f);
        glVertex2f(-1.5f, 0.7f);
        glVertex2f(-1.55f, 0.75f);
        glVertex2f(-1.95f, 0.75f);
        glVertex2f(-2.0f, 0.7f);
        glEnd();

        glBegin(GL_POLYGON); // door
        glColor3ub(0, 230, 230);
        glVertex2f(-1.9f, 0.5f);
        glVertex2f(-1.9f, 0.62f);
        glColor3ub(0, 153, 153);
        glVertex2f(-1.82f, 0.62f);
        glVertex2f(-1.82f, 0.5f);
        glEnd();

        glBegin(GL_POLYGON); // window
        glColor3ub(0, 230, 230);
        glVertex2f(-1.77f, 0.55f);
        glVertex2f(-1.77f, 0.62f);
        glColor3ub(0, 153, 153);
        glVertex2f(-1.6f, 0.62f);
        glVertex2f(-1.6f, 0.55f);
        glEnd();

        glBegin(GL_LINES);
        glColor3ub(128, 0, 0);
        glVertex2f(-1.52f, 0.5f);
        glVertex2f(-1.98f, 0.5f);

        glVertex2f(-1.524f, 0.504f);
        glVertex2f(-1.98f, 0.504f);

        glVertex2f(-1.9f, 0.5f); // door
        glVertex2f(-1.9f, 0.62f);

        glVertex2f(-1.9f, 0.62f);
        glVertex2f(-1.82f, 0.62f);

        glVertex2f(-1.82f, 0.62f);
        glVertex2f(-1.82f, 0.5f);

        glVertex2f(-1.82f, 0.5f);
        glVertex2f(-1.9f, 0.5f);

        glVertex2f(-1.82f, 0.55f);
        glVertex2f(-1.9f, 0.55f);

        glVertex2f(-1.77f, 0.55f); // window
        glVertex2f(-1.77f, 0.62f);

        glVertex2f(-1.77f, 0.62f);
        glVertex2f(-1.6f, 0.62f);

        glVertex2f(-1.6f, 0.62f);
        glVertex2f(-1.6f, 0.55f);

        glVertex2f(-1.6f, 0.55f);
        glVertex2f(-1.77f, 0.55f);
        glEnd();

        glColor3f(1.0, 1.0, 1.0);
        c = "BFC";
        glRasterPos2f(-1.8, 0.78);
        for (int i = 0; c[i] != '\0'; i++)
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c[i]);
        // left shop end

        // right shop start
        glBegin(GL_POLYGON); // body
        glColor3ub(255, 204, 102);
        glVertex2f(-0.75f, 0.5f);
        glVertex2f(-0.75f, 0.8f);
        glVertex2f(-0.2f, 0.8f);
        glVertex2f(-0.2f, 0.5f);
        glEnd();

        glBegin(GL_POLYGON); // roof
        glColor3ub(179, 89, 0);
        glVertex2f(-0.75f, 0.85f);
        glVertex2f(-0.75f, 0.8f);
        glVertex2f(-0.2f, 0.8f);
        glVertex2f(-0.2f, 0.85f);
        glEnd();
        glBegin(GL_POLYGON); // roof
        glColor3ub(179, 89, 0);
        glVertex2f(-0.3f, 0.85f);
        glVertex2f(-0.35f, 0.9f);
        glVertex2f(-0.6f, 0.9f);
        glVertex2f(-0.66f, 0.85f);
        glEnd();

        glBegin(GL_POLYGON); // inside
        glColor3ub(77, 38, 0);
        glVertex2f(-0.73f, 0.6f);
        glVertex2f(-0.73f, 0.75f);
        glVertex2f(-0.22f, 0.75f);
        glVertex2f(-0.22f, 0.6f);
        glEnd();

        glBegin(GL_POLYGON); // product
        glColor3ub(255, 0, 0);
        glVertex2f(-0.7f, 0.6f);
        glVertex2f(-0.7f, 0.65f);
        glVertex2f(-0.6f, 0.65f);
        glVertex2f(-0.6f, 0.6f);
        glEnd();
        glBegin(GL_POLYGON); // product
        glColor3ub(255, 204, 102);
        glVertex2f(-0.65f, 0.65f);
        glVertex2f(-0.65f, 0.68f);
        glVertex2f(-0.6f, 0.68f);
        glVertex2f(-0.6f, 0.65f);
        glEnd();
        glBegin(GL_POLYGON); // product
        glColor3ub(255, 204, 102);
        glVertex2f(-0.55f, 0.6f);
        glVertex2f(-0.55f, 0.65f);
        glVertex2f(-0.45f, 0.65f);
        glVertex2f(-0.45f, 0.6f);
        glEnd();
        glBegin(GL_POLYGON); // product
        glColor3ub(204, 0, 102);
        glVertex2f(-0.4f, 0.6f);
        glVertex2f(-0.4f, 0.65f);
        glVertex2f(-0.35f, 0.6f);
        glVertex2f(-0.35f, 0.65f);
        glEnd();
        glBegin(GL_POLYGON); // product
        glColor3ub(255, 204, 102);
        glVertex2f(-0.34f, 0.6f);
        glVertex2f(-0.34f, 0.66f);
        glVertex2f(-0.3f, 0.6f);
        glVertex2f(-0.3f, 0.66f);
        glEnd();

        glBegin(GL_POLYGON); // table
        glColor3ub(128, 64, 0);
        glVertex2f(-0.73f, 0.5f);
        glVertex2f(-0.73f, 0.6f);
        glVertex2f(-0.22f, 0.6f);
        glVertex2f(-0.22f, 0.5f);
        glEnd();

        glBegin(GL_POLYGON); // shelter
        glColor3ub(230, 115, 0);
        glVertex2f(-0.8f, 0.7f);
        glVertex2f(-0.15f, 0.7f);
        glVertex2f(-0.15f, 0.75f);
        glVertex2f(-0.2f, 0.8f);
        glVertex2f(-0.75f, 0.8f);
        glVertex2f(-0.8f, 0.75f);
        glEnd();

        glBegin(GL_LINES);
        glColor3ub(128, 0, 0);
        glVertex2f(-0.17f, 0.5f);
        glVertex2f(-0.77f, 0.5f);

        glVertex2f(-0.17f, 0.504f);
        glVertex2f(-0.77f, 0.504f);

        glColor3ub(255, 153, 51);
        glVertex2f(-0.73f, 0.6f);
        glVertex2f(-0.22f, 0.6f);
        glEnd();

        glColor3ub(255, 255, 0);
        c = "Candy Shop";
        glRasterPos2f(-0.6, 0.84);
        for (int i = 0; c[i] != '\0'; i++) {
            glutBitmapCharacter(GLUT_BITMAP_9_BY_15, c[i]);

        }

        glPopMatrix();

    }











    //normal tree1
    glPushMatrix();

    glScalef(0.35, 0.4, 1);
    glTranslatef(1.75, -1.0, 0);
    {


        glBegin(GL_QUADS);
        glColor3ub(101, 67, 33);
        glVertex2f(-0.62, -0.3);
        glVertex2f(-0.62, 0.1);
        glVertex2f(-0.65, 0.1);
        glVertex2f(-0.65, -0.3);
        glEnd();


        glBegin(GL_TRIANGLES);
        glColor3ub(0.0f, 0.2f, 0.0f);
        glVertex2f(-0.57, -0.1);
        glVertex2f(-0.635, 0.15);
        glVertex2f(-0.7, -0.1);
        glEnd();

        glBegin(GL_TRIANGLES);
        glColor3ub(0.0f, 0.2f, 0.0f);
        glVertex2f(-0.57, -0.03);
        glVertex2f(-0.635, 0.12);
        glVertex2f(-0.7, -0.03);
        glEnd();


        glBegin(GL_TRIANGLES);
        glColor3ub(0.0f, 0.2f, 0.0f);
        glVertex2f(-0.58, 0.04);
        glVertex2f(-0.635, 0.19);
        glVertex2f(-0.69, 0.04);
        glEnd();

    }

    glPopMatrix();




    //normal tree2
    glPushMatrix();

    glScalef(0.35, 0.4, 1);
    glTranslatef(2.20, -1.0, 0);
    {


        glBegin(GL_QUADS);
        glColor3ub(101, 67, 33);
        glVertex2f(-0.62, -0.3);
        glVertex2f(-0.62, 0.1);
        glVertex2f(-0.65, 0.1);
        glVertex2f(-0.65, -0.3);
        glEnd();


        glBegin(GL_TRIANGLES);
        glColor3ub(0.0f, 0.2f, 0.0f);
        glVertex2f(-0.57, -0.1);
        glVertex2f(-0.635, 0.15);
        glVertex2f(-0.7, -0.1);
        glEnd();

        glBegin(GL_TRIANGLES);
        glColor3ub(0.0f, 0.2f, 0.0f);
        glVertex2f(-0.57, -0.03);
        glVertex2f(-0.635, 0.12);
        glVertex2f(-0.7, -0.03);
        glEnd();


        glBegin(GL_TRIANGLES);
        glColor3ub(0.0f, 0.2f, 0.0f);
        glVertex2f(-0.58, 0.04);
        glVertex2f(-0.635, 0.19);
        glVertex2f(-0.69, 0.04);
        glEnd();

    }

    glPopMatrix();



    //normal tree3
    glPushMatrix();

    glScalef(0.35, 0.4, 1);
    glTranslatef(2.65, -1.0, 0);
    {


        glBegin(GL_QUADS);
        glColor3ub(101, 67, 33);
        glVertex2f(-0.62, -0.3);
        glVertex2f(-0.62, 0.1);
        glVertex2f(-0.65, 0.1);
        glVertex2f(-0.65, -0.3);
        glEnd();


        glBegin(GL_TRIANGLES);
        glColor3ub(0.0f, 0.2f, 0.0f);
        glVertex2f(-0.57, -0.1);
        glVertex2f(-0.635, 0.15);
        glVertex2f(-0.7, -0.1);
        glEnd();

        glBegin(GL_TRIANGLES);
        glColor3ub(0.0f, 0.2f, 0.0f);
        glVertex2f(-0.57, -0.03);
        glVertex2f(-0.635, 0.12);
        glVertex2f(-0.7, -0.03);
        glEnd();


        glBegin(GL_TRIANGLES);
        glColor3ub(0.0f, 0.2f, 0.0f);
        glVertex2f(-0.58, 0.04);
        glVertex2f(-0.635, 0.19);
        glVertex2f(-0.69, 0.04);
        glEnd();

    }

    glPopMatrix();



    //normal tree4
    glPushMatrix();

    glScalef(0.35, 0.4, 1);
    glTranslatef(3.1, -1.0, 0);
    {


        glBegin(GL_QUADS);
        glColor3ub(101, 67, 33);
        glVertex2f(-0.62, -0.3);
        glVertex2f(-0.62, 0.1);
        glVertex2f(-0.65, 0.1);
        glVertex2f(-0.65, -0.3);
        glEnd();


        glBegin(GL_TRIANGLES);
        glColor3ub(0.0f, 0.2f, 0.0f);
        glVertex2f(-0.57, -0.1);
        glVertex2f(-0.635, 0.15);
        glVertex2f(-0.7, -0.1);
        glEnd();

        glBegin(GL_TRIANGLES);
        glColor3ub(0.0f, 0.2f, 0.0f);
        glVertex2f(-0.57, -0.03);
        glVertex2f(-0.635, 0.12);
        glVertex2f(-0.7, -0.03);
        glEnd();


        glBegin(GL_TRIANGLES);
        glColor3ub(0.0f, 0.2f, 0.0f);
        glVertex2f(-0.58, 0.04);
        glVertex2f(-0.635, 0.19);
        glVertex2f(-0.69, 0.04);
        glEnd();

    }

    glPopMatrix();










    //tree-2


//////////////tree 03 copy.01..................




    glPushMatrix();
    glTranslatef(.6f, -.75f, 0.0f);
    glScalef(1, 1, 1);
    {


        glBegin(GL_QUADS);
        glColor3f(0.4f, 0.0f, 0.0f);
        glVertex2f(-0.64f, 0.2f);
        glVertex2f(-0.64f, 0.3f);
        glVertex2f(-0.65f, 0.3f);
        glVertex2f(-0.65f, 0.2f);
        glEnd();


        glBegin(GL_TRIANGLES);

        glColor3f(0.0f, 0.2f, 0.0f);
        glVertex2f(-0.645f, 0.2f);
        glVertex2f(-0.645f, 0.25f);
        glVertex2f(-0.64f, 0.2f);

        glColor3f(0.0f, 0.2f, 0.0f);
        glVertex2f(-0.645f, 0.2f);
        glVertex2f(-0.655f, 0.26f);
        glVertex2f(-0.658f, 0.2f);


        glColor3f(0.0f, 0.5f, 0.0f);
        glVertex2f(-0.645f, 0.2f);
        glVertex2f(-0.635f, 0.26f);
        glVertex2f(-0.638f, 0.2f);


        glEnd();


        glPushMatrix();
        glTranslatef(-0.01f, 0.01f, 0.0f);
        glBegin(GL_TRIANGLES);

        glColor3f(0.0f, 0.2f, 0.0f);
        glVertex2f(-0.645f, 0.2f);
        glVertex2f(-0.645f, 0.25f);
        glVertex2f(-0.64f, 0.2f);

        glColor3f(0.0f, 0.2f, 0.0f);
        glVertex2f(-0.645f, 0.2f);
        glVertex2f(-0.655f, 0.26f);
        glVertex2f(-0.658f, 0.2f);


        glColor3f(0.0f, 0.5f, 0.0f);
        glVertex2f(-0.645f, 0.2f);
        glVertex2f(-0.635f, 0.26f);
        glVertex2f(-0.638f, 0.2f);


        glEnd();


        glPopMatrix();










        GLfloat xf1 = -0.645f;
        GLfloat yf1 = 0.3f;
        GLfloat radiusf1 = 0.039f;
        glColor3f(0.0f, 0.2f, 0.0f);
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(xf1, yf1);
        GLfloat twice1Pi = 1.0f * PI;
        for (int i = 0; i <= triangleAmount; i++)
        {
            glVertex2f(xf1 + (radiusf1 * cos(i * twice1Pi / triangleAmount)),
                yf1 + (radiusf1 * sin(i * twice1Pi / triangleAmount)));
        }
        glEnd();


        GLfloat xf2 = -0.645f;
        GLfloat yf2 = 0.33f;
        GLfloat radiusf2 = 0.034f;
        glColor3f(0.0f, 0.2f, 0.0f);
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(xf2, yf2);
        for (int i = 0; i <= triangleAmount; i++)
        {
            glVertex2f(xf2 + (radiusf2 * cos(i * twice1Pi / triangleAmount)),
                yf2 + (radiusf2 * sin(i * twice1Pi / triangleAmount)));
        }
        glEnd();

        GLfloat xf3 = -0.645f;
        GLfloat yf3 = 0.36f;
        GLfloat radiusf3 = 0.029f;
        glColor3f(0.0f, 0.2f, 0.0f);
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(xf3, yf3);
        for (int i = 0; i <= triangleAmount; i++)
        {
            glVertex2f(xf3 + (radiusf3 * cos(i * twice1Pi / triangleAmount)),
                yf3 + (radiusf3 * sin(i * twice1Pi / triangleAmount)));
        }
        glEnd();

        glLoadIdentity();


    }

    glPopMatrix();












    //train 2 start //train 2 start//train 2 start//train 2 start//train 2 start

    glPushMatrix();
    glScalef(0.75, 0.75, 1);
    glTranslatef(position, -0.20, 0);
    {



        //
        //
                //wheel1//wheel1//wheel1//wheel1//wheel1//wheel1//wheel1//wheel1
        glPushMatrix();

        glScalef(0.55, 1, 1);
        glTranslatef(-0.87, 0.225, 0);
        {


            GLfloat x = -0.85;
            GLfloat y = -0.8;
            GLfloat radius = .03f;
            int triangleAmount = 40; //# of triangles used to draw circle# of triangles used to draw circle# of triangles used to draw circle

            //GLfloat radius = 0.8f; //radius
            GLfloat twicePi = 2.0f * PI;

            glBegin(GL_TRIANGLE_FAN);
            glColor3ub(0, 0, 0);
            glVertex2f(x, y); // center of circle
            for (int i = 0; i <= triangleAmount; i++)
            {
                glVertex2f(
                    x + (radius * cos(i * twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount))
                );
            }
            glEnd();


        }

        glPopMatrix();


        //wheel2//wheel2//wheel2//wheel2//wheel2//wheel2//wheel2
        glPushMatrix();

        glScalef(0.55, 1, 1);
        glTranslatef(-0.69, 0.225, 0);
        {


            GLfloat x = -0.85;
            GLfloat y = -0.8;
            GLfloat radius = .03f;
            int triangleAmount = 40; //# of triangles used to draw circle# of triangles used to draw circle# of triangles used to draw circle

            //GLfloat radius = 0.8f; //radius
            GLfloat twicePi = 2.0f * PI;

            glBegin(GL_TRIANGLE_FAN);
            glColor3ub(0, 0, 0);
            glVertex2f(x, y); // center of circle
            for (int i = 0; i <= triangleAmount; i++)
            {
                glVertex2f(
                    x + (radius * cos(i * twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount))
                );
            }
            glEnd();


        }

        glPopMatrix();


        //wheel3//wheel3//wheel3//wheel3//wheel3//wheel3//wheel3//wheel3
        glPushMatrix();

        glScalef(0.54, 1, 1);
        glTranslatef(-0.55, 0.225, 0);
        {


            GLfloat x = -0.85;
            GLfloat y = -0.8;
            GLfloat radius = .03f;
            int triangleAmount = 40; //# of triangles used to draw circle# of triangles used to draw circle# of triangles used to draw circle

            //GLfloat radius = 0.8f; //radius
            GLfloat twicePi = 4.0f * PI;

            glBegin(GL_TRIANGLE_FAN);
            glColor3ub(0, 0, 0);
            glVertex2f(x, y); // center of circle
            for (int i = 0; i <= triangleAmount; i++)
            {
                glVertex2f(
                    x + (radius * cos(i * twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount))
                );
            }
            glEnd();


        }

        glPopMatrix();




        //wheel4//wheel4//wheel4//wheel4//wheel4//wheel4//wheel4
        glPushMatrix();

        glScalef(0.55, 1, 1);
        glTranslatef(-0.35, 0.225, 0);
        {


            GLfloat x = -0.85;
            GLfloat y = -0.8;
            GLfloat radius = .03f;
            int triangleAmount = 40; //# of triangles used to draw circle# of triangles used to draw circle# of triangles used to draw circle

            //GLfloat radius = 0.8f; //radius
            GLfloat twicePi = 2.0f * PI;

            glBegin(GL_TRIANGLE_FAN);
            glColor3ub(0, 0, 0);
            glVertex2f(x, y); // center of circle
            for (int i = 0; i <= triangleAmount; i++)
            {
                glVertex2f(
                    x + (radius * cos(i * twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount))
                );
            }
            glEnd();


        }

        glPopMatrix();



        //wheel5//wheel5//wheel5//wheel5//wheel5//wheel5//wheel5//wheel5//wheel5
        glPushMatrix();

        glScalef(0.54, 1, 1);
        glTranslatef(-0.20, 0.225, 0);
        {


            GLfloat x = -0.85;
            GLfloat y = -0.8;
            GLfloat radius = .03f;
            int triangleAmount = 40; //# of triangles used to draw circle# of triangles used to draw circle# of triangles used to draw circle

            //GLfloat radius = 0.8f; //radius
            GLfloat twicePi = 4.0f * PI;

            glBegin(GL_TRIANGLE_FAN);
            glColor3ub(0, 0, 0);
            glVertex2f(x, y); // center of circle
            for (int i = 0; i <= triangleAmount; i++)
            {
                glVertex2f(
                    x + (radius * cos(i * twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount))
                );
            }
            glEnd();


        }

        glPopMatrix();




        //wheel6//wheel6//wheel6//wheel6//wheel6//wheel6//wheel6//wheel6//wheel6//wheel6
        glPushMatrix();

        glScalef(0.55, 1, 1);
        glTranslatef(0.01, 0.225, 0);
        {


            GLfloat x = -0.85;
            GLfloat y = -0.8;
            GLfloat radius = .03f;
            int triangleAmount = 40; //# of triangles used to draw circle# of triangles used to draw circle# of triangles used to draw circle

            //GLfloat radius = 0.8f; //radius
            GLfloat twicePi = 2.0f * PI;

            glBegin(GL_TRIANGLE_FAN);
            glColor3ub(0, 0, 0);
            glVertex2f(x, y); // center of circle
            for (int i = 0; i <= triangleAmount; i++)
            {
                glVertex2f(
                    x + (radius * cos(i * twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount))
                );
            }
            glEnd();


        }

        glPopMatrix();



        //wheel7//wheel7//wheel7//wheel7//wheel7//wheel7//wheel7
        glPushMatrix();

        glScalef(0.54, 1, 1);
        glTranslatef(0.17, 0.225, 0);
        {


            GLfloat x = -0.85;
            GLfloat y = -0.8;
            GLfloat radius = .03f;
            int triangleAmount = 40; //# of triangles used to draw circle# of triangles used to draw circle# of triangles used to draw circle

            //GLfloat radius = 0.8f; //radius
            GLfloat twicePi = 4.0f * PI;

            glBegin(GL_TRIANGLE_FAN);
            glColor3ub(0, 0, 0);
            glVertex2f(x, y); // center of circle
            for (int i = 0; i <= triangleAmount; i++)
            {
                glVertex2f(
                    x + (radius * cos(i * twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount))
                );
            }
            glEnd();


        }

        glPopMatrix();




        //wheel8//wheel8//wheel8//wheel8//wheel8//wheel8//wheel8
        glPushMatrix();

        glScalef(0.55, 1, 1);
        glTranslatef(0.39, 0.225, 0);
        {


            GLfloat x = -0.85;
            GLfloat y = -0.8;
            GLfloat radius = .03f;
            int triangleAmount = 40; //# of triangles used to draw circle# of triangles used to draw circle# of triangles used to draw circle

            //GLfloat radius = 0.8f; //radius
            GLfloat twicePi = 2.0f * PI;

            glBegin(GL_TRIANGLE_FAN);
            glColor3ub(0, 0, 0);
            glVertex2f(x, y); // center of circle
            for (int i = 0; i <= triangleAmount; i++)
            {
                glVertex2f(
                    x + (radius * cos(i * twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount))
                );
            }
            glEnd();


        }

        glPopMatrix();

        //body1//body1//body1//body1//body1//body1//body1//body1
        glBegin(GL_QUADS);
        glColor3ub(0, 54, 54);
        glVertex2f(-0.81, -0.386);
        glVertex2f(-0.98, -0.386);
        glVertex2f(-0.98, -0.575);
        glVertex2f(-0.81, -0.575);
        glEnd();


        //lowerpart1//lowerpart1//lowerpart1//lowerpart1
        glBegin(GL_QUADS);
        glColor3ub(0, 0, 0);
        glVertex2f(-0.81, -0.555);
        glVertex2f(-0.98, -0.555);
        glVertex2f(-0.98, -0.575);
        glVertex2f(-0.81, -0.575);
        glEnd();


        //join1//join1//join1//join1//join1//join1//join1
        glBegin(GL_QUADS);
        glColor3ub(0, 0, 0);
        glVertex2f(-0.79, -0.565);
        glVertex2f(-0.81, -0.565);
        glVertex2f(-0.81, -0.575);
        glVertex2f(-0.79, -0.575);
        glEnd();


        //body2//body2//body2//body2//body2//body2//body2//body2
        glBegin(GL_QUADS);
        glColor3ub(0, 54, 54);
        glVertex2f(-0.62, -0.386);
        glVertex2f(-0.79, -0.386);
        glVertex2f(-0.79, -0.575);
        glVertex2f(-0.62, -0.575);
        glEnd();


        //lowerpart2//lowerpart2//lowerpart2//lowerpart2
        glBegin(GL_QUADS);
        glColor3ub(0, 0, 0);
        glVertex2f(-0.62, -0.555);
        glVertex2f(-0.79, -0.555);
        glVertex2f(-0.79, -0.575);
        glVertex2f(-0.62, -0.575);
        glEnd();


        //join2//join2//join2//join2//join2//join2//join2//join2
        glBegin(GL_QUADS);
        glColor3ub(0, 0, 0);
        glVertex2f(-0.6, -0.565);
        glVertex2f(-0.62, -0.565);
        glVertex2f(-0.62, -0.575);
        glVertex2f(-0.6, -0.575);
        glEnd();


        //body3//body3//body3//body3//body3//body3//body3
        glBegin(GL_QUADS);
        glColor3ub(0, 54, 54);
        glVertex2f(-0.43, -0.386);
        glVertex2f(-0.60, -0.386);
        glVertex2f(-0.60, -0.575);
        glVertex2f(-0.43, -0.575);
        glEnd();

        //lowerpart3//lowerpart3//lowerpart3//lowerpart3
        glBegin(GL_QUADS);
        glColor3ub(0, 0, 0);
        glVertex2f(-0.43, -0.555);
        glVertex2f(-0.60, -0.555);
        glVertex2f(-0.60, -0.575);
        glVertex2f(-0.43, -0.575);
        glEnd();

        //join3//join3//join3//join3//join3//join3//join3//join3
        glBegin(GL_QUADS);
        glColor3ub(0, 0, 0);
        glVertex2f(-0.41, -0.565);
        glVertex2f(-0.43, -0.565);
        glVertex2f(-0.43, -0.575);
        glVertex2f(-0.41, -0.575);
        glEnd();


        //body4//body4//body4//body4//body4//body4
        glBegin(GL_QUADS);
        glColor3ub(0, 54, 54);
        glVertex2f(-0.26, -0.386);
        glVertex2f(-0.41, -0.386);
        glVertex2f(-0.41, -0.575);
        glVertex2f(-0.26, -0.575);
        glEnd();


        //body triangle//body triangle//body triangle//body triangle
        glBegin(GL_TRIANGLES);
        glColor3ub(0, 54, 54);
        glVertex2f(-0.185, -0.555);
        glVertex2f(-0.26, -0.386);
        glVertex2f(-0.26, -0.555);
        glEnd();

        //body smoke//body smoke//body smoke//body smoke
        glBegin(GL_QUADS);
        glColor3ub(25, 68, 74);
        glVertex2f(-0.28, -0.33);
        glVertex2f(-0.33, -0.33);
        glVertex2f(-0.33, -0.386);
        glVertex2f(-0.28, -0.386);
        glEnd();


        //lowerpart4//lowerpart4//lowerpart4//lowerpart4//lowerpart4
        glBegin(GL_QUADS);
        glColor3ub(0, 0, 0);
        glVertex2f(-0.185, -0.555);
        glVertex2f(-0.41, -0.555);
        glVertex2f(-0.41, -0.575);
        glVertex2f(-0.185, -0.575);
        glEnd();



        //windows 1 and door 1//windows 1 and door 1//windows 1 and door 1//windows 1 and door 1

        glBegin(GL_QUADS);
        glColor3ub(107, 153, 166);
        glVertex2f(-0.93, -0.44);
        glVertex2f(-0.95, -0.44);
        glVertex2f(-0.95, -0.48);
        glVertex2f(-0.93, -0.48);
        glEnd();

        glBegin(GL_QUADS);
        glColor3ub(107, 153, 166);
        glVertex2f(-0.88, -0.44);
        glVertex2f(-0.9, -0.44);
        glVertex2f(-0.9, -0.48);
        glVertex2f(-0.88, -0.48);
        glEnd();


        glBegin(GL_QUADS);
        glColor3ub(86, 112, 120);
        glVertex2f(-0.825, -0.42);
        glVertex2f(-0.85, -0.42);
        glVertex2f(-0.85, -0.54);
        glVertex2f(-0.825, -0.54);
        glEnd();



        //windows 2 and door 2//windows 2 and door 2//windows 2 and door 2//windows 2 and door 2

        glBegin(GL_QUADS);
        glColor3ub(107, 153, 166);
        glVertex2f(-0.73, -0.44);
        glVertex2f(-0.75, -0.44);
        glVertex2f(-0.75, -0.48);
        glVertex2f(-0.73, -0.48);
        glEnd();

        glBegin(GL_QUADS);
        glColor3ub(107, 153, 166);
        glVertex2f(-0.68, -0.44);
        glVertex2f(-0.7, -0.44);
        glVertex2f(-0.7, -0.48);
        glVertex2f(-0.68, -0.48);
        glEnd();


        glBegin(GL_QUADS);
        glColor3ub(86, 112, 120);
        glVertex2f(-0.635, -0.42);
        glVertex2f(-0.66, -0.42);
        glVertex2f(-0.66, -0.54);
        glVertex2f(-0.635, -0.54);
        glEnd();




        //windows 3 and door 3//windows 3 and door 3//windows 3 and door 3//windows 3 and door 3

        glBegin(GL_QUADS);
        glColor3ub(107, 153, 166);
        glVertex2f(-0.55, -0.44);
        glVertex2f(-0.57, -0.44);
        glVertex2f(-0.57, -0.48);
        glVertex2f(-0.55, -0.48);
        glEnd();

        glBegin(GL_QUADS);
        glColor3ub(107, 153, 166);
        glVertex2f(-0.5, -0.44);
        glVertex2f(-0.52, -0.44);
        glVertex2f(-0.52, -0.48);
        glVertex2f(-0.5, -0.48);
        glEnd();


        glBegin(GL_QUADS);
        glColor3ub(86, 112, 120);
        glVertex2f(-0.445, -0.42);
        glVertex2f(-0.47, -0.42);
        glVertex2f(-0.47, -0.54);
        glVertex2f(-0.445, -0.54);
        glEnd();



        //windows 4 and door 4//windows 4 and door 4//windows 4 and door 4//windows 4 and door 4

        glBegin(GL_QUADS);
        glColor3ub(107, 153, 166);
        glVertex2f(-0.36, -0.44);
        glVertex2f(-0.38, -0.44);
        glVertex2f(-0.38, -0.48);
        glVertex2f(-0.36, -0.48);
        glEnd();

        glBegin(GL_QUADS);
        glColor3ub(107, 153, 166);
        glVertex2f(-0.28, -0.44);
        glVertex2f(-0.3, -0.44);
        glVertex2f(-0.3, -0.48);
        glVertex2f(-0.28, -0.48);
        glEnd();


        glBegin(GL_QUADS);
        glColor3ub(86, 112, 120);
        glVertex2f(-0.315, -0.42);
        glVertex2f(-0.34, -0.42);
        glVertex2f(-0.34, -0.54);
        glVertex2f(-0.315, -0.54);
        glEnd();
    }
    glPopMatrix();

















    glFlush(); // Render now

}

void display()
{







    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
    glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)



    glBegin(GL_QUADS);// sky //// sky //// sky //// sky //
    glColor3ub(155, 206, 235);//135,206,235
    glVertex2f(1, 1);
    glVertex2f(-1, 1);
    glVertex2f(-1, -1);
    glVertex2f(1, -1);
    glEnd();






    //mountain//mountain//mountain//mountain//mountain


    GLfloat x2 = 0.9;
    GLfloat y2 = -0.7;
    GLfloat radius2 = .4f;
    int triangleAmount2 = 50; //# of triangles used to draw circle# of triangles used to draw circle# of triangles used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi2 = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(163, 155, 121);
    glVertex2f(x2, y2); // center of circle
    for (int i = 0; i <= triangleAmount2; i++)
    {
        glVertex2f(
            x2 + (radius2 * cos(i * twicePi2 / triangleAmount2)),
            y2 + (radius2 * sin(i * twicePi2 / triangleAmount2))
        );
    }
    glEnd();







    glBegin(GL_TRIANGLES);
    glColor3ub(173, 165, 111);
    glVertex2f(0.9, -0.45);
    glVertex2f(0.5, 0.1);
    glVertex2f(-0.1, -0.45);
    glEnd();

    GLfloat x1 = -0.78;
    GLfloat y1 = -0.65;
    GLfloat radius1 = .4f;
    int triangleAmount1 = 50; //# of triangles used to draw circle# of triangles used to draw circle# of triangles used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi1 = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(163, 155, 121);
    glVertex2f(x1, y1); // center of circle
    for (int i = 0; i <= triangleAmount1; i++)
    {
        glVertex2f(
            x1 + (radius1 * cos(i * twicePi1 / triangleAmount1)),
            y1 + (radius1 * sin(i * twicePi1 / triangleAmount1))
        );
    }
    glEnd();



    ////////////////////
    glPushMatrix();
    glScalef(0.5, 0.6, 0);
    glTranslatef(0.4f, -0.17f, 0.0f);

    // glBegin(GL_TRIANGLES);
    // glColor4ub(204, 204, 202, 128);
    // glVertex2f(0.4, -0.52);
    // glVertex2f(0.4, 0.2);``
    // glVertex2f(-0.3, -0.55);
    // glEnd();

    glScalef(2.0, 1.8, 0);
    glTranslatef(1.009f, 0.28f, 0.0f);
    glBegin(GL_TRIANGLES);
    glColor4ub(201, 201, 171, 200);
    glVertex2f(-0.25, -0.65);
    glVertex2f(-0.7, -0.1);
    glVertex2f(-0.6, -0.61);
    glEnd();


    glPopMatrix();

    ////////////////////



    GLfloat x = -0.15;
    GLfloat y = -0.5;
    GLfloat radius = .4f;
    int triangleAmount = 50; //# of triangles used to draw circle# of triangles used to draw circle# of triangles used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(163, 155, 121);
    glVertex2f(x, y); // center of circle
    for (int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i * twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();


    ////////////////////////////////////////////////////////////////////////////

    // shade hoolls 

    glPushMatrix();
    glScalef(0.5, 0.6, 0);
    glTranslatef(-0.1f, -0.2f, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glColor4ub(204, 204, 202, 128);
    glVertex2f(x, y); // center of circle
    for (int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i * twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();



    glScalef(0.5, 0.6, 0);
    glTranslatef(-0.3f, -0.35f, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glColor4ub(158, 157, 152, 128);
    glVertex2f(x, y); // center of circle
    for (int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i * twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
    glPopMatrix();

    ////////////////////////////////////////////////////////////////////////////



    glBegin(GL_TRIANGLES);
    glColor3ub(153, 155, 111);
    glVertex2f(-0.1, -0.45);
    glVertex2f(-0.35, 0.15);
    glVertex2f(-0.5, -0.45);
    glEnd();

    ///////////
    glPushMatrix();
    glScalef(0.5, 0.6, 0);
    glTranslatef(-0.32f, 0.08f, 0.0f);

    glBegin(GL_QUADS);
    glColor4ub(204, 204, 202, 128);
    glVertex2f(-0.1, -0.49);
    glVertex2f(-0.37, 0.15);
    glVertex2f(-0.5, -0.49);
    glVertex2f(-0.3, -0.25);
    glEnd();

    glTranslatef(0.05f, -0.2f, 0.0f);
    glBegin(GL_QUADS);
    glColor4ub(204, 204, 202, 128);
    glVertex2f(-0.1, -0.49);
    glVertex2f(-0.33, 0.05);
    glVertex2f(-0.5, -0.49);
    glVertex2f(-0.28, -0.25);
    glEnd();

    glPopMatrix();
    ///////////////


    glBegin(GL_TRIANGLES);
    glColor3ub(163, 165, 111);
    glVertex2f(-0.4, -0.45);
    glVertex2f(-0.5, -0.1);
    glVertex2f(-0.7, -0.45);
    glEnd();

    ////////////////////
    glPushMatrix();
    glScalef(0.5, 0.6, 0);
    glTranslatef(-0.5f, -0.1f, 0.0f);

    glBegin(GL_TRIANGLES);
    glColor4ub(204, 204, 202, 200);
    glVertex2f(-0.4, -0.65);
    glVertex2f(-0.5, -0.1);
    glVertex2f(-0.5, -0.65);
    glEnd();

    //glScalef(0.5, 0.6, 0);
    glTranslatef(-0.0f, -0.0f, 0.0f);
    glBegin(GL_TRIANGLES);
    glColor4ub(201, 201, 171, 200);
    glVertex2f(-0.6, -0.65);
    glVertex2f(-0.5, -0.1);
    glVertex2f(-0.7, -0.65);
    glEnd();

    glPopMatrix();

    ////////////////////



    //camp 1//camp 1//camp 1//camp 1//camp 1//camp 1//camp 1//camp 1//camp 1//camp 1//camp 1
    glPushMatrix();

    glScalef(0.40, 0.85, 1);
    glTranslatef(-1.2, -0.02, 0);
    {

        glBegin(GL_POLYGON);
        glColor3ub(96, 71, 65);
        glVertex2f(-0.63, -0.1);
        glVertex2f(-0.78, -0.0);
        glVertex2f(-0.92, -0.1);
        glVertex2f(-0.92, -0.3);
        glVertex2f(-0.63, -0.3);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(77, 60, 61);
        glVertex2f(-0.65, -0.1);
        glVertex2f(-0.78, -0.02);
        glVertex2f(-0.90, -0.1);
        glVertex2f(-0.90, -0.3);
        glVertex2f(-0.65, -0.3);
        glEnd();



        glBegin(GL_QUADS);
        glColor3ub(77, 60, 61);
        glVertex2f(-0.59, -0.08);
        glVertex2f(-0.78, 0.05);
        glVertex2f(-0.78, 0);
        glVertex2f(-0.59, -0.13);
        glEnd();


        glBegin(GL_QUADS);
        glColor3ub(77, 60, 61);
        glVertex2f(-0.78, 0.05);
        glVertex2f(-0.96, -0.08);
        glVertex2f(-0.96, -0.13);
        glVertex2f(-0.78, 0);

        glEnd();


        glBegin(GL_QUADS);
        glColor3ub(10, 10, 0);
        glVertex2f(-0.72, -0.15);
        glVertex2f(-0.83, -0.15);
        glVertex2f(-0.83, -0.3);
        glVertex2f(-0.72, -0.3);
        glEnd();

    }

    glPopMatrix();



    //camp 2//camp 2//camp 2//camp 2//camp 2//camp 2//camp 2//camp 2//camp 2//camp 2
    glPushMatrix();

    glScalef(0.35, 0.7, 1);
    glTranslatef(0.6, 0.1, 0);
    {

        glBegin(GL_POLYGON);
        glColor3ub(96, 71, 65);
        glVertex2f(-0.63, -0.1);
        glVertex2f(-0.78, -0.0);
        glVertex2f(-0.92, -0.1);
        glVertex2f(-0.92, -0.3);
        glVertex2f(-0.63, -0.3);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(77, 60, 61);
        glVertex2f(-0.65, -0.1);
        glVertex2f(-0.78, -0.02);
        glVertex2f(-0.90, -0.1);
        glVertex2f(-0.90, -0.3);
        glVertex2f(-0.65, -0.3);
        glEnd();



        glBegin(GL_QUADS);
        glColor3ub(77, 60, 61);
        glVertex2f(-0.59, -0.08);
        glVertex2f(-0.78, 0.05);
        glVertex2f(-0.78, 0);
        glVertex2f(-0.59, -0.13);
        glEnd();


        glBegin(GL_QUADS);
        glColor3ub(77, 60, 61);
        glVertex2f(-0.78, 0.05);
        glVertex2f(-0.96, -0.08);
        glVertex2f(-0.96, -0.13);
        glVertex2f(-0.78, 0);

        glEnd();


        glBegin(GL_QUADS);
        glColor3ub(10, 10, 0);
        glVertex2f(-0.72, -0.15);
        glVertex2f(-0.83, -0.15);
        glVertex2f(-0.83, -0.3);
        glVertex2f(-0.72, -0.3);
        glEnd();

    }

    glPopMatrix();





    //camp 3//camp 3//camp 3//camp 3//camp 3//camp 3//camp 3//camp 3
    glPushMatrix();

    glScalef(0.3, 0.65, 1);
    glTranslatef(0.17, 0.1, 0);
    {

        glBegin(GL_POLYGON);
        glColor3ub(96, 71, 65);
        glVertex2f(-0.63, -0.1);
        glVertex2f(-0.78, -0.0);
        glVertex2f(-0.92, -0.1);
        glVertex2f(-0.92, -0.3);
        glVertex2f(-0.63, -0.3);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(77, 60, 61);
        glVertex2f(-0.65, -0.1);
        glVertex2f(-0.78, -0.02);
        glVertex2f(-0.90, -0.1);
        glVertex2f(-0.90, -0.3);
        glVertex2f(-0.65, -0.3);
        glEnd();



        glBegin(GL_QUADS);
        glColor3ub(77, 60, 61);
        glVertex2f(-0.59, -0.08);
        glVertex2f(-0.78, 0.05);
        glVertex2f(-0.78, 0);
        glVertex2f(-0.59, -0.13);
        glEnd();


        glBegin(GL_QUADS);
        glColor3ub(77, 60, 61);
        glVertex2f(-0.78, 0.05);
        glVertex2f(-0.96, -0.08);
        glVertex2f(-0.96, -0.13);
        glVertex2f(-0.78, 0);

        glEnd();


        glBegin(GL_QUADS);
        glColor3ub(10, 10, 0);
        glVertex2f(-0.72, -0.15);
        glVertex2f(-0.83, -0.15);
        glVertex2f(-0.83, -0.3);
        glVertex2f(-0.72, -0.3);
        glEnd();

    }

    glPopMatrix();






    //tree1//tree1//tree1//tree1//tree1//tree1//tree1
    glBegin(GL_QUADS);
    glColor3ub(118, 92, 72);
    glVertex2f(-0.62, -0.3);
    glVertex2f(-0.62, 0.1);
    glVertex2f(-0.65, 0.1);
    glVertex2f(-0.65, -0.3);
    glEnd();


    glBegin(GL_TRIANGLES);
    glColor3ub(66, 105, 41);
    glVertex2f(-0.57, -0.1);
    glVertex2f(-0.635, 0.15);
    glVertex2f(-0.7, -0.1);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(66, 105, 41);
    glVertex2f(-0.57, -0.03);
    glVertex2f(-0.635, 0.12);
    glVertex2f(-0.7, -0.03);
    glEnd();


    glBegin(GL_TRIANGLES);
    glColor3ub(66, 105, 41);
    glVertex2f(-0.58, 0.04);
    glVertex2f(-0.635, 0.19);
    glVertex2f(-0.69, 0.04);
    glEnd();


    //tree2//tree2//tree2//tree2//tree2//tree2//tree2//tree2//tree2
    glPushMatrix();

    glScalef(0.4, 0.65, 1);
    glTranslatef(0.75, 0.04, 0);
    {


        glBegin(GL_QUADS);
        glColor3ub(118, 92, 72);
        glVertex2f(-0.62, -0.3);
        glVertex2f(-0.62, 0.1);
        glVertex2f(-0.65, 0.1);
        glVertex2f(-0.65, -0.3);
        glEnd();


        glBegin(GL_TRIANGLES);
        glColor3ub(66, 105, 41);
        glVertex2f(-0.57, -0.1);
        glVertex2f(-0.635, 0.15);
        glVertex2f(-0.7, -0.1);
        glEnd();

        glBegin(GL_TRIANGLES);
        glColor3ub(66, 105, 41);
        glVertex2f(-0.57, -0.03);
        glVertex2f(-0.635, 0.12);
        glVertex2f(-0.7, -0.03);
        glEnd();


        glBegin(GL_TRIANGLES);
        glColor3ub(66, 105, 41);
        glVertex2f(-0.58, 0.04);
        glVertex2f(-0.635, 0.19);
        glVertex2f(-0.69, 0.04);
        glEnd();

    }

    glPopMatrix();



    //tree3//tree3//tree3//tree3//tree3//tree3//tree3//tree3
    glPushMatrix();

    glScalef(0.4, 0.65, 1);
    glTranslatef(3.0, -0.2, 0);
    {


        glBegin(GL_QUADS);
        glColor3ub(118, 92, 72);
        glVertex2f(-0.62, -0.3);
        glVertex2f(-0.62, 0.1);
        glVertex2f(-0.65, 0.1);
        glVertex2f(-0.65, -0.3);
        glEnd();


        glBegin(GL_TRIANGLES);
        glColor3ub(66, 105, 41);
        glVertex2f(-0.57, -0.1);
        glVertex2f(-0.635, 0.15);
        glVertex2f(-0.7, -0.1);
        glEnd();

        glBegin(GL_TRIANGLES);
        glColor3ub(66, 105, 41);
        glVertex2f(-0.57, -0.03);
        glVertex2f(-0.635, 0.12);
        glVertex2f(-0.7, -0.03);
        glEnd();


        glBegin(GL_TRIANGLES);
        glColor3ub(66, 105, 41);
        glVertex2f(-0.58, 0.04);
        glVertex2f(-0.635, 0.19);
        glVertex2f(-0.69, 0.04);
        glEnd();

    }

    glPopMatrix();

    //tree4//tree4//tree4//tree4//tree4//tree4//tree4
    glPushMatrix();

    glScalef(0.4, 0.65, 1);
    glTranslatef(2.75, -0.2, 0);
    {


        glBegin(GL_QUADS);
        glColor3ub(118, 92, 72);
        glVertex2f(-0.62, -0.3);
        glVertex2f(-0.62, 0.1);
        glVertex2f(-0.65, 0.1);
        glVertex2f(-0.65, -0.3);
        glEnd();


        glBegin(GL_TRIANGLES);
        glColor3ub(66, 105, 41);
        glVertex2f(-0.57, -0.1);
        glVertex2f(-0.635, 0.15);
        glVertex2f(-0.7, -0.1);
        glEnd();

        glBegin(GL_TRIANGLES);
        glColor3ub(66, 105, 41);
        glVertex2f(-0.57, -0.03);
        glVertex2f(-0.635, 0.12);
        glVertex2f(-0.7, -0.03);
        glEnd();


        glBegin(GL_TRIANGLES);
        glColor3ub(66, 105, 41);
        glVertex2f(-0.58, 0.04);
        glVertex2f(-0.635, 0.19);
        glVertex2f(-0.69, 0.04);
        glEnd();

    }

    glPopMatrix();



    //tree5//tree5//tree5//tree5//tree5//tree5//tree5//tree5
    glPushMatrix();

    glScalef(0.9, 1.2, 1);
    glTranslatef(0.8, -0.072, 0);
    {


        glBegin(GL_QUADS);
        glColor3ub(118, 92, 72);
        glVertex2f(-0.62, -0.3);
        glVertex2f(-0.62, 0.1);
        glVertex2f(-0.65, 0.1);
        glVertex2f(-0.65, -0.3);
        glEnd();


        glBegin(GL_TRIANGLES);
        glColor3ub(66, 105, 41);
        glVertex2f(-0.57, -0.1);
        glVertex2f(-0.635, 0.15);
        glVertex2f(-0.7, -0.1);
        glEnd();

        glBegin(GL_TRIANGLES);
        glColor3ub(66, 105, 41);
        glVertex2f(-0.57, -0.03);
        glVertex2f(-0.635, 0.12);
        glVertex2f(-0.7, -0.03);
        glEnd();


        glBegin(GL_TRIANGLES);
        glColor3ub(66, 105, 41);
        glVertex2f(-0.58, 0.04);
        glVertex2f(-0.635, 0.19);
        glVertex2f(-0.69, 0.04);
        glEnd();

    }

    glPopMatrix();


    //tree6 //tree6 //tree6 //tree6 //tree6 //tree6 //tree6 //tree6 //tree6
    glPushMatrix();

    glScalef(0.9, 1.2, 1);
    glTranslatef(1.12, -0.072, 0);
    {


        glBegin(GL_QUADS);
        glColor3ub(118, 92, 72);
        glVertex2f(-0.62, -0.3);
        glVertex2f(-0.62, 0.1);
        glVertex2f(-0.65, 0.1);
        glVertex2f(-0.65, -0.3);
        glEnd();


        glBegin(GL_TRIANGLES);
        glColor3ub(66, 105, 41);
        glVertex2f(-0.57, -0.1);
        glVertex2f(-0.635, 0.15);
        glVertex2f(-0.7, -0.1);
        glEnd();

        glBegin(GL_TRIANGLES);
        glColor3ub(66, 105, 41);
        glVertex2f(-0.57, -0.03);
        glVertex2f(-0.635, 0.12);
        glVertex2f(-0.7, -0.03);
        glEnd();


        glBegin(GL_TRIANGLES);
        glColor3ub(66, 105, 41);
        glVertex2f(-0.58, 0.04);
        glVertex2f(-0.635, 0.19);
        glVertex2f(-0.69, 0.04);
        glEnd();

    }

    glPopMatrix();

    //tree7//tree7//tree7//tree7//tree7//tree7//tree7
    glPushMatrix();

    glScalef(0.9, 1.2, 1);
    glTranslatef(1.42, -0.072, 0);
    {


        glBegin(GL_QUADS);
        glColor3ub(118, 92, 72);
        glVertex2f(-0.62, -0.3);
        glVertex2f(-0.62, 0.1);
        glVertex2f(-0.65, 0.1);
        glVertex2f(-0.65, -0.3);
        glEnd();


        glBegin(GL_TRIANGLES);
        glColor3ub(66, 105, 41);
        glVertex2f(-0.57, -0.1);
        glVertex2f(-0.635, 0.15);
        glVertex2f(-0.7, -0.1);
        glEnd();

        glBegin(GL_TRIANGLES);
        glColor3ub(66, 105, 41);
        glVertex2f(-0.57, -0.03);
        glVertex2f(-0.635, 0.12);
        glVertex2f(-0.7, -0.03);
        glEnd();


        glBegin(GL_TRIANGLES);
        glColor3ub(66, 105, 41);
        glVertex2f(-0.58, 0.04);
        glVertex2f(-0.635, 0.19);
        glVertex2f(-0.69, 0.04);
        glEnd();

    }

    glPopMatrix();




    //rail line//rail line//rail line//rail line//rail line//rail line
    glBegin(GL_QUADS);
    glColor3ub(64, 54, 44);
    glVertex2f(1, -0.60);
    glVertex2f(-1, -0.60);
    glVertex2f(-1, -0.62);
    glVertex2f(1, -0.62);
    glEnd();

    //rail sand///rail sand///rail sand///rail sand/
    glBegin(GL_QUADS);
    glColor3ub(194, 165, 135);
    glVertex2f(1, -0.62);
    glVertex2f(-1, -0.62);
    glVertex2f(-1, -0.72);
    glVertex2f(1, -0.72);
    glEnd();


    //rail line wood//rail line wood//rail line wood//rail line wood//rail line wood
    /*
    //rail line wood
    glBegin(GL_QUADS);
    glColor3ub(90,92,72);
    glVertex2f(-0.85, -0.7);
    glVertex2f(-0.9,-0.7);
    glVertex2f(-0.9,-0.713);
    glVertex2f(-0.85,-0.713);
    glEnd();
    */
    //rail line wood//rail line wood//rail line wood//rail line wood//rail line wood
    float a1, a2, increment;
    a1 = -0.85;
    a2 = -0.9;
    increment = 0;

    for (int i = 0; i < 15; i++)
    {

        glBegin(GL_QUADS);
        glColor3ub(90, 92, 72);
        glVertex2f(a1 + increment, -0.62);
        glVertex2f(a2 + increment, -0.62);
        glVertex2f(a2 + increment, -0.633);
        glVertex2f(a1 + increment, -0.633);
        glEnd();
        increment = increment + 0.15;

    }




    //water river//water river//water river//water river//water river
    glBegin(GL_QUADS);
    glColor3ub(127, 197, 222);
    glVertex2f(1, -0.72);
    glVertex2f(-1, -0.72);
    glVertex2f(-1, -1);
    glVertex2f(1, -1);
    glEnd();




    //boat1//boat1//boat1//boat1//boat1//boat1
    glPushMatrix();//move
    glTranslatef(position2, 0.0, 0);
    {



        glPushMatrix();

        glScalef(0.04, 0.05, 1.0);

        glTranslatef(5, -19, 0.0);
        {
            glBegin(GL_POLYGON);
            glColor3f(0.0, 0.0, 0.0);
            glVertex3f(0.0, 0.0, 0.0);
            glVertex3f(1.0, 0.0, 0.0);
            glVertex3f(2.0, 1.0, 0.0);
            glVertex3f(-2.0, 1.0, 0.0);
            glVertex3f(-1.0, 0.0, 0.0);
            glEnd();

            glBegin(GL_POLYGON);
            glColor3f(1.0, 1.0, 0.0);
            glVertex3f(0.6, 1.2, 0.0);
            glVertex3f(0.4, 1.2, 0.0);
            glVertex3f(0.4, 1.4, 0.0);
            glVertex3f(0.6, 1.4, 0.0);
            glEnd();

            glBegin(GL_POLYGON);
            glColor3f(1.0, 1.0, 0.0);
            glVertex3f(-0.6, 1.2, 0.0);
            glVertex3f(-0.4, 1.2, 0.0);
            glVertex3f(-0.4, 1.4, 0.0);
            glVertex3f(-0.6, 1.4, 0.0);
            glEnd();

            glBegin(GL_POLYGON);
            glColor3f(0.698, 0.133, 0.133);
            glVertex3f(-1.0, 1.0, 0.0);
            glVertex3f(1.0, 1.0, 0.0);
            glVertex3f(1.0, 2.0, 0.0);
            glVertex3f(-1.0, 2.0, 0.0);
            glEnd();

        }
        glPopMatrix();
    }
    glPopMatrix();



    glPushMatrix();//move
    glTranslatef(position3, 0.0, 0);
    {

        //boat2//boat2//boat2//boat2//boat2//boat2
        glPushMatrix();

        glScalef(0.03, 0.04, 1.0);

        glTranslatef(11, -22, 0.0);
        {
            glBegin(GL_POLYGON);
            glColor3f(0.0, 0.0, 0.0);
            glVertex3f(0.0, 0.0, 0.0);
            glVertex3f(1.0, 0.0, 0.0);
            glVertex3f(2.0, 1.0, 0.0);
            glVertex3f(-2.0, 1.0, 0.0);
            glVertex3f(-1.0, 0.0, 0.0);
            glEnd();

            glBegin(GL_POLYGON);
            glColor3f(1.0, 1.0, 0.0);
            glVertex3f(0.6, 1.2, 0.0);
            glVertex3f(0.4, 1.2, 0.0);
            glVertex3f(0.4, 1.4, 0.0);
            glVertex3f(0.6, 1.4, 0.0);
            glEnd();

            glBegin(GL_POLYGON);
            glColor3f(1.0, 1.0, 0.0);
            glVertex3f(-0.6, 1.2, 0.0);
            glVertex3f(-0.4, 1.2, 0.0);
            glVertex3f(-0.4, 1.4, 0.0);
            glVertex3f(-0.6, 1.4, 0.0);
            glEnd();

            glBegin(GL_POLYGON);
            glColor3f(0.698, 0.133, 0.133);
            glVertex3f(-1.0, 1.0, 0.0);
            glVertex3f(1.0, 1.0, 0.0);
            glVertex3f(1.0, 2.0, 0.0);
            glVertex3f(-1.0, 2.0, 0.0);
            glEnd();

        }
        glPopMatrix();

    }
    glPopMatrix();


    //boat3//boat3//boat3//boat3//boat3//boat3//boat3

    glPushMatrix();//move
    glTranslatef(position4, 0.0, 0);
    {
        glPushMatrix();

        glScalef(0.04, 0.05, 1.0);

        glTranslatef(-10, -18, 0.0);
        {
            glBegin(GL_POLYGON);
            glColor3f(0.0, 0.0, 0.0);
            glVertex3f(0.0, 0.0, 0.0);
            glVertex3f(1.0, 0.0, 0.0);
            glVertex3f(2.0, 1.0, 0.0);
            glVertex3f(-2.0, 1.0, 0.0);
            glVertex3f(-1.0, 0.0, 0.0);
            glEnd();

            glBegin(GL_POLYGON);
            glColor3f(1.0, 1.0, 0.0);
            glVertex3f(0.6, 1.2, 0.0);
            glVertex3f(0.4, 1.2, 0.0);
            glVertex3f(0.4, 1.4, 0.0);
            glVertex3f(0.6, 1.4, 0.0);
            glEnd();

            glBegin(GL_POLYGON);
            glColor3f(1.0, 1.0, 0.0);
            glVertex3f(-0.6, 1.2, 0.0);
            glVertex3f(-0.4, 1.2, 0.0);
            glVertex3f(-0.4, 1.4, 0.0);
            glVertex3f(-0.6, 1.4, 0.0);
            glEnd();

            glBegin(GL_POLYGON);
            glColor3f(0.698, 0.133, 0.133);
            glVertex3f(-1.0, 1.0, 0.0);
            glVertex3f(1.0, 1.0, 0.0);
            glVertex3f(1.0, 2.0, 0.0);
            glVertex3f(-1.0, 2.0, 0.0);
            glEnd();

        }
        glPopMatrix();
    }
    glPopMatrix();



    //train start//train start//train start//train start//train start


    //for move


    glPushMatrix();
    glScalef(0.75, 0.75, 1);
    glTranslatef(position, -0.20, 0);

    {



        //wheel1//wheel1//wheel1//wheel1//wheel1//wheel1//wheel1//wheel1
        glPushMatrix();

        glScalef(0.55, 1, 1);
        glTranslatef(-0.87, 0.225, 0);
        {




            GLfloat x = -0.85;
            GLfloat y = -0.8;
            GLfloat radius = .03f;
            int triangleAmount = 40; //# of triangles used to draw circle# of triangles used to draw circle# of triangles used to draw circle

            //GLfloat radius = 0.8f; //radius
            GLfloat twicePi = 2.0f * PI;

            glBegin(GL_TRIANGLE_FAN);
            glColor3ub(0, 0, 0);
            glVertex2f(x, y); // center of circle
            for (int i = 0; i <= triangleAmount; i++)
            {
                glVertex2f(
                    x + (radius * cos(i * twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount))
                );
            }
            glEnd();


        }

        glPopMatrix();


        //wheel2//wheel2//wheel2//wheel2//wheel2//wheel2//wheel2
        glPushMatrix();

        glScalef(0.55, 1, 1);
        glTranslatef(-0.69, 0.225, 0);
        {


            GLfloat x = -0.85;
            GLfloat y = -0.8;
            GLfloat radius = .03f;
            int triangleAmount = 40; //# of triangles used to draw circle# of triangles used to draw circle# of triangles used to draw circle

            //GLfloat radius = 0.8f; //radius
            GLfloat twicePi = 2.0f * PI;

            glBegin(GL_TRIANGLE_FAN);
            glColor3ub(0, 0, 0);
            glVertex2f(x, y); // center of circle
            for (int i = 0; i <= triangleAmount; i++)
            {
                glVertex2f(
                    x + (radius * cos(i * twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount))
                );
            }
            glEnd();


        }

        glPopMatrix();


        //wheel3//wheel3//wheel3//wheel3//wheel3//wheel3//wheel3//wheel3
        glPushMatrix();

        glScalef(0.54, 1, 1);
        glTranslatef(-0.55, 0.225, 0);
        {


            GLfloat x = -0.85;
            GLfloat y = -0.8;
            GLfloat radius = .03f;
            int triangleAmount = 40; //# of triangles used to draw circle# of triangles used to draw circle# of triangles used to draw circle

            //GLfloat radius = 0.8f; //radius
            GLfloat twicePi = 4.0f * PI;

            glBegin(GL_TRIANGLE_FAN);
            glColor3ub(0, 0, 0);
            glVertex2f(x, y); // center of circle
            for (int i = 0; i <= triangleAmount; i++)
            {
                glVertex2f(
                    x + (radius * cos(i * twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount))
                );
            }
            glEnd();


        }

        glPopMatrix();




        //wheel4//wheel4//wheel4//wheel4//wheel4//wheel4//wheel4
        glPushMatrix();

        glScalef(0.55, 1, 1);
        glTranslatef(-0.35, 0.225, 0);
        {


            GLfloat x = -0.85;
            GLfloat y = -0.8;
            GLfloat radius = .03f;
            int triangleAmount = 40; //# of triangles used to draw circle# of triangles used to draw circle# of triangles used to draw circle

            //GLfloat radius = 0.8f; //radius
            GLfloat twicePi = 2.0f * PI;

            glBegin(GL_TRIANGLE_FAN);
            glColor3ub(0, 0, 0);
            glVertex2f(x, y); // center of circle
            for (int i = 0; i <= triangleAmount; i++)
            {
                glVertex2f(
                    x + (radius * cos(i * twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount))
                );
            }
            glEnd();


        }

        glPopMatrix();



        //wheel5//wheel5//wheel5//wheel5//wheel5//wheel5//wheel5//wheel5//wheel5
        glPushMatrix();

        glScalef(0.54, 1, 1);
        glTranslatef(-0.20, 0.225, 0);
        {


            GLfloat x = -0.85;
            GLfloat y = -0.8;
            GLfloat radius = .03f;
            int triangleAmount = 40; //# of triangles used to draw circle# of triangles used to draw circle# of triangles used to draw circle

            //GLfloat radius = 0.8f; //radius
            GLfloat twicePi = 4.0f * PI;

            glBegin(GL_TRIANGLE_FAN);
            glColor3ub(0, 0, 0);
            glVertex2f(x, y); // center of circle
            for (int i = 0; i <= triangleAmount; i++)
            {
                glVertex2f(
                    x + (radius * cos(i * twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount))
                );
            }
            glEnd();


        }

        glPopMatrix();




        //wheel6//wheel6//wheel6//wheel6//wheel6//wheel6//wheel6//wheel6//wheel6//wheel6
        glPushMatrix();

        glScalef(0.55, 1, 1);
        glTranslatef(0.01, 0.225, 0);
        {


            GLfloat x = -0.85;
            GLfloat y = -0.8;
            GLfloat radius = .03f;
            int triangleAmount = 40; //# of triangles used to draw circle# of triangles used to draw circle# of triangles used to draw circle

            //GLfloat radius = 0.8f; //radius
            GLfloat twicePi = 2.0f * PI;

            glBegin(GL_TRIANGLE_FAN);
            glColor3ub(0, 0, 0);
            glVertex2f(x, y); // center of circle
            for (int i = 0; i <= triangleAmount; i++)
            {
                glVertex2f(
                    x + (radius * cos(i * twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount))
                );
            }
            glEnd();


        }

        glPopMatrix();



        //wheel7//wheel7//wheel7//wheel7//wheel7//wheel7//wheel7
        glPushMatrix();

        glScalef(0.54, 1, 1);
        glTranslatef(0.17, 0.225, 0);
        {


            GLfloat x = -0.85;
            GLfloat y = -0.8;
            GLfloat radius = .03f;
            int triangleAmount = 40; //# of triangles used to draw circle# of triangles used to draw circle# of triangles used to draw circle

            //GLfloat radius = 0.8f; //radius
            GLfloat twicePi = 4.0f * PI;

            glBegin(GL_TRIANGLE_FAN);
            glColor3ub(0, 0, 0);
            glVertex2f(x, y); // center of circle
            for (int i = 0; i <= triangleAmount; i++)
            {
                glVertex2f(
                    x + (radius * cos(i * twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount))
                );
            }
            glEnd();


        }

        glPopMatrix();




        //wheel8//wheel8//wheel8//wheel8//wheel8//wheel8//wheel8
        glPushMatrix();

        glScalef(0.55, 1, 1);
        glTranslatef(0.39, 0.225, 0);
        {


            GLfloat x = -0.85;
            GLfloat y = -0.8;
            GLfloat radius = .03f;
            int triangleAmount = 40; //# of triangles used to draw circle# of triangles used to draw circle# of triangles used to draw circle

            //GLfloat radius = 0.8f; //radius
            GLfloat twicePi = 2.0f * PI;

            glBegin(GL_TRIANGLE_FAN);
            glColor3ub(0, 0, 0);
            glVertex2f(x, y); // center of circle
            for (int i = 0; i <= triangleAmount; i++)
            {
                glVertex2f(
                    x + (radius * cos(i * twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount))
                );
            }
            glEnd();


        }

        glPopMatrix();

        //body1//body1//body1//body1//body1//body1//body1//body1
        glBegin(GL_QUADS);
        glColor3ub(0, 54, 54);
        glVertex2f(-0.81, -0.386);
        glVertex2f(-0.98, -0.386);
        glVertex2f(-0.98, -0.575);
        glVertex2f(-0.81, -0.575);
        glEnd();


        //lowerpart1//lowerpart1//lowerpart1//lowerpart1
        glBegin(GL_QUADS);
        glColor3ub(0, 0, 0);
        glVertex2f(-0.81, -0.555);
        glVertex2f(-0.98, -0.555);
        glVertex2f(-0.98, -0.575);
        glVertex2f(-0.81, -0.575);
        glEnd();


        //join1//join1//join1//join1//join1//join1//join1
        glBegin(GL_QUADS);
        glColor3ub(0, 0, 0);
        glVertex2f(-0.79, -0.565);
        glVertex2f(-0.81, -0.565);
        glVertex2f(-0.81, -0.575);
        glVertex2f(-0.79, -0.575);
        glEnd();


        //body2//body2//body2//body2//body2//body2//body2//body2
        glBegin(GL_QUADS);
        glColor3ub(0, 54, 54);
        glVertex2f(-0.62, -0.386);
        glVertex2f(-0.79, -0.386);
        glVertex2f(-0.79, -0.575);
        glVertex2f(-0.62, -0.575);
        glEnd();


        //lowerpart2//lowerpart2//lowerpart2//lowerpart2
        glBegin(GL_QUADS);
        glColor3ub(0, 0, 0);
        glVertex2f(-0.62, -0.555);
        glVertex2f(-0.79, -0.555);
        glVertex2f(-0.79, -0.575);
        glVertex2f(-0.62, -0.575);
        glEnd();


        //join2//join2//join2//join2//join2//join2//join2//join2
        glBegin(GL_QUADS);
        glColor3ub(0, 0, 0);
        glVertex2f(-0.6, -0.565);
        glVertex2f(-0.62, -0.565);
        glVertex2f(-0.62, -0.575);
        glVertex2f(-0.6, -0.575);
        glEnd();


        //body3//body3//body3//body3//body3//body3//body3
        glBegin(GL_QUADS);
        glColor3ub(0, 54, 54);
        glVertex2f(-0.43, -0.386);
        glVertex2f(-0.60, -0.386);
        glVertex2f(-0.60, -0.575);
        glVertex2f(-0.43, -0.575);
        glEnd();

        //lowerpart3//lowerpart3//lowerpart3//lowerpart3
        glBegin(GL_QUADS);
        glColor3ub(0, 0, 0);
        glVertex2f(-0.43, -0.555);
        glVertex2f(-0.60, -0.555);
        glVertex2f(-0.60, -0.575);
        glVertex2f(-0.43, -0.575);
        glEnd();

        //join3//join3//join3//join3//join3//join3//join3//join3
        glBegin(GL_QUADS);
        glColor3ub(0, 0, 0);
        glVertex2f(-0.41, -0.565);
        glVertex2f(-0.43, -0.565);
        glVertex2f(-0.43, -0.575);
        glVertex2f(-0.41, -0.575);
        glEnd();


        //body4//body4//body4//body4//body4//body4
        glBegin(GL_QUADS);
        glColor3ub(0, 54, 54);
        glVertex2f(-0.26, -0.386);
        glVertex2f(-0.41, -0.386);
        glVertex2f(-0.41, -0.575);
        glVertex2f(-0.26, -0.575);
        glEnd();


        //body triangle//body triangle//body triangle//body triangle
        glBegin(GL_TRIANGLES);
        glColor3ub(0, 54, 54);
        glVertex2f(-0.185, -0.555);
        glVertex2f(-0.26, -0.386);
        glVertex2f(-0.26, -0.555);
        glEnd();

        //body smoke//body smoke//body smoke//body smoke
        glBegin(GL_QUADS);
        glColor3ub(25, 68, 74);
        glVertex2f(-0.28, -0.33);
        glVertex2f(-0.33, -0.33);
        glVertex2f(-0.33, -0.386);
        glVertex2f(-0.28, -0.386);
        glEnd();


        //lowerpart4//lowerpart4//lowerpart4//lowerpart4//lowerpart4
        glBegin(GL_QUADS);
        glColor3ub(0, 0, 0);
        glVertex2f(-0.185, -0.555);
        glVertex2f(-0.41, -0.555);
        glVertex2f(-0.41, -0.575);
        glVertex2f(-0.185, -0.575);
        glEnd();



        //windows 1 and door 1//windows 1 and door 1//windows 1 and door 1//windows 1 and door 1

        glBegin(GL_QUADS);
        glColor3ub(107, 153, 166);
        glVertex2f(-0.93, -0.44);
        glVertex2f(-0.95, -0.44);
        glVertex2f(-0.95, -0.48);
        glVertex2f(-0.93, -0.48);
        glEnd();

        glBegin(GL_QUADS);
        glColor3ub(107, 153, 166);
        glVertex2f(-0.88, -0.44);
        glVertex2f(-0.9, -0.44);
        glVertex2f(-0.9, -0.48);
        glVertex2f(-0.88, -0.48);
        glEnd();


        glBegin(GL_QUADS);
        glColor3ub(86, 112, 120);
        glVertex2f(-0.825, -0.42);
        glVertex2f(-0.85, -0.42);
        glVertex2f(-0.85, -0.54);
        glVertex2f(-0.825, -0.54);
        glEnd();



        //windows 2 and door 2//windows 2 and door 2//windows 2 and door 2//windows 2 and door 2

        glBegin(GL_QUADS);
        glColor3ub(107, 153, 166);
        glVertex2f(-0.73, -0.44);
        glVertex2f(-0.75, -0.44);
        glVertex2f(-0.75, -0.48);
        glVertex2f(-0.73, -0.48);
        glEnd();

        glBegin(GL_QUADS);
        glColor3ub(107, 153, 166);
        glVertex2f(-0.68, -0.44);
        glVertex2f(-0.7, -0.44);
        glVertex2f(-0.7, -0.48);
        glVertex2f(-0.68, -0.48);
        glEnd();


        glBegin(GL_QUADS);
        glColor3ub(86, 112, 120);
        glVertex2f(-0.635, -0.42);
        glVertex2f(-0.66, -0.42);
        glVertex2f(-0.66, -0.54);
        glVertex2f(-0.635, -0.54);
        glEnd();




        //windows 3 and door 3//windows 3 and door 3//windows 3 and door 3//windows 3 and door 3

        glBegin(GL_QUADS);
        glColor3ub(107, 153, 166);
        glVertex2f(-0.55, -0.44);
        glVertex2f(-0.57, -0.44);
        glVertex2f(-0.57, -0.48);
        glVertex2f(-0.55, -0.48);
        glEnd();

        glBegin(GL_QUADS);
        glColor3ub(107, 153, 166);
        glVertex2f(-0.5, -0.44);
        glVertex2f(-0.52, -0.44);
        glVertex2f(-0.52, -0.48);
        glVertex2f(-0.5, -0.48);
        glEnd();


        glBegin(GL_QUADS);
        glColor3ub(86, 112, 120);
        glVertex2f(-0.445, -0.42);
        glVertex2f(-0.47, -0.42);
        glVertex2f(-0.47, -0.54);
        glVertex2f(-0.445, -0.54);
        glEnd();



        //windows 4 and door 4//windows 4 and door 4//windows 4 and door 4//windows 4 and door 4

        glBegin(GL_QUADS);
        glColor3ub(107, 153, 166);
        glVertex2f(-0.36, -0.44);
        glVertex2f(-0.38, -0.44);
        glVertex2f(-0.38, -0.48);
        glVertex2f(-0.36, -0.48);
        glEnd();

        glBegin(GL_QUADS);
        glColor3ub(107, 153, 166);
        glVertex2f(-0.28, -0.44);
        glVertex2f(-0.3, -0.44);
        glVertex2f(-0.3, -0.48);
        glVertex2f(-0.28, -0.48);
        glEnd();


        glBegin(GL_QUADS);
        glColor3ub(86, 112, 120);
        glVertex2f(-0.315, -0.42);
        glVertex2f(-0.34, -0.42);
        glVertex2f(-0.34, -0.54);
        glVertex2f(-0.315, -0.54);
        glEnd();

    }
    glPopMatrix();

    //train end//train end//train end//train end//train end//train end


    //Sun //Sun//Sun//Sun//Sun//Sun//Sun//Sun //Sun//Sun//Sun//Sun//Sun//Sun//Sun //Sun//Sun//Sun//Sun//Sun//Sun
    glPushMatrix();

    glScalef(0.55, 1, 1);
    glTranslatef(0.8, 0, 0);
    {

        //Sun //Sun//Sun//Sun//Sun//Sun//Sun
        GLfloat x = 0.85;
        GLfloat y = 0.8;
        GLfloat radius = .13f;
        int triangleAmount = 20; //# of triangles used to draw circle# of triangles used to draw circle# of triangles used to draw circle

        //GLfloat radius = 0.8f; //radius
        GLfloat twicePi = 2.0f * PI;

        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(249, 215, 28);
        glVertex2f(x, y); // center of circle
        for (int i = 0; i <= triangleAmount; i++)
        {
            glVertex2f(
                x + (radius * cos(i * twicePi / triangleAmount)),
                y + (radius * sin(i * twicePi / triangleAmount))
            );
        }
        glEnd();


    }

    glPopMatrix();





    glPushMatrix();
    glScalef(0.95, 1.3, 1);
    glTranslatef(-0.05, -0.2, 0);
    {
        //cloud start //cloud start //cloud start //cloud start //cloud start
        glLineWidth(1);

        GLfloat x = -0.92f;
        GLfloat y = .725f;
        GLfloat radius = .055f;

        int lineAmount = 100; //# of triangles used to draw circle

        //GLfloat radius = 0.8f; //radius
        GLfloat twicePi = 2.0f * PI;

        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(208, 222, 236);
        for (int i = 0; i <= lineAmount; i++)
        {
            glVertex2f(
                x + (radius * cos(i * twicePi / lineAmount)),
                y + (radius * sin(i * twicePi / lineAmount))
            );
        }
        glEnd();




        glLineWidth(1);

        x = -0.765f;
        y = .725f;
        radius = .045f;

        lineAmount = 100; //# of triangles used to draw circle

        //GLfloat radius = 0.8f; //radius
        twicePi = 2.0f * PI;

        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(208, 222, 236);
        for (int i = 0; i <= lineAmount; i++)
        {
            glVertex2f(
                x + (radius * cos(i * twicePi / lineAmount)),
                y + (radius * sin(i * twicePi / lineAmount))
            );
        }
        glEnd();



        glLineWidth(1);

        x = -0.85f;
        y = .75f;
        radius = .08f;

        lineAmount = 100; //# of triangles used to draw circle

        //GLfloat radius = 0.8f; //radius
        twicePi = 2.0f * PI;

        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(208, 222, 236);
        for (int i = 0; i <= lineAmount; i++)
        {
            glVertex2f(
                x + (radius * cos(i * twicePi / lineAmount)),
                y + (radius * sin(i * twicePi / lineAmount))
            );
        }
        glEnd();

    }

    glPopMatrix();


    glPushMatrix();
    glScalef(0.8, 0.8, 1);
    glTranslatef(0.5, 0.4, 0);
    {
        //cloud start //cloud start //cloud start //cloud start //cloud start
        glLineWidth(1);

        GLfloat x = -0.92f;
        GLfloat y = .725f;
        GLfloat radius = .055f;

        int lineAmount = 100; //# of triangles used to draw circle

        //GLfloat radius = 0.8f; //radius
        GLfloat twicePi = 2.0f * PI;

        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(208, 222, 236);
        for (int i = 0; i <= lineAmount; i++)
        {
            glVertex2f(
                x + (radius * cos(i * twicePi / lineAmount)),
                y + (radius * sin(i * twicePi / lineAmount))
            );
        }
        glEnd();




        glLineWidth(1);

        x = -0.78f;
        y = .73f;
        radius = .049f;

        lineAmount = 100; //# of triangles used to draw circle

        //GLfloat radius = 0.8f; //radius
        twicePi = 2.0f * PI;

        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(208, 222, 236);
        for (int i = 0; i <= lineAmount; i++)
        {
            glVertex2f(
                x + (radius * cos(i * twicePi / lineAmount)),
                y + (radius * sin(i * twicePi / lineAmount))
            );
        }
        glEnd();



        glLineWidth(1);

        x = -0.85f;
        y = .73f;
        radius = .06f;

        lineAmount = 100; //# of triangles used to draw circle

        //GLfloat radius = 0.8f; //radius
        twicePi = 2.0f * PI;

        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(208, 222, 236);
        for (int i = 0; i <= lineAmount; i++)
        {
            glVertex2f(
                x + (radius * cos(i * twicePi / lineAmount)),
                y + (radius * sin(i * twicePi / lineAmount))
            );
        }
        glEnd();

    }

    glPopMatrix();




    //text for 1
    glPushMatrix();//move
    glTranslatef(position8, 0.0, 0);
    {
        glColor3ub(243, 0, 0);
        glRasterPos2f(-0.3f, 0.42f);
        const char* text = "Press 's' to start the train engine";
        for (int i = 0; text[i] != '\0'; ++i)
        {
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);
        }

    }
    glPopMatrix();





    glFlush();  // Render now
}


void display2()
{







    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
    glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)



    glBegin(GL_QUADS);// sky //// sky //// sky //// sky //
    glColor3ub(155, 206, 235);//135,206,235
    glVertex2f(1, 1);
    glVertex2f(-1, 1);
    glVertex2f(-1, -1);
    glVertex2f(1, -1);
    glEnd();







    //upper road //upper road //upper road //upper road //upper road
    glBegin(GL_QUADS);
    glColor3ub(150, 149, 148);
    glVertex2f(1, -0.52);
    glVertex2f(-1, -0.52);
    glVertex2f(-1, -1);
    glVertex2f(1, -1);
    glEnd();

    //beach sand /beach sand/beach sand/beach sand/beach sand
    glBegin(GL_QUADS);
    glColor3ub(230, 188, 135);
    glVertex2f(1, -0.32);
    glVertex2f(-1, -0.32);
    glVertex2f(-1, -0.52);
    glVertex2f(1, -0.52);
    glEnd();


    //sea//sea//sea//sea//sea//sea//sea
    glBegin(GL_QUADS);
    glColor3ub(118, 194, 222);
    glVertex2f(1, -0.02);
    glVertex2f(-1, -0.02);
    glVertex2f(-1, -0.32);
    glVertex2f(1, -0.32);
    glEnd();


    //boat 1 display 2//boat 1 display 2//boat 1 display 2


    glPushMatrix();//move
    glTranslatef(position6, 0.0, 0);
    {


        glPushMatrix();

        glScalef(0.01, 0.02, 1.0);

        glTranslatef(-70, -2.8, 0.0);
        {
            glBegin(GL_POLYGON);
            glColor3f(0.0, 0.0, 0.0);
            glVertex3f(0.0, 0.0, 0.0);
            glVertex3f(1.0, 0.0, 0.0);
            glVertex3f(2.0, 1.0, 0.0);
            glVertex3f(-2.0, 1.0, 0.0);
            glVertex3f(-1.0, 0.0, 0.0);
            glEnd();

            glBegin(GL_POLYGON);
            glColor3f(1.0, 1.0, 0.0);
            glVertex3f(0.6, 1.2, 0.0);
            glVertex3f(0.4, 1.2, 0.0);
            glVertex3f(0.4, 1.4, 0.0);
            glVertex3f(0.6, 1.4, 0.0);
            glEnd();

            glBegin(GL_POLYGON);
            glColor3f(1.0, 1.0, 0.0);
            glVertex3f(-0.6, 1.2, 0.0);
            glVertex3f(-0.4, 1.2, 0.0);
            glVertex3f(-0.4, 1.4, 0.0);
            glVertex3f(-0.6, 1.4, 0.0);
            glEnd();

            glBegin(GL_POLYGON);
            glColor3f(0.698, 0.133, 0.133);
            glVertex3f(-1.0, 1.0, 0.0);
            glVertex3f(1.0, 1.0, 0.0);
            glVertex3f(1.0, 2.0, 0.0);
            glVertex3f(-1.0, 2.0, 0.0);
            glEnd();

        }
        glPopMatrix();

    }
    glPopMatrix();

    //boat 2 display 2//boat 2 display 2//boat 2 display 2//boat 2 display 2//boat 2 display 2

    glPushMatrix();//move
    glTranslatef(position5, 0.0, 0);
    {



        glPushMatrix();

        glScalef(0.02, 0.03, 1.0);

        glTranslatef(-30, -5, 0.0);
        {
            glBegin(GL_POLYGON);
            glColor3f(0.0, 0.0, 0.0);
            glVertex3f(0.0, 0.0, 0.0);
            glVertex3f(1.0, 0.0, 0.0);
            glVertex3f(2.0, 1.0, 0.0);
            glVertex3f(-2.0, 1.0, 0.0);
            glVertex3f(-1.0, 0.0, 0.0);
            glEnd();

            glBegin(GL_POLYGON);
            glColor3f(1.0, 1.0, 0.0);
            glVertex3f(0.6, 1.2, 0.0);
            glVertex3f(0.4, 1.2, 0.0);
            glVertex3f(0.4, 1.4, 0.0);
            glVertex3f(0.6, 1.4, 0.0);
            glEnd();

            glBegin(GL_POLYGON);
            glColor3f(1.0, 1.0, 0.0);
            glVertex3f(-0.6, 1.2, 0.0);
            glVertex3f(-0.4, 1.2, 0.0);
            glVertex3f(-0.4, 1.4, 0.0);
            glVertex3f(-0.6, 1.4, 0.0);
            glEnd();

            glBegin(GL_POLYGON);
            glColor3f(0.698, 0.133, 0.133);
            glVertex3f(-1.0, 1.0, 0.0);
            glVertex3f(1.0, 1.0, 0.0);
            glVertex3f(1.0, 2.0, 0.0);
            glVertex3f(-1.0, 2.0, 0.0);
            glEnd();

        }
        glPopMatrix();

    }
    glPopMatrix();








    //train station start//train station start//train station start//train station start

    //floor//floor//floor//floor//floor//floor

    glPushMatrix();
    glScalef(.75, .75, 1);
    glTranslatef(0.3, -0.175, 0);

    {


        glBegin(GL_QUADS);
        glColor3ub(67, 63, 62);
        glVertex2f(0.7, -0.48);
        glVertex2f(0.1, -0.48);
        glVertex2f(0.1, -0.52);
        glVertex2f(0.7, -0.52);
        glEnd();




        //square roof//square roof//square roof//square roof//square roof
        glBegin(GL_QUADS);
        glColor3ub(223, 219, 214);
        glVertex2f(0.75, -0.15);
        glVertex2f(0.05, -0.15);
        glVertex2f(0.05, -0.25);
        glVertex2f(0.75, -0.25);
        glEnd();





        //pillar//pillar//pillar//pillar//pillar//pillar//pillar//pillar



        //pillar 1
        glBegin(GL_QUADS);
        glColor3ub(103, 40, 38);
        glVertex2f(0.18, -0.25);
        glVertex2f(0.12, -0.25);
        glVertex2f(0.14, -0.48);
        glVertex2f(0.16, -0.48);
        glEnd();


        //pillar 2
        glPushMatrix();
        glTranslatef(0.14, 0, 0);
        {

            glBegin(GL_QUADS);
            glColor3ub(0, 40, 38);
            glVertex2f(0.18, -0.25);
            glVertex2f(0.12, -0.25);
            glVertex2f(0.14, -0.48);
            glVertex2f(0.16, -0.48);
            glEnd();

        }

        glPopMatrix();


        //pillar 3
        glPushMatrix();
        glTranslatef(0.34, 0, 0);
        {

            glBegin(GL_QUADS);
            glColor3ub(0, 40, 38);
            glVertex2f(0.18, -0.25);
            glVertex2f(0.12, -0.25);
            glVertex2f(0.14, -0.48);
            glVertex2f(0.16, -0.48);
            glEnd();

        }

        glPopMatrix();


        //pillar 4
        glPushMatrix();
        glTranslatef(0.5, 0, 0);
        {

            glBegin(GL_QUADS);
            glColor3ub(103, 40, 38);
            glVertex2f(0.18, -0.25);
            glVertex2f(0.12, -0.25);
            glVertex2f(0.14, -0.48);
            glVertex2f(0.16, -0.48);
            glEnd();

        }

        glPopMatrix();





        //curve roof//curve roof//curve roof//curve roof

        //curve 1
        glPushMatrix();

        glScalef(0.55, 1, 1);
        glTranslatef(-0.45, -0.95, 0);
        {


            GLfloat x = 0.85;
            GLfloat y = 0.8;
            GLfloat radius = .21f;
            int triangleAmount = 20; //# of triangles used to draw circle# of triangles used to draw circle# of triangles used to draw circle

            //GLfloat radius = 0.8f; //radius
            GLfloat twicePi = 1.0f * PI;

            glBegin(GL_TRIANGLE_FAN);
            glColor3ub(232, 232, 232);
            glVertex2f(x, y); // center of circle
            for (int i = 0; i <= triangleAmount; i++)
            {
                glVertex2f(
                    x + (radius * cos(i * twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount))
                );
            }
            glEnd();


        }

        glPopMatrix();



        glPushMatrix();

        glScalef(0.55, 1, 1);
        glTranslatef(-0.45, -0.95, 0);
        {


            GLfloat x = 0.85;
            GLfloat y = 0.8;
            GLfloat radius = .18f;
            int triangleAmount = 20; //# of triangles used to draw circle# of triangles used to draw circle# of triangles used to draw circle

            //GLfloat radius = 0.8f; //radius
            GLfloat twicePi = 1.0f * PI;

            glBegin(GL_TRIANGLE_FAN);
            glColor3ub(198, 198, 200);
            glVertex2f(x, y); // center of circle
            for (int i = 0; i <= triangleAmount; i++)
            {
                glVertex2f(
                    x + (radius * cos(i * twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount))
                );
            }
            glEnd();


        }

        glPopMatrix();


        //curve 3
        glPushMatrix();

        glScalef(0.55, 1, 1);
        glTranslatef(0.25, -0.95, 0);
        {


            GLfloat x = 0.85;
            GLfloat y = 0.8;
            GLfloat radius = .21f;
            int triangleAmount = 20; //# of triangles used to draw circle# of triangles used to draw circle# of triangles used to draw circle

            //GLfloat radius = 0.8f; //radius
            GLfloat twicePi = 1.0f * PI;

            glBegin(GL_TRIANGLE_FAN);
            glColor3ub(232, 232, 232);
            glVertex2f(x, y); // center of circle
            for (int i = 0; i <= triangleAmount; i++)
            {
                glVertex2f(
                    x + (radius * cos(i * twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount))
                );
            }
            glEnd();


        }

        glPopMatrix();



        glPushMatrix();

        glScalef(0.55, 1, 1);
        glTranslatef(0.25, -0.95, 0);
        {


            GLfloat x = 0.85;
            GLfloat y = 0.8;
            GLfloat radius = .18f;
            int triangleAmount = 20; //# of triangles used to draw circle# of triangles used to draw circle# of triangles used to draw circle

            //GLfloat radius = 0.8f; //radius
            GLfloat twicePi = 1.0f * PI;

            glBegin(GL_TRIANGLE_FAN);
            glColor3ub(198, 198, 200);
            glVertex2f(x, y); // center of circle
            for (int i = 0; i <= triangleAmount; i++)
            {
                glVertex2f(
                    x + (radius * cos(i * twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount))
                );
            }
            glEnd();


        }

        glPopMatrix();







        //curve 2
        glPushMatrix();

        glScalef(0.55, 1, 1);
        glTranslatef(-0.1, -0.95, 0);
        {


            GLfloat x = 0.85;
            GLfloat y = 0.8;
            GLfloat radius = .215f;
            int triangleAmount = 20; //# of triangles used to draw circle# of triangles used to draw circle# of triangles used to draw circle

            //GLfloat radius = 0.8f; //radius
            GLfloat twicePi = 1.0f * PI;

            glBegin(GL_TRIANGLE_FAN);
            glColor3ub(232, 232, 232);
            glVertex2f(x, y); // center of circle
            for (int i = 0; i <= triangleAmount; i++)
            {
                glVertex2f(
                    x + (radius * cos(i * twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount))
                );
            }
            glEnd();


        }

        glPopMatrix();



        glPushMatrix();

        glScalef(0.55, 1, 1);
        glTranslatef(-0.1, -0.95, 0);
        {


            GLfloat x = 0.85;
            GLfloat y = 0.8;
            GLfloat radius = .18f;
            int triangleAmount = 20; //# of triangles used to draw circle# of triangles used to draw circle# of triangles used to draw circle

            //GLfloat radius = 0.8f; //radius
            GLfloat twicePi = 1.0f * PI;

            glBegin(GL_TRIANGLE_FAN);
            glColor3ub(198, 198, 200);
            glVertex2f(x, y); // center of circle
            for (int i = 0; i <= triangleAmount; i++)
            {
                glVertex2f(
                    x + (radius * cos(i * twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount))
                );
            }
            glEnd();


        }

        glPopMatrix();





    }

    glPopMatrix();


    //train station end//train station end//train station end//train station end//train station end






    //camp 1//camp 1//camp 1//camp 1//camp 1//camp 1//camp 1//camp 1//camp 1//camp 1//camp 1
    glPushMatrix();

    glScalef(0.25, 0.45, 1);
    glTranslatef(-2.8, -0.5, 0);
    {

        glBegin(GL_POLYGON);
        glColor3ub(96, 71, 65);
        glVertex2f(-0.63, -0.1);
        glVertex2f(-0.78, -0.0);
        glVertex2f(-0.92, -0.1);
        glVertex2f(-0.92, -0.3);
        glVertex2f(-0.63, -0.3);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(77, 60, 61);
        glVertex2f(-0.65, -0.1);
        glVertex2f(-0.78, -0.02);
        glVertex2f(-0.90, -0.1);
        glVertex2f(-0.90, -0.3);
        glVertex2f(-0.65, -0.3);
        glEnd();



        glBegin(GL_QUADS);
        glColor3ub(77, 60, 61);
        glVertex2f(-0.59, -0.08);
        glVertex2f(-0.78, 0.05);
        glVertex2f(-0.78, 0);
        glVertex2f(-0.59, -0.13);
        glEnd();


        glBegin(GL_QUADS);
        glColor3ub(77, 60, 61);
        glVertex2f(-0.78, 0.05);
        glVertex2f(-0.96, -0.08);
        glVertex2f(-0.96, -0.13);
        glVertex2f(-0.78, 0);

        glEnd();


        glBegin(GL_QUADS);
        glColor3ub(10, 10, 0);
        glVertex2f(-0.72, -0.15);
        glVertex2f(-0.83, -0.15);
        glVertex2f(-0.83, -0.3);
        glVertex2f(-0.72, -0.3);
        glEnd();

    }

    glPopMatrix();




    //tree 1 for scene 2  //tree 1 for scene 2//tree 1 for scene 2
    glPushMatrix();

    glScalef(-0.4, 0.65, 1);
    glTranslatef(3.0, -0.2, 0);
    {


        glBegin(GL_QUADS);
        glColor3ub(118, 92, 72);
        glVertex2f(-0.62, -0.3);
        glVertex2f(-0.62, 0.1);
        glVertex2f(-0.65, 0.1);
        glVertex2f(-0.65, -0.3);
        glEnd();


        glBegin(GL_TRIANGLES);
        glColor3ub(66, 105, 41);
        glVertex2f(-0.57, -0.1);
        glVertex2f(-0.635, 0.15);
        glVertex2f(-0.7, -0.1);
        glEnd();

        glBegin(GL_TRIANGLES);
        glColor3ub(66, 105, 41);
        glVertex2f(-0.57, -0.03);
        glVertex2f(-0.635, 0.12);
        glVertex2f(-0.7, -0.03);
        glEnd();


        glBegin(GL_TRIANGLES);
        glColor3ub(66, 105, 41);
        glVertex2f(-0.58, 0.04);
        glVertex2f(-0.635, 0.19);
        glVertex2f(-0.69, 0.04);
        glEnd();

    }

    glPopMatrix();

    //tree 2 for scene 2 //tree 1 for scene 2//tree 1 for scene 2
    glPushMatrix();

    glScalef(-0.4, 0.65, 1);
    glTranslatef(2.75, -0.2, 0);
    {


        glBegin(GL_QUADS);
        glColor3ub(118, 92, 72);
        glVertex2f(-0.62, -0.3);
        glVertex2f(-0.62, 0.1);
        glVertex2f(-0.65, 0.1);
        glVertex2f(-0.65, -0.3);
        glEnd();


        glBegin(GL_TRIANGLES);
        glColor3ub(66, 105, 41);
        glVertex2f(-0.57, -0.1);
        glVertex2f(-0.635, 0.15);
        glVertex2f(-0.7, -0.1);
        glEnd();

        glBegin(GL_TRIANGLES);
        glColor3ub(66, 105, 41);
        glVertex2f(-0.57, -0.03);
        glVertex2f(-0.635, 0.12);
        glVertex2f(-0.7, -0.03);
        glEnd();


        glBegin(GL_TRIANGLES);
        glColor3ub(66, 105, 41);
        glVertex2f(-0.58, 0.04);
        glVertex2f(-0.635, 0.19);
        glVertex2f(-0.69, 0.04);
        glEnd();

    }

    glPopMatrix();








    //rail line//rail line//rail line//rail line//rail line//rail line
    glBegin(GL_QUADS);
    glColor3ub(64, 54, 44);
    glVertex2f(1, -0.60);
    glVertex2f(-1, -0.60);
    glVertex2f(-1, -0.62);
    glVertex2f(1, -0.62);
    glEnd();

    //rail sand///rail sand///rail sand///rail sand/
    glBegin(GL_QUADS);
    glColor3ub(194, 165, 135);
    glVertex2f(1, -0.62);
    glVertex2f(-1, -0.62);
    glVertex2f(-1, -0.72);
    glVertex2f(1, -0.72);
    glEnd();



    //rail line wood//rail line wood//rail line wood//rail line wood//rail line wood
    float a1, a2, increment;
    a1 = -0.85;
    a2 = -0.9;
    increment = 0;

    for (int i = 0; i < 15; i++)
    {

        glBegin(GL_QUADS);
        glColor3ub(90, 92, 72);
        glVertex2f(a1 + increment, -0.62);
        glVertex2f(a2 + increment, -0.62);
        glVertex2f(a2 + increment, -0.633);
        glVertex2f(a1 + increment, -0.633);
        glEnd();
        increment = increment + 0.15;


    }




    //road only //road only //road only //road only //road only
    glBegin(GL_QUADS);
    glColor3ub(58, 58, 62);
    glVertex2f(1, -0.67);
    glVertex2f(-1, -0.67);
    glVertex2f(-1, -1);
    glVertex2f(1, -1);
    glEnd();

    //road white line//road white line//road white line
    float c1, c2, increment2;
    c1 = -0.93;
    c2 = -0.97;
    increment2 = 0;

    for (int i = 0; i < 20; i++)
    {

        glBegin(GL_QUADS);
        glColor3ub(255, 255, 255);
        glVertex2f(c1 + increment2, -0.780);
        glVertex2f(c2 + increment2, -0.780);
        glVertex2f(c2 + increment2, -0.794);
        glVertex2f(c1 + increment2, -0.794);
        glEnd();
        increment2 = increment2 + 0.1;

    }





    //road sand //road sand//road sand //road sand//road sand //road sand
    glBegin(GL_QUADS);
    glColor3ub(194, 165, 135);
    glVertex2f(1, -0.92);
    glVertex2f(-1, -0.92);
    glVertex2f(-1, -1);
    glVertex2f(1, -1);
    glEnd();











    // house01......................................................................................................

    glPushMatrix();
    glTranslatef(0.7f, -0.73f, 0.0f);
    glScalef(1, 1, 1); {


        glBegin(GL_QUADS);
        glColor3f(0.6f, 0.6f, 0.6f);

        glVertex2f(-0.86f, 0.48f);
        glVertex2f(-0.88f, 0.48f);
        glVertex2f(-0.88f, 0.3f);
        glVertex2f(-0.86f, 0.3f);

        glColor3f(0.2f, 0.0f, 0.0f);

        glVertex2f(-0.855f, 0.48f);
        glVertex2f(-0.885f, 0.48f);
        glVertex2f(-0.885f, 0.495f);
        glVertex2f(-0.855f, 0.495f);


        glEnd();

        glBegin(GL_POLYGON);

        glColor3f(0.6f, 0.6f, 0.6f);
        glVertex2f(-0.9f, 0.2f);
        glVertex2f(-0.9f, 0.4f);
        glVertex2f(-0.8f, 0.5f);
        glVertex2f(-0.7f, 0.4f);
        glVertex2f(-0.7f, 0.2f);


        glEnd();

        glBegin(GL_QUADS);

        glColor3f(0.2f, 0.0f, 0.0f);

        glVertex2f(-0.69f, 0.39f);
        glVertex2f(-0.8f, 0.5f);
        glVertex2f(-0.8f, 0.52f);
        glVertex2f(-0.68f, 0.4f);

        glVertex2f(-0.91f, 0.39f);
        glVertex2f(-0.8f, 0.5f);
        glVertex2f(-0.8f, 0.52f);
        glVertex2f(-0.92f, 0.4f);
        glEnd();

        //windos...................................................................................................
        glBegin(GL_QUADS);
        glColor3f(1.0f, 1.0f, 1.0f);

        glVertex2f(-0.808f, 0.43f);
        glVertex2f(-0.792f, 0.43f);
        glVertex2f(-0.792f, 0.46f);
        glVertex2f(-0.808f, 0.46f);

        glColor3f(0.6f, 0.8f, 1.0f);

        glVertex2f(-0.805f, 0.435f);
        glVertex2f(-0.795f, 0.435f);
        glVertex2f(-0.795f, 0.455f);
        glVertex2f(-0.805f, 0.455f);

        glEnd();

        glBegin(GL_QUADS);

        glColor3f(1.0f, 1.0f, 1.0f);

        glVertex2f(-0.78f, 0.32f);
        glVertex2f(-0.82f, 0.32f);
        glVertex2f(-0.82f, 0.38f);
        glVertex2f(-0.78f, 0.38f);

        glColor3f(0.2f, 0.0f, 0.0f);

        glVertex2f(-0.775f, 0.39f);
        glVertex2f(-0.825f, 0.39f);
        glVertex2f(-0.825f, 0.38f);
        glVertex2f(-0.775f, 0.38f);




        glVertex2f(-0.785f, 0.325f);
        glVertex2f(-0.795f, 0.325f);
        glVertex2f(-0.795f, 0.345f);
        glVertex2f(-0.785f, 0.345f);

        glVertex2f(-0.785f, 0.35f);
        glVertex2f(-0.795f, 0.35f);
        glVertex2f(-0.795f, 0.37f);
        glVertex2f(-0.785f, 0.37f);

        glVertex2f(-0.815f, 0.325f);
        glVertex2f(-0.805f, 0.325f);
        glVertex2f(-0.805f, 0.345f);
        glVertex2f(-0.815f, 0.345f);

        glVertex2f(-0.815f, 0.35f);
        glVertex2f(-0.805f, 0.35f);
        glVertex2f(-0.805f, 0.37f);
        glVertex2f(-0.815f, 0.37f);


        glEnd();
        glLineWidth(1);
        glBegin(GL_LINES);
        glVertex2f(-0.80f, 0.32f);
        glVertex2f(-0.80f, 0.38f);
        glEnd();


        //copy windos.............................................................

        glPushMatrix();
        glTranslatef(-0.06f, 0.0f, 0.0f);

        glBegin(GL_QUADS);

        glColor3f(1.0f, 1.0f, 1.0f);

        glVertex2f(-0.78f, 0.32f);
        glVertex2f(-0.82f, 0.32f);
        glVertex2f(-0.82f, 0.38f);
        glVertex2f(-0.78f, 0.38f);

        glColor3f(0.2f, 0.0f, 0.0f);

        glVertex2f(-0.775f, 0.39f);
        glVertex2f(-0.825f, 0.39f);
        glVertex2f(-0.825f, 0.38f);
        glVertex2f(-0.775f, 0.38f);


        glColor3f(0.6f, 0.8f, 1.0f);

        glVertex2f(-0.785f, 0.325f);
        glVertex2f(-0.795f, 0.325f);
        glVertex2f(-0.795f, 0.345f);
        glVertex2f(-0.785f, 0.345f);

        glVertex2f(-0.785f, 0.35f);
        glVertex2f(-0.795f, 0.35f);
        glVertex2f(-0.795f, 0.37f);
        glVertex2f(-0.785f, 0.37f);

        glVertex2f(-0.815f, 0.325f);
        glVertex2f(-0.805f, 0.325f);
        glVertex2f(-0.805f, 0.345f);
        glVertex2f(-0.815f, 0.345f);

        glVertex2f(-0.815f, 0.35f);
        glVertex2f(-0.805f, 0.35f);
        glVertex2f(-0.805f, 0.37f);
        glVertex2f(-0.815f, 0.37f);


        glEnd();
        glLineWidth(1);
        glBegin(GL_LINES);
        glVertex2f(-0.80f, 0.32f);
        glVertex2f(-0.80f, 0.38f);
        glEnd();

        glPopMatrix();

        glPushMatrix();
        glTranslatef(0.06f, 0.0f, 0.0f);

        glBegin(GL_QUADS);

        glColor3f(1.0f, 1.0f, 1.0f);

        glVertex2f(-0.78f, 0.32f);
        glVertex2f(-0.82f, 0.32f);
        glVertex2f(-0.82f, 0.38f);
        glVertex2f(-0.78f, 0.38f);

        glColor3f(0.2f, 0.0f, 0.0f);

        glVertex2f(-0.775f, 0.39f);
        glVertex2f(-0.825f, 0.39f);
        glVertex2f(-0.825f, 0.38f);
        glVertex2f(-0.775f, 0.38f);




        glVertex2f(-0.785f, 0.325f);
        glVertex2f(-0.795f, 0.325f);
        glVertex2f(-0.795f, 0.345f);
        glVertex2f(-0.785f, 0.345f);

        glVertex2f(-0.785f, 0.35f);
        glVertex2f(-0.795f, 0.35f);
        glVertex2f(-0.795f, 0.37f);
        glVertex2f(-0.785f, 0.37f);

        glVertex2f(-0.815f, 0.325f);
        glVertex2f(-0.805f, 0.325f);
        glVertex2f(-0.805f, 0.345f);
        glVertex2f(-0.815f, 0.345f);

        glVertex2f(-0.815f, 0.35f);
        glVertex2f(-0.805f, 0.35f);
        glVertex2f(-0.805f, 0.37f);
        glVertex2f(-0.815f, 0.37f);


        glEnd();
        glLineWidth(1);
        glBegin(GL_LINES);
        glVertex2f(-0.80f, 0.32f);
        glVertex2f(-0.80f, 0.38f);
        glEnd();

        glPopMatrix();

        glPushMatrix();
        glTranslatef(0.0f, -0.1f, 0.0f);

        glBegin(GL_QUADS);

        glColor3f(1.0f, 1.0f, 1.0f);

        glVertex2f(-0.78f, 0.32f);
        glVertex2f(-0.82f, 0.32f);
        glVertex2f(-0.82f, 0.38f);
        glVertex2f(-0.78f, 0.38f);

        glColor3f(0.2f, 0.0f, 0.0f);

        glVertex2f(-0.775f, 0.39f);
        glVertex2f(-0.825f, 0.39f);
        glVertex2f(-0.825f, 0.38f);
        glVertex2f(-0.775f, 0.38f);


        glColor3f(0.6f, 0.8f, 1.0f);

        glVertex2f(-0.785f, 0.325f);
        glVertex2f(-0.795f, 0.325f);
        glVertex2f(-0.795f, 0.345f);
        glVertex2f(-0.785f, 0.345f);

        glVertex2f(-0.785f, 0.35f);
        glVertex2f(-0.795f, 0.35f);
        glVertex2f(-0.795f, 0.37f);
        glVertex2f(-0.785f, 0.37f);

        glVertex2f(-0.815f, 0.325f);
        glVertex2f(-0.805f, 0.325f);
        glVertex2f(-0.805f, 0.345f);
        glVertex2f(-0.815f, 0.345f);

        glVertex2f(-0.815f, 0.35f);
        glVertex2f(-0.805f, 0.35f);
        glVertex2f(-0.805f, 0.37f);
        glVertex2f(-0.815f, 0.37f);


        glEnd();
        glLineWidth(1);
        glBegin(GL_LINES);
        glVertex2f(-0.80f, 0.32f);
        glVertex2f(-0.80f, 0.38f);
        glEnd();

        glPopMatrix();


        glPushMatrix();
        glTranslatef(-0.06f, -0.1f, 0.0f);

        glBegin(GL_QUADS);

        glColor3f(1.0f, 1.0f, 1.0f);

        glVertex2f(-0.78f, 0.32f);
        glVertex2f(-0.82f, 0.32f);
        glVertex2f(-0.82f, 0.38f);
        glVertex2f(-0.78f, 0.38f);

        glColor3f(0.2f, 0.0f, 0.0f);

        glVertex2f(-0.775f, 0.39f);
        glVertex2f(-0.825f, 0.39f);
        glVertex2f(-0.825f, 0.38f);
        glVertex2f(-0.775f, 0.38f);




        glVertex2f(-0.785f, 0.325f);
        glVertex2f(-0.795f, 0.325f);
        glVertex2f(-0.795f, 0.345f);
        glVertex2f(-0.785f, 0.345f);

        glVertex2f(-0.785f, 0.35f);
        glVertex2f(-0.795f, 0.35f);
        glVertex2f(-0.795f, 0.37f);
        glVertex2f(-0.785f, 0.37f);

        glVertex2f(-0.815f, 0.325f);
        glVertex2f(-0.805f, 0.325f);
        glVertex2f(-0.805f, 0.345f);
        glVertex2f(-0.815f, 0.345f);

        glVertex2f(-0.815f, 0.35f);
        glVertex2f(-0.805f, 0.35f);
        glVertex2f(-0.805f, 0.37f);
        glVertex2f(-0.815f, 0.37f);


        glEnd();
        glLineWidth(1);
        glBegin(GL_LINES);
        glVertex2f(-0.80f, 0.32f);
        glVertex2f(-0.80f, 0.38f);
        glEnd();

        glPopMatrix();


        //door

        glBegin(GL_QUADS);

        glColor3f(1.0f, 1.0f, 1.0f);

        glVertex2f(-0.76f, 0.2f);
        glVertex2f(-0.72f, 0.2f);
        glVertex2f(-0.72f, 0.28f);
        glVertex2f(-0.76f, 0.28f);


        glColor3f(0.6f, 0.8f, 1.0f);

        glVertex2f(-0.755f, 0.21f);
        glVertex2f(-0.742f, 0.21f);
        glVertex2f(-0.742f, 0.27f);
        glVertex2f(-0.755f, 0.27f);

        glVertex2f(-0.738f, 0.21f);
        glVertex2f(-0.725f, 0.21f);
        glVertex2f(-0.725f, 0.27f);
        glVertex2f(-0.738f, 0.27f);


        glEnd();

        glBegin(GL_QUADS);


        glColor3f(0.8f, 0.8f, 0.8f);

        glVertex2f(-0.76f, 0.2f);
        glVertex2f(-0.72f, 0.2f);
        glVertex2f(-0.72f, 0.19f);
        glVertex2f(-0.76f, 0.19f);

        glVertex2f(-0.755f, 0.17f);
        glVertex2f(-0.725f, 0.17f);
        glVertex2f(-0.725f, 0.19f);
        glVertex2f(-0.755f, 0.19f);
        glEnd();
    }

    glPopMatrix();






    //train 2 start //train 2 start//train 2 start//train 2 start//train 2 start

    glPushMatrix();
    glScalef(0.75, 0.75, 1);
    glTranslatef(position, -0.20, 0);
    {



        //
        //
                //wheel1//wheel1//wheel1//wheel1//wheel1//wheel1//wheel1//wheel1
        glPushMatrix();

        glScalef(0.55, 1, 1);
        glTranslatef(-0.87, 0.225, 0);
        {


            GLfloat x = -0.85;
            GLfloat y = -0.8;
            GLfloat radius = .03f;
            int triangleAmount = 40; //# of triangles used to draw circle# of triangles used to draw circle# of triangles used to draw circle

            //GLfloat radius = 0.8f; //radius
            GLfloat twicePi = 2.0f * PI;

            glBegin(GL_TRIANGLE_FAN);
            glColor3ub(0, 0, 0);
            glVertex2f(x, y); // center of circle
            for (int i = 0; i <= triangleAmount; i++)
            {
                glVertex2f(
                    x + (radius * cos(i * twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount))
                );
            }
            glEnd();


        }

        glPopMatrix();


        //wheel2//wheel2//wheel2//wheel2//wheel2//wheel2//wheel2
        glPushMatrix();

        glScalef(0.55, 1, 1);
        glTranslatef(-0.69, 0.225, 0);
        {


            GLfloat x = -0.85;
            GLfloat y = -0.8;
            GLfloat radius = .03f;
            int triangleAmount = 40; //# of triangles used to draw circle# of triangles used to draw circle# of triangles used to draw circle

            //GLfloat radius = 0.8f; //radius
            GLfloat twicePi = 2.0f * PI;

            glBegin(GL_TRIANGLE_FAN);
            glColor3ub(0, 0, 0);
            glVertex2f(x, y); // center of circle
            for (int i = 0; i <= triangleAmount; i++)
            {
                glVertex2f(
                    x + (radius * cos(i * twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount))
                );
            }
            glEnd();


        }

        glPopMatrix();


        //wheel3//wheel3//wheel3//wheel3//wheel3//wheel3//wheel3//wheel3
        glPushMatrix();

        glScalef(0.54, 1, 1);
        glTranslatef(-0.55, 0.225, 0);
        {


            GLfloat x = -0.85;
            GLfloat y = -0.8;
            GLfloat radius = .03f;
            int triangleAmount = 40; //# of triangles used to draw circle# of triangles used to draw circle# of triangles used to draw circle

            //GLfloat radius = 0.8f; //radius
            GLfloat twicePi = 4.0f * PI;

            glBegin(GL_TRIANGLE_FAN);
            glColor3ub(0, 0, 0);
            glVertex2f(x, y); // center of circle
            for (int i = 0; i <= triangleAmount; i++)
            {
                glVertex2f(
                    x + (radius * cos(i * twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount))
                );
            }
            glEnd();


        }

        glPopMatrix();




        //wheel4//wheel4//wheel4//wheel4//wheel4//wheel4//wheel4
        glPushMatrix();

        glScalef(0.55, 1, 1);
        glTranslatef(-0.35, 0.225, 0);
        {


            GLfloat x = -0.85;
            GLfloat y = -0.8;
            GLfloat radius = .03f;
            int triangleAmount = 40; //# of triangles used to draw circle# of triangles used to draw circle# of triangles used to draw circle

            //GLfloat radius = 0.8f; //radius
            GLfloat twicePi = 2.0f * PI;

            glBegin(GL_TRIANGLE_FAN);
            glColor3ub(0, 0, 0);
            glVertex2f(x, y); // center of circle
            for (int i = 0; i <= triangleAmount; i++)
            {
                glVertex2f(
                    x + (radius * cos(i * twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount))
                );
            }
            glEnd();


        }

        glPopMatrix();



        //wheel5//wheel5//wheel5//wheel5//wheel5//wheel5//wheel5//wheel5//wheel5
        glPushMatrix();

        glScalef(0.54, 1, 1);
        glTranslatef(-0.20, 0.225, 0);
        {


            GLfloat x = -0.85;
            GLfloat y = -0.8;
            GLfloat radius = .03f;
            int triangleAmount = 40; //# of triangles used to draw circle# of triangles used to draw circle# of triangles used to draw circle

            //GLfloat radius = 0.8f; //radius
            GLfloat twicePi = 4.0f * PI;

            glBegin(GL_TRIANGLE_FAN);
            glColor3ub(0, 0, 0);
            glVertex2f(x, y); // center of circle
            for (int i = 0; i <= triangleAmount; i++)
            {
                glVertex2f(
                    x + (radius * cos(i * twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount))
                );
            }
            glEnd();


        }

        glPopMatrix();




        //wheel6//wheel6//wheel6//wheel6//wheel6//wheel6//wheel6//wheel6//wheel6//wheel6
        glPushMatrix();

        glScalef(0.55, 1, 1);
        glTranslatef(0.01, 0.225, 0);
        {


            GLfloat x = -0.85;
            GLfloat y = -0.8;
            GLfloat radius = .03f;
            int triangleAmount = 40; //# of triangles used to draw circle# of triangles used to draw circle# of triangles used to draw circle

            //GLfloat radius = 0.8f; //radius
            GLfloat twicePi = 2.0f * PI;

            glBegin(GL_TRIANGLE_FAN);
            glColor3ub(0, 0, 0);
            glVertex2f(x, y); // center of circle
            for (int i = 0; i <= triangleAmount; i++)
            {
                glVertex2f(
                    x + (radius * cos(i * twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount))
                );
            }
            glEnd();


        }

        glPopMatrix();



        //wheel7//wheel7//wheel7//wheel7//wheel7//wheel7//wheel7
        glPushMatrix();

        glScalef(0.54, 1, 1);
        glTranslatef(0.17, 0.225, 0);
        {


            GLfloat x = -0.85;
            GLfloat y = -0.8;
            GLfloat radius = .03f;
            int triangleAmount = 40; //# of triangles used to draw circle# of triangles used to draw circle# of triangles used to draw circle

            //GLfloat radius = 0.8f; //radius
            GLfloat twicePi = 4.0f * PI;

            glBegin(GL_TRIANGLE_FAN);
            glColor3ub(0, 0, 0);
            glVertex2f(x, y); // center of circle
            for (int i = 0; i <= triangleAmount; i++)
            {
                glVertex2f(
                    x + (radius * cos(i * twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount))
                );
            }
            glEnd();


        }

        glPopMatrix();




        //wheel8//wheel8//wheel8//wheel8//wheel8//wheel8//wheel8
        glPushMatrix();

        glScalef(0.55, 1, 1);
        glTranslatef(0.39, 0.225, 0);
        {


            GLfloat x = -0.85;
            GLfloat y = -0.8;
            GLfloat radius = .03f;
            int triangleAmount = 40; //# of triangles used to draw circle# of triangles used to draw circle# of triangles used to draw circle

            //GLfloat radius = 0.8f; //radius
            GLfloat twicePi = 2.0f * PI;

            glBegin(GL_TRIANGLE_FAN);
            glColor3ub(0, 0, 0);
            glVertex2f(x, y); // center of circle
            for (int i = 0; i <= triangleAmount; i++)
            {
                glVertex2f(
                    x + (radius * cos(i * twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount))
                );
            }
            glEnd();


        }

        glPopMatrix();

        //body1//body1//body1//body1//body1//body1//body1//body1
        glBegin(GL_QUADS);
        glColor3ub(0, 54, 54);
        glVertex2f(-0.81, -0.386);
        glVertex2f(-0.98, -0.386);
        glVertex2f(-0.98, -0.575);
        glVertex2f(-0.81, -0.575);
        glEnd();


        //lowerpart1//lowerpart1//lowerpart1//lowerpart1
        glBegin(GL_QUADS);
        glColor3ub(0, 0, 0);
        glVertex2f(-0.81, -0.555);
        glVertex2f(-0.98, -0.555);
        glVertex2f(-0.98, -0.575);
        glVertex2f(-0.81, -0.575);
        glEnd();


        //join1//join1//join1//join1//join1//join1//join1
        glBegin(GL_QUADS);
        glColor3ub(0, 0, 0);
        glVertex2f(-0.79, -0.565);
        glVertex2f(-0.81, -0.565);
        glVertex2f(-0.81, -0.575);
        glVertex2f(-0.79, -0.575);
        glEnd();


        //body2//body2//body2//body2//body2//body2//body2//body2
        glBegin(GL_QUADS);
        glColor3ub(0, 54, 54);
        glVertex2f(-0.62, -0.386);
        glVertex2f(-0.79, -0.386);
        glVertex2f(-0.79, -0.575);
        glVertex2f(-0.62, -0.575);
        glEnd();


        //lowerpart2//lowerpart2//lowerpart2//lowerpart2
        glBegin(GL_QUADS);
        glColor3ub(0, 0, 0);
        glVertex2f(-0.62, -0.555);
        glVertex2f(-0.79, -0.555);
        glVertex2f(-0.79, -0.575);
        glVertex2f(-0.62, -0.575);
        glEnd();


        //join2//join2//join2//join2//join2//join2//join2//join2
        glBegin(GL_QUADS);
        glColor3ub(0, 0, 0);
        glVertex2f(-0.6, -0.565);
        glVertex2f(-0.62, -0.565);
        glVertex2f(-0.62, -0.575);
        glVertex2f(-0.6, -0.575);
        glEnd();


        //body3//body3//body3//body3//body3//body3//body3
        glBegin(GL_QUADS);
        glColor3ub(0, 54, 54);
        glVertex2f(-0.43, -0.386);
        glVertex2f(-0.60, -0.386);
        glVertex2f(-0.60, -0.575);
        glVertex2f(-0.43, -0.575);
        glEnd();

        //lowerpart3//lowerpart3//lowerpart3//lowerpart3
        glBegin(GL_QUADS);
        glColor3ub(0, 0, 0);
        glVertex2f(-0.43, -0.555);
        glVertex2f(-0.60, -0.555);
        glVertex2f(-0.60, -0.575);
        glVertex2f(-0.43, -0.575);
        glEnd();

        //join3//join3//join3//join3//join3//join3//join3//join3
        glBegin(GL_QUADS);
        glColor3ub(0, 0, 0);
        glVertex2f(-0.41, -0.565);
        glVertex2f(-0.43, -0.565);
        glVertex2f(-0.43, -0.575);
        glVertex2f(-0.41, -0.575);
        glEnd();


        //body4//body4//body4//body4//body4//body4
        glBegin(GL_QUADS);
        glColor3ub(0, 54, 54);
        glVertex2f(-0.26, -0.386);
        glVertex2f(-0.41, -0.386);
        glVertex2f(-0.41, -0.575);
        glVertex2f(-0.26, -0.575);
        glEnd();


        //body triangle//body triangle//body triangle//body triangle
        glBegin(GL_TRIANGLES);
        glColor3ub(0, 54, 54);
        glVertex2f(-0.185, -0.555);
        glVertex2f(-0.26, -0.386);
        glVertex2f(-0.26, -0.555);
        glEnd();

        //body smoke//body smoke//body smoke//body smoke
        glBegin(GL_QUADS);
        glColor3ub(25, 68, 74);
        glVertex2f(-0.28, -0.33);
        glVertex2f(-0.33, -0.33);
        glVertex2f(-0.33, -0.386);
        glVertex2f(-0.28, -0.386);
        glEnd();


        //lowerpart4//lowerpart4//lowerpart4//lowerpart4//lowerpart4
        glBegin(GL_QUADS);
        glColor3ub(0, 0, 0);
        glVertex2f(-0.185, -0.555);
        glVertex2f(-0.41, -0.555);
        glVertex2f(-0.41, -0.575);
        glVertex2f(-0.185, -0.575);
        glEnd();



        //windows 1 and door 1//windows 1 and door 1//windows 1 and door 1//windows 1 and door 1

        glBegin(GL_QUADS);
        glColor3ub(107, 153, 166);
        glVertex2f(-0.93, -0.44);
        glVertex2f(-0.95, -0.44);
        glVertex2f(-0.95, -0.48);
        glVertex2f(-0.93, -0.48);
        glEnd();

        glBegin(GL_QUADS);
        glColor3ub(107, 153, 166);
        glVertex2f(-0.88, -0.44);
        glVertex2f(-0.9, -0.44);
        glVertex2f(-0.9, -0.48);
        glVertex2f(-0.88, -0.48);
        glEnd();


        glBegin(GL_QUADS);
        glColor3ub(86, 112, 120);
        glVertex2f(-0.825, -0.42);
        glVertex2f(-0.85, -0.42);
        glVertex2f(-0.85, -0.54);
        glVertex2f(-0.825, -0.54);
        glEnd();



        //windows 2 and door 2//windows 2 and door 2//windows 2 and door 2//windows 2 and door 2

        glBegin(GL_QUADS);
        glColor3ub(107, 153, 166);
        glVertex2f(-0.73, -0.44);
        glVertex2f(-0.75, -0.44);
        glVertex2f(-0.75, -0.48);
        glVertex2f(-0.73, -0.48);
        glEnd();

        glBegin(GL_QUADS);
        glColor3ub(107, 153, 166);
        glVertex2f(-0.68, -0.44);
        glVertex2f(-0.7, -0.44);
        glVertex2f(-0.7, -0.48);
        glVertex2f(-0.68, -0.48);
        glEnd();


        glBegin(GL_QUADS);
        glColor3ub(86, 112, 120);
        glVertex2f(-0.635, -0.42);
        glVertex2f(-0.66, -0.42);
        glVertex2f(-0.66, -0.54);
        glVertex2f(-0.635, -0.54);
        glEnd();




        //windows 3 and door 3//windows 3 and door 3//windows 3 and door 3//windows 3 and door 3

        glBegin(GL_QUADS);
        glColor3ub(107, 153, 166);
        glVertex2f(-0.55, -0.44);
        glVertex2f(-0.57, -0.44);
        glVertex2f(-0.57, -0.48);
        glVertex2f(-0.55, -0.48);
        glEnd();

        glBegin(GL_QUADS);
        glColor3ub(107, 153, 166);
        glVertex2f(-0.5, -0.44);
        glVertex2f(-0.52, -0.44);
        glVertex2f(-0.52, -0.48);
        glVertex2f(-0.5, -0.48);
        glEnd();


        glBegin(GL_QUADS);
        glColor3ub(86, 112, 120);
        glVertex2f(-0.445, -0.42);
        glVertex2f(-0.47, -0.42);
        glVertex2f(-0.47, -0.54);
        glVertex2f(-0.445, -0.54);
        glEnd();



        //windows 4 and door 4//windows 4 and door 4//windows 4 and door 4//windows 4 and door 4

        glBegin(GL_QUADS);
        glColor3ub(107, 153, 166);
        glVertex2f(-0.36, -0.44);
        glVertex2f(-0.38, -0.44);
        glVertex2f(-0.38, -0.48);
        glVertex2f(-0.36, -0.48);
        glEnd();

        glBegin(GL_QUADS);
        glColor3ub(107, 153, 166);
        glVertex2f(-0.28, -0.44);
        glVertex2f(-0.3, -0.44);
        glVertex2f(-0.3, -0.48);
        glVertex2f(-0.28, -0.48);
        glEnd();


        glBegin(GL_QUADS);
        glColor3ub(86, 112, 120);
        glVertex2f(-0.315, -0.42);
        glVertex2f(-0.34, -0.42);
        glVertex2f(-0.34, -0.54);
        glVertex2f(-0.315, -0.54);
        glEnd();
    }
    glPopMatrix();




    //// beach chair and umbrella-1

    glPushMatrix();



    glScalef(0.15, 0.2, 1);
    glTranslatef(-5, -2, 0); {


        glBegin(GL_QUADS); // chair base
        glColor3ub(110, 67, 33);
        glVertex2f(0.1f, 0.15f);
        glVertex2f(0.7f, 0.35);
        glVertex2f(0.7f, 0.15f);
        glVertex2f(0.1f, 0.35f);
        glEnd();

        glBegin(GL_QUADS); // chair up
        glColor3ub(165, 100, 42);
        glVertex2f(0.1f, 0.35f);
        glVertex2f(0.05f, 0.48f);
        glVertex2f(0.4f, 0.48f);
        glVertex2f(0.5f, 0.35f);
        glEnd();


        glBegin(GL_QUADS); // ubrella bar
        glColor3ub(135, 68, 23);
        glVertex2f(0.0f, 0.15f);
        glVertex2f(0.02f, 0.15f);
        glVertex2f(0.02f, 0.65f);
        glVertex2f(0.0f, 0.65f);
        glEnd();


        glBegin(GL_TRIANGLES); // ubrella
        glColor3ub(83, 219, 81);
        glVertex2f(-0.3f, 0.65f);
        glVertex2f(0.0f, 0.9f);
        glVertex2f(0.3f, 0.65f);
        glEnd();

        glBegin(GL_TRIANGLES);// ubrella
        glColor3ub(232, 247, 89);
        glVertex2f(-0.1f, 0.65f);
        glVertex2f(0.0f, 0.9f);
        glVertex2f(0.0f, 0.65f);
        glEnd();

        glBegin(GL_TRIANGLES);// ubrella
        glColor3ub(240, 10, 29);
        glVertex2f(-0.0f, 0.65f);
        glVertex2f(0.0f, 0.9f);
        glVertex2f(0.1f, 0.65f);
        glEnd();

    }

    glPopMatrix();


    //// beach chair and umbrella-2

    glPushMatrix();



    glScalef(0.15, 0.2, 1);
    glTranslatef(-4, -2, 0); {


        glBegin(GL_QUADS); // chair base
        glColor3ub(110, 67, 33);
        glVertex2f(0.1f, 0.15f);
        glVertex2f(0.7f, 0.35);
        glVertex2f(0.7f, 0.15f);
        glVertex2f(0.1f, 0.35f);
        glEnd();

        glBegin(GL_QUADS); // chair up
        glColor3ub(165, 100, 42);
        glVertex2f(0.1f, 0.35f);
        glVertex2f(0.05f, 0.48f);
        glVertex2f(0.4f, 0.48f);
        glVertex2f(0.5f, 0.35f);
        glEnd();


        glBegin(GL_QUADS); // ubrella bar
        glColor3ub(135, 68, 23);
        glVertex2f(0.0f, 0.15f);
        glVertex2f(0.02f, 0.15f);
        glVertex2f(0.02f, 0.65f);
        glVertex2f(0.0f, 0.65f);
        glEnd();


        glBegin(GL_TRIANGLES); // ubrella
        glColor3ub(83, 219, 81);
        glVertex2f(-0.3f, 0.65f);
        glVertex2f(0.0f, 0.9f);
        glVertex2f(0.3f, 0.65f);
        glEnd();

        glBegin(GL_TRIANGLES);// ubrella
        glColor3ub(232, 247, 89);
        glVertex2f(-0.1f, 0.65f);
        glVertex2f(0.0f, 0.9f);
        glVertex2f(0.0f, 0.65f);
        glEnd();

        glBegin(GL_TRIANGLES);// ubrella
        glColor3ub(240, 10, 29);
        glVertex2f(-0.0f, 0.65f);
        glVertex2f(0.0f, 0.9f);
        glVertex2f(0.1f, 0.65f);
        glEnd();

    }

    glPopMatrix();


















    //Sun 2 //Sun 2//Sun 2//Sun 2//Sun 2//Sun 2//Sun 2
    glPushMatrix();

    glScalef(0.55, 1, 1);
    glTranslatef(0.8, 0, 0);
    {

        //Sun //Sun//Sun//Sun//Sun//Sun//Sun
        GLfloat x = 0.85;
        GLfloat y = 0.8;
        GLfloat radius = .12f;
        int triangleAmount = 20; //# of triangles used to draw circle# of triangles used to draw circle# of triangles used to draw circle

        //GLfloat radius = 0.8f; //radius
        GLfloat twicePi = 2.0f * PI;

        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(249, 215, 28);
        glVertex2f(x, y); // center of circle
        for (int i = 0; i <= triangleAmount; i++)
        {
            glVertex2f(
                x + (radius * cos(i * twicePi / triangleAmount)),
                y + (radius * sin(i * twicePi / triangleAmount))
            );
        }
        glEnd();


    }

    glPopMatrix();





    glPushMatrix();
    glScalef(0.790, 0.90, 1);
    glTranslatef(1.3, 0.17, 0);
    {
        //cloud 2 start  //cloud 2 start //cloud 2 start //cloud 2 start
        glLineWidth(1);

        GLfloat x = -0.92f;
        GLfloat y = .725f;
        GLfloat radius = .055f;

        int lineAmount = 100; //# of triangles used to draw circle

        //GLfloat radius = 0.8f; //radius
        GLfloat twicePi = 2.0f * PI;

        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(208, 222, 236);
        for (int i = 0; i <= lineAmount; i++)
        {
            glVertex2f(
                x + (radius * cos(i * twicePi / lineAmount)),
                y + (radius * sin(i * twicePi / lineAmount))
            );
        }
        glEnd();




        glLineWidth(1);

        x = -0.765f;
        y = .725f;
        radius = .045f;

        lineAmount = 100; //# of triangles used to draw circle

        //GLfloat radius = 0.8f; //radius
        twicePi = 2.0f * PI;

        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(208, 222, 236);
        for (int i = 0; i <= lineAmount; i++)
        {
            glVertex2f(
                x + (radius * cos(i * twicePi / lineAmount)),
                y + (radius * sin(i * twicePi / lineAmount))
            );
        }
        glEnd();



        glLineWidth(1);

        x = -0.85f;
        y = .75f;
        radius = .08f;

        lineAmount = 100; //# of triangles used to draw circle

        //GLfloat radius = 0.8f; //radius
        twicePi = 2.0f * PI;

        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(208, 222, 236);
        for (int i = 0; i <= lineAmount; i++)
        {
            glVertex2f(
                x + (radius * cos(i * twicePi / lineAmount)),
                y + (radius * sin(i * twicePi / lineAmount))
            );
        }
        glEnd();

    }

    glPopMatrix();


    glPushMatrix();
    glScalef(0.8, 0.8, 1);
    glTranslatef(-0.1, 0.4, 0);
    {
        //cloud start //cloud start //cloud start //cloud start //cloud start
        glLineWidth(1);

        GLfloat x = -0.92f;
        GLfloat y = .725f;
        GLfloat radius = .055f;

        int lineAmount = 100; //# of triangles used to draw circle

        //GLfloat radius = 0.8f; //radius
        GLfloat twicePi = 2.0f * PI;

        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(208, 222, 236);
        for (int i = 0; i <= lineAmount; i++)
        {
            glVertex2f(
                x + (radius * cos(i * twicePi / lineAmount)),
                y + (radius * sin(i * twicePi / lineAmount))
            );
        }
        glEnd();




        glLineWidth(1);

        x = -0.78f;
        y = .73f;
        radius = .049f;

        lineAmount = 100; //# of triangles used to draw circle

        //GLfloat radius = 0.8f; //radius
        twicePi = 2.0f * PI;

        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(208, 222, 236);
        for (int i = 0; i <= lineAmount; i++)
        {
            glVertex2f(
                x + (radius * cos(i * twicePi / lineAmount)),
                y + (radius * sin(i * twicePi / lineAmount))
            );
        }
        glEnd();



        glLineWidth(1);

        x = -0.85f;
        y = .73f;
        radius = .06f;

        lineAmount = 100; //# of triangles used to draw circle

        //GLfloat radius = 0.8f; //radius
        twicePi = 2.0f * PI;

        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(208, 222, 236);
        for (int i = 0; i <= lineAmount; i++)
        {
            glVertex2f(
                x + (radius * cos(i * twicePi / lineAmount)),
                y + (radius * sin(i * twicePi / lineAmount))
            );
        }
        glEnd();

    }

    glPopMatrix();


    glPushMatrix();
    glScalef(0.8, 0.8, 1);
    glTranslatef(0.08, -0.15, 0);
    {

        //text//text//text//text//text//text
        glColor3ub(0, 0, 45);
        glRasterPos2f(0.3f, -0.22f);
        const char* text = "COX'S  BAZAR  RAILWAY  STATION";
        for (int i = 0; text[i] != '\0'; ++i)
        {
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);
        }

    }
    glPopMatrix();



    //windmill//windmill//windmill//windmill//windmill//windmill//windmill//windmill

    glPushMatrix();

    glScalef(0.5, 0.5, 1.0);

    glTranslatef(1, -1.29, 0.0);
    {



        glBegin(GL_QUADS);//bar
        glColor3ub(255, 255, 255);
        glVertex2f(0.765, 0.85);
        glVertex2f(0.745, 0.85);
        glVertex2f(0.745, 0.5);
        glVertex2f(0.765, 0.5);
        glEnd();


        glBegin(GL_QUADS);//bottom
        glColor3ub(88, 32, 32);
        glVertex2f(0.8, 0.5);
        glVertex2f(0.7, 0.5);
        glVertex2f(0.65, 0.25);
        glVertex2f(0.85, 0.25);
        glEnd();
    }
    glPopMatrix();



    glPushMatrix();


    glScalef(0.3, 0.5, 1.0);
    glTranslatef(2.925, -0.41, 0);


    glBegin(GL_TRIANGLES);//fan1
    glColor3ub(255, 255, 255);
    glVertex2f(0.0, 0.0);
    glVertex2f(0.05, 0.25);
    glVertex2f(-0.03, 0.06);
    glEnd();

    glBegin(GL_TRIANGLES);//fan2
    glColor3ub(255, 255, 255);
    glVertex2f(0.0, 0.0);
    glVertex2f(-0.23, -0.11);
    glVertex2f(-0.03, -0.06);
    glEnd();

    glBegin(GL_TRIANGLES);//fan3
    glColor3ub(255, 255, 255);
    glVertex2f(0.0, 0.0);
    glVertex2f(0.20, -0.13);
    glVertex2f(0.08, 0.00);
    glEnd();
    glLoadIdentity();
    glPopMatrix();//glPopMatrix pops the top matrix off the stack


    GLfloat x8 = 0.875;
    GLfloat y8 = -0.21;
    GLfloat radius8 = .01f;
    GLfloat triangleAmount8 = 50; //# of triangles used to draw circle# of triangles used to draw circle# of triangles used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi8 = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(167, 154, 154);
    glVertex2f(x8, y8); // center of circle
    for (int i = 0; i <= triangleAmount8; i++)
    {
        glVertex2f(
            x8 + (radius8 * cos(i * twicePi8 / triangleAmount8)),
            y8 + (radius8 * sin(i * twicePi8 / triangleAmount8))
        );
    }
    glEnd();


    //car-3 right to left"

    glPushMatrix();
    glTranslated(position5, -0.57f, 0.0f);
    glScalef(0.7, 0.7, 1);

    glBegin(GL_POLYGON);
    glColor3f(1.0f, .50f, .0f);
    glVertex2f(-.60, -.35);
    glVertex2f(-.65, -.35);
    glVertex2f(-.70, -0.42);
    glVertex2f(-.40, -0.42);
    glVertex2f(-.40, -.35);
    glVertex2f(-.45, -.35);
    glVertex2f(-.50, -.31);
    glEnd();
    glColor3f(1.0f, 1.f, 1.0f);
    DrawCircle(-.60, -.42, .03, 200);
    DrawCircle(-.45, -.42, .03, 200);

    glPopMatrix();





    //car-4 right to left"


    glPushMatrix();
    glTranslatef(0.5f, 0.0f, 0.0f); {
        glPushMatrix();
        glTranslated(position5, -0.57f, 0.0f);
        glScalef(0.7, 0.7, 1);

        glBegin(GL_POLYGON);
        glColor3f(0.0f, 0.50f, .0f);
        glVertex2f(-.60, -.35);
        glVertex2f(-.65, -.35);
        glVertex2f(-.70, -0.42);
        glVertex2f(-.40, -0.42);
        glVertex2f(-.40, -.35);
        glVertex2f(-.45, -.35);
        glVertex2f(-.50, -.31);
        glEnd();
        glColor3f(1.0f, 1.f, 1.0f);
        DrawCircle(-.60, -.42, .03, 200);
        DrawCircle(-.45, -.42, .03, 200);

        glPopMatrix();

    }

    glPopMatrix();



    //car-5 right to left"


    glPushMatrix();
    glTranslatef(0.8f, 0.0f, 0.0f); {
        glPushMatrix();
        glTranslated(position5, -0.57f, 0.0f);
        glScalef(0.7, 0.7, 1);

        glBegin(GL_POLYGON);
        glColor3f(192, 192, 192);
        glVertex2f(-.60, -.35);
        glVertex2f(-.65, -.35);
        glVertex2f(-.70, -0.42);
        glVertex2f(-.40, -0.42);
        glVertex2f(-.40, -.35);
        glVertex2f(-.45, -.35);
        glVertex2f(-.50, -.31);
        glEnd();
        glColor3f(1.0f, 1.f, 1.0f);
        DrawCircle(-.60, -.42, .03, 200);
        DrawCircle(-.45, -.42, .03, 200);

        glPopMatrix();

    }

    glPopMatrix();



















    glFlush();  // Render now
}

void coxbazar(int val)
{
    glutDisplayFunc(display2);
    glutPostRedisplay();

}


void kamalapur(int val) {

    glutDisplayFunc(display1);
    glutPostRedisplay();
}





void mid(int val)
{
    glutDisplayFunc(display);
    glutPostRedisplay();

}





void handleKeypress(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 's':
        speed = 0.02f;
        position8 = 20;
        PlaySound("a.wav", NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
        break;

    case 'a':
        glutDisplayFunc(display1);
        glutPostRedisplay();
        break;
    }
}




int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1400, 700);
    glutInitWindowPosition(95, 40);
    glutCreateWindow("Final Project");


    cout << "Press 's' to start the train engine";

    glutDisplayFunc(information);

    // glutTimerFunc(0, mid, 0);

    glutIdleFunc(Idle);

    glutKeyboardFunc(handleKeypress);


    glutTimerFunc(100, update, 0);
    glutTimerFunc(100, update2, 0);
    glutTimerFunc(100, update3, 0);
    glutTimerFunc(100, update4, 0);
    glutTimerFunc(100, update5, 0);
    glutTimerFunc(100, update6, 0);
    glutTimerFunc(100, update7, 0);


    glutMainLoop();
    return 0;
}
