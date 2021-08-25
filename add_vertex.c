#include <stdio.h>
#include <stdlib.h>

struct node
{
    int vertex;
    struct node *next;
};
struct node *gnode;
void createGraph(struct node *Adj[ ], int no_of_nodes);
void displayGraph (struct node *Adj[], int no_of_nodes);

int main( )
{
    
    int no_of_nodes;
    int i;
    printf("\n Enter the number of nodes in G: ");
    scanf("%d", &no_of_nodes);
    struct node *Adj[no_of_nodes];// array of pointer 
    for(i = 0; i < no_of_nodes; i++)
        Adj[i] = NULL;
    createGraph(Adj, no_of_nodes);
    printf("\n The graph is: ");
    displayGraph(Adj, no_of_nodes);
    return 0;
}
void createGraph(struct node *Adj[ ], int no_of_nodes)
{
    struct node *new_node, *last;// for new vertex
    int i, j, n, val;
    for(i = 0; i < no_of_nodes; i++)//
    {
        last = NULL;
        printf("\n Enter the number of neighbours of %d: ", i);
        scanf("%d", &n);// no of adjacent vertex
        for(j = 1; j <= n; j++)//
        {
            printf("\n Enter the neighbour %d of %d: ", j, i);
            scanf("%d", &val);
            new_node = (struct node *) malloc(sizeof(struct node));
            new_node -> vertex = val;
            new_node -> next = NULL;
            if (Adj[i] == NULL)//array is empty
                     Adj[i] = new_node;
            else
                     last -> next = new_node;
            last = new_node;
        }
}
}
void displayGraph (struct node *Adj[], int no_of_nodes)
{
    struct node *ptr;
    int i;
    for(i = 0; i < no_of_nodes; i++)
    {
        ptr = Adj[i];
        printf("\n The neighbours of node %d are:", i);
        while(ptr != NULL)
        {
            printf("\t%d", ptr -> vertex);
            ptr = ptr -> next;
        }
    }
}





