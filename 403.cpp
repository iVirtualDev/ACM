#include <iostream>
#include <string>

using namespace std;

int read_number(const string& line, int pos, int* number) {
    int sign = 1;
    if (line[pos] == '-') {
	sign = -1;
	++pos;
    }
    int result = 0;
    while ((pos < line.size()) && (line[pos] >= '0') && (line[pos] <= '9')) {
	const int digit = line[pos] - '0';
	result = 10 * result + digit;
	++pos;
    }
    *number = sign * result;
    return pos;
}

int read_spaces(const string& line, int pos) {
    while ((pos < line.size()) && (line[pos] == ' ')) {
	++pos;
    }
    return pos;
}

int main() {
    string line;
    getline(cin, line);

    int a, b;
    char op;

    int pos = read_number(line, 0, &a);
    pos = read_spaces(line, pos);
    op = line[pos];
    ++pos;
    pos = read_spaces(line, pos);
    pos = read_number(line, pos, &b);

    switch (op) {
    case '+':
	cout << a + b << endl;
	break;
    case '-':
	cout << a - b << endl;
	break;
    case '*':
	cout << a * b << endl;
	break;
    case '/':
	cout << a / b << endl;
	break;
    }
    return 0;
}
