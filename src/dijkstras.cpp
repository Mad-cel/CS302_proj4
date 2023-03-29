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
		//~Node();
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

/*
Node::~Node()
{
	delete []prev;
}
*/

int main(int argc, char *argv[])
{
    map <char, int> path;
    vector < vector <Node*> > node_Vec;
    multimap<int, Node*> node_mutimap;
    multimap<int, Node*>::iterator it;
    int num_title, title_point, map_row, map_col, start_row, start_col, total_distance, row, col, end_row, end_col;
    char type, c;
    //Node * node;

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

    cin >> start_row >> start_col >> end_row >> end_col;
	//cout << end_row << end_col;
    /***********End of input **********/
    Node * start_node = node_Vec[start_row][start_col];   //satrting Node
    Node * right_node, * bottom_node;
    start_node->distance_from_start = 0;
    node_mutimap.insert(pair<int, Node*>(0, start_node)); //insert satring node and makle the distance to 0 
    it = node_mutimap.begin();
    
    while (it != node_mutimap.end())
    {
		start_node = it->second;

        if (start_node->visited == false)
        {
            start_node->visited = true;
            total_distance = start_node->weight + it->first;    //the distance would be the cost of leaving the Node + the distance taken already 
            row = start_node->r;
            col = start_node->c;

            //Find adjcent Node only search right and bottom
            if (col + 1 < map_col)
            {
                right_node = node_Vec[row][col + 1];
                if (right_node->distance_from_start == -1)  //not visited, add the distance from start, push Node to multimap 
                {
                    right_node->distance_from_start = total_distance;
                    right_node->prev = start_node;
                    node_mutimap.insert(pair<int, Node *>(total_distance, right_node));
                    it = node_mutimap.begin();
                }

                else if (total_distance < right_node->distance_from_start)  //similiarly if a shorter path exist, same thing happen
                {
                    right_node->distance_from_start = total_distance;
                    right_node->prev = start_node;
                    node_mutimap.insert(pair<int, Node *>(total_distance, right_node));
                    it = node_mutimap.begin();
                }
            
            }

            if (row + 1 < map_row)
            {
                bottom_node = node_Vec[row + 1][col];
                if (bottom_node->distance_from_start == -1)
                {
                    bottom_node->distance_from_start = total_distance;
                    bottom_node->prev = start_node;
                    node_mutimap.insert(pair<int, Node*>(total_distance, bottom_node));
                    it = node_mutimap.begin();
                }

                else if (total_distance < bottom_node->distance_from_start)
                {
                    bottom_node->distance_from_start = total_distance;
                    bottom_node->prev = start_node;
                    node_mutimap.insert(pair<int, Node*>(total_distance, bottom_node));
                    it = node_mutimap.begin();                    
                }
            }

            else
                it++;
        }

        else if (start_node->visited)
			it++;
    }
	
	cout << node_Vec[end_row][end_col]->distance_from_start << endl;
    Node * node = node_Vec[end_row][end_col];
	vector <pair <int, int >> dest;
	
	while (node != NULL )
	{
		dest.push_back(pair<int, int>(node->r, node->c));
		node = node->prev;
	}

	for (int i = dest.size() - 1; i >= 0; i--)
	{
		cout << dest[i].first << " " << dest[i].second << endl;
	}

	for (int i = 0; i < map_row; i++)
	{
		for (int j = 0; j < map_row; j++)
		{
			delete node_Vec[i][j];
		}
	}
	node_Vec.clear();
	

    return 0;
}

