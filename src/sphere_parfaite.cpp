#include "sphere_parfaite.h"

using namespace Eigen;

GLfloat vertices2[]  = { 1, 1, 1,  -1, 1, 1,  -1,-1, 1,      // v0-v1-v2 (front)
                       -1,-1, 1,   1,-1, 1,   1, 1, 1,      // v2-v3-v0

                        1, 1, 1,   1,-1, 1,   1,-1,-1,      // v0-v3-v4 (right)
                        1,-1,-1,   1, 1,-1,   1, 1, 1,      // v4-v5-v0

                        1, 1, 1,   1, 1,-1,  -1, 1,-1,      // v0-v5-v6 (top)
                       -1, 1,-1,  -1, 1, 1,   1, 1, 1,      // v6-v1-v0

                       -1, 1, 1,  -1, 1,-1,  -1,-1,-1,      // v1-v6-v7 (left)
                       -1,-1,-1,  -1,-1, 1,  -1, 1, 1,      // v7-v2-v1

                       -1,-1,-1,   1,-1,-1,   1,-1, 1,      // v7-v4-v3 (bottom)
                        1,-1, 1,  -1,-1, 1,  -1,-1,-1,      // v3-v2-v7

                        1,-1,-1,  -1,-1,-1,  -1, 1,-1,      // v4-v7-v6 (back)
                       -1, 1,-1,   1, 1,-1,   1,-1,-1 };    // v6-v5-v4




Sphere_parfaite::Sphere_parfaite()
{
    _center = Vector3f(0,0,0);
    glGenBuffers(1, &_vbo);

    glBindBuffer(GL_ARRAY_BUFFER,_vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices2), vertices2, GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    _bbox.extend(Vector3f(-1,-1,-1));
    _bbox.extend(Vector3f(1,1,1));

    _ready = false;

}

Sphere_parfaite::~Sphere_parfaite()
{
    glDeleteBuffers(1,&_vbo);
}

void Sphere_parfaite::init()
{
    glGenVertexArrays(1,&_vao);

    glBindVertexArray(_vao);

    glBindBuffer(GL_ARRAY_BUFFER, _vbo);

    glBindVertexArray(0);

    checkError();

    _ready = true;
}

void Sphere_parfaite::display(Shader *shader)
{
    if(!_ready)
        init();

    glBindVertexArray(_vao);

    // Recuperation des emplacements des deux attributs dans le shader
    int vertexPositionIndex = shader->getAttribLocation("vtx_position");

    if(vertexPositionIndex >=0)
    {
        glBindBuffer(GL_ARRAY_BUFFER, _vbo);
        glVertexAttribPointer(vertexPositionIndex, 3, GL_FLOAT, GL_FALSE, 0, 0);
        glEnableVertexAttribArray(vertexPositionIndex);
    }

    glDrawArrays(GL_TRIANGLES, 0, 36);

    if(vertexPositionIndex>=0)
        glDisableVertexAttribArray(vertexPositionIndex);

    glBindVertexArray(0);
}
