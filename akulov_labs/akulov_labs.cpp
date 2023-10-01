#include <iostream>
#include <string>
#include <fstream>
using namespace std;
void menu(){
	cout << "1.Add tube\n";
	cout << "2.Add Compressor station\n";
	cout << "3.View all objects\n";
	cout << "4.Edit tube\n";
	cout << "5.Edit Compressor station\n";
	cout << "6.Save\n";
	cout << "7.Load\n";
	cout << "0.Exit\n";
}
void checkint(int& x) {

    cin >> x;
    while (cin.fail() || x < 0 || cin.peek() != '\n') {

        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Error. Try again!" << endl;
        cin >> x;

    }
}

void doublecheck(double& x) {

    cin >> x;

    while (cin.fail() || x < 0 || cin.peek() != '\n') {

        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Error. Try again!" << endl;
        cin >> x;

    }
}

void boolcheck(bool& a)
{
    cin >> a;
    while (!cin || !(a == 0 || a == 1) || cin.peek() != '\n')
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Please, try again: ";
        cin >> a;
    }
};
struct Tube {
    string name;
    double length = 0;
    int diametr = 0;
    bool maintenance = false;
    void add_tube() {  

        cout << "Type name:\n";
        cin >> name;

        cout << "Type length:\n";
        doublecheck(length);

        cout << "Type diametr:\n";
        checkint(diametr);

    }

    void print_tube() {

        if (diametr != 0) {
            cout << "Tube:\n";
            cout << "Name: " << name << endl;
            cout << "Length: " << length << endl;
            cout << "Diametr: " << diametr << endl;
            cout << "Maintenance: " << maintenance << endl;
        }

        else {
            cout << "The tube doesn't exist\n";
        }
    }

    void edit_tube() {

        char renovation;

        cout << "Is tube under maintenance(y/n)";

        cin >> renovation;

        while ((renovation != 'y') && (renovation != 'n')) {
            cout << "Error! Try again\n" << "Under maintenance(y/n)\n";
            cin >> renovation;
        }

        if (renovation == 'y') {
            maintenance = true;
        }

        else if (renovation == 'n') {
            maintenance = false;
        }

    }

    void save_tube() {

        if (name.empty())
        {
            cout << "You don't have the tube to save\n";
        }
        else
        {
            ofstream data;
            data.open("repository.txt", ios::app);
            if (data.is_open())
            {
                data << "Tube:" << endl;
                data << name << endl << length << endl << diametr << endl << maintenance << endl;
            }
            data.close();
            cout << "Tube successfully saved!" << " " << "Please, check your file." << endl;
        }
    }

    void load_tube()
    {
        bool rewrite_data;
        rewrite_data = 1;
        if (!name.empty())
        {
            cout << "You already have data about your Tube!" << endl;
            cout << "If you are sure you want to replace them with data from the file, then press 1, otherwise 0: ";
            boolcheck(rewrite_data);
        }
        if (rewrite_data == 1)
        {
            ifstream readdata;
            string row;
            readdata.open("repository.txt", ios::in);
            if (readdata.is_open())
            {
                while (getline(readdata, row))
                {
                    if (row == "Tube:")
                    {
                        getline(readdata, name);
                        readdata >> length >> diametr >> maintenance;
                    }
                }
                readdata.close();
                if (name.empty())
                {
                    cout << "You don't have data about the tube to download\n";
                }
                else
                {
                    cout << "Your tube data has been successfully download!" << " " << " Press 3 to check your objects. " << endl;
                }
            }
        }
    }


};
struct Compressor_station {
    string name;
    int amount_of_workshops = 0;
    int amount_of_working_workshops = 0;
    double efficiency = 0;
    void add_cstation() {

        cout << "Type name:\n";
        cin >> name;

        cout << "Type amount workshops:\n";
        checkint(amount_of_workshops);

        cout << "Type amount working workshops:\n";
        checkint(amount_of_working_workshops);

        while (amount_of_working_workshops > amount_of_workshops) {
            cout << "Error. There's not so many workshops. Try again\n";
            checkint(amount_of_working_workshops);
        }

        cout << "Type efficiency:\n";
        doublecheck(efficiency);

    }

