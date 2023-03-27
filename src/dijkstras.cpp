// dijsktras.cpp
// Main Execution
#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main(int argc, char *argv[])
{
    map <char, int> path;
    vector < vector <int> > vec;
    int num_title, title_point, row, col, size;
    char type, c;

    cin >> num_title;
    for (int i = 0; i < num_title; i++)
    {
        cin >> type >> title_point;
        path.insert(pair<char, int>(type, title_point));
    }

    cin >> row >> col;

    for (int i = 0; i < row; i++)
    {
        vec[i].resize(col);
        for (int j = 0; j < col; j++)
        {
            cin >> c;
            vec[i][j] = path.find(c)->second;
        }
    }


    return 0;
}
