///////////////////////////////////////////////////////////
// CDIB.H: Header file for the DIB class.
///////////////////////////////////////////////////////////

#ifndef __CDIB_H
#define __CDIB_H

class CDib : public CObject
{
protected:
    LPBITMAPFILEHEADER m_pBmFileHeader;
    LPBITMAPINFO m_pBmInfo;
    LPBITMAPINFOHEADER m_pBmInfoHeader;
    RGBQUAD far* m_pRGBTable;
    BYTE huge* m_pDibBits;
    UINT m_numColors;
    
public:
    CDib(const char far* fileName);
    ~CDib();

    DWORD GetDibSizeImage();
    UINT GetDibWidth();
    UINT GetDibHeight();
    UINT GetDibNumColors();
    LPBITMAPINFOHEADER GetDibInfoHeaderPtr();
    LPBITMAPINFO GetDibInfoPtr();
    LPRGBQUAD GetDibRGBTablePtr();
    BYTE huge* GetDibBitsPtr();

protected:
    void LoadBitmapFile(const char far* fileName);

};

#endif
