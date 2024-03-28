// CCompound.cpp
#include "CCompound.h"
#include <sstream>

double CCompound::GetDensity() const
{
    double totalMass = GetMass();
    double totalVolume = GetVolume();
    return totalVolume != 0 ? totalMass / totalVolume : 0.0;
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

std::string GenerateIndentedString(const std::string& str, int indentation)
{
    std::string indent(indentation, ' ');
    std::stringstream ss;
    ss << indent << str << "\n";
    return ss.str();
}

std::string CCompound::ToString() const
{
    return ToStringRecursive(0);
}

std::string CCompound::ToStringRecursive(int indentation) const
{
    std::string compoundInfo;
    std::string indent(indentation, ' ');

    compoundInfo += GenerateIndentedString("Compound Body:", indentation);

    for (const auto& body : m_bodies)
    {
        compoundInfo += body->ToString();
        if (auto compound = dynamic_pointer_cast<CCompound>(body))
        {
            compoundInfo += compound->ToStringRecursive(indentation + 5);
        }
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
