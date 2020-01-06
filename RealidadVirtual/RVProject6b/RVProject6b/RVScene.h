#ifndef RVSCENE

#define RVSCENE

#include <glew.h>
#include "RVBed.h"
class RVScene
{
public:
	RVScene(GLuint *textura);
	~RVScene();
	void Draw();

private:
	RVBed* bed;
	GLuint *textures;

	void DrawGround();
	void DrawFences();
	void DrawContorno();
	void DrawTecho();
	void DrawSalon();
	void DrawCocina();
	void DrawPasillo();
	void DrawBaño();
	void DrawHabitacion1();
	void DrawHabitacion2();
	void DrawHabitacion3();
	void DrawMarcos();
	void DrawCamas();
	void DrawVentanas();
};

#endif