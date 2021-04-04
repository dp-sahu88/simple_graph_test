//Author:DEADPOOL
//User@DEADPOOL
//Device name:LAPTOP-MGJPSU5N
//***************************
#include <stdio.h>
#include<stdlib.h>
#include<ctype.h>
// checking for the integer
int isInteger(char str[10]){
    int counter;
    for(counter=0;str[counter]!='\0';counter++){
        if(isdigit(str[counter])==0)
            return 0;
        else
            return 1;
    }
}
//is_Les_thn_n()checkes that degree of each vertex should less than n
int is_Les_thn_n(int *vrtx,int n_vertex){
    int counter;
    for (counter = 0; counter < n_vertex ;counter++){
        if (vrtx[counter]>=n_vertex)
            return 0;
    }
    return 1;
}


//deleting the element from 1st position
int dlt_1_elmt(int *d_vrtx,int n){
    int count,val;
    val=d_vrtx[0];
    for (count=0;count<(n-1);count++) {
        d_vrtx[count]=d_vrtx[count+1];
    }
    return val;
}

//sorting the array
void srt(int *d_vrtx,int n){
    int count_i,count_j,temp;
    for (count_i=0;count_i<n-1;count_i++){
        for (count_j=count_i+1;count_j<n;count_j++){
            if (d_vrtx[count_i]<d_vrtx[count_j]){
            temp=d_vrtx[count_i];
            d_vrtx[count_i]=d_vrtx[count_j];
            d_vrtx[count_j]=temp;
            }
        }
    }
}

//substracting 1 from eligible element ......
void sub_n_elmt(int *d_vrtx,int n){
    int count;
    for (count=0;count<n;count++){
        d_vrtx[count]-=1;
    }
}

//there should even number of odd vertices..
// so the following function checks the above condition
int is_evn_od_degree(int *vrtx,int n_vertex){
    int odd_count,counter;
    for (counter = 0; counter < n_vertex ;counter++){
        if ((vrtx[counter]%2)!=0)
            odd_count++;
    }
    if ((odd_count%2)==0)
        return 1;
    else
        return 0;

}

//havel's hakim test
int is_h_h(int *vrtx,int n_vertex){

  signed  int d_vrtx[n_vertex];
  int counter,dltd_elmt;

    //creating a duplicate array of vrtx as d_vrtx...
    for (counter=0;counter<n_vertex;counter++)
        d_vrtx[counter]=vrtx[counter];

recur:
    srt(d_vrtx,n_vertex);//sorting the array
    dltd_elmt=dlt_1_elmt(d_vrtx,n_vertex);//deleting the 1st element
    n_vertex--;//decrease in the number of vertex after deleting an element
    sub_n_elmt(d_vrtx,dltd_elmt);// subtracting 1 from 1st (dltd_elmt) no.of element
    for (counter=0;counter<n_vertex;counter++){
        if (d_vrtx[counter]>0)
            goto recur;
        else if(d_vrtx[counter]<0)
            return 0;

    }
    return 1;

}


int main() {
    //variable declaration
    int *vrtx,flag,n_vertex,f,flag1,flag2,flag3,counter;
    char str[10];

    //no of vertices taking as input

n_vertices:
    printf("\nEnter the number of vertices in the graph ");
    scanf("%s",str);
    flag=isInteger(str);
    if(flag==1)
        n_vertex=atoi(str);
    else
        goto n_vertices;

     //allocating the memory to stote the degree of vertices

    vrtx=(int *)malloc(n_vertex*sizeof(int));

    //taking the degree of vertices as input

vertices:
    printf("\nEnter degrees vertices..");
    for (counter=0;counter<n_vertex;counter++){
        scanf("%s",str);
        flag=isInteger(str);
        if(flag==1)
             vrtx[counter]=atoi(str);
        else {
             printf("\n only integers can be degree of vertex you may entered a character as input... so try again .... ");
            goto vertices;

         }
    }
    //checking all three condition so that we can proof that this is a simple graph ...

    flag1=is_Les_thn_n(vrtx,n_vertex);
    if (flag1==1)
        printf("\n\a each vertex have less than %d degree which is less than the number of vertices in graph",n_vertex);
    else{
        printf ("\n\a this is not a simple graph because ,there is/are some vertex whose degree greater than %d ",n_vertex-1);
        return 0;
    }
    flag2=is_evn_od_degree(vrtx,n_vertex);
    if (flag2==1){
        printf("\n\n even no of odd degree found ,this may be a simple graph");
    }
    else{
        printf ("\n\n\a odd no of odd degrees found this is not a simple graph...");
        return 0;
    }
    if ((flag1==1)&&(flag2==1)){
        if(is_h_h(vrtx,n_vertex)){
            printf("\n\a It's a simple graph");
           // plot_graph(vrtxn_vertex);
        }
        else
            printf("\n\a It's not a simple graph");
    }

    return 0;
}
