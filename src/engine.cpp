#include "engine.h"
#include <iostream>

using namespace std;
using namespace Engine;

const int Base::WIDTH = 640;
const int Base::HEIGHT = 480;
const char* Base::NAME = "harald";

ObjectList Window::objects;

// Object

Object::Object(Base* engine) {
  this->engine = engine;
  x = 0;
  y = 0;
}

void Object::addX(float x) {
  Object::x += x;
}

void Object::addY(float y) {
  Object::y += y;
}

void Object::subX(float x) {
  Object::x -= x;
}

void Object::subY(float y) {
  Object::y -= y;
}

float Object::getX() {
  return x;
}

float Object::getY() {
  return y;
}

void Object::setY(float y) {
  Object::y = y;
}

void Object::setX(float x) {
  Object::x = x;
}

void Object::drawQuad(int w, int h) {
  glLoadIdentity();
  glTranslatef(getX() + 0.0f, getY() + 0.0f, 0.0f);
  glRotatef(20.0f,1.0f,0.5f,0);
  glBegin(GL_QUADS);
    // Front
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.1f, -0.1f,  0.1f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f( 0.1f, -0.1f,  0.1f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f( 0.1f,  0.1f,  0.1f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.1f,  0.1f,  0.1f);
    // Back
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-0.1f, -0.1f, -0.1f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-0.1f,  0.1f, -0.1f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f( 0.1f,  0.1f, -0.1f);
    glTexCoord2f(0.0f, 0.0f); glVertex3f( 0.1f, -0.1f, -0.1f);
    // Top
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.1f,  0.1f, -0.1f);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.1f,  0.1f,  0.1f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f( 0.1f,  0.1f,  0.1f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f( 0.1f,  0.1f, -0.1f);
    // Bottom
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-0.1f, -0.1f, -0.1f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f( 0.1f, -0.1f, -0.1f);
    glTexCoord2f(0.0f, 0.0f); glVertex3f( 0.1f, -0.1f,  0.1f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-0.1f, -0.1f,  0.1f);
    // Right
    glTexCoord2f(1.0f, 0.0f); glVertex3f( 0.1f, -0.1f, -0.1f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f( 0.1f,  0.1f, -0.1f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f( 0.1f,  0.1f,  0.1f);
    glTexCoord2f(0.0f, 0.0f); glVertex3f( 0.1f, -0.1f,  0.1f);
    // Left
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.1f, -0.1f, -0.1f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-0.1f, -0.1f,  0.1f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-0.1f,  0.1f,  0.1f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.1f,  0.1f, -0.1f);
  glEnd();
}

void Object::draw2dQuad(int w, int h) {
  glDisable(GL_DEPTH_TEST);
  glMatrixMode(GL_PROJECTION);
  glPushMatrix();
  glLoadIdentity();
  glOrtho(0,engine->WIDTH,0,engine->HEIGHT,-1,1);
  glMatrixMode(GL_MODELVIEW);
  glPushMatrix();
  glLoadIdentity();

  glBegin(GL_QUADS);
  glTexCoord2i(0, 0);
  glVertex2i(0, 0);
  glTexCoord2i(0, 1);
  glVertex2i(0, h);
  glTexCoord2i(1, 1);
  glVertex2i(w, h);
  glTexCoord2i(1, 0);
  glVertex2i(w, 0);
  glEnd();

  glMatrixMode(GL_PROJECTION);
  glPopMatrix();
  glMatrixMode(GL_MODELVIEW);
  glPopMatrix();
  glEnable(GL_DEPTH_TEST);
}

// Window

Window::Window(int argc, char* argv[], int width, int height, char* name) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
  glutInitWindowPosition(100,100);
  glutInitWindowSize(width, height);
  glutCreateWindow(name);

  // bind some callbacks
  glutDisplayFunc(&display);
  glutIdleFunc(&display);
  glutTimerFunc(0,&timer,0);
  glutKeyboardFunc(&keyboard);
  glutSpecialFunc(&specialKeyboard);
  glutReshapeFunc(&reshape);

  // enable some features
  glEnable(GL_TEXTURE_2D);
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT1);

  // clear screen
  glClearColor(0.8f, 0.8f, 0.8f, 0.5f);
  glClearDepth(1.0f);

  glShadeModel(GL_SMOOTH);
  glDepthFunc(GL_LEQUAL);

  glViewport(0, 0, width, height);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  // fancy lightning
  GLfloat lightAmbient[] = { 0.5f, 0.5f, 0.5f, 1.0f };
  GLfloat lightDiffuse[]= { 0.8f, 0.8f, 0.5f, 1.0f };
  GLfloat lightPos[]= { 1.0f, 0.0f, 2.0f, 1.0f };
  glLightfv(GL_LIGHT1, GL_AMBIENT, lightAmbient);
  glLightfv(GL_LIGHT1, GL_DIFFUSE, lightDiffuse);
  glLightfv(GL_LIGHT1, GL_POSITION, lightPos);

}

