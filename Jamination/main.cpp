#include <iostream>
#include <time.h>
#include <math.h>

// Apple Specific Compatibility Issues
#ifdef __APPLE__
#include "GLUT/glut.h"
#else
#include "GL\glut.h"
#endif

// Define the value of PI, upto 12 decimal places
#define PI 3.141592653589

void selectFont(int newfont);
void selectMessage(int msg);
void tick(void);
void display(void);

//Delays program
void delay(float secs);
//Renders a string at x,y scaled to w,h with the colours r,g,b,a using strokeSize for weight.
void print(char* string,
	GLfloat r, GLfloat g, GLfloat b, GLfloat a,
	GLint x, GLint y,
	GLfloat w, GLfloat h,
	GLfloat strokeSize);
//Draws circle
//TX and TY are the x/y coordinates of the object
//SX and SY are the scale of the object
//r,g,b are RGB colours
void drawCircle(GLfloat x, GLfloat y,
	GLfloat r, GLfloat g, GLfloat b,
	GLfloat sx, GLfloat sy,
	GLfloat radius);
//Draws semi-circle
//TX and TY are the x/y coordinates of the object
//SX and SY are the scale of the object
//r,g,b are RGB colours
void drawSemiCircle(GLfloat tx, GLfloat ty,
	GLfloat sx, GLfloat sy,
	GLfloat r, GLfloat g, GLfloat b,
	GLfloat radius,
	GLfloat start_angle, GLfloat end_angle);

//Draws arc
//TX and TY are the x/y coordinates of the object
//SX and SY are the scale of the object
//r,g,b are RGB colours
void drawArc(GLfloat tx, GLfloat ty,
	GLfloat sx, GLfloat sy,
	GLfloat r, GLfloat g, GLfloat b);

//Draws a woman
//TX and TY are the x/y coordinates of the object
//SX and SY are the scale of the object
//Variables ending in R,G, or B are referring to the colours of that object their name refers to)
void drawWoman(GLfloat tx, GLfloat ty, GLfloat sx, GLfloat sy,
	GLfloat hair_r, GLfloat hair_g, GLfloat hair_b,
	GLfloat top_r, GLfloat top_g, GLfloat top_b,
	GLfloat ribbon_r, GLfloat ribbon_g, GLfloat ribbon_b,
	GLfloat skirt_r, GLfloat skirt_g, GLfloat skirt_b);
//TX and TY are the x/y coordinates of the object
//SX and SY are the scale of the object
//Shirt R, shirt G, shirt B are the RGB colours for the shirt.
void drawDeveloperShirtAndTrousers(GLfloat tx, GLfloat ty,
	GLfloat sx, GLfloat sy,
	GLfloat shirt_r, GLfloat shirt_g, GLfloat shirt_b);
//TX and TY are the x/y coordinates of the object
//SX and SY are the scale of the object
//Shirt R, shirt G, shirt B are the RGB colours for the shirt.
void drawDeveloper(GLfloat tx, GLfloat ty,
	GLfloat sx, GLfloat sy,
	GLfloat shirt_r, GLfloat shirt_g, GLfloat shirt_b);
//TX and TY are the x/y coordinates of the object
//SX and SY are the scale of the object
void drawTree(GLfloat tx, GLfloat ty,
	GLfloat sx, GLfloat sy);
// TX and TY are the x/y coordinates of the object
// SX and SY are the scale of the object
// Shirt R, shirt G, shirt B are the RGB colours for the shirt.
void drawSchoolBoy(GLfloat tx, GLfloat ty,
	GLfloat sx, GLfloat sy,
	GLfloat shirt_r, GLfloat shirt_g, GLfloat shirt_b);

/*
* Scene 0 - Introduction Screen
*/
//Draws the title "JAMINATION" and prompts to press N to start.
void introduction();

/*
* Scene 1 - Client coming to company
*/
//All EC functions refer to this
void clientComing();
// Background for when the client comes to the company.
void EC_drawBackground();
// Road for when the client comes to the company.
void EC_drawRoad();
// Part of the building for when the client comes to the company.
void EC_drawFrontFacingBuilding();
// Part of the building for when the client comes to the company.
void EC_drawLeftWing();
// Part of the building for when the client comes to the company.
void EC_drawRightWing();
// Trees outside the building for when the client comes to the company.
void EC_drawTrees();
// Client coming to the company.
void EC_drawBoys();
// Part of the building for when the client comes to the company.
void EC_drawWorkingStation();
// Part of the building for when the client comes to the company.
void EC_drawBoard();

/*
*	Scene 2 - Client comes
*/
// PS functions refer to this
void clientComes();
// Indoors
// Draws ceiling for when the client comes
void PS_drawCeiling();
// Indoors
// Draws side wall for when the client comes
void PS_drawSideWall();
// Indoors
// Draws centre wall for when the client comes
void PS_drawCentreWall();
// Indoors
// Draws dividing wall for when the client comes
void PS_drawDividingWall();
// Indoors
// Draws receptionist wall for when the client comes
void PS_drawReceptionistWall();
// Indoors
// Draws floor for when the client comes
void PS_drawFloor();
// Indoors
// Draws door for when the client comes
void PS_drawDoor();
// Outdoors
// Draws background for when the client comes
void PS_drawBackground();
// Outdoors
// Draws road for when the client comes
void PS_drawRoad();
// Outdoors
// Draws outside for when the client comes
void PS_drawOutside();
// Indoors
// Draws reception for when the client comes
void PS_drawReception();

/*
* Scene 3 - Meeting Room
*/
//All KG functions refer to this
void meetingRoom();
//Draws the ceiling and border for meeting room
void KG_drawCeiling();
//Draws the side wall for meeting room
void KG_drawSideWall();
//Draws the centre wall for meeting room
void KG_drawCentreWall();
//Draws the floor for meeting room
void KG_drawFloor();
//Draws the outside background for meeting room
void KG_drawOutside();
//Draws the door for meeting room
void KG_drawDoor();
//Draws head
//TX and TY are the x/y coordinates of the object
void KG_drawDevHead(GLfloat tx, GLfloat ty);
//Draws the blackboard for meeting room
void KG_drawBlackboard();
// Draws the desks for meeting room
void KG_drawDesks();

/*
*	Scene 4 - Developers working
*/
//All PUC functions refer to this
void workingStation();
//Draws floor for the developers working
void PUC_drawFloor();
//Draws centre wallfor the developers working
void PUC_drawCentreWall();
//Draws ceiling for the developers working
void PUC_drawCeiling();
//Draws left wall for the developers working
void PUC_drawLeftWall();
//Draws right wall for the developers working
void PUC_drawRightWall();
//Draws left doors for the developers working
void PUC_drawLeftDoors();
//Draws right doors for the developers working
void PUC_drawRightDoors();
//Draws board for the developers working
void PUC_drawBoard();

/*
*	Scene 5 - Developer in workplace
*/
// All WP functions above refer to this.
void workplace();
// Floor under working developer
void WP_drawFloor();
// Side wall next to working developer
void WP_drawSideWall();
// Wall next to working developer
void WP_drawWall();
// Table for working developer
void WP_drawTable();
// Tech person in the working developer scene
void WP_drawTechie();
// Computer for working developer
void WP_drawComputer();
// AC next to working developer
void WP_drawAC();
bool server_on;
bool light_a = true, light_b, light_c, light_d;
// Servers light next to working developer
//TX and TY are the x/y coordinates of the object
//Light R, Light G, and Light B refer to the colour of the light in RGB, when on
void WP_drawServerLight(GLfloat tx, GLfloat ty,
	GLfloat light_r, GLfloat light_g, GLfloat light_b,
	bool light_on);
// Server box next to working developer
// TX and TY are the x/y coordinates of the object
//void WP_drawServerInnerBox(GLfloat tx, GLfloat ty);
// Server box next to working developer
//bool wp_tb_s1_done, wp_tb_s2_done, wp_tb_s3_done, wp_tb_big_done;
//GLfloat wp_tb_s1, wp_tb_s2, wp_tb_s3, wp_tb_big,
wp_tb_text;
// Thought bubble for when the developer is working next to the server
void WP_drawThoughtBubble();

/*
*	Scene 6 - The final window
*/
void end();

// Function to Render Scene
void renderScene();
// Animator Update Function
// Times and changes scenes
void update(int);
// Keyboard Action
void keyPress(unsigned char key, int x, int y);
// Function to Initialize Screen
void initializeScreen();
// Main Function
// Initializing window and rendering
int main(int argc, char** argv);

//Declaring and initializing global variables
// ID to detect which scene the story is in.
int SCENE_ID;
// Variables for Animator Faders
GLfloat title_fade,
intro_next_text_appear,
kg_a_fade, kg_apple_fade, kg_b_fade, kg_ball_fade, kg_soon_fade, kg_subtitle_1_appear,
ps_chap_fade, ps_title_fade,
ps_subtitle_1_appear, ps_subtitle_2_appear, ps_subtitle_3_appear, ps_subtitle_4_appear, ps_subtitle_5_appear,
hs_subtitle_1_appear,
puc_subtitle_1_fade,
ec_subtitle_1_fade,
wp_subtitle_1_fade,
t_subtitle_1_appear;
// Variables for Translation Animators
GLfloat
trans_x_chap2, trans_y_title2,
trans_x_guy2, trans_x_ball,
trans_subtitle_1_done, trans_subtitle_2_done, trans_subtitle_3_done, trans_subtitle_4_done, trans_subtitle_5_done,
t_subtitle_1_done,
trans_x_sb1 = -630, trans_y_sb1 = -50, trans_x_sb2 = -1630, trans_y_sb2 = -50,
trans_x_ec_sb1 = 850, trans_x_ec_sb2 = -1000, trans_y_ec_sb = 40, trans_x_ec_gb = -180, trans_y_ec_gb = 1040;
// Variables for Colour Morphers
GLfloat window_top_r = 59, window_top_g = 91, window_top_b = 132,
window_bottom_r = 97, window_bottom_g = 131, window_bottom_b = 159,
sky_r = 12, sky_g = 172, sky_b = 232,
grass_r = 82, grass_g = 163, grass_b = 42;
// Variables for Turn-based Switching
bool
chapter_1_done, chapter_2_done, chapter_3_done, chapter_4_done, chapter_5_done,
puc_begin_anim, puc_end_anim,
ec_graduation_done;
void* style = GLUT_STROKE_ROMAN;
void* styles[] =
{ GLUT_STROKE_ROMAN, GLUT_STROKE_MONO_ROMAN };
char companyName[] = "J A M I N A T I O N";
char* company = companyName;
int rotate = 0;	// angle

