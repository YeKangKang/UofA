#include "Musician.h"
#include "Orchestra.h"
#include <iostream>
using namespace std;

int main(){
	Musician A;
	Musician B;
	Musician C;

	Orchestra* O = new Orchestra(3);

	O->add_musician(A);
	O->add_musician(B);
	O->add_musician(C);

	cout << O->get_current_number_of_members() << endl;
}