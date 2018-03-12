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

    protected:
        string group;

    public:
        void show_data();

    friend void insert_student_data(Student & student);
};


class Worker:public Person{

    protected:
        string position;

    public:
        void show_data();

    friend void insert_worker_data(Worker & worker);
};


int main() {
    Student student = Student();
    insert_student_data(student);

    Worker worker = Worker();
    insert_worker_data(worker);

    cout << endl << endl;

    student.show_data();
    worker.show_data();
    return 0;
}


void insert_student_data(Student & student){
    cout << "STUDENT" << endl;
    cout << "Set first name: ";
    cin >> student.first_name;

    cout << "Set last name: ";
    cin >> student.last_name;

    cout << "Set age: ";
    cin >> student.age;

    cout << "Set group: ";
    cin >> student.group;
}


void insert_worker_data(Worker & worker){
    cout << "WORKER" << endl;
    cout << "Set first name: ";
    cin >> worker.first_name;

    cout << "Set last name: ";
    cin >> worker.last_name;

    cout << "Set age: ";
    cin >> worker.age;

    cout << "Set position: ";
    cin >> worker.position;
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
