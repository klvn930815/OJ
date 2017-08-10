//
// Created by Qiezz on 17-8-6.
//

#include <iostream>
#include <fstream>

bool getCharByIndex(FILE* fpc,int index,int &font,int& width,int& height, unsigned short& label, unsigned char* &pData)
{
    if (!fpc)
    {
        return false;
    }
    if (pData)
    {
        delete[]pData;
        pData = NULL;
    }
    int nLanguage = 0;
    int nTotalCharNum = 0;
    int offset =  sizeof(int) + 92*sizeof(char)  + 2*sizeof(short) + 4*sizeof(int) + sizeof(char);
    fseek(fpc,sizeof(int),SEEK_SET);
    if(fread(&nTotalCharNum,sizeof(int),1,fpc)==0)
    {
        return false;
    }
    if (index < 0 || index>nTotalCharNum)
    {
        return false;
    }
    fseek(fpc,offset,SEEK_CUR);
    int nCharLength = 0;
    for (int i=0;i<index;i++)
    {
        if(fread(&nCharLength,sizeof(int),1,fpc)==0)
        {
            return false;
        }
        fseek(fpc,nCharLength - sizeof(int),SEEK_CUR);
    }
    if(fread(&nCharLength,sizeof(int),1,fpc)==0)
    {
        return false;
    }
    if(fread(&font,sizeof(int),1,fpc)==0)
    {
        return false;
    }
    unsigned short nlabel =0;
    if(fread(&nlabel,sizeof(unsigned short),1,fpc)==0)
    {
        return false;
    }
    fseek(fpc,2*sizeof(short int),SEEK_CUR);
    short int nWidth = 0;
    short int nHeight = 0;
    if(fread(&nWidth,sizeof(short int),1,fpc)==0)
    {
        return false;
    }
    if(fread(&nHeight,sizeof(short int),1,fpc)==0)
    {
        return false;
    }
    pData = new unsigned char[nWidth * nHeight];
    if(fread(pData,nWidth*nHeight,1,fpc)==0)
    {
        return false;
    }
    width = nWidth;
    height = nHeight;
    label=  nlabel;
    return true;
}

