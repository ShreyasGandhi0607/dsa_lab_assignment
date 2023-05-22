#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;

class Employee
{
    int employee_id;
    char name[50];
    char post[50];
    float salary;

public:
    void setData()
    {
        cout << "\nEnter Employee ID : ";
        cin >> employee_id;
        cout << "Enter Name of Employee : ";
        cin >> name;
        cout << "Enter Post of Employee : ";
        cin >> post;
        cout << "Enter Salary of Employee : ";
        cin >> salary;
    }

    void showData()
    {
        cout << endl;
        cout << "\n\tEmployee ID : " << employee_id;
        cout << "\n\tEmployee Name : " << name;
        cout << "\n\tEmployee Post : " << post;
        cout << "\n\tEmployee Salary : " << salary;
        cout << endl;
    }

    int retemployee_id()
    {
        return employee_id;
    }
};

void write_record()
{
    ofstream outFile;
    outFile.open("Employee.dat", ios::binary | ios::app);
    Employee obj;
    obj.setData();
    outFile.write((char *)&obj, sizeof(obj));
    outFile.close();
}

void display()
{
    ifstream inFile;
    inFile.open("Employee.dat", ios::binary);
    Employee obj;
    while (inFile.read((char *)&obj, sizeof(obj)))
    {
        obj.showData();
    }
    inFile.close();
}

void search(int n)
{
    ifstream inFile;
    inFile.open("Employee.dat", ios::binary);
    Employee obj;
    while (inFile.read((char *)&obj, sizeof(obj)))
    {
        if (obj.retemployee_id() == n)
        {
            obj.showData();
            break;
        }
    }
    inFile.close();
}

void delete_record(int n)
{
    Employee obj;
    ifstream inFile;
    inFile.open("Employee.dat", ios::binary);
    ofstream outFile;
    outFile.open("temp.dat", ios::out | ios::binary);
    while (inFile.read((char *)&obj, sizeof(obj)))
    {
        if (obj.retemployee_id() != n)
        {
            outFile.write((char *)&obj, sizeof(obj));
        }
    }
    inFile.close();
    outFile.close();
    remove("Employee.dat");
    rename("temp.dat", "Employee.dat");
}

void modify_record(int n)
{
    fstream file;
    file.open("Employee.dat", ios::in | ios::out);
    Employee obj;
    while (file.read((char *)&obj, sizeof(obj)))
    {
        if (obj.retemployee_id() == n)
        {
            cout << "\nEnter the new details of Employee :";
            obj.setData();
            long int pos = -1 * sizeof(obj);
            file.seekp(pos, ios::cur);
            file.write((char *)&obj, sizeof(obj));
        }
    }
    file.close();
}

int main()
{
    int ch;
    do
    {
        cout << "\n******** Menu ********";
        cout << "\n 1. ADD Employee";
        cout << "\n 2. Display Employee";
        cout << "\n 3. Search Employee";
        cout << "\n 4. Delete Employee";
        cout << "\n 5. Modify Employee";
        cout << "\n 6. Exit";
        cout << "\n\nEnter your choice : ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            cout << "\nEnter number of records : "; // Store 4 records in file
            int n;
            cin >> n;
            for (int i = 0; i < n; i++)
                write_record();
            break;
        case 2:
            cout << "\nList of records : ";
            display();
            break;
        case 3: // Search record
            cout << "\nEnter Employee ID to be searched : ";
            int s;
            cin >> s;
            search(s);
            break;
        case 4:
            cout << "\nEnter Employee ID to be deleted : ";
            int d;
            cin >> d;
            delete_record(d);
            cout << "\nRecord Deleted !!";
            break;
        case 5: // Modify record
            cout << "\nEnter Employee ID to be modified : ";
            int m;
            cin >> m;
            modify_record(m);
            break;
        case 6:
            cout << "\nThanks for using this Program !!";
            return 0;
        }
    } while (ch != 6);
}
