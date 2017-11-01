/**
 *  sgeMath.h
 *  ���ڶ���һЩ������ѧ�ṹ�ͺ���
 */
#ifndef SGE_MATH_H
#define SGE_MATH_H

#include <assert.h>
#include <malloc.h>
#include <string.h>
#include <math.h>

#pragma pack(push)
#pragma pack(1)

namespace sge
{
    typedef unsigned char           byte;
    typedef int                     sizei;

    /**
     *  ��3��float��ʾ��ɫ
     *  �ڴ�ֱ�ΪRed,Green,Blue
     *  ÿ�����������۷�ΧΪ0-1
     */
    struct Color3f
    {
        float   _red;
        float   _green;
        float   _blue;

    public:
        Color3f() {}
        Color3f(float r, float g, float b) : _red(r), _green(g), _blue(b) {}
    };

    /**
     *  ��4��float��ʾ��ɫ
     *  �ڴ�ֱ�ΪRed,Green,Blue,Alpha
     *  ÿ�����������۷�ΧΪ0-1��AlphaΪ0��ʾȫ͸����1��ʾ��͸��
     */
    struct Color4f
    {
        float   _red;
        float   _green;
        float   _blue;
        float   _alpha;

    public:
        Color4f() {}
        Color4f(Color3f &c):_red(c._red), _green(c._green), _blue(c._blue), _alpha(0) {}
        Color4f(float r, float g, float b, float a = 1) : _red(r), _green(g), _blue(b), _alpha(a) {}
    };

    inline Color3f alphaBlend(Color3f &bgcolor, Color4f &fcolor)
    {
        float pA = 1.0f - fcolor._alpha;
        Color3f out;
        out._red = pA * bgcolor._red + fcolor._alpha * fcolor._red;
        out._green = pA * bgcolor._green + fcolor._alpha * fcolor._green;
        out._blue = pA * bgcolor._blue + fcolor._alpha * fcolor._blue;
        return out;
    }

    /**
     *  �����ֽڱ������ɫ�ṹ
     *  �ڴ�ֱ�ΪAlpha,Blue,Green,Red
     *  ������intֵ��ʾ������0xAABBGGRR,����AlphaΪ0��͸����255Ϊȫ͸��
     */
    union Color4b {
        int     _value;
        struct
        {
            byte    _alpha;
            byte    _blue;
            byte    _green;
            byte    _red;
        };

    public:
        Color4b() {}
        Color4b(int value) : _value(value) {}
        Color4b(byte a, byte r, byte g, byte b) : _alpha(a), _blue(b), _green(g), _red(r) {}
    };

    typedef struct Color3f          color3f;
    typedef struct Color4f          color4f;
    typedef union Color4b           color4b;
}

#pragma pack(pop)

#endif