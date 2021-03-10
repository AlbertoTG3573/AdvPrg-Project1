#ifndef PROJECT_1_IMAGEPROCESSING_H
#define PROJECT_1_IMAGEPROCESSING_H

//copy image function
void copyImage();

//flip horizontal function
void flipHorizontal(int** v, width, height);

//flip vertical function; vertical is spelled incorrectly on the pdf so it is copied from there
void flipVeritcal(int** v, width, height);

//median filter function
void mediamFilter(int** v, width, height);

#endif //PROJECT_1_IMAGEPROCESSING_H