void Window::reshape(int w, int h) {
  glViewport(0, 0, w, h);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

void Window::keyboard(unsigned char key, int x, int y) {
  switch(key) {
    case 27:
      exit(0);
      break;
  }
}

void Window::specialKeyboard(int key, int x, int y) {
  for(ObjectList::const_iterator iter = objects.begin(),
    endIter = objects.end(); iter != endIter; ++iter) {
    Object *object = *iter;
    object->key(key);
  }
}

void Window::run() {
  glutMainLoop();
}

void Window::add(Object* object) {
  objects.push_back(object);
}

void Window::display() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  float time = glutGet(GLUT_ELAPSED_TIME);

  for(ObjectList::const_iterator iter = objects.begin(),
    endIter = objects.end(); iter != endIter; ++iter) {
    Object *object = *iter;
    object->draw();
  }

  glutSwapBuffers();

  glFlush();
}

void Window::timer(int time) {
  glutPostRedisplay();
  glutTimerFunc(1000/30,&timer,0);
}

// Base

Base::Base(int argc, char* argv[]) {
  window = new Window(argc, argv, WIDTH, HEIGHT, (char*)NAME);
}

void Base::add(Object* object) {
  window->add(object);
}

void Base::run() {
  window->run();
}

Texture* Base::loadImage(char* filename) {
  if (textures[filename] == NULL) {
    GLuint image;
    ILuint texid;
    ilInit();
    ilGenImages(1, &texid);
    ilBindImage(texid);
    if (ilLoadImage(filename)) {
      if (ilConvertImage(IL_RGB, IL_UNSIGNED_BYTE)) {
        glGenTextures(1, &image);
        glBindTexture(GL_TEXTURE_2D, image);
        textures[filename] = new Texture(ilGetInteger(IL_IMAGE_BPP), ilGetInteger(IL_IMAGE_WIDTH),
          ilGetInteger(IL_IMAGE_HEIGHT), ilGetInteger(IL_IMAGE_FORMAT), ilGetData());
      }
    }
  }
  return textures[filename];
}

void Base::bindTexture(Texture* texture) {

  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

  glTexImage2D(GL_TEXTURE_2D, 0, texture->getInternalFormat(), texture->getWidth(),
    texture->getHeight(), 0, texture->getFormat(), GL_UNSIGNED_BYTE,
    texture->getData());
}

// Texture

Texture::Texture(GLint internalFormat, GLsizei width, GLsizei height,
    GLenum format, GLvoid* data) {
  Texture::internalFormat = internalFormat;
  Texture::width = width;
  Texture::height = height;
  Texture::format = format;
  Texture::data = data;
}

GLint Texture::getInternalFormat() {
  return internalFormat;
}

GLsizei Texture::getWidth() {
  return width;
}

GLsizei Texture::getHeight() {
  return height;
}

GLenum Texture::getFormat() {
  return format;
}

GLvoid* Texture::getData() {
  return data;
}

