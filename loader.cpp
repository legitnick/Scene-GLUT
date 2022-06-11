
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

    // There's a SEGFAULT: Find it ;)
    // fread(&fileheader,sizeof(fileheader),1,l_file);    
    // fseek(l_file,sizeof(fileheader),SEEK_SET);
    // fread(&infoheader,sizeof(infoheader),1,l_file);
    
    infoheader.biWidth = width;
    infoheader.biHeight = height;

    l_texture=(unsigned char*)malloc(infoheader.biWidth*infoheader.biHeight*4);

    memset(l_texture,0,infoheader.biWidth * infoheader.biHeight*4);
    //memset(l_texture,0,sizeof(l_texture));
    //printf("4444444444\n");
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
    texid1=LoadBitmap("assets/front.bmp", 256, 128);
    texid2=LoadBitmap("assets/left.bmp", 128, 256);
    texid3=LoadBitmap("assets/right.bmp", 128, 256);
    texid4=LoadBitmap("assets/minar_tiles.bmp", 192, 128);
    texid5=LoadBitmap("assets/minar_gliph.bmp", 192, 128);
    texid6=LoadBitmap("assets/dome_gliph.bmp", 256, 128);
    texid7=LoadBitmap("assets/black_stone.bmp", 128, 128);
    texid8=LoadBitmap("assets/big_dome.bmp", 512, 256);
    texid9=LoadBitmap("assets/tree.bmp", 128, 128);
    texid10=LoadBitmap("assets/grass.bmp", 256, 256);
    texid11=LoadBitmap("assets/water.bmp", 512, 256);
    texid12=LoadBitmap("assets/brick.bmp", 128, 128);
    texid13=LoadBitmap("assets/tiles.bmp", 512, 64);
    texid14=LoadBitmap("assets/small_gliphs.bmp", 256, 128);
    texid15=LoadBitmap("assets/red_stone.bmp", 128, 128);
    texid16=LoadBitmap("assets/octagon_side.bmp", 1024, 64);
}

void TexManager::initSkybox(void)
{
  skybox = new int(6);
  skybox[SKY_FRONT] = LoadBitmap("assets/txStormydays_front.bmp", 1024, 1024);
  skybox[SKY_RIGHT] = LoadBitmap("assets/txStormydays_right.bmp", 1024, 1024);
  skybox[SKY_LEFT] = LoadBitmap("assets/txStormydays_left.bmp", 1024, 1024);
  skybox[SKY_BACK] = LoadBitmap("assets/txStormydays_back.bmp", 1024, 1024);
  skybox[SKY_UP] = LoadBitmap("assets/txStormydays_up.bmp", 1024, 1024);
  skybox[SKY_DOWN] = LoadBitmap("assets/txStormydays_down.bmp", 1024, 1024);
}
