#ifndef RVPUERTA_H
#define RVPUERTA_H

#include "stdafx.h"
#include <glew.h>
#include <FreeImage.h>
#include <math.h>


class RVPuerta
{
public:
	RVPuerta();
	~RVPuerta();
	void Draw();
	bool getCerrada();
	void setCerrada(bool estado);
private:
	bool cerrada;
	
	GLuint textures[2];

	void InitTextures();
};

#endif

