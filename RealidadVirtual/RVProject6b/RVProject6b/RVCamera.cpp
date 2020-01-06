#include "stdafx.h"
#include <glew.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include "RVCamera.h"

//
// FUNCI�N: RVCamera::RVCamera()
//
// PROP�SITO: Construye una c�mara
//
// COMENTARIOS: 
//     La posici�n inicial es (0,0,0).
//     La orientaci�n incial es el sistema de coordenadas del modelo
//     El tama�o del paso inicial es 0.1
//     El t�ma�o del giro inicial es 1.0 grados
//
RVCamera::RVCamera() {
	xPos = 0.0f;
	yPos = 0.0f;
	zPos = 0.0f;
	
	xDir = 0.0f;
	yDir = 0.0f;
	zDir = 1.0f;
	
	xUp = 0.0f;
	yUp = 1.0f;
	zUp = 0.0f;
	
	xRight = 1.0f;
	yRight = 0.0f;
	zRight = 0.0f;

	moveStep = 1.5f;
	turnStep = 2.0f;
	cosAngle = (GLfloat) cos(3.141592*turnStep / 180);
	sinAngle = (GLfloat) sin(3.141592*turnStep / 180);
}

//
// FUNCI�N: RVCamera::PlaceCamera()
//
// PROP�SITO: Aplica los cambios a la matriz ModelView para situar la c�mara.
//
void RVCamera::PlaceCamera()
{
	// Creates a rotation matrix using vectors Dir, Up and Right
	GLfloat m[16];
	m[0] = xRight;
	m[4] = yRight;
	m[8] = zRight;
	m[12] = 0.0;
	m[1] = xUp;
	m[5] = yUp;
	m[9] = zUp;
	m[13] = 0.0;
	m[2] = xDir;
	m[6] = yDir;
	m[10] = zDir;
	m[14] = 0.0;
	m[3] = 0.0;
	m[7] = 0.0;
	m[11] = 0.0;
	m[15] = 1.0;
	glMultMatrixf(m);

	glTranslatef(-xPos, -yPos, -zPos);
}

//
// FUNCI�N: RVCamera::SetPosition(GLfloat x, GLfloat y, GLfloat z)
//
// PROP�SITO: Asigna la posici�n de la c�mara con respecto al sistema de coordenadas del modelo.
//
void RVCamera::SetPosition(GLfloat x, GLfloat y, GLfloat z)
{
	xPos = x;
	yPos = y;
	zPos = z;
}

//
// FUNCI�N: RVCamera::SetDirection(GLfloat xDir, GLfloat yDir, GLfloat zDir, GLfloat xUp, GLfloat yUp, GLfloat zUp)
//
// PROP�SITO: Asigna la orientaci�n de la c�mara.
//
void RVCamera::SetDirection(GLfloat xD, GLfloat yD, GLfloat zD, GLfloat xU, GLfloat yU, GLfloat zU)
{
	xDir = xD;
	yDir = yD;
	zDir = zD;

	xUp = xU;
	yUp = yU;
	zUp = zU;


	// Right = Up x Dir
	xRight = yUp*zDir - zUp*yDir;
	yRight = zUp*xDir - xUp*zDir;
	zRight = xUp*yDir - yUp*xDir;
}

//
// FUNCI�N: RVCamera::SetMoveStep(GLfloat step)
//
// PROP�SITO: Asigna el avance en cada paso.
//
void RVCamera::SetMoveStep(GLfloat step)
{
	moveStep = step;
}

//
// FUNCI�N: RVCamera::SetTurnStep(GLfloat step)
//
// PROP�SITO: Asigna el �ngulo de giro en cada paso.
//
void RVCamera::SetTurnStep(GLfloat step)
{
	turnStep = step;
	cosAngle = (GLfloat) cos(3.141592*turnStep / 180);
	sinAngle = (GLfloat) sin(3.141592*turnStep / 180);
}

//
// FUNCI�N: RVCamera::GetPosition()
//
// PROP�SITO: Obtiene la posici�n de la c�mara.
//
void RVCamera::GetPosition(GLfloat* vPos)
{
	vPos[0] = xPos;
	vPos[1] = yPos;
	vPos[2] = zPos;
}

//
// FUNCI�N: RVCamera::GetDirection()
//
// PROP�SITO: Obtiene la orientaci�n de la c�mara (eje Z).
//
void RVCamera::GetDirection(GLfloat* vDir)
{
	vDir[0] = xDir;
	vDir[1] = yDir;
	vDir[2] = zDir;
}

//
// FUNCI�N: RVCamera::GetUpDirection()
//
// PROP�SITO: Obtiene la orientaci�n cenital de la c�mara (eje Y).
//
void RVCamera::GetUpDirection(GLfloat* vUp)
{
	vUp[0] = xUp;
	vUp[1] = yUp;
	vUp[2] = zUp;
}

