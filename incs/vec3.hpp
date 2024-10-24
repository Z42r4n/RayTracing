#ifndef VEC3_HPP
#define VEC3_HPP

class Vec3
{

public:
    double e[3];

    Vec3() : e{0, 0, 0} {}
    Vec3(double e1, double e2, double e3) : e{e1, e2, e3} {}

    double x() const { return e[0]; }
    double y() const { return e[1]; }
    double z() const { return e[2]; }

    Vec3 operator-() { return Vec3(-e[0], -e[1], -e[2]); }
    double operator[](int i) { return e[i]; }
};

#endif // VEC3_HPP