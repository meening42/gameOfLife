#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 16
#define COLS 60


int population;
int populationMax;
int populationMin;

int tempWorld[ROWS][COLS];
int world[ROWS][COLS];

void printOutWorld();
int countNeighbours(int, int);
void initializeWorld();
void procesGeneration();
void sleep(unsigned int);
int getUserInput();

int main()
{

    srand(time(NULL));
    int generations = getUserInput();

    printf("1");
    for(int i = 0; i<=generations;i++){
        printf("2");
        initializeWorld();
        printf("3");
        procesGeneration();
        printf("4");
        printOutWorld();
        printf("5");
        sleep(300);
    }


    return 0;
};

int getUserInput(){
    int g;
    printf("Welcome to GAME OF LIFE\n");
    printf("How many generations do you want to see: ");
    scanf("%d", &g);
    //intf("The program will run %d generations", g);
    printf("STARTING GAME....");
    return g;
};
// ************************************************
void initializeWorld()
{
    for(int i = 0; i< ROWS; i++)
    {
        for(int j = 0; j<COLS;j++)
        {
            if((j==0)||(i==0)||(i==ROWS-1)||(j==COLS-1) ){
               world[i][j] = -1;
               continue;
            }
            else{ world[i][j] = rand() %3;}
        }
    }
};

// ************************************************
void procesGeneration(){
    int neighbours;
    for(int i = 0; i<ROWS;i++)
    {
        for(int j = 0; j <COLS; j++){
            if(world[i][j] == -1) continue;
            neighbours = countNeighbours(i,j);
            if(world[i][j] == 1 && (neighbours <2 || neighbours >3) )
                tempWorld[i][j] = 0;
            if(world[i][j] == 0 && neighbours == 3)
                tempWorld[i][j] = 1;

        }
    }

    population = 0;
    for(int i = 0; i<ROWS;i++)
    {
        for(int j = 0; j <COLS; j++){
            if (world[i][j] == -1) continue;
            if (tempWorld[i][j] == 1){
                population++;
                world[i][j] = tempWorld[i][j];
            }
        }
    }

};


// ************************************************
void printOutWorld(){
    system("clear");
    printf("GAME OF LIFE\n\a");
    for(int i = 0; i< ROWS; i++){
        for(int j = 0; j<COLS;j++){
            if(world[i][j]==-1) printf("X");
            else if(world[i][j]==1){printf("#");}
            else{printf(" ");}
        }
        printf("\n");
    }
};

// ************************************************
int countNeighbours(int x, int y){
    int i,j,n;
    n=0;
    /*
		[ ] [ ] [ ]
		[ ] [X] [ ]
		[ ] [ ] [ ]
	*/
	for(i=y-1;i<y+2;i++){
        for(j=x-1;j<x+2;j++){
            if (i==x && j==y) continue;
            if (world[i][j] == 1) n++;
        }
	}
	return n;
}
// ************************************************
void sleep(unsigned int mill)
{
	clock_t start = clock();
	while(clock() - start < mill) { }
}
