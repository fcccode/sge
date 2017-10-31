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

#define PI              (3.14159265358979323846)
#define DEG2RAD(x)      (x * PI / 180)      // �Ƕ�ת����
#define RAD2EDG(x)      (x * 180 / PI)      // ����ת�Ƕ�

namespace sge
{
    typedef unsigned char       byte;
    typedef int                 sizei;
    typedef struct Color4f       Color4f;

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
     *  ÿ�����������۷�ΧΪ0-1
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
        Color4f(float r, float g, float b, float a = 0) : _red(r), _green(g), _blue(b), _alpha(a) {}
    };

    /**
     *  �����ֽڱ������ɫ�ṹ
     *  �ڴ�ֱ�ΪAlpha,Blue,Green,Red
     *  ������intֵ��ʾ������0xAABBGGRR
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
        Color4b(int value) : _value(value) {}
        Color4b(byte a, byte r, byte g, byte b) : _alpha(a), _blue(b), _green(g), _red(r) {}
    };

}

#pragma pack(pop)

#endif