# simple_graph_test


This is a code in c language to check whether a graph is a simple graph or not 




The degree of  all the vertices are taken as input from user   and then stored in an array 




Then we checked  the following condition to check that the graph is a simple graph 
      1) Each vertex of the graph should have the degree <= n-1  , where n is the number of vertices in the graph . This is done in the [int is_Les_thn_n(int *vrtx,int n_vertex)] function .
    2) Then we check for the whether even number of vertices containing odd degree is there , if yes then it may be a simple graph.This condition is checked in  [int is_evn_od_degree(int *vrtx,int n_vertex)] function  .
    3) Because the above two are not enough to check a simple graph ,  we use the famous Havel's Hakim method to check the simple graph . This condition is checked in [int is_h_h(int *vrtx,int n_vertex)] function .





thank you ....
