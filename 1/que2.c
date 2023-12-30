#include<stdio.h>
#include<stdlib.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include<unistd.h>
#include <ctype.h>
char ques[100][100];
struct node{
	int x;
	int y;
	struct node * next;
};

struct node * head;
struct node * one;
struct node * two;
struct node * three;
struct node * four;
struct node * play;
struct node * end;
struct node * prin;
int row=0;
int column=0;

void input(){
	char path[512];
	printf("Enter The Absolute Path Of The Input File :\n");
	scanf("%s", path);
	FILE* file;
	file = fopen(path, "r");
	if(file ==  NULL) { printf("NOT Found\n"); exit(0); }
	//file = fopen("maze1.txt", "r");
	char buffer[512]; 
	int ihi= 0;
	while (fgets(buffer, sizeof(buffer), file) != NULL) {

		for (  ihi = 0; buffer[ihi] != '\0' && buffer[ihi] != '\n'; ihi++) {
			if (!isprint(buffer[ihi])) continue;
			ques[row][column] = buffer[ihi];
			column++;
		}
		ques[row][column] = '\0'; 
		row++;
		column = 0;
	}
	column = ihi;
	fclose(file);
	return ;
}

void print(){
	for(int i = 0 ; i < row ; i++){
		for(int j = 0 ; j < column ; j++){
			printf("%c ",ques[i][j]);
		}puts("");        
	}
}

int dist( int ax, int wy ){
	return ( (end -> y - ax) + (end-> x - wy  ) );
}

void myfun(){

	end = malloc(sizeof(struct node));
	end -> x = -1 ; end -> y = -1;
	head = malloc(sizeof(struct node));
	head -> x = -1 ; head -> y = -1;
	for(int i = 0 ;  i < row ; i++ ){
		for(int j = 0 ; j < column ; j ++){
			if(ques[i][j] == 'S'){ head -> x = i ; head -> y = j;}
			//	else {printf("head not found\n"); exit(0);	}
			if(ques[i][j] == 'E'){ end -> x = i ; end -> y = j;}
			//	else {printf("end not found\n"); exit(0);	}
		}}
	if(end -> x == -1  ) {printf("end not found\n"); exit(0);} 
	if(head -> x == -1  ) {printf("head not found\n"); exit(0);}
	printf("%d %d %d %d" , head ->x,head->y,end->x,end->y);


	int a  = 0;
	int b = 0;
	int c;
	int move;
	puts("");

	one = head;
	play = head;
	int runs = 0;
	while(one != NULL ){runs++;
		if(runs == 500 )  { printf("End Not Found\n"); exit(0); }
		if( one == NULL ) { printf("End Not Found\n"); exit(0); }
		//  print();
		prin = one;
		while( prin->next !=NULL && 0 ){
			printf(" %d %d ," ,prin->x,prin->y);
			prin = prin->next;
		}
		//      puts("");

		move = 0;
		a = one -> x;
		b = one -> y;
		while( ques[a][b] == '.' && 0 ) {
			two = one;
			one = one->next;
			free(two);
			a = one -> x;
			b = one -> y;
		}
		ques[a][b]='.';
		//printf("%d %d\t",a,b);

		if( ques[a][b-1] != '#' && ques[a][b-1] != '.' ){
			//     ques[a][b-1] = '.';
			if( ques[a][b-1] == 'E' ) break;
			if( dist(a,b-1) <= dist(a,b) ){ 
				two = malloc(sizeof(struct node));
				two -> x = a;
				two -> y = b-1;
				two->next = one;
				one = two;
				move = 1;
			}
			else if( dist(a,b-1) > dist(a,b) ){
				//printf("left");
				three = one->next;
				//      printf("ad");
				two = malloc(sizeof(struct node));
				two -> x = a;
				two -> y = b-1;
				one->next = two;
				two->next= three;

			}

		}



		if( ques[a-1][b] != '#' && ques[a-1][b] != '.'){
			//   printf("left");
			if( ques[a-1][b] == 'E' ) break;
			if( dist(a-1,b) <= dist(a,b) ){ 
				ques[a-1][b] = '.';
				two = malloc(sizeof(struct node));
				two -> x = a-1;
				two -> y = b;
				two->next = one;
				one = two;
				move = 1;
			}
			else  if( dist(a-1,b) > dist(a,b) ){
				ques[a-1][b] = '.';
				three = one->next;

				two = malloc(sizeof(struct node));
				two -> x = a-1;
				two -> y = b;
				one->next = two;
				two->next= three;
			}

		}



		if( ques[a][b+1] != '#' && ques[a][b+1] != '.'){
			if( ques[a][b+1] == 'E' ) break;
			if( dist(a,b+1) <= dist(a,b) ){ 
				//        ques[a][b+1] = '.';
				two = malloc(sizeof(struct node));
				two -> x = a;
				two -> y = b+1;
				two->next = one;
				one = two;
				move = 1;
			}
			else if( dist(a,b+1) > dist(a,b+1) ){
				//       ques[a][b+1] = '.';
				three = one->next;

				two = malloc(sizeof(struct node));
				two -> x = a;
				two -> y = b+1;
				one->next = two;
				two->next= three;
			}

		}


		if( ques[a+1][b] != '#' && ques[a+1][b] != '.'){
			if( ques[a+1][b] == 'E' ) break;
			if( dist(a+1,b) <= dist(a,b) ){ 
				//    ques[a+1][b] = '.';
				two = malloc(sizeof(struct node));
				two -> x = a+1;
				two -> y = b;
				two->next = one;
				one = two;
				move = 1;
			}
			else if( dist(a+1,b) > dist(a,b) ){
				//       ques[a+1][b] = '.';
				three = one->next;

				two = malloc(sizeof(struct node));
				two -> x = a+1;
				two -> y = b;
				one->next = two;
				two->next= three;

			}

		}
		if( one == NULL ) { printf("End Not Found\n"); exit(0); }
		if( ques[a][b] == 'E' ) break;
		if( move == 1  ) continue;
		if( one -> next == NULL ) { printf("End Not Found"); exit(0); }
		one = one->next;


	}
}

int main(){

	input(); print(); 
	myfun();
	ques[head->x][head->y] = 'S';
	puts("");
	print();
}



