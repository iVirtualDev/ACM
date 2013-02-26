#include <iostream>
#include <string>
#include <cassert>

using namespace std;

int read_number(const char** curr, const char* const end) {
    const char* current = *curr;
    int sign = 1;
    if (*current == '-') {
	sign = -1;
	++current;
    }
    int result = 0;
    while ((current < end) && (*current >= '0') && (*current <= '9')) {
	const int digit = *current - '0';
	result = 10 * result + digit;
	++current;
    }
    *curr = current;
    return sign * result;
}

void read_spaces(const char** curr, const char* end) {
    const char* current = *curr;
    while ((current < end) && (*current == ' ')) {
	++current;
    }
    *curr = current;
}

int calculate(const char* begin, const char* const end) {
    const int BEGIN = 0;
    const int EXP_NUMBER = 1;
    const int EXP_OP = 2;
    
    int result;
    int last_number;
    char last_op;

    int state = BEGIN;
    const char* current = begin;

    while (current < end) {
	if ((state == BEGIN) || (state == EXP_NUMBER)) {
	    int sign = 1;
	    if (*current == '-') {
		sign = -1;
		++current;
	    }
	    if (*current == '(') {
		++current;
		const char* new_begin = current;
		int count = 1;
		while (current < end) {
		    if (*current == '(') {
			++count;
		    } else if (*current == ')') {
			--count;
		    }

		    if (count == 0) {
			break;
		    }
		    ++current;
		}
		assert(*current == ')');
		assert(count == 0);
		last_number = calculate(new_begin, current);
		++current;
	    } else {
		last_number = read_number(&current, end);
	    }
	    if (state == BEGIN) {
		result = sign * last_number;
	    } else {
		switch (last_op) {
		case '+':
		    result = result + sign * last_number;
		    break;
		case '-':
		    result = result - sign * last_number;
		    break;
		case '*':
		    result = result * sign * last_number;
		    break;
		case '/':
		    result = result / (sign * last_number);
		    break;
		}
	    }
	    state = EXP_OP;
	} else if (state == EXP_OP) {
	    read_spaces(&current, end);
	    last_op = *current;
	    ++current;
	    read_spaces(&current, end);
	    state = EXP_NUMBER;
	}
    }
    return result;
}

int main() {
    string line;
    getline(cin, line);

    cout << calculate(line.data(), line.data() + line.size()) << endl;
    return 0;
}
