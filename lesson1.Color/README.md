# ��1�£���ɫ�ı�ʾ

>�κ��������ɫ����ͨ������ɫ����red����green����blue����϶��ɣ���ɫ�ķ�����Ҳ�н���ͨ������ָred��green��blue����ռ���������������ַ����⣬������ʱ����Ҫʹ�õ�͸���ȷ�����alpha��

-------------------

## ʹ��3��float��ʾ��ɫ

>���ǵ��������ܺ��ڴ濪����ʹ��3��float����ʾ��red��green��blue������һ��ʹ�÷�ΧΪ0��1��1Ϊ100%
``` c++
    struct Color3f
    {
        float   _red;
        float   _green;
        float   _blue;

    public:
        Color3f() {}
        Color3f(float r, float g, float b) : _red(r), _green(g), _blue(b) {}
    };
```

## ʹ��4��float��ʾ��ɫ

>ʹ��4��float��ʾ����͸���ȵ���ɫ������alpha��0��ʾ��͸����1��ʾ100%͸��
``` c++
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
```
## ʹ��4���ֽڱ�ʾ��ɫ
>�ܶ�ʱ������Ҳ����4���ֽڱ�ʾ��ɫ������ÿ���ֽڵı�ʾ��ΧΪ0-255���������Ϊ������ɫ�ĸ������ֳ���256���̶ȣ���ô��ȥ͸���ȣ������Ա�ʾ����ɫ��256*256*256�֣������һ�ֱ�ʾ��ʽ�����ľ���Զ������һ�֣�����ʡ�����ڴ濪������ʵ��Ŀǰ����ʾ�豸���Ҳֻ֧����ô�����ɫ������
``` c++
	typedef unsigned char       byte;
	
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
```
- ��������ʹ���������嶨��Color4b�ṹ���������Է����˸��������з��ʣ�Ҳ������int��ֵ������0xAABBGGRR����
- ��������û��ʹ��class��������ɫ����Ϊ��ɫ������ֻ��һ�������ṹ������ķ�װ���̳С���̬���޹�ϵ��

### ���´���λ��sgeMath.h�У�github����https://github.com/xiangwencheng1994/sge/tree/master/lesson1.Color