#include <GL/glut.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#define RADIUS 0.025
#define SPEED  0.0020
int view_no = 1;
int WIDTH = 900;
int HEIGHT =  650;
int RATIO = WIDTH/HEIGHT;
int score = 0;
int redhit = 0;
bool show[5][10];
float x_brick[4][9];
float y_brick[4][9];
float P_XPOS = 0;
float P_YPOS = -0.8;
bool phit_center = false , phit_corner = false;
bool game_over = false;
bool RIGHT = 1,LEFT = 0,UP = 1,DOWN = 0;
bool started = false;
float x_pos = 0,y_pos = -0.75;
bool hit = false;
int lives  = 3;
float scorered=0;
using namespace std;

void DrawCircle(float cx, float cy, float r, int num_segments) {
    glBegin(GL_POLYGON);
    for (int ii = 0; ii < num_segments; ii++)   {
        float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);//get the current angle
        float x = r * cosf(theta);//calculate the x component
        float y = r * sinf(theta);//calculate the y component
        glVertex2f(x + cx, y + cy);//output vertex
    }
    glEnd();
}

void drawstring(float x1, float y1, char *s)
{
	char *c;
	glRasterPos2f(x1, y1);
	for (c = s; *c != '\0'; c++)
		glutBitmapCharacter(GLUT_BITMAP_8_BY_13, *c);
}
void drawstring1(float x1, float y1, char *s)
{
	char *c;
	glRasterPos2f(x1, y1);
	for (c = s; *c != '\0'; c++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
}
void drawstring2(float x1, float y1, char *s)
{
	char *c;
	glRasterPos2f(x1, y1);
	for (c = s; *c != '\0'; c++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *c);
}
void page()
{
    glClearColor(0,0,0,0);
	glColor3f(1, 0, 0);
	glLineWidth(5);
	glBegin(GL_LINE_LOOP); // second member line loop
	glVertex2d(-0.7, 0.2);
	glVertex2d(-0.1, 0.2);
	glVertex2d(-0.1, -0.2);
	glVertex2d(-0.7, -0.2);
	glEnd();


	glColor3f(1, 0, 0);
	glLineWidth(5);
	glBegin(GL_LINE_LOOP); // first member line loop
	glVertex2d(0.7, 0.2);
	glVertex2d(0.1, 0.2);
	glVertex2d(0.1, -0.2);
	glVertex2d(0.7, -0.2);
	glEnd();

	glColor3f(0.5, 0.2, 0.2);
	glLineWidth(5);
	glBegin(GL_LINE_LOOP); //faculty lineloop
	glVertex2d(167, 160);
	glVertex2d(342, 160);
	glVertex2d(342, 210);
	glVertex2d(167, 210);
	glEnd();




    glColor3f (1, 1, 1);
    drawstring1(-0.4, 0.9, "N.M.A.M INSTITUTE OF TECHNOLOGY ");
    drawstring1(-0.6, 0.8, "DEPARTMENT OF COMPUTER SCIENCE AND ENGINEERING");
	glColor3f (1.0,1.0,1.0);   //(0.5, 0, 0.9);
	drawstring1(-0.22, 0.6, "SIMPLE BALL GAME");
	//drawstring1(-0.25, 0.5, "SIMPLE BALL GAME");
    glColor3f (1, 1, 1);
	drawstring(0.2, 0.1, "NAME : MOGHE SUDHEESH RAO");
	drawstring(0.2, 0.0, "USN : 4NM18CS094  ");
	drawstring(0.2, -0.1, "SEM : VI ");

	drawstring(-0.6, 0.1, "NAME : P V CHETAN ACHARYA ");
	drawstring(-0.6, 0.0, "USN : 4NM18CS107 ");
	drawstring(-0.6, -0.1, "SEM : VI ");

	drawstring(-0.25, -0.5, " FACULTY NAME : Mr.PUNEETH RP ");
	drawstring(-0.2, -0.6, " ASSISTANT PROFESSOR ");

    glColor3f (1.0, 1.0, 1.0);
    drawstring(-0.3, -0.9, " PRESS -- I -- FOR INSTRUCTION ");
	glFlush();
}


void dispchetan()
{
    float tx=0,ty=0;
    float sx=1,sy=1;
    sx=scorered;
    sy=scorered;

    glColor3f(0.57,0.41,0.41);

    glBegin(GL_QUADS);
    glVertex2f(-0.00625*sx+tx ,0.03148148148148148*sy + ty);
glVertex2f(-0.13229166666666667*sx+tx ,-0.07592592592592592*sy + ty);
glVertex2f(-0.121875*sx+tx ,-0.14074074074074075*sy + ty);
glVertex2f(0.003125*sx+tx ,-0.053703703703703705*sy + ty);
    glVertex2f(0.00625*sx+tx ,0.03148148148148148*sy + ty);
glVertex2f(0.13229166666666667*sx+tx ,-0.07592592592592592*sy + ty);
glVertex2f(0.121875*sx+tx ,-0.14074074074074075*sy + ty);
glVertex2f(-0.003125*sx+tx ,-0.053703703703703705*sy + ty);
glVertex2f(-0.007291666666666667*sx+tx ,-0.11851851851851852*sy + ty);
glVertex2f(-0.103125*sx+tx ,-0.387037037037037*sy + ty);
glVertex2f(-0.08229166666666667*sx+tx ,-0.44074074074074077*sy + ty);
glVertex2f(0.0010416666666666667*sx+tx ,-0.1648148148148148*sy + ty);
glVertex2f(0.007291666666666667*sx+tx ,-0.11851851851851852*sy + ty);
glVertex2f(0.103125*sx+tx ,-0.387037037037037*sy + ty);
glVertex2f(0.08229166666666667*sx+tx ,-0.44074074074074077*sy + ty);
glVertex2f(-0.0010416666666666667*sx+tx ,-0.1648148148148148*sy + ty);
glColor3f(0.84,0.04,0.04);
glVertex2f(-0.010416666666666666*sx+tx ,-0.1259259259259259*sy + ty);
glVertex2f(-0.084375*sx+tx ,-0.21666666666666667*sy + ty);
glVertex2f(-0.025*sx+tx ,-0.30925925925925923*sy + ty);
glVertex2f(0.004166666666666667*sx+tx ,-0.16296296296296298*sy + ty);
glVertex2f(0.010416666666666666*sx+tx ,-0.1259259259259259*sy + ty);
glVertex2f(0.084375*sx+tx ,-0.21666666666666667*sy + ty);
glVertex2f(0.025*sx+tx ,-0.30925925925925923*sy + ty);
glVertex2f(-0.004166666666666667*sx+tx ,-0.16296296296296298*sy + ty);
glVertex2f(-0.017708333333333333*sx+tx ,0.12222222222222222*sy + ty);
glVertex2f(-0.017708333333333333*sx+tx ,-0.18333333333333332*sy + ty);
glVertex2f(0.021875*sx+tx ,-0.18703703703703703*sy + ty);
glVertex2f(0.019791666666666666*sx+tx ,0.1388888888888889*sy + ty);

    glEnd();


         glColor3f(0.57,0.41,0.41);
         ty+=0.15*sx;
DrawCircle(sx*0.0001+tx,sy*0.0001+ty,0.09*sx,20);
glColor3f(0.03,0.03,0.03);
ty-=0.1*sx;
DrawCircle(tx+(sx*-0.03229166666666667),ty+(sy*0.1425925925925926),0.015*sx,30);
DrawCircle(tx+(sx*0.01875),ty+(sy*0.14074074074074075),0.015*sx,30);
//printf("%f \n",sx);
}

void b_draw()
{

      glBegin(GL_QUADS);
      for(int a = 0; a < 9; a++)
      {
              for(int b = 0; b < 4; b++)
              {
                  if(b==0){
                  glColor3f(0.0,1.0,0.0);
                  }
                  else if(b==1){
                    glColor3f(1.0,1.0,0.0);
                  }
                  else if(b==2){
                    glColor3f(1.0,0.0,0.0);
                  }
                  else{
                    glColor3f(0.0,0.0,1.0);
                  }
                      if(show[b][a] == 1)
                      {
                                    glVertex2f(x_brick[b][a],y_brick[b][a]);
                                    glVertex2f(x_brick[b][a],y_brick[b][a] - 0.10);
                                    glVertex2f(x_brick[b][a]+0.2,y_brick[b][a] - 0.10);
                                    glVertex2f(x_brick[b][a]+0.2,y_brick[b][a]);
                      }
              }
      }
      glEnd();
}

void red_hit()
{
    for(int a = 0; a < 9; a++)
      {
            if(show[2][a] == 0)
            {
            redhit++;
                scorered+=0.2;
            }
      }
}



void c_draw()
{
     glColor3f(0.0,0.0,0.0);
     glBegin(GL_TRIANGLE_FAN);
     glVertex2f(x_pos,y_pos);
     for (float angle = 0; angle < (10); angle+=0.01)
     {
         glVertex2f((x_pos + sin(angle) * RADIUS), (y_pos + (cos(angle)) * RADIUS));
     }
     glEnd();
}
bool b_hit()
{
     hit = false;
     int flag = 1;
     for(int a = 0; a < 10; a++)
     {
             for(int b =0; b < 4; b++)
             {
                     if(x_pos >= x_brick[b][a] && x_pos <= x_brick[b][a] + 0.2)
                     {
                              if(y_pos <= y_brick[b][a] && y_pos >= y_brick[b][a] - 0.1)
                              {
                                       if(show[b][a] == 1)
                                       {
                                                     show[b][a] = 0;
                                                     flag = 0;
                                                     hit = true;
                                                     score++;
                                                    if(b==2)
                                                    {
                                                     //printf(" scored ; %f \n",scorered);
                                                        scorered+=0.2;
                                                    }
                                                     break;
                                       }
                              }
                     }
             }
             if(flag == 0)
                     break;
     }
     return hit;
}
bool crashed()
{
     if(y_pos < P_YPOS - 0.05){
              //return true;
              red_hit();
              printf("YOUR SCORE IS %d\n\n",score);
              printf("RED BRICKS HIT ARE %d\n\n",redhit);
              printf("GAME OVER!!!!\n\n");
              exit(0);
     }
     else return false;;
}
void p_hit()
{

     phit_corner = false;
     phit_center = false;
     if(x_pos <= P_XPOS + 0.13 && x_pos >= P_XPOS - 0.13)
     {
              if(y_pos <= P_YPOS)
              {

                       phit_center = true;
              }
     }
     else if((x_pos >= P_XPOS + 0.13 && x_pos <= P_XPOS + 0.2) || (x_pos <= P_XPOS - 0.13 && x_pos >= P_XPOS - 0.2))
     {
               if(y_pos <= P_YPOS)
               {
                        phit_corner = true;
               }
     }
}
 void c_move()
 {
      if(UP && RIGHT)
      {
           x_pos += (SPEED);
           y_pos += (SPEED);
      }
      if(UP && LEFT)
      {
            x_pos -= (SPEED);
            y_pos += (SPEED);
      }
      if(DOWN && RIGHT)
      {
              x_pos += (SPEED);
              y_pos -= (SPEED);
      }
      if(DOWN && LEFT)
      {
              x_pos -= (SPEED);
              y_pos -= (SPEED);
      }
      b_hit();
      if(x_pos >= (RATIO-RADIUS))
      {
               RIGHT = 0;
               LEFT = 1;
      }
      else if(x_pos <= (-RATIO+RADIUS))
      {
           RIGHT = 1;
           LEFT = 0;
      }
      if(y_pos >= (RATIO-RADIUS) || hit )
      {
                  UP = 0;
                  DOWN = 1;
      }
      else if(y_pos <= (-RATIO+RADIUS) || hit )
      {
           UP = 1;
           DOWN = 0;
      }
      p_hit();
      if(phit_center)
      {
                     DOWN = 0;
                     UP = 1;
      }
      if(phit_corner)
      {
                     if(LEFT)
                     {
                             LEFT = 0;
                             RIGHT = 1;
                     }
                     else
                     {
                         RIGHT = 0;
                         LEFT = 1;
                     }
                     UP = 1;
                     DOWN = 0;
      }
}
void p_draw()
{
     glColor3f(0.0,0.0,0.0);
     glBegin(GL_QUADS);
                      glVertex2f(P_XPOS-0.2,P_YPOS);
                      glVertex2f(P_XPOS+0.2,P_YPOS);
                      glVertex2f(P_XPOS+0.2,P_YPOS-0.05);
                      glVertex2f(P_XPOS-0.2,P_YPOS-0.05);
     glEnd();
}

void BallLoop()
{
     const int   win_width  = glutGet(GLUT_WINDOW_WIDTH);
     const int   win_height = glutGet(GLUT_WINDOW_HEIGHT);
     const float aspect = (float)win_width/(float)win_height;
     switch(view_no) {
        case 1:
            glClear(GL_COLOR_BUFFER_BIT);
            page();
            break;
        case 2:
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clean the screen and the depth buffer
            glClearColor(0,0,0,0);
            glColor3f (1, 0, 0);
            drawstring2(-0.22, 0.7, "INSTRUCTIONS");
            glColor3f (1.0, 1.0, 1.0);
            drawstring1(-0.8, 0.5, "--> Press 1 to Launch the Game");
	        drawstring1(-0.8, 0.4, "--> Press Enter to launch the ball");
	        drawstring1(-0.8, 0.3, "--> Press Left and Right arrow key to move the ball");
	        drawstring1(-0.8, 0.2, "--> Breaking the red brick will increase the size of man");
            drawstring1(-0.8, 0.1, "--> Press H for Home Page");
	        drawstring1(-0.8, 0.0,  "--> Press Q to quit");

            glColor3f (0, 0.3, 0);
	        glBegin(GL_LINE_LOOP);
            glVertex2d(95,55 );
            glVertex2d(395,55);
            glVertex2d(395, 190);
            glVertex2d(95, 190);
            glEnd();
         	glFlush();
            break;

         case 3:
              glClearColor(1.0,1.0,1.0,0);
     glDisable(GL_DEPTH_TEST);
     glClear(GL_COLOR_BUFFER_BIT);

     glViewport(0, 0, win_width, win_height);
     glMatrixMode(GL_PROJECTION);
     glLoadIdentity();
     gluOrtho2D(-1, 1, -1, 1); /* those ortho limits should match your game logic */

     glMatrixMode(GL_MODELVIEW);
     glLoadIdentity();
     c_draw();
     b_draw();
     p_draw();
     glFlush();
     if(started)
                c_move();
     if(crashed())
     {
                 x_pos = 0;
                 y_pos = -0.7;
                 started = 0;
                 UP = 1;
                 RIGHT = 1;
                 DOWN = 0;
                 LEFT = 0;
     }

     dispchetan();
    break;


    }
    glFlush();
    glutSwapBuffers();
    glutPostRedisplay();
}
void user_input(unsigned char key, int x, int y)
{
     if(key == 13)
     started = true;
     if (key == '1' || key == '1'){
          view_no = 3;
          glutPostRedisplay();
	}

	/*if (key == '2' || key == '2')
	{
		  launch pad
	}*/

	if (key == 'I' || key == 'i')
	{

        view_no = 2;
        glutPostRedisplay();
	}
	if (key == 'H' || key == 'h')
	{

        view_no = 1;
        glutPostRedisplay();
	}

	if (key == 'Q' || key == 'q')
		exit(0);
}
void ArrowKeys(int key, int x, int y)
{
     if(key==GLUT_KEY_LEFT && P_XPOS >= -0.8)
      for(float a = 0; a < 0.05; a+= 0.001)
      {
                                      P_XPOS -=0.003;
                                      BallLoop();
      }
     if(key==GLUT_KEY_RIGHT && P_XPOS <= 0.8)
     {
                            for(float a = 0; a < 0.05; a+= 0.001)
                            {
                                      P_XPOS +=0.003;
                                      BallLoop();
                            }
     }
}
void set_xy()
{
    for(int a = 0; a < 5; a++)
    {
            for(int b = 0; b < 10; b++)
            {
                    show[a][b] = 1;
            }
    }
    int c = 0;
    for(float a = -0.94; c <= 8; a+=0.21)
    {

              for(int b = 0; b <= 5; b++)
              {
                      x_brick[b][c] = a;

              }
              c++;
    }
    int d = 0;
    for(float s = 0.99; d <= 3; s-=0.11)
    {
              for(int  r = 0; r < 9; r++)
              {
                       y_brick[d][r] = s;
              }
              d++;
    }
}
void changeSize(int w, int h)
{

    if(h == 0)
        h = 1;
    RATIO = w/h;
    float ratio = 1.0* w / h;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0, 0, w, h);
    glMatrixMode(GL_MODELVIEW);
    BallLoop();
}
int main(int argc, char **argv)
{
    set_xy();
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(WIDTH,HEIGHT);
    glutCreateWindow("Brick Breaker - By Chetan&Sudheesh");
    glutReshapeFunc(changeSize);
    glutDisplayFunc(BallLoop);
    glutKeyboardFunc(user_input);
    glutSpecialFunc(ArrowKeys);
    glutIdleFunc(BallLoop);
    glutMainLoop();
    return 0;
}