//Functions for the window's rendering
void
selectFont(int newfont)
{
	style = styles[newfont];
	glutPostRedisplay();
}
void
selectMessage(int msg)
{
	switch (msg) {
	case 1:
		company = "abcdefghijklmnop";
		break;
	case 2:
		company = "ABCDEFGHIJKLMNOP";
		break;
	}
}
void
tick(void)
{
	rotate -= 2;
	glutPostRedisplay();
}
void
display(void)
{
	int size;

	glClear(GL_COLOR_BUFFER_BIT);
	glPushMatrix();
	glRotatef(rotate, 0.0, 0.0, 1.0);

	glTranslatef(-750, 0, 0);

	size = (int)strlen(company);

	for (int i = 0; i < size; i++) {
		glutStrokeCharacter(style, company[i]);
		Sleep(2);
	}
	glPopMatrix();
	glutSwapBuffers();
}

//Delays program
void delay(float secs) {
	float end = clock() / CLOCKS_PER_SEC + secs;
	while ((clock() / CLOCKS_PER_SEC) < end);
}
//Renders a string at x,y scaled to w,h with the colours r,g,b,a using strokeSize for weight.
void print(char* string,
	GLfloat r, GLfloat g, GLfloat b, GLfloat a,
	GLint x, GLint y,
	GLfloat w, GLfloat h,
	GLfloat strokeSize) {
	glPushMatrix();

	glColor4f(r, g, b, a);
	glTranslatef(x, y, 0);
	glScalef(w, h, 0);

	glPointSize(strokeSize);
	glLineWidth(strokeSize);

	while (*string)
		glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, *string++);

	glPopMatrix();

	glLineWidth(1);
	glPointSize(1);
}
//Draws circle
//TX and TY are the x/y coordinates of the object
//SX and SY are the scale of the object
//r,g,b are RGB colours
void drawCircle(GLfloat x, GLfloat y,
	GLfloat r, GLfloat g, GLfloat b,
	GLfloat sx, GLfloat sy,
	GLfloat radius) {
	glPushMatrix();

	glTranslatef(x, y, 0);
	glScalef(sx, sy, 0);

	glBegin(GL_POLYGON);
	glColor3ub(r, g, b);
	for (GLfloat i = 0; i < 360; i += 5)
		glVertex2f(radius * sin(i * PI / 180), radius * cos(i * PI / 180));
	glEnd();

	glPopMatrix();
}
//Draws semi-circle
//TX and TY are the x/y coordinates of the object
//SX and SY are the scale of the object
//r,g,b are RGB colours
void drawSemiCircle(GLfloat tx, GLfloat ty,
	GLfloat sx, GLfloat sy,
	GLfloat r, GLfloat g, GLfloat b,
	GLfloat radius,
	GLfloat start_angle, GLfloat end_angle) {
	glPushMatrix();

	glTranslatef(tx, ty, 0);
	glScalef(sx, sy, 0);

	glBegin(GL_POLYGON);
	glColor3ub(r, g, b);
	for (GLfloat i = start_angle; i < end_angle; i += 5)
		glVertex2f(radius * sin(i * PI / 180), radius * cos(i * PI / 180));
	glEnd();

	glPopMatrix();
}

//Draws arc
//TX and TY are the x/y coordinates of the object
//SX and SY are the scale of the object
//r,g,b are RGB colours
void drawArc(GLfloat tx, GLfloat ty,
	GLfloat sx, GLfloat sy,
	GLfloat r, GLfloat g, GLfloat b) {
	glPushMatrix();

	glTranslatef(tx, ty, 0);
	glScalef(sx, sy, 0);

	glPointSize(2);
	glBegin(GL_POINTS);
	glColor3ub(r, g, b);
	for (GLfloat i = 90; i < 270; i++)
		glVertex2f(15 * sin(i * PI / 180), 15 * cos(i * PI / 180));
	glEnd();
	glPointSize(1);

	glPopMatrix();
}

//Draws a woman
//TX and TY are the x/y coordinates of the object
//SX and SY are the scale of the object
//Variables ending in R,G, or B are referring to the colours of that object their name refers to
void drawWoman(GLfloat tx, GLfloat ty, GLfloat sx, GLfloat sy,
	GLfloat hair_r, GLfloat hair_g, GLfloat hair_b,
	GLfloat top_r, GLfloat top_g, GLfloat top_b,
	GLfloat ribbon_r, GLfloat ribbon_g, GLfloat ribbon_b,
	GLfloat skirt_r, GLfloat skirt_g, GLfloat skirt_b) {
	glPushMatrix();

	glTranslatef(tx, ty, 0);
	glScalef(sx, sy, 0);

	// Neck
	glLineWidth(10);
	glBegin(GL_LINES);
	glColor3ub(203, 166, 108); // Darker Skin
	glVertex2f(507, 380);
	glVertex2f(507, 360);
	glVertex2f(513, 380);
	glVertex2f(513, 360);
	glEnd();
	glLineWidth(1);

	// Face
	drawCircle(510, 407,
		232, 190, 123, // Lighter Skin
		1, 1,
		30);

	// Hair
	drawSemiCircle(510, 420, 1, .6,
		hair_r, hair_g, hair_b,
		35, -90, 90);

	drawSemiCircle(485, 400, .4, 1,
		hair_r, hair_g, hair_b,
		35, -180, 0);

	// Left Eye
	drawCircle(505, 410,
		250, 250, 250,
		1, 1,
		5);

	drawCircle(508, 408,
		10, 10, 10,
		1, 1,
		2.5);

	// Right Eye
	drawCircle(530, 410,
		250, 250, 250,
		1, 1,
		5);

	drawCircle(532, 408,
		10, 10, 10,
		1, 1,
		2.5);

	// Smile
	drawArc(514, 388, .5, .3,
		20, 20, 20);

	// Nose
	glLineWidth(2);
	glBegin(GL_LINES);
	glVertex2f(518, 405);
	glVertex2f(522, 398);
	glVertex2f(522, 398);
	glVertex2f(518, 395);
	glEnd();
	glLineWidth(1);

	// Arms
	glLineWidth(10);
	glBegin(GL_LINES);
	glColor3ub(232, 190, 123); // Lighter Skin
	glVertex2f(470, 340);
	glVertex2f(470, 240);
	glVertex2f(475, 340);
	glVertex2f(475, 240);
	glVertex2f(480, 340);
	glVertex2f(480, 240);

	glVertex2f(540, 340);
	glVertex2f(540, 240);
	glVertex2f(545, 340);
	glVertex2f(545, 240);
	glVertex2f(550, 340);
	glVertex2f(550, 240);
	glEnd();
	glLineWidth(1);

	// Top
	glBegin(GL_POLYGON);
	glColor3ub(top_r, top_g, top_b);
	glVertex2f(460, 370);
	glVertex2f(560, 370);
	glVertex2f(540, 300);
	glVertex2f(480, 300);
	glEnd();

	// Skirt
	glBegin(GL_POLYGON);
	glColor3ub(skirt_r, skirt_g, skirt_b);
	glVertex2f(480, 300);
	glVertex2f(540, 300);
	glVertex2f(560, 180);
	glVertex2f(460, 180);
	glEnd();

	// Ribbon
	glLineWidth(10);
	glBegin(GL_LINES);
	glColor3ub(ribbon_r, ribbon_g, ribbon_b);
	glVertex2f(480, 300);
	glVertex2f(540, 300);
	glEnd();
	glLineWidth(1);

	// Legs
	glLineWidth(10);
	glBegin(GL_LINES);
	glColor3ub(232, 190, 123); // Lighter Skin
	glVertex2f(490, 180);
	glVertex2f(490, 150);
	glVertex2f(495, 180);
	glVertex2f(495, 150);

	glVertex2f(525, 180);
	glVertex2f(525, 150);
	glVertex2f(530, 180);
	glVertex2f(530, 150);
	glEnd();
	glLineWidth(1);

	glPopMatrix();
}
//TX and TY are the x/y coordinates of the object
//SX and SY are the scale of the object
//Shirt R, shirt G, shirt B are the RGB colours for the shirt.
void drawDeveloperShirtAndTrousers(GLfloat tx, GLfloat ty,
	GLfloat sx, GLfloat sy,
	GLfloat shirt_r, GLfloat shirt_g, GLfloat shirt_b) {
	glPushMatrix();

	glTranslatef(tx, ty, 0);
	glScalef(sx, sy, 0);

	// Bottom Shirt
	glColor3ub(shirt_r, shirt_g, shirt_b);
	glBegin(GL_POLYGON);
	glVertex2f(0, 20);
	glVertex2f(100, 20);
	glVertex2f(100, 100);
	glVertex2f(0, 100);
	glEnd();

	// Top Shirt
	glBegin(GL_POLYGON);
	glVertex2f(100, 100);
	glVertex2f(135, 105);
	glVertex2f(120, 175);
	glVertex2f(100, 200);
	glVertex2f(50, 180);
	glVertex2f(0, 200);
	glVertex2f(-20, 175);
	glVertex2f(-35, 105);
	glVertex2f(0, 100);
	glEnd();

	// Left Leg Trouser
	glColor3ub(37, 107, 202);
	glBegin(GL_POLYGON);
	glVertex2f(0, 25);
	glVertex2f(0, -100);
	glVertex2f(35, -100);
	glVertex2f(65, 25);
	glEnd();

	// Right Leg Trouser
	glBegin(GL_POLYGON);
	glVertex2f(35, 25);
	glVertex2f(65, -100);
	glVertex2f(100, -100);
	glVertex2f(100, 25);
	glEnd();

	glPopMatrix();
}
//TX and TY are the x/y coordinates of the object
//SX and SY are the scale of the object
//Shirt R, shirt G, shirt B are the RGB colours for the shirt.
void drawDeveloper(GLfloat tx, GLfloat ty,
	GLfloat sx, GLfloat sy,
	GLfloat shirt_r, GLfloat shirt_g, GLfloat shirt_b) {
	glPushMatrix();

	glTranslatef(tx, ty, 0);
	glScalef(sx, sy, 0);

	// Neck
	drawSemiCircle(-1, -35, .6, 1,
		203, 166, 108,
		20, -90, 90);

	// Face
	drawCircle(0, 0,
		232, 190, 123,
		1, 1,
		24);

	// Left Eye
	drawCircle(-8, 0,
		250, 250, 250,
		1, 1,
		4);
	drawCircle(-6, 0,
		10, 10, 10,
		1, 1,
		2);

	// Right Eye
	drawCircle(8, 0,
		250, 250, 250,
		1, 1,
		4);
	drawCircle(10, 0,
		10, 10, 10,
		1, 1,
		2);

	// Cap
	drawSemiCircle(0, 10, 1, 1,
		0, 0, 0,
		24, -90, 90);

	// Hands
	drawCircle(-42, -82,
		232, 190, 123,
		1, 1,
		10);
	drawCircle(38, -82,
		232, 190, 123,
		1, 1,
		10);

	// Shirt and Trousers
	drawDeveloperShirtAndTrousers(-32, -125,
		.6, .5,
		shirt_r, shirt_g, shirt_b);

	// Left Shoe
	drawSemiCircle(-21, -178,
		1.2, 1,
		20, 20, 20,
		10,
		-90, 90);

	// Right Shoe
	drawSemiCircle(18, -178,
		1.2, 1,
		20, 20, 20,
		10,
		-90, 90);

	glPopMatrix();
}
//TX and TY are the x/y coordinates of the object
//SX and SY are the scale of the object
void drawTree(GLfloat tx, GLfloat ty,
	GLfloat sx, GLfloat sy) {
	glPushMatrix();

	glTranslatef(tx, ty, 0);
	glScalef(sx, sy, 0);

	// Bark
	glBegin(GL_POLYGON);
	glColor3ub(86, 46, 11);
	glVertex2f(0, 0);
	glVertex2f(40, 0);
	glColor3ub(71, 36, 6);
	glVertex2f(35, 200);
	glVertex2f(5, 200);
	glEnd();

	// Tree
	drawCircle(20, 200, 5, 80, 10, 1, 1, 80);

	// Apples
	drawCircle(27, 194, 255, 0, 0, 1, 1.2, 5);
	drawCircle(-15, 170, 255, 0, 0, 1, 1.2, 5);
	drawCircle(47, 155, 255, 0, 0, 1, 1.2, 5);
	drawCircle(-2, 228, 255, 0, 0, 1, 1.2, 5);
	drawCircle(72, 216, 255, 0, 0, 1, 1.2, 5);

	glPopMatrix();
}
// TX and TY are the x/y coordinates of the object
// SX and SY are the scale of the object
// Shirt R, shirt G, shirt B are the RGB colours for the shirt.
void drawSchoolBoy(GLfloat tx, GLfloat ty,
	GLfloat sx, GLfloat sy,
	GLfloat shirt_r, GLfloat shirt_g, GLfloat shirt_b) {
	glPushMatrix();

	glScalef(sx, sy, 0);
	glTranslatef(tx, ty, 0);

	// Shoes
	drawSemiCircle(1160, 120,
		1, 1,
		255, 255, 255,
		10,
		-90, 91);

	// Shoe Extension
	glBegin(GL_POLYGON);
	glColor3ub(255, 255, 255);
	glVertex2f(1160, 120);
	glVertex2f(1170, 120);
	glVertex2f(1170, 135);
	glVertex2f(1160, 135);
	glEnd();

	// Pants
	glBegin(GL_POLYGON);
	glColor3ub(0, 0, 200);
	glVertex2f(1158, 135);
	glVertex2f(1172, 135);
	glVertex2f(1170, 190);
	glVertex2f(1160, 190);
	glEnd();

	// Shirt
	glBegin(GL_POLYGON);
	glColor3ub(shirt_r, shirt_g, shirt_b);
	glVertex2f(1155, 190);
	glVertex2f(1170, 190);
	glVertex2f(1170, 260);
	glVertex2f(1160, 260);
	glEnd();

	// Head
	drawCircle(1164, 273,
		232, 190, 123,
		1, 1.4,
		12);

	// Hair
	drawSemiCircle(1167, 277,
		1, 1,
		0, 0, 0,
		14,
		-80, 180);

	// Nose
	glBegin(GL_TRIANGLES);
	glColor3ub(232, 190, 123);
	glVertex2f(1155, 270);
	glVertex2f(1152, 260);
	glVertex2f(1157, 262);
	glEnd();

	// Eye
	glPointSize(2);
	glBegin(GL_POINTS);
	glColor3ub(0, 0, 0);
	glVertex2f(1156, 270);
	glEnd();
	glPointSize(1);

	// Lips
	glPointSize(1);
	glBegin(GL_POINTS);
	glColor3ub(0, 0, 0);
	glVertex2f(1158, 256);
	glVertex2f(1159, 257);
	glVertex2f(1160, 258);
	glEnd();
	glPointSize(1);

	glPopMatrix();
}


