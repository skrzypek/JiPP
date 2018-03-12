//nnoremap <F5> :<C-U>make %:r && ./%:r<CR>
#include <iostream>
#include <fstream>

using namespace std;


template <class Object> class IOManager{

    public:
        static Object read_data_from_file(Object & object, string path);
        static Object save_data_to_file(Object & object, string path);
};


class Person{

    protected:
        string first_name;
        string last_name;
        int age;
};


class Student:public Person{

    protected:
        string group;

	public:
        void insert_data();
};


class StudentEdukacja:public Student{

    protected:
        int index;

	public:
        void insert_index();
        void show_data();
};


int main() {
	string path = "/Users/jakubnowak/Desktop/student.bin";

	StudentEdukacja student;

    student.insert_data();
    student.insert_index();

    IOManager <StudentEdukacja>::save_data_to_file(student, path);
    IOManager <StudentEdukacja>::read_data_from_file(student, path);

    student.show_data();
	return 0;
}


void StudentEdukacja::insert_index(){
    cout << "Set index (integer): ";
    cin >> index;
}


void Student::insert_data(){
    cout << "Set first name (string): ";
    cin >> first_name;

    cout << "Set last name (string): ";
    cin >> last_name;

    cout << "Set group (string): ";
    cin >> group;

    cout << "Set age (integer): ";
    cin >> age;
}

void StudentEdukacja::show_data(){
    cout << endl;
    cout << "Read from file: " << endl;
    cout << "Index: " << index << endl;
    cout << "First name: " << first_name << endl;
    cout << "Last name: " << last_name << endl;
    cout << "Group: " << group << endl;
    cout << "Age: " << age << endl;
}


template <class Object> Object IOManager<Object>::read_data_from_file(Object & object, string path){
    if (ifstream(path)){
        ifstream file;
        file.open(path, ios::in | ios::binary);
        file.read((char*) &object, sizeof(object));
        file.close();
    }

    return object;
}


template <class Object> Object IOManager<Object>::save_data_to_file(Object & object, string path){
    ofstream file;
    file.open(path, ios::out | ios::binary);
    file.write((char*) &object, sizeof(object));
    file.close();

    return object;
}
