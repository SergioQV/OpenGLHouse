#include "stdafx.h"
#include "RVScene.h"


RVScene::RVScene(GLuint *texturas)
{
	textures = texturas;
	bed = new RVBed();

}
RVScene::~RVScene(){
	delete bed;
}
void RVScene::Draw() {
	DrawGround();
	DrawFences();
	DrawContorno();
	DrawTecho();
	DrawSalon();
	DrawCocina();
	DrawPasillo();
	DrawBaño();
	DrawHabitacion1();
	DrawHabitacion2();
	DrawHabitacion3();
	DrawMarcos();
	DrawCamas();
	DrawVentanas();
}

//
// FUNCIÓN: RVScene::DrawGround()
//
// PROPÓSITO: Dibuja el suelo
//
void RVScene::DrawGround()
{

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textures[0]);
	glShadeModel(GL_FLAT);
	glBegin(GL_QUADS);

	//dibujamos el suelo normal
	for (GLfloat i = 100.0f; i > -100.0f; i-=20.0f)
	{
		for (GLfloat j = 200.0f; j > -200.0f; j-=20.0f)
		{
			if (!(i >= -60.0f && i <= 80.0f && j <= -20.0f && j >= -120.0f)) {
				glTexCoord2f(0.0f, 0.0f);
				glVertex3f(i, 0.0f, j);
				glTexCoord2f(0.0f, 1.0f);
				glVertex3f(i, 0.0f, j - 20.0f);
				glTexCoord2f(1.0f, 1.0f);
				glVertex3f(i - 20.0f, 0.0f, j - 20.0f);
				glTexCoord2f(1.0f, 0.0f);
				glVertex3f(i - 20.0f, 0.0f, j);
			}
		}
	}
	glEnd();

	// dibujamos el borde de la piscina
	glBindTexture(GL_TEXTURE_2D, textures[4]);

	glBegin(GL_QUADS);
	for (GLfloat i = 80.0f; i > -80.0f; i -= 10.0f) {
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(i, 0.0f, -20.0f);
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(i, 0.0f, -25.0f);
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(i - 10.0f , 0.0f, -25.0f);
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(i - 10.0f, 0.0f, -20.0f);

		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(i, 0.0f, -135.0f);
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(i, 0.0f, -140.0f);
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(i - 10.0f, 0.0f, -140.0f);
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(i - 10.0f, 0.0f, -135.0f);
	}

	for (GLfloat i = -25.0f; i > -135.0f; i -= 10.0f) {
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(80.0f, 0.0f, i);
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(80.0f, 0.0f, i -10.0f);
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(75.0f, 0.0f, i - 10.0f);
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(75.0f, 0.0f, i);

		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(-75.0f, 0.0f, i); 
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(-75.0f, 0.0f, i - 10.0f);
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(-80.0f, 0.0f, i - 10.0f);
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(-80.0f, 0.0f, i);
	}
	glEnd();

	// dibujamos el agua
	glBindTexture(GL_TEXTURE_2D, textures[3]);
	glBegin(GL_QUADS);
	for (GLfloat i = 75.0f; i > -75.0f; i -= 10.0f)
	{
		for (GLfloat j = -25.0f; j > -135.0f; j -= 10.0f)
		{
			glTexCoord2f(0.0f, 0.0f);
			glVertex3f(i, 0.0f, j);
			glTexCoord2f(0.0f, 1.0f);
			glVertex3f(i, 0.0f, j - 10.0f);
			glTexCoord2f(1.0f, 1.0f);
			glVertex3f(i - 10.0f, 0.0f, j - 10.0f);
			glTexCoord2f(1.0f, 0.0f);
			glVertex3f(i - 10.0f, 0.0f, j);
			
		}
	}
	glEnd();
	glDisable(GL_TEXTURE_2D);

}


//
// FUNCIÓN: RVScene::DrawFences()
//
// PROPÓSITO: Dibuja unas vallas que delimitan la parcela
//
void RVScene::DrawFences()
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textures[1]);
	glShadeModel(GL_FLAT);
	glBegin(GL_QUADS);

	for (GLfloat i = 100.0f; i > -100.0f; i -= 20.f) 
	{
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(i, 0.0f, 200.0f);
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(i -20.0f, 0.0f, 200.0f);
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(i - 20.0f, 15.0f, 200.0f);
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(i, 15.0f, 200.0f);

		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(i, 0.0f, -200.0f);
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(i, 15.0f, -200.0f);
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(i - 20.0f, 15.0f, -200.0f);
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(i - 20.0f, 0.0f, -200.0f);
	}

	for (GLfloat i = 200.0f; i > -200.0f; i -= 20.f)
	{
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(-100.0f, 0.0f, i);
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(-100.0f, 0.0f, i - 20.0f);
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(-100.0f, 15.0f, i - 20.0f);
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(-100.0f, 15.0f, i);

		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(100.0f, 0.0f, i);
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(100.0f, 15.0f, i);
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(100.0f, 15.0f, i - 20.0f);
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(100.0f, 0.0f, i - 20.0f);
	}

	glEnd();
	glDisable(GL_TEXTURE_2D);

}

//
// FUNCIÓN: RVScene::DrawContorno()
//
// PROPÓSITO: Dibuja las vista exterior de la vivienda
//
void RVScene::DrawContorno()
{

	
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textures[2]);
	glShadeModel(GL_FLAT);
	glBegin(GL_QUADS);

	// muros este y oeste
	for (GLfloat y = 30.0f; y > 0.0f; y -= 5.0f)
	{
		for (GLfloat z = 130.9f; z > 71.1f; z -= 5.0f)
		{
			if (!(y <= 25.0f && y > 5.0f && z <= 100.1f)) {
				glTexCoord2f(0.0f, 0.0f);
				glVertex3f(61.15f, y, z);
				glTexCoord2f(0.0f, 1.0f);
				glVertex3f(61.15f, y - 5.0f, z);
				glTexCoord2f(1.0f, 1.0f);
				glVertex3f(61.15f, y - 5.0f, z - 5.0f);
				glTexCoord2f(1.0f, 0.0f);
				glVertex3f(61.15f, y, z - 5.0f);
			}

			glTexCoord2f(0.0f, 0.0f);
			glVertex3f(-61.15f, y, z);
			glTexCoord2f(1.0f, 0.0f);
			glVertex3f(-61.15f, y, z - 5.0f);
			glTexCoord2f(1.0f, 1.0f);
			glVertex3f(-61.15f, y - 5.0f, z - 5.0f);
			glTexCoord2f(0.0f, 1.0f);
			glVertex3f(-61.15f, y-5.0f, z);
		}
	}

	//muros norte y sur
	for (GLfloat y = 30.0f; y > 0.0f; y -= 5.0f)
	{
		for (GLfloat x = 61.15f; x > -61.15f; x -= 5.0f)
		{
			if (!((x <= 16.95f && x >= 7.05f && y <= 20.0f) || (x <= -12.05f && x >= -19.75f && y <= 20.0f && y >= 15.0f) 
				|| (x <= -43.75 && x >= -51.45 && y <= 20.0f && y >= 15.0f)) ) {
				if (x > -58.85f) {
					glTexCoord2f(0.0f, 0.0f);
					glVertex3f(x, y, 130.9f);
					glTexCoord2f(1.0f, 0.0f);
					glVertex3f(x - 5.0f, y, 130.9f);
					glTexCoord2f(1.0f, 1.0f);
					glVertex3f(x - 5.0f, y - 5.0f, 130.9f);
					glTexCoord2f(0.0f, 1.0f);
					glVertex3f(x, y - 5.0f, 130.9f);
				}
				else {
					glTexCoord2f(0.0f, 0.0f);
					glVertex3f(x, y, 130.9f);
					glTexCoord2f(1.0f, 0.0f);
					glVertex3f(-61.15f, y, 130.9f);
					glTexCoord2f(1.0f, 1.0f);
					glVertex3f(-61.15f, y - 5.0f, 130.9f);
					glTexCoord2f(0.0f, 1.0f);
					glVertex3f(x, y - 5.0f, 130.9f);
				}
			}

			if (!((x >= 33.75 && y <= 25.0f && y > 5.0f) || (x <= 10.75f && x >= -4.65f && y <= 20.0f && y >= 15.0f)
				|| (x <= -30.35f && x >= -45.75f && y <= 20.0f && y >= 15.0f) )) {
				if (x > -58.85f) {
					glTexCoord2f(0.0f, 0.0f);
					glVertex3f(x, y, 71.1f);
					glTexCoord2f(0.0f, 1.0f);
					glVertex3f(x, y - 5.0f, 71.1f);
					glTexCoord2f(1.0f, 1.0f);
					glVertex3f(x - 5.0f, y - 5.0f, 71.1f);
					glTexCoord2f(1.0f, 0.0f);
					glVertex3f(x - 5.0f, y, 71.1f);
				}
				else {
					glTexCoord2f(0.0f, 0.0f);
					glVertex3f(x, y, 71.1f);
					glTexCoord2f(0.0f, 1.0f);
					glVertex3f(x, y - 5.0f, 71.1f);
					glTexCoord2f(1.0f, 1.0f);
					glVertex3f(-61.15f, y - 5.0f, 71.1f);
					glTexCoord2f(1.0f, 0.0f);
					glVertex3f(-61.15f, y, 71.1f);
				}
			}
		}
	}
	
	//tejado
	for (GLfloat x = 61.15f; x > -61.15f; x -= 5.0f) {
		for (GLfloat z = 130.9f; z > 71.1f; z -= 5.0f) {
			if (x > -58.85f) {
				glTexCoord2f(0.0f, 0.0f);
				glVertex3f(x, 30.0f, z);
				glTexCoord2f(0.0f, 1.0f);
				glVertex3f(x, 30.0f, z - 5.0f);
				glTexCoord2f(1.0f, 1.0f);
				glVertex3f(x - 5.0f, 30.0f, z - 5.0f);
				glTexCoord2f(1.0f, 0.0f);
				glVertex3f(x - 5.0f, 30.0f, z);
			}
			else {
				glTexCoord2f(0.0f, 0.0f);
				glVertex3f(x, 30.0f, z);
				glTexCoord2f(0.0f, 1.0f);
				glVertex3f(x, 30.0f, z - 5.0f);
				glTexCoord2f(1.0f, 1.0f);
				glVertex3f(-61.15f, 30.0f, z - 5.0f);
				glTexCoord2f(1.0f, 0.0f);
				glVertex3f(-61.15f, 30.0f, z);
			}

		}
	}
	
	glEnd();
	glDisable(GL_TEXTURE_2D);

}
//
// FUNCIÓN: RVScene::DrawMurosInteriores()
//
// PROPÓSITO: Dibuja el techo la vivienda
//

