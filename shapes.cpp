#include <iostream>
#include <cmath>
#include "bmplib.h"

using namespace std;

// global variable. bad style but ok for this lab
unsigned char image[SIZE][SIZE];

// Fill in this function:
void draw_rectangle(int top, int left, int height, int width) {

    for(int i = top; i < top+height; i++){
        if(i >= 0 & i <= 255){
            if(left >= 0 & left <= 255){
                image[i][left] = 0;
            }
        }
    }
    for(int j = left; j < left+width; j++){

        if(top >= 0 & top <= 255){
            if(j >= 0 & j <= 255){
                image[top][j] = 0;
            }
        }
    }
    for(int k = top; k < top+height; k++){
        if(k >= 0 & k <= 255){
            if(width+left >= 0 & width+left <= 255){
                image[k][width+left] = 0;
            }
        }

    }
    for(int l = left; l < left+width; l++){
        if(height+top >= 0 & height+top <= 255){
            if(l >= 0 & l <= 255){
                image[height+top][l] = 0;
            }
        }

    }
}

// Fill in this function:
void draw_ellipse(int cy, int cx, int height, int width) {
    int rx = (width/2);
    int ry = (height/2);
    for(double theta = 0; theta < 360; theta += .001){
        int y = (rx * cos(theta)+cx);
        int x = (ry * sin(theta)+cy);
        if(x >= 0 & x <= 255) {
            if ( y >= 0 & y <= 255 ) {
                image[x][y] = 0;
            }
        }
    }

}


int main() {
    // initialize the image to all white pixels
    for (int i=0; i < SIZE; i++) {
        for (int j=0; j < SIZE; j++) {
            image[i][j] = 255;
        }
    }

    // Main program loop here
    int a;
    int b;
    int x;
    int y;
    int z;
    while(b != 2){
        cout <<("\nTo draw a rectangle, enter: 0 top left height width"
                "\nTo draw an ellipse, enter: 1 cy cx height width"
                "\nTo save your drawing as \"output.bmp\" and quit, enter:");
        cin >> b >> x >> y >> z >> a;
        if(b == 0){
            draw_rectangle (x,y,z,a);
        }
        if(b == 1){
            draw_ellipse (x,y,z,a);
        }
        // Write the resulting image to the .bmp file
        writeGSBMP("output.bmp", image);


    }
    return 0;

}