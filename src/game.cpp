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
      addY(0.01f);
      break;
    case GLUT_KEY_DOWN:
      subY(0.01f);
      break;
    case GLUT_KEY_LEFT:
      subX(0.01f);
      break;
    case GLUT_KEY_RIGHT:
      addX(0.01f);
      break;
  }
}

// TREE

Tree::Tree(Base* engine) : Object(engine) {
  texture = engine->loadImage("data/img/objects/tree.png");
  setX(0.3f);
  setY(0.3f);
}

void Tree::draw() {
  engine->bindTexture(texture);
  drawQuad(texture->getWidth(), texture->getHeight());
}

void Tree::key(int key) {
}

// GRASS

Grass::Grass(Base* engine) : Object(engine) {
  texture = engine->loadImage("data/img/objects/grass.png");
}

void Grass::draw() {
  engine->bindTexture(texture);
  draw2dQuad(engine->WIDTH, engine->HEIGHT);
}

void Grass::key(int key) {
}
