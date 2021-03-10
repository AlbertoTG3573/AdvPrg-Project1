void copyImage(int** v, int width, int height)
{
    //spits the same image out
}

//flip horizontal
void flipHorizontal(int** v, int width, int height)
{
    for(int i=0; i < height; i++)
    {
        for( int j = 0; j < width/2; j++)
        {
            int temp = v[i][j]; //set
            v[i][j] = v[i][width-j-1];
            v[i][width-j-1] = temp;
        }
    }
}

//flip vertical
void flipVertical(int** v, int width, int height)
{
    for(int i=0; i < height/2; i++)
    {
        for( int j = 0; j < width; j++)
        {
            int temp = v[i][j]; //set
            v[i][j] = v[i][height-j-1];
            v[i][height-j-1] = temp;
        }
    }
}

void medianFilter(int**, int, int){

}
