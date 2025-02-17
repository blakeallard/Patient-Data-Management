#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

// STRUCT - declare struct
struct Patient
{
    string id;
    string name;
    int    age;
    string condition;
};

// FUNCTION PROTOTYPES - declare & define function prototypes
void AddPatient();
void DisplayPatients();
void SearchPatient();


int main()
{
    // VARIABLES - declare variables
    int choice;

    do
    {
        cout << "\nPatient Data Management System:";
        cout << "\n1. Add Patient;";
        cout << "\n2. Display Patients;";
        cout << "\n3. Search Patient";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        cin  >> choice;
        cout << endl;
        cin.ignore(10000, '\n');


        switch (choice)
        {
            case 1: AddPatient();
                   break;

            case 2: DisplayPatients();
                   break;

            case 3: SearchPatient();
                   break;

            case 4: cout << "\nExiting program...\n";
                   break;

            default: cout <<"\nInvalid choice.  Please try again.\n:";

        } // end swtich

    } while (choice!= 4); // end do-while

    return 0;

} // end main

void AddPatient()
{
    ofstream fileOut("patients.txt", ios::app);
    bool validFile = true;

    if (!fileOut)
    {
        cout << "\nFile could not be opened";
        validFile = false;
    }

    Patient p;
    cout << "Enter Patient ID: ";
    getline(cin, p.id);
    cout << "Enter Patient name: ";
    getline(cin, p.name);
    cout << "Enter Patient age: ";
    cin  >> p.age;
    cin.ignore(1000000, '\n');
    cout << "Enter Patient condition: ";
    getline(cin, p.condition);

    fileOut << p.id << "\n" << p.name << "\n" << p.age << "\n" << p.condition << "\n";
    fileOut.close();
    cout << "Patient record added successfully!\n";
}

void DisplayPatients()
{
    ifstream fileIn("patients.txt");
    bool validFile = true;

    if (!fileIn)
    {
        cout << "\nFile could not be opened";
        validFile = false;
    }

    Patient p;
    cout << "\nPatient Records:\n";
    cout << left << setw(10) << "ID" << setw(20) << "Name" << setw(5) << "Age" << "Condition\n";
    cout << "------------------------------------------------------------\n";

    while (getline(fileIn, p.id))
    {
        getline(fileIn, p.name);
        fileIn >> p.age;
        fileIn.ignore(10000, '\n');
        getline(fileIn, p.condition);
        cout << left << setw(10) << p.id << setw(20) << p.name << setw(5) << p.age << p.condition << "\n";
    }
    fileIn.close();
}

void SearchPatient()
{
    ifstream fileIn("patients.txt");
    bool validFile = true;

    if (!fileIn)
    {
        cout << "\nFile could not be opened";
        validFile = false;
    }

    string searchID;

    cout << "Enter Patient ID to search: ";
    getline(cin, searchID);

    Patient p;
    bool found = false;

    while (getline(fileIn,p.id))
    {
        getline(fileIn, p.name);  // Read name
        fileIn >> p.age;  // Read age
        fileIn.ignore();  // Ignore the newline after age
        getline(fileIn, p.condition);  // Read condition

        if (p.id == searchID)
        {
            found = true;
            cout << "\nPatient Found!\n";
            cout << left << setw(10) << "ID" << setw(20) << "Name" << setw(5) << "Age" << "Condition\n";
            cout << left << setw(10) << p.id << setw(20) << p.name << setw(5) << p.age << p.condition << "\n";
            break;
        } // end if (p.id == searchID)
    } // end while

    if (!found)
    {
        cout << "\nPatient with ID " << searchID << " NOT FOUND!\n";
    }

    fileIn.close();

} // end SearchPatient()