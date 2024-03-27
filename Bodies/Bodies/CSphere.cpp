#include "CSphere.h"
#define _USE_MATH_DEFINES
#include <math.h>

CSphere::CSphere(double density, double radius)
    : m_radius(radius) 
{
    m_density = density;
}

double CSphere::GetDensity() const
{
    return m_density;
}

double CSphere::GetVolume() const
{
    return (4.0 / 3.0) * M_PI * pow(m_radius, 3);
}

double CSphere::GetMass() const 
{
    return GetDensity() * GetVolume();
}

std::string CSphere::ToString() const 
{
    return "Sphere";
}
