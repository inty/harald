#include "game.h"
#include "GL/glut.h"
#include <IL/il.h>
#include <iostream>

using namespace Game;
using namespace Engine;

// PLAYER

Player::Player(Base* engine) : Object(engine) {
  texture = engine->loadImage("data/img/objects/player.png");
}

void Player::draw() {
  engine->bindTexture(texture);
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

// TREE

Tree::Tree(Base* engine) : Object(engine) {
  texture = engine->loadImage("data/img/objects/tree.png");
}

void Tree::draw() {
  engine->bindTexture(texture);
  glBegin(GL_QUADS);
  glTexCoord2i(0, 0);
  glVertex2i(200, 200);
  glTexCoord2i(0, 1);
  glVertex2i(200, 264);
  glTexCoord2i(1, 1);
  glVertex2i(264, 264);
  glTexCoord2i(1, 0);
  glVertex2i(264, 200);
  glEnd();
}

void Tree::key(int key) {
}

