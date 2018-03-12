// nnoremap <F5> :<C-U>make %:r && ./%:r<CR>
// PROJECT_NAME: Baza danych studentów
#include <iostream>
#include <fstream>
#include <iomanip>

#define RED "\033[31m"
#define RESET "\033[0m"
#define GREEN "\033[32;1m"

using namespace std;


template <class Object> class IOManager{

    public:
        static Object read_data_from_file(Object objects[], string path, int objects_size);
        static Object save_data_to_file(Object objects[], string path, int counter);
};


template <class Object> class Bubble{

    public:
        static Object sort(Object objects[], int counter);
};


class StudentEdukacja{

    private:
        int id;
        int index;
        int age;
        float average_degree;
        string first_name;
        string last_name;
        string group;


    public:
        int get_id(){
            return id;
        }
        int get_index(){
            return index;
        }
        int get_age(){
            return age;
        }
        float get_average_degree(){
            return average_degree;
        }
        string get_first_name(){
            return first_name;
        }
        string get_last_name(){
            return last_name;
        }
        string get_group(){
            return group;
        }

        void insert_data(int &next_id, int &counter);

        static int __init__(StudentEdukacja students[], int students_size, int &counter, int &next_id);
        static void show_data(StudentEdukacja students[], int &counter);
        static void delete_student(StudentEdukacja students[], const int &students_size, int &counter);
};


class Executor{

    private:
        char action;

    public:
        void worker();
};


int main(){
    Executor workflow;
    workflow.worker();
	return 0;
}


void Executor::worker(){
    string path = "/Users/jakubnowak/Desktop/students.bin";
    const int students_size = 20;
    int counter(0), next_id(0);

    StudentEdukacja *students = new StudentEdukacja[students_size];

    if (ifstream(path)){
        cout << "Reading student from file: " << path << endl;
        IOManager <StudentEdukacja>::read_data_from_file(students, path, students_size);
        counter = StudentEdukacja::__init__(students, students_size, counter, next_id);
        StudentEdukacja::show_data(students, counter);
    }

    while (action != 'K'){
        cout << "-------------------------------------------------" << endl;
        cout << left << setw(7) << "Type" << "Descripton" << endl;
        cout << left << setw(7) << "L" << "List all students" << endl;
        cout << left << setw(7) << "D" << "Add new student" << endl;
        cout << left << setw(7) << "U" << "Remove student" << endl;
        cout << left << setw(7) << "K" << "Write all students from memmory to file and exit." << endl;

        cout << "Type a action: ";
        cin >> action;
        action = toupper(action);
        if (counter >= students_size){
            action = 'U';
        }

        switch (action){
            case 'L':
                Bubble <StudentEdukacja>::sort(students, counter);
                StudentEdukacja::show_data(students, counter);
                break;
            case 'D':
                students[counter].insert_data(next_id, counter);
                break;
            case 'U':
                StudentEdukacja::delete_student(students, students_size, counter);
                break;
        }
    }
    IOManager <StudentEdukacja>::save_data_to_file(students, path, counter);
    cout << "Saved students to file: " << path << endl;
}


int StudentEdukacja::__init__(StudentEdukacja students[], int students_size, int &counter, int &next_id){
    for (int i=0; i<students_size; i++){
        if (students[i].first_name != "" && students[i].last_name != ""){
            if (next_id <= students[i].get_id()){
                next_id = students[i].get_id() + 1;
            }
            counter++;
        }
    }
    return counter;
}


void StudentEdukacja::show_data(StudentEdukacja students[], int &counter){
    for (int i=0; i<counter; i++){
        cout << "ID: " << students[i].get_id() << endl;
        cout << "Index: " << students[i].get_index() << endl;
        cout << "Average degrees: " << students[i].get_average_degree() << endl;
        cout << "First name: " << students[i].get_first_name() << endl;
        cout << "Last name: " << students[i].get_last_name() << endl;
        cout << "Group: " << students[i].get_group() << endl;
        cout << "Age: " << students[i].get_age() << endl;

        cout << "--------" << endl;
    }
}


void StudentEdukacja::insert_data(int &next_id, int &counter){
    id = next_id;

    cout << "Set first name (string): ";
    cin >> first_name;

    cout << "Set last name (string): ";
    cin >> last_name;

    cout << "Set group (string): ";
    cin >> group;

    cout << "Set age (integer): ";
    cin >> age;

    cout << "Set index (integer): ";
    cin >> index;

    cout << "Set average degrees (float): ";
    cin >> average_degree;

    next_id++;
    counter++;
}


void StudentEdukacja::delete_student(StudentEdukacja students[], const int &students_size, int &counter){
    if (counter == 0){
        cout << RED << "StudentEdukacja.IndexError" << RESET << endl;
        return;
    } else if (counter >= students_size){
        cout << RED << "StudentEdukacja.OutOfRange: ArrayDB overload" << RESET << endl;
    }

    int id_to_remove;
    char yes_no;
    cout << "If you want to delete student, just type thier id (";
    for (int to=0; to<counter; to++){
        cout << students[to].get_id();
        if (to != counter-1){
            cout << ", ";
        }
    }
    cout << "): ";
    cin >> id_to_remove;

    for (int i=0; i<counter; i++){
        if (students[i].get_id() == id_to_remove){
            cout << "Found student:" << endl;
            cout << "\tID: " << students[i].get_id() << endl;
            cout << "\tIndex: " << students[i].get_index() << endl;
            cout << "\tAverage degrees: " << students[i].get_average_degree() << endl;
            cout << "\tFirst name: " << students[i].get_first_name() << endl;
            cout << "\tLast name: " << students[i].get_last_name() << endl;
            cout << "\tGroup: " << students[i].get_group() << endl;
            cout << "\tAge: " << students[i].get_age() << endl;

            while (yes_no != 'y' || yes_no != 'n'){
                cout << "Type (y) to remove, (n) to cancel: ";
                cin >> yes_no;

                if (yes_no == 'y'){
                    for (int d=i; d<counter-1; d++){
                        students[d] = students[d+1];
                    }
                    cout << GREEN << "**Removed**" << RESET << endl;
                    counter--;
                    return;
                } else if (yes_no == 'n') {
                    cout << "**Cancelled**" << endl;
                    return;
                }
            }
        }
    }

    cout << RED << "StudentEdukacja.DoesNotExist" << RESET << endl;
}


template <class Object> Object Bubble<Object>::sort(Object objects[], int counter){

    Object temp;
    for (int i=0; i<counter-1; i++){
        if (objects[i].get_index() > objects[i+1].get_index()){
            temp = objects[i];
            objects[i] = objects[i+1];
            objects[i+1] = temp;
            i = -1;
        }
    }
    return *objects;
}


template <class Object> Object IOManager<Object>::read_data_from_file(Object objects[], string path, int objects_size){
    if (ifstream(path)){
        ifstream student_file;
        student_file.open(path, ios::in | ios::binary);
        student_file.read((char*) objects, sizeof(objects[0])*objects_size);
        student_file.close();
    }

    return *objects;
}


template <class Object> Object IOManager<Object>::save_data_to_file(Object objects[], string path, int counter){
    ofstream object_file;
    object_file.open(path, ios::out | ios::binary);
    object_file.write((char*) objects, sizeof(objects[0])*counter);
    object_file.close();

    return *objects;
}
