#include "CCompound.h"
double CCompound::GetDensity() const 
{
    double totalMass = 0.0;
    double totalVolume = 0.0;
    for (const auto& body : m_bodies) 
    {
        totalMass += body->GetMass();
        totalVolume += body->GetVolume();
    }
    return totalMass / totalVolume;
}

double CCompound::GetVolume() const 
{
    double totalVolume = 0.0;
    for (const auto& body : m_bodies) 
    {
        totalVolume += body->GetVolume();
    }
    return totalVolume;
}

double CCompound::GetMass() const 
{
    double totalMass = 0.0;
    for (const auto& body : m_bodies) 
    {
        totalMass += body->GetMass();
    }
    return totalMass;
}

std::string CCompound::ToString() const 
{
    std::string compoundInfo = "Compound Body:\n";
    for (const auto& body : m_bodies)
    {
        compoundInfo += body->ToString() + "\n";
    }
    return compoundInfo;
}

bool CCompound::AddChildBody(const BodyPtr& body) 
{
    if (Contains(body)) 
    {
        return false;
    }
    m_bodies.push_back(body);
    return true;
}

bool CCompound::Contains(const BodyPtr& body) const 
{
    for (const auto& b : m_bodies) 
    {
        if (b.get() == body.get()) 
        {
            return true;
        }
        if (auto compound = std::dynamic_pointer_cast<CCompound>(b)) 
        {
            if (compound->Contains(body)) 
            {
                return true;
            }
        }
    }
    return false;
}