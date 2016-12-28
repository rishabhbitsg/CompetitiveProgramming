#include <bits/stdc++.h>
using namespace std;

class Str {
public:
	Str() {
		p = new char[128];
		assert(p != 0);
	}

	void print() {
		printf("%s\n", p);
	}

	void set(char * s) {
		p = strcpy(p, s);
	}

	~Str() {
		delete[] p;
	}
private:
	char * p;
};

void display(Str * s) {
	s->print();
}

int main() {
	Str * a = new Str();
	char s[] = "aaaaaaaaa";
	a->set(s);

	a->print();

	int val = 111;
	if (val > 100) {
		display(a);
		a->print();
	}

}

