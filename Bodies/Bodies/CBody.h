#pragma once
#include <memory>
#include <string>
#include <vector>

using namespace std;

class CBody
{
public:
    virtual double GetDensity() const = 0;
    virtual double GetVolume() const = 0;
    virtual double GetMass() const = 0;
    virtual string ToString() const = 0;
    virtual ~CBody() {}

protected:
    double m_density;
};

using BodyPtr = shared_ptr<CBody>;

// ќбъ€влени€ классов тел: CSphere, CParallelepiped, CCone, CCylinder, CCompound

// ќбъ€влени€ функций поиска тел с наибольшей массой и тела, которое будет легче всего весить в воде
BodyPtr MaxBodyMass(const vector<BodyPtr>& bodies);
BodyPtr MinWeightInWater(const vector<BodyPtr>& bodies);
