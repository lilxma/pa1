#include "block.h"
#include <cmath>
#include <iostream>

//the only data associated with the block is the vector
//a block is just a vector whose elements are vectors of pixel

//in each row how many HSLAPixels
int Block::width() const
{
    // if (data.size() == 0) {
    //     return 0;
    // }
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
//     if (!(column>=0 && (unsigned)column<im.width())) return;
//     if (!(row>=0 && (unsigned)row<im.width())) return;
  
//   int col_bound = (column + width() > (int)im.width())? im.width() : (column + width());
//   int row_bound = (row + height() > (int)im.height())? im.height() : (row + height());
  
//   for (int col = column; col<col_bound; col++){
//     for (int rowNum = row; rowNum<row_bound; rowNum++){
//       *(im.getPixel(col, rowNum)) = data[rowNum-(unsigned)row][col-(unsigned)column];
//     }
//   }
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
}   

//You will be taking the pixels from a rectangular region in an image, and placing them into a block. 
//A block is just a vector whose elements are vectors of pixels.
void Block::build(PNG &im, int column, int row, int width, int height)
{

    // unsigned int col_bound = column + width;
    // unsigned int row_bound = row + height;

    // data.resize(height);
    // for (unsigned int rowNum=row; rowNum<row_bound; rowNum++){
    //     data[rowNum].resize(width);
    //     for (unsigned int col=column; col<col_bound; col++){
    //     data[rowNum - row][col-column] = *(im.getPixel(col, rowNum));
    //     }
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
        HSLAPixel temp = data[j][i];
        data[j][i] = data[j][last];
        data[j][last] = temp;
    }
    last--;
    }
}
