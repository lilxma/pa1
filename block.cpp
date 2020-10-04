#include "block.h"
#include <cmath>
#include <iostream>

//the only data associated with the block is the vector
//a block is just a vector whose elements are vectors of pixel

//in each row how many HSLAPixels
int Block::width() const
{
    if (data.size() == 0) {
        return 0;
    }
    return data[0].size();
}

//number of rows of vectors
int Block::height() const
{
    return data.size();
}

//Draws the current block at position (column,row) in im.
//render takes in an image and some parameters and renders(draws) the current block onto the given image.
void Block::render(PNG &im, int column, int row) const
{
    int c = 0;
    int r = 0;

    for (int i = column; i < column+width(); i++){
        if (i<(int)im.width()){
            for (int j=row; j<row+height(); j++) {
            if (j< (int)im.height()) {
                *im.getPixel(i,j) = data[c][r];
                r++;
            }
        }
    }
    c++;
}

    // for (int x = column; x < column + width(); x++) {
    //     for (int y = row; y < row + height(); y++) {
    //         if ((unsigned) x < im.width() && (unsigned) y < im.height()) {
    //              HSLAPixel *pixelImage = im.getPixel(x, y);
    //              for (int i = 0; i < width(); i++) {
    //                 for (int j = 0; j < height(); j++) {
    //                  *pixelImage = data[i][j];
    //                 }
    //             }        
    //         }
            
    //     }
    // }
}

//You will be taking the pixels from a rectangular region in an image, and placing them into a block. 
//A block is just a vector whose elements are vectors of pixels.
void Block::build(PNG &im, int column, int row, int width, int height)
{
    // int c = 0;
    // int r = 0;

    // data.resize(height);
    // for (int col = column; col < column + width; col++) {
    //     data[col].resize(width);
    //     for (int rowNum = row; rowNum < row + height; rowNum++){
    //         data[c][r] = *(im.getPixel(col,rowNum));
    //         r++;
    //     }
    //     c++;
    // }

    vector<HSLAPixel> pixels;
    for (int x = column; x < column + width; x++) {
        for (int y = row; y < row + height; y++) {
            HSLAPixel *pixel = im.getPixel(x, y);
            pixels.push_back(*pixel);
        }
        data.push_back(pixels);
    }
}

void Block::flip()
{
int last = height()-1;
for (int i = 0; i < height()/2; i++) {
  for (int j = 0; j < width(); j++) {
     data[j][i] = data[j][last];
    }
    last--;
    }
}
