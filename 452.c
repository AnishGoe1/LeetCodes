// Function to compare two integer arrays (representing balloon intervals)
// based on their ending points (index 1).
// Handles ties in ending points by sorting based on starting points (index 0)
// in ascending order.
int cmpfunc( const void** p1,  const void** p2){
   int* arr1 = *(int**)p1; // Dereference pointers to access actual arrays
   int* arr2 = *(int**)p2;

  if(arr1[1] == arr2[1]){
      if(arr1[0] == arr2[0])
          return 0;
      else if(arr1[0] > arr2[0])
          return 1;
      else 
          return -1;      
  } 
  else{
      if(arr1[1] == arr2[1])
          return 0;
      else if(arr1[1] > arr2[1])
          return 1;
      else 
          return -1;
  }  
}

// Function to find the minimum number of arrows needed to burst all balloons
int findMinArrowShots(int** points, int pointsSize, int* pointsColSize){
    if (points == NULL || pointsSize == 0) { // Handle empty input
        return 0;
    }

    // Sort the array of balloon intervals based on ending points using qsort
    qsort(points, pointsSize, sizeof(int*), cmpfunc);

    int minArrows = 1;  // Minimum arrows needed (at least 1 for the first balloon)
    int currentEnd = points[0][1]; // Ending point of the current interval

    for (int i = 1; i < pointsSize; i++) {
        // If the current balloon's starting point is beyond the previous interval's
        // ending point, we need a new arrow. Update currentEnd for the new interval.
        if (points[i][0] > currentEnd) {
            minArrows++;
            currentEnd = points[i][1];
        }
    }

    return minArrows;
}

