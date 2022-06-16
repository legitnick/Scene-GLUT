
#include "loader.h"

int num_texture=-1;
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
    texid12=LoadBitmap("assets/grey_wall.bmp", 366, 366);
    texid9=LoadBitmap("assets/chess_prob.bmp", 225, 225);
    texid4=LoadBitmap("assets/game_win2.bmp", 256, 256);
    texid3=LoadBitmap("assets/game_lose.bmp", 256, 256);
    texid5 = LoadBitmap("assets/wood.bmp",225,225);
	 texid2=LoadBitmap("assets/brick.bmp", 128, 128);
}

