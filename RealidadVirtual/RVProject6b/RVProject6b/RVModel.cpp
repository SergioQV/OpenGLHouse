#include "stdafx.h"
#include <glew.h>
#include <FreeImage.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include "RVModel.h"


//
// FUNCTION: Initialize(GLsizei, GLsizei)
//
// PURPOSE: Initialize the 3D model
//
void RVModel::Initialize(GLsizei w, GLsizei h)
{
	InitCubeMap();
	InitTextures();

	// Inicializa la posición de las figuras

	// Crea la cámara y la escena
	camera = new RVCamera();
	camera->SetPosition(90.0f, 17.0f, 190.0f);
	camera->SetDirection(0.0f,0.0f,1.0f,0.0f,1.0f,0.0f);
	scene = new RVScene(textures);
	puertaCalle = new RVPuerta();
	puertaBaño = new RVPuerta();
	puertaHab1 = new RVPuerta();
	puertaHab2 = new RVPuerta();
	puertaHab3 = new RVPuerta();

	// Asigna el viewport y el clipping volume
	ChangeSize(w, h);

	// Opciones de dibujo
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glEnable(GL_CULL_FACE);
	glFrontFace(GL_CCW);
	glPolygonMode(GL_FRONT, GL_FILL);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

}

void RVModel::InitCubeMap()
{
	glGenTextures(1, cubemap);

	char* cubemap_files[] = { "textures/posx.jpg", "textures/negx.jpg", "textures/posy.jpg",
		"textures/negy.jpg", "textures/posz.jpg", "textures/negz.jpg" };

	GLenum  cube[6] = { GL_TEXTURE_CUBE_MAP_POSITIVE_X,
		GL_TEXTURE_CUBE_MAP_NEGATIVE_X,
		GL_TEXTURE_CUBE_MAP_POSITIVE_Y,
		GL_TEXTURE_CUBE_MAP_NEGATIVE_Y,
		GL_TEXTURE_CUBE_MAP_POSITIVE_Z,
		GL_TEXTURE_CUBE_MAP_NEGATIVE_Z };

	glEnable(GL_TEXTURE_CUBE_MAP);
	glBindTexture(GL_TEXTURE_CUBE_MAP, cubemap[0]);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_GENERATE_MIPMAP, GL_TRUE);

	for (int i = 0; i < 6; i++)  
	{
		FREE_IMAGE_FORMAT format = FreeImage_GetFileType(cubemap_files[i], 0);
		FIBITMAP* bitmap = FreeImage_Load(format, cubemap_files[i]);
		FIBITMAP *pImage = FreeImage_ConvertTo32Bits(bitmap);
		int nWidth = FreeImage_GetWidth(pImage);
		int nHeight = FreeImage_GetHeight(pImage);

		glTexImage2D(cube[i], 0, GL_RGBA8, nWidth, nHeight,
			0, GL_BGRA, GL_UNSIGNED_BYTE, (void*)FreeImage_GetBits(pImage));

		FreeImage_Unload(pImage);
	}
}

