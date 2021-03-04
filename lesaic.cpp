#include "mosaic.hpp"
#include <iostream>
using namespace std;

string GetImage();

int main(int argc char* argv)
{
    shared_prt<CDot> dot;
    string strFile = GetImageFile();
    
    dot.imread(strFile);

    if(dot.empty())
    {
        Mat mat_result;

        om.ShowOriginalImage();
        if(dot.CreateMosaicImage())
        {    dot.Render(mat_result);
            imshow("Result image", mat_result);
        }
        else
            cout<<"Can not create a letter mosaic image"
    }

	return 0;
}
string GetImage()
{
    return "abc.jpg";
}
