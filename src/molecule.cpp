#include "molecule.h"



using namespace Eigen;


//                          NO2
//                          /
//molécule de TNT       C--C
//                     /    \
//               NO2--C      C--CH3
//                     \    /
//                      C--C
//                          \
//                           NO2





//notre molécule n'est pas à l'échelle ! c'est un souhait !



Molecule::Molecule()
{
    _positions.resize(19,3);
    _colors.resize(19,3);
    _rayons.resize(19);
    _positions_c.resize(9,3);
    _rotation_c.resize(9);



   // 6 carbone répartie uniformément sur un cercle

    for (int i=0; i<6; i++)
    {
        _positions.row(i) = 4.7*Vector3f(std::sin(M_PI*i/3),std::cos(M_PI*i/3),0);
        _colors.row(i)= Vector3f(0.2,0.2,0.2);
        _rayons(i) = 1.5f;
    }
    // 3 azotes répartie uniformément sur un cercle

    for (int j=6; j<9; j++)
    {
        _positions.row(j) = 7*Vector3f(std::sin(2*M_PI*j/3),std::cos(2*M_PI*j/3),0);
        _colors.row(j)= Vector3f(0,0,0.8);
        _rayons(j) = 1.f;
    }
// 3 oxygènes répartie uniformément sur un cercle
    for (int k=9; k<12; k++)
    {
        _positions.row(k) = 8*Vector3f(std::sin(2*M_PI*k/3+(M_PI/18)),std::cos(2*M_PI*k/3+(M_PI/18)),0.1);
        _colors.row(k)= Vector3f(0.8,0,0);
        _rayons(k) = 1.f;
    }

    // 3 oxygène répartie uniformément sur un cercle
    for (int m=12; m<15; m++)
    {
        _positions.row(m) = 8*Vector3f(std::sin(2*M_PI*m/3-(M_PI/18)),std::cos(2*M_PI*m/3-(M_PI/18)),-0.1);
        _colors.row(m)= Vector3f(0.8,0,0);
        _rayons(m)= 1.f;
    }

    // un carbone d'une liason méthyl
    _positions.row(15) = 8*Vector3f(std::sin(M_PI/3)-0.05,std::cos(M_PI/3)-0.05,0);
    _colors.row(15)= Vector3f(0.2,0.2,0.2);
    _rayons(15)= 1.5f;

    // 3 hydrogène sur le carbone du méthyl
        _positions.row(16) = 8*Vector3f(std::sin(M_PI/3)-0.05,std::cos(M_PI/3)-0.05,0) + 1.8*Vector3f(std::sin(2*M_PI/3),std::cos(2*M_PI/3),0);
        _colors.row(16)= Vector3f(1,1,1);
        _rayons(16)= 0.5f;

        _positions.row(17) = 8*Vector3f(std::sin(M_PI/3)-0.05,std::cos(M_PI/3)-0.05,0) + 1.8*Vector3f(std::sin(2*M_PI/3)-0.5,std::cos(2*M_PI/3)+1.3,-0.6);
        _colors.row(17)= Vector3f(1,1,1);
        _rayons(17)= 0.5f;

        _positions.row(18) = 8*Vector3f(std::sin(M_PI/3)-0.05,std::cos(M_PI/3)-0.05,0) + 1.8*Vector3f(std::sin(2*M_PI/3)-1.2,std::cos(2*M_PI/3)+1.2,+0.5);
        _colors.row(18)= Vector3f(1,1,1);
        _rayons(18)= 0.5f;


        for (int i=0; i<6; i++)
        {
            _positions_c.row(i) = 4.7*Vector3f(std::sin(M_PI*i/3+M_PI/6),std::cos(M_PI*i/3+M_PI/6),0);
            _rotation_c(i) = M_PI-M_PI*(i)/3-M_PI/6;
        }

        for (int i=6; i<9; i++)
        {
            _positions_c.row(i) = 4*Vector3f(std::sin(2*M_PI*i/3+M_PI/6),std::cos(2*M_PI*i/3+M_PI/6),0);
            _rotation_c(i) = M_PI-2*M_PI*(i)/3-M_PI/6;
        }

   _bbox.extend(Eigen::Vector3f(-5,-5,-5));
   _bbox.extend(Eigen::Vector3f(5,5,5));



}

