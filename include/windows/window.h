#ifndef window_h
#define window_h
#include "main.h"
#include "windows/toolbar/toolbar.h"
#include "windows/window_content/window_content.h"
class window
{
public:
    String tytle;

    lv_obj_t *img_obj = lv_img_create(ui_Screen1);
    lv_obj_t *window_box = lv_obj_create(ui_Screen1);
    int x = 0;
    int y = 50;
    int width = 800;
    int height = 480;
    File icon1;
    class window_content
    {
    public:
        window_content();
    };
    class toolbar
    {
    public:
        toolbar();
    };
    window();
};

#endif