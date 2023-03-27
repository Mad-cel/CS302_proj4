// dijsktras.cpp
// Main Execution
#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Node
{
    public:
        Node(int r, int c, int weight);
        int r;
        int c;
        int weight;
        int distance_from_start;
        bool visited;
        Node * prev;
};

Node::Node(int r, int c, int weight)
{
    this->r = r;
    this->c = c;
    this->weight = weight;
    visited = false;
    prev = NULL;
    distance_from_start = -1;
}

int main(int argc, char *argv[])
{
    map <char, int> path;
    vector < vector <Node*> > node_Vec;
    int num_title, title_point, map_row, map_col, start_row, start_col;
    char type, c;

    cin >> num_title;
    for (int i = 0; i < num_title; i++)
    {
        cin >> type >> title_point;
        path.insert(pair<char, int>(type, title_point));
    }

    cin >> map_row >> map_col;
    node_Vec.resize(map_row);

    /*Store the index and weight of each Node into the Node vector*/
    for (int i = 0; i < map_row; i++)
    {
        node_Vec[i].resize(map_col);
        for (int j = 0; j < map_col; j++)
        {
            cin >> c;
            node_Vec[i][j] = new Node(i, j, path.find(c)->second);
        }
    }

    cin >> start_row >> start_col;
    /***********End of input **********/    


    return 0;
}
