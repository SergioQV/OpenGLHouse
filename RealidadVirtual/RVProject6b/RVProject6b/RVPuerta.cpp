#include "stdafx.h"
#include "RVPuerta.h"


RVPuerta::RVPuerta()
{
	cerrada = true;
	InitTextures();
}


RVPuerta::~RVPuerta()
{
	glDeleteTextures(2, textures);
}


void RVPuerta::InitTextures()
{
	glGenTextures(2, textures);

	char* texture_files[] = {"textures/marco.jpg","textures/puerta.jpg"};

	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glEnable(GL_TEXTURE_2D);

	for (int i = 0; i < 2; i++)
	{
		FREE_IMAGE_FORMAT format = FreeImage_GetFileType(texture_files[i], 0);
		FIBITMAP* bitmap = FreeImage_Load(format, texture_files[i]);

		glBindTexture(GL_TEXTURE_2D, textures[i]);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

		FIBITMAP *pImage = FreeImage_ConvertTo32Bits(bitmap);
		int nWidth = FreeImage_GetWidth(pImage);
		int nHeight = FreeImage_GetHeight(pImage);

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, nWidth, nHeight,
			0, GL_BGRA, GL_UNSIGNED_BYTE, (void*)FreeImage_GetBits(pImage));

		FreeImage_Unload(pImage);
	}
}

void RVPuerta::Draw()
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textures[1]);
	glShadeModel(GL_FLAT);
	glBegin(GL_QUADS);

	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-5.0f, 0.0f, 0.0f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(5.0f, 0.0f, 0.0f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(5.0f, 20.0f, 0.0f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-5.0f, 20.0f, 0.0f);

	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(5.0f, 0.0f, -1.1f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-5.0f, 0.0f, -1.1f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-5.0f, 20.0f, -1.1f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(5.0f, 20.0f, -1.1f);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, textures[0]);
	glBegin(GL_QUADS);

	for (GLfloat y = 20.0f; y > 0.0f; y -= 5.0f)
	{
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(5.0f, y, 0.0f);
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(5.0f, y - 5.0f, 0.0f);
		glTexCoord2f(0.5f, 1.0f);
		glVertex3f(5.0f, y - 5.0f, -1.1f);
		glTexCoord2f(0.5f, 0.0f);
		glVertex3f(5.0f, y, -1.1f);

		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(-5.0f, y, 0.0f);
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(-5.0f, y, -1.1f);
		glTexCoord2f(0.5f, 1.0f);
		glVertex3f(-5.0f, y - 5.0f, -1.1f);
		glTexCoord2f(0.5f, 0.0f);
		glVertex3f(-5.0f, y - 5.0f, 0.0f);
	}


	glEnd();
	glDisable(GL_TEXTURE_2D);
}

bool RVPuerta::getCerrada() {
	return cerrada;
}

void RVPuerta::setCerrada(bool estado) {
	cerrada = estado;
}