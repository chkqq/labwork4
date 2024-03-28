#include <iostream>
#include <vector>
#include <sstream>
#include "CBody.h"
#include "CSphere.h"
#include "CParallelepiped.h"
#include "CCone.h"
#include "CCylinder.h"
#include "CCompound.h"

using namespace std;

bool ValidateInput() {
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return false;
    }
    return true;
}


void DisplayMenu() {
    cout << "=== Body Control Menu ===\n"
        << "1. Create Sphere <density> <radius>\n"
        << "2. Create Parallelepiped <density> <width> <height> <depth>\n"
        << "3. Create Cone <density> <base_radius> <height>\n"
        << "4. Create Cylinder <density> <base_radius> <height>\n"
        << "5. Add Compound Body\n"
        << "6. Find Body with Maximum Mass\n"
        << "7. Find Body with Minimum Weight in Water\n"
        << "8. Display All Bodies\n"
        << "9. Exit\n"
        << "=======================\n";
}

void CreateSphere(vector<BodyPtr>& bodies, double density, double radius) 
{
    bodies.push_back(make_shared<CSphere>(density, radius));
    cout << "Sphere created successfully!\n";
}

void CreateParallelepiped(vector<BodyPtr>& bodies, double density, double width, double height, double depth) 
{
    bodies.push_back(make_shared<CParallelepiped>(density, width, height, depth));
    cout << "Parallelepiped created successfully!\n";
}

void CreateCone(vector<BodyPtr>& bodies, double density, double baseRadius, double height) 
{
    bodies.push_back(make_shared<CCone>(density, baseRadius, height));
    cout << "Cone created successfully!\n";
}

void CreateCylinder(vector<BodyPtr>& bodies, double density, double baseRadius, double height) 
{
    bodies.push_back(make_shared<CCylinder>(density, baseRadius, height));
    cout << "Cylinder created successfully!\n";
}

void FindMaxBodyMass(vector<BodyPtr>& bodies)
{
    auto maxMassBody = MaxBodyMass(bodies);
    if (maxMassBody)
    {
        cout << "Body with maximum mass:\n" << maxMassBody->ToString() << endl;
        cout << "Mass: " << maxMassBody->GetMass() << endl;
    }
    else
    {
        cout << "No bodies found!" << endl;
    }
}

void FindMinWeightInWater(vector<BodyPtr>& bodies)
{
    auto minWeightInWaterBody = MinWeightInWater(bodies);
    if (minWeightInWaterBody) 
    {
        cout << "Body with minimum weight in water:\n" << minWeightInWaterBody->ToString() 
             << " with mass " << minWeightInWaterBody->GetMass() << endl;
        double weightDiff = minWeightInWaterBody->GetMass() - (1000 * minWeightInWaterBody->GetVolume());
        cout << "Weight difference: " << weightDiff << endl;
    }
    else {
        cout << "No bodies found!" << endl;
    }
}

