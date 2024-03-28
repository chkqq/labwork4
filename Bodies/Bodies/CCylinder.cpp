#include "CCylinder.h"
#include <cmath>
#define _USE_MATH_DEFINES
#include <math.h>

CCylinder::CCylinder(double density, double baseRadius, double height)
    : m_baseRadius(baseRadius), m_height(height) 
{
    m_density = density;
}

double CCylinder::GetDensity() const
{
    return m_density;
}

double CCylinder::GetVolume() const 
{
    return M_PI * pow(m_baseRadius, 2) * m_height;
}

double CCylinder::GetMass() const 
{
    return GetDensity() * GetVolume();
}

string CCylinder::ToString() const
{
    string CylinderInfo = "Cylinder\n";
    CylinderInfo += "Density: " + to_string(GetDensity()) + "\n";
    CylinderInfo += "Mass: " + to_string(GetMass()) + "\n";
    CylinderInfo += "Volume: " + to_string(GetVolume()) + "\n";
    return CylinderInfo;
}