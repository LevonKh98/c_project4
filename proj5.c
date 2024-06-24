#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Declare global variables, including dynamic array to store sequence of traversed tracks
int *sequence = NULL;
int numSequences;

/*********************************************************/
void option1() {
	// prompt for the sequence size
	printf("Enter size of sequence: ");
	scanf("%d", &numSequences);
	
	// allocate memory for the sequence of traversed tracks
    sequence = (int *)malloc(numSequences * sizeof(int));
  return;
} // "OPTION #1"


/*********************************************************/
void option2() {
	// declare local variables	
	int distance;
	
	// prompt for starting track, store in index 0
	printf("Enter starting track: ");
	scanf("%d", &sequence[0]);
	
	// prompt for sequence of tracks to seek, store in index 1 to "sequence size-1"
	printf("Enter sequence of tracks to seek: ");
	
	for(int i = 1; i < numSequences; i++)
	{
	    scanf("%d", &sequence[i]);
	}
	
	// calculate total distance of traversed tracks
	distance = sequence[0];
	for(int i = 1; i < numSequences; i++)
	{
	    distance += abs(sequence[i-1] - sequence[i]);
	}
	
	// print sequence of traversal
	printf("Traversed sequence: ");
	for(int i = 0; i < numSequences; i++)
	{
	    printf("%d ", sequence[i]);
	}
	
	// print total distance of tracks traversed
	printf("\nThe distance of the traversed tracks is: %d\n\n", distance);
	
	return;
} // "OPTION #2"	


/*********************************************************/
void option3() {
    // declare local variables	
	int distance;
	int currentTrack;
	int *done = (int *)calloc(numSequences , sizeof(int));
	int numNotTraversed = numSequences;
	int shortestDistance;
	int shortestDistanceIndex;
	
	// prompt for starting track, store in index 0
	printf("Enter starting track: ");
	scanf("%d", &sequence[0]);
	
	// prompt for sequence of tracks to seek, store in index 1 to "sequence size-1"
	printf("Enter sequence of tracks to seek: ");
	
	for(int i = 1; i < numSequences; i++)
	{
	    scanf("%d", &sequence[i]);
	}
	
	// initialize current track and distance traversed to starting track  
	currentTrack = sequence[0];
	distance = sequence[0];
	
	// begin printing sequence of traversal 
	printf("Traversed sequence: ");
	printf("%d ", sequence[0]);
	done[0] = 1;
	numNotTraversed--;
	
	// until every track is traversed
	while(numNotTraversed > 0)
    {
	    // initilize shortest distance to INT_MAX
	    shortestDistance = INT_MAX;
	    
		// for each track in sequence
		for(int i = 0; i < numSequences; i++)
		{
		    // if not already traversed
		    if(done[i] != 1)
		    {
		        //if distance to traverse is shorter than current shortest distance
		        if(abs(sequence[i] - currentTrack) < shortestDistance)
		        {
		            // set current shortest distance and index of the track	w/ shortest distance
		            shortestDistance = abs(sequence[i] - currentTrack);
		            shortestDistanceIndex = i;
		        }
		    }
		}
			
		// set "done" value for track w/shortest distance to 1 (mark as traversed)
		done[shortestDistanceIndex] = 1;
		
		// decrement number of tracks that have been traversed
		numNotTraversed--;
		
		// update total distance traversed
		distance += shortestDistance;
		
		//set current track to new position, print position
		currentTrack = sequence[shortestDistanceIndex];
		printf("%d ", currentTrack);
	}
		
  	// print total distance traversed
	printf("\nThe distance of the traversed tracks is: %d\n\n", distance);
  	
  	free(done);
	return;

} // "OPTION #3" 


/*********************************************************/
void option4() {
	// declare local variables
	int direction;
	int distance;
	int currentTrack;
	int *done = (int *)calloc(numSequences , sizeof(int));
	int numNotTraversed = numSequences;
	int shortestDistance;
	int shortestDistanceIndex;
	int atLeastOne;
	
    // prompt for starting track, store in index 0
	printf("Enter starting track: ");
	scanf("%d", &sequence[0]);
	
	// prompt for sequence of tracks to seek, store in index 1 to "sequence size-1"
	printf("Enter sequence of tracks to seek: ");
	
	for(int i = 1; i < numSequences; i++)
	{
	    scanf("%d", &sequence[i]);
	}
	
    //prompt for initial direction (0=descreasing, 1=increasing)
    printf("Enter initial direction: (0=decreasing, 1=increasing): ");
    scanf("%d", &direction);
    
	// initialize current track and distance traversed to starting track
	currentTrack = sequence[0];
	distance = sequence[0];
	
	// begin printing sequence of traversal 
	printf("Traversed sequence: ");
	printf("%d ", sequence[0]);
	done[0] = 1;
	numNotTraversed--;
	
	// until every track is traversed
	while(numNotTraversed > 0)
	{
	    // initilize shortest distance to INT_MAX
	    shortestDistance = INT_MAX;
	    atLeastOne = 0;
	    
		// for each track in sequence
		for(int i = 0; i < numSequences; i++)
		{
			// if not already traversed
			if(done[i] != 1)
			{
			    //if distance to traverse is shorter than current shortest distance in the current direction
			    if(direction == 1)
			    {
			        if((abs(sequence[i] - currentTrack) < shortestDistance) && sequence[i] > currentTrack)
					{
					    // set current shortest distance and index of the track	w/ shortest distance
					    shortestDistance = abs(sequence[i] - currentTrack);
					    shortestDistanceIndex = i;
                        // set flag that at least one track was traversed
                        atLeastOne = 1;
					}
			    }
			    else
			    {
			        if((abs(sequence[i] - currentTrack) < shortestDistance) && sequence[i] < currentTrack)
					{
					    // set current shortest distance and index of the track	w/ shortest distance
					    shortestDistance = abs(sequence[i] - currentTrack);
					    shortestDistanceIndex = i;
                        // set flag that at least one track was traversed
                        atLeastOne = 1;
					}
			    }
			}
				
		}
		
		// if at least one track was traversed
		if(atLeastOne == 1)
		{
		    // set "done" value for track w/shortest distance to 1 (mark as traversed)
		    done[shortestDistanceIndex] = 1;
		    
			// decrement number of traversed tracks
			numNotTraversed--;
			
			// update total distance traversed
			distance += shortestDistance;
			
			//set current track to new position, print position
			currentTrack = sequence[shortestDistanceIndex];
		    printf("%d ", currentTrack);
		}
    	else
    	{
    	    if(direction == 1)
    	    {
    	        direction = 0;
    	    }
    	    else
    	    {
    	        direction = 1;
    	    }
    	}
		
	}
		
 	// print total distance traversed
	printf("\nThe distance of the traversed tracks is: %d\n\n", distance);
 	
 	free(done);
 	  	
	return;
} // "OPTION #4"


