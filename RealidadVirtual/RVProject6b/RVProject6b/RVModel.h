#ifndef RVMODEL
#define RVMODEL

#include <glew.h>
#include "RVCamera.h"
#include "RVScene.h"
#include "RVPuerta.h"

class RVModel {
public:
	void Initialize(GLsizei w, GLsizei h);
	void Finalize();
	void RenderScene();
	void KeyboardAction(int virtualKey);
	void MouseAction(int xPos, int yPos, WPARAM wParam);
	void TimerAction();
	void ChangeSize(GLsizei w, GLsizei h);

private:
	GLfloat aspectRatio;
	GLfloat wWidth;
	GLfloat wHeight;
	GLsizei wndWidth;
	GLsizei wndHeight;

	GLuint textures[20];
	GLuint cubemap[1];
	GLfloat copia[3];
	GLfloat puertas[5][4];


	RVPuerta *puertaCalle;
	RVPuerta *puertaBaño;
	RVPuerta *puertaHab1;
	RVPuerta *puertaHab2;
	RVPuerta *puertaHab3;
	RVCamera* camera;
	RVScene* scene;
	void InitTextures();
	void InitCubeMap();
	void DrawPuertas();
	int zonaPuertas(GLfloat x, GLfloat z);
	void DrawSkyBox();
};


#endif