void RVModel::InitTextures()
{
	glGenTextures(19, textures);

	char* texture_files[] = { "textures/baldosas.jpg","textures/valla.jpg","textures/exterior.jpg","textures/piscina.jpg",
								"textures/bordePiscina.jpg","textures/ventana2.png","textures/ventanal.png",
								"textures/paredSalon.jpg","textures/techo.jpg","textures/sueloMadera.jpg","textures/paredCocina.jpg",
								"textures/sueloCocina.jpg","textures/paredPasillo.jpg","textures/paredBaño.jpg","textures/sueloBaño.jpg",
								"textures/paredHabitacion1.jpg","textures/paredHabitacion2.jpg", "textures/paredHabitacion3.jpg","textures/marco.jpg"};

	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glEnable(GL_TEXTURE_2D);

	for (int i = 0; i < 19; i++)
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

///////////////////////////////////////////////////////////
// Draw the skybox. This is just six quads, with texture
// coordinates set to the corners of the cube map
void RVModel::DrawSkyBox()
{
	GLfloat fExtent = 3000.0f;
	glEnable(GL_TEXTURE_CUBE_MAP);
	glBindTexture(GL_TEXTURE_CUBE_MAP, cubemap[0]);

	glBegin(GL_QUADS);
	//////////////////////////////////////////////
	// Negative X
	glTexCoord3f(-1.0f, -1.0f, 1.0f);
	glVertex3f(-fExtent, -fExtent, fExtent);

	glTexCoord3f(-1.0f, -1.0f, -1.0f);
	glVertex3f(-fExtent, -fExtent, -fExtent);

	glTexCoord3f(-1.0f, 1.0f, -1.0f);
	glVertex3f(-fExtent, fExtent, -fExtent);

	glTexCoord3f(-1.0f, 1.0f, 1.0f);
	glVertex3f(-fExtent, fExtent, fExtent);


	///////////////////////////////////////////////
	//  Postive X
	glTexCoord3f(1.0f, -1.0f, -1.0f);
	glVertex3f(fExtent, -fExtent, -fExtent);

	glTexCoord3f(1.0f, -1.0f, 1.0f);
	glVertex3f(fExtent, -fExtent, fExtent);

	glTexCoord3f(1.0f, 1.0f, 1.0f);
	glVertex3f(fExtent, fExtent, fExtent);

	glTexCoord3f(1.0f, 1.0f, -1.0f);
	glVertex3f(fExtent, fExtent, -fExtent);


	////////////////////////////////////////////////
	// Negative Z 
	glTexCoord3f( -1.0f, -1.0f, -1.0f);
	glVertex3f(-fExtent, -fExtent, -fExtent);

	glTexCoord3f( 1.0f, -1.0f, -1.0f);
	glVertex3f(fExtent, -fExtent, -fExtent);

	glTexCoord3f( 1.0f, 1.0f, -1.0f);
	glVertex3f(fExtent, fExtent, -fExtent);

	glTexCoord3f( -1.0f, 1.0f, -1.0f);
	glVertex3f(-fExtent, fExtent, -fExtent);


	////////////////////////////////////////////////
	// Positive Z 
	glTexCoord3f(1.0f, -1.0f, 1.0f);
	glVertex3f(fExtent, -fExtent, fExtent);

	glTexCoord3f(-1.0f, -1.0f, 1.0f);
	glVertex3f(-fExtent, -fExtent, fExtent);

	glTexCoord3f(-1.0f, 1.0f, 1.0f);
	glVertex3f(-fExtent, fExtent, fExtent);

	glTexCoord3f(1.0f, 1.0f, 1.0f);
	glVertex3f(fExtent, fExtent, fExtent);


	//////////////////////////////////////////////////
	// Positive Y
	glTexCoord3f(-1.0f, 1.0f, 1.0f);
	glVertex3f(-fExtent, fExtent, fExtent);

	glTexCoord3f(-1.0f, 1.0f, -1.0f);
	glVertex3f(-fExtent, fExtent, -fExtent);

	glTexCoord3f( 1.0f, 1.0f, -1.0f);
	glVertex3f(fExtent, fExtent, -fExtent);

	glTexCoord3f( 1.0f, 1.0f, 1.0f);
	glVertex3f(fExtent, fExtent, fExtent);


	///////////////////////////////////////////////////
	// Negative Y
	glTexCoord3f(-1.0f, -1.0f, -1.0f);
	glVertex3f(-fExtent, -fExtent, -fExtent);

	glTexCoord3f(-1.0f, -1.0f, 1.0f);
	glVertex3f(-fExtent, -fExtent, fExtent);

	glTexCoord3f(1.0f, -1.0f, 1.0f);
	glVertex3f(fExtent, -fExtent, fExtent);

	glTexCoord3f(1.0f, -1.0f, -1.0f);
	glVertex3f(fExtent, -fExtent, -fExtent);
	glEnd();

	glDisable(GL_TEXTURE_CUBE_MAP);
}

//
// FUNCTION: Finalize()
//
// PURPOSE: Finalize the 3D model
//
void RVModel::Finalize()
{
	delete camera;
	delete scene;
	delete puertaCalle;
	glDeleteTextures(19, textures);
	glDeleteTextures(1, cubemap);
}

//
// FUNCTION: ChangeSize(GLsizei, GLsizei)
//
// PURPOSE: Modify de rectangle size and viewport when the window changes its size
//
void RVModel::ChangeSize(GLsizei w, GLsizei h)
{
	double fov = 15.0 * M_PI / 180.0;
	double sin_fov = sin(fov);
	double cos_fov = cos(fov);
	if (h == 0) h = 1;
	aspectRatio = (GLfloat)w / (GLfloat)h;
	wHeight = (GLfloat)(sin_fov * 0.2 / cos_fov);
	wWidth = wHeight * aspectRatio;

	wndWidth = w;
	wndHeight = h;

	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-wWidth, wWidth, -wHeight, wHeight, 0.2, 10000.0);
}