void RVScene::DrawTecho()
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textures[8]);
	glShadeModel(GL_FLAT);
	glBegin(GL_QUADS);
	for (GLfloat x = 61.15f; x > -61.15f; x -= 5.0f) {
		for (GLfloat z = 130.9f; z > 71.1f; z -= 5.0f) {
			if (x > -58.85f && z - 71.1f >= 5.0f) {
				glTexCoord2f(0.0f, 0.0f);
				glVertex3f(x, 30.0f, z);
				glTexCoord2f(0.0f, 1.0f);
				glVertex3f(x - 5.0f, 30.0f, z);
				glTexCoord2f(1.0f, 1.0f);
				glVertex3f(x - 5.0f, 30.0f, z - 5.0f);
				glTexCoord2f(1.0f, 0.0f);
				glVertex3f(x, 30.0f, z - 5.0f);
			}
			else if(x <= -58.85f){
				if (z - 71.1f >= 5.0f) {
					glTexCoord2f(0.0f, 0.0f);
					glVertex3f(x, 30.0f, z);
					glTexCoord2f(0.0f, 1.0f);
					glVertex3f(-61.15f, 30.0f, z);
					glTexCoord2f(1.0f, 1.0f);
					glVertex3f(-61.15f, 30.0f, z - 5.0f);
					glTexCoord2f(1.0f, 0.0f);
					glVertex3f(x, 30.0f, z - 5.0f);
				}
				else {
					glTexCoord2f(0.0f, 0.0f);
					glVertex3f(x, 30.0f, z);
					glTexCoord2f(0.0f, 1.0f);
					glVertex3f(-61.15f, 30.0f, z);
					glTexCoord2f(1.0f, 1.0f);
					glVertex3f(-61.15f, 30.0f, 71.1f);
					glTexCoord2f(1.0f, 0.0f);
					glVertex3f(x, 30.0f, 71.1f);
				}

			}

			else {
				glTexCoord2f(0.0f, 0.0f);
				glVertex3f(x, 30.0f, z);
				glTexCoord2f(0.0f, 1.0f);
				glVertex3f(x - 5.0f, 30.0f, z);
				glTexCoord2f(1.0f, 1.0f);
				glVertex3f(x - 5.0f, 30.0f, 71.1f);
				glTexCoord2f(1.0f, 0.0f);
				glVertex3f(x, 30.0f, 71.1f);
			}
		
		}
	}

	glEnd();
	glDisable(GL_TEXTURE_2D);

}

//
// FUNCIÓN: RVScene::DrawSalon()
//
// PROPÓSITO: Dibuja el salon de la casa
//

