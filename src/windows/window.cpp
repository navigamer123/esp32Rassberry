#include "windows/window.h"

window::window()
{
    lv_img_set_src(img_obj, "sd/icons/04.png");
    lv_obj_set_x(window_box, x);
    lv_obj_set_y(window_box, y);
    lv_obj_set_width(window_box,width);
    lv_obj_set_height(window_box,height);
    lv_obj_set_style_bg_img_src(window_box,&img_obj,LV_PART_MAIN | LV_STATE_DEFAULT);
    icon1 = SD.open("04.jpeg")
    //_ui_flag_modify(window_box,LV_OBJ_FLAG_HIDDEN,_UI_MODIFY_FLAG_ADD);
}
window::window_content window_content()
{
}
window::toolbar::toolbar()
{
}