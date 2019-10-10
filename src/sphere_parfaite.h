#ifndef SPHERE_PARFAITE_H
#define SPHERE_PARFAITE_H
#include "shape.h"

class Sphere_parfaite : public Shape
{
public:
    Sphere_parfaite();
    virtual ~Sphere_parfaite();
    void init();
    void display(Shader *shader);
    Eigen::Vector3f getCenter(){return _center;}

private:
    GLuint _vbo;
    GLuint _vao;
    Eigen::Vector3f _center;
};


#endif // SPHERE_PARFAITE_H
