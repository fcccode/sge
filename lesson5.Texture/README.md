# ��5�£�������ͼ

> ��һ��������ʹ��ɨ�����㷨���������������ɫ�������Σ����½�ʹ�����������㷨���ƾ�����ͼ�������Σ������ͼ����ͨ��������������

-------------------
## ͼƬ��ȡ

### stb_image

> stb_image��һ���ǳ���������ͼƬ���߿⣬���ֻ��Ҫ��ȡͼƬ��ֻ��Ҫstb_imgage.h�ļ����ɣ���Ҫע�����ͷ�ļ��а���Դ���룬ʹ��STB_IMAGE_IMPLEMENTATION����ƣ���Ҫ�����Դ�ļ��п����ú��������ʱ�����ض��壬�ļ�ͷ������ʹ��˵�����������ǲ���stb_image����ͼƬ��ȡ��

- ��װ������
``` c++
// sgeTexture.h

class sgeTexture
{
public:
    sgeTexture(const char* file);
    ~sgeTexture();

    inline const color4b&  pixelAt(int x, int y) const { return _data[(y % _height) * _width + (x % _width)]; }

    inline int  width() const { return _width; }
    inline int  height() const { return _height; }

    const color4b   pixelUV(float u, float v) const;

private:
    color4b*    _data;
    int         _width;
    int         _height;
};

// sgeTexture.cpp
#include "sgeTexture.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

sgeTexture::sgeTexture(const char * file)
    : _width(0), _height(0), _data(NULL)
{
    assert(file);
    int comp = 0;
    byte* data = stbi_load(file, &_width, &_height, &comp, 4);
    assert(data && "stbi_load failed, see stbi_failure_reason()");
    for (int y = 0; y < _height; ++y)
    {
        int dy = y * _width;
        for (int x = 0; x < _width; ++x)
        {
            // rgba ==> bgra
            Swap(data[(dy + x) * 4 + 0], data[(dy + x) * 4 + 2]);
        }
    }
    _data = (color4b*)data;
}

sgeTexture::~sgeTexture()
{
    if (_data)
    {
        stbi_image_free(_data);
        _data = NULL;
    }
}

const color4b sge::sgeTexture::pixelUV(float u, float v) const
{
    float x = u * _width;
    float y = v * _height;

    return  pixelAt(x, y);
}
```
- pixelUV������ͼƬ��߹淶��0-1֮�䣬����ֻ�ǽ����˼򵥵�ȡ�ͽ�������ɫ��Ϊ�˸��õ���ʾЧ�������Բ���˫���Բ�ֵ���㷨�����ʾЧ����

### FreeImage

> FreeImageͼ������stb_image���ܸ�Ϊǿ��ʹ�õ�Ҳ�Ƚ϶࣬����ʹ�÷������аٶȡ�

## ���������㷨����������

### ���������㷨

> ��һ�����Ѿ����������������㷨�����˲������ֱ����в�����ĵط���������������ϡ�

> ����������������壬��P(Px, Py)���ɶ���A(x1, y1)��B(x2, y2)��C(x3, y3)���ɵ��������е���������Ϊ��b1, b2, b3��,�����ΪS,�У�
>> b1 = S(PBC) / S(ABC)
>>
>> b2 = S(PAC) / S(ABC)
>>
>> b3 = S(PBC) / S(ABC)
>>
> S(ABC) = 0.5*[(y1-y3)*(x2-x3)+(y2-y3)*(x3-x1)];
> ͬ�����ǿ�����������������ε������ע����������û�жԶ������˳�򻯣��������Ϊ���������ⲻӰ����������������꣬���ǽ����ӷ�ĸͬʱ����2���Լ򻯵õ��������ӣ�
>> b1 * S(ABC) = (Py-y3)*(x2-x3)+(x3-Px)*(y2-y3)
>>
>> b2 * S(ABC) = (Py-y1)*(x3-x1)+(x1-Px)*(y3-y1)
>>
>> b3 * S(ABC) = (Py-y2)*(x1-x2)+(x2-Px)*(y1-y2)
>>
> ����������������壬����֪�����������ͬ�ţ�������0���С��0�����ʾ���������ڲ�����������ֻ��Ҫ�ж��ұ��Ƿ�ͬ�žͿ��жϵ�P�Ƿ����������ڲ���
> 
> ��P�����������꽫�ǲ���A��B��C����������ļ�Ȩֵ,���Ȩ����b1��b2��b3��

