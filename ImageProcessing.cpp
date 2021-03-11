#include <bits/stdc++.h>
using namespace std;

void copyImage(int** v, int** c, int width, int height)
{
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            int temp = v[i][j]; //grab value of original
            c[i][j] = temp; // place value in copy matrix
            // this is mostly used in median filter since we can make a copy of the image and store it for later
        }
    }
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

void medianFilter(int** v, int** c, int width, int height){

    copyImage(v, c, width, height); // create copy matrix to hold data

    for (int i = 4; i < height - 4; i++){ // start at the 5th row from the top and stop at the 5th from the bottom

        for (int j = 4; j < width -4; j++){ // start at the 5th column from the left and stop at the 5th from the right

            int values [81]; // create an array of 81 values to be used in the filter
            for (int y = -4; y < 5; y++) { // index for the height

                for (int x = -4; x < 5; x++) { // index for the width
                    c[i + y][j + x] = values[(x) + (y * 9)]; // set indexed value into values array
                }
            }
            // values array should now have the 81 values for the filter
            sort(values,values + 81);
            v[i][j] = values[40]; // put the median value into the original matrix
        }

    }

}
