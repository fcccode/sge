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
        Color3f(const Color3f& c) :_red(c._red), _green(c._green), _blue(c._blue) {}
        Color3f(float r, float g, float b) : _red(r), _green(g), _blue(b) {}

        Color3f     operator +(const Color3f& c) const { return Color3f(_red + c._red, _green + c._green, _blue + c._blue); }
        Color3f     operator -(const Color3f& c) const { return Color3f(_red - c._red, _green - c._green, _blue - c._blue); }
        Color3f&    operator +=(const Color3f& c) { _red += c._red, _green += c._green, _blue += c._blue; return *this; }
        Color3f&    operator -=(const Color3f& c) { _red -= c._red, _green -= c._green, _blue -= c._blue; return *this; }
        Color3f     operator *(float k) const { return Color3f(_red * k, _green * k, _blue * k); }
        Color3f     operator /(float k) const { return Color3f(_red / k, _green / k, _blue / k); }
        Color3f&    operator *=(float k) { _red *= k, _green *= k, _blue *= k; return *this; }
        Color3f&    operator /=(float k) { _red /= k, _green /= k, _blue /= k; return *this; }
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
        Color4f(const Color3f &c) :_red(c._red), _green(c._green), _blue(c._blue), _alpha(1.0f) {}
        Color4f(float r, float g, float b, float a = 1.0f) : _red(r), _green(g), _blue(b), _alpha(a) {}

        Color4f     operator +(const Color4f& c) const { return Color4f(_red + c._red, _green + c._green, _blue + c._blue, _alpha + c._alpha); }
        Color4f     operator -(const Color4f& c) const { return Color4f(_red - c._red, _green - c._green, _blue - c._blue, _alpha - c._alpha); }
        Color4f&    operator +=(const Color4f& c) { _red += c._red, _green += c._green, _blue += c._blue, _alpha += c._alpha; return *this; }
        Color4f&    operator -=(const Color4f& c) { _red -= c._red, _green -= c._green, _blue -= c._blue, _alpha -= c._alpha; return *this; }
        Color4f     operator *(float k) const { return Color4f(_red * k, _green * k, _blue * k, _alpha * k); }
        Color4f     operator /(float k) const { return Color4f(_red / k, _green / k, _blue / k, _alpha / k); }
        Color4f&    operator *=(float k) { _red *= k, _green *= k, _blue *= k, _alpha *= k; return *this; }
        Color4f&    operator /=(float k) { _red /= k, _green /= k, _blue /= k, _alpha /= k; return *this; }
    };

    /**
    *  ��͸����ɫ�Ͱ�͸����ɫ�Ļ��
    *  ����һ��ͼ����A����һ��͸����ͼ����B����ô͸��Bȥ��A���������տ�������ɫ
    */
    Color3f alphaBlend(const Color3f &bgcolor, const Color4f &fcolor);

    /**
    *  ��͸����ɫ�Ͱ�͸����ɫ�Ļ��
    *  �������͸����ɫ�Ĳ����ص������ɫ��͸����
    */
    inline Color4f alphaBlend(const Color4f &c1, const Color4f &c2);

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
        Color4b(const Color4b& c) : _value(c._value) {}
        Color4b(int value) : _value(value) {}
        Color4b(byte a, byte r, byte g, byte b) : _alpha(a), _blue(b), _green(g), _red(r) {}
    };

    typedef struct Color3f          color3f;
    typedef struct Color4f          color4f;
    typedef union Color4b           color4b;
}

#pragma pack(pop)

#endif