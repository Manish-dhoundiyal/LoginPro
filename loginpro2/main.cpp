#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int Isloggedin()
{
    string username, password, un, pw;
    cout<<"enter username: "; cin>> username;
    cout<<"enter password:"; cin>> password ;

    ifstream read;
    read.open("database.txt");
    getline(read, un);
    getline(read, pw);
    read.close();


    if (un == username && pw == password)
    {
        return 1;
    }
    else
    {
        return 0;
}
}
int main()
{
    int choice;
    cout<<"1: register:";
    cout<<"2: login:";
    cin>> choice;
    if (choice == 1)
    {
        string un,pw;
        cout << "select a username: "; cin>> un;
        cout<< "select a password: "; cin>> pw;

        ofstream file;
        file.open("database.txt");
        file << un << endl << pw;
        file.close();

        main();
    }
    else if ( choice == 2)
    {
        bool status = Isloggedin();

        if (!status)
        {
            cout<<"false login!"<<endl;
            return 0;
        }
        else
        {
            cout<<"successfully logged in!"<<endl;
            return 1;

    }

}
}
