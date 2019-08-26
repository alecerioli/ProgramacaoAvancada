#ifndef COLOR_H
#define COLOR_H


class color
{
    float r,g,b;
public:
    color(float mr=0,float mg=0,float mb=0);
    ~color();
    void print(void);
    color combina(color c2);
    bool compara(color c1);
};

#endif // COLOR_H
