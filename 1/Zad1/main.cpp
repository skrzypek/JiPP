//nnoremap <F5> :<C-U>make %:r && ./%:r<CR>
#include <iostream>

using namespace std;


class Elements{

    private:
        int elements[10];
        void read_data();
        void sort_data();

    public:
        void show_data();

    Elements();
};


int main(){
	Elements elements = Elements();
	elements.show_data();
	return 0;
}


Elements::Elements(){
	read_data();
}


void Elements::read_data(){
	cout << "Input your numbers (10)" << endl;
	for (int a=0; a<10; a++){
		cout << "Set number with index (" << a << "): ";
		cin >> elements[a];
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
