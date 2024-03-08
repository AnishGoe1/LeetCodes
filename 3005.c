int maxFrequencyElements(int *n, int s) 
{
    int map[101] = { 0 }, max = 0, count = 0;
    
    while(s--) map[*n++]++;

    for(int i = 0; i < 101; i++)
    {
        if(map[i] == max)
        {
            count += map[i];
        }
        else if(map[i] > max)
        {
            max = map[i];
            count = map[i];
        }
    }
    
    return count;
}
