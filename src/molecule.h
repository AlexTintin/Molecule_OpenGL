#ifndef MOLECULE_H
#define MOLECULE_H
#include "sphere_parfaite.h"
#include "opengl.h"
#include <Eigen/Eigen>

class Molecule : public Sphere_parfaite
{
public:
    Molecule();
    Eigen::Vector3f getColorAtome(int i){return _colors.row(i);}
    Eigen::Vector3f getPositionAtome(int i){return _positions.row(i);}
    Eigen::Vector3f getPositionCube(int i){return _positions_c.row(i);}
    float getOrientationCube(int i){return _rotation_c[i];}
    float getRadiusAtome(int i){return _rayons[i];}
    int getNbAtome(){return _rayons.size();}


private:

    Eigen::MatrixXf _colors;
    Eigen::VectorXf _rayons;
    Eigen::MatrixXf _positions;
    Eigen::MatrixXf _positions_c;
    Eigen::VectorXf _rotation_c;
};
#endif // MOLECULE_H
