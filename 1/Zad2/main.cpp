//nnoremap <F5> :<C-U>make %:r && ./%:r<CR>
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;


class Elements{

    private:
        int* elements;
        void insert_data();
        void sort_data();

    public:
        void show_data();

    Elements();
    ~Elements();
};


int main(){
    Elements elements = Elements();
    elements.show_data();
    return 0;
}


Elements::Elements(){
    elements = new int[10];
    insert_data();
}


Elements::~Elements(){
    cout << endl << "Desctructor called: delete [] elements";
    delete [] elements;
}


void Elements::insert_data(){
    srand(time(NULL));
    for (int a=0; a<10; a++){
        elements[a] = rand() % 12 + 1;
    }

    cout << "Your whole data is: ";
    for (int a=0; a<10; a++){
        cout << elements[a] << ", ";
    }
    cout << endl;
}


void Elements::sort_data(){
    int temp(0);
    for (int i=0; i<9; i++){
        if (elements[i]>elements[i+1]){
            temp = elements[i];
            elements[i] = elements[i+1];
            elements[i+1] = temp;
            i = -1;
        }
    }
}


void Elements::show_data(){
    sort_data();

    cout << "Your sorted data is: ";
    for (int a=0; a<10; a++){
        cout << elements[a] << ", ";
    }
}
