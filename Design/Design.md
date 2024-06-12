
# Design    

# Program Flow  

* NOTE - This program flow did not make it in. driver.cpp is not set up properly    
intro   
menu    
start   
request edge  
user input choose edge  
request name  
user input name vertex   
request num_edges    
user input choose num_edges    

request edge    
user input edge    


# General  


* This was from when I was thinking I might use openGL (never have used it before, and changed my mind about it)  

Adding a node could cause a visual problem in openGL where it draws a node over a node. 
need to develop algorithm - One simple solution would be to have a 2D representation 
of the graph. Something like:    

void draw_node(){    
    while(new node is created){    
        if(no node exists in display){    
            draw node to openGL;    
        }    
        else{    
            move over 10 pixels;   
            move up 10 pixels;   
            draw_node();   
        }    
    }    
}    
// Does openGl have typical sort of collision detection? if so, could make a collision object,   
as well as visual object for each node.    
// Research openGL collision, and if it is easy, make a 3D graph.  


I originally had wanted to include the dangling edges.   

I am not sure if I want to have a remove function, but it would be a good way to prove it's pathfinding.  

OUTLINE - User begins in room Alpha. There are three paths; A, B and C. User will be asked which path to take, 
then the user will be asked what room they have entered (name new vertex, room). User will be asked how many paths they 
see(min 1, max 10, new edges.)  




This graph should allow user to:  
--------------------------------  
accept user input (string)  
add a node  
add an edge  
determine if a path is possible from node A to node B   
find a node   
find shortest path(highlight)     
find all paths(highlight) // not really needed, will just highlight all edges.  
find the minimum spanning tree of the graph  


Design constraints(features):  
-----------------------------  
User may not name the nodes. Might use two-hexadigit numbering system.  
CHANGE - maybe user names each room, and also the number of doors(edges)?   
I like this, I think user names each room using string input.  
Should I limit the number of edges per vertex? ex: max_weight = 4? - It's not unreasonable.  
Must limit each edge to have a max of 2 vertices. ex: max_weight = 2 - I will refer to this as weight as well.   


Objects needed:    
---------------  
linked list of node structs   
call the node "vertex!"  
struct vertex(name, id number, num_edges(weight), color, width, what_else_???)   
 - can each node have a "sub-node" that is the collision node?  
 - color, width options could allow for a highlight.  
struct edge(name, connections(0,1,2), color, width, what_else_???)  
Should a path be an object? I don't need it to be. idk...    


Object Pseudo:  
--------------  
struct vertex {  
    string name; 
    int id; 
    int num_edges;  
    color(what data type?); //surely this is an openGL setting lol    
    width;// this line is also something with openGL. Perhaps two structs, one collision.    
    vertex *next;  
};  

struct edge {  

}  

class graph {   
    vertex *head;   
    -add function declarations-   
};   

class collision_graph {   
    vertex *head;  
} // this is not right, but I think I want two graphs, one for math, one for display   


Functions needed:  
-----------------  
string user_input() //idk, could return string to use elsewhere.      
void add_node()   
void add_edge()   
void find_node()   
void find_edge()   
bool is_path_extant()   
void shortest_path()   
void min_span_tree()   


Functions Pseudo:   
-----------------   
 
string user_input(){    
    string user_input;  
    if(cin >> "" ){  
        cout << This is an empty input, try again;  
    } else {    
        return user_input;   
    }    
}    


void graph::add_node(){    

}    


void graph::add_edge(){   

}   


bool graph::is_path_extant(){   
    This will take two inputs from user_input   
    string input_A;  
    string input_B;  

    if(the edges don't connect the vertices twixt A and B) {  
        return false;  
    } else {  
        return true;  
    }  

}  


void graph::shortest_path(){  
    run is_path_extant() on two inputs, both string, both from user_in    

    if (is_path_extant = true) {    
        use algo to find shortest path    
    } else {    
        cout << "not gonna do it" << endl;    
    }    
}  // Dijkstra's Algo is roughly Big O(n^2)   


void graph::min_span_tree(){    
    use kruskal's. Remember: this finds a spanning tree!  
}   




Test functions needed:   
----------------------   
2 tests for each function.  

