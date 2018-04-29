#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <utility> //for pair

using namespace std;

struct Vertex { 
    //double field stores the cost of each edge
    typedef pair<double, vertex*> edge;
    vector<edge> adj;
    string name;
    vertex(string s) : name(s) {}
    };


class Graph {
    public:
        typedef unordered_map<string, vertex *> vmap;
        vmap my_graph;
        void add_vertex(const string& name);
        void add_edge(const string& from, const string& to, double cost);
    };


void graph::add_vertex(const string& name) {
    vmap::iterator itr = my_graph.find(name);
    if (itr == my_graph.end()) {
        vertex *v;
        v = new vertex(name);
        my_graph[name] = v;        
        }    
    }


void graph::add_edge(const string& from, const string& to, double cost) {
    vertex *f = my_graph.find(from)->second;
    vertex *t = my_graph.find(to)->second;
    pair<double, vertex*> new_edge = make_pair(cost, t);
    f->adj.push_back(new_edge);
    }


void check_neighbours(string node_name, Graph& my_graph, vector<pair <int, int>>& offset_vector, vector<vector<int>> &matrix) {
    for (auto offset : offset_vector) {
        if (matrix[i + offset_vector.first][j + offset_vector.second] == 1) {
            neighbour_name = to_string(i + offset_vector.first) + "#" + to_string(j + offset_vector.second);
            my_graph.add_vertex(neighbour_name);
            my_graph.add_edge(node_name, neighbour_name);
            }    
    }


Graph& convert_to_graph(Graph &my_graph, vector<vector<int>> &matrix, int n, int m) {
    typedef pair <int, int> index_offset;
    vector <index_offset> top_left {make_pair(0, 1), make_pair(1, 1), make_pair(1, 0)};
    vector <index_offset> top {make_pair(0, -1), make_pair(1, -1), make_pair(1, 0), make_pair(1, 1), make_pair(0, 1)};
    vector <index_offset> top_right {make_pair(0, -1), make_pair(1, -1), make_pair(1, 0)};
    vector <index_offset> left {make_pair(-1, 0), make_pair(-1, 1), make_pair(0, 1), make_pair(1, 1), make_pair(1, 0)};
    vector <index_offset> centre {make_pair(-1, -1), make_pair(-1, 0), make_pair(-1, 1), make_pair(0, 1), make_pair(1, 1), make_pair(1, 0), make_pair(1, -1), make_pair(0, -1)};
    vector <index_offset> right {make_pair(-1, 0), make_pair(-1, -1), make_pair(0, -1), make_pair(1, -1), make_pair(1, 0)};
    vector <index_offset> bottom_left {make_pair(-1, 0), make_pair(-1, 1), make_pair(0, 1)};
    vector <index_offset> bottom {make_pair(0, -1), make_pair(-1, -1), make_pair(-1, 0), make_pair(-1, 1), make_pair(0, 1)};
    vector <index_offset> bottom_right {make_pair(0, -1), make_pair(-1, -1), make_pair(-1, 0)};    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            node_name = to_string(i) + "#" + to_string(j)
            my_graph.add_vertex(node_name);
            if (i = 0 and j = 0)
                check_neighbours(node_name, my_graph, top_left, matrix);                 
            else if (i = 0 and j > 0 and j < m) 
                check_neighbours(node_name, my_graph, top, matrix);                
            else if (i = 0 and j = m) 
                check_neighbours(node_name, my_graph, top_right, matrix); 
            else if (j = 0 and i > 0 and i < n) 
                check_neighbours(node_name, my_graph, left, matrix); 
            else if (j = m and i > 0 and i < n) 
                check_neighbours(node_name, my_graph, right, matrix); 
            else if (j = 0 and i = n) 
                check_neighbours(node_name, my_graph, bottom_left, matrix); 
            else if (i = n and j > 0 and j < m) 
                check_neighbours(node_name, my_graph, bottom, matrix); 
            else if (i = n and j = n) 
                check_neighbours(node_name, my_graph, bottom_right, matrix);                                                           
            else
                check_neighbours(node_name, my_graph, centre, matrix);         
            }                                    
        }
    return my_graph;
    }
    
    
int main() {
    int n, m, num;
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> matrix[i][j];
            } 
        }   
    Graph my_graph;
    my_graph = convert_to_graph(my_graph, matrix, n, m);
    cout << largest_region(input_graph) << endl;
    return 0;
    }    
