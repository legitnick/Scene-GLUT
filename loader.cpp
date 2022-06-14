
#include "loader.h"

int num_texture=-1;
int LoadPicture(char* filename)
{
    ILboolean success;
     ILuint image;

    ilGenImages(1, &image); /* Generation of one image name */
     ilBindImage(image); /* Binding of image name */
     success = ilLoadImage(filename); /* Loading of the image filename by DevIL */

    if (success) /* If no error occured: */
    {
        /* Convert every colour component into unsigned byte. If your image contains alpha channel you can replace IL_RGB with IL_RGBA */
           success = ilConvertImage(IL_RGBA, IL_UNSIGNED_BYTE);

        if (!success)
           {
                 return -1;
           }
    }
    else
        return -1;

    return image;
}
int LoadBitmap(char *filename, int width, int height)
{
    int i,j=0;
    FILE *l_file;
    unsigned char *l_texture;
    BITMAPINFOHEADER infoheader; 
    RGBTRIPLE rgb;

    num_texture++;
    if((l_file=fopen(filename,"rb"))==NULL)return(-1);

    
    infoheader.biWidth = width;
    infoheader.biHeight = height;

    l_texture=(unsigned char*)malloc(infoheader.biWidth*infoheader.biHeight*4);

    memset(l_texture,0,infoheader.biWidth * infoheader.biHeight*4);
    
	 for(i=0;i<infoheader.biWidth*infoheader.biHeight;i++)
    {
        fread(&rgb,sizeof(rgb),1,l_file);
        l_texture[j+0]=rgb.rgbtRed;
        l_texture[j+1]=rgb.rgbtGreen;
        l_texture[j+2]=rgb.rgbtBlue;
        l_texture[j+3]=255;
        j+=4;
    }
    fclose(l_file);
    glBindTexture(GL_TEXTURE_2D,num_texture);
    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_NEAREST);
    //�glTexParameterf(GL_TEXTURE_2D,�GL_TEXTURE_MIN_FILTER,�GL_LINEAR);
    glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_MODULATE);
    glTexImage2D(GL_TEXTURE_2D,0,4,infoheader.biWidth,infoheader.biHeight,0,GL_RGBA,GL_UNSIGNED_BYTE,l_texture);
    gluBuild2DMipmaps(GL_TEXTURE_2D,4,infoheader.biWidth,infoheader.biHeight,GL_RGBA,GL_UNSIGNED_BYTE,l_texture);
    free(l_texture);
    return(num_texture);
}


void TexManager::loadBMPs(void)
{
    texid1=LoadBitmap("assets/green_circle.bmp", 184, 184);
    texid9=LoadBitmap("assets/chess_prob.bmp", 128, 128);
    texid12=LoadBitmap("assets/brick.bmp", 128, 128);
}

