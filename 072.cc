#include <iostream>
#include <cassert>

using namespace std;

const int RIGHT = 0;
const int LEFT = 1;
const int BOTTOM = 2;
const int UP = 3;
const int FRONT = 4;
const int BACK = 5;

const int transitions[] = {
    //right
    BOTTOM, RIGHT,
    RIGHT, UP,
    UP, LEFT,
    LEFT, BOTTOM,
    FRONT, FRONT,
    BACK, BACK,
    //left
    RIGHT, BOTTOM,
    BOTTOM, LEFT,
    LEFT, UP,
    UP, RIGHT,
    BACK, BACK,
    FRONT, FRONT,
    //down
    FRONT, UP,
    UP, BACK,
    BACK, BOTTOM,
    BOTTOM, FRONT,
    RIGHT, RIGHT,
    LEFT, LEFT,
    //up
    FRONT, BOTTOM,
    BOTTOM, BACK,
    BACK, UP,
    UP, FRONT,
    RIGHT, RIGHT,
    LEFT, LEFT
};

struct CubicPosition {
    explicit CubicPosition(int pos) {
    }

    int to_int() const {
	int start = facets[BOTTOM] * 4 * 2;
	for (int i = start; i < start + 4 * 2; i += 2) {
	    assert(i + 1 < 2*4*6);
	    if (CubicPosition::neighbours[i] == facets[RIGHT]) {
		assert(CubicPosition::neighbours[i + 1] == facets[FRONT]);
		return i / 2;
	    }
	}
	assert(false);
    }

    int facets[6];

    static int neighbours[];
};

int CubicPosition::neighbours[] = {
    //right
    UP, FRONT,
    FRONT, BOTTOM,
    BOTTOM, BACK,
    BACK, UP,
	//left
	UP, FRONT, BOTTOM, BACK,
	//up
        FRONT, RIGHT, BACK, LEFT,
	//bottom
	FRONT, RIGHT, BACK, LEFT,
	//front
	UP, RIGHT, BOTTOM, LEFT,
	//left
	UP, RIGHT, BOTTOM, LEFT
    };

int main() {
    return 0;
}
