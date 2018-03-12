// nnoremap <F5> :<C-U>make %:r && ./%:r<CR>
// kolokwium z zadań 1, 2, 3 -- 24.06.2017 -- poprawka 25.06.2017
#include <iostream>

using namespace std;


const int students_size = 5;
class StudentEdukacja;


template <class Object> class Bubble{

    public:
        static Object sort(Object objects[], int counter);
};


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
        void insert_data();
        static void show_data(StudentEdukacja students[], int students_size);
};


class StudentEdukacja:public Student{

    public:
        int index;

        void insert_index();
};


int main() {
	StudentEdukacja students[students_size];

    for (int i=0; i<students_size; i++){
        cout << "STUDENT: " << i << endl;

        students[i].insert_data();
        students[i].insert_index();
    }

    Student::show_data(students, students_size);
	return 0;
}


void StudentEdukacja::insert_index(){
    cout << "\tSet index (integer): ";
    cin >> index;
}


void Student::insert_data(){
    cout << "\tSet first name (string): ";
    cin >> first_name;

    cout << "\tSet last name (string): ";
    cin >> last_name;

    cout << "\tSet group (string): ";
    cin >> group;

    cout << "\tSet age (integer): ";
    cin >> age;
}


void Student::show_data(StudentEdukacja students[], int students_size){

    Bubble <StudentEdukacja>::sort(students, students_size);

    for (int i=0; i<students_size; i++){
        cout << "Index: " << students[i].index;
        cout << " First name: " << students[i].first_name;
        cout << " Last name: " << students[i].last_name;
        cout << " Age: " <<  students[i].age;
        cout << " Group: " << students[i].group;
        cout << endl;
    }

}


template <class Object> Object Bubble<Object>::sort(Object objects[], int counter){

    Object temp;
    for (int i=0; i<counter-1; i++){
        if (objects[i].index > objects[i+1].index){
            temp = objects[i];
            objects[i] = objects[i+1];
            objects[i+1] = temp;
            i = -1;
        }
    }
    return *objects;
}
