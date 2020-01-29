#include <stdio.h>

#define X_MAX   6
#define Y_MAX   6

/* These are called macros, do 'gcc -E maze.c | less' to see how they work 
 * They will be replaced before the code is compiled
 */
#define VISITED(x, y)      maze[x][y] = 2; 
#define CAN_VISIT(x, y)   (maze[x][y] == 0) 

/* MAKE SURE THE MATRIX MATCH X_ AND Y_MAX */
int maze[X_MAX][Y_MAX] = {{0, 0, 0, 0, 0, 1},
			  {1, 1, 1, 1, 0, 0},
			  {0, 0, 0, 0, 0, 0},
			  {0, 1, 1, 1, 1, 1},
			  {0, 0, 0, 0, 1, 1},
			  {1, 1, 1, 0, 0, 0}};


#define X_TARGET   (X_MAX - 1)
#define Y_TARGET   (Y_MAX - 1) 
#define X_START    0
#define Y_START    0
/* if you can find a path to given X_TARGET, Y_TARGET then 
 * findpath should  return 1. 
 * 0 otherwise
 */

int findpath(int x, int y) 
{
  
 if(x == X_TARGET && y == Y_TARGET && CAN_VISIT(x,y)) {
    printf("(%d,%d)\n",x,y );	  
    return 1; // we came to the point. Should display the path
 }
  
  VISITED(x,y); // make the problem small.
  // remove this and see what will happen
    
 


if(x==0&&y==0) //when path point at(0,0)
{


	if(CAN_VISIT(x, y+1))
	{
	printf("(%d,%d)\n",x,y ); 
	return findpath(x,y+1);	
	}

    else if(CAN_VISIT(x+1, y))
    {
    printf("(%d,%d)\n",x,y ); 
	return findpath(x+1,y);
	}
	
}

	
if(x==X_MAX-1&&y==Y_MAX-1) //when the path pont at end point
{
	if(CAN_VISIT(x-1, y))
	{
	printf("(%d,%d)\n",x,y ); 
	return findpath(x-1,y);	
	}

    else if(CAN_VISIT(x, y-1))
    {
    printf("(%d,%d)\n",x,y ); 
	return findpath(x,y-1);
	}
	
	
}	
	

 if(x==0&&y==(Y_MAX-1)) //when path at right uper corner
{

    if(CAN_VISIT(x, y-1))
    {
    printf("(%d,%d)\n",x,y ); 	
	return findpath(x,y-1);	
    }
    
    else if(CAN_VISIT(x+1, y))
    {
    printf("(%d,%d)\n",x,y ); 	
	return findpath(x+1,y);	
	}

}

if(x==(X_MAX-1)&&y==0) //when at the left corner
{

    if(CAN_VISIT(x-1, y))
    {
    printf("(%d,%d)\n",x,y ); 	
	return findpath(x-1,y);	
	}
    
    else if(CAN_VISIT(x, y+1))
    {
    printf("(%d,%d)\n",x,y ); 	
	return findpath(x,y+1);
	}
	
}

	
if(x==0) //when upper edge
{
    if(CAN_VISIT(x, y+1))
    {
    printf("(%d,%d)\n",x,y ); 	
	return findpath(x,y+1);	
	}

	else if(CAN_VISIT(x, y-1))
	{
	printf("(%d,%d)\n",x,y ); 	
	return findpath(x,y-1);	
	}

	else if(CAN_VISIT(x+1, y))
	{
	printf("(%d,%d)\n",x,y ); 	
	return findpath(x+1,y);	
	}


}

if(y==0) //when left edge
{
    if(CAN_VISIT(x, y+1))
    {
     printf("(%d,%d)\n",x,y ); 

	return findpath(x,y+1);	
	}

    else if(CAN_VISIT(x+1, y))
    {
    printf("(%d,%d)\n",x,y ); 	
	return findpath(x+1,y);	
	}

	else if(CAN_VISIT(x-1, y))
	{
	printf("(%d,%d)\n",x,y ); 	
	return findpath(x-1,y);	
	}

}	

if(x==X_MAX-1)
{

	if(CAN_VISIT(x, y+1))
	{
	printf("(%d,%d)\n",x,y ); 	
	return findpath(x,y+1);	
	}

	else if(CAN_VISIT(x, y-1))
	{
	printf("(%d,%d)\n",x,y ); 	
	return findpath(x,y-1);	
	}

	
	else if(CAN_VISIT(x-1, y))
	{
	printf("(%d,%d)\n",x,y ); 	
	return findpath(x-1,y);	
	}

}

if(y==Y_MAX -1)
{
   
    if(CAN_VISIT(x, y-1))
    {
    printf("(%d,%d)\n",x,y ); 	
	return findpath(x,y-1);	
	}

	else if(CAN_VISIT(x+1, y))
	{
	printf("(%d,%d)\n",x,y ); 	
	return findpath(x+1,y);	
	}

	else if(CAN_VISIT(x-1, y))
	{
	printf("(%d,%d)\n",x,y ); 	
	return findpath(x-1,y);	
	}	

}




    if(CAN_VISIT(x, y+1))
	{
	printf("(%d,%d)\n",x,y ); 	
	return findpath(x,y+1);	
	}

    if(CAN_VISIT(x, y-1))
	{
	printf("(%d,%d)\n",x,y ); 	
	return findpath(x,y-1);	
	}

	if(CAN_VISIT(x+1, y))
	{
     printf("(%d,%d)\n",x,y ); 
	return findpath(x+1,y);	
	}

	if(CAN_VISIT(x-1, y))
	{
	printf("(%d,%d)\n",x,y ); 	
	return findpath(x-1,y);	
	}
	







  return 0;  // tried all no path

}


int main()
{
  printf("%s", findpath(0, 0) == 1 ? "There is a path.\n" : "No path\n");
  
}
      
