#include <opencv2/opencv.hpp>
#include <iostream>
#include "letter_set.h"

using namespace cv;
using namespace std;

class CMosaic 
{
	public:
		CMosaic(){};
		~CMosaic(){};
		
        void ImageRead(string);
		bool empty()const;
        bool Run();
        void ShowOriginalImage() const;
        void ShowResultImage() const;

        Mat& GetImage() {return matImage;};

        
    private:
		Mat matOriginalImage;
        string strResult;
        MosaicFont fntMosaic;
        //Mat matResultImage;
        CLetterSet letSet;
};
