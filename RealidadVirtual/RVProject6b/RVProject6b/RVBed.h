#ifndef RVBED
#define RVBED

#include "stdafx.h" 
#include <glew.h>
#include "RVBed_0.h"
#include "RVBed_1.h"
#include "RVBed_2.h"



class RVBed {
private:
	GLuint textures[3];
	RVBed_0 *bed0;
	RVBed_1 *bed1;
	RVBed_2 *bed2;
	void InitTexture(GLuint texture, char* filename);
public:
	RVBed();
	~RVBed();
	void Draw();
};


	
	

#endif