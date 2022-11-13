#include <iostream>
#include <Windows.h>
#include <iomanip>
using namespace std;

class contact
{
    string name;
    string mob;
public:
    contact() : name(""), mob("") {}
    bool show();
    bool show(string search_term);
    bool name_exists(string tname);
    bool add(string new_name, string new_mob);
    bool edit(string);
    bool erase(string new_name);
};

bool contact::show()
{
    if (name != "")
    {
        cout << name << setw(25) << mob << endl;
        return 1; 
    }
    else return 0; 
}

bool contact::add(string new_name, string new_mob)
{
    if (name == "")
    {
        name = new_name;
        mob = new_mob;
        return 1;
    }
    else return 0; 
}

bool contact ::edit(string new_name)
{
    string new_mob;
    if (new_name == name)
    {
        cout << "Enter new name : ";
        cin >> new_name;
        cout << "Enter new mobile no : ";
        cin >> new_mob;
        name = new_name;
        mob = new_mob;
        return 1;
    }
    else return 0;
}

bool contact::erase(string new_name)
{
    if (new_name == name)
    {
        name = "";
        mob = "";
        return 1;
    }
    else return 0;
}

bool contact::show(string search_term)
{
    if (search_term == name)
    {
        cout << name << " " << mob << endl;
        return 1;
    }
    else return 0;
}
bool contact::name_exists(string tname)
{
    if (tname == name)
        return 1;
    else return 0;
}

bool name_valid(string tname)
{
    if (tname.size() > 20)
    {
        cout << "Invalid Name!\nEnter a name within 20 characters!" << endl;
        return 0;
    }
    else if (tname == "")
    {
        cout << "Invalid Name!\nName cannot be blank!" << endl;
        return 0;
    }
    else return 1;
}

bool mob_valid(string tmob)  //mobile number validation
{
    if (tmob.size() > 13 || tmob.size() < 10)
    {
        cout << "Invalid mobile no.\nEnter a no. between 10 and 13 digits" << endl;
        return 0;
    }
    else if (tmob == "")
    {
        cout << "Invalid mobile no.\nMobile no cannot be blank" << endl;
        return 0;
    }
    else return 1;
}
int main()
{
    contact person[100];
    char ch;
    cout << "\n\n\t\t**************************************************************************************************";
    cout << "\n\n\t\t\t\t\t\tTELEPHONE DIRECTORY ";
    cout << "\n\n\t\t**************************************************************************************************";
    cout << "\n\n\n\n\t\t\t\t\t\t MADE BY : SEJAL JAIN ";
    cout << "\n\t\t\t\t\t\t\t   SHRISHTI JAIN ";
    Sleep(3000);
    cout << "\n\n LOADING..............";
    Sleep(2000);
    system("cls");
    system("color 0A");
    cout << "\n\n"<< setw(85) << "WELCOME TO MY TELEPHONE DIRECTORY";
    do
    {
        int choice, flag = 0, counter = 0, cancel_flag = 0;
        string temp_name, temp_mob;
        cout << "\n\n\t\t**************************************************************************************************";
        cout << "\n\n"<< setw(70) << "MAIN MENU";
        cout << "\n\n\t\t**************************************************************************************************\n";
        cout << "\t\t\t\t\t\t\t1. Show contacts" << endl;
        cout << "\t\t\t\t\t\t\t2. Add Contact" << endl;
        cout << "\t\t\t\t\t\t\t3. Edit Contact" << endl;
        cout << "\t\t\t\t\t\t\t4. Delete Contact" << endl;
        cout << "\t\t\t\t\t\t\t5. Search" << endl;
        cout << "\t\t\t\t\t\t\t6. Quit" << endl<< endl;
        cout << "Enter your choice(1-6) : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Showing Contacts" << endl;
            for (int i = 0; i < 100; i++)
                if (person[i].show())
                    flag = 1;
            if (!flag)
                cout << "No contacts found!" << endl;
            break;

        case 2:
            cout << "Add New Contact\t\t\t\tpress $ to cancel" << endl;
            counter = 0;
            do
            {
                flag = 0;
                if (counter)
                    cout << "Try again\t\t\t\tpress $ to cancel" << endl;
                counter++;  			//counts how many times the do-while loop executes
                cout << "Name: ";
                cin >> temp_name;
                if (temp_name == "$")		//Cancel operation
                {
                    cancel_flag = 1;
                    break;
                }
                cout << "Mobile No.: ";
                cin >> temp_mob;
                if (temp_mob == "$")		//Cancel operation
                {
                    cancel_flag = 1;
                    break;
                }
                for (int i = 0; i < 100; i++)
                    if (person[i].name_exists(temp_name))			//Check whether name exists or not
                    {
                        cout << "The name you entered is already there in the telephone directory, enter a distinct name." << endl;
                        flag = 1;
                        break;
                    }

            } while (!name_valid(temp_name) || flag || !mob_valid(temp_mob));
            if (cancel_flag)
            {
                system("cls");
                break;
            }
            for (int i = 0; i < 100; i++)
                if (person[i].add(temp_name, temp_mob))
                {
                    cout << "\n\n\t\t\t\t\tContact added successfully :-)" << endl;
                    flag = 1;
                    break;
                }
            if (!flag)
                cout << "Memory full! Delete some contacts first." << endl;
            break;

        case 3:
            cout << "Enter a contact name to edit : \t\t\t\tpress $ to cancel\n";
            cin >> temp_name;
            if (temp_name == "$")
            {
                system("cls");
                break;
            }
            for (int i = 0; i < 100; i++)
                if (person[i].edit(temp_name))
                {
                    cout << "Edited Successfully!" << endl;
                    flag = 1;
                    break;
                }
            if (!flag)
                cout << "Contact name not found!" << endl;
            break;

        case 4:
            do
            {
                if (counter)
                    cout << "Try again" << endl;
                counter++;
                cout << "Enter a contact name to delete\t\t\tpress $ to cancel\n";
                cin >> temp_name;
                if (temp_name == "$") //Cancel Operation
                {
                    system("cls");
                    break;
                }
                for (int i = 0; i < 100; i++) //Final Confirmation
                    if (person[i].name_exists(temp_name))
                    {
                        flag = 1;
                        cout << "Are you sure you want to delete? (1/0)" << endl;
                        int yes;
                        cin >> yes;
                        if (!yes)
                        {
                            system("cls");
                            cancel_flag = 1;
                        }
                        break;
                    }
                if (!flag)
                    cout << "Contact name not found!" << endl;
                if (cancel_flag)
                    break;
                if (flag) 
                {
                    for (int i = 0; i < 100; i++)
                        if (person[i].erase(temp_name))
                        {
                            cout << "Deleted successfully!" << endl;
                            break;
                        }
                }
            } while (!flag);
            break;

        case 5:
            do
            {
                if (counter)
                    cout << "Try again" << endl;
                counter++;
                cout << "Search a name: \t\t\t\tpress $ to cancel\n";
                cin >> temp_name;
                if (temp_name == "$") //Cancel Operation
                {
                    system("cls");
                    break;
                }
                for (int i = 0; i < 100; i++)
                    if (person[i].show(temp_name))
                    {
                        flag = 1;
                        break;
                    }
                if (flag == 0)
                    cout << "Contact name not found" << endl;
            } while (!flag);
            break;

        case 6:
            exit(0);
            break;
        default:
            break;
        }
        cout << "\nWant to continue press y or Y : ";
        cin >> ch;
        system("cls");
    } while (ch == 'Y' || ch == 'y');
    return 0;
}
