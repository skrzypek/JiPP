//nnoremap <F5> :<C-U>make %:r && ./%:r<CR>
#include <iostream>

using namespace std;


class Person{

    protected:
        string first_name;
        string last_name;
        int age;

    public:
        void show_data();
};


class Student:public Person{

    private:
        string group;

    public:
        void insert_data();
        void show_data();
};


class Worker:public Person{

    private:
        string position;

    public:
        void insert_data();
        void show_data();
};


int main() {
    Student student = Student();
    student.insert_data();

    Worker worker = Worker();
    worker.insert_data();

    cout << endl << endl;

    student.show_data();
    worker.show_data();
    return 0;
}


void Student::insert_data(){
    cout << "STUDENT" << endl;
    cout << "Set first name: ";
    cin >> first_name;

    cout << "Set last name: ";
    cin >> last_name;

    cout << "Set age: ";
    cin >> age;

    cout << "Set group: ";
    cin >> group;
}


void Worker::insert_data(){
    cout << "WORKER" << endl;
    cout << "Set first name: ";
    cin >> first_name;

    cout << "Set last name: ";
    cin >> last_name;

    cout << "Set age: ";
    cin >> age;

    cout << "Set position: ";
    cin >> position;
}


void Student::show_data(){
    cout << "STUDENT" << endl;
    cout << "First name: ";
    cout << first_name << endl;

    cout << "Last name: ";
    cout << last_name << endl;

    cout << "Age: ";
    cout << age << endl;

    cout << "Group: ";
    cout << group << endl;
}


void Worker::show_data(){
    cout << "WORKER" << endl;
    cout << "First name: ";
    cout << first_name << endl;

    cout << "Last name: ";
    cout << last_name << endl;

    cout << "Age: ";
    cout << age << endl;

    cout << "Position: ";
    cout << position << endl;
}