void RVScene::DrawSalon() {

	glEnable(GL_TEXTURE_2D);
	//paredes
	glBindTexture(GL_TEXTURE_2D, textures[7]);
	glShadeModel(GL_FLAT);
	glBegin(GL_QUADS);
	
	for (GLfloat y = 30.0f; y > 0.0f; y -= 5.0f)
	{
		for (GLfloat z = 110.9f; z > 73.3f; z -= 5.0f)
		{
			if (!(y <= 25.0f && y > 5.0f && z <= 100.1f)) {
				if ((z - 73.3f) >= 5.0f) {
					glTexCoord2f(0.0f, 0.0f);
					glVertex3f(58.95f, y, z);
					glTexCoord2f(0.0f, 1.0f);
					glVertex3f(58.95f, y, z - 5.0f);
					glTexCoord2f(1.0f, 1.0f);
					glVertex3f(58.95f, y - 5.0f, z - 5.0f);
					glTexCoord2f(1.0f, 0.0f);
					glVertex3f(58.95f, y - 5.0f, z);
				}
				else {
					glTexCoord2f(0.0f, 0.0f);
					glVertex3f(58.95f, y, z);
					glTexCoord2f(0.0f, 1.0f);
					glVertex3f(58.95f, y, 73.3f);
					glTexCoord2f(1.0f, 1.0f);
					glVertex3f(58.95f, y - 5.0f, 73.3f);
					glTexCoord2f(1.0f, 0.0f);
					glVertex3f(58.95f, y - 5.0f, z);
				}
			}
		}

		for (GLfloat z = 73.3f; z <= 101.0f; z += 5.0f)
		{
			if ((101.0f - z) >= 5.0f) {
				glTexCoord2f(0.0f, 0.0f);
				glVertex3f(23.51f, y, z);
				glTexCoord2f(0.0f, 1.0f);
				glVertex3f(23.51f, y, z + 5.0f);
				glTexCoord2f(1.0f, 1.0f);
				glVertex3f(23.51f, y - 5.0f, z + 5.0f);
				glTexCoord2f(1.0f, 0.0f);
				glVertex3f(23.51f, y - 5.0f, z);
			}
			else {
				glTexCoord2f(0.0f, 0.0f);
				glVertex3f(23.51f, y, z);
				glTexCoord2f(0.0f, 1.0f);
				glVertex3f(23.51f, y, 101.0f);
				glTexCoord2f(1.0f, 1.0f);
				glVertex3f(23.51f, y - 5.0f, 101.0f);
				glTexCoord2f(1.0f, 0.0f);
				glVertex3f(23.51f, y - 5.0f, z);
			}
		}

		for (GLfloat x = 23.51f; x < 58.95f; x += 5.0f) 
		{
			if (!(x >= 31.1f && y <= 25.0f && y > 5.0f)) {
				if ((58.95f - x) >= 5.0f && (31.1f -x) >= 5.0f) {
					glTexCoord2f(0.0f, 0.0f);
					glVertex3f(x, y, 73.3f);
					glTexCoord2f(0.0f, 1.0f);
					glVertex3f(x, y - 5.0f, 73.3f);
					glTexCoord2f(1.0f, 1.0f);
					glVertex3f(x + 5.0f, y - 5.0f, 73.3f);
					glTexCoord2f(1.0f, 0.0f);
					glVertex3f(x + 5.0f, y, 73.3f);
				}
				else if ((31.1f - x) < 5.0f && (31.1f - x) >= 0.0f && y <= 25.0f && y > 5.0f) {
					glTexCoord2f(0.0f, 0.0f);
					glVertex3f(x, y, 73.3f);
					glTexCoord2f(0.0f, 1.0f);
					glVertex3f(x, y - 5.0f, 73.3f);
					glTexCoord2f(1.0f, 1.0f);
					glVertex3f(31.1f, y - 5.0f, 73.3f);
					glTexCoord2f(1.0f, 0.0f);
					glVertex3f(31.1f, y, 73.3f);
				}
				else {
					glTexCoord2f(0.0f, 0.0f);
					glVertex3f(x, y, 73.3f);
					glTexCoord2f(0.0f, 1.0f);
					glVertex3f(x, y - 5.0f, 73.3f);
					glTexCoord2f(1.0f, 1.0f);
					glVertex3f(58.95f, y - 5.0f, 73.3f);
					glTexCoord2f(1.0f, 0.0f);
					glVertex3f(58.95f, y, 73.3f);
				}
			}

		}

	}

	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(31.1f, 5.0f, 73.3f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(61.1f, 5.0f, 73.3f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(61.1f, 5.0f, 71.1f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(31.1f, 5.0f, 71.1f);

	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(31.1f, 25.0f, 73.3f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(31.1f, 25.0f, 71.1f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(61.1f, 25.0f, 71.1f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(61.1f, 25.0f, 73.3f);

	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(58.95f, 5.0f, 71.1f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(58.95f, 5.0f, 100.1f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(61.1f, 5.0f, 100.1f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(61.1f, 5.0f, 71.1f);	

	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(58.95f, 25.0f, 71.1f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(61.1f, 25.0f, 71.1f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(61.1f, 25.0f, 100.1f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(58.95f, 25.0f, 100.1f);

	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(31.1f, 25.0f, 73.3f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(31.1f, 5.0f, 73.3f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(31.1f, 5.0f, 71.1f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(31.1f, 25.0f, 71.1f);

	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(61.1f, 25.0f, 95.9f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(61.1f, 5.0f, 95.5f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(58.95f, 5.0f, 95.9f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(58.95f, 25.0f, 95.9f);	
	glEnd();


	//suelo
	glBindTexture(GL_TEXTURE_2D, textures[9]);
	glBegin(GL_QUADS);

	for (GLfloat x = 58.95f; x > 23.51f; x -= 5.0f) {
		for (GLfloat z = 110.9f; z > 73.3f; z -= 5.0f){
			
			glTexCoord2f(0.0f, 0.0f);
			glVertex3f(x, 0.1f, z);
			glTexCoord2f(0.0f, 1.0f);
			glVertex3f(x, 0.1f, z - 5.0f);
			glTexCoord2f(1.0f, 1.0f);
			glVertex3f(x - 5.0f, 0.1f, z - 5.0f);
			glTexCoord2f(1.0f, 0.0f);
			glVertex3f(x - 5.0f, 0.1f, z);
			
		}
	}

	glEnd();
	glDisable(GL_TEXTURE_2D);
}


//
// FUNCIÓN: RVScene::DrawCocina()
//
// PROPÓSITO: Dibuja las ventanas de la casa
//
void RVScene::DrawCocina()
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textures[10]);
	glShadeModel(GL_FLAT);
	glBegin(GL_QUADS);
	for (GLfloat y = 30.0f; y > 0.0f; y -= 5.0f)
	{
		for (GLfloat z = 110.9f; z < 130.9f; z += 5.0f)
		{
			glTexCoord2f(0.0f, 0.0f);
			glVertex3f(58.95f, y, z);
			glTexCoord2f(0.0f, 1.0f);
			glVertex3f(58.95f, y - 5.0f, z);
			glTexCoord2f(1.0f, 1.0f);
			glVertex3f(58.95f, y - 5.0f, z + 5.0f);
			glTexCoord2f(1.0f, 0.0f);
			glVertex3f(58.95f, y, z + 5.0f);
		}

		for (GLfloat x = 61.15f; x > 31.15f; x -= 5.0f) {
			glTexCoord2f(0.0f, 0.0f);
			glVertex3f(x, y, 128.7f);
			glTexCoord2f(0.0f, 1.0f);
			glVertex3f(x, y - 5.0f, 128.7f);
			glTexCoord2f(1.0f, 1.0f);
			glVertex3f(x - 5.0f, y - 5.0f, 128.7f);
			glTexCoord2f(1.0f, 0.0f);
			glVertex3f(x - 5.0f, y, 128.7f);
		}
	}
	glEnd();
	
	glBindTexture(GL_TEXTURE_2D, textures[11]);
	glBegin(GL_QUADS);
	for (GLfloat x = 61.15f; x > 31.15f; x -= 5.0f)
	{
		for (GLfloat z = 110.9f; z < 130.9f; z += 5.0f) {
			glTexCoord2f(0.0f, 0.0f);
			glVertex3f(x, 0.1f, z);
			glTexCoord2f(0.0f, 1.0f);
			glVertex3f(x - 5.0f, 0.1f, z);
			glTexCoord2f(1.0f, 1.0f);
			glVertex3f(x - 5.0f, 0.1f, z + 5.0f);
			glTexCoord2f(1.0f, 0.0f);
			glVertex3f(x, 0.1f, z + 5.0f);

		}
	}
	glEnd();
	glDisable(GL_TEXTURE_2D);

}


//
// FUNCIÓN: RVScene::DrawPasillo()
//
// PROPÓSITO: Dibuja la entrada y el pasillo la casa, así como los huecos de las puertas
//

void RVScene::DrawPasillo() {
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textures[12]);
	glShadeModel(GL_FLAT);
	glBegin(GL_QUADS);
	for (GLfloat y = 30.0f; y > 0.0f; y -= 5.0f) {
		//entrada
		for (GLfloat x = 26.15f; x > -1.35; x -= 5.0f) {
			if (!(x <= 16.95f && x >= 7.05f && y <= 20.0f)) {
				if (x - 1.35 >= 5.0f) {
					glTexCoord2f(0.0f, 0.0f);
					glVertex3f(x, y, 128.7f);
					glTexCoord2f(0.0f, 1.0f);
					glVertex3f(x, y - 5.0f, 128.7f);
					glTexCoord2f(1.0f, 1.0f);
					glVertex3f(x - 5.0f, y - 5.0f, 128.7f);
					glTexCoord2f(1.0f, 0.0f);
					glVertex3f(x - 5.0f, y, 128.7f);
				}
				else {
					glTexCoord2f(0.0f, 0.0f);
					glVertex3f(x, y, 128.7f);
					glTexCoord2f(0.0f, 1.0f);
					glVertex3f(x, y - 5.0f, 128.7f);
					glTexCoord2f(1.0f, 1.0f);
					glVertex3f(-1.35f, y - 5.0f, 128.7f);
					glTexCoord2f(1.0f, 0.0f);
					glVertex3f(-1.35f, y, 128.7f);
				}	
			}
		}
		//pasillo
		for (GLfloat x = -1.35f; x > -32.6f; x -= 5.0f) {
			if (!(x <= -11.35f && x >= -21.25f && y <= 20.0f)) {
				if (-32.6f-x <= -5.0f) {
					glTexCoord2f(0.0f, 0.0f);
					glVertex3f(x, y, 110.99f);
					glTexCoord2f(0.0f, 1.0f);
					glVertex3f(x, y - 5.0f, 110.99f);
					glTexCoord2f(1.0f, 1.0f);
					glVertex3f(x - 5.0f, y - 5.0f, 110.99f);
					glTexCoord2f(1.0f, 0.0f);
					glVertex3f(x - 5.0f, y, 110.99f);
				}
				else {
					glTexCoord2f(0.0f, 0.0f);
					glVertex3f(x, y, 110.99f);
					glTexCoord2f(0.0f, 1.0f);
					glVertex3f(x, y - 5.0f, 110.99f);
					glTexCoord2f(1.0f, 1.0f);
					glVertex3f(-32.6f, y - 5.0f, 110.99f);
					glTexCoord2f(1.0f, 0.0f);
					glVertex3f(-32.6f, y, 110.99f);
				}
			}	
		}
		for (GLfloat x = 23.51f; x > -32.6f; x -= 5.0f) {
			if (!((x <= 13.51f && x >= 3.61f && y <= 20.0f) || (x <= -16.39f && x >= -26.29f && y <= 20.0f))) {
				if (-32.6f - x <= -5.0f) {
					glTexCoord2f(0.0f, 0.0f);
					glVertex3f(x, y, 101.0f);
					glTexCoord2f(0.0f, 1.0f);
					glVertex3f(x - 5.0f, y, 101.0f);
					glTexCoord2f(1.0f, 1.0f);
					glVertex3f(x - 5.0f, y - 5.0f, 101.0f);
					glTexCoord2f(1.0f, 0.0f);
					glVertex3f(x, y - 5.0f, 101.0f);
				}
				else {
					glTexCoord2f(0.0f, 0.0f);
					glVertex3f(x, y, 101.0f);
					glTexCoord2f(0.0f, 1.0f);
					glVertex3f(-32.6f, y, 101.0f);
					glTexCoord2f(1.0f, 1.0f);
					glVertex3f(-32.6f, y - 5.0f, 101.0f);
					glTexCoord2f(1.0f, 0.0f);
					glVertex3f(x, y - 5.0f, 101.0f);
				}
			}
		}

		for (GLfloat z = 128.7f; z > 110.99f; z -= 5.0f) {
			if (z - 110.99f >= 5.0f) {
				glTexCoord2f(0.0f, 0.0f);
				glVertex3f(-1.35f, y, z);
				glTexCoord2f(0.0f, 1.0f);
				glVertex3f(-1.35f, y - 5.0f, z);
				glTexCoord2f(1.0f, 1.0f);
				glVertex3f(-1.35f, y - 5.0f, z - 5.0f);
				glTexCoord2f(1.0f, 0.0f);
				glVertex3f(-1.35f, y, z - 5.0f);
			}
			else {
				glTexCoord2f(0.0f, 0.0f);
				glVertex3f(-1.35f, y, z);
				glTexCoord2f(0.0f, 1.0f);
				glVertex3f(-1.35f, y - 5.0f, z);
				glTexCoord2f(1.0f, 1.0f);
				glVertex3f(-1.35f, y - 5.0f, 110.99f);
				glTexCoord2f(1.0f, 0.0f);
				glVertex3f(-1.35f, y, 110.99f);
			}
		}

		for (GLfloat z = 110.99f; z > 101.0f; z -= 5.0f) {
			if ((z  == 110.99f || z== 105.99f) && y > 20.0f) {
				glTexCoord2f(0.0f, 0.0f);
				glVertex3f(-32.6f, y, z);
				glTexCoord2f(0.0f, 1.0f);
				glVertex3f(-32.6f, y - 5.0f, z);
				glTexCoord2f(1.0f, 1.0f);
				glVertex3f(-32.6f, y - 5.0f, z - 5.0f);
				glTexCoord2f(1.0f, 0.0f);
				glVertex3f(-32.6f, y, z - 5.0f);
			}
			else if (z == 110.99 && y <= 20.0f) {
				glTexCoord2f(0.0f, 0.0f);
				glVertex3f(-32.6f, y, z);
				glTexCoord2f(0.0f, 1.0f);
				glVertex3f(-32.6f, y - 5.0f, z);
				glTexCoord2f(1.0f, 1.0f);
				glVertex3f(-32.6f, y - 5.0f, 110.94f);
				glTexCoord2f(1.0f, 0.0f);
				glVertex3f(-32.6f, y, z - 110.94f);
			}
			else if (z == 105.99 && y <= 20.0f) {
				glTexCoord2f(0.0f, 0.0f);
				glVertex3f(-32.6f, y, 101.05f);
				glTexCoord2f(0.0f, 1.0f);
				glVertex3f(-32.6f, y - 5.0f, 101.05f);
				glTexCoord2f(1.0f, 1.0f);
				glVertex3f(-32.6f, y - 5.0f, 101.0f);
				glTexCoord2f(1.0f, 0.0f);
				glVertex3f(-32.6f, y, z - 101.0f);
			}

		}

	}
	glEnd();

	//suelo
	glBindTexture(GL_TEXTURE_2D, textures[9]);
	glBegin(GL_QUADS);
	for (GLfloat x = 26.15f; x > -1.35; x -= 5.0f) {
		for (GLfloat z = 130.9f; z > 110.99f; z -= 5.0f) {
			if (-1.35f - x <= -5.0f) {
				glTexCoord2f(0.0f, 0.0f);
				glVertex3f(x, 0.1f, z);
				glTexCoord2f(0.0f, 1.0f);
				glVertex3f(x, 0.1f, z - 5.0f);
				glTexCoord2f(1.0f, 1.0f);
				glVertex3f(x - 5.0f, 0.1f, z - 5.0f);
				glTexCoord2f(1.0f, 0.0f);
				glVertex3f(x - 5.0f, 0.1f, z);
			}
			else {
				glTexCoord2f(0.0f, 0.0f);
				glVertex3f(x, 0.1f, z);
				glTexCoord2f(0.0f, 1.0f);
				glVertex3f(x, 0.1f, z - 5.0f);
				glTexCoord2f(0.5f, 1.0f);
				glVertex3f(-1.35f, 0.1f, z - 5.0f);
				glTexCoord2f(0.5f, 0.0f);
				glVertex3f(-1.35f, 0.1f, z);
			}
		}
	}

	for (GLfloat x = 19.0f; x > -32.6f; x -= 5.0f) {
		for (GLfloat z = 110.9f; z > 100.9f; z -= 5.0f) {
			if (-32.6f - x <= -5.0f) {
				glTexCoord2f(0.0f, 0.0f);
				glVertex3f(x, 0.1f, z);
				glTexCoord2f(0.0f, 1.0f);
				glVertex3f(x, 0.1f, z - 5.0f);
				glTexCoord2f(1.0f, 1.0f);
				glVertex3f(x - 5.0f, 0.1f, z - 5.0f);
				glTexCoord2f(1.0f, 0.0f);
				glVertex3f(x - 5.0f, 0.1f, z);
			}
			else {
				glTexCoord2f(0.0f, 0.0f);
				glVertex3f(x, 0.1f, z);
				glTexCoord2f(0.0f, 1.0f);
				glVertex3f(x, 0.1f, z - 5.0f);
				glTexCoord2f(0.4f, 1.0f);
				glVertex3f(-32.6f, 0.1f, z - 5.0f);
				glTexCoord2f(0.4f, 0.0f);
				glVertex3f(-32.6f, 0.1f, z);
			}
		}
	}

	glEnd();
	glDisable(GL_TEXTURE_2D);
}


//
// FUNCIÓN: RVScene::DrawBaño()
//
// PROPÓSITO: Dibuja el baño de la casa
//
void RVScene::DrawBaño() {
	//paredes
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textures[13]);
	glShadeModel(GL_FLAT);
	glBegin(GL_QUADS);

	for (GLfloat y = 30.0f; y > 0.0f; y -= 5.0f) {
		for (GLfloat x = -1.35f; x > -32.6f; x -= 5.0f) {
			if (-32.6f - x <= -5.0f) {
				if (!(x <= -11.35f && x >=  -21.35f && y <= 20.0f && y >= 15.0f)) {
					glTexCoord2f(0.0f, 0.0f);
					glVertex3f(x, y, 128.7f);
					glTexCoord2f(0.0f, 1.0f);
					glVertex3f(x, y - 5.0f, 128.7f);
					glTexCoord2f(1.0f, 1.0f);
					glVertex3f(x - 5.0f, y - 5.0f, 128.7f);
					glTexCoord2f(1.0f, 0.0f);
					glVertex3f(x - 5.0f, y, 128.7f);
				}

				else if (x == -11.35f && y <= 20.0f && y >= 15.0f) {
					glTexCoord2f(0.0f, 0.0f);
					glVertex3f(x, y, 128.7f);
					glTexCoord2f(0.0f, 1.0f);
					glVertex3f(x, y - 5.0f, 128.7f);
					glTexCoord2f(0.5f, 1.0f);
					glVertex3f(-13.85f, y - 5.0f, 128.7f);
					glTexCoord2f(0.5f, 0.0f);
					glVertex3f(-13.85f, y, 128.7f);
				}

				else if (x == -21.35f && y <= 20.0f && y >= 15.0f) {
					glTexCoord2f(0.0f, 0.0f);
					glVertex3f(-23.85f, y, 128.7f);
					glTexCoord2f(0.0f, 1.0f);
					glVertex3f(-23.85f, y - 5.0f, 128.7f);
					glTexCoord2f(0.5f, 1.0f);
					glVertex3f(-26.35f, y - 5.0f, 128.7f);
					glTexCoord2f(0.5f, 0.0f);
					glVertex3f(-26.35f, y, 128.7f);
				}

				if (!(x <= -11.35f && x >= -21.25f && y <= 20.0f)) {
					glTexCoord2f(0.0f, 0.0f);
					glVertex3f(x, y, 112.09f);
					glTexCoord2f(0.0f, 1.0f);
					glVertex3f(x - 5.0f, y, 112.09f);
					glTexCoord2f(1.0f, 1.0f);
					glVertex3f(x - 5.0f, y - 5.0f, 112.09f);
					glTexCoord2f(1.0f, 0.0f);
					glVertex3f(x, y - 5.0f, 112.09f);
				}

			}
			else {
				glTexCoord2f(0.0f, 0.0f);
				glVertex3f(x, y, 128.7f);
				glTexCoord2f(0.0f, 1.0f);
				glVertex3f(x, y - 5.0f, 128.7f);
				glTexCoord2f(0.3f, 1.0f);
				glVertex3f(-32.6f, y - 5.0f, 128.7f);
				glTexCoord2f(0.3f, 0.0f);
				glVertex3f(-32.6f, y, 128.7f);

				glTexCoord2f(0.0f, 0.0f);
				glVertex3f(x, y, 112.09f);
				glTexCoord2f(0.0f, 0.3f);
				glVertex3f(-32.6f, y, 112.09f);
				glTexCoord2f(1.0f, 0.3f);
				glVertex3f(-32.6f, y - 5.0f, 112.09f);
				glTexCoord2f(1.0f, 0.0f);
				glVertex3f(x, y - 5.0f, 112.09f);
			}
		}

		for (GLfloat z = 128.7f; z > 110.99f; z -= 5.0f) {
			if (z - 110.99f >= 5.0f) {
				glTexCoord2f(0.0f, 0.0f);
				glVertex3f(-32.6f, y, z);
				glTexCoord2f(0.0f, 1.0f);
				glVertex3f(-32.6f, y - 5.0f, z);
				glTexCoord2f(1.0f, 1.0f);
				glVertex3f(-32.6f, y - 5.0f, z - 5.0f);
				glTexCoord2f(1.0f, 0.0f);
				glVertex3f(-32.6f, y, z - 5.0f);

				glTexCoord2f(0.0f, 0.0f);
				glVertex3f(-2.45f, y, z);
				glTexCoord2f(0.0f, 1.0f);
				glVertex3f(-2.45f, y, z - 5.0f);
				glTexCoord2f(1.0f, 1.0f);
				glVertex3f(-2.45f, y - 5.0f, z - 5.0f);
				glTexCoord2f(1.0f, 0.0f);
				glVertex3f(-2.45f, y - 5.0f, z);
			}
			else {
				glTexCoord2f(0.0f, 0.0f);
				glVertex3f(-32.6f, y, z);
				glTexCoord2f(0.0f, 1.0f);
				glVertex3f(-32.6f, y - 5.0f, z);
				glTexCoord2f(0.5f, 1.0f);
				glVertex3f(-32.6f, y - 5.0f, 110.99f);
				glTexCoord2f(0.5f, 0.0f);
				glVertex3f(-32.6f, y, 110.99f);

				glTexCoord2f(0.0f, 0.0f);
				glVertex3f(-2.45f, y, z);
				glTexCoord2f(0.0f, 0.5f);
				glVertex3f(-2.45f, y, 110.99f);
				glTexCoord2f(1.0f, 0.5f);
				glVertex3f(-2.45f, y - 5.0f, 110.99f);
				glTexCoord2f(1.0f, 0.0f);
				glVertex3f(-2.45f, y - 5.0f, z);
			}
		}

		if (y <= 20.0f && y >= 15.0f) {
			glTexCoord2f(0.0f, 0.0f);
			glVertex3f(-23.85f, y, 130.9f);
			glTexCoord2f(0.0f, 1.0f);
			glVertex3f(-23.85f, y - 5.0f, 130.9f);
			glTexCoord2f(0.5f, 1.0f);
			glVertex3f(-23.85f, y - 5.0f, 128.7f);
			glTexCoord2f(0.5f, 0.0f);
			glVertex3f(-23.85f, y, 128.7f);

			glTexCoord2f(0.0f, 0.0f);
			glVertex3f(-13.85f, y, 130.9f);
			glTexCoord2f(0.0f, 0.5f);
			glVertex3f(-13.85f, y, 128.7f);
			glTexCoord2f(1.0f, 0.5f);
			glVertex3f(-13.85f, y - 5.0f, 128.7f);
			glTexCoord2f(1.0f, 0.0f);
			glVertex3f(-13.85f, y - 5.0f, 130.9f);
		}


	}

	for (GLfloat x = -13.85f; x >= -23.85f; x -= 5.0f) {
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(x, 10.0f, 130.9f);
		glTexCoord2f(0.0f, 0.5f);
		glVertex3f(x, 10.0f, 128.7f);
		glTexCoord2f(1.0f, 0.5f);
		glVertex3f(x - 5.0f, 10.0f, 128.7f);
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(x - 5.0f, 10.0f, 130.9f);

		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(x, 20.0f, 130.9f);
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(x - 5.0f, 20.0f, 130.9f);
		glTexCoord2f(0.5f, 1.0f);
		glVertex3f(x - 5.0f, 20.0f, 128.7f);
		glTexCoord2f(0.5f, 0.0f);
		glVertex3f(x, 20.0f, 128.7f);
	}

	glEnd();

	//suelo
	glBindTexture(GL_TEXTURE_2D, textures[14]);
	glBegin(GL_QUADS);
	for (GLfloat x = -1.35f; x > -32.6f; x -= 5.0f) {
		for (GLfloat z = 128.7f; z > 110.99f; z -= 5.0f) {
			if (-32.6f - x <= -5.0f && z - 110.99f >= 5.0f) {
				glTexCoord2f(0.0f, 0.0f);
				glVertex3f(x, 0.1f, z);
				glTexCoord2f(0.0f, 1.0f);
				glVertex3f(x, 0.1f, z - 5.0f);
				glTexCoord2f(1.0f, 1.0f);
				glVertex3f(x - 5.0f, 0.1f, z - 5.0f);
				glTexCoord2f(1.0f, 0.0f);
				glVertex3f(x - 5.0f, 0.1f, z); 
			}
			else if (-32.6f - x > -5.0f && z - 110.99f >= 5.0f) {
				glTexCoord2f(0.0f, 0.0f);
				glVertex3f(x, 0.1f, z);
				glTexCoord2f(0.0f, 1.0f);
				glVertex3f(x, 0.1f, z - 5.0f);
				glTexCoord2f(0.3f, 1.0f);
				glVertex3f(-32.6f, 0.1f, z - 5.0f);
				glTexCoord2f(0.3f, 0.0f);
				glVertex3f(-32.6f, 0.1f, z);

			}
			else if(-32.6f - x <= -5.0f && z - 110.99f < 5.0f){
				glTexCoord2f(0.0f, 0.0f);
				glVertex3f(x, 0.1f, z);
				glTexCoord2f(0.0f, 0.5f);
				glVertex3f(x, 0.1f, 110.99f);
				glTexCoord2f(1.0f, 0.5f);
				glVertex3f(x - 5.0f, 0.1f,110.99f);
				glTexCoord2f(1.0f, 0.0f);
				glVertex3f(x - 5.0f, 0.1f, z);
			}
			else {
				glTexCoord2f(0.0f, 0.0f);
				glVertex3f(x, 0.1f, z);
				glTexCoord2f(0.0f, 0.5f);
				glVertex3f(x, 0.1f, 110.99f);
				glTexCoord2f(0.3f, 0.5f);
				glVertex3f(-32.6f, 0.1f, 110.99f);
				glTexCoord2f(0.3f, 0.0f);
				glVertex3f(-32.6f, 0.1f, z);
			}
		}
	}
	glEnd();

	glDisable(GL_TEXTURE_2D);
}
//
// FUNCIÓN: RVScene::DrawHabitacion1()
//
// PROPÓSITO: Dibuja la habitación este de la casa
//

void RVScene::DrawHabitacion1() {
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textures[15]);
	glShadeModel(GL_FLAT);
	glBegin(GL_QUADS);

	for (GLfloat y = 30.0f; y > 0.0f; y -= 5.0f) {

		for (GLfloat z = 130.9f; z > 101.0f; z -= 5.0f) {
			if (z > 111.0f || y > 20.0f) {
				glTexCoord2f(0.0f, 0.0f);
				glVertex3f(-33.7f, y, z);
				glTexCoord2f(0.0f, 1.0f);
				glVertex3f(-33.7f, y, z - 5.0f);
				glTexCoord2f(1.0f, 1.0f);
				glVertex3f(-33.7f, y - 5.0f, z - 5.0f);
				glTexCoord2f(1.0f, 0.0f);
				glVertex3f(-33.7f, y - 5.0f, z);
			}

			glTexCoord2f(0.0f, 0.0f);
			glVertex3f(-58.95f, y, z);
			glTexCoord2f(0.0f, 1.0f);
			glVertex3f(-58.95f, y - 5.0f, z);
			glTexCoord2f(1.0f, 1.0f);
			glVertex3f(-58.95f, y - 5.0f, z - 5.0f);
			glTexCoord2f(1.0f, 0.0f);
			glVertex3f(-58.95f, y, z - 5.0f);
		}

		for (GLfloat x = -32.6f; x > -61.15f; x -= 5.0f) {

			if (-61.15f - x <= -5.0f) {
				glTexCoord2f(0.0f, 0.0f);
				glVertex3f(x, y, 101.0f);
				glTexCoord2f(0.0f, 1.0f);
				glVertex3f(x - 5.0f, y, 101.0f);
				glTexCoord2f(1.0f, 1.0f);
				glVertex3f(x - 5.0f, y - 5.0f, 101.0f);
				glTexCoord2f(1.0f, 0.0f);
				glVertex3f(x, y - 5.0f, 101.0f);

				if ( !(x <= -42.6f && x >= -52.6f  && y <= 20.0f && y >= 15.0f)) {
					glTexCoord2f(0.0f, 0.0f);
					glVertex3f(x, y, 128.7f);
					glTexCoord2f(0.0f, 1.0f);
					glVertex3f(x, y - 5.0f, 128.7f);
					glTexCoord2f(1.0f, 1.0f);
					glVertex3f(x - 5.0f, y - 5.0f, 128.7f);
					glTexCoord2f(1.0f, 0.0f);
					glVertex3f(x - 5.0f, y, 128.7f);
				}

				else if (x == -42.6f && y <= 20.0f && y >= 15.0f) {
					glTexCoord2f(0.0f, 0.0f);
					glVertex3f(x, y, 128.7f);
					glTexCoord2f(0.0f, 1.0f);
					glVertex3f(x, y - 5.0f, 128.7f);
					glTexCoord2f(1.0f, 1.0f);
					glVertex3f(-43.85f, y - 5.0f, 128.7f);
					glTexCoord2f(1.0f, 0.0f);
					glVertex3f(-43.85f, y, 128.7f);
				}

				else if (x == -52.6f && y <= 20.0f && y >= 15.0f){
					glTexCoord2f(0.0f, 0.0f);
					glVertex3f(-53.85f, y, 128.7f);
					glTexCoord2f(0.0f, 1.0f);
					glVertex3f(-53.85f, y - 5.0f, 128.7f);
					glTexCoord2f(1.0f, 1.0f);
					glVertex3f(x - 5.0f, y - 5.0f, 128.7f);
					glTexCoord2f(1.0f, 0.0f);
					glVertex3f(x - 5.0f, y, 128.7f);
				}
			}

			else {
				glTexCoord2f(0.0f, 0.0f);
				glVertex3f(x, y, 101.0f);
				glTexCoord2f(0.0f, 1.0f);
				glVertex3f(-61.15f, y, 101.0f);
				glTexCoord2f(1.0f, 1.0f);
				glVertex3f(-61.15f, y - 5.0f, 101.0f);
				glTexCoord2f(1.0f, 0.0f);
				glVertex3f(x, y - 5.0f, 101.0f);


				glTexCoord2f(0.0f, 0.0f);
				glVertex3f(x, y, 128.7f);
				glTexCoord2f(0.0f, 1.0f);
				glVertex3f(x, y - 5.0f, 128.7f);
				glTexCoord2f(1.0f, 1.0f);
				glVertex3f(-61.15f, y - 5.0f, 128.7f);
				glTexCoord2f(1.0f, 0.0f);
				glVertex3f(-61.15f, y, 128.7f);
			}

		}
	}

	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-43.85f, 20.0f, 130.9f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-43.85f, 20.0f, 128.7f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-43.85f, 10.0f, 128.7f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-43.85f, 10.0f, 130.9f);


	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-53.85f, 20.0f, 130.9f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-53.85f, 10.0f, 130.9f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-53.85f, 10.0f, 128.7f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-53.85f, 20.0f, 128.7f);

	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-43.85f, 10.0f, 130.9f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-43.85f, 10.0f, 128.7f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-53.85f, 10.0f, 128.7f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-53.85f, 10.0f, 130.9f);

	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-43.85f, 20.0f, 130.9f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-53.85f, 20.0f, 130.9f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-53.85f, 20.0f, 128.7f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-43.85f, 20.0f, 128.7f);

	glEnd();
	//suelo
	glBindTexture(GL_TEXTURE_2D, textures[9]);
	glBegin(GL_QUADS);
	for (GLfloat x = -32.6f; x > -61.15f; x -= 5.0f) {
		for (GLfloat z = 130.9f; z > 101.0f; z -= 5.0f) {
			if (-61.15f - x <= -5.0f) {
				glTexCoord2f(0.0f, 0.0f);
				glVertex3f(x, 0.1f, z);
				glTexCoord2f(0.0f, 1.0f);
				glVertex3f(x, 0.1f, z - 5.0f);
				glTexCoord2f(1.0f, 1.0f);
				glVertex3f(x - 5.0f, 0.1f, z - 5.0f);
				glTexCoord2f(1.0f, 0.0f);
				glVertex3f(x - 5.0f, 0.1f, z);
			}

			else {
				glTexCoord2f(0.0f, 0.0f);
				glVertex3f(x, 0.1f, z);
				glTexCoord2f(0.0f, 1.0f);
				glVertex3f(x, 0.1f, z - 5.0f);
				glTexCoord2f(0.7f, 1.0f);
				glVertex3f(-61.15f, 0.1f, z - 5.0f);
				glTexCoord2f(0.7f, 0.0f);
				glVertex3f(-61.15f, 0.1f, z);
			}

		}
	}
	glEnd();
	glDisable(GL_TEXTURE_2D);
}

//
// FUNCIÓN: RVScene::DrawHabitacion2()
//
// PROPÓSITO: Dibuja la habitación sur de la casa
//
void RVScene::DrawHabitacion2() {
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textures[16]);
	glShadeModel(GL_FLAT);
	glBegin(GL_QUADS);
	for (GLfloat y = 30.0f; y > 0.0f; y -= 5.0f) {

		for (GLfloat z = 101.0f; z > 71.1f; z -= 5.0f)
		{
			if (z - 71.1f >= 5.0f) {
				glTexCoord2f(0.0f, 0.0f);
				glVertex3f(-58.9f, y, z);
				glTexCoord2f(0.0f, 1.0f);
				glVertex3f(-58.9f, y - 5.0f, z);
				glTexCoord2f(1.0f, 1.0f);
				glVertex3f(-58.9f, y - 5.0f, z - 5.0f);
				glTexCoord2f(1.0f, 0.0f);
				glVertex3f(-58.9f, y, z - 5.0f);

				glTexCoord2f(0.0f, 0.0f);
				glVertex3f(-13.75f, y, z);
				glTexCoord2f(0.0f, 1.0f);
				glVertex3f(-13.75f, y, z - 5.0f);
				glTexCoord2f(1.0f, 1.0f);
				glVertex3f(-13.75f, y - 5.0f, z - 5.0f);
				glTexCoord2f(1.0f, 0.0f);
				glVertex3f(-13.75f, y - 5.0f, z);
			}

			else {
				glTexCoord2f(0.0f, 0.0f);
				glVertex3f(-58.9f, y, z);
				glTexCoord2f(0.0f, 1.0f);
				glVertex3f(-58.9f, y - 5.0f, z);
				glTexCoord2f(1.0f, 1.0f);
				glVertex3f(-58.9f, y - 5.0f, 71.1f);
				glTexCoord2f(1.0f, 0.0f);
				glVertex3f(-58.9f, y, 71.1f);

				glTexCoord2f(0.0f, 0.0f);
				glVertex3f(-13.75f, y, z);
				glTexCoord2f(0.0f, 1.0f);
				glVertex3f(-13.75f, y, 71.1f);
				glTexCoord2f(1.0f, 1.0f);
				glVertex3f(-13.75f, y - 5.0f, 71.1f);
				glTexCoord2f(1.0f, 0.0f);
				glVertex3f(-13.75f, y - 5.0f, z);
			}

		}

		for (GLfloat x = -13.71f; x > -61.15f; x -= 5.0f) {
			if (-61.15f - x <= -5.0f) {
				if (!(x <= -33.7f && x >= -48.7f && y <= 20.0f && y >= 15.0f)) {
					glTexCoord2f(0.0f, 0.0f);
					glVertex3f(x, y, 73.3f);
					glTexCoord2f(0.0f, 1.0f);
					glVertex3f(x - 5.0f, y, 73.3f);
					glTexCoord2f(1.0f, 1.0f);
					glVertex3f(x - 5.0f, y - 5.0f, 73.3f);
					glTexCoord2f(1.0f, 0.0f);
					glVertex3f(x, y - 5.0f, 73.3f);
				}

				if (!(x <= -13.71f  && x >= -23.71f && y <= 20.0f)) {
					glTexCoord2f(0.0f, 0.0f);
					glVertex3f(x, y, 99.9f);
					glTexCoord2f(0.0f, 1.0f);
					glVertex3f(x, y - 5.0f, 99.9f);
					glTexCoord2f(1.0f, 1.0f);
					glVertex3f(x - 5.0f, y - 5.0f, 99.9f);
					glTexCoord2f(1.0f, 0.0f);
					glVertex3f(x - 5.0f, y, 99.9f);
				}
				else if (x == -13.71f && y <= 20.0f) {
					glTexCoord2f(0.0f, 0.0f);
					glVertex3f(x, y, 99.9f);
					glTexCoord2f(0.0f, 1.0f);
					glVertex3f(x, y - 5.0f, 99.9f);
					glTexCoord2f(1.0f, 1.0f);
					glVertex3f(-16.49f, y - 5.0f, 99.9f);
					glTexCoord2f(1.0f, 0.0f);
					glVertex3f(-16.49f, y, 99.9f);
				}
				else if (x == -23.71f && y <= 20.0f) {
					glTexCoord2f(0.0f, 0.0f);
					glVertex3f(-26.49f, y, 99.9f);
					glTexCoord2f(0.0f, 1.0f);
					glVertex3f(-26.49f, y - 5.0f, 99.9f);
					glTexCoord2f(1.0f, 1.0f);
					glVertex3f(x - 5.0f, y - 5.0f, 99.9f);
					glTexCoord2f(1.0f, 0.0f);
					glVertex3f(x - 5.0f, y, 99.9f);
				}
			}
		}

	}

	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-48.71f, 20.0f, 73.3f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-48.71f, 10.0f, 73.3f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-48.71f, 10.0f, 71.1f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-48.71f, 20.0f, 71.1f);


	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-33.7f, 20.0f, 73.3f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-33.7f, 20.0f, 71.1f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-33.7f, 10.0f, 71.1f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-33.7f, 10.0f, 73.3f);

	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-33.7f, 10.0f, 73.3f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-33.7f, 10.0f, 71.1f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-48.71f, 10.0f, 71.1f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-48.71f, 10.0f, 73.3f);
	
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-33.7f, 20.0f, 73.3f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-48.71f, 20.0f, 73.3f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-48.71f, 20.0f, 71.1f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-33.7f, 20.0f, 71.1f);
	
	glEnd();


	// suelo
	glBindTexture(GL_TEXTURE_2D, textures[9]);
	glBegin(GL_QUADS);
	for (GLfloat x = -13.71f; x > -61.15f; x -= 5.0f) {
		for (GLfloat z = 101.0f; z > 71.1f; z -= 5.0f) {
			if (-61.15f - x <= -5.0f && z - 71.1f >= 5.0f) {
				glTexCoord2f(0.0f, 0.0f);
				glVertex3f(x, 0.1f, z);
				glTexCoord2f(0.0f, 1.0f);
				glVertex3f(x, 0.1f, z - 5.0f);
				glTexCoord2f(1.0f, 1.0f);
				glVertex3f(x - 5.0f, 0.1f, z - 5.0f);
				glTexCoord2f(1.0f, 0.0f);
				glVertex3f(x - 5.0f, 0.1f, z);
			}

			else if(-61.15f - x > -5.0f){
				glTexCoord2f(0.0f, 0.0f);
				glVertex3f(x, 0.1f, z);
				glTexCoord2f(0.0f, 1.0f);
				glVertex3f(x, 0.1f, z - 5.0f);
				glTexCoord2f(0.7f, 1.0f);
				glVertex3f(-61.15f, 0.1f, z - 5.0f);
				glTexCoord2f(0.7f, 0.0f);
				glVertex3f(-61.15f, 0.1f, z);
			}

			else {
				glTexCoord2f(0.0f, 0.0f);
				glVertex3f(x, 0.1f, z);
				glTexCoord2f(0.0f, 1.0f);
				glVertex3f(x, 0.1f, 71.1f);
				glTexCoord2f(1.0f, 1.0f);
				glVertex3f(x - 5.0f, 0.1f, 71.1f);
				glTexCoord2f(1.0f, 0.0f);
				glVertex3f(x - 5.0f, 0.1f, z);
			}
		}
	}
	glEnd();
	glDisable(GL_TEXTURE_2D);

}

//
// FUNCIÓN: RVScene::DrawHabitacion3()
//
// PROPÓSITO: Dibuja la habitación oeste de la casa
//
void RVScene::DrawHabitacion3() {
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textures[17]);
	glShadeModel(GL_FLAT);
	glBegin(GL_QUADS);
	for (GLfloat y = 30.0f; y > 0.0f; y -= 5.0f) {
		for (GLfloat z = 101.0f; z > 71.1f; z -= 5.0f)
		{
			if (z - 71.1f >= 5.0f) {
				glTexCoord2f(0.0f, 0.0f);
				glVertex3f(-12.65f, y, z);
				glTexCoord2f(0.0f, 1.0f);
				glVertex3f(-12.65f, y - 5.0f, z);
				glTexCoord2f(1.0f, 1.0f);
				glVertex3f(-12.65f, y - 5.0f, z - 5.0f);
				glTexCoord2f(1.0f, 0.0f);
				glVertex3f(-12.65f, y, z - 5.0f);

				glTexCoord2f(0.0f, 0.0f);
				glVertex3f(22.41f, y, z);
				glTexCoord2f(0.0f, 1.0f);
				glVertex3f(22.41f, y, z - 5.0f);
				glTexCoord2f(1.0f, 1.0f);
				glVertex3f(22.41f, y - 5.0f, z - 5.0f);
				glTexCoord2f(1.0f, 0.0f);
				glVertex3f(22.41f, y - 5.0f, z);
			}

			else {
				glTexCoord2f(0.0f, 0.0f);
				glVertex3f(-12.65f, y, z);
				glTexCoord2f(0.0f, 1.0f);
				glVertex3f(-12.65f, y - 5.0f, z);
				glTexCoord2f(1.0f, 1.0f);
				glVertex3f(-12.65f, y - 5.0f, 71.1f);
				glTexCoord2f(1.0f, 0.0f);
				glVertex3f(-12.65f, y, 71.1f);

				glTexCoord2f(0.0f, 0.0f);
				glVertex3f(22.41f, y, z);
				glTexCoord2f(0.0f, 1.0f);
				glVertex3f(22.41f, y, 71.1f);
				glTexCoord2f(1.0f, 1.0f);
				glVertex3f(22.41f, y - 5.0f, 71.1f);
				glTexCoord2f(1.0f, 0.0f);
				glVertex3f(22.41f, y - 5.0f, z);
			}
		}

		for (GLfloat x = 23.51f; x > -12.65f; x -= 5.0f) {
			if (-12.65f - x <= -5.0f) {
				
				if (!(x <= 8.51f && x >= -6.49f && y <= 20.0f && y >= 15.0f)) {
						glTexCoord2f(0.0f, 0.0f);
						glVertex3f(x, y, 73.3f);
						glTexCoord2f(0.0f, 1.0f);
						glVertex3f(x - 5.0f, y, 73.3f);
						glTexCoord2f(1.0f, 1.0f);
						glVertex3f(x - 5.0f, y - 5.0f, 73.3f);
						glTexCoord2f(1.0f, 0.0f);
						glVertex3f(x, y - 5.0f, 73.3f);
					}
				else if (x == 8.51f && y <= 20.0f) {
					glTexCoord2f(0.0f, 0.0f);
					glVertex3f(x, y, 73.3f);
					glTexCoord2f(0.0f, 0.5f);
					glVertex3f(6.15f, y, 73.3f);
					glTexCoord2f(1.0f, 0.5f);
					glVertex3f(6.15f, y - 5.0f, 73.3f);
					glTexCoord2f(1.0f, 0.0f);
					glVertex3f(x, y - 5.0f, 73.3f);
				}
				else if (x == -6.49f && y <= 20.0f) {
					glTexCoord2f(0.0f, 0.0f);
					glVertex3f(-8.85f, y, 73.3f);
					glTexCoord2f(0.0f, 0.5f);
					glVertex3f(x - 5.0f, y, 73.3f);
					glTexCoord2f(1.0f, 0.5f);
					glVertex3f(x - 5.0f, y - 5.0f, 73.3f);
					glTexCoord2f(1.0f, 0.0f);
					glVertex3f(-8.85f, y - 5.0f, 73.3f);
				}	
				if (!(x <= 13.51f && x >= 8.51f && y <= 20.0f)) {
					glTexCoord2f(0.0f, 0.0f);
					glVertex3f(x, y, 99.9f);
					glTexCoord2f(0.0f, 1.0f);
					glVertex3f(x, y - 5.0f, 99.9f);
					glTexCoord2f(1.0f, 1.0f);
					glVertex3f(x - 5.0f, y - 5.0f, 99.9f);
					glTexCoord2f(1.0f, 0.0f);
					glVertex3f(x - 5.0f, y, 99.9f);
				}
			}
			else {
				glTexCoord2f(0.0f, 0.0f);
				glVertex3f(x, y, 73.3f);
				glTexCoord2f(0.0f, 0.3f);
				glVertex3f(-12.65f, y, 73.3f);
				glTexCoord2f(1.0f, 0.3f);
				glVertex3f(-12.65f, y - 5.0f, 73.3f);
				glTexCoord2f(1.0f, 0.0f);
				glVertex3f(x, y - 5.0f, 73.3f);

				glTexCoord2f(0.0f, 0.0f);
				glVertex3f(x, y, 99.9f);
				glTexCoord2f(0.0f, 1.0f);
				glVertex3f(x, y - 5.0f, 99.9f);
				glTexCoord2f(1.0f, 1.0f);
				glVertex3f(-12.65f, y - 5.0f, 99.9f);
				glTexCoord2f(1.0f, 0.0f);
				glVertex3f(-12.65f, y, 99.9f);
			}
		
		}
	}

	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-8.85f, 20.0f, 73.3f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-8.85f, 10.0f, 73.3f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-8.85f, 10.0f, 71.1f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-8.85f, 20.0f, 71.1f);


	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(6.15f, 20.0f, 73.3f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(6.15f, 20.0f, 71.1f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(6.15f, 10.0f, 71.1f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(6.15f, 10.0f, 73.3f);

	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(6.15f, 10.0f, 73.3f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(6.15f, 10.0f, 71.1f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-8.85f, 10.0f, 71.1f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-8.85f, 10.0f, 73.3f);

	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(6.15f, 20.0f, 73.3f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-8.85f, 20.0f, 73.3f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-8.85f, 20.0f, 71.1f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(6.15f, 20.0f, 71.1f);

	glEnd();


	// suelo
	glBindTexture(GL_TEXTURE_2D, textures[9]);
	glBegin(GL_QUADS);
	for (GLfloat x = 19.01f; x > -12.65f; x -= 5.0f) {
		for (GLfloat z = 101.0f; z > 71.1f; z -= 5.0f) {
			if (-12.65f - x <= -5.0f && z - 71.1f >= 5.0f) {
				glTexCoord2f(0.0f, 0.0f);
				glVertex3f(x, 0.1f, z);
				glTexCoord2f(0.0f, 1.0f);
				glVertex3f(x, 0.1f, z - 5.0f);
				glTexCoord2f(1.0f, 1.0f);
				glVertex3f(x - 5.0f, 0.1f, z - 5.0f);
				glTexCoord2f(1.0f, 0.0f);
				glVertex3f(x - 5.0f, 0.1f, z);
			}

			else if(-12.65f - x > -5.0f){
				glTexCoord2f(0.0f, 0.0f);
				glVertex3f(x, 0.1f, z);
				glTexCoord2f(0.0f, 1.0f);
				glVertex3f(x, 0.1f, z - 5.0f);
				glTexCoord2f(0.4f, 1.0f);
				glVertex3f(-12.65f, 0.1f, z - 5.0f);
				glTexCoord2f(0.4f, 0.0f);
				glVertex3f(-12.65f, 0.1f, z);
			}

			else {
				glTexCoord2f(0.0f, 0.0f);
				glVertex3f(x, 0.1f, z);
				glTexCoord2f(0.0f, 1.0f);
				glVertex3f(x, 0.1f, 71.1f);
				glTexCoord2f(1.0f, 1.0f);
				glVertex3f(x - 5.0f, 0.1f, 71.1f);
				glTexCoord2f(1.0f, 0.0f);
				glVertex3f(x - 5.0f, 0.1f, z);
			}
		}
	}
	glEnd();
	glDisable(GL_TEXTURE_2D);
}

//
// FUNCIÓN: RVScene::DrawMarcos()
//
// PROPÓSITO: Dibuja los marcos de las puertas de la casa
//
void RVScene::DrawMarcos() {
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textures[18]);
	glShadeModel(GL_FLAT);
	glBegin(GL_QUADS);
	
	for (GLfloat y = 20.0f; y > 0.0f; y -= 5.0f) {
		//entrada
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(6.0f, y, 130.9f);
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(6.0f, y - 5.0f, 130.9f);
		glTexCoord2f(0.5f, 1.0f);
		glVertex3f(6.0f, y - 5.0f, 128.7f);
		glTexCoord2f(0.5f, 0.0f);
		glVertex3f(6.0f, y, 128.7f);

		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(16.2f, y, 130.9f);
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(16.2f, y, 128.7f);
		glTexCoord2f(0.5f, 1.0f);
		glVertex3f(16.2f, y - 5.0f, 128.7f);
		glTexCoord2f(0.5f, 0.0f);
		glVertex3f(16.2f, y - 5.0f, 130.9f);

		//baño
		
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(-11.35f, y, 112.09f);
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(-11.35f, y, 110.99f);
		glTexCoord2f(0.5f, 1.0f);
		glVertex3f(-11.35f, y - 5.0f, 110.99f);
		glTexCoord2f(0.5f, 0.0f);
		glVertex3f(-11.35f, y - 5.0f, 112.09f);

		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(-21.35f, y, 112.09f);
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(-21.35f, y - 5.0f, 112.09f);
		glTexCoord2f(0.5f, 1.0f);
		glVertex3f(-21.35f, y - 5.0f, 110.99f);
		glTexCoord2f(0.5f, 0.0f);
		glVertex3f(-21.35f, y, 110.99f);

		//habitación 1
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(-32.6f, y, 110.99f);
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(-32.6f, y - 5.0f, 110.99f);
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(-33.7f, y - 5.0f, 110.99f);
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(-33.7f, y, 110.99f);

		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(-32.6f, y, 101.01f);
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(-33.7f, y, 101.01f);
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(-33.7f, y - 5.0f, 101.01f);
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(-32.6f, y - 5.0f, 101.01f);

		//habitación 2
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(-16.49f, y, 101.0f);
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(-16.49f, y, 99.9f);
		glTexCoord2f(0.5f, 1.0f);
		glVertex3f(-16.49f, y - 5.0f, 99.9f);
		glTexCoord2f(0.5f, 0.0f);
		glVertex3f(-16.49f, y - 5.0f, 101.0f);

		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(-26.49f, y, 101.0f);
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(-26.49f, y - 5.0f, 101.0f);
		glTexCoord2f(0.5f, 1.0f);
		glVertex3f(-26.49f, y - 5.0f, 99.9f);
		glTexCoord2f(0.5f, 0.0f);
		glVertex3f(-26.49f, y, 99.9f);

		//habitación 3
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(13.51f, y, 101.0f);
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(13.51f, y, 99.9f);
		glTexCoord2f(0.5f, 1.0f);
		glVertex3f(13.51f, y - 5.0f, 99.9f);
		glTexCoord2f(0.5f, 0.0f);
		glVertex3f(13.51f, y - 5.0f, 101.0f);

		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(3.51f, y, 101.0f);
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(3.51f, y - 5.0f, 101.0f);
		glTexCoord2f(0.5f, 1.0f);
		glVertex3f(3.51f, y - 5.0f, 99.9f);
		glTexCoord2f(0.5f, 0.0f);
		glVertex3f(3.51f, y, 99.9f);
	}

	//entrada
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(16.2f, 20.0f, 130.9f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(6.0f, 20.0f, 130.9f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(6.0f, 20.0f, 128.7f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(16.2f, 20.0f, 128.7f);
	
	
	//baño
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-11.35f, 20.0f, 112.09f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-21.35f, 20.0f, 112.09f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-21.35f, 20.0f, 110.99f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-11.35f, 20.0f, 110.99f);

	//habitación 1
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-32.6f, 20.0f, 110.99f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-33.7f, 20.0f, 110.99f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-33.7f, 20.0f, 101.0f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-32.6f, 20.0f, 101.0f);


	//habitación 2
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-16.49f, 20.0f, 101.0f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-26.49f, 20.0f, 101.0f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-26.49f, 20.0f, 99.9f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-16.49f, 20.0f, 99.9f);
	
	//habitación 3
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(13.51f, 20.0f, 101.0f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(3.51f, 20.0f, 101.0f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(3.51f, 20.0f, 99.9f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(13.51f, 20.0f, 99.9f);

	glEnd();
	glDisable(GL_TEXTURE_2D);
}

//
// FUNCIÓN: RVScene::DrawCamas()
//
// PROPÓSITO: Dibuja las camas de las habitaciones
//
void RVScene::DrawCamas() {
	//habitación 1
	glPushMatrix();
	glTranslatef(-54.0f, 4.9f, 119.9f);
	bed->Draw();
	glPopMatrix();

	//habitación 2
	glPushMatrix();
	glTranslatef(-49.5f, 4.9f, 90.9f);
	glRotatef(-90.0f, 0.0f, 1.0f, 0.0f);
	bed->Draw();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-49.5f, 4.9f, 81.7f);
	glRotatef(-90.0f, 0.0f, 1.0f, 0.0f);
	bed->Draw();
	glPopMatrix();

	//habitación 3
	glPushMatrix();
	glTranslatef(-2.65f, 4.9f, 78.5f);
	glRotatef(-90.0f, 0.0f, 1.0f, 0.0f);
	bed->Draw();
	glPopMatrix();
}

//
// FUNCIÓN: RVScene::DrawVentanas()
//
// PROPÓSITO: Dibuja las ventanas de la casa
//
void RVScene::DrawVentanas()
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textures[5]);
	glShadeModel(GL_FLAT);
	glBegin(GL_QUADS);
	//ventanas normales
	//exterior
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-13.85f, 20.0f, 130.9f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-23.85f, 20.0f, 130.9f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-23.85f, 10.0f, 130.9f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-13.85f, 10.0f, 130.9f);

	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-43.85f, 20.0f, 130.9f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-53.85f, 20.0f, 130.9f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-53.85f, 10.0f, 130.9f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-43.85f, 10.0f, 130.9f);

	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(6.15f, 20.0f, 71.1f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(6.15f, 10.0f, 71.1f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-1.35f, 10.0f, 71.1f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-1.35f, 20.0f, 71.1f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-1.35f, 20.0f, 71.1f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-1.35f, 10.0f, 71.1f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-8.85f, 10.0f, 71.1f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-8.85f, 20.0f, 71.1f);

	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-33.85f, 20.0f, 71.1f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-33.85f, 10.0f, 71.1f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-41.35f, 10.0f, 71.1f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-41.35f, 20.0f, 71.1f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-41.35f, 20.0f, 71.1f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-41.35f, 10.0f, 71.1f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-48.85f, 10.0f, 71.1f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-48.85f, 20.0f, 71.1f);

	//interior
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-23.85f, 20.0f, 130.9f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-13.85f, 20.0f, 130.9f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-13.85f, 10.0f, 130.9f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-23.85f, 10.0f, 130.9f);
	
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-43.85f, 20.0f, 130.9f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-43.85f, 10.0f, 130.9f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-53.85f, 10.0f, 130.9f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-53.85f, 20.0f, 130.9f);

	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(6.15f, 20.0f, 71.1f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-1.35f, 20.0f, 71.1f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-1.35f, 10.0f, 71.1f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(6.15f, 10.0f, 71.1f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-1.35f, 20.0f, 71.1f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-8.85f, 20.0f, 71.1f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-8.85f, 10.0f, 71.1f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-1.35f, 10.0f, 71.1f);

	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-33.7f, 20.0f, 71.1f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-41.35f, 20.0f, 71.1f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-41.35f, 10.0f, 71.1f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-33.7f, 10.0f, 71.1f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-41.35f, 20.0f, 71.1f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-48.71f, 20.0f, 71.1f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-48.71f, 10.0f, 71.1f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-41.35f, 10.0f, 71.1f);
	glEnd();
	
	//ventanales
	glBindTexture(GL_TEXTURE_2D, textures[6]);
	glBegin(GL_QUADS);
	//interior
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(61.1f, 25.0f, 95.9f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(61.1f, 25.0f, 71.1f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(61.1f, 5.0f, 71.1f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(61.1f, 5.0f, 95.9f);

	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(61.1f, 25.0f, 71.1f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(31.1f, 25.0f, 71.1f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(31.1f, 5.0f, 71.1f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(61.1f, 5.0f, 71.1f);
	
	//exterior
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(61.1f, 25.0f, 95.9f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(61.1f, 5.0f, 95.9f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(61.1f, 5.0f, 71.1f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(61.1f, 25.0f, 71.1f);

	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(61.1f, 25.0f, 71.1f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(61.1f, 5.0f, 71.1f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(31.1f, 5.0f, 71.1f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(31.1f, 25.0f, 71.1f);
	glEnd();
	glDisable(GL_TEXTURE_2D);
}