shared_ptr<CCompound> AddCompoundBodyRecursive(int indentation = 0)
{
    auto compound = make_shared<CCompound>();

    int numComponents;
    cout << "Enter the number of components: ";
    cin >> numComponents;

    if (!ValidateInput())
    {
        cout << "Invalid input! Please enter a valid number." << endl;
        return nullptr;
    }

    double density, radius, width, height, depth, baseRadius;

    for (int i = 0; i < numComponents; ++i)
    {
        for (int i = 0; i < indentation; ++i)
        {
            cout << " ";
        }
        cout << "Enter component type (1. Sphere, 2. Parallelepiped, 3. Cone, 4. Cylinder,  5. Compound): ";
        int choice;
        cin >> choice;

        if (!ValidateInput()) {
            cout << "Invalid input! Please enter a valid number." << endl;
            --i;
            continue;
        }

        for (int i = 0; i < indentation; ++i)
        {
            cout << " ";
        }

        switch (choice)
        {
        case 1:
            cout << "Enter density and radius: ";
            cin >> density >> radius;
            if (!ValidateInput())
            {
                cout << "Invalid input! Please enter valid numbers." << endl;
                --i;
                continue;
            }
            compound->AddChildBody(make_shared<CSphere>(density, radius));
            break;
        case 2:
            cout << "Enter density, width, height, and depth: ";
            cin >> density >> width >> height >> depth;
            if (!ValidateInput())
            {
                cout << "Invalid input! Please enter valid numbers." << endl;
                --i;
                continue;
            }
            compound->AddChildBody(make_shared<CParallelepiped>(density, width, height, depth));
            break;
        case 3:
            cout << "Enter density, base radius, and height: ";
            cin >> density >> baseRadius >> height;
            if (!ValidateInput())
            {
                cout << "Invalid input! Please enter valid numbers." << endl;
                --i;
                continue;
            }
            compound->AddChildBody(make_shared<CCone>(density, baseRadius, height));
            break;
        case 4:
            cout << "Enter density, base radius, and height: ";
            cin >> density >> baseRadius >> height;
            if (!ValidateInput())
            {
                cout << "Invalid input! Please enter valid numbers." << endl;
                --i;
                continue;
            }
            compound->AddChildBody(make_shared<CCylinder>(density, baseRadius, height));
            break;
        case 5:
            compound->AddChildBody(AddCompoundBodyRecursive(indentation + 4));
            break;
        default:
            cout << "Invalid component type! Please try again.\n";
            --i;
            break;
        }
    }
    return compound;
}

void AddCompoundBody(vector<BodyPtr>& bodies)
{
    auto finalcompound = AddCompoundBodyRecursive();
    if (finalcompound)
    {
        bodies.push_back(finalcompound);
        cout << "Compound body added successfully!\n";
    }
}


int main() 
{
    vector<BodyPtr> bodies;

    int choice = 0;
    double density, radius, width, height, depth, baseRadius;

    while (choice != 9) {
        
        cout << "> ";
        cin >> choice;

        switch (choice) {
        case 0:
            DisplayMenu();
            break;
        case 1:
            cout << "Enter density and radius: ";
            cin >> density >> radius;
            if (!ValidateInput()) {
                cout << "Invalid input! Please enter valid numbers." << endl;
                break;
            }
            CreateSphere(bodies, density, radius);
            break;
        case 2:
            cout << "Enter density, width, height, and depth: ";
            cin >> density >> width >> height >> depth;
            if (!ValidateInput()) {
                cout << "Invalid input! Please enter valid numbers." << endl;
                break;
            }
            CreateParallelepiped(bodies, density, width, height, depth);
            break;
        case 3:
            cout << "Enter density, base radius, and height: ";
            cin >> density >> baseRadius >> height;
            if (!ValidateInput()) {
                cout << "Invalid input! Please enter valid numbers." << endl;
                break;
            }
            CreateCone(bodies, density, baseRadius, height);
            break;
        case 4:
            cout << "Enter density, base radius, and height: ";
            cin >> density >> baseRadius >> height;
            if (!ValidateInput()) {
                cout << "Invalid input! Please enter valid numbers." << endl;
                break;
            }
            CreateCylinder(bodies, density, baseRadius, height);
            break;
        case 5:
            AddCompoundBody(bodies);
            break;
        case 6:
        {
            FindMaxBodyMass(bodies);
        }
        break;
        case 7:
        {
            FindMinWeightInWater(bodies);
           
        }
        break;
        case 8:
            cout << "All Bodies:\n";
            for (const auto& body : bodies) {
                cout << body->ToString() <<endl;
                cout << "Density: " << body->GetDensity() << endl;
                cout << "Volume: " << body->GetVolume() << endl;
                cout << "Mass: " << body->GetMass() << endl;
                cout << endl;
            }
        break;
        case 9:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid command. Type 'help' or '0' for the list of commands.\n";
            break;
        }
    }

    return 0;
}
