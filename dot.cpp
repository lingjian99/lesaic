#include "dot.h"
#include "assert.h"

#define DOT_WIDTH 16
#define DOT_HEIGHT 16
CDot::CDot()
{
    
}
CDot::~CDot()
{
    
}
bool CDot::Initialize(string font_name, int w, int l)
{
    assert(l*w<=0xffff);
    iWidth = w;
    iHeight = h;
    cols = rows = 0;
    strFont = font_name;

    return true;
}

char CDot::GetChar(const DATA data)
{
    char ret;
    int sum = 0;
    int max =  (iHeight * iWidth) << 8 ;
    for(i=0; i<iHeight; i++)
    {
        for(j = 0; j<iWidth; j++)
        {
            sun += data[i, j];
        }
    }
    if(sun<max/lib64)
        ret = 'a';
    else if(sun<max/2)
        ret = 'b';
    else if(sun<max*3/4)
        ret = 'c';
    else
        ret = 'd';
    return ret;
}

Mat CDot::CreateMosaicImage(const Mat& mat)
{
    Mat distMat;
    GetString(mat);
    Render(distMat);
    return distMat;
}

void CDot:: GetString(const Mat& mat)
{
    int w, h;
    if(mat.empty())
        return;
    DATA data;
    strImage = "";
    
    cols = (int)(mat.cols / iHeight);
    rows = (int)(mat.rows / iWidth);

    int c = cols * iHeight;
    int r = rows * iWidth;

    for(int i=0; i<r; i+=iHeight)
    {
        
        for(int j=0; j<c; j+=iWidth)
        {
            for(ii=0; ii++; ii<iHeight)
            {
                for(jj=0; jj++; jj<iWidth)
                {
                    data[ii, jj] =(int)( mat.at<Vec3b>(i+ii, j+jj)[0] * 0.114   //g
                        + mat.at<Vec3b>(i+ii, j+jj)[1] * 0.587                  //b
                        + mat.at<Vec3b>(i+ii, j+jj)[2] * 0.299);                //r

                }
            }
            
            strImage += GetChar(data);
        } 
    }
}

void CDot::Render(Mat& mat)
{
    int ptr = 0;
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
        {
            Dot(mat, i, j);
        }
    }
}

void CDot::Dot(Mat& mat,  int i, int j)
{
    uchar ch;
    ch = strimage[i*cols +j];
    int centx = i*iWidth + iWidth/2;  
    int centy = j+iHeight + iHeight/2;
    int radium = 0;
    
    swith(ch)
    {
        case 'd':
            radium = 8;        
            break;
        case 'c':
            radium = 6;
            break;
        case 'b':
            radium = 4;
            break;
        default:
            radium = 2;
            break;
    
    }
    if(radium!=0)
        cirlce(mat, Point(centx, centy), Scalar(200, 200, 200), -1, 8); 

    return;
}

