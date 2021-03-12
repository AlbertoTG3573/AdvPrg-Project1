#include "ImageProcessing.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void copyImage(int** v, int width, int height)
{
    //spits the same image out
}

//flip vertical
void flipHorizontal(int** v, int width, int height)
{
    for(int i=0; i < height; i++)
    {
        for( int j = 0; j < width/2; j++) //within bounds of picture
        {
            int temp = v[i][j]; //swap so that vertical coordinates remain the same while horizontal coordinates flip
            v[i][j] = v[i][width-j-1];
            v[i][width-j-1] = temp;
        }
    }
}

//flip vertical
void flipVertical(int** v, int width, int height)
{
    for(int i = 0; i < height/2; i++)
    {
        for( int j = 0; j < width; j++) //within bounds of picture
        {
            int temp = v[i][j]; //swap so attached to same horizontal coordinate but flipped vertically
            v[i][j] = v[height-i-1][j];
            v[height-i-1][j] = temp;
        }
    }
}

void medianFilter(int** matrix, int width, int height)
{
    int** temporary = new int*[height]; //assign temporary pointer to allocated memory for width
    for(int i = 0; i < height; i++)
    {
        temporary[i] = new int[width]; //allocate memory for width values
    }
    for(int i = 0; i < width; i++)
    {
        for(int j = 0; j < height; j++) //within bounds of width and width
        {
            if (i >= 4 && i < width - 4 && j >= 4 && j < height - 4) //creates a 9x9 box
            {
                vector<int> median; //assign vector
                for(int k = i - 4; k <= i + 4; k++)
                {
                    for(int l = j - 4; l <= j + 4; l++) //remains in 9x9 box
                    {
                        median.push_back(matrix[l][k]); //pushes matrix into the vector so it can be organized
                    }
                }
                sort(median.begin(), median.end()); //sorts vector into numeric order, smallest to largest
                int hold = median[median.size()/2]; //finds hold by splitting that into half
                temporary[j][i] = hold;
            }
            else
            {
                temporary[j][i] = matrix[j][i]; //if it is outside 9x9 box, leave as is
            }
        }
    }
    for(int x = 0; x < width; x++)
    {
        for(int y = 0; y < height; y++)
        {
            matrix[y][x] = temporary[y][x];
        }
    }
    for(int i = 0; i < height; i++)
    {
        delete[] temporary[i]; //deleting temp made earlier using same for loop
    }
    delete temporary; //deallocating memory so no memory leak
}

// end program