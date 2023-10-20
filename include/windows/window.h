#ifndef window_h
#define window_h
#include "main.h"
#include "windows/toolbar/toolbar.h"
#include "windows/window_content/window_content.h"
#define minimum(a, b) (((a) < (b)) ? (a) : (b))
#ifndef LV_ATTRIBUTE_MEM_ALIGN
#define LV_ATTRIBUTE_MEM_ALIGN
#endif

class window
{
public:
    String tytle;
    ////////////////////////////////WINDOWBOX////////////////////////////////
    lv_obj_t *window_box = lv_obj_create(ui_Screen1);

    int x = 0;
    int y = 25;
    int width = lv_pct(100);
    int height = 430;
    bool decoded;
    File icon1;
    File image;
    ////////////////////////////////TOOLBAR ////////////////////////////////
    lv_obj_t *toolbar_box = lv_obj_create(window_box);
    lv_obj_t *minimizeButton = lv_imgbtn_create(toolbar_box);
    lv_obj_t *resizeButton = lv_imgbtn_create(toolbar_box);
    lv_obj_t *closeButton = lv_imgbtn_create(toolbar_box);
    lv_obj_t *appText = lv_label_create(toolbar_box);
    void toolbarSetup();
    void setup_btn_set_img(int x, int y, int w, int h, lv_obj_t *obj, const lv_img_dsc_t &src_mid);
    void setup_btn_and_text(lv_obj_t *obj, lv_obj_t *obj_l, int x, int y, int w, int h, const char *text);
    static void event_minimize( lv_event_t * e);
    static void event_resize( lv_event_t * e);
    void* event_close( lv_event_t * e);
    void* event_close_MY(void);
    
    String title = "test";
    
    
    int toolbar_x = 0;
    int toolbar_y = -189;
    int toolbar_width = 800;
    int toolbar_height = 50;

    // class window_content
    //{
    // public:
    //     window_content();
    // };
    // class toolbar
    //{
    // public:

    // toolbar();
    //};
    window();
};

#endif