/*********************************************************/
void option5() {
	// declare local variables
	int distance;
	int currentTrack;
	int *done = (int *)calloc(numSequences , sizeof(int));
	int numNotTraversed = numSequences;
	int shortestDistance;
	int shortestDistanceIndex;
	int atLeastOne;
	int subtract = 0;
	
	// prompt for starting track, store in index 0
	printf("Enter starting track: ");
	scanf("%d", &sequence[0]);
	
	// prompt for sequence of tracks to seek, store in index 1 to "sequence size-1"
	printf("Enter sequence of tracks to seek: ");
	
	for(int i = 1; i < numSequences; i++)
	{
	    scanf("%d", &sequence[i]);
	}
	
	// initialize current track and number traversed to starting track
	currentTrack = sequence[0];
	distance = sequence[0];
	
	// begin printing sequence of traversal 
	printf("Traversed sequence: ");
	printf("%d ", sequence[0]);
	done[0] = 1;
	numNotTraversed--;
	
	// until every track is traversed
	while(numNotTraversed > 0)
	{
		// initilize shortest distance to INT_MAX
	    shortestDistance = INT_MAX;
	    atLeastOne = 0;
	    
		// for each track in sequence
		for(int i = 0; i < numSequences; i++)
		{
			// if not already traversed
			if(done[i] != 1)
			{
			    //if distance to traverse is shorter than current shortest distance and a positive value (only increasing direction)
			    if((abs(sequence[i] - currentTrack) < shortestDistance) && sequence[i] > currentTrack)
				{
				    // set current shortest distance and index of the track	w/ shortest distance
				    shortestDistance = abs(sequence[i] - currentTrack);
				    shortestDistanceIndex = i;
                    // set flag that at least one track was traversed
                    atLeastOne = 1;
                }
			}
				
		}
		
		// if at least one track was traversed
		if(atLeastOne == 1)
		{
		    // set "done" value for track w/shortest distance to 1 (mark as traversed)
		    done[shortestDistanceIndex] = 1;
		    
			// decrement number of traversed tracks
			numNotTraversed--;
			
			if(subtract == 1)
		    {
		        subtract = 0; 
		        distance -= shortestDistance;
		    }
		    else
		    {
		        // update total distance traversed
			    distance += shortestDistance;
		    }
			
			//set current track to new position, print position
			currentTrack = sequence[shortestDistanceIndex];
		    printf("%d ", currentTrack);
		}
		else
		{
		    // update total distance by current track (adds remaining distance before going back to 0)
		    distance+= currentTrack;
		    currentTrack = 0;
		    subtract = 1;
		    			// reset current track to 0 (loop back around)
			// set "end reached" flag to 1
		}
			
			// if largest track was reached
				// update total distance traversed by derementing by distance to track (subtracts distance from 0 to track)
				// reset "largest track" flag
			// else
				// update total distance traversed by distance to track
			//set current track to new position, print position
		
			

	}

 	// print total distance traversed
	printf("\nThe distance of the traversed tracks is: %d\n\n", distance);
 	
 	free(done);
 	
	return;    
} // "OPTION #5


/***************************************************************/
void option6() {
	// if sequence is not NULL, free sequence
	if(sequence != NULL)
	    free(sequence);
	return;
} // "OPTION #6


/***************************************************************/
int main() {
	// declare local vars
    int choice = -1;
    
	while(choice != 6)
    {
        /* print menu of options */

        printf("Disk scheduling\n");
        printf("---------------\n");
        printf("1) Enter parameters\n");
        printf("2) Calculate distance to traverse tracks using FIFO\n");
        printf("3) Calculate distance to traverse tracks using SSTF\n");
        printf("4) Calculate distance to traverse tracks using Scan\n");
        printf("5) Calculate distance to traverse tracks using C-Scan\n");
        printf("6) Quit program and free memory\n");
        
        // prompt for menu selection 
        printf("\nEnter selection: ");
        scanf("%d", &choice);
        
        printf("\n");
        
        /* call appropriate procedure based on choice--use switch statement or series of if, else if, else statements */
        switch(choice)
        {
            case 1: 
                option1();
                break;
            case 2:
                option2();
                break;
            case 3:
                option3();
                break;
            case 4:
                option4();
                break;
            case 5:
                option5();
                break;
            case 6:
                option6();
        }
        
    }
    
    
   printf("\nQuitting program...");
   
   return 1; // indicates success
} // main	