/*
* Scene 0 - Introduction Title Screen
*/
//Draws "JAMINATION" and the prompt to press N to start.
void introduction() {
	// Background
	glClearColor(0.05, 0.05, 0.05, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);

	// Story Title
	print("JAMINATION",
		1, 1, 1, title_fade, 280, 380, .3, .3, 2);

	print("Press N to start the animation.",
		1, 1, 1, intro_next_text_appear, 560, 10, .09, .09, 1);
}

/*
*	Scene 1 - Client coming to company
*/
//All EC functions refer to this
void clientComing() {
	// Background
	glClearColor(0.05, 0.05, 0.05, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);

	EC_drawBackground();
	EC_drawRoad();

	EC_drawWorkingStation();

	EC_drawTrees();
	EC_drawBoys();

	EC_drawBoard();

	print("A client owning a store comes to the company for a website and a mobile app.",
		1, 1, 1, ec_subtitle_1_fade, 60, 30, .14, .14, 1);
}
// Background for when the client comes to the company.
void EC_drawBackground() {
	// Background
	glBegin(GL_POLYGON);
	glColor3ub(12, 172, 232); // Sky Blue
	glVertex2f(0, 800);
	glVertex2f(1400, 800);
	glVertex2f(1400, 400);
	glVertex2f(0, 400);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(12, 172, 232); // Sky Blue
	glVertex2f(0, 400);
	glVertex2f(1400, 400);
	glColor3ub(82, 163, 42); // Green Grass
	glVertex2f(1400, 125);
	glVertex2f(0, 125);
	glEnd();
}
// Road for when the client comes to the company.
void EC_drawRoad() {
	glBegin(GL_POLYGON);
	glColor3ub(40, 40, 40);
	glVertex2f(0, 75);
	glVertex2f(1400, 75);
	glVertex2f(1400, 125);
	glVertex2f(0, 125);
	glEnd();

	glLineWidth(2);
	glBegin(GL_LINES);
	glColor3ub(255, 255, 255);
	glVertex2f(0, 100);
	glVertex2f(100, 100);

	glVertex2f(120, 100);
	glVertex2f(220, 100);

	glVertex2f(240, 100);
	glVertex2f(340, 100);

	glVertex2f(360, 100);
	glVertex2f(460, 100);

	glVertex2f(480, 100);
	glVertex2f(580, 100);

	glVertex2f(600, 100);
	glVertex2f(700, 100);

	glVertex2f(720, 100);
	glVertex2f(820, 100);

	glVertex2f(840, 100);
	glVertex2f(940, 100);

	glVertex2f(960, 100);
	glVertex2f(1060, 100);

	glVertex2f(1080, 100);
	glVertex2f(1180, 100);

	glVertex2f(1200, 100);
	glVertex2f(1300, 100);

	glVertex2f(1320, 100);
	glVertex2f(1420, 100);

	glEnd();
	glLineWidth(1);
}
// Part of the building for when the client comes to the company.
void EC_drawFrontFacingBuilding() {
	// Front Facing Building
	glBegin(GL_POLYGON);
	glColor3ub(30, 120, 182);
	glVertex2f(550, 125);
	glColor3ub(4, 36, 86);
	glVertex2f(850, 125);
	glColor3ub(0, 22, 52);
	glVertex2f(850, 650);
	glColor3ub(2, 36, 80);
	glVertex2f(550, 650);
	glEnd();

	// Front Facing Building Mesh
	glBegin(GL_LINES);
	glColor3ub(0, 30, 60);

	// Vertical Lines - 4
	glVertex2f(550, 650);
	glVertex2f(550, 125);

	glVertex2f(625, 650);
	glVertex2f(625, 125);

	glVertex2f(700, 650);
	glVertex2f(700, 125);

	glVertex2f(775, 650);
	glVertex2f(775, 125);

	glVertex2f(850, 650);
	glVertex2f(850, 125);

	// Horizontal Lines - 10
	glVertex2f(550, 125);
	glVertex2f(850, 125);

	glVertex2f(550, 177.5);
	glVertex2f(850, 177.5);

	glVertex2f(550, 230);
	glVertex2f(850, 230);

	glVertex2f(550, 282.5);
	glVertex2f(850, 282.5);

	glVertex2f(550, 335);
	glVertex2f(850, 335);

	glVertex2f(550, 387.5);
	glVertex2f(850, 387.5);

	glVertex2f(550, 440);
	glVertex2f(850, 440);

	glVertex2f(550, 492.5);
	glVertex2f(850, 492.5);

	glVertex2f(550, 545);
	glVertex2f(850, 545);

	glVertex2f(550, 598);
	glVertex2f(850, 598);

	glVertex2f(550, 650);
	glVertex2f(850, 650);
	glEnd();

	// Door
	glBegin(GL_POLYGON);
	glColor3ub(23, 99, 152);
	glVertex2f(626, 125);
	glColor3ub(11, 57, 110);
	glVertex2f(774, 125);
	glColor3ub(8, 49, 92);
	glVertex2f(774, 282);
	glColor3ub(21, 99, 144);
	glVertex2f(626, 282);
	glEnd();

	glBegin(GL_LINES);
	glColor3ub(0, 30, 60);
	glVertex2f(700, 282);
	glVertex2f(700, 125);
	glEnd();

	drawCircle(690, 206, 240, 240, 240, 1, 1, 3);
	drawCircle(690, 202, 240, 240, 240, 1, 1, 3);
	drawCircle(690, 198, 240, 240, 240, 1, 1, 3);

	drawCircle(710, 206, 240, 240, 240, 1, 1, 3);
	drawCircle(710, 202, 240, 240, 240, 1, 1, 3);
	drawCircle(710, 198, 240, 240, 240, 1, 1, 3);
}
// Part of the building for when the client comes to the company.
void EC_drawLeftWing() {
	// Left Wing
	glBegin(GL_POLYGON);
	glColor3ub(0, 30, 60);
	glVertex2f(500, 125);
	glVertex2f(550, 125);
	glVertex2f(550, 598);
	glVertex2f(500, 598);
	glEnd();

	// Left Building
	glBegin(GL_POLYGON);
	glColor3ub(30, 120, 182);
	glVertex2f(200, 184);
	glColor3ub(4, 36, 86);
	glVertex2f(500, 125);
	glColor3ub(0, 22, 52);
	glVertex2f(500, 598);
	glColor3ub(2, 36, 80);
	glVertex2f(200, 539);
	glEnd();

	// Left Building
	glBegin(GL_LINE_LOOP);
	glColor3ub(0, 30, 60);
	glVertex2f(200, 184);
	glVertex2f(500, 125);
	glVertex2f(500, 598);
	glVertex2f(200, 539);
	glEnd();

	// Windows Edges
	glBegin(GL_LINES);
	glColor3ub(0, 30, 60);
	glVertex2f(500, 125);
	glVertex2f(500, 598);

	glVertex2f(400, 144);
	glVertex2f(400, 576);

	glVertex2f(300, 164);
	glVertex2f(300, 556);

	glVertex2f(200, 184);
	glVertex2f(200, 539);
	glEnd();
}
// Part of the building for when the client comes to the company.
void EC_drawRightWing() {
	// Right Wing
	glBegin(GL_POLYGON);
	glColor3ub(0, 30, 60);
	glVertex2f(850, 125);
	glVertex2f(900, 125);
	glVertex2f(900, 598);
	glVertex2f(850, 598);
	glEnd();

	// Right Building
	glBegin(GL_POLYGON);
	glColor3ub(4, 36, 86);
	glVertex2f(900, 125);
	glColor3ub(30, 120, 182);
	glVertex2f(1200, 184);
	glColor3ub(2, 36, 80);
	glVertex2f(1200, 539);
	glColor3ub(0, 22, 52);
	glVertex2f(900, 598);
	glEnd();

	// Right Building
	glBegin(GL_LINE_LOOP);
	glColor3ub(0, 30, 60);
	glVertex2f(900, 125);
	glVertex2f(1200, 184);
	glVertex2f(1200, 539);
	glVertex2f(900, 598);
	glEnd();

	// Windows Edges
	glBegin(GL_LINES);
	glColor3ub(0, 30, 60);
	glVertex2f(900, 125);
	glVertex2f(900, 598);

	glVertex2f(1000, 144);
	glVertex2f(1000, 576);

	glVertex2f(1100, 164);
	glVertex2f(1100, 556);

	glVertex2f(1200, 184);
	glVertex2f(1200, 539);
	glEnd();
}
// Trees outside the building for when the client comes to the company.
void EC_drawTrees() {
	// Left Trees
	drawTree(430, 130, .5, .5);
	drawTree(360, 140, .48, .48);
	drawTree(290, 150, .46, .46);
	drawTree(220, 160, .44, .44);

	// Right Trees
	drawTree(940, 130, .5, .5);
	drawTree(1010, 140, .48, .48);
	drawTree(1080, 150, .46, .46);
	drawTree(1150, 160, .44, .44);
}
// Client coming to the company.
void EC_drawBoys() {
	// Red Boy
	drawSchoolBoy(trans_x_ec_sb1, trans_y_ec_sb,
		.75, .75,
		255, 0, 0);
}
// Part of the building for when the client comes to the company.
void EC_drawWorkingStation() {
	EC_drawFrontFacingBuilding();
	EC_drawLeftWing();
	EC_drawRightWing();
}
// Part of the building for when the client comes to the company.
void EC_drawBoard() {
	glBegin(GL_POLYGON);
	glColor3ub(0, 30, 60);
	glVertex2f(500, 660);
	glVertex2f(900, 660);
	glVertex2f(900, 760);
	glVertex2f(500, 760);
	glEnd();

	glLineWidth(10);
	glBegin(GL_LINES);
	glVertex2f(625, 650);
	glVertex2f(625, 670);
	glEnd();
	glLineWidth(1);

	glLineWidth(10);
	glBegin(GL_LINES);
	glVertex2f(775, 650);
	glVertex2f(775, 670);
	glEnd();
	glLineWidth(1);

	glBegin(GL_POLYGON);
	glColor3ub(2, 36, 80);
	glVertex2f(505, 665);
	glVertex2f(895, 665);
	glColor3ub(0, 22, 52);
	glVertex2f(895, 755);
	glVertex2f(505, 755);
	glEnd();

	print("Welcome to",
		1, 1, 1, 1,
		640, 725,
		.12, .12,
		1);

	print("JAMINATION COMPANY",
		1, 1, 1, 1,
		530, 685,
		.19, .19,
		1);
}