//
// FUNCTION:DrawPuertas()
//
// PURPOSE: Dibuja las puertas de la casa, abiertas o cerradas, además de guardar las coordenadas de las "zonas de puertas"
//
void RVModel::DrawPuertas()
{
	glPushMatrix();
	if (puertaCalle->getCerrada())
	{
		glTranslatef(11.2f, 0.0f, 130.9f);
		puertas[0][0] = 6.2f;
		puertas[0][1] = 16.2f;
		puertas[0][2] = 130.9f;
		puertas[0][3] = 127.8f;
	}
	else {
		glTranslatef(6.2f, 0.0f, 125.9f);
		glRotatef(-90.0f, 0.0f, 1.0f, 0.0f);
		puertas[0][0] = 6.2f;
		puertas[0][1] = 7.3f;
		puertas[0][2] = 130.9f;
		puertas[0][3] = 120.9f;
	}
	puertaCalle->Draw();
	glPopMatrix();

	glPushMatrix();
	if (puertaBaño->getCerrada())
	{
		glTranslatef(-16.35f, 0.0f, 112.09f);
		puertas[1][0] = -21.35f;
		puertas[1][1] = -11.35f;
		puertas[1][2] = 112.09f;
		puertas[1][3] = 110.99f;
	}
	else {
		glTranslatef(-12.45f, 0.0f, 115.99f);
		glRotatef(-90.0f, 0.0f, 1.0f, 0.0f);
		puertas[1][0] = -12.45f;
		puertas[1][1] = -11.35f;
		puertas[1][2] = 120.99f;
		puertas[1][3] = 110.99f;
	}
	puertaBaño->Draw();
	glPopMatrix();


	glPushMatrix();
	if (puertaHab1->getCerrada()) {
		glTranslatef(-32.6f, 0.0f, 106.0f);
		glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
		puertas[2][0] = -33.7f;
		puertas[2][1] = -32.6f;
		puertas[2][2] = 111.0f;
		puertas[2][3] = 101.0f;
	}
	else {
		glTranslatef(-37.6f, 0.0f, 102.1f);
		puertas[2][0] = -42.6f;
		puertas[2][1] = -32.6f;
		puertas[2][2] = 102.1f;
		puertas[2][3] = 101.0f;
	}
	puertaHab1->Draw();
	glPopMatrix();


	glPushMatrix();
	if (puertaHab2->getCerrada()) {
		glTranslatef(-21.49f, 0.0f, 101.0f);
		puertas[3][0] = -26.49f;
		puertas[3][1] = -16.49f;
		puertas[3][2] = 101.0f;
		puertas[3][3] = 99.9f;
	}
	else {
		glTranslatef(-16.49f, 0.0f, 96.0f);
		glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
		puertas[3][0] = -17.59f;
		puertas[3][1] = -16.49f;
		puertas[3][2] = 101.0f;
		puertas[3][3] = 91.0f;
	}
	puertaHab2->Draw();
	glPopMatrix();

	glPushMatrix();
	if (puertaHab3->getCerrada()) {
		glTranslatef(8.51f, 0.0f, 101.0f);
		puertas[4][0] = 3.51f;
		puertas[4][1] = 13.51f;
		puertas[4][2] = 101.0f;
		puertas[4][3] = 99.9f;
	}
	else {
		glTranslatef(13.51f, 0.0f, 96.0f);
		glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
		puertas[4][0] = 12.41f;
		puertas[4][1] = 13.51f;
		puertas[4][2] = 101.0f;
		puertas[4][3] = 91.0f;
	}
	puertaHab3->Draw();
	glPopMatrix();

	camera->setZonaPuerta(puertas);
}

