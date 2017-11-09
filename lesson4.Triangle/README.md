# ��4�£���������

> ���������������ͼԪ֮һ�������������������ι��ɣ����еĶ���ζ��ܹ��ָ�����������Σ����߿�ͨ������ϸ��ģ�⣩����ʵ����OpenGL��DirectX�У����е���״����ͨ����������������ɵġ�

-------------------
## ����������㷨

### ɨ�����㷨

> �������߷ֳ�һ��ƽ��������(�������������Y������ͬ)��һ��ƽ��������(�������������Y������ͬ)���ڰ�yɨ�������������Σ�һ��һ�еĽ��л���

- �ֳ����������Σ����ǰ�y��������������򣬲��ѽ������߷ֳ���������������
``` c++
void sge::Canvas::drawTriangle(const Point & p1, const Point & p2, const Point & p3, const color4b & c1)
{
    Point p[3] = { p1, p2, p3 };
    // sort by y
    if (p[1].y > p[0].y) Swap(p[0], p[1]);
    if (p[2].y > p[0].y) Swap(p[0], p[2]);
    if (p[1].y < p[2].y) Swap(p[1], p[2]);

    int px = (int)roundf(float(p[1].y - p[0].y) / (p[2].y - p[0].y) * (p[2].x - p[0].x) + p[0].x);
    Point mid(px, p[1].y);

    drawFlatBottomTriangle(p[0], p[1], mid, c1);
    drawFlatTopTriangle(p[2], p[1], mid, c1);
}
```

- ����ƽ�������Σ�y�ݼ���x����

``` c++
void sge::Canvas::drawFlatBottomTriangle(const Point& top, const Point& left, const Point& right, const color4b& c1)
{
    float dy = top.y - left.y;
    float stepX1 = (top.x - left.x) / dy;
    float stepX2 = (top.x - right.x) / dy;
    float leftX = top.x;
    float rightX = top.x;
    for (int y = top.y; y >= left.y; --y)
    {
        if (rightX > leftX) drawSpanLine((int)leftX, (int)rightX, y, c1);
        else drawSpanLine((int)rightX, (int)leftX, y, c1);
        leftX -= stepX1;
        rightX -= stepX2;
    }
}
void sge::Canvas::drawSpanLine(int minX, int maxX, int y, const color4b & c1)
{
    if (y < 0 || y >= _height) return;
    if (maxX >= _width) maxX = _width - 1;
    
    for (int x = minX < 0 ? 0 : minX; x <= maxX; ++x)
    {
        maskBlend(_pixels[y * _width + x], c1);
    }
}
```

- ͬ������ƽ�������ߣ�y������x����

``` c++
void sge::Canvas::drawFlatBottomTriangle(const Point& top, const Point& left, const Point& right, const color4b& c1)
{
    float dy = top.y - left.y;
    float stepX1 = (top.x - left.x) / dy;
    float stepX2 = (top.x - right.x) / dy;
    float leftX = top.x;
    float rightX = top.x;
    for (int y = top.y; y >= left.y; --y)
    {
        if (rightX > leftX) drawSpanLine((int)leftX, (int)rightX, y, c1);
        else drawSpanLine((int)rightX, (int)leftX, y, c1);
        leftX -= stepX1;
        rightX -= stepX2;
    }
}
```

### ���������㷨

> ����������ƽ�������㶼�ܱ�ʾΪ����ļ�Ȩƽ��ֵ�����Ȩ�ͽ����������ꡣ
> 
> �����������ͨ���������ռ�Ƚ��м��㣬��P����������ABC�е���������ΪP(x, y, z),��ôx�����������PBC���������������ABC�������y�����������PAC���������������ABC�������z�����������PAB���������������ABC�������
> ͨ����ͼ�ܺ���⣬x + y + z ʼ��Ϊ1�������Ƕ�ͬʱ����0��1֮��ʱ����P�����������ڲ�����֮�����������ⲿ��
> 
> ���ǿ���ͨ��ɨ�������ߵ�������Χ���ڵ�ÿ�����ؽ����ж��Ƿ����������ڲ����Ӷ����л��ơ�
> ͨ���ȽϺͲ��ԣ���Ч���ϱ�ɨ�����㷨�ף������Ը���С��ɫ��ֵ�����

## ����������

> ͨ����������Ĳ�ͬ��ɫ�����ǿ��Ը��ݻ�������һ���������Բ�ֵ����������������ߡ�

### ���ڴ���Ч��ͼ

![lesson4.Triangle](capture.png)

- ���ڲ���������㣬ʹ��Release����������ѡ����������֡��

-------------------
### github����https://github.com/xiangwencheng1994/sge/tree/master/lesson4.Triangle