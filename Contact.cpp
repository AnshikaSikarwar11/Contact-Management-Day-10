#include <iostream>
#include <fstream>
using namespace std;

class temp
{
    string phoneNo, name, address, description, search;
    fstream file;

public:
    void addContact();
    void showAll();
    void searchContact();
} obj;
int main()
{
    char choice;
    cout << "1 - - > Add Contact \n";
    cout << "2 - - > Show All Contact \n";
    cout << "3 - - > Search Contact \n";
    cout << "0 - - > exit\n";
    cin >> choice;

    switch (choice)
    {
    case '1':
        cin.ignore();
        obj.addContact();
        break;
    case '2':
        cin.ignore();
        obj.showAll();
        break;
    case '3':
        cin.ignore();
        obj.searchContact();
        break;
    case '0':
        return 0;
        break;
    default:
        cout << "Invalid choice...!";
        break;
    }
    return 0;
}
void temp ::addContact()
{
    cout << "Enter phone number :\n";
    getline(cin, phoneNo);
    cout << "Enter name :\n";
    getline(cin, name);
    cout << "Enter address :\n";
    getline(cin, address);
    cout << "Enter description :\n";
    getline(cin, description);

    file.open("Cdata.csv", ios ::out | ios ::app);
    file << phoneNo << "," << name << "," << address << "," << description << "\n";
    file.close();
}
void temp ::showAll()
{
    file.open("Cdata.csv", ios ::in);
    getline(file, phoneNo, ',');
    getline(file, name, ',');
    getline(file, address, ',');
    getline(file, description, '\n');
    while (!file.eof())
    {
        cout << "Phone Number :" << phoneNo << endl;
        cout << "Phone Name :" << name << endl;
        cout << "Phone Address :" << address << endl;
        cout << "Phone description :" << description << endl
             << endl;
        getline(file, phoneNo, ',');
        getline(file, name, ',');
        getline(file, address, ',');
        getline(file, description, '\n');
        file.close();
    }
}
void temp ::searchContact()
{
    cout << "Enter Phone Number :";
    getline(cin, search);
    file.open("Cdata.csv", ios ::in);
    getline(file, phoneNo, ',');
    getline(file, name, ',');
    getline(file, address, ',');
    getline(file, description, '\n');
    while (!file.eof())
    {
        if (phoneNo == search)
        {
            cout << "Phone Number :" << phoneNo << endl;
            cout << "Phone Name :" << name << endl;
            cout << "Phone Address :" << address << endl;
            cout << "Phone description :" << description << endl
                 << endl;
        }
        getline(file, phoneNo, ',');
        getline(file, name, ',');
        getline(file, address, ',');
        getline(file, description, '\n');
        file.close();
    }
}