#include "game.h"
#include "GL/glut.h"

using namespace Game;

Player::Player() {

}

void Player::draw() {
  glColor3f(1,0,0);
  glBegin(GL_QUADS);
  glVertex2f(-4,-4);
  glVertex2f(-4,-2);
  glVertex2f(-2,-2);
  glVertex2f(-2,-4);
  glEnd();
}

void Player::key(int key) {
  switch(key) {
    case GLUT_KEY_UP:
    case GLUT_KEY_DOWN:
    case GLUT_KEY_LEFT:
    case GLUT_KEY_RIGHT:
      glRotatef(100,0,0,1);
      break;
  }
}
