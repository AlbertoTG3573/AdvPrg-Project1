#include <iostream>
#include "PGM.h"
#include "ImageProcessing.h"

using namespace std;
// Group: Alberto & Emma
int main()
{
    // Path to the file
    // If image is in the same directory as executable
    //string fileName = "lena.pgm";
    bool cont;
    char yesno = 'n';
    const unsigned int COPY = 0;
    const unsigned int FLIPVERT = 1;
    const unsigned int FLIPHOR = 2;
    const unsigned int MEDIAN = 3;
    unsigned int choice = 0;
    string fileInput;
    string fileName;
    string outputName;

    do {
        cout << "Enter Original File Name: ";
        cin >> fileInput;
        fileName = "..\\test_images\\" + fileInput;
        //Open File set information
        if (openPGM(fileName)) {
            // Get Image Size Information
            cout << "\nFile Successfully Opened!" << endl;
            int width = getPGMWidth();
            int height = getPGMHeight();

            // Declare and allocate memory for data
            int **original;
            original = new int *[height];

            for (int i = 0; i < height; i++) {
                original[i] = new int[width];
            }

            // Get the data
            getPGMData(original);

            // Declare and allocate memory for copy data
            int **copy;
            copy = new int *[height];

            for (int i = 0; i < height; i++) {
                copy[i] = new int[width];
            }
            //get operation int from console
            cout << "[0] Copy Image\n[1] Flip Vertical\n[2] Flip Horizontal\n[3] Median Filter\nEnter Selection: ";
            cin >> choice;
            cout << "\nEnter Save File Name: ";
            cin >> fileInput;
            outputName = "..\\processed_images\\" + fileInput;
            cout << "\nPreforming Operation..." << endl;

            // choose operation based on choice
            switch(choice){
                case COPY:
                    copyImage(original,width,height);
                    break;
                case FLIPVERT:
                    flipVertical(original,width,height);
                    break;
                case FLIPHOR:
                    flipHorizontal(original,width,height);
                    break;
                case MEDIAN:
                    medianFilter(original,width,height);
                    break;
            }
            cout << "Writing out the File...";

            // Write back out the same image
            if (!writePGM(outputName, original)) {
                cout << "\nFailed to write out file" << endl;
                cont = false;
            }
            cout << "Cleaning up now!\n";
            // Clean up memory
            for (int i = 0; i < height; i++) {
                delete[] original[i];
            }
            delete original;
            // prompt for continue
            cout << "Clean-up finished.\nPreform another operation [y/n]? ";

            cin >> yesno;
            // check if yesno is equal to no
            if ((yesno != 'n') && (yesno != 'N')){
                cont = true;
            }
            else{
                cont = false;
            }

        } else {
            cout << "\nCannot open file " << fileName << endl;
            cont = false;
        }
    }while(cont);
    return 0;
}