/*
*	Scene 2 - Client comes
*/
// PS functions refer to this
void clientComes() {
	// Background
	glClearColor(0.05, 0.05, 0.05, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);

	print("RECEPTIONIST: Hello sir, how may I help you?",
		1, 1, 1, ps_subtitle_1_appear, 300, 30 + trans_subtitle_1_done, .14, .14, 1);

	print("CUSTOMER: I want a website and mobile application for my shop.",
		1, 1, 1, ps_subtitle_2_appear, 300, 30 + trans_subtitle_2_done, .14, .14, 1);

	print("RECEPTIONIST: When do you need it and what is your budget?",
		1, 1, 1, ps_subtitle_3_appear, 300, 30 + trans_subtitle_3_done, .14, .14, 1);

	print("CUSTOMER: 2 months and my budget is £1000.",
		1, 1, 1, ps_subtitle_4_appear, 300, 30 + trans_subtitle_4_done, .14, .14, 1);

	print("RECEPTIONIST: That's fine. Kindly tell us your requirements.",
		1, 1, 1, ps_subtitle_5_appear, 300, 30 + trans_subtitle_5_done, .14, .14, 1);

	PS_drawCeiling();
	PS_drawSideWall();
	PS_drawCentreWall();
	PS_drawDividingWall();
	PS_drawFloor();

	PS_drawDoor();

	PS_drawOutside();

	PS_drawReceptionistWall();
	PS_drawReception();

	// Guy inside House
	drawDeveloper(250, 370,
		1, 1,
		255, 0, 0);
}
// Indoors
// Draws ceiling for when the client comes
void PS_drawCeiling() {
	// Ceiling
	glBegin(GL_POLYGON);
	glColor3ub(65, 105, 120); // Aqua
	glVertex2f(0, 800);
	glVertex2f(0, 700);
	glVertex2f(100, 650);
	glVertex2f(1400, 650);
	glVertex2f(1400, 800);
	glEnd();

	// Border for Ceiling
	glBegin(GL_LINE_LOOP);
	glColor3ub(0, 0, 0);
	glVertex2f(0, 800);
	glVertex2f(0, 700);
	glVertex2f(100, 650);
	glVertex2f(1400, 650);
	glVertex2f(1400, 800);
	glEnd();
}
// Indoors
// Draws side wall for when the client comes
void PS_drawSideWall() {
	// Side Wall
	glBegin(GL_POLYGON);
	glColor3ub(176, 204, 217); // Light Aqua
	glVertex2f(0, 700);
	glVertex2f(100, 650);
	glVertex2f(100, 200);
	glVertex2f(0, 75);
	glEnd();

	// Border for Side Wall
	glBegin(GL_LINE_LOOP);
	glColor3ub(0, 0, 0);
	glVertex2f(0, 700);
	glVertex2f(100, 650);
	glVertex2f(100, 200);
	glVertex2f(0, 75);
	glEnd();
}
// Indoors
// Draws centre wall for when the client comes
void PS_drawCentreWall() {
	// Centre Wall
	glBegin(GL_POLYGON);
	glColor3ub(120, 160, 175);
	glVertex2f(100, 650);
	glVertex2f(700, 650);
	glColor3ub(164, 191, 203);
	glVertex2f(700, 200);
	glVertex2f(100, 200);
	glEnd();

	// Border for Centre Wall
	glBegin(GL_LINE_LOOP);
	glColor3ub(0, 0, 0);
	glVertex2f(100, 650);
	glVertex2f(700, 650);
	glVertex2f(700, 200);
	glVertex2f(100, 200);
	glEnd();
}
// Indoors
// Draws dividing wall for when the client comes
void PS_drawDividingWall() {
	// Dividing Wall
	glBegin(GL_POLYGON);
	glColor3ub(176, 204, 217); // Light Aqua
	glVertex2f(700, 650);
	glVertex2f(850, 800);
	glVertex2f(850, 75);
	glVertex2f(700, 200);
	glEnd();

	// Border for Dividing Wall
	glBegin(GL_LINE_LOOP);
	glColor3ub(0, 0, 0);
	glVertex2f(700, 650);
	glVertex2f(850, 800);
	glVertex2f(850, 75);
	glVertex2f(700, 200);
	glEnd();
}
// Indoors
// Draws receptionist wall for when the client comes
void PS_drawReceptionistWall() {
	// Wall
	glBegin(GL_POLYGON);
	glColor3ub(164, 191, 203);
	glVertex2f(850, 800);
	glVertex2f(1400, 800);
	glVertex2f(1400, 75);
	glVertex2f(850, 75);
	glEnd();

	// Border for Wall
	glBegin(GL_LINE_LOOP);
	glColor3ub(0, 0, 0);
	glVertex2f(850, 800);
	glVertex2f(1400, 800);
	glVertex2f(1400, 75);
	glVertex2f(850, 75);
	glEnd();
}
// Indoors
// Draws floor for when the client comes
void PS_drawFloor() {
	// Floor
	glBegin(GL_POLYGON);
	glColor3ub(120, 160, 175);
	glVertex2f(100, 200);
	glVertex2f(700, 200);
	glVertex2f(850, 75);
	glVertex2f(0, 75);
	glEnd();

	// Border for Floor
	glBegin(GL_LINE_LOOP);
	glColor3ub(0, 0, 0);
	glVertex2f(100, 200);
	glVertex2f(700, 200);
	glVertex2f(850, 75);
	glVertex2f(0, 75);
	glEnd();
}
// Indoors
// Draws door for when the client comes
void PS_drawDoor() {
	// Door
	glBegin(GL_POLYGON);
	glColor3ub(255, 255, 255);
	glVertex2f(300, 500);
	glVertex2f(500, 500);
	glVertex2f(500, 200);
	glVertex2f(300, 200);
	glEnd();

	// Border
	glLineWidth(5);
	glBegin(GL_LINES);
	glColor3ub(122, 76, 29); // Wood Dark Brown
	glVertex2f(300, 200);
	glVertex2f(300, 500);
	glVertex2f(300, 500);
	glVertex2f(500, 500);
	glVertex2f(500, 500);
	glVertex2f(500, 200);
	glEnd();
	glLineWidth(1);
}
// Outdoors
// Draws background for when the client comes
void PS_drawBackground() {
	glBegin(GL_POLYGON);
	glColor3ub(12, 172, 232); // Sky Blue
	glVertex2f(300, 500);
	glVertex2f(500, 500);
	glColor3ub(82, 163, 42); // Green Grass
	glVertex2f(500, 275);
	glVertex2f(300, 275);
	glEnd();
}
// Outdoors
// Draws road for when the client comes
void PS_drawRoad() {
	glBegin(GL_POLYGON);
	glColor3ub(40, 40, 40);
	glVertex2f(300, 275);
	glVertex2f(500, 275);
	glVertex2f(500, 200);
	glVertex2f(300, 200);
	glEnd();

	glLineWidth(3);
	glBegin(GL_LINES);
	glColor3ub(255, 255, 255);
	glVertex2f(300, 235);
	glVertex2f(380, 235);
	glVertex2f(420, 235);
	glVertex2f(500, 235);
	glEnd();
	glLineWidth(1);
}
// Outdoors
// Draws outside for when the client comes
void PS_drawOutside() {
	PS_drawBackground();
	PS_drawRoad();
}
// Indoors
// Draws reception for when the client comes
void PS_drawReception() {
	glBegin(GL_POLYGON);
	glColor3ub(247, 239, 187);
	glVertex2f(950, 550);
	glVertex2f(1300, 550);
	glVertex2f(1300, 300);
	glVertex2f(950, 300);
	glEnd();

	// PS_drawReceptionist
	drawWoman(1630, 50, -1, 1,
		20, 20, 20,
		229, 49, 49, // top
		37, 107, 202, // bottom
		229, 49, 49 // skirt
	);

	// Method to hide Woman's body
	glBegin(GL_POLYGON);
	glColor3ub(164, 191, 203);
	glVertex2f(1050, 300);
	glVertex2f(1200, 300);
	glVertex2f(1200, 140);
	glVertex2f(1050, 140);
	glEnd();

	// Receptionist Table
	glBegin(GL_POLYGON);
	glColor3ub(138, 82, 32);
	glVertex2f(950, 300);
	glVertex2f(1000, 330);
	glVertex2f(1300, 330);
	glVertex2f(1300, 300);
	glEnd();
}