//
// FUNCI�N: RVCamera::GetMoveStep()
//
// PROP�SITO: Obtiene el avance en cada paso.
//
GLfloat RVCamera::GetMoveStep()
{
	return moveStep;
}

//
// FUNCI�N: RVCamera::GetTurnStep()
//
// PROP�SITO: Obtiene el �ngulo de giro en cada paso.
//
GLfloat RVCamera::GetTurnStep()
{
	return turnStep;
}

//
// FUNCI�N: RVCamera::MoveFront()
//
// PROP�SITO: Mueve el observador un paso (moveStep) en la direcci�n (-xDir, -yDir, -zDir) 
//
//
void RVCamera::MoveFront()
{
	GLfloat x = xPos - xDir*moveStep;
	GLfloat z = zPos - zDir*moveStep;

	if (!zonaProhibida(x,z) && !zonaPuerta(x,z)) {
		xPos = x;
		yPos -= yDir*moveStep;
		zPos = z;
	}

}

//
// FUNCI�N: RVCamera::MoveBack()
//
// PROP�SITO: Mueve el observador un paso (moveStep) hacia atr�s en la direcci�n (xDir, yDir, zDir) 
//
//
void RVCamera::MoveBack()
{
	GLfloat x = xPos + xDir*moveStep;
	GLfloat z = zPos + zDir*moveStep;

	if (!zonaProhibida(x, z) && !zonaPuerta(x, z)) {
		xPos = x;
		yPos += yDir*moveStep;
		zPos = z;
	}
}

//
// FUNCI�N: RVCamera::MoveLeft()
//
// PROP�SITO: Mueve el observador un paso (moveStep) hacia la izquierda. 
//
//
void RVCamera::MoveLeft()
{
	xPos -= xRight*moveStep;
	yPos -= yRight*moveStep;
	zPos -= zRight*moveStep;
}

//
// FUNCI�N: RVCamera::MoveRight()
//
// PROP�SITO: Mueve el observador un paso (moveStep) hacia la derecha. 
//
//
void RVCamera::MoveRight()
{
	xPos += xRight*moveStep;
	yPos += yRight*moveStep;
	zPos += zRight*moveStep;
}

//
// FUNCI�N: RVCamera::MoveUp()
//
// PROP�SITO: Mueve el observador un paso (moveStep) hacia arriba. 
//
//
void RVCamera::MoveUp()
{
	xPos += xUp*moveStep;
	yPos += yUp*moveStep;
	zPos += zUp*moveStep;
}

//
// FUNCI�N: RVCamera::MoveDown()
//
// PROP�SITO: Mueve el observador un paso (moveStep) hacia abajo. 
//
void RVCamera::MoveDown()
{
	xPos -= xUp*moveStep;
	yPos -= yUp*moveStep;
	zPos -= zUp*moveStep;
}

//
// FUNCI�N: RVCamera::TurnRight()
//
// PROP�SITO: Rota el observador un paso (angleStep) hacia su derecha.
//
void RVCamera::TurnRight()
{
	xDir = cosAngle*xDir - sinAngle*xRight;
	yDir = cosAngle*yDir - sinAngle*yRight;
	zDir = cosAngle*zDir - sinAngle*zRight;

	// Right = Up x Dir
	xRight = yUp*zDir - zUp*yDir;
	yRight = zUp*xDir - xUp*zDir;
	zRight = xUp*yDir - yUp*xDir;
}

//
// FUNCI�N: RVCamera::TurnLeft()
//
// PROP�SITO: Rota el observador un paso (angleStep) hacia su izquierda.
//
void RVCamera::TurnLeft()
{
	xDir = cosAngle*xDir + sinAngle*xRight;
	yDir = cosAngle*yDir + sinAngle*yRight;
	zDir = cosAngle*zDir + sinAngle*zRight;

	// Right = Up x Dir
	xRight = yUp*zDir - zUp*yDir;
	yRight = zUp*xDir - xUp*zDir;
	zRight = xUp*yDir - yUp*xDir;
}

//
// FUNCI�N: RVCamera::TurnUp()
//
// PROP�SITO: Rota el observador un paso (angleStep) hacia arriba.
//
void RVCamera::TurnUp()
{
	xDir = cosAngle*xDir - sinAngle*xUp;
	yDir = cosAngle*yDir - sinAngle*yUp;
	zDir = cosAngle*zDir - sinAngle*zUp;

	// Up = Dir x Right
	xUp = yDir*zRight - zDir*yRight;
	yUp = zDir*xRight - xDir*zRight;
	zUp = xDir*yRight - yDir*xRight;
}

