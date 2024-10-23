#include <iostream>
extern "C"
{
#include <mlx.h>
}

// #include <stdio.h>

typedef struct s_data
{
    void *img;
    char *addr;
    int bits_per_pixel;
    int line_length;
    int endian;
} t_data;


void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int *)dst = color;
}

int create_trgb(int t, int r, int g, int b)
{
    return (t << 24 | r << 16 | g << 8 | b);
}

int main()
{

    // Image

    int image_width = 500;
    int image_height = 400;

    // Render

    void *mlx;
    void *mlx_win;
    t_data img;
    // const char *window_title = "RT Project";

    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, image_width, image_height, (char *)"RT Project");
    img.img = mlx_new_image(mlx, image_width, image_height);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
                                 &img.endian);
    for (int y = 0; y < image_height; y++)
    {
        std::clog << "\rScan lines " << image_height - 1 << ' ';
        for (int x = 0; x < image_width; x++)
        {
            auto r = double(x) / (image_width - 1);
            auto g = double(y) / (image_height - 1);
            auto b = 0.0;

            int ir = int(255.999 * r);
            int ig = int(255.999 * g);
            int ib = int(255.999 * b);
            my_mlx_pixel_put(&img, x, y, create_trgb(0, ir, ig, ib));
        }
    }
    std::clog << "\rDone.            \n";
    mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
    mlx_loop(mlx);
}