### ����������

> ͨ���������ص㣬���ݸ����ص�����������ж��Ƿ����������ڲ��������������������������õ���������꣬���Ƹõ㡣

- �����ʽ��UV����Ӧ�������꣬����x,yҲ���淶����0-1��
``` c++
    // sgeMath.h

    // 2d����ṹ��XY + UV
    template<typename T>
    class XYUV
    {
    public:
        T   x, y;
        T   u, v;
    public:
        XYUV() {}
        XYUV(T x, T y, T u, T v) : x(x), y(y), u(u), v(v) {}
    };

    typedef class XYUV<float>   xyuv;
```

- ��2D���������Χ��
``` c++
    // sgeMath.h

    // 2d������Χ��
    template<typename T>
    class AxisAlignedBox2D
    {
    public:
        T   minX;
        T   minY;
        T   maxX;
        T   maxY;

    public:
        AxisAlignedBox2D(T x, T y) : minX(x), maxX(x), minY(y), maxY(y) {}
        AxisAlignedBox2D(const Vector2<T> & p) : minX(p.x), maxX(p.x), minY(p.y), maxY(p.y) {}

        void update(T x, T y)
        {
            if (x < minX) minX = x;
            else if (x > maxX) maxX = x;
            if (y < minY) minY = y;
            else if (y > maxY) maxY = y;
        }
    };


    typedef class AxisAlignedBox2D<int>     aabb2i;
    typedef class AxisAlignedBox2D<float>   aabb2f;
```

- ʵ�����������������������
``` c++
void Canvas::drawTriangle(const xyuv & v1, const xyuv & v2, const xyuv & v3, const sgeTexture & tex)
{
    int x1 = v1.x * _width, x2 = v2.x * _width, x3 = v3.x * _width;
    int y1 = v1.y * _height, y2 = v2.y * _height, y3 = v3.y * _height;
    aabb2i box(x1, y1);
    box.update(x2, y2);
    box.update(x3, y3);

    int dx23 = x2 - x3, dx31 = x3 - x1, dx12 = x1 - x2;
    int dy23 = y2 - y3, dy31 = y3 - y1, dy12 = y1 - y2;
    
    int ss =  dy23 * dx31 - dy31 * dx23;

    if (ss == 0) return; // ��������һ��ֱ����

    for (int x = box.minX; x <= box.maxX; ++x)
    {
        if (x < 0) continue;
        if (x >= _width) break;
        for (int y = box.minY; y <= box.maxY; ++y)
        {
            if (y < 0) continue;
            if (y >= _height) break;

            int s1 = (y - y3) * dx23 + (x3 - x) * dy23;
            int s2 = (y - y1) * dx31 + (x1 - x) * dy31;
            int s3 = (y - y2) * dx12 + (x2 - x) * dy12;
            if ((s1 >= 0 && s2 >= 0 && s3 >= 0)
                || (s1 <= 0 && s2 <= 0 && s3 <= 0))
            {
                float b1 = (float)s1 / ss, b2 = (float)s2 / ss, b3 = (float)s3 / ss;
                float fu = b1 * v1.u + b2 * v2.u + b3 * v3.u;
                float fv = b1 * v1.v + b2 * v2.v + b3 * v3.v;
                maskBlend(_pixels[y * _width + x], tex.pixelUV(fu, fv));
            }
        }
    }
}
```


### ���ڴ���Ч��ͼ

![lesson5.Texture](capture.png)

-------------------
### github����https://github.com/xiangwencheng1994/sge/tree/master/lesson5.Texture