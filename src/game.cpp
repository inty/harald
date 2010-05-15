#include "game.h"
#include "GL/glut.h"

using namespace Game;
using namespace Engine;

Player::Player(Base* engine) : Object(engine) {

}

void Player::draw() {
  engine->loadImage("data/img/objects/player.png");
  glBegin(GL_QUADS);
  glTexCoord2i(0, 0);
  glVertex2i(0, 0);
  glTexCoord2i(0, 1);
  glVertex2i(0, 32);
  glTexCoord2i(1, 1);
  glVertex2i(32, 32);
  glTexCoord2i(1, 0);
  glVertex2i(32, 0);
  glEnd();
}

void Player::key(int key) {
  switch(key) {
    case GLUT_KEY_UP:
      glTranslatef(0.0f,-2.0f,0.0f);
      break;
    case GLUT_KEY_DOWN:
      glTranslatef(0.0f,2.0f,0.0f);
      break;
    case GLUT_KEY_LEFT:
      glTranslatef(-2.0f,0.0f,0.0f);
      break;
    case GLUT_KEY_RIGHT:
      glTranslatef(2.0f,0.0f,0.0f);
      break;
  }
}

