# Final_Assignment_CS260  
Final for CS260, Spring 2024 - Make a Graph  


# Design  
I want to make an interactive graph that has a visual interface, using openGL.  

The reason I want a visual representation is because that is the easiest way for me to be 
reasonably sure that my mathematics are correct. It also adds a flair and "production value"     

Adding a node could cause a visual problem in openGL where it draws a node over a node. 
NEED TO develop algorithm - One simple solution would be to have a 2D representation 
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


This graph should allow user to:  
--------------------------------  
add a node  
add an edge  
determine if a path is possible from node 00 to node A5  
highlight node - maybe   
find shortest path(highlight)  
traverse shortest path? - maybe, might be pointless, might be fun to watch.    
find all paths(highlight)  



Design constraints(features):  
-----------------------------  
User may not name the nodes. Might use two-hexadigit numbering system.  
This would allow for 256 total nodes, as long as removing nodes is not an issue.  



Objects needed:    
---------------  
linked list of node structs  
struct node(name, num_edges(weight), color, width, what_else_???)  
 - can each node have a "sub-node" that is the collision node?  
 - color, width options could allow for a highlight.  
struct edge(name, connections(0,1,2), color, width, what_else_???)  
Should a path be an object?  




Functions needed:  
-----------------  
void add_node()  
void add_edge()  
bool is_path_extant()  
void shortest_path()  
void find_all_paths() 
void min_span_tree()   





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

openGL - getting started https://www.khronos.org/opengl/wiki/Getting_Started#Downloading_OpenGL    

openGL tutorial https://ogldev.org/  

openGL loading library - https://www.khronos.org/opengl/wiki/OpenGL_Loading_Library  

nvidia driver, Windows (my card, 2070 super) https://www.nvidia.com/Download/driverResults.aspx/224748/en-us/   


GLEW - https://glew.sourceforge.net/  

GLFW - https://www.glfw.org/download.html  

GLAD Multi-Language GL/GLES/EGL/GLX/WGL Loader-Generator based on the official specs. - https://glad.dav1d.de/    

instructional videos:  
---------------------  
https://www.youtube.com/watch?v=Y4F0tI7WlDs  
https://www.youtube.com/watch?v=Zqsj--c_RME   






# INSTRUCTIONS  

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
