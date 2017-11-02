# ��2�£�����

> Ŀǰ�������ͼ��Ķ��������ر�ʾ�ģ������ǵ㡢ֱ�ߡ�Բ������ͼ�����ն����Ե����ʽ��ʾ�������ܶ�Խ��ͼ�ο�����Խϸ�塣

-------------------
## ���ص����

### DDA�㷨

> https://baike.baidu.com/item/DDA%E7%AE%97%E6%B3%95/3896255?fr=aladdin
>
> ���ø��㲽����С��������������ת��Ϊ������������

### Bresenham�㷨

> https://baike.baidu.com/item/bresenham%E7%AE%97%E6%B3%95/6430161?fr=aladdin
>
> ����뷽�����������������һ�����������ж��Ƿ�����������DDA�㷨���˴����������㣬����һЩϵ�л��ڸ��㷨�Ĳ����Ż���
> - ���ڲ��ø��㷨���л���
``` c++
void sge::Canvas::drawLine(int x1, int y1, int x2, int y2, const color4f & c1)
{
    int x, y, dx, dy, s1, s2, p, temp, interchange, i;
    x = x1;
    y = y1;
    dx = abs(x2 - x1);
    dy = abs(y2 - y1);

    if (x2 > x1)
        s1 = 1;
    else
        s1 = -1;

    if (y2 > y1)
        s2 = 1;
    else
        s2 = -1;

    if (dy > dx)
    {
        temp = dx;
        dx = dy;
        dy = temp;
        interchange = 1;
    }
    else
        interchange = 0;

    p = 2 * dy - dx;
    int pIndexMax = _width * _height;
    for (i = 1; i <= dx; i++)
    {
        drawPoint(x, y, c1);
        if (p >= 0)
        {
            if (interchange == 0)
                y = y + s2;
            else
                x = x + s1;
            p = p - 2 * dx;
        }
        if (interchange == 0)
            x = x + s1;
        else
            y = y + s2;
        p = p + 2 * dy;
    }
}
```
-------------------

## ��ɫ�����Խ���
> ��ɫ�Ľ��伴�������Ľ��䣬ʹ�����Բ�ֵ����
- �������߶�
``` c++
void sge::Canvas::drawLine(int x1, int y1, int x2, int y2, const color4f & c1, const color4f & c2)
{
    int x, y, dx, dy, s1, s2, p, temp, interchange, i;
    Color4f stepColor = c2 - c1;
    Color4f color = c1;
    x = x1;
    y = y1;
    dx = abs(x2 - x1);
    dy = abs(y2 - y1);
    
    if (x2 > x1)
        s1 = 1;
    else
        s1 = -1;

    if (y2 > y1)
        s2 = 1;
    else
        s2 = -1;

    if (dy > dx)
    {
        temp = dx;
        dx = dy;
        dy = temp;
        interchange = 1;
    }
    else
    {
        interchange = 0;
    }

    p = 2 * dy - dx;
    stepColor /= (float)dx;
    for (i = 1; i <= dx; i++)
    {
        drawPoint(x, y, color);
        if (p >= 0)
        {
            if (interchange == 0)
                y = y + s2;
            else
                x = x + s1;
            p = p - 2 * dx;
        }
        if (interchange == 0)
            x = x + s1;
        else
            y = y + s2;
        p = p + 2 * dy;

        color += stepColor;
    }
}
```

-------

### ���ڴ���Ч��ͼ

![lesson3.Canvas](capture.png)
-------------------
### github����https://github.com/xiangwencheng1994/sge/tree/master/lesson3.Line