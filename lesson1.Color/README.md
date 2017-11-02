# ��1�£���ɫ

>�κ��������ɫ����ͨ������ɫ����red����green����blue����϶��ɣ���ɫ�ķ�����Ҳ�н���ͨ������ָred��green��blue����ռ���������������ַ����⣬������ʱ����Ҫʹ�õ�͸���ȷ�����alpha��

-------------------

## ��ɫ�ı�ʾ

### ʹ��3��float��ʾ��ɫ

>���ǵ��������ܺ��ڴ濪����ʹ��3��float����ʾ��red��green��blue������һ��ʹ�÷�ΧΪ0��1��1Ϊ100%
``` c++
    struct Color3f
    {
        float   _red;
        float   _green;
        float   _blue;

    public:
        Color3f() {}
        Color3f(const Color3f& c):_red(c._red), _green(c._green), _blue(c._blue) {}
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
```

### ʹ��4��float��ʾ��ɫ

>ʹ��4��float��ʾ����͸���ȵ���ɫ������alpha��0��ʾȫ͸����1��ʾ��͸��
``` c++
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
```
### ʹ��4���ֽڱ�ʾ��ɫ

>�ܶ�ʱ������Ҳ����4���ֽڱ�ʾ��ɫ������ÿ���ֽڵı�ʾ��ΧΪ0-255���������Ϊ������ɫ�ĸ������ֳ���256���̶ȣ���ô��ȥ͸���ȣ������Ա�ʾ����ɫ��256*256*256�֣������һ�ֱ�ʾ��ʽ�����ľ���Զ������һ�֣�����ʡ�����ڴ濪������ʵ��Ŀǰ����ʾ�豸���Ҳֻ֧����ô�����ɫ������
``` c++
    typedef unsigned char	byte;
	
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
```
- ��������ʹ���������嶨��Color4b�ṹ���������Է����˸��������з��ʣ�Ҳ������int��ֵ������0xAABBGGRR����
- ��������û��ʹ��class��������ɫ����Ϊ��ɫ������ֻ��һ�������ṹ������ķ�װ���̳С���̬���޹�ϵ�����ǽ�����һЩ�������������

-------------------

## ��ɫ�Ļ��

### ��͸����ɫ�Ͱ�͸����ɫ�Ļ��

> ����һ��͸���ı���ͼ����A����һ��͸����ͼ����B����ô͸��Bȥ��A������ȥ��ͼ��C����B��A�Ļ��ͼ��
> 
> C = (1 - B.alpha) * A + B.alpha * B
``` c++
Color3f sge::alphaBlend(const Color3f &bgcolor, const Color4f &fcolor)
{
    float pA = 1.0f - fcolor._alpha;
    Color3f out;
    out._red = pA * bgcolor._red + fcolor._alpha * fcolor._red;
    out._green = pA * bgcolor._green + fcolor._alpha * fcolor._green;
    out._blue = pA * bgcolor._blue + fcolor._alpha * fcolor._blue;
    return out;
}
```

### ��͸����ɫ�Ͱ�͸����ɫ�Ļ��

> ��͸������A���͸������B�ص��뵥����͸������C��Ч��һ�������ǿ��Ը���A��B�����C����ɫ��͸���ȡ�
> 
> ��������һ����͸��͸����Ϊ80%�Ĳ��������ǿ�ȱ�Ϊ80%����͸��һ��͸����Ϊ60%�Ĳ��������ǿ��ʣ��48%���������ǲ��ò�͸���ȣ����ǽ�A��B��C͸���ȼ�дΪA.a��B.a��C.a,��:
>> C.a = 1 - ((1 - A.a) * (1 - B.a)) = A.a + B.a - A.a * B.a
>
> �����Ѿ�֪�����ڱ���ɫ����ε��Ӱ�͸��ɫ�����ǿ��Է�Ϊ���������ڱ���ɫ�ϵ��ϵ�һ����͸����ɫA��Ȼ���ڵ��õĽ���ϵ��ϵڶ�����͸����ɫB����ԭʼ����ɫΪR1,��һ�εĵ��õĽ��ΪT1��ȫ���õĽ��ΪT2
>> T1 = (1 - A.a) * R1 + A.a * A��
>> 
>> T2 = (1 - B.a) * T1 + B.a * B
>>>  = (1 - B.a) * ((1 - A.a) * R1 + A.a * A) + B.a * B
>>>  = (1 - B.a) * (1 - A.a) * R1 + (1 - B.a) * A.a * A + B.a * B
>
> ��T2��Ӧ��ͬ��R1��C��ֱ�ӻ�Ͻ��
>> T2 = (1 - C.a) * R1 + C.a * C
>>>  = (1 - (A.a + B.a - A.a * B.a)) * R1 + (A.a + B.a - A.a * B.a) * C
>>>  = (1 - A.a) * (1 - B.a) * R1 + (A.a + B.a - A.a * B.a) * C
>
> ����������ʽ��ͬ��(1 - A.a) * (1 - B.a) * R1,��������R1,�����C:
>> C = [(1 - B.a) * A.a * A + B.a * B] / (A.a + B.a - A.a * B.a)
``` c++
Color4f sge::alphaBlend(const Color4f &c1, const Color4f &c2)
{
    Color4f out;
    out._alpha = c1._alpha + c2._alpha - c1._alpha * c2._alpha;
    float k = (1.0f - c2._alpha) * c1._alpha;
    out._red = (k * c1._red + c2._alpha * c2._red) / out._alpha;
    out._green = (k * c1._green + c2._alpha * c2._green) / out._alpha;
    out._blue = (k * c1._blue + c2._alpha * c2._blue) / out._alpha;
    return out;
}
```

-------------------

### ���ڲ������ɿ�ִ�г���

-------------------
### ���´���λ��sgeMath.h�У�github����https://github.com/xiangwencheng1994/sge/tree/master/lesson1.Color