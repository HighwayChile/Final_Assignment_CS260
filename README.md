# Final_Assignment_CS260    
Final for CS260, Spring 2024 - Make a Graph  

Locations of assigned modules/functions:  

Design: \Design\Design.md    
Tests: \test_function.cpp     
Graph class: \graph.h, \graph.cpp    

add_vertex(): \graph.cpp - line 28     
add_edge(): \graph.cpp - line 35    
shortest_path(): \graph.cpp - line 159      
min_spanning_tree(): \graph.cpp - line 94     


Complexity analyzation:  
driver.cpp:  





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

Thank you  


# Program Overview  

This program was meant to create a list as the user manually traverses a list as the list is being created.  

The true functionality is that the test_function creates several graphs, then does function calls on those graphs  

These graphs are weighted graphs that contain vertices and edges. Each one is a class object with attributes.  

