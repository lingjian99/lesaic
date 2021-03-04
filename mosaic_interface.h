#include <string>

typeof struct interface; 
interface IMosaic 
{
    virtual bool(string font_name, int w, int l) = 0;
    virtual void InputBlock(const byte *p) = 0;
    virtual char OutputBlock() = 0;
    virtual void OutputBlock(byte *p) = 0;
};
