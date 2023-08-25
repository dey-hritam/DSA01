#include <stdio.h>
#include <stdlib.h>
int NoOfVertices;
struct Node
{
    int data;
    struct Node *link;
};

void readgraph(struct Node *Adj[])
{
    struct Node *newnode;
    int k, data;
    for (int i = 0; i < NoOfVertices; i++)
    {
        struct Node *rare = NULL;
        printf("How much number of vertices you want to adjacent at %d:", i);
        scanf("%d", &k);
        for (int j = 1; j <= k; j++)
        {
            newnode = (struct Node *)malloc(sizeof(struct Node));
            printf("Enter the data for the %d vertices of %d:", j, i);
            scanf("%d", &data);
            newnode->data = data;
            newnode->link = NULL;
            if (Adj[i] == NULL)
            {
                Adj[i] = newnode;
            }
            else
            {
                rare->link = newnode;
            }
            rare = newnode;
        }
    }
}
void printgraph(struct Node *Adj[])
{
    struct Node *temp;
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
void Dfs(struct Node *Adj[], int start, int visited[])
{
    visited[start] = 1;
    printf("%d  \t", start);
    struct Node *ptr;
    ptr = Adj[start];
    while (ptr != NULL)
    {
        if (visited[ptr->data] == 0)
        {
            Dfs(Adj, ptr->data, visited);
        }
        ptr = ptr->link;
    }
}
int main()
{
    int ch, start, visited[NoOfVertices];
    printf("Enter the number of vertices:");
    scanf("%d", &NoOfVertices);
    struct Node *Adj[NoOfVertices];
    for (int i = 0; i < NoOfVertices; i++)
    {
        Adj[i] = NULL;
    }
    readgraph(Adj);
    do
    {
        printf("\n1.Enter 1 for the Dfs.");
        printf("\n2.Enter 2 for the Adjacency List.");
        printf("\n3.Enter 3 for the Exit.");
        printf("\nEnter the choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the vertex from which you want to start?");
            scanf("%d", &start);
            for (int i = 0; i < NoOfVertices; i++)
            {
                visited[i] = 0;
            }
            Dfs(Adj, start, visited);
            break;
        case 2:
            printgraph(Adj);
        case 3:
            break;
        default:
            break;
        }
    } while (ch != 4);
}
