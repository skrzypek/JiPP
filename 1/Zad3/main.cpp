//nnoremap <F5> :<C-U>make %:r && ./%:r<CR>
#include <iostream>
#include <cmath>

using namespace std;


class Computing{

	private:
        int a, b, c;
		void insert_data();
        void show_data(double x1=0, double x2=0);

    public:
		void calculate();

	Computing();
};


int main(){
	Computing compute = Computing();
	compute.calculate();
	return 0;
}


Computing::Computing(){
	insert_data();
}


void Computing::insert_data(){
    cout << "Set a: ";
    cin >> a;

    cout << "Set b: ";
    cin >> b;

    cout << "Set c: ";
    cin >> c;

	cout << endl;
}


void Computing::show_data(double x1, double x2){
    if (x1 != 0){
        cout << "x1: " << x1 << endl;
    }
    if (x2 != 0){
        cout << "x2: " << x2 << endl;
    }

    if (x1 == 0 && x2 == 0){
        cout << "No result." << endl;
    }
}


void Computing::calculate(){
    cout << "a: " << a << " b: " << b << " c: " << c << endl;

    int delta = (b*b) - (4*a*c);
    int switch_number(0);

    cout << "\u2206: " << delta << endl;

    if (delta > 0){
        switch_number = 2;
    } else if (delta == 0){
        switch_number = 1;
    }

    switch (switch_number){
        case 1:
            show_data((b*-1) / (2*a));
            break;
        case 2:
            show_data(
                ((b*-1) - sqrt(delta)) / (2*a),
                ((b*-1) + sqrt(delta)) / (2*a)
            );
            break;
        default:
            show_data();
            break;
    }
}