For testing, I have been testing each functionality as the code comes together enough to test.  
I have run the first tests, and they are outputting the desired   feedback.  
My first tests involved manually creating nodes and edges, connecting them, and printing the 
results to the screen.  
My second tests will be designed.  



Test Design:  
----------------------   

For this test I will create a graph class, populate a graph , then test each connection.  

My first test graph will be a 3 node graph with three edges.  
nodes are: A, B, and C    
edges are: A/B, B/C, and C/A    
C/A and A/C are equivalent (C/A or A/C)    

My second test graph will be a binary tree    
nodes are: D, E, F, G, H, I, J, K, L    
terminal nodes are: G, H, I, K, L    
edges are: D/E, D/F, E/G, E/H, F/I, F/J, J/K    
so it looks like this:    

            D     
          /   \     
         E     F     
        / \   / \     
       G   H I   J    
                / \     
               K   L    


My third test graph will be a more complicated example, 
which will be good for testing my algorithms.    
nodes are: M, N, O, P, Q, R, S    
edges are: ???    


# REFERENCES & RESOURCES   

Kruskal's Algorithm: finds minimum spanning tree   
--------------------  
The algorithm performs the following steps:  

1. Create a forest (a set of trees) initially consisting of a separate single-vertex tree for each vertex in the input graph.   
2. Sort the graph edges by weight.   
3. Loop through the edges of the graph, in ascending sorted order by their weight. For each edge:  
    - Test whether adding the edge to the current forest would create a cycle.  
    - If not, add the edge to the forest, combining two trees into a single tree.  

At the termination of the algorithm, the forest forms a minimum spanning forest of the graph. If the graph is connected, the forest has a single component and forms a minimum spanning tree.   





resource sites:    
---------------    
Kruskal's Algortihm:  
---------------  

https://www.geeksforgeeks.org/kruskals-minimum-spanning-tree-algorithm-greedy-algo-2/   

https://en.wikipedia.org/wiki/Kruskal%27s_algorithm   

(I also used my own notes from MTH231)  


Dijkstra's Algorthm  
----------------  
https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm   




OpenGL(I never used OpenGL at all)  
----------------  

openGL - getting started https://www.khronos.org/opengl/wiki/Getting_Started#Downloading_OpenGL    
  
openGL tutorial https://ogldev.org/    

openGL loading library - https://www.khronos.org/opengl/wiki/OpenGL_Loading_Library    

nvidia driver, Windows (my card, 2070 super) https://www.nvidia.com/Download/driverResults.aspx/224748/en-us/     
  

GLEW - https://glew.sourceforge.net/   

GLFW - https://www.glfw.org/download.html   

GLAD Multi-Language GL/GLES/EGL/GLX/WGL Loader-Generator based on   the official specs. - https://glad.dav1d.de/    

instructional videos:  
---------------------  
https://www.youtube.com/watch?v=Y4F0tI7WlDs  
https://www.youtube.com/watch?v=Zqsj--c_RME   






# INSTRUCTIONS  

DUE TUESDAY, JUNE 11, 10:59 PM  
------------------------------  

1. (20%) Create a design before you start coding that describes or shows how a graph structure could be used to store some kinds of data and attempt to solve some kind of problem (yes, this can be a game that needs a graph to represent a map!),  

2. (20%) Create some tests (at least two for each piece of functionality) before you start coding...  

3. (40%) Implement a graph class with at least (this category effectively combines implementation and specification, partly to emphasize getting the algorithms working!):

    - (5%) a function to add a new vertex to the graph (perhaps add_vertex(vertex_name)),

    - (5%) a function to add a new edge between two vertices of the graph (perhaps add_edge(source, destination) or source.add_edge(destination)),

    - (15%) a function for a shortest path algorithm (perhaps shortest_path(source, destination)),

    - (15%) a function for a minimum spanning tree algorithm (example min_span_tree()).

4. (10%) Analyze the complexity of all of your graph behaviors (effectively a part of our documentation for grading purposes),

5. (10%) Once you have implemented and tested your code, add to the README file what line(s) of code or inputs and outputs show your work meeting each of the above requirements (or better, include a small screen snip of where it meets the requirement!).


Let's go over some shortest-path algorithms, such as Dijkstra's algorthm: https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm  

Let's also go over minimum spanning tree algorithms, such as Kruskal's: https://en.wikipedia.org/wiki/Kruskal%27s_algorithm  