/*
* Scene 3 - Meeting Room
*/
//All KG functions refer to this
void meetingRoom() {
	// Background
	glClearColor(0.05, 0.05, 0.05, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);

	KG_drawCeiling();
	KG_drawSideWall();
	KG_drawCentreWall();
	KG_drawFloor();

	KG_drawOutside();

	KG_drawDoor();

	KG_drawBlackboard();

	// Receptionist
	drawWoman(0, 0, 1, 1,
		60, 60, 60,
		229, 49, 49, // top
		37, 107, 202, // ribbon
		229, 49, 49 // skirt
	);

	KG_drawDesks();

	KG_drawDevHead(0, 0);
	KG_drawDevHead(140, 0);
	KG_drawDevHead(460, 0);
	KG_drawDevHead(600, 0);

	print("A",
		0, 0, 0, kg_a_fade, 600, 440, .3, .3, 3);

	print("- Website",
		0, 0, 0, kg_apple_fade, 655, 445, .2, .2, 1);

	print("B",
		0, 0, 0, kg_b_fade, 600, 380, .3, .3, 3);

	print("- Mobile App",
		0, 0, 0, kg_ball_fade, 655, 385, .2, .2, 1);

	print("The team sits together and discusses the set requirments.",
		1, 1, 1, t_subtitle_1_appear, 300, 30 + t_subtitle_1_done, .14, .14, 1);
}
//Draws the ceiling and border for meeting room
void KG_drawCeiling() {
	// Ceiling
	glBegin(GL_POLYGON);
	glColor3ub(166, 148, 124); // Dark Brown
	glVertex2f(0, 800);
	glColor3ub(251, 242, 233); // Light Brown
	glVertex2f(200, 700);
	glColor3ub(251, 242, 233); // Light Brown
	glVertex2f(1400, 700);
	glColor3ub(166, 148, 124); // Dark Brown
	glVertex2f(1400, 800);
	glEnd();

	// Border for Ceiling
	glLineWidth(2);
	glBegin(GL_LINE_LOOP);
	glColor3ub(0, 0, 0); // Black
	glVertex2f(0, 800);
	glVertex2f(200, 700);
	glVertex2f(1400, 700);
	glVertex2f(1400, 800);
	glEnd();
	glLineWidth(1);
}
//Draws the side wall for meeting room
void KG_drawSideWall() {
	// Side Wall
	glBegin(GL_POLYGON);
	glColor3ub(166, 148, 124); // Dark Brown
	glVertex2f(0, 800);
	glColor3ub(251, 242, 233); // Light Brown
	glVertex2f(200, 700);
	glColor3ub(251, 242, 233); // Light Brown
	glVertex2f(200, 175);
	glColor3ub(166, 148, 124); // Dark Brown
	glVertex2f(0, 75);
	glEnd();

	// Border for side wall
	glLineWidth(2);
	glBegin(GL_LINE_LOOP);
	glColor3ub(0, 0, 0); // Black
	glVertex2f(0, 800);
	glVertex2f(200, 700);
	glVertex2f(200, 175);
	glVertex2f(0, 75);
	glEnd();
	glLineWidth(1);
}
//Draws the centre wall for meeting room
void KG_drawCentreWall() {
	// Centre Wall
	glBegin(GL_POLYGON);
	glColor3ub(251, 242, 233); // Light Brown
	glVertex2f(200, 700);
	glColor3ub(251, 242, 233); // Light Brown
	glVertex2f(1400, 700);
	glColor3ub(166, 148, 124); // Dark Brown
	glVertex2f(1400, 175);
	glColor3ub(166, 148, 124); // Dark Brown
	glVertex2f(200, 175);
	glEnd();

	// Border for Centre Wall
	glLineWidth(2);
	glBegin(GL_LINE_LOOP);
	glColor3ub(0, 0, 0); // Black
	glVertex2f(200, 700);
	glVertex2f(1400, 700);
	glVertex2f(1400, 175);
	glVertex2f(200, 175);
	glEnd();
	glLineWidth(1);
}
//Draws the floor for meeting room
void KG_drawFloor() {
	// Floor
	glBegin(GL_POLYGON);
	glColor3ub(166, 148, 124); // Dark Brown
	glVertex2f(200, 175);
	glVertex2f(1400, 175);
	glVertex2f(1400, 75);
	glVertex2f(0, 75);
	glEnd();

	// Border for Floor
	glLineWidth(2);
	glBegin(GL_LINE_LOOP);
	glColor3ub(0, 0, 0); // Black
	glVertex2f(200, 175);
	glVertex2f(1400, 175);
	glVertex2f(1400, 75);
	glVertex2f(0, 75);
	glEnd();
	glLineWidth(1);
}
//Draws the outside background for meeting room
void KG_drawOutside() {
	// Outside
	glBegin(GL_POLYGON);
	glColor3ub(12, 172, 232); // Sky Blue
	glVertex2f(0, 600);
	glVertex2f(180, 540);
	glColor3ub(82, 163, 42); // Green Grass
	glVertex2f(180, 165);
	glVertex2f(0, 75);
	glEnd();
}
//Draws the door for meeting room
void KG_drawDoor() {
	// Door Hinges
	glLineWidth(6);
	glBegin(GL_LINE_LOOP);
	glColor3ub(63, 36, 19); // Chocolate Brown
	glVertex2f(0, 600);
	glVertex2f(180, 540);
	glVertex2f(180, 165);
	glVertex2f(0, 75);
	glEnd();
	glLineWidth(1);

	// Door
	glBegin(GL_POLYGON);
	glColor3ub(63, 36, 19); // Chocolate Brown
	glVertex2f(180, 540);
	glVertex2f(30, 520);
	glVertex2f(30, 180);
	glVertex2f(180, 165);
	glEnd();

	// Door Knob
	drawCircle(45, 350,
		223, 189, 31, // Goldish Yellow
		1, 1,
		5);
}
//Draws head
//TX and TY are the x/y coordinates of the object
void KG_drawDevHead(GLfloat tx, GLfloat ty) {
	glPushMatrix();

	glTranslatef(tx, ty, 0);

	// Face
	drawCircle(480, 110,
		232, 190, 123, // Lighter Skin
		1, 1,
		25);

	int hair_line;

	// Hair Strands
	hair_line = 400;
	glLineWidth(100);
	glBegin(GL_LINES);
	glColor3ub(20, 20, 20); // Almost Black
	glVertex2f(hair_line + 60, 138);
	glVertex2f(hair_line + 65, 128);

	glVertex2f(hair_line + 70, 140);
	glVertex2f(hair_line + 75, 130);

	glVertex2f(hair_line + 80, 140);
	glVertex2f(hair_line + 85, 130);

	glVertex2f(hair_line + 90, 138);
	glVertex2f(hair_line + 95, 128);
	glEnd();
	glLineWidth(1);

	glPopMatrix();
}
//Draws the blackboard for meeting room
void KG_drawBlackboard() {
	// Blackboard
	glBegin(GL_POLYGON);
	glColor3ub(255, 255, 255); // white colour
	glVertex2f(450, 540);
	glVertex2f(1100, 540);
	glVertex2f(1100, 300);
	glVertex2f(450, 300);
	glEnd();

	// Blackboard Border
	glLineWidth(10);
	glBegin(GL_LINE_LOOP);
	glColor3ub(63, 36, 19); // Chocolate Brown
	glVertex2f(450, 540);
	glVertex2f(1100, 540);
	glVertex2f(1100, 300);
	glVertex2f(450, 300);
	glEnd();
	glLineWidth(1);
}
// Draws the desks for meeting room
void KG_drawDesks() {
	// Left Desk
	glBegin(GL_POLYGON);
	glColor3ub(138, 82, 32); // Wood Brown
	glVertex2f(400, 150);
	glVertex2f(700, 150);
	glVertex2f(730, 120);
	glVertex2f(370, 120);
	glEnd();

	// Left Desk Edge
	glBegin(GL_POLYGON);
	glColor3ub(122, 76, 29); // Wood Dark Brown
	glVertex2f(370, 120);
	glVertex2f(370, 115);
	glVertex2f(730, 115);
	glVertex2f(730, 120);
	glEnd();

	// Right Desk
	glBegin(GL_POLYGON);
	glColor3ub(138, 82, 32); // Wood Brown
	glVertex2f(850, 150);
	glVertex2f(1150, 150);
	glVertex2f(1180, 120);
	glVertex2f(820, 120);
	glEnd();

	// Right's Desk Edge
	glBegin(GL_POLYGON);
	glColor3ub(122, 76, 29); // Wood Dark Brown
	glVertex2f(820, 120);
	glVertex2f(820, 115);
	glVertex2f(1180, 115);
	glVertex2f(1180, 120);
	glEnd();
}

