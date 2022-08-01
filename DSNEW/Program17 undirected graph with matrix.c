#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define max 20
#define initial 1
#define waiting 2
#define visit 3

int adj[max][max], visited[max], visited1[max], q[max];
int n, max_edges;
int queue[max], front = -1, rear = -1;
int state[max];

void insert_edge();
void create_graph();
void display();
void adjVertex();
void BFS();
void dfs();
int delete_queue();
int isEmpty_queue();
void insert_queue(int vertex);

void main()
{
    int choice, i;
    int node, origin, destin;

    while (choice != 7)
    {
        printf("\n***************MENU***********************\n");
        printf("1.Create an undirected graph.\n");
        printf("2.Insert an edge to the existing graph.\n");
        printf("3.Display the graph\n");
        printf("4.List all vertices that are adjacent to a specified vertex.\n");
        printf("5.Print out vertices using depth first search\n");
        printf("6.Print out vertices using breadth first search\n");
        printf("7.Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            create_graph();
            break;
        case 2:
            insert_edge();
            break;
        case 3:
            display();
            break;
        case 4:
            adjVertex();
            break;
        case 5:
            for (i = 0; i < n; i++)
                visited[i] = 0;
            dfs(0);
            break;
        case 6:
            for (i = 0; i < n; i++)
                state[i] = initial;

            printf("Enter Start Vertex for BFS: \n");
            scanf("%d", &i);
            printf("BFS traversal for the given graph is: \n");
            BFS(i);
        case 7:
            exit(0);
        default:
            printf("Wrong choice\n");
            break;
        }
    }
}

void create_graph()
{
    int i, origin, destin;
    printf("\n.....Creating an undirected graph.....\n");
    printf("\n Enter number of nodes : ");
    scanf("%d", &n);
    max_edges = n * (n - 1);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            adj[i][j] = 0;
    printf("\n Start entering pair of vertices for each edge. \n Press ( 0 0 ) to quit.\n");
    for (i = 1; i <= max_edges; i++)
    {
        printf("\n Enter edge %d (x, y): ", i);
        scanf("%d %d", &origin, &destin);
        if ((origin == 0) && (destin == 0))
            break;
        if (origin > n || destin > n || origin < 0 || destin < 0)
        {
            printf("\n Invalid edge!!!\n");
            i--;
        }
        else
        {
            adj[origin][destin] = 1;
            adj[destin][origin] = 1;
        }
    }
}

void display()
{
    int i, j;
    printf("\n The adjacency matrix of the implemented graph is: \n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            printf("%4d", adj[i][j]);
        printf("\n");
    }
}

void insert_edge()
{
    int i, origin, destin;

    printf("\n Enter the  edge (x,y) to be inserted:\n");
    scanf("%d %d", &origin, &destin);

    adj[origin][destin] = 1;
    adj[destin][origin] = 1;
}

void adjVertex()
{
    int v;

    printf("\n Enter the vertex: ");
    scanf("%d", &v);

    printf("\n List of vertices that are adjacent to your specified vertex: \n");
    for (int i = 0; i < n; i++)
    {
        if (adj[v][i] == 1)
            printf("\n %d", i);
    }
}

void dfs(int i)
{
    int j;

    printf("\n%d", i);

    visited[i] = 1;

    for (j = 0; j < n; j++)
    {
        //printf("\n adj [%d] [%d] %d", i, j, adj[i][j]);
        if (visited[j] == 0 && adj[i][j] == 1)
        {
            dfs(j);
        }
    }
}

void BFS(int v)
{
    int i;

	insert_queue(v);
	state[v] = waiting;

	while(!isEmpty_queue())
		{
		v = delete_queue();
		printf("%d ",v);
		state[v] = visit;

		for(i=0; i<n; i++)
		{
			if(adj[v][i] == 1 && state[i] == initial)
			{
				insert_queue(i);
				state[i] = waiting;
			}
		}
	}
	printf("\n");
}
void insert_queue(int vertex)
{
	if(rear == max-1)
		printf("Queue Overflow\n");
	else
	{
		if(front == -1)
			front = 0;
		rear = rear+1;
		queue[rear] = vertex ;; 
	}
}
 
int isEmpty_queue()
{
	if(front == -1 || front > rear){
		return 1;
    }
	else
		return 0;
}
 
int delete_queue()
{
	int delete_item;
	if(!isEmpty_queue())
	{
		delete_item = queue[front];
	    front = front+1;	 
	}
	return delete_item;
	
}