#include <iostream>
using namespace std;
#define MAX 100
#define TEMP 0
#define PERM 1
#define infinity 9999
#define NIL -1
void findPath(int s, int v);
void Dijkstra(int s);
int min_temp();
void create_graph();
int n; // number of vertices
int adj[MAX][MAX];
int pred[MAX];
int pathlength[MAX];
int status[MAX];
int main() {
 int s, v;
 create_graph();
  cout << "Enter the source vertex: ";
  cin >> s;
   Dijkstra(s);
 // start of while loop
    while (1) {
     cout << "Enter destination vertex (-1 to quit): ";
      cin >> v;
    if (v == -1)
     break;
     if (v < 0 || v >= n)
      cout << "This vertex does not exist\n";
       else if (v == s)
            cout << "Source and destination vertices are the same\n";
        else if (pathlength[v] == infinity)
            cout << "There is no path from source to destination vertex\n";
        else
            findPath(s, v);
    }
    // end of while loop
return 0;
} // end of main section
void Dijkstra(int s) {
    int i, current;
  // make all vertices temporary
    for (i = 0; i < n; i++) {
        pred[i] = NIL;
        pathlength[i] = infinity;
        status[i] = TEMP;
    }
// make pathlength of source vertex = 0
    pathlength[s] = 0;
// start of while loop
    while (1) {
        // search for temporary vertex for minimum pathlength and make it 'current' vertex
        current = min_temp();
 if (current == NIL)
            return;
status[current] = PERM;
 for (i = 0; i < n; i++) {
            // check for adjacent temporary vertices
            if ((adj[current][i] != 0) && (status[i] == TEMP))
                if (pathlength[current] + adj[current][i] < pathlength[i]) {
                    pred[i] = current; // relabel it
                    pathlength[i] = pathlength[current] + adj[current][i];
                }
        }
    }
} // end of Dijkstra function

int min_temp() {
    int i;
    int min = infinity;
    int k = NIL;
    for (i = 0; i < n; i++) {
        if (status[i] == TEMP && pathlength[i] < min) {
            min = pathlength[i];
            k = i;
        }
    }
    return k;
} // end of min_temp

void findPath(int s, int v) {
    int i, u;
    int path[MAX]; // stores the shortest path
    int shortDist = 0; // length of shortest path
    int count = 0; // number of vertices in the shortest path

    // store the full path in the array path
    while (v != s) {
        count++;
        path[count] = v;
        u = pred[v];
        shortDist += adj[u][v];
        v = u;
    }
    count++;
    path[count] = s;

    cout << "Shortest path is: ";
    for (i = count; i >= 1; i--)
        cout << path[i] << " ";
    cout << "\nThe shortest distance is: " << shortDist << endl;
} // end of findPath
void create_graph() {
    int i, max_edges, origin, destin, wt;
    cout << "Enter the number of vertices: ";
    cin >> n;
max_edges = n * (n - 1);
 for (i = 1; i <= max_edges; i++) {
        cout << "Enter edge " << i << " (enter -1 -1 to finish): ";
        cin >> origin >> destin;
 if (origin == -1 && destin == -1)
            break;
cout << "Enter weight of this edge: ";
        cin >> wt;
 if (origin > n || destin > n || origin < 0 || destin < 0) {
            cout << "Invalid edge! Please enter again." << endl;
            i--;
        } else
            adj[origin][destin] = wt;
    }
}

/*
output:
enter no of vertices: 
8
enter edge1 (enter -1 -1 to exit)0 2
enter the weight of this edge: 
2
enter edge1 (enter -1 -1 to exit)0 3
enter the weight of this edge: 
7
enter edge1 (enter -1 -1 to exit)2 0
enter the weight of this edge: 
5
enter edge1 (enter -1 -1 to exit)2 3
enter the weight of this edge: 
4
enter edge1 (enter -1 -1 to exit)6 2
enter the weight of this edge: 
6
enter edge1 (enter -1 -1 to exit)2 6
enter the weight of this edge: 
3
enter edge1 (enter -1 -1 to exit)6 3
enter the weight of this edge: 
3
enter edge1 (enter -1 -1 to exit)3 4
enter the weight of this edge: 
9
enter edge1 (enter -1 -1 to exit)4 0
enter the weight of this edge: 
4
enter edge1 (enter -1 -1 to exit)0 1
enter the weight of this edge: 
8
enter edge1 (enter -1 -1 to exit)1 5
enter the weight of this edge: 
16
enter edge1 (enter -1 -1 to exit)4 5
enter the weight of this edge: 
5
enter edge1 (enter -1 -1 to exit)7 5
enter the weight of this edge: 
2
enter edge1 (enter -1 -1 to exit)4 7
enter the weight of this edge: 
8
enter edge1 (enter -1 -1 to exit)7 6
enter the weight of this edge: 
5
enter edge1 (enter -1 -1 to exit)6 4
enter the weight of this edge: 
4
enter edge1 (enter -1 -1 to exit)-1 -1
Enter source vertex:
0
enter destination vertex(-1 to quit):
7
shortest path is:
0
3
4
7
shortest distance is:24
enter destination vertex(-1 to quit):
*/