    void print_cstation() {

        if (amount_of_workshops != 0) {
            cout << "Compressor station:\n";
            cout << "Name: " << name << endl;
            cout << "Amount of workshops: " << amount_of_workshops << endl;
            cout << "Amount of working workshops: " << amount_of_working_workshops << endl;
            cout << "Efficiency: " << efficiency << endl;
        }

        else {
            cout << "Compressor station doesn't exist\n";
        }
    }

    void working_workshops_change() {

        int aowws; 

        checkint(aowws);

        while (aowws > amount_of_workshops) {
            cout << "Error. There's no so many workshops. Try again\n";
            checkint(aowws);
        }

        amount_of_working_workshops = aowws;

    }

    void save_cstation() {

        if (name.empty())
        {
            cout << "You don't have the compressor station to save.\n";
        }
        else
        {
            ofstream data;
            data.open("repository.txt", ios::app);
            if (data.is_open())
            {
                data << "Compressor station:" << endl;
                data << name << endl << amount_of_workshops << endl << amount_of_working_workshops << endl << efficiency << endl;
            }
            data.close();
            cout << "Compressor station successfully saved!" << " " << "Please, check your file." << endl;
        }

    }

    void load_cstation()
    {
        bool rewrite_data;
        rewrite_data = 1;
        if (!name.empty())
        {
            cout << "You already have data about your compressor station!" << endl;
            cout << "If you are sure you want to replace them with data from the file, then press 1, otherwise 0: ";
            boolcheck(rewrite_data);
        }
        if (rewrite_data == 1)
        {
            ifstream readdata;
            string row;
            readdata.open("repository.txt", ios::in);
            if (readdata.is_open())
            {
                string row;
                while (getline(readdata, row))
                {
                    if (row == "Compressor station:")
                    {
                        getline(readdata, name);
                        readdata >> amount_of_workshops >> amount_of_working_workshops >> efficiency;
                    }
                }
                readdata.close();
                if (name.empty())
                {
                    cout << "You don't have data about the compressor station to download.\n";
                }
                else
                {
                    cout << "Your compressor station data has been successfully download!" << " " << " Press 3 to check your objects. " << endl;
                }
            }
        }
    }

};
int main() {

    
    int selection;
    menu();
    Tube new_tube;
    Compressor_station new_cstation;
    string rowin;
    fstream repository("repository.txt");
    for (;;) {  

        cout << "================================\n";
        checkint(selection);

        switch (selection) {

        case 1:
            cout << "Add tube\n";
            new_tube.add_tube();
            cout << "0. Return to menu\n";
            break;

        case 2:
            cout << "Add compressor station\n";
            new_cstation.add_cstation();
            cout << "0. Return to menu\n";
            break;

        case 3:
            cout << "View all objects\n";
            new_tube.print_tube();

            new_cstation.print_cstation();

            cout << "0. Return to menu\n";
            break;

        case 4:
            cout << "Edit tube\n";
            new_tube.edit_tube();
            cout << "0. Return to menu\n";
            break;

        case 5:
            cout << "Edit compressor station\n";
            cout << "Type amount of working workshops: ";
            new_cstation.working_workshops_change();
            cout << "0. Return to menu\n";
            break;

        case 6:
            cout << "Save\n";
            new_tube.save_tube();
            new_cstation.save_cstation();
            cout << "0. Return to menu\n";
            break;

        case 7:
            cout << "Load\n";
            if (repository.peek() == EOF)
            {
                cout << "File is empty!" << " " << "Please, check your data about your objects!!!" << endl;
                repository.close();
            }
            else
            {
                new_tube.load_tube();
                new_cstation.load_cstation();
            }
            cout << "0. Return to menu\n";
            break;

        case 0:
            menu();
            break;

        default:
            cout << "Error. Command doesn't exist.\n";
            menu();
        }


    }

}


void print_menu() {

    cout << "1. Add pipe\n";
    cout << "2. Add compressor station\n";
    cout << "3. View all objects\n";
    cout << "4. Edit pipe\n";
    cout << "5. Edit compressor station\n";
    cout << "6. Save\n";
    cout << "7. Load\n";
    cout << "0. Return to menu\n";

}