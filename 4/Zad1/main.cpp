//nnoremap <F5> :<C-U>make %:r && ./%:r<CR>
#include <iostream>
#include <fstream>

using namespace std;


class Student{

    private:
        string group;
        string first_name;
        string last_name;
        int age;

    public:
        void insert_data();
        void save_data(string path);
        void show_data(string path);
};


int main() {
    string path = "/Users/jakubnowak/Desktop/student.txt";

	Student student;
    student.insert_data();
    student.save_data(path);
    student.show_data(path);
	return 0;
}


void Student::insert_data(){
    cout << "Set first name (string): ";
    cin >> first_name;

    cout << "Set last name (string): ";
    cin >> last_name;

    cout << "Set age (integer): ";
    cin >> age;

    cout << "Set group (string): ";
    cin >> group;

}


void Student::save_data(string path){
    ofstream student_file;
    student_file.open(path);
    student_file
        << "first name: "  << first_name
        << ", last name: " << last_name
        << ", age: " << age
        << ", group: " <<  group;
    student_file.close();
    cout << "Saved student to file: " << path << endl;
}


void Student::show_data(string path){
    string line;

    cout << "Reading student from file: " << path << endl;

    ifstream student_file;
    student_file.open(path);

    if (student_file.is_open()){
        while (getline(student_file, line)) {
            cout << line << endl;
        }
        student_file.close();
    }
}
