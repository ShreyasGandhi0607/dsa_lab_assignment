#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;

class Student
{
    int roll_no;
    char name[50];
    char addr[50];

public:
    void setData()
    {
        cout << "\nEnter Roll No. : ";
        cin >> roll_no;
        cout << "Enter name of student : ";
        cin >> name;
        cout << "Enter the address of the student : ";
        cin >> addr;
    }

    void showData()
    {
        cout << endl;
        cout << "\n\tRoll No. : " << roll_no;
        cout << "\n\tStudent Name : " << name;
        cout << "\n\tAddress : " << addr;
        cout << endl;
    }

    int retroll_no()
    {
        return roll_no;
    }
};

void write_record()
{
    ofstream outFile;
    outFile.open("student.dat", ios::binary | ios::app);
    Student obj;
    obj.setData();
    outFile.write((char *)&obj, sizeof(obj));
    outFile.close();
}

void display()
{
    ifstream inFile;
    inFile.open("student.dat", ios::binary);
    Student obj;
    while (inFile.read((char *)&obj, sizeof(obj)))
    {
        obj.showData();
    }
    inFile.close();
}

void search(int n)
{
    ifstream inFile;
    inFile.open("student.dat", ios::binary);
    Student obj;
    while (inFile.read((char *)&obj, sizeof(obj)))
    {
        if (obj.retroll_no() == n)
        {
            obj.showData();
            break;
        }
    }
    inFile.close();
}

void delete_record(int n)
{
    Student obj;
    ifstream inFile;
    inFile.open("student.dat", ios::binary);
    ofstream outFile;
    outFile.open("temp.dat", ios::out | ios::binary);
    while (inFile.read((char *)&obj, sizeof(obj)))
    {
        if (obj.retroll_no() != n)
        {
            outFile.write((char *)&obj, sizeof(obj));
        }
    }
    inFile.close();
    outFile.close();
    remove("student.dat");
    rename("temp.dat", "student.dat");
}

void modify_record(int n)
{
    fstream file;
    file.open("student.dat", ios::in | ios::out);
    Student obj;
    while (file.read((char *)&obj, sizeof(obj)))
    {
        if (obj.retroll_no() == n)
        {
            cout << "\nEnter the new details of student :";
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
        cout << "\n**** Menu ****";
        cout << "\n 1. Write";
        cout << "\n 2. Display";
        cout << "\n 3. Search";
        cout << "\n 4. Delete";
        cout << "\n 5. Modify";
        cout << "\n 6. Exit";
        cout << "\n\nEnter your choice : ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            cout << "\nEnter number of records : ";
            int n;
            cin >> n;
            for (int i = 0; i < n; i++)
                write_record();
            break;
        case 2:
            cout << "\nList of records : ";
            display();
            break;
        case 3:
            cout << "\nEnter Roll No no. to be searched : ";
            int s;
            cin >> s;
            search(s);
            break;
        case 4:
            cout << "\nEnter Roll No to be deleted : ";
            int d;
            cin >> d;
            delete_record(d);
            cout << "\nRecord Deleted !!";
            break;
        case 5:
            cout << "\nEnter Roll No. to be modified : ";
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
