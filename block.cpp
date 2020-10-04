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
    // if (!(column>=0 && (unsigned)column<im.width())) return;
    // if (!(row>=0 && (unsigned)row<im.height())) return;
  
  int col_bound = (column + width() > (int)im.width())? im.width() : (column + width());
  int row_bound = (row + height() > (int)im.height())? im.height() : (row + height());
  
  for (int col = column; col<col_bound; col++){
    for (int rowNum = row; rowNum<row_bound; rowNum++){
      *(im.getPixel(col, rowNum)) = data[rowNum-row][col-column];
    }
  }

}   

//You will be taking the pixels from a rectangular region in an image, and placing them into a block. 
//A block is just a vector whose elements are vectors of pixels.
void Block::build(PNG &im, int column, int row, int width, int height)
{   
    for  (int x = row; x < row + height; x++) {
            vector<HSLAPixel> pixels;
            for (int y = column; y < column + width; y++){
                    HSLAPixel *pixel = im.getPixel(y, x);
                    pixels.push_back(*pixel);
            }
        data.push_back(pixels);
    }
}

void Block::flip()
{
    int last = height()-1;
    for (int row = 0; row < height()/2; row++) {
        for (int col = 0; col < width(); col++) {
            HSLAPixel temp = data[row][col];
            data[row][col] = data[last-row][col];
            data[last-row][col] = temp;
        }
    
    }
}
