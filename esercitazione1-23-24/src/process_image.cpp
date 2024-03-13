#include <cstdio>
#include <cstring>
#include <cassert>
#include <cmath>

#include "image.h"

using namespace std;

// HW0 #3
// const Image& im: input image
// return the corresponding grayscale image
Image rgb_to_grayscale(const Image &im) {
    assert(im.c == 3); // only accept RGB images
    Image gray(im.w,im.h,1); // create a new grayscale image (note: 1 channel)

    // TODO: calculate the pixels of 'gray'
    //NOT_IMPLEMENTED();
    for(int j=0;j<im.w;j++){
        for(int k=0;k<im.h;k++){
            gray(j,k,0)=0.299*im(j,k,0);
            gray(j,k,0)+=0.587*im(j,k,1);
            gray(j,k,0)+=0.114*im(j,k,2);
        }
    }
    return gray;
}


// Example function that changes the color of a grayscale image
Image grayscale_to_rgb(const Image &im, float r, float g, float b) {
    assert(im.c == 1);
    Image rgb(im.w, im.h, 3);

    for (int q2 = 0; q2 < im.h; q2++)
        for (int q1 = 0; q1 < im.w; q1++) {
            rgb(q1, q2, 0) = r * im(q1, q2);
            rgb(q1, q2, 1) = g * im(q1, q2);
            rgb(q1, q2, 2) = b * im(q1, q2);
        }

    return rgb;
}


// HW0 #4
// Image& im: input image to be modified in-place
// int c: which channel to shift
// float v: how much to shift
void shift_image(Image &im, int c, float v) {
    assert(c>=0 && c<im.c); // needs to be a valid channel

    // TODO: shift all the pixels at the specified channel
    //NOT_IMPLEMENTED();
    for(int i=0;i<im.w;i++){
        for(int j=0;j<im.h;j++){
            im(i,j,c)+=v;
        }
    }
}

// HW0 #8
// Image& im: input image to be modified in-place
// int c: which channel to scale
// float v: how much to scale
void scale_image(Image &im, int c, float v) {
    assert(c>=0 && c<im.c); // needs to be a valid channel

    // TODO: scale all the pixels at the specified channel

    //NOT_IMPLEMENTED();
    for(int i=0;i<im.w;i++){
        for(int j=0;j<im.h;j++){
            im(i,j,c)*=v;
        }
    }

}


// HW0 #5
// Image& im: input image to be modified in-place
void clamp_image(Image &im) {
    // TODO: clamp all the pixels in all channel to be between 0 and 1

    //NOT_IMPLEMENTED();
    for(int i=0;i<im.size();i++){
        if(im.data[i]<0)
            im.data[i]=0;
        if(im.data[i]>1)
            im.data[i]=1;
        //if(im.data[i]>1 || im.data[i]<0)
            //printf("trovato\n");
    }
}

// These might be handy
float max(float a, float b, float c) {
    return max({a, b, c});
}

float min(float a, float b, float c) {
    return min({a, b, c});
}


// HW0 #6
// Image& im: input image to be modified in-place
void rgb_to_hsv(Image &im) {
    assert(im.c==3 && "only works for 3-channels images");

    // TODO: Convert all pixels from RGB format to HSV format
    float R,G,B,H,S,V,m,C;
    //NOT_IMPLEMENTED();
    for(int i=0;i<im.w;i++){
        for(int j=0;j<im.h;j++){
            R=im(i,j,0);
            G=im(i,j,1);
            B=im(i,j,2);
            V=max(R,G,B);
            m=min(R,G,B);
            C=V-m;
            if(V!=0)
                S=C/V;
            else
                S=0;
            if(V==R)
                H=(G-B)/C;
            else if(V==G)
                H=((B-R)/C)+2;
            else if(V==B)
                H=((R-G)/C)+4;
            //else    
               // H=NULL;
            if(H!=NULL && H<0)
                H=(H/6)+1;
            else if(H!=NULL)
                H=(H/6);
            //while(H<0)
               // H++;
            im(i,j,0)=H;
            im(i,j,1)=S;
            im(i,j,2)=V;
        }
    }
}

// HW0 #7
// Image& im: input image to be modified in-place
void hsv_to_rgb(Image &im) {
    assert(im.c==3 && "only works for 3-channels images");

    // TODO: Convert all pixels from HSV format to RGB format
    float R,G,B,H,S,V,m,C,X;
    //NOT_IMPLEMENTED();
    for(int i=0;i<im.w;i++){
        for(int j=0;j<im.h;j++){
            H=im(i,j,0);
            S=im(i,j,1);
            V=im(i,j,2);
            C = V * S;
            X = C * (1 - abs(fmod(6*H,2.0) - 1));
            m = V - C;
            if(H>=0 && H<1/6){
                R=C;
                G=X;
                B=0;
            }
            else if(H>=1/6 && H<2/6){
                R=X;
                G=C;
                B=0;
            }
            else if(H>=2/6 && H<3/6){
                R=0;
                G=C;
                B=X;
            }
            else if(H>=3/6 && H<4/6){
                R=0;
                G=X;
                B=C;
            }
            else if(H>=4/6 && H<5/6){
                R=X;
                G=0;
                B=C;
            }
            else if(H>=5/6 && H<1){
                R=C;
                G=0;
                B=X;
            }
            R+=m;
            G+=m;
            B+=m;
            im(i,j,0)=R;
            im(i,j,1)=G;
            im(i,j,2)=B;
        }
    }
}

// HW0 #9
// Image& im: input image to be modified in-place
void rgb_to_lch(Image& im)
{
    assert(im.c==3 && "only works for 3-channels images");

    // TODO: Convert all pixels from RGB format to LCH format


    NOT_IMPLEMENTED();

}

// HW0 #9
// Image& im: input image to be modified in-place
void lch_to_rgb(Image& im)
{
    assert(im.c==3 && "only works for 3-channels images");

    // TODO: Convert all pixels from LCH format to RGB format

    NOT_IMPLEMENTED();

}


// Implementation of member functions
void Image::clamp(void) { clamp_image(*this); }

void Image::shift(int c, float v) { shift_image(*this, c, v); }

void Image::scale(int c, float v) { scale_image(*this, c, v); }

void Image::HSVtoRGB(void) { hsv_to_rgb(*this); }

void Image::RGBtoHSV(void) { rgb_to_hsv(*this); }

//void Image::LCHtoRGB(void) { lch_to_rgb(*this); }
