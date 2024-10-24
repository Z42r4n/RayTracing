#ifndef COLOR_HPP
#define COLOR_HPP

class Color
{
private:
    int create_trgb(int t, int r, int g, int b)
    {
        return (t << 24 | r << 16 | g << 8 | b);
    }

public:
    float rgb[3];

    Color() : rgb{0, 0, 0} {}
    Color(float r, float g, float b) : rgb{r, g, b} {}

    int r() const { return rgb[0]; }
    int g() const { return rgb[1]; }
    int b() const { return rgb[2]; }

    int write_color()
    {
        int res[3];

        res[0] = int(255.999 * rgb[0]);
        res[1] = int(255.999 * rgb[1]);
        res[2] = int(255.999 * rgb[2]);

        return create_trgb(0, res[0], res[1], res[2]);
    }

    // Color operator-() { return Color(-e[0], -e[1], -e[2]); }
    // double operator[](int i) { return e[i]; }
};

#endif // COLOR_HPP