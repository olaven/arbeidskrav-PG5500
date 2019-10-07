#ifndef ARBEIDSKRAV_LETTERS
#define ARBEIDSKRAV_LETTERS

int t[][20] = {
    //horizontal part
    {4, 0},
    {4, 1},
    {4, 2},
    {4, 3},
    {4, 4},
    //vertical part
    {0, 2},
    {1, 2},
    {2, 2},
    {3, 2},
};

int e[][20] = {
    //top
    {4, 0},
    {4, 1},
    {4, 2},
    {4, 3},
    //middle
    {2, 0},
    {2, 1},
    {2, 2},
    {2, 3},
    //bottom
    {0, 0},
    {0, 1},
    {0, 2},
    {0, 3},
    //missing parts of "trunk"
    {1, 3}, //Does not render on my display. TODO: check on someone elses
    {3, 3}};

int s[][20] = {
    // bottom
    {0, 0},
    {0, 1},
    {0, 2},
    {0, 3},
    // right trunk
    {1, 0},
    // middle
    {2, 0},
    {2, 1},
    {2, 2},
    {2, 3},
    // left trunk
    {3, 3},
    // top
    // middle
    {4, 0},
    {4, 1},
    {4, 2},
    {4, 3}};

#endif