/*
*	Scene 4 - Developers working
*/
//All PUC functions refer to this
void workingStation() {
	// Background
	glClearColor(0.05, 0.05, 0.05, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);

	PUC_drawFloor();
	PUC_drawCentreWall();
	PUC_drawCeiling();

	PUC_drawLeftWall();
	PUC_drawRightWall();

	PUC_drawLeftDoors();
	PUC_drawRightDoors();
	PUC_drawBoard();

	// Black Shirt Person
	drawSchoolBoy(trans_x_sb1, trans_y_sb1,
		1.4, 1.4,
		0, 0, 0);

	// Green Shirt Person
	drawSchoolBoy(trans_x_sb2, trans_y_sb2,
		-1.4, 1.4,
		0, 255, 0);

	print("Each developer will each work on their assigned task.",
		1, 1, 1, puc_subtitle_1_fade, 300, 30, .14, .14, 1);
}
//Draws floor for the developers working
void PUC_drawFloor() {
	// Floor
	glBegin(GL_POLYGON);
	glColor3ub(225, 215, 205);
	glVertex2f(0, 75);
	glVertex2f(1400, 75);
	glColor3ub(210, 193, 179);
	glVertex2f(775, 200);
	glVertex2f(625, 200);
	glEnd();

	// Floor Border
	glBegin(GL_LINE_LOOP);
	glColor3ub(20, 20, 20);
	glVertex2f(0, 75);
	glVertex2f(1400, 75);
	glVertex2f(775, 200);
	glVertex2f(625, 200);
	glEnd();
}
//Draws centre wallfor the developers working
void PUC_drawCentreWall() {
	// Centre Wall
	glBegin(GL_POLYGON);
	glColor3ub(230, 230, 230);
	glVertex2f(625, 200);
	glVertex2f(775, 200);
	glVertex2f(775, 450);
	glVertex2f(625, 450);
	glEnd();

	// Centre Wall Border
	glBegin(GL_LINE_LOOP);
	glColor3ub(20, 20, 20);
	glVertex2f(625, 200);
	glVertex2f(775, 200);
	glVertex2f(775, 450);
	glVertex2f(625, 450);
	glEnd();

	// Centre Wall Strip
	glBegin(GL_POLYGON);
	glColor3ub(0, 130, 255);
	glVertex2f(625, 200);
	glVertex2f(775, 200);
	glVertex2f(775, 207.81);
	glVertex2f(625, 207.81);
	glEnd();

	// Centre Wall Strip Border
	glBegin(GL_LINE_LOOP);
	glColor3ub(20, 20, 20);
	glVertex2f(625, 200);
	glVertex2f(775, 200);
	glVertex2f(775, 207.81);
	glVertex2f(625, 207.81);
	glEnd();
}
//Draws ceiling for the developers working
void PUC_drawCeiling() {
	// Ceiling
	glBegin(GL_POLYGON);
	glColor3ub(230, 230, 230);
	glVertex2f(625, 450);
	glVertex2f(775, 450);
	glColor3ub(240, 240, 240);
	glVertex2f(1400, 800);
	glVertex2f(0, 800);
	glEnd();

	// Ceiling Border
	glBegin(GL_LINE_LOOP);
	glColor3ub(20, 20, 20);
	glVertex2f(625, 450);
	glVertex2f(775, 450);
	glVertex2f(1400, 800);
	glVertex2f(0, 800);
	glEnd();
}
//Draws left wall for the developers working
void PUC_drawLeftWall() {
	// Left Wall
	glBegin(GL_POLYGON);
	glColor3ub(240, 240, 240);
	glVertex2f(0, 75);
	glVertex2f(625, 200);
	glVertex2f(625, 450);
	glVertex2f(0, 800);
	glEnd();

	// Left Wall Border
	glBegin(GL_LINE_LOOP);
	glColor3ub(20, 20, 20);
	glVertex2f(0, 75);
	glVertex2f(625, 200);
	glVertex2f(625, 450);
	glVertex2f(0, 800);
	glEnd();

	// Left Wall Bottom Strip
	glBegin(GL_POLYGON);
	glColor3ub(0, 130, 255);
	glVertex2f(0, 75);
	glVertex2f(625, 200);
	glVertex2f(625, 207.81);
	glVertex2f(0, 100);
	glEnd();

	// Left Wall Bottom Strip Border
	glBegin(GL_LINE_LOOP);
	glColor3ub(20, 20, 20);
	glVertex2f(0, 75);
	glVertex2f(625, 200);
	glVertex2f(625, 207.81);
	glVertex2f(0, 100);
	glEnd();
}
//Draws right wall for the developers working
void PUC_drawRightWall() {
	// Right Wall
	glBegin(GL_POLYGON);
	glColor3ub(240, 240, 240);
	glVertex2f(775, 200);
	glVertex2f(1400, 75);
	glVertex2f(1400, 800);
	glVertex2f(775, 450);
	glEnd();

	// Right Wall Border
	glBegin(GL_LINE_LOOP);
	glColor3ub(20, 20, 20);
	glVertex2f(775, 200);
	glVertex2f(1400, 75);
	glVertex2f(1400, 800);
	glVertex2f(775, 450);
	glEnd();

	// Right Wall Bottom Strip
	glBegin(GL_POLYGON);
	glColor3ub(0, 130, 255);
	glVertex2f(1400, 75);
	glVertex2f(1400, 100);
	glVertex2f(775, 207.81);
	glVertex2f(775, 200);
	glEnd();

	// Right Wall Bottom Strip Border
	glBegin(GL_LINE_LOOP);
	glColor3ub(20, 20, 20);
	glVertex2f(1400, 75);
	glVertex2f(1400, 100);
	glVertex2f(775, 207.81);
	glVertex2f(775, 200);
	glEnd();
}
//Draws left doors for the developers working
void PUC_drawLeftDoors() {
	// First Door
	glBegin(GL_POLYGON);
	glColor3ub(210, 210, 210);
	glVertex2f(150, 104);
	glVertex2f(350, 144);
	glVertex2f(350, 481);
	glVertex2f(150, 548);
	glEnd();

	// First Door Border
	glBegin(GL_LINE_LOOP);
	glColor3ub(20, 20, 20);
	glVertex2f(150, 104);
	glVertex2f(350, 144);
	glVertex2f(350, 481);
	glVertex2f(150, 548);
	glEnd();

	// First Wooden Door
	glBegin(GL_POLYGON);
	glColor3ub(63, 36, 19);
	glVertex2f(150, 104);
	glVertex2f(335, 158);
	glVertex2f(335, 472);
	glVertex2f(150, 548);
	glEnd();

	// First Wooden Door Border
	glBegin(GL_LINE_LOOP);
	glColor3ub(20, 20, 20);
	glVertex2f(150, 104);
	glVertex2f(335, 158);
	glVertex2f(335, 472);
	glVertex2f(150, 548);
	glEnd();

	// PCMB
	glBegin(GL_POLYGON);
	glColor3ub(255, 255, 255);
	glVertex2f(140, 520);
	glVertex2f(140, 490);
	glVertex2f(250, 490);
	glVertex2f(250, 520);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3ub(20, 20, 20);
	glVertex2f(140, 520);
	glVertex2f(140, 490);
	glVertex2f(250, 490);
	glVertex2f(250, 520);
	glEnd();

	drawCircle(138, 510, 100, 100, 100, 1, 1, 3);
	drawCircle(142, 510, 100, 100, 100, 1, 1, 3);

	drawCircle(138, 499, 100, 100, 100, 1, 1, 3);
	drawCircle(142, 499, 100, 100, 100, 1, 1, 3);

	print("Website",
		0, 0, 0, 1, 160, 500, .1, .1, 2);

	// Door Knob
	drawCircle(320, 300,
		223, 189, 31, // Goldish Yellow
		1, 1,
		5);
}
//Draws right doors for the developers working
void PUC_drawRightDoors() {
	// First Door
	glBegin(GL_POLYGON);
	glColor3ub(210, 210, 210);
	glVertex2f(1049, 144);
	glVertex2f(1250, 104);
	glVertex2f(1250, 548);
	glVertex2f(1049, 481);
	glEnd();

	// First Door Border
	glBegin(GL_LINE_LOOP);
	glColor3ub(20, 20, 20);
	glVertex2f(1049, 144);
	glVertex2f(1250, 104);
	glVertex2f(1250, 548);
	glVertex2f(1049, 481);
	glEnd();

	// First Wooden Door
	glBegin(GL_POLYGON);
	glColor3ub(63, 36, 19);
	glVertex2f(1250, 104);
	glVertex2f(1065, 158);
	glVertex2f(1065, 472);
	glVertex2f(1250, 548);
	glEnd();

	// First Wooden Door Border
	glBegin(GL_LINE_LOOP);
	glColor3ub(20, 20, 20);
	glVertex2f(1250, 104);
	glVertex2f(1065, 158);
	glVertex2f(1065, 472);
	glVertex2f(1250, 548);
	glEnd();

	// PCMC
	glBegin(GL_POLYGON);
	glColor3ub(255, 255, 255);
	glVertex2f(1260, 520);
	glVertex2f(1260, 490);
	glVertex2f(1150, 490);
	glVertex2f(1150, 520);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3ub(20, 20, 20);
	glVertex2f(1260, 520);
	glVertex2f(1260, 490);
	glVertex2f(1150, 490);
	glVertex2f(1150, 520);
	glEnd();

	drawCircle(1258, 510, 100, 100, 100, 1, 1, 3);
	drawCircle(1262, 510, 100, 100, 100, 1, 1, 3);

	drawCircle(1258, 499, 100, 100, 100, 1, 1, 3);
	drawCircle(1262, 499, 100, 100, 100, 1, 1, 3);

	print("Mobile App",
		0, 0, 0, 1, 1155, 500, .1, .1, 2);

	// Door Knob
	drawCircle(1080, 300,
		223, 189, 31, // Goldish Yellow
		1, 1,
		5);
}
//Draws board for the developers working
void PUC_drawBoard() {
	// Board Hanging Line
	glLineWidth(4);
	glBegin(GL_LINES);
	glColor3ub(20, 20, 20);
	glVertex2f(550, 800);
	glVertex2f(550, 750);
	glVertex2f(850, 800);
	glVertex2f(850, 750);
	glEnd();
	glLineWidth(1);

	// Board Border
	glBegin(GL_POLYGON);
	glColor3ub(20, 20, 20);
	glVertex2f(450, 750);
	glVertex2f(450, 600);
	glVertex2f(950, 600);
	glVertex2f(950, 750);
	glEnd();

	// Board
	glBegin(GL_POLYGON);
	glColor3ub(200, 131, 255);
	glVertex2f(452, 748);
	glColor3ub(200, 104, 204);
	glVertex2f(452, 602);
	glVertex2f(948, 602);
	glColor3ub(200, 131, 255);
	glVertex2f(948, 748);
	glEnd();

	print("J A M I N A T I O N",
		1, 1, 1, 1, 505, 690, .2, .2, 4);

	print("Work Station",
		1, 1, 1, 1, 600, 660, .15, .15, 2);
}


