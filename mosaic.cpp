#include "mosaic.h"

void CMosaic::ImageRead(string str)
{
	matImage = imread(str);
}
bool CMosaic::empty() const
{
	return matImage.empty();
}
void CMosaic::ShowOriginalImage() const
{
    imshow("Original Image", matImage);
}

void CMosaic::ShowResultImage() const
{
    imshow("Result Image", matResultImage);

}

bool Run()
{

}

