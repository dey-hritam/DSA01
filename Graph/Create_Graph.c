#include <stdio.h>
#include <stdlib.h>
int NoOfVertices;
struct node
{
    int data;
    struct node *link;
};
void readingGraph(struct node *Adj[])
{
    struct node *newnode;
    int k, data;
    for (int i = 0; i < NoOfVertices; i++)
    {
        struct node *rear = NULL;
        printf("Enter the number of adjacency vertices of %d:", i);
        scanf("%d", &k);
        for (int j = 1; j <= k; j++)
        {
            newnode = (struct node *)malloc(sizeof(struct node));
            printf("Enter the data for %d neighbour of %d:", j, i);
            scanf("%d", &data);
            newnode->data = data;
            newnode->link = NULL;
            if (Adj[i] == NULL)
            {
                Adj[i] = newnode;
            }
            else
            {
                rear->link = newnode;
            }
            rear = newnode;
        }
    }
}
void printgraph(struct node *Adj[])
{
    struct node *temp;
    for (int i = 0; i < NoOfVertices; i++)
    {
        temp = Adj[i];
        printf("\nthe adjaceny vertices to %d->", i);
        while (temp != NULL)
        {
            printf("%d->", temp->data);
            temp = temp->link;
        }
        printf("END");
    }
}
int main()
{
    printf("Enter the number of vertices in the graph:");
    scanf("%d", &NoOfVertices);
    struct node *Adj[NoOfVertices];
    for (int i = 0; i < NoOfVertices; i++)
    {
        Adj[i] = NULL;
    }
    readingGraph(Adj);
    printgraph(Adj);
}
