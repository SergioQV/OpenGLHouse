#include "stdafx.h" 
#include <glew.h>
#include <FreeImage.h>
#include "RVBed.h"


RVBed::RVBed() 
{
	// Crea las figuras
	bed0 = new RVBed_0();
	bed0->InitBuffers();
	bed1 = new RVBed_1();
	bed1->InitBuffers();
	bed2 = new RVBed_2();
	bed2->InitBuffers();

	// Carga las texturas
	glGenTextures(3, textures);
	InitTexture(textures[0], "textures/dusek.bmp");
	InitTexture(textures[1], "textures/sipk.bmp");
	InitTexture(textures[2], "textures/drvo.bmp");
}

RVBed::~RVBed()
{
	// Elimina las figuras
	delete bed0;
	delete bed1;
	delete bed2;

	// Elimina las texturas
	glDeleteTextures(3, textures);
}


void RVBed::InitTexture(GLuint texture, char* filename)
{
	FREE_IMAGE_FORMAT format = FreeImage_GetFileType(filename, 0);
	FIBITMAP* bitmap = FreeImage_Load(format, filename);
	FIBITMAP *pImage = FreeImage_ConvertTo32Bits(bitmap);
	int nWidth = FreeImage_GetWidth(pImage);
	int nHeight = FreeImage_GetHeight(pImage);

	glBindTexture(GL_TEXTURE_2D, texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, nWidth, nHeight,
		0, GL_BGRA, GL_UNSIGNED_BYTE, (void*)FreeImage_GetBits(pImage));

	FreeImage_Unload(pImage);
}

void RVBed::Draw()
{
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	glEnable(GL_TEXTURE_2D);
	glTexEnvi(GL_TEXTURE_2D, GL_TEXTURE_ENV_MODE, GL_MODULATE);

	glBindTexture(GL_TEXTURE_2D, textures[0]);
	bed0->Draw();
	glBindTexture(GL_TEXTURE_2D, textures[1]);
	bed1->Draw();
	glBindTexture(GL_TEXTURE_2D, textures[2]);
	bed2->Draw();

	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_NORMAL_ARRAY);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	glDisable(GL_TEXTURE_2D);
}