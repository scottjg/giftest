#include <stdio.h>
#include <gifski.h>

int main(int argc, char *argv[])
{
    printf("Hello, world!\n");

    gifski *g = gifski_new(&(GifskiSettings){});
    gifski_set_file_output(g, "file.gif");

    for(int i=0; i < 25; i++) {
        char filename[256];
        sprintf(filename, "frame%d.png", i);
        int res = gifski_add_frame_png_file(g, i, filename, i / 10.0);
        if (res != GIFSKI_OK) break;
    }
    int res = gifski_finish(g);
    if (res != GIFSKI_OK) return res;

    return 0;
}