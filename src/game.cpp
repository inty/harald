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
  drawQuad(texture->getWidth(), texture->getHeight());
}

void Player::key(int key) {
  switch(key) {
    case GLUT_KEY_UP:
      subY(1);
      break;
    case GLUT_KEY_DOWN:
      addY(1);
      break;
    case GLUT_KEY_LEFT:
      subX(1);
      break;
    case GLUT_KEY_RIGHT:
      addX(1);
      break;
  }
}

// TREE

Tree::Tree(Base* engine) : Object(engine) {
  texture = engine->loadImage("data/img/objects/tree.png");
  setX(200);
  setY(200);
}

void Tree::draw() {
  engine->bindTexture(texture);
  drawQuad(texture->getWidth(), texture->getHeight());
}

void Tree::key(int key) {
}

