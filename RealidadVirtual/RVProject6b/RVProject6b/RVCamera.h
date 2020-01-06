#ifndef RVCAMERA_H
#define RVCAMERA_H

#include <glew.h>

class RVCamera {
public:
	RVCamera();
    void PlaceCamera();

    void SetPosition(GLfloat x, GLfloat y, GLfloat z);
    void SetDirection(GLfloat xDir, GLfloat yDir, GLfloat zDir, GLfloat xUp, GLfloat yUp, GLfloat zUp);
    void SetMoveStep(GLfloat step);
    void SetTurnStep(GLfloat step);

    void GetPosition(GLfloat* vPos);
    void GetDirection(GLfloat* vDir); 
    void GetUpDirection(GLfloat* vUp); 
    GLfloat GetMoveStep();
    GLfloat GetTurnStep();

    void MoveFront();
    void MoveBack();
    void MoveRight();
    void MoveLeft();
    void MoveUp();
    void MoveDown(); 

    void TurnRight();
    void TurnLeft();
    void TurnUp();
    void TurnDown();
    void TurnCW();
    void TurnCCW();

	void setZonaPuerta(GLfloat puertas[5][4]);

private:
	GLfloat xPos;
    GLfloat yPos;
    GLfloat zPos;

    GLfloat xDir;
    GLfloat yDir;
    GLfloat zDir;

    GLfloat xUp;
    GLfloat yUp;
    GLfloat zUp;

    GLfloat xRight;
    GLfloat yRight;
    GLfloat zRight;

	GLfloat moveStep;
    GLfloat turnStep;
    GLfloat cosAngle;
    GLfloat sinAngle;

	GLfloat zonaPuertas[5][4];
	bool zonaProhibida(GLfloat x, GLfloat z);
	bool zonaPuerta(GLfloat x, GLfloat z);
};

#endif