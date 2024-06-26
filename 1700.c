int countStudents(int* students, int studentsSize, int* sandwiches, int sandwichesSize){
    int n = studentsSize;
    int oneCn = 0, zeroCn = 0;
    for(int i = 0; i < n; i++){
        if(students[i] == 1)
            oneCn++;    
    }
    zeroCn = n - oneCn;
    for(int i = 0; i < n; i++){
        if(sandwiches[i] == 1){
            if(oneCn > 0)
                oneCn--;
            else
                return n - i;
        }
        else{
            if(zeroCn > 0)
                zeroCn--;
            else
                return n - i;
        }
    }   
    return 0;
}
