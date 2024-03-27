#include "CParallelepiped.h"

CParallelepiped::CParallelepiped(double density, double width, double height, double depth)
    : m_width(width), m_height(height), m_depth(depth)
{
    m_density = density;
}

double CParallelepiped::GetDensity() const
{
    return m_density;
}

double CParallelepiped::GetVolume() const 
{
    return m_width * m_height * m_depth;
}

double CParallelepiped::GetMass() const 
{
    return GetDensity() * GetVolume();
}

string CParallelepiped::ToString() const 
{
    return "Parallelepiped";
}