//
// FUNCI�N: RVCamera::TurnDown()
//
// PROP�SITO: Rota el observador un paso (angleStep) hacia abajo.
//
void RVCamera::TurnDown()
{
	xDir = cosAngle*xDir + sinAngle*xUp;
	yDir = cosAngle*yDir + sinAngle*yUp;
	zDir = cosAngle*zDir + sinAngle*zUp;

	// Up = Dir x Right
	xUp = yDir*zRight - zDir*yRight;
	yUp = zDir*xRight - xDir*zRight;
	zUp = xDir*yRight - yDir*xRight;
}

//
// FUNCI�N: RVCamera::TurnCW()
//
// PROP�SITO: Rota el observador un paso (angleStep) en sentido del reloj.
//
void RVCamera::TurnCW()
{
	xUp = cosAngle*xUp + sinAngle*xRight;
	yUp = cosAngle*yUp + sinAngle*yRight;
	zUp = cosAngle*zUp + sinAngle*zRight;

	// Right = Up x Dir
	xRight = yUp*zDir - zUp*yDir;
	yRight = zUp*xDir - xUp*zDir;
	zRight = xUp*yDir - yUp*xDir;
}

//
// FUNCI�N: RVCamera::TurnDown()
//
// PROP�SITO: Rota el observador un paso (angleStep) en sentido contrario al reloj.
//
void RVCamera::TurnCCW()
{
	xUp = cosAngle*xUp - sinAngle*xRight;
	yUp = cosAngle*yUp - sinAngle*yRight;
	zUp = cosAngle*zUp - sinAngle*zRight;

	// Right = Up x Dir
	xRight = yUp*zDir - zUp*yDir;
	yRight = zUp*xDir - xUp*zDir;
	zRight = xUp*yDir - yUp*xDir;
}


//
// FUNCI�N: RVCamera::setZonaPuerta(GLfloat puertas[5][4])
//
// PROP�SITO: obtiene las coordenas de las puertas para impedir o permitir el paso
//
void RVCamera::setZonaPuerta(GLfloat puertas[5][4])
{
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 4; j++) {
			zonaPuertas[i][j] = puertas[i][j];
		}
	}
}


//
// FUNCI�N: RVCamera::zonaProhibida(GLfloat x, GLfloat z)
//
// PROP�SITO: comprueba que la posici�n definida por las coordenadas x y z no se encuentra en una zona prohibida
//
bool RVCamera::zonaProhibida(GLfloat x, GLfloat z)
{
	//Vallas
	if (x >= 95.0f || x <= -95.0f) return true;
	if (z >= 195.0f || z <= -195.0f) return true;
	
	//Muros Exteriores
	if (z >= 70.0f && z <=130.9f && x <= 64.2f && x >= 56.0f) return true;
	if (z >= 70.0f && z <= 130.9f && x >= -64.2f && x <= -56.0f) return true;
	if (z >= 126.0f && z <= 134.0f && ((x >= -61.15f && x <= 6.2f) || (x >= 16.2f && x<=61.15f))) return true;
	if (z >= 68.0f && z <= 76.0f && x >= -61.15f && x <= 61.15f) return true;

	//Piscina
	if (z <= -17.0f && z >= -143.0f && x >= -83.0f && x <= 83.0f) return true;
	
	//Muros Interiores
	if (z <= 102.0f && z >= 73.3f && ((x >= 20.41f && x <= 25.51f) || (x <= -11.65f && x >= -14.75f))) return true;
	if (z <= 102.0f && z >= 98.9f && ((x <= 23.51f && x >= 13.51f) || (x <= 3.51f && x >= -16.49f) || (x <= -26.49f && x >= -61.15f ))) return true;
	if (z <= 113.9f && z >= 109.99f && ((x <= -1.35f && x >= -11.35) || (x <= -21.35f && x >= -33.7f))) return true;
	if (z <= 128.7f && z >= 112.09f && ((x <= -0.35f && x >= -3.45f) || (x <= -31.6f && x >= -34.7f))) return true;

	//muebles
	if (z <= 128.7f && z >= 108.7f && x >= -58.95f && x <= -46.95f) return true;
	if (z <= 96.9f && z >= 76.7f && x >= -58.95f && x <= -39.05f) return true;
	if (z <= 84.9f && z >= 73.3f && x >= -12.65f && x <= 9.35f) return true;
	return false;
}


//
// FUNCI�N: RVCamera::zonaPuerta(GLfloat x, GLfloat z)
//
// PROP�SITO: comprueba que la posici�n definida por las coordenadas x y z no se encuentra en una zona de puertas
//
bool RVCamera::zonaPuerta(GLfloat x, GLfloat z)
{
	int i = 0;

	while (i < 5) {
		if ((zonaPuertas[i][0] - 2.0f) <= x && (2.0f + zonaPuertas[i][1]) > x && (2.0f + zonaPuertas[i][2]) >= z && (zonaPuertas[i][3] - 2.0f) <= z) {
			return true;
		}
		i++;
	}
	return false;
}