/*
*	Scene 5 - Developer in workplace
*/
// All WP functions above refer to this
void workplace() {
	// Background
	glClearColor(0.05, 0.05, 0.05, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);

	WP_drawFloor();
	WP_drawSideWall();
	WP_drawWall();

	WP_drawTechie();
	WP_drawTable();
	WP_drawComputer();

	WP_drawAC();
	WP_drawServerBox();

	WP_drawThoughtBubble();

	print("The client's full satisfaction is our first and only priority.",
		1, 1, 1, wp_subtitle_1_fade, 35, 30, .14, .14, 1);
}
// Floor under working developer
void WP_drawFloor() {
	glBegin(GL_POLYGON);
	glColor3ub(80, 80, 80);
	glVertex2f(0, 75);
	glVertex2f(1400, 75);
	glVertex2f(1400, 150);
	glVertex2f(50, 150);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3ub(20, 20, 20);
	glVertex2f(0, 75);
	glVertex2f(1400, 75);
	glVertex2f(1400, 150);
	glVertex2f(50, 150);
	glEnd();
}
// Side wall next to working developer
void WP_drawSideWall() {
	glBegin(GL_POLYGON);
	glColor3ub(180, 180, 180);
	glVertex2f(0, 75);
	glVertex2f(50, 150);
	glVertex2f(50, 800);
	glVertex2f(0, 800);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3ub(20, 20, 20);
	glVertex2f(0, 75);
	glVertex2f(50, 150);
	glVertex2f(50, 800);
	glVertex2f(0, 800);
	glEnd();
}
// Wall next to working developer
void WP_drawWall() {
	glBegin(GL_POLYGON);
	glColor3ub(200, 200, 200);
	glVertex2f(50, 150);
	glVertex2f(1400, 150);
	glVertex2f(1400, 800);
	glVertex2f(50, 800);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3ub(20, 20, 20);
	glVertex2f(50, 150);
	glVertex2f(1400, 150);
	glVertex2f(1400, 800);
	glVertex2f(50, 800);
	glEnd();
}
// Table for working developer
void WP_drawTable() {
	// Table - Front Face
	glBegin(GL_POLYGON);
	glColor3ub(96, 48, 13);
	glVertex2f(100, 100);
	glVertex2f(500, 100);
	glVertex2f(500, 250);
	glVertex2f(100, 250);
	glEnd();

	// Table - Top Face
	glBegin(GL_POLYGON);
	glColor3ub(81, 39, 8);
	glVertex2f(100, 250);
	glVertex2f(500, 250);
	glVertex2f(525, 275);
	glVertex2f(125, 275);
	glEnd();

	// Table - Side Face
	glBegin(GL_POLYGON);
	glColor3ub(58, 28, 6);
	glVertex2f(500, 100);
	glVertex2f(525, 150);
	glVertex2f(525, 275);
	glVertex2f(500, 250);
	glEnd();
}
// Tech person in the working developer scene
void WP_drawTechie() {
	drawCircle(300, 380,
		203, 166, 108,
		1, 1.2,
		30);

	drawSemiCircle(300, 400, 1, .6,
		20, 20, 20,
		32, -90, 90);
	drawSemiCircle(320, 390, .6, .6,
		20, 20, 20,
		35, 0, 180);

	// Left Eye
	drawCircle(298, 383,
		255, 255, 255,
		1, 1,
		5);
	drawCircle(297, 382,
		20, 20, 20,
		1, 1,
		2);

	// Right Eye
	drawCircle(278, 383,
		255, 255, 255,
		1, 1,
		5);
	drawCircle(277, 382,
		20, 20, 20,
		1, 1,
		2);

	// Body
	drawCircle(300, 275,
		200, 40, 40,
		.6, .8,
		80);
}
// Computer for working developer
void WP_drawComputer() {
	// Monitor
	glBegin(GL_POLYGON);
	glColor3ub(80, 80, 80);
	glVertex2f(210, 280);
	glVertex2f(400, 280);
	glVertex2f(400, 380);
	glVertex2f(210, 380);
	glEnd();

	// Monitor Logo
	drawCircle(300, 325,
		40, 40, 40,
		1, 1,
		10);

	// Monitor Stand
	glBegin(GL_POLYGON);
	glColor3ub(20, 20, 20);
	glVertex2f(290, 280);
	glVertex2f(280, 260);
	glVertex2f(320, 260);
	glVertex2f(310, 280);
	glEnd();

	// Mouse
	drawSemiCircle(240, 262, 1, 1,
		150, 150, 150,
		10, -90, 91);
}
// Air Conditioner above the working developer
void WP_drawAC() {
	glBegin(GL_POLYGON);
	glColor3ub(255, 255, 255);
	glVertex2f(300, 675);
	glVertex2f(700, 675);
	glVertex2f(700, 750);
	glVertex2f(300, 750);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(240, 240, 240);
	glVertex2f(300, 675);
	glVertex2f(310, 660);
	glVertex2f(710, 660);
	glVertex2f(700, 675);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(230, 230, 230);
	glVertex2f(700, 750);
	glVertex2f(710, 720);
	glVertex2f(710, 660);
	glVertex2f(700, 675);
	glEnd();

	glLineWidth(3);
	glBegin(GL_LINES);
	glColor3ub(150, 150, 150);
	glVertex2f(320, 666);
	glVertex2f(690, 666);
	glEnd();
	glLineWidth(1);
}
// Server's light next to working developer
//TX and TY are the x/y coordinates of the object
//Light R, Light G, and Light B refer to the colour of the light in RGB, when on
void WP_drawServerLight(GLfloat tx, GLfloat ty,
	//GLfloat light_r, GLfloat light_g, GLfloat light_b,
	//bool light_on) {
	//glPushMatrix();
	glTranslatef(tx, ty, 0);

	//glBegin(GL_POLYGON);
	if (light_on)
		glColor3ub(light_r, light_g, light_b);
	else
		glColor3ub(30, 30, 30);
	//glVertex2f(0, 0);
	glVertex2f(6, 0);
	glVertex2f(6, 6);
	glVertex2f(0, 6);
	glEnd();

	glPopMatrix();
}
// Server next to working developer
// TX and TY are the x/y coordinates of the object
// Whether or not it's on will affect the lighting
void WP_drawServer(GLfloat tx, GLfloat ty,
	bool server_on) {
	glPushMatrix();
	glTranslatef(tx, ty, 0);

	// Server
	//glBegin(GL_POLYGON);
	//glColor3ub(30, 30, 30);
	glVertex2f(960, 460);
	glVertex2f(1200, 460);
	glVertex2f(1200, 530);
	glVertex2f(960, 530);
	glEnd();

	//if (server_on) {
	//	drawCircle(990, 492,
			255, 255, 0,
			1, 1, 3);
	}

	//WP_drawServerLight(1100, 492, 246, 233, 192, light_a);
	//WP_drawServerLight(1125, 492, 243, 201, 32, light_b);
	//WP_drawServerLight(1150, 492, 255, 167, 50, light_c);
	//WP_drawServerLight(1175, 492, 21, 123, 193, light_d);

	glPopMatrix();
}
// Server box next to working developer
// TX and TY are the x/y coordinates of the object
void WP_drawServerInnerBox(GLfloat tx, GLfloat ty) {
	glPushMatrix();
	glTranslatef(tx, ty, 0);

	// Server Inner Box Back Wall
	glBegin(GL_POLYGON);
	glColor3ub(200, 200, 200);
	glVertex2f(920, 450);
	glVertex2f(1400, 450);
	glVertex2f(1400, 580);
	glVertex2f(920, 580);
	glEnd();
/*
	// Server Inner Box Side Wall
	glBegin(GL_POLYGON);
	glColor3ub(180, 180, 180);
	glVertex2f(920, 450);
	glVertex2f(945, 475);
	glVertex2f(945, 580);
	glVertex2f(920, 580);
	glEnd();

	// Server Inner Box Floor
	glBegin(GL_POLYGON);
	glColor3ub(160, 160, 160);
	glVertex2f(920, 450);
	glVertex2f(1400, 450);
	glVertex2f(1400, 475);
	glVertex2f(945, 475);
	glEnd();

	WP_drawServer(0, 0, !server_on);
	WP_drawServer(280, 0, server_on);

	glPopMatrix();
}
// Server box next to working developer
void WP_drawServerBox() {
	// Server Box
	glBegin(GL_POLYGON);
	glColor3ub(60, 60, 60);
	glVertex2f(900, 100);
	glVertex2f(1400, 100);
	glVertex2f(1400, 600);
	glVertex2f(900, 600);
	glEnd();

	// Server Box Top
	glBegin(GL_POLYGON);
	glColor3ub(30, 30, 30);
	glVertex2f(900, 600);
	glVertex2f(1400, 600);
	glVertex2f(1400, 610);
	glVertex2f(925, 610);
	glEnd();

	WP_drawServerInnerBox(0, 0);
}
*/
// Thought Bubble for when the developer is working next to the server
void WP_drawThoughtBubble() {
	// Thought Bubble leads to...
	drawCircle(365, 410, 240, 240, 240, 1, 1, wp_tb_s1);
	drawCircle(400, 430, 240, 240, 240, 1, 1, wp_tb_s2);
	drawCircle(435, 450, 240, 240, 240, 1, 1, wp_tb_s3);

	// Thought Bubble
	drawCircle(500, 480, 240, 240, 240, 1, 1, wp_tb_big);
	drawCircle(540, 500, 240, 240, 240, 1, 1, wp_tb_big);
	drawCircle(580, 500, 240, 240, 240, 1, 1, wp_tb_big);
	drawCircle(620, 500, 240, 240, 240, 1, 1, wp_tb_big);
	drawCircle(660, 500, 240, 240, 240, 1, 1, wp_tb_big);
	drawCircle(700, 480, 240, 240, 240, 1, 1, wp_tb_big);
	drawCircle(540, 460, 240, 240, 240, 1, 1, wp_tb_big);
	drawCircle(580, 460, 240, 240, 240, 1, 1, wp_tb_big);
	drawCircle(620, 460, 240, 240, 240, 1, 1, wp_tb_big);
	drawCircle(660, 460, 240, 240, 240, 1, 1, wp_tb_big);

	// Text inside Thought Bubble
	print("Will the customer be comfortable",
		0, 0, 0, wp_tb_text, 480, 480, .075, .075, 1);

	print("using this software?",
		0, 0, 0, wp_tb_text, 505, 460, .075, .075, 1);
}

/*
*	Scene 6 - The final window
*/
void end()
{
	int i, submenu;
	//Creates a new window that displays the spinning logo "JAMINATION"
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(1400, 800);
	glutCreateWindow("JAMINATION");
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 2000, 0, 2000);
	glMatrixMode(GL_MODELVIEW);
	glEnable(GL_LINE_SMOOTH);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glLineWidth(3.0);
	glTranslatef(1000, 1000, 0);
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glColor3f(1.0, 1.0, 1.0);
	glutDisplayFunc(display);
	glutIdleFunc(tick);
	submenu = glutCreateMenu(selectMessage);
	glutAddMenuEntry("abc", 1);
	glutAddMenuEntry("ABC", 2);
	glutCreateMenu(selectFont);
	glutAddMenuEntry("Roman", 0);
	glutAddMenuEntry("Mono Roman", 1);
	glutAddSubMenu("Messages", submenu);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutMainLoop();
}





