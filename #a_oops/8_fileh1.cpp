#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int ID;

class student
{
public:
    int id;
    string name;
    int age;
    string stream;

    void addstudent()
    {
        cout << "enter your name:-" << endl;
        cin.get(); // clears the buffer (good to use before getline..)-(in c lang we use fflush(stdin)....)
        getline(cin, name);
        cout << "enter your age:-" << endl;
        cin >> age;
        cout << "enter your stream:-" << endl;
        cin >> stream;
        ID++;

        ofstream fout;
        fout.open("student.txt", ios::app | ios::in | ios::out);
        fout << "\n"<< ID;
        fout << "\n"<< name;
        fout << "\n"<< age;
        fout << "\n"<< stream;
        fout.close();

        fout.open("id.txt", ios::app | ios::in | ios::out);
        fout << "\n"<< ID;
        fout.close();

        cout << "record added successfully." << endl;
    }

    void printallstudent()
    {
        ifstream fin;
        fin.open("student.txt");

        student s;
        while (!fin.eof())
        {
            fin >> s.id;
            fin.ignore(); // if we are using fin in getline then use fin.ignore() to clear the buffer.
            getline(fin, s.name);
            fin >> s.age;
            fin >> s.stream;

            s.print();
        }
        fin.close();
    }

    void print()
    {
        cout<<endl;
        cout << "ID:-" << id << endl;
        cout << "Name:-" << name << endl;
        cout << "Age:-" << age << endl;
        cout << "Stream:-" << stream << endl;
        cout<<"------------------------------------------"<<endl;
    }

    void searchstudent(int id)
    {
        ifstream fin;
        fin.open("student.txt");

        student s;
        while (!fin.eof())
        {
            fin >> s.id;
            fin.ignore();
            getline(fin, s.name);
            fin >> s.age;
            fin >> s.stream;

            if (s.id == id)
            {
                s.print();
                break;
            }
        }
        fin.close();
    }

    /*
    basic logic to delete a data-
    deleting is little tricky because we can delete randomly so there will be problem to arrange the data so here we will create a temperory file and we will compare every student data  with the data to be deleted if it does not matches to the data to be deleted then copy that into temperory file and the data to be deleted we will not copy to temperory file and then we will make the temperory file as student.txt(main file )and delete the previous file.
    */
    void deletestudent(int id)
    {
        ifstream fin;
        fin.open("student.txt");

        ofstream fout;
        fout.open("temp.txt", ios::app);

        student s;
        while (!fin.eof())
        {
            fin >> s.id;
            fin.ignore();
            getline(fin, s.name);
            fin >> s.age;
            fin >> s.stream;

            if (s.id != id)
            {
                fout << "\n"<< s.id;
                fout << "\n"<< s.name;
                fout << "\n"<< s.age;
                fout << "\n"<< s.stream;
            }
        }

        fin.close();
        fout.close();

        remove("student.txt");    // this func deletes the file given in the path.
        rename("temp.txt", "student.txt"); // this func renames the first file to second file.

        cout << "record deleted successfully." << endl;
    }

    /*
    logic of update is-(combination of delete and add student data)
    first we will delete the student id which is to be updated and then we will add a new student with the updated information
    */
    void updatestudent(int id)
    {
        deletestudent(id);

        cout << "enter your name:-" << endl;
        cin.get(); // clears the buffer (good to use before getline..)-(in c lang we use fflush(stdin)....)
        getline(cin, name);
        cout << "enter your age:-" << endl;
        cin >> age;
        cout << "enter your stream:-" << endl;
        cin >> stream;
        ID++;

        ofstream fout;
        fout.open("student.txt", ios::app | ios::in | ios::out);
        fout << "\n"<< id;
        fout << "\n"<< name;
        fout << "\n"<< age;
        fout << "\n"<< stream;
        fout.close();

        cout << "record added successfully." << endl;
    }
};

int main()
{
    int choice;

    ifstream fin;
    fin.open("id.txt");

    if (!fin) // just exceptional handling if file not created of found.
    {
        cout << "fine not found" << endl;
    }
    else
    {
        while (!fin.eof()) // this makes the id get not vanish whenever we run our ID will continue from our last entened ID.
        {
            fin >> ID;
        }
        fin.close();
        cout << "ID=" << ID << endl;
    }

    cout << "1.add student" << endl;
    cout << "2.print all student" << endl;
    cout << "3.search a student" << endl;
    cout << "4.update a student" << endl;
    cout << "5.delete a student" << endl;
    cout << "6.exit" << endl;

    while (1)
    {
        cout << "enter your choice-" ;

        cin >> choice;
        student s;

        int id;
        switch (choice)
        {
        case 1:
            s.addstudent();
            break;
        case 2:
            s.printallstudent();
            break;
        case 3:
            cout << "enter student id" << endl;
            cin >> id;
            s.searchstudent(id);
            break;
        case 4:
            cout << "enter student id-" << endl;
            cin >> id;
            s.updatestudent(id);
            break;
        case 5:
            cout << "enter student id-" << endl;
            cin >> id;
            s.deletestudent(id);
            break;
        case 6:
            exit(0);
        default:
            cout << "enter valid choice..." << endl;
        }
    }
}