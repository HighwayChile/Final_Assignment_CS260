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





# REFERENCES & RESOURCES   

Kruskal's Algorithm: finds minimum spanning tree  
--------------------  
The algorithm performs the following steps:  

    Create a forest (a set of trees) initially consisting of a separate single-vertex tree for each vertex in the input graph.  
    Sort the graph edges by weight.  
    Loop through the edges of the graph, in ascending sorted order by their weight. For each edge:  
        Test whether adding the edge to the current forest would create a cycle.  
        If not, add the edge to the forest, combining two trees into a single tree.  

At the termination of the algorithm, the forest forms a minimum spanning forest of the graph. If the graph is connected, the forest has a single component and forms a minimum spanning tree.   







openGL - getting started https://www.khronos.org/opengl/wiki/Getting_Started#Downloading_OpenGL    

openGL tutorial https://ogldev.org/  

openGL loading library - https://www.khronos.org/opengl/wiki/OpenGL_Loading_Library  

nvidia driver, Windows (my card, 2070 super) https://www.nvidia.com/Download/driverResults.aspx/224748/en-us/   


GLEW - https://glew.sourceforge.net/  

GLFW - https://www.glfw.org/download.html  

GLAD Multi-Language GL/GLES/EGL/GLX/WGL Loader-Generator based on the official specs. - https://glad.dav1d.de/    

instructional videos:  
https://www.youtube.com/watch?v=Y4F0tI7WlDs  
https://www.youtube.com/watch?v=Zqsj--c_RME   






# INSTRUCTIONS  

Topics: More graph coding, making an add_node and add_edge function in our code, and discussion of graph algorithms  

helping with final projects, review, and thinking ahead?  


Other graph properties: connectivity, graph cuts, isographs, others?  


Let's go over some shortest-path algorithms, such as Dijkstra's algorthm: https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm  

Let's also go over minimum spanning tree algorithms, such as Kruskal's: https://en.wikipedia.org/wiki/Kruskal%27s_algorithm  
