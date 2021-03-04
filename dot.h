#include "mosaic_interface.h"
#include <opencv2/opcnecv.hpp>
using namespace cv;

typedef chared_ptr<uchar> DATA;

DotPattern
{
    int iWidth, iHeight;  
    int x, y;
};

class CDot:IMosaic
{
    public:
        virtual bool Initialize(string font_name, int w, int l);
        virtual char GetChar(const byte *p) const;
        virtual Mat CreateMosaicImage(const Mat matSource);
        virtual void Render(Mat& mat) const;
    protected:
        void GetString(const Mat& mat);
        void Dot(Mat& mat, int i, int j);
        string strImage;
    private:
        int iWidth, iHeight;  // block size;
        int rows, cols;       //
        shared_ptr<DotPattern> Pattern;

}

