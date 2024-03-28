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
    string ParallelepipedInfo = "Parallelepiped\n";
    ParallelepipedInfo += "Density: " + to_string(GetDensity()) + "\n";
    ParallelepipedInfo += "Mass: " + to_string(GetMass()) + "\n";
    ParallelepipedInfo += "Volume: " + to_string(GetVolume()) + "\n";

    return ParallelepipedInfo;
}