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

void printOutWorld(int);
int countNeighbours(int, int);
void initializeWorld();
void procesGeneration();
void sleep(unsigned int);
int getUserInput();

int main()
{
    srand(time(NULL));
    int gen;
    printf("Welcome to GAME OF LIFE\n");
    printf("How many generations do you want to see: ");
    scanf("%d", &gen);
    printf("The program will run %d generations\n", gen);
    sleep(300000);
    printf("STARTING GAME....");
    sleep(300000);

    initializeWorld();

    for(int i = 0; i<=gen;i++){
        procesGeneration();
        printOutWorld(i);
        sleep(1000000);
    }


    return 0;
};

int getUserInput(){
    static int g;
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
    int k;
    for(int i = 0; i< ROWS; i++)
    {
        for(int j = 0; j<COLS;j++)
        {
            if((j==0)||(i==0)||(i==ROWS-1)||(j==COLS-1) ){
               world[i][j] = -1;
               continue;
            }
            else{
            k = rand()%3;
            if (k == 0){world[i][j] = 1;}
            }
        }
    }
};

// ************************************************
void procesGeneration(){
    int neighbours,i,j;
    for(i = 0; i<ROWS;i++)
    {
        for(j = 0; j <COLS; j++){

            if(world[i][j] == -1) continue;
            neighbours = countNeighbours(i,j);
            if(world[i][j] == 1 && (neighbours <2 || neighbours >3) )
                tempWorld[i][j] = 0;
            else if(world[i][j] == 0 && neighbours == 3)
                tempWorld[i][j] = 1;

        }

    }

    population = 0;
    for(i = 0; i<ROWS;i++)
    {
        for(j = 0; j <COLS; j++){
            if (world[i][j] == -1) continue;
            if (tempWorld[i][j] == 1){population++;}
            world[i][j] = tempWorld[i][j];
        }
    }
};


// ************************************************
void printOutWorld(int g){
    system("clear");
    printf("GAME OF LIFE\a ... generation %d\n", g);
    int n;
    for(int i = 0; i< ROWS; i++){
        for(int j = 0; j<COLS;j++){
            if(world[i][j]==-1) printf("X");
            else if(world[i][j]==1){
                printf("0",n);
            }
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
	for(j=y-1;j<y+2;j++){
        for(i=x-1;i<x+2;i++){
            if (i==x && j==y) continue;
            if ((world[i][j] != -1) && (world[i][j]==1)) n+=1;
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
