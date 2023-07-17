#include <bits/stdc++.h>
#include <iostream>
#include <conio.h>
#include <fstream>
#include <cstring>

void menu();

using namespace std;
class one // abstract class
{
public:
    virtual void get() = 0;
    virtual void show() = 0;
};

class info : public one
{
public:
    string name, time;
    int num, age;
    void get()
    {
        cin.sync(); // cin. sync discards all unread characters from the input buffer.

        cout << "\nEnter The Patient Name = ";
        cin >> name;

        cout << "\nEnter The Appoinment Time = ";
        cin >> time;

        cout << "\nEnter Age = ";
        cin >> age;

        cout << "\nEnter Appoinment No = ";
        cin >> num;
    }
    void show()
    {
        cout << "\nName = " << name;
        cout << "\nAge = " << age;
        cout << "\nAppointment No = " << num;
        cout << "\nTime = " << time;
    }
};

class Joe : public info
{
public:
    info a1;
    void get()
    {
        ofstream out("dr1.dat", ios::app | ios::binary); // opens a binary file to write data inside
        a1.get();
        out.write((char *)&a1, sizeof(info)); // write( (char *) & ob, sizeof(ob)) ->syntax
        out.close();
        cout << "Your Entry Has been saved ";
        getch();
        menu();
    }
    void show()
    {
        ifstream in("dr1.dat");
        if (!in)
        {
            cout << "\n\nNo Data In the File ";
            cout << "\n\n\t\tPress Any key To Continue : ";
            getch();
            menu();
        }
        else
        {

            while (in.read((char *)&a1, sizeof(a1)))
            {
                // reads all data from file till end of file
                a1.show();
            }
            in.close();
            getch();
            menu();
        }
    }
};
class Raman : public info
{
public:
    info a1;
    void get()
    {
        ofstream out("dr2.dat", ios::app | ios::binary);
        a1.get();
        out.write((char *)&a1, sizeof(info));
        out.close();
        cout << "Your Entry Has been saved ";
        getch();
        menu();
    }
    void show()
    {
        ifstream in("dr2.dat");
        if (!in)
        {
            cout << "No Data In the File ";
            cout << "\nPress Any key To Continue : ";
            getch();
            menu();
        }
        else
        {

            while (in.read((char *)&a1, sizeof(a1)))
            {
                a1.show();
            }
            in.close();
            cout << "Press Enter To Continue =";
            getch();
            menu();
        }
    }
};
class Henry : public info
{
public:
    info a1;
    void get()
    {
        ofstream out("dr3.dat", ios::app | ios::binary);
        a1.get();
        out.write((char *)&a1, sizeof(info));
        out.close();
        cout << "Your Entry Has been saved ";
        getch();
        menu();
    }
    void show()
    {
        ifstream in("dr3.dat");
        if (!in)
        {
            cout << "No Data In the File ";
            cout << "\nPress Any key To Continue : ";
            getch();
            menu();
        }
        else
        {

            while (in.read((char *)&a1, sizeof(info)))
            {
                a1.show();
            }
            in.close();
        }
    }
};
class staff : public one
{
public:
    string all;
    string name, pos;
    int age, salary;

    void get()
    {
        ofstream out("staff.txt", ios::app);
        {
            cin.sync();

            cout << "\nEnter Name = ";
            cin >> name;
            cout << "\nEnter Age  = ";
            cin >> age;
            cout << "\nEnter Salary = ";
            cin >> salary;
            cout << "\nEnter Working Position =";
            cin >> pos;
        }
        out << "\nName :" << name << "\nAge :" << age << "\nSalary :" << salary << "\nWorking Position :"
            << pos << endl;
        out.close();
        cout << "\n\nYour Information has been saved :\n\t\t\tPress any key to continue  ";
        getch();
        menu();
    }
    void show()
    {

        ifstream in("staff.txt"); // opening file to read from it
        if (!in)
        {
            cout << "File opening error";
        }
        while (!(in.eof()))
        {
            getline(in, all);
            cout << all << endl;
        }
        in.close();
        cout << "\n\n\t\t\tPress Any Key To Continue : ";
        getch();
        menu();
    }
};