// Function to Render Scene
void renderScene() {
	// Switch to know which scene is playing
	switch (SCENE_ID) {
	case 0:
		//render introduction
		introduction();
		break;
	case 1:
		//render the client on their way
		clientComing();
		break;

	case 2:
		//render the client reaching their destination
		clientComes();
		break;
	case 3:
		//render the meeting room
		meetingRoom();
		break;
	case 4:
		//render the working station
		workingStation();
		break;
	case 5:
		//render the work place
		workplace();
		break;
	case 6:
		//change SCENE_ID as to not call the "end" method, which creates a new window, again
		SCENE_ID = 7;
		//end the animation on scene 6
		end();
		break;
	case 7:
		//If the user clicks back to the main scene after the new window popped up, end the program.
		exit(0);
		break;
	default:
		break;
	}

	// glFush sends it to the Display Buffer
	glFlush();
}
// Animator Update Function
// Times and changes scenes
void update(int) {
	//introduction();
	if (SCENE_ID == 0) {
		//How much opacity for the title to be drawn in
		if (title_fade < 1)
			title_fade += .003;
		else
			//Make the next message appear
			intro_next_text_appear = 1;
	}
	//clientComing();
	if (SCENE_ID == 1) {
		if (trans_x_ec_sb1 >= -180)
			trans_x_ec_sb1 -= 4;
		if (trans_x_ec_sb2 >= -2050)
			trans_x_ec_sb2 -= 4;

		if (trans_x_ec_sb1 <= -180 && trans_x_ec_sb2 <= -2050 && !ec_graduation_done) {
			trans_y_ec_sb += 1000;
			ec_graduation_done = true;

			SCENE_ID++;
		}

		if (ec_subtitle_1_fade < 1)
			ec_subtitle_1_fade += .005;
	}
	//clientComes();
	if (SCENE_ID == 2) {
		if (trans_x_guy2 < wp_tb_big)
			trans_x_guy2 += .3;

		if (ps_subtitle_1_appear < 1)
			ps_subtitle_1_appear += .005;
		else {
			if (ps_subtitle_2_appear < 1) {
				trans_subtitle_1_done = 200;
				ps_subtitle_2_appear += .005;
			}
			else if (ps_subtitle_3_appear < 1)
			{
				trans_subtitle_2_done = 200;
				ps_subtitle_3_appear += .005;
			}
			else if (ps_subtitle_4_appear < 1)
			{
				trans_subtitle_3_done = 200;
				ps_subtitle_4_appear += .005;
			}
			else if (ps_subtitle_5_appear < 1)
			{
				trans_subtitle_4_done = 200;
				ps_subtitle_5_appear += .005;
			}
			else
			{
				Sleep(5000);
				SCENE_ID++;
			}
		}
	}
	//meetingRoom();
	//if (SCENE_ID == 3) {
	//	if (kg_a_fade < 1)
			kg_a_fade += .025;
		else
			if (kg_apple_fade < 1)
				kg_apple_fade += .025;
			else
				if (kg_b_fade < 1)
					kg_b_fade += .025;
				else
					if (kg_ball_fade < 1)
						kg_ball_fade += .025;
					else
						if (kg_soon_fade < 1)
							kg_soon_fade += .025;
						else
						{
							kg_subtitle_1_appear = 1;
							Sleep(2000);
							SCENE_ID++;
						}

		if (t_subtitle_1_appear < 1)
			t_subtitle_1_appear += .005;
	}
	//workingStation();
	//if (SCENE_ID == 4) {
		if (puc_subtitle_1_fade < 1)
			puc_subtitle_1_fade += 0.005;

		if (!puc_begin_anim) {
			delay(1);
			puc_begin_anim = true;
		}

		if (!puc_end_anim) {
			if (trans_x_sb1 >= -930)
				trans_x_sb1 -= 1;
			if (trans_y_sb1 <= -20)
				trans_y_sb1 += .1;

			if (trans_x_sb2 >= -1930)
				trans_x_sb2 -= 1;
			if (trans_y_sb2 <= -20)
				trans_y_sb2 += .1;

			if (trans_y_sb1 >= -20 && trans_y_sb2 >= -20)
			{
				puc_end_anim = true;
			}
		}

		if (puc_end_anim) {
			delay(1);

			if (trans_y_sb1 <= 5000)
				trans_y_sb1 += 5000;

			if (trans_y_sb2 <= 5000)
				trans_y_sb2 += 5000;

			SCENE_ID++;
		}
	}
	//workplace();
	if (SCENE_ID == 5) {
		if (server_on) {
			server_on = false;
		}
		else {
			server_on = true;
		}

		if (!wp_tb_s1_done) {
			if (wp_tb_s1 <= 10)
				wp_tb_s1 += .25;
			else
				wp_tb_s1_done = true;
		}

		//if (light_a) {
			light_a = false;
			light_b = true;
			light_c = false;
			light_d = false;
		}
		else if (light_b) {
			light_a = false;
			light_b = false;
			light_c = true;
			light_d = false;
		}
		else if (light_c) {
			light_a = false;
			light_b = false;
			light_c = false;
			light_d = true;
		}
		else {
			light_a = true;
			light_b = false;
			light_c = false;
			light_d = false;
		}

		if (wp_tb_s1_done && !wp_tb_s2_done) {
			if (wp_tb_s2 <= 12)
				wp_tb_s2 += .25;
			else
				wp_tb_s2_done = true;
		}

		if (wp_tb_s1_done && wp_tb_s2_done && !wp_tb_s3_done) {
			if (wp_tb_s3 <= 14)
				wp_tb_s3 += .25;
			else
				wp_tb_s3_done = true;
		}

		if (wp_tb_s1_done && wp_tb_s2_done && wp_tb_s3_done && !wp_tb_big_done) {
			if (wp_tb_big <= 30)
				wp_tb_big += .5;
			else
				wp_tb_big_done = true;
		}

		if (wp_tb_s1_done && wp_tb_s2_done && wp_tb_s3_done && wp_tb_big_done) {
			if (wp_tb_text <= 1)
				wp_tb_text += .005;

			if (wp_subtitle_1_fade <= 1)
				wp_subtitle_1_fade += .005;
			else
				SCENE_ID++;
		}
	}

	// Recalls the Display Function
	glutPostRedisplay();

	// Creates a Timer of 25ms
	glutTimerFunc(25, update, 0);
}
// Keyboard Action
void keyPress(unsigned char key, int x, int y) {
	switch (key) {
		// Go to Previous Scene
	case 'b':
	case 'B':
		if (SCENE_ID == 0)
			break;
		SCENE_ID--;
		break;
		// Go to Next Scene
	case 'n':
	case 'N':
		if (SCENE_ID == 15)
			break;
		SCENE_ID++;
		break;
		// Quit Story
	case 'q':
	case 'Q':
		exit(0);
		break;
	default:
		break;
	}

	glutPostRedisplay();
}
// Function to Initialize Screen
void initializeScreen() {
	//Setting render modes
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//Setting camera view
	gluOrtho2D(0, 1400, 0, 800);
}
// Main Function
// Initializing window and rendering
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(1400, 800);
	glutCreateWindow("JAMINATION");

	// Enables Transparency
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);

	// Enable Smoothening
	glEnable(GL_LINE_SMOOTH);
	glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);

	// Display Function
	glutDisplayFunc(renderScene);
	//renderScene will be called for display

	// Input Functions
	glutKeyboardFunc(keyPress);

	initializeScreen();

	// Timer Function
	// every 25 milliseconds, update function is called
	glutTimerFunc(25, update, 0);
	//update will be called for timing updates

	glutMainLoop();

	return 0;
}