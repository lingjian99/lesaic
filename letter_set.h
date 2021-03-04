class CLetter: IMosaic
{

    public:
        bool virtual Initialize(string font_name, int w, int l);
        bool void InputBlock(const byte *p);
        char virtual OutputBlock();
        void virtual OutputBlock(byte *p);

    private:
        string strFont;
        float fntSize;

};