//
// FUNCTION:zonaPuertas()
//
// PURPOSE: Devuelve el número de puerta si la posición especificada está cerca de alguna puerta, o -1 en caso contrario
//
int RVModel::zonaPuertas(GLfloat x, GLfloat z) {
	
	int i = 0;

	while (i < 5) {
		if ((puertas[i][0] - 4.0f) <= x && (4.0f + puertas[i][1]) > x && (4.0f + puertas[i][2]) >= z && (puertas[i][3] - 4.0f) <= z) {
			return i;
		}
		i++;
	}
	return -1;
}


//
// FUNCTION: RenderScene()
//
// PURPOSE: Paints the scene
//
void RVModel::RenderScene()
{
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	camera->PlaceCamera();
	DrawSkyBox();
	DrawPuertas();
	scene->Draw();
	glColor3f(1.0f, 1.0f, 1.0f);


	
	
}

//
// FUNCTION: TimerAction()
//
// PURPOSE: Animate the scene
//
void RVModel::TimerAction()
{

}

//
// FUCNTION: KeyboardAction(int)
//
// PURPOSE: 
//
void RVModel::KeyboardAction(int virtualKey)
{
	GLfloat posicion[3], direccion[3], direccionUp[3];
	camera->GetPosition(posicion);
	camera->GetDirection(direccion);
	camera->GetUpDirection(direccionUp);
	if (direccionUp[0] == 0.0 && direccionUp[2] == 0.0f) {
		copia[0] = direccion[0]; copia[2] = direccion[2];
	}

	switch (virtualKey)
	{
		case VK_UP:
		camera->SetDirection(copia[0], 0.0f, copia[2], 0.0f, 1.0f, 0.0f);
		if(posicion[1] == 17.0f) camera->MoveFront();
		break;
	case VK_DOWN:
		camera->SetDirection(copia[0], 0.0f, copia[2], 0.0f, 1.0f, 0.0f);
		if (posicion[1] == 17.0f) camera->MoveBack();
		break;
	case VK_LEFT:
		if (direccionUp[0] == 0.0 && direccionUp[2] == 0.0f)camera->TurnLeft();
		break;
	case VK_RIGHT:
		if (direccionUp[0] == 0.0 && direccionUp[2] == 0.0f)camera->TurnRight();
		break;
	case 'W':
		camera->TurnUp();
		break;
	case 'S':
		camera->TurnDown();
		break;
	case 'Q':
		if (direccionUp[0] == 0.0 && direccionUp[2] == 0.0f && (posicion[0] > 61.15f || posicion[0] < -61.15f || posicion[2] > 130.9f || posicion[2] < 71.1f)) camera->MoveUp();
		break;
	case 'E':
		if(posicion[1] > 17.0f && direccionUp[0] == 0.0 && direccionUp[2] == 0.0f)camera->MoveDown();
		break;
	case VK_RETURN:
		int puerta = zonaPuertas(posicion[0], posicion[2]);

		switch (puerta) {
		case 0: puertaCalle->setCerrada(!puertaCalle->getCerrada());
			break;
		case 1: puertaBaño->setCerrada(!puertaBaño->getCerrada());
			break;
		case 2: puertaHab1->setCerrada(!puertaHab1->getCerrada());
			break;
		case 3: puertaHab2->setCerrada(!puertaHab2->getCerrada());
			break;
		case 4: puertaHab3->setCerrada(!puertaHab3->getCerrada());
			break;
		}
		
		break;
	}
}

//
// FUNCTION: MouseAction(int xPos, int yPos, WPARAM wParam)
//
// PURPOSE: 
//
void RVModel::MouseAction(int xPos, int yPos, WPARAM wParam)
{
	/*
	if (wParam & MK_CONTROL)
	{ // Control key is down
	}
	else if (wParam & MK_SHIFT)
	{ // Shift key is down
	}
	else if (wParam & MK_LBUTTON)
	{ // Left button is down
	}
	else if (wParam & MK_MBUTTON)
	{ // Middle button is down
	}
	else if (wParam & MK_RBUTTON)
	{ // Right button is down
	}
	*/
}

