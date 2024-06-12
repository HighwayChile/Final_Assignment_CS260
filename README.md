# Final_Assignment_CS260    
Final for CS260, Spring 2024 - Make a Graph  

Locations of required modules/functions:  
--------------------------   

Design: \Design\Design.md    
Tests: \test_function.cpp     
Graph class: \graph.h, \graph.cpp    

add_vertex(): \graph.cpp - line 28     
add_edge(): \graph.cpp - line 35    
shortest_path(): \graph.cpp - line 159      
min_spanning_tree(): \graph.cpp - line 94     


Complexity analyzation:  
-----------------------  
driver.cpp:  
driver function uses swtich, which is O(1)  

test_function.cpp:  
This complexity is variable, but could be expressed as O(vertices+edges)    

graph.h:    
cunstructor has O(1)    
deconstructor has O(vertices+edges)      
add_vertex has O(1)    
add_edge has O(1)    
find_vertex has O(n)    
find_edge has O(n)    
print_graph has O(vertices+edges)  

Kruskal's:   
My attempt:  
Kruskal's has O(log(n^2))  

ChatGPT's answer:  
Kruskal's has O(nlog(n) + nα(m)), where n is edges and m is vertices. This is because the algo has two parts, the sorting and the actual union-find operation.    

Djikstra's:  
My Attempt:  
min_distance is  O(n)  
print_solution is O(n)    
shortest_path is O(n(2n+1))  

ChatGPT's answer:  
shortest_path is O(n^2)






# Message and reflection      

Hello! Thank you for teaching us out! I know I have told you several times that I appreciate it, 
but it bears repeating!  

For this project planning phase lasted too long, and I ended up with a hodgepodge of half-baked ideas that 
sometimes might improve my program. Therefore, my Design.md document is very long.      

My driver.cpp file works, but it is not a realistic driver of my program. It is more of a testing environment. If you want to compile 
and run something, the best bet is to compile and run test_function.cpp. This function shows a 
realistic set of manipulations to the graphs, although driver.cpp shows the very same outputs when user inputs values.  

I also noticed that I found myself putting off applying the algorithms, and instead I would create more 
functions to manipulate the graph or call for more information. I was trying to lay the groundworks for 
an interactive program, but I think I took it too far. Then I had to scramble to implement the algorithms 
properly. Luckily, I noticed my own fault while I still had time to at least get a form of each algorithm working on my graph.     

Thank you!  

Sincerely, HighwayChile(name redacted for public repo)   
Spring 2024    


# Program Overview  

This program was meant to create a list as the user manually traverses a list as the list is being created.  

The true functionality is that the test_function creates several graphs, then does function calls on those graphs  

These graphs are weighted graphs that contain vertices and edges. Each one is a class object with attributes.  