class information
{
public:
    void drinfo()
    {
        cout << "\n==============================================================================\n";
        cout << "\n\n\t\t(Three Doctors Available) \n\n \t\t[Information And Timing Are Given Below]\n";
        cout << "-----------------------------------------------------------------------------\n";
        cout << "\t\tDr Available:\n";
        cout << "\t\tDr. Joe (skin specialist)\n\n";
        cout << "\t\t\t [[Timing]]:\n\n";
        cout << "\tMonday To Friday\t\t9AM TO 5PM\n";
        cout << "\tSatuday         \t\t9AM TO 1PM\n";
        cout << "\tSunday          \t\t Off\n";
        cout << "\n------------------------------------------------------------------------------\n";
        cout << "\t\tDr. Henry Cavill (child specialist)\n\n";
        cout << "\t\t\t [[Timing]]:\n\n";
        cout << "\tMonday To Friday\t\t2PM TO 10PM\n";
        cout << "\tSatuday         \t\t8AM TO 1PM\n";
        cout << "\tSunday          \t\t12PM TO 9PM\n";
        cout << "\n------------------------------------------------------------------------------\n";
        cout << "\t\tDr. Raman Chopra (DVM)\n\n";
        cout << "\t\t\t [[Timing]]:\n\n";
        cout << "\tMonday To Friday\t\t8AM TO 5PM\n";
        cout << "\tSatuday         \t\t10AM TO 1PM\n";
        cout << "\tSunday          \t\t Off\n";
        cout << "\n------------------------------------------------------------------------------\n";
        cout << "\nPrees Any Key to Continue: ";
        getch();
        menu();
    }
};
void call_dr()
{
    int choice;
    cout << "\n\n\n\t\t Press 1 for Dr Joe Goldberg \n\n\t\t Press 2 for Dr Raman Chopra \n\n\t\t Press 3 for Dr Henry Cavill \n\n\t\t ";
    cin >> choice;

    one *ptr; // making pointer object of class one
    Joe s3;
    Raman s4;
    Henry s5;
    if (choice == 1)
    {
        ptr = &s3;  // using base class pointer towards child class object
        ptr->get(); // calling a virtual function using base class pointer
    }
    if (choice == 2)
    {
        ptr = &s4;
        ptr->get();
    }
    if (choice == 3)
    {
        ptr = &s5;
        ptr->get();
    }

    else
    {
        cout << "Sorry invalid choice :";
    }
}

void pinfoshow()
{
    int choice;
    cout << "\n\n\t 1 -Press 1 for Dr Joe Goldberg \n\n\t 2-  Press 2 for Dr Raman Chopra \n\n\t 3-  Press 3 for Dr Henry Cavill \n\n\t";
    cout << "Please Enter Your Choice :";
    cin >> choice;
    one *ptr;
    Joe s3;
    Raman s4;
    Henry s5;
    if (choice == 1)
    {
        ptr = &s3;
        ptr->show();
    }
    else if (choice == 2)
    {
        ptr = &s4;
        ptr->show();
    }
    else if (choice == 3)
    {
        ptr = &s5;
        ptr->show();
    }
    else
    {
        cout << "Sorry Invalid choice : ";
        getch();
        menu();
    }
}

void menu()
{
    cout << "\n Hospital Management system";
    cout << "\n----------------------------------------------------------------------------------------------------------------------------------------------------------------\n";

    cout << "\n\n\n\n\n\n\n";

    cout << "\t\t    |   ++++++++++  MAIN MENU   +++++++++  |  \n";
    cout << "\t\t    |    [[[  Hospital Management system  ]]]  |\n";
    cout << "\t\t    |======================================|   \n";

    cout << "\n--------------------------------------------------------------------------------\n";

    cout << "\n\n\t1-\t\tPress 1 For Available Doctor Information\n\n";
    cout << "\t2-\t\tPress 2 for Doctor Appointment\n\n";
    cout << "\t3-\t\tPress 3 for Saving Staff information\n\n";
    cout << "\t4-\t\tPress 4 for Checking Patient Appointment Menu:\n\n ";
    cout << "\t5-\t\tPress 5 for Checking Staff Information Menu:\n\n";

    cout << "\n================================================================================\n";
    cout << "\n\n\t\tPlease Enter Your Choice : ";
    information a1;
    one *ptr;
    staff a2;
    int a;
    cin >> a;
    cout << endl;
    if (a == 1)
    {
        a1.drinfo();
    }
    else if (a == 2)
    {
        call_dr();
    }
    else if (a == 3)
    {
        ptr = &a2;
        ptr->get();
    }
    else if (a == 4)
    {
        pinfoshow();
    }
    else if (a == 5)
    {
        ptr = &a2;
        ptr->show();
    }

    else
    {
        cout << "Sorry invalid choice : ";
    }

    cout << endl;
}

int main()
{
    menu();
}