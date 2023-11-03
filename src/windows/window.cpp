#include "windows/window.h"
LV_IMG_DECLARE(minimize);
LV_IMG_DECLARE(resize);
LV_IMG_DECLARE(close_img);
bool check(long double n)
{
    if (ceil(n) == floor(n))
        return false;
    else
        return true;
}
window::window(String name, int app_number_)
{
    title = name;
    app_number = app_number_;
}

void window::app_button_setUp()
{
    if (app_number == 0)
    {
        lv_obj_set_x(aplication_button, ((app_width * -1) + app_width / 2) + app_width * app_number + 5*(app_number + 2));
        lv_obj_set_y(aplication_button, ((app_height * -1) + app_height / 2) + 10);
    }
    else
    {
        if (!(app_number % (500 / app_width)))
        {
            lv_obj_set_x(aplication_button, ((app_width * -1) + app_width / 2) + app_width * (app_number - (app_number / u16_t(500 / app_width)) * 10) + 5);
            lv_obj_set_y(aplication_button, ((app_height * -1) + app_height / 2) + (app_height * (app_number / (500 / app_width))) + 5);
        }
        else
        {
            lv_obj_set_x(aplication_button, ((app_width * -1) + app_width / 2) + app_width * (app_number - (app_number / u16_t(500 / app_width)) * 10) + 5*(app_number + 2));
            lv_obj_set_y(aplication_button, ((app_height * -1) + app_height / 2) + 10);
        }
    }
    lv_obj_set_width(aplication_button, app_width);
    lv_obj_set_height(aplication_button, app_height);

    lv_obj_set_width(aplication_button_text, LV_SIZE_CONTENT);
    lv_obj_set_height(aplication_button_text, LV_SIZE_CONTENT);
    lv_obj_set_align(aplication_button_text, LV_ALIGN_CENTER);

    lv_label_set_text(aplication_button_text, title.c_str());
}
// window::toolbar::toolbar()
void window::toolbarSetup()
{
    lv_obj_set_x(toolbar_box, toolbar_x);
    lv_obj_set_y(toolbar_box, toolbar_y);
    lv_obj_set_width(toolbar_box, 800);
    lv_obj_set_height(toolbar_box, toolbar_height);
    lv_obj_set_style_radius(toolbar_box, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_align(toolbar_box, LV_ALIGN_CENTER);
    lv_obj_clear_flag(toolbar_box, LV_OBJ_FLAG_SCROLLABLE);

    // lv_obj_set_x(minimizeButton, 250);
    // lv_obj_set_y(minimizeButton, 0);
    // lv_obj_set_width(minimizeButton, 50);
    // lv_obj_set_height(minimizeButton, 50);
    // lv_obj_set_style_radius(minimizeButton, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_align(minimizeButton, LV_ALIGN_CENTER);
    // lv_obj_clear_flag(minimizeButton, LV_OBJ_FLAG_SCROLLABLE);
    // lv_imgbtn_set_src(minimizeButton, LV_IMGBTN_STATE_RELEASED, NULL, &minimize, NULL);

    setup_btn_set_img(250, 0, 50, 50, minimizeButton, minimize);
    lv_obj_add_event_cb(minimizeButton, event_minimize, LV_EVENT_CLICKED, NULL);

    setup_btn_set_img(300, 0, 50, 50, resizeButton, resize);
    lv_obj_add_event_cb(resizeButton, event_resize, LV_EVENT_CLICKED, NULL);

    setup_btn_set_img(350, 0, 50, 50, closeButton, close_img);
    lv_obj_add_event_cb(closeButton, event_close, LV_EVENT_CLICKED, NULL);

    lv_label_set_text(appText, title.c_str());
    lv_obj_set_style_text_font(appText, &lv_font_montserrat_26, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_width(appText, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(appText, LV_SIZE_CONTENT); /// 1
    Serial.println(LV_SIZE_CONTENT);
    lv_obj_set_y(appText, 0);
    lv_obj_set_align(appText, LV_ALIGN_LEFT_MID);
    _ui_flag_modify(window_box, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
}
void window::setup_btn_set_img(int x, int y, int w, int h, lv_obj_t *obj, const lv_img_dsc_t &src_mid)
{
    lv_obj_set_x(obj, x);
    lv_obj_set_y(obj, y);
    lv_obj_set_width(obj, w);
    lv_obj_set_height(obj, h);
    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_align(obj, LV_ALIGN_CENTER);
    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
    lv_imgbtn_set_src(obj, LV_IMGBTN_STATE_RELEASED, NULL, &src_mid, NULL);
}
void *window::event_close_MY(void)
{
    _ui_flag_modify(window_box, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
    return 0;
}
void window::setup()
{
    lv_obj_set_x(window_box, x);
    lv_obj_set_y(window_box, y);
    lv_obj_set_width(window_box, lv_pct(100));
    lv_obj_set_height(window_box, height);
    lv_obj_set_style_radius(window_box, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_align(window_box, LV_ALIGN_CENTER);
    lv_obj_clear_flag(window_box, LV_OBJ_FLAG_SCROLLABLE); /// Flags
    toolbarSetup();
    app_button_setUp();
}

bool window::button_read(int button)
{
    switch (button)
    {
    case 1:
        return lv_obj_get_state(minimizeButton);
        break;
    case 2:
        return lv_obj_get_state(resizeButton);

        break;
    case 3:
        return lv_obj_get_state(closeButton);
        break;
    case 4:
        return lv_obj_get_state(aplication_button);

    default:
        break;
    }
    return false;
}

void window::loop()
{
    if (button_read(1))
    {
        /* code */
    }
    else if (button_read(2))
    {
        
    }
    else if (button_read(3))
    {
        _ui_flag_modify(window_box, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
    }
    else if (button_read(4)){
        _ui_flag_modify(window_box, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
    
    }
}


void window::event_minimize(lv_event_t *e)
{
    Serial.print("event_minimize");
}
void window::event_resize(lv_event_t *e)
{
    Serial.print("event_resize");
}
void window::event_close(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
}
void window::setup_btn_and_text(lv_obj_t *obj, lv_obj_t *obj_l, int x, int y, int w, int h, const char *text)
{
}