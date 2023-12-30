//assignment 4
//i was unable to take input and then output on command line. if i did that, the code was not functioning well.
//hence i gave input of all three mazes here and it works fine if i give input in int main
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_ROWS 100
#define MAX_COLS 100


//creating structure for the maze
struct maze{
    int r;
    int c;
};

//structure defining for each element of the maze
struct node{
    int data;
    struct node *next;
};


//structure defining the queue, used for the BFS search
struct queue{
    struct node  *front;
    struct node  *rear;
};


//structure for graph implementation using the adjacecny list, tries to store the maze contents in the graph
struct graph{
    struct node **adjacency_list;
};

//this part of the code tries to create a void function that adds edges between two nodes
void edgeCreation(struct graph *g, int src, int dest){
    struct node *new_node = (struct node* )malloc(sizeof(struct node));
    new_node -> data = dest;
    new_node -> next = g -> adjacency_list[src];
    g -> adjacency_list[src] = new_node;
}

//this function enqueues the elements in the queue for bfs traversal
void enqueue(struct queue *q, int data){
    struct node *new_node = (struct node* )malloc(sizeof(struct node));
    new_node -> data = data;
    new_node -> next = NULL;

    if(q -> front == NULL){
        q -> front = q -> rear = new_node;
    } 
    
    else{
        q -> rear -> next = new_node;
        q -> rear = new_node;
    }
}

//this function dequeues elements from queue, after bfs traverses the given element(here by element I refer to the cell of the maze bfs traverses)
int dequeue(struct queue *q){
    int data = q -> front -> data;
    struct node *temp = q -> front;

    if(q -> front == q -> rear){
        q -> front = q -> rear = NULL;
    } 
    
    else{
        q -> front = q -> front -> next;
    }

    free(temp);
    return data;
}

//bool function checks for empty queue or not
bool if_queue_is_Empty(struct queue *q){
    return q -> front == NULL;
}


//bool fucntion checks for all the only valid moves in the maze
bool is_it_a_valid_Move(char maze[MAX_ROWS][MAX_COLS], int rows, int cols, int r, int c){
    return r >= 0 && r < rows && c >= 0 && c < cols && maze[r][c] != '#';
}


//this void function prints the valid path after the bfs traversal 
void print_validPath(char maze[MAX_ROWS][MAX_COLS], struct maze path[MAX_ROWS][MAX_COLS], struct maze S, struct maze E){
    struct maze current = E;
    while(!(current.r == S.r && current.c == S.c)){
        maze[current.r][current.c] = '-';
        current = path[current.r][current.c];
    }

    for(int i = 0; i < MAX_ROWS; i++){
        for(int j = 0; j < MAX_COLS; j++){
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

//main part where functions are called
int main(){
    char maze[MAX_ROWS][MAX_COLS] = {

    //maze 1
        "##########",
        "#  S     #",
        "# ### ## #",
        "# #    # #",
        "# #  # # #",
        "# ## #####",
        "# #      #",
        "# # #  # #",
        "##### ####",
        "#   #    #",
        "# #    #E#",
        "##########"


    //maze 2
    //    "#######################################",
    //    "#E                    #     #         #",
    //    "####### ############# ##### ######### #",
    //    "#     #   #                           #",
    //    "# ### ### ### #########################",
    //    "#     #   #   #   #                   #",
    //    "### # # # # # # # # ### ###############",
    //    "# # #   #   #   #   # # #   # #       #",
    //    "# ################### # # #   ####### #",
    //    "# #   #   # # #       # # ###         #",
    //    "# # # # # # # # ####### #   ######### #",
    //    "# # # # # # #   #       ### #         #",
    //    "#   # # # # # # # #######   # #########",
    //    "# # #   #   # # # #       # #         #",
    //    "# # ######### # # # ####### # ####### #",
    //    "#S#                 #       #         #",
    //    "#######################################"
   

    //maze 3
    //    "########",
    //    "#     S#",
    //    "# ###  #",
    //    "#      #",
    //    "# #  # #",
    //    "# ######",
    //    "# ###  #",
    //    "##### ##",
    //    "#   #  #",
    //    "#   # E#",
    //    "########"
 
   
   
   
   
    };

    int rows = 12;
    int cols = 10;

    struct maze S, E;

    for(int i = 0; i < MAX_ROWS; i++){
        for(int j = 0; j < MAX_COLS; j++){
            if(maze[i][j] == 'S'){
                S.r = i;
                S.c = j;
            } 
            
            else if(maze[i][j] == 'E'){
                E.r = i;
                E.c = j;
            }
        }
    }

    struct queue q = { .front = NULL, .rear = NULL };

    bool visited[MAX_ROWS][MAX_COLS] = { false };
    struct maze path[MAX_ROWS][MAX_COLS];

    struct graph g;
    g.adjacency_list = (struct node**)malloc(rows * cols * sizeof(struct node*));
    for (int i = 0; i < rows * cols; i++) {
        g.adjacency_list[i] = NULL;
    }

//making the adjacecny list of the maze/graph that we are solving
    for(int i = 0 ; i < rows ; i++){
        for(int j = 0 ; j < cols ; j++){
            if(maze[i][j] != '#'){
                int current_index = i * cols + j;
                int moves_for_row[] = {-1, 1, 0, 0};
                int moves_for_col[] = {0, 0, -1, 1};

                for(int k = 0; k < 4; k++){
                    int new_row = i + moves_for_row[k];
                    int new_col = j + moves_for_col[k];
                    if(is_it_a_valid_Move(maze, rows, cols, new_row, new_col) && maze[new_row][new_col] != '#'){
                        int neighbor_index = new_row * cols + new_col;
                        edgeCreation(&g, current_index, neighbor_index);
                    }
                }
            }
        }
    }

    enqueue(&q, S.r * cols + S.c);
    visited[S.r][S.c] = true;

    while(!if_queue_is_Empty(&q)){
        int current_index = dequeue(&q);
        struct maze current = { current_index / cols, current_index % cols };

        if(current.r == E.r && current.c == E.c){
            printf("Path found\n");
            printf("The path is as follows:\n");
            print_validPath(maze, path, S, E);
            return 0;
        }

        struct node *neighbor = g.adjacency_list[current_index];
        while(neighbor != NULL){
            int neighbor_index = neighbor -> data;
            int new_row = neighbor_index / cols;
            int new_col = neighbor_index % cols;

            if(!visited[new_row][new_col]){
                struct maze neighbor_point = { new_row, new_col };
                enqueue(&q, neighbor_index);
                visited[new_row][new_col] = true;
                path[new_row][new_col] = current;
            }

            neighbor = neighbor -> next;
        }
    }

    printf("No path has been found!\n");

    free(g.adjacency_list);

    return 0;
}
