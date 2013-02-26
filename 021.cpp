#include <iostream>
#include <string>
#include <vector>
#include <cassert>

using namespace std;

size_t find_token(const string& line, const size_t begin) {
    assert(line[begin] == '{');

    int count = 1;
    size_t end = begin + 1;
    while (count > 0) {
	assert(end < line.size());
	if (line[end] == '{') {
	    ++count;
	} else if (line[end] == '}') {
	    --count;
	}
	++end;
    }
    assert(end - 1 >= begin + 1);
    return end;
}

struct Rectangle {
    int width;
    int height;
};

Rectangle get_size(const string& line, const size_t begin, const size_t end) {
    Rectangle result;

    const int NUMERATOR = 0;
    const int DENOMINATOR = 1;
    const int FREE = 2;
    vector<Rectangle> tokens[3];
    int index = 0;

    size_t pos = begin;
    while (pos < end) {
	if (line[pos] == '{') {
	    size_t new_pos = find_token(line, pos);
	    tokens[index].push_back(get_size(line, pos + 1, new_pos - 1));

	    pos = new_pos;
	} else if (line[pos] == '/') {
	    index = DENOMINATOR;
	    ++pos;
	} else if ((line[pos] == '+') || (line[pos] == '-') || (line[pos] == '*')) {
	    index = NUMERATOR;
	    ++pos;
	} else {
	    size_t new_pos = line.find_first_of("+-*", pos);
	    if ((new_pos == string::npos) || (new_pos >= end)) {
		new_pos = end;
	    }

	    Rectangle r;
	    r.width = new_pos - pos;
	    r.height = 1;
	    tokens[FREE].push_back(r);

	    pos = new_pos;
	}
    }

    assert(tokens[NUMERATOR].size() == tokens[DENOMINATOR].size());

    const unsigned int fraction_count = tokens[NUMERATOR].size();
    result.width = 0;
    for (unsigned int i = 0; i < fraction_count; ++i) {
	result.width += max(tokens[NUMERATOR][i].width, tokens[DENOMINATOR][i].width) + 2;
    }

    for (unsigned int i = 0; i < tokens[FREE].size(); ++i) {
	result.width += tokens[FREE][i].width;
    }

    result.width += max(fraction_count + tokens[FREE].size(), (size_t)1) - 1;

    if (fraction_count > 0) {
	int max_height[] = {0, 0};
	for (int k = 0; k < 2; ++k) {
	    for (unsigned int i = 0; i < tokens[k].size(); ++i) {
		max_height[k] = max(max_height[k], tokens[k][i].height);
	    }
	}
	result.height = max_height[0] + max_height[1] + 1;
    } else if (tokens[FREE].size() > 0) {
	result.height = 1;
    } else {
	result.height = 0;
    }

    return result;
}

int main() {
    string line;
    cin >> line;

    Rectangle result = get_size(line, 0, line.size());
    cout << result.width << '\t' << result.height << endl;
    return 0;
}
