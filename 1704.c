bool checkVowel(char c)
{
    return ( c == 'a'||c == 'e'||c ==  'i'||c ==  'o'||c ==  'u'||c ==  'A'||c ==  'E'||c ==  'I'||c == 'O'||c == 'U' );
}
bool halvesAreAlike(char * s){

    int a_count = 0;
    int b_count = 0;
    for(int i = 0;i<strlen(s);i++)
    {
        if(checkVowel(s[i]))
        {
            if(i<(strlen(s)/2))
                a_count++;
            else
               b_count++; 
        }
    }
    return(a_count == b_count );
}
