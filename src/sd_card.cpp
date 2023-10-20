#include "main.h"
#include <vector>
#include "sq_studio/ui.h"
LV_IMG_DECLARE( ui_img_cancel_png);   // assets\refresh (1).png
LV_IMG_DECLARE( ui_img_rsz_correct_png);   // assets\refresh (1).png
#define button_x 200
#define button_w 110
#define button_h 50
String data_name[100];
String data_bool[100];
String file_data_name_str;
lv_obj_t *file_list1[100];
lv_obj_t *file_list_text[100];
lv_obj_t *file_list_btn_Save;
lv_obj_t *file_list_btn_delete;
lv_obj_t *file_list_btn_rename;
lv_obj_t *file_list_btn_create;
lv_obj_t *file_list_btn_Save_lable;
lv_obj_t *file_list_btn_delete_lable;
lv_obj_t *file_list_btn_rename_lable;
lv_obj_t *file_list_btn_create_lable;
lv_obj_t *ui_Panel1;
lv_obj_t *ui_button6;
lv_obj_t *ui_Label3;
lv_obj_t *ui_TextArea1;
lv_obj_t *ui_ImgButton3;
int currnt = 0;
String rootPath = "/root/";

void ui_event_button(lv_event_t *e);
void load_buttons();
void listDir(fs::FS &fs, const char *dirname, uint8_t levels);
void createDir(fs::FS &fs, const char *path);
void removeDir(fs::FS &fs, const char *path);
void readFile(fs::FS &fs, String path);
void writeFile(fs::FS &fs, const char *path, const char *message);
void appendFile(fs::FS &fs, const char *path, const char *message);
void renameFile(fs::FS &fs, const char *path1, const char *path2);
void deleteFile(fs::FS &fs, const char *path);
void testFileIO(fs::FS &fs, const char *path);
void ui_event_button_fileEx(lv_event_t *e);
void ui_event_button_rename(lv_event_t *e);

void sd_card_init()
{
    pinMode(SD_CS, OUTPUT);
    digitalWrite(SD_CS, HIGH);
    SPI.begin(SPI_SCK, SPI_MISO, SPI_MOSI);
    if (!SD.begin(SD_CS, SPI, 1000000))
    {
        Serial.println("SD Card Mount Failed");
    }
    uint8_t cardType = SD.cardType();
    if (cardType == CARD_NONE)
    {
        Serial.println("No SD card attached");
    }
    Serial.print("SD Card Type: ");
    if (cardType == CARD_MMC)
    {
        Serial.println("MMC");
    }
    else if (cardType == CARD_SD)
    {
        Serial.println("SDSC");
    }
    else if (cardType == CARD_SDHC)
    {
        Serial.println("SDHC");
    }
    else
    {
        Serial.println("UNKNOWN");
    }
    uint64_t cardSize = SD.cardSize() / (1024 * 1024);
    Serial.printf("SD Card Size: %lluMB\n", cardSize);
    //listDir(SD, "/root", 0);
}
String openFile(String path)
{

    File file;
    file = SD.open(path, "r");
    return file.readString();
    file.close();
}
String openFileW(String path)
{

    File file;
    file = SD.open(path, "a", true);
    return file.readString();
    file.close();
}

int number = 0;
void list_files()
{

    const char *separator = ",";
    const char *separator1 = ";";
    String file = openFile("/file_list.txt");

    Serial.println(file.indexOf(separator));
    number = file.charAt(0);
    for (int a = 0; a < number; a++)
    {
        String data;
        for (int i = 1; i < file.indexOf(separator); i++)
        {
            data += file.charAt(i);
        }
        data_name[a] = data;
        data = "";
        for (int i = file.indexOf(separator); i < file.indexOf(separator1); i++)
        {
            data += file.charAt(i);
        }
        data_bool[a] = data;
        file.remove(1, file.indexOf(separator1));
    }
}
void load_files()
{
    String file = openFile("/file_list.txt");

    Serial.print(data_name[0]);
    listDir(SD, "/root", 0);
    for (int i = 0; i < number; i++)
    {

        lv_obj_t *file_list_btn_lable;
        if (data_bool[i] == "true")
        {
            file_list1[currnt] = lv_tabview_create(ui_TabView3, LV_DIR_LEFT, 100);
            Serial.print(data_name[i]);
        }
        else
        {
            file_list1[currnt] = lv_tabview_add_tab(ui_TabView3, data_name[i].c_str());
            lv_obj_add_event_cb(ui_TabView3, ui_event_button_fileEx, LV_EVENT_ALL, NULL);
            Serial.print(data_name[i]);
            file_list_text[currnt] = lv_textarea_create(file_list1[currnt]);
            lv_textarea_set_placeholder_text(file_list_text[currnt], data_name[i].c_str());

            String file_patch = "/root/";
            file_patch += data_name[i];
            Serial.print(file_patch);
            readFile(SD, file_patch);
            lv_textarea_set_text(file_list_text[currnt], file_data_name_str.c_str());
            lv_obj_add_event_cb(file_list_text[currnt], ui_event_button, LV_EVENT_ALL, NULL);
            lv_obj_set_width(file_list_text[currnt], 270);
            lv_obj_set_height(file_list_text[currnt], 220);
            lv_obj_set_x(file_list_text[currnt], -52);
            lv_obj_set_y(file_list_text[currnt], 0);
            lv_obj_set_align(file_list_text[currnt], LV_ALIGN_CENTER);
        }
        currnt++;
    }
    lv_obj_add_event_cb(ui_TabView3, ui_event_button_rename, LV_EVENT_LONG_PRESSED_REPEAT, NULL);
    load_buttons();
}
void ui_event_button_fileEx(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_VALUE_CHANGED)
    {
        _ui_flag_modify(ui_Keyboard1, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
        _ui_flag_modify(file_list_btn_Save, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
        _ui_flag_modify(file_list_btn_rename, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
        _ui_flag_modify(file_list_btn_delete, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
    }
}
void ui_event_button(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_CLICKED)
    {

        _ui_keyboard_set_target(ui_Keyboard1, target);
        _ui_flag_modify(ui_Keyboard1, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);

        _ui_flag_modify(file_list_btn_create, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
        _ui_flag_modify(file_list_btn_Save, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
        _ui_flag_modify(file_list_btn_rename, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
        _ui_flag_modify(file_list_btn_delete, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
    }
}
void ui_event_button_save(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_CLICKED)
    {

        Serial.println(lv_textarea_get_text(lv_keyboard_get_textarea(ui_Keyboard1)));
        String file_name = lv_textarea_get_placeholder_text(lv_keyboard_get_textarea(ui_Keyboard1));
        String result = rootPath + file_name;
        writeFile(SD, result.c_str(), lv_textarea_get_text(lv_keyboard_get_textarea(ui_Keyboard1)));
    }
}
void ui_event_button_rename(lv_event_t *e)
{
    lv_label_set_text(ui_Label3, "type the new name");
    _ui_flag_modify(ui_Panel1, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
}
void ui_event_button_rename_close(lv_event_t *e)
{
    _ui_flag_modify(ui_Panel1, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
}

void ui_event_button_rename_comfirm(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    int tabview_number = lv_tabview_get_tab_act(ui_TabView3);

    String file_name = lv_textarea_get_placeholder_text(file_list_text[tabview_number]);
    String file_dir = rootPath + file_name;

    String file_name_new = lv_textarea_get_text(ui_TextArea1);
    String file_dir_new = rootPath + file_name_new;
    lv_tabview_rename_tab(ui_TabView3, tabview_number, file_name_new.c_str());

    data_name[tabview_number] = file_name_new;
    renameFile(SD, file_dir.c_str(), file_dir_new.c_str());

    Serial.print(file_dir_new.c_str());
    _ui_flag_modify(ui_Panel1, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
    lv_textarea_set_text(ui_TextArea1, "");
}

void load_buttons()
{
    file_list_btn_Save = lv_btn_create(ui_Panel5);
    lv_obj_set_width(file_list_btn_Save, button_w);
    lv_obj_set_height(file_list_btn_Save, button_h);
    lv_obj_set_x(file_list_btn_Save, button_x);
    lv_obj_set_y(file_list_btn_Save, 85);
    lv_obj_set_align(file_list_btn_Save, LV_ALIGN_CENTER);
    lv_obj_add_flag(file_list_btn_Save, LV_OBJ_FLAG_SCROLL_ON_FOCUS); /// Flags
    lv_obj_clear_flag(file_list_btn_Save, LV_OBJ_FLAG_SCROLLABLE);    /// Flags
    file_list_btn_Save_lable = lv_label_create(file_list_btn_Save);
    lv_label_set_text(file_list_btn_Save_lable, "save");
    lv_obj_set_x(file_list_btn_Save_lable, 0);
    lv_obj_set_y(file_list_btn_Save_lable, 0);
    lv_obj_add_event_cb(file_list_btn_Save, ui_event_button_save, LV_EVENT_ALL, NULL);

    file_list_btn_delete = lv_btn_create(ui_Panel5);
    lv_obj_set_width(file_list_btn_delete, button_w);
    lv_obj_set_height(file_list_btn_delete, button_h);
    lv_obj_set_x(file_list_btn_delete, button_x);
    lv_obj_set_y(file_list_btn_delete, -27);
    lv_obj_set_align(file_list_btn_delete, LV_ALIGN_CENTER);
    lv_obj_add_flag(file_list_btn_delete, LV_OBJ_FLAG_SCROLL_ON_FOCUS); /// Flags
    lv_obj_clear_flag(file_list_btn_delete, LV_OBJ_FLAG_SCROLLABLE);    /// Flags
    file_list_btn_delete_lable = lv_label_create(file_list_btn_delete);
    lv_label_set_text(file_list_btn_delete_lable, "delete");
    lv_obj_set_x(file_list_btn_delete_lable, 0);
    lv_obj_set_y(file_list_btn_delete_lable, 0);

    file_list_btn_rename = lv_btn_create(ui_Panel5);
    lv_obj_set_width(file_list_btn_rename, button_w);
    lv_obj_set_height(file_list_btn_rename, button_h);
    lv_obj_set_x(file_list_btn_rename, button_x);
    lv_obj_set_y(file_list_btn_rename, 29);
    lv_obj_set_align(file_list_btn_rename, LV_ALIGN_CENTER);
    lv_obj_add_flag(file_list_btn_rename, LV_OBJ_FLAG_SCROLL_ON_FOCUS); /// Flags
    lv_obj_clear_flag(file_list_btn_rename, LV_OBJ_FLAG_SCROLLABLE);    /// Flags
    file_list_btn_rename_lable = lv_label_create(file_list_btn_rename);
    lv_label_set_text(file_list_btn_rename_lable, "rename");
    lv_obj_set_x(file_list_btn_rename_lable, 0);
    lv_obj_set_y(file_list_btn_rename_lable, 0);
    lv_obj_add_event_cb(file_list_btn_rename, ui_event_button_rename, LV_EVENT_CLICKED, NULL);

    file_list_btn_create = lv_btn_create(ui_Panel5);
    lv_obj_set_width(file_list_btn_create, button_w);
    lv_obj_set_height(file_list_btn_create, button_h);
    lv_obj_set_x(file_list_btn_create, button_x);
    lv_obj_set_y(file_list_btn_create, -83);
    lv_obj_set_align(file_list_btn_create, LV_ALIGN_CENTER);
    lv_obj_add_flag(file_list_btn_create, LV_OBJ_FLAG_SCROLL_ON_FOCUS); /// Flags
    lv_obj_clear_flag(file_list_btn_create, LV_OBJ_FLAG_SCROLLABLE);    /// Flags
    file_list_btn_create_lable = lv_label_create(file_list_btn_create);
    lv_label_set_text(file_list_btn_create_lable, "create");
    lv_obj_set_x(file_list_btn_create_lable, 0);
    lv_obj_set_y(file_list_btn_create_lable, 0);

    ui_Panel1 = lv_obj_create(ui_Screen1);
    lv_obj_set_width(ui_Panel1, 189);
    lv_obj_set_height(ui_Panel1, 170);
    lv_obj_set_x(ui_Panel1, 299);
    lv_obj_set_y(ui_Panel1, -103);
    lv_obj_set_align(ui_Panel1, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Panel1, LV_OBJ_FLAG_SCROLLABLE); /// Flags

    ui_button6 = lv_imgbtn_create(ui_Panel1);
    lv_imgbtn_set_src(ui_button6, LV_IMGBTN_STATE_RELEASED, NULL, &ui_img_cancel_png, NULL);
    lv_obj_set_height(ui_button6, 32);
    lv_obj_set_width(ui_button6, LV_SIZE_CONTENT); /// 1
    lv_obj_set_x(ui_button6, 73);
    lv_obj_set_y(ui_button6, -61);
    lv_obj_set_align(ui_button6, LV_ALIGN_CENTER);
    lv_obj_add_event_cb(ui_button6, ui_event_button_rename_close, LV_EVENT_CLICKED, NULL);

    ui_Label3 = lv_label_create(ui_Panel1);
    lv_obj_set_width(ui_Label3, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_Label3, LV_SIZE_CONTENT); /// 1
    lv_obj_set_x(ui_Label3, -21);
    lv_obj_set_y(ui_Label3, -62);
    lv_obj_set_align(ui_Label3, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label3, "type the new name");

    ui_TextArea1 = lv_textarea_create(ui_Panel1);
    lv_obj_set_width(ui_TextArea1, 150);
    lv_obj_set_height(ui_TextArea1, 79);
    lv_obj_set_x(ui_TextArea1, -6);
    lv_obj_set_y(ui_TextArea1, -5);
    lv_obj_set_align(ui_TextArea1, LV_ALIGN_CENTER);
    lv_textarea_set_placeholder_text(ui_TextArea1, "name");
    lv_textarea_set_max_length(ui_Panel1, 32);
    lv_obj_add_event_cb(ui_TextArea1, ui_event_button, LV_EVENT_CLICKED, NULL);

    ui_ImgButton3 = lv_imgbtn_create(ui_Panel1);
    lv_imgbtn_set_src(ui_ImgButton3, LV_IMGBTN_STATE_RELEASED, NULL, &ui_img_rsz_correct_png, NULL);
    lv_obj_set_height(ui_ImgButton3, 35);
    lv_obj_set_width(ui_ImgButton3, LV_SIZE_CONTENT); /// 1
    lv_obj_set_x(ui_ImgButton3, -3);
    lv_obj_set_y(ui_ImgButton3, 61);
    lv_obj_set_align(ui_ImgButton3, LV_ALIGN_CENTER);
    lv_obj_add_event_cb(ui_ImgButton3, ui_event_button_rename_comfirm, LV_EVENT_CLICKED, NULL);

    _ui_flag_modify(file_list_btn_Save, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
    _ui_flag_modify(file_list_btn_rename, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
    _ui_flag_modify(file_list_btn_delete, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
    _ui_flag_modify(ui_Panel1, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
}

void listDir(fs::FS &fs, const char *dirname, uint8_t levels)
{
    int i = 0;
    Serial.printf("Listing directory: %s\n", dirname);
    File root = fs.open(dirname);
    if (!root)
    {
        Serial.println("Failed to open directory");
        return;
    }
    if (!root.isDirectory())
    {
        Serial.println("Not a directory");
        return;
    }
    File file = root.openNextFile();
    while (file)
    {
        if (file.isDirectory())
        {
            Serial.print(" DIR : ");
            Serial.println(file.name());
            data_name[i] = file.name();
            data_bool[i] = true;
            if (levels)
            {
                listDir(fs, file.name(), levels - 1);
            }
            i++;
        }
        else
        {
            Serial.print(" FILE: ");
            data_name[i] = file.name();
            data_bool[i] = false;
            Serial.print(file.name());
            Serial.print(" SIZE: ");
            Serial.println(file.size());
            i++;
        }
        file = root.openNextFile();
    }
    number = i;
}
void createDir(fs::FS &fs, const char *path)
{
    Serial.printf("Creating Dir: %s\n", path);
    if (fs.mkdir(path))
    {
        Serial.println("Dir created");
    }
    else
    {
        Serial.println("mkdir failed");
    }
}
void removeDir(fs::FS &fs, const char *path)
{
    Serial.printf("Removing Dir: %s\n", path);
    if (fs.rmdir(path))
    {
        Serial.println("Dir removed");
    }
    else
    {
        Serial.println("rmdir failed");
    }
}
void readFile(fs::FS &fs, const String path)
{
    Serial.printf("Reading file: %s\n", path);
    File file = fs.open(path, "r");
    if (!file)
    {
        Serial.println("Failed to open file for reading");
        return;
    }
    Serial.print("Read from file: ");
    //while (file.available())
    //{
    //}
    file_data_name_str = file.readString();
    Serial.println("done");
}
void writeFile(fs::FS &fs, const char *path, const char *message)
{
    Serial.printf("Writing file: %s\n", path);
    File file = fs.open(path, FILE_WRITE);
    if (!file)
    {
        Serial.println("Failed to open file for writing");
        return;
    }
    if (file.print(message))
    {
        Serial.println("File written");
    }
    else
    {
        Serial.println("Write failed");
    }
    file.close();
}
void appendFile(fs::FS &fs, const char *path, const char *message)
{
    Serial.printf("Appending to file: %s\n", path);
    File file = fs.open(path, FILE_APPEND);
    if (!file)
    {
        Serial.println("Failed to open file for appending");
        return;
    }
    if (file.print(message))
    {
        Serial.println("Message appended");
    }
    else
    {
        Serial.println("Append failed");
    }
    file.close();
}
void renameFile(fs::FS &fs, const char *path1, const char *path2)
{
    Serial.printf("Renaming file %s to %s\n", path1, path2);
    if (fs.rename(path1, path2))
    {
        Serial.println("File renamed");
    }
    else
    {
        Serial.println("Rename failed");
    }
}
void deleteFile(fs::FS &fs, const char *path)
{
    Serial.printf("Deleting file: %s\n", path);
    if (fs.remove(path))
    {
        Serial.println("File deleted");
    }
    else
    {
        Serial.println("Delete failed");
    }
}
void testFileIO(fs::FS &fs, const char *path)
{
    File file = fs.open(path);
    static uint8_t buf[512];
    size_t len = 0;
    uint32_t start = millis();
    uint32_t end = start;
    if (file)
    {
        len = file.size();
        size_t flen = len;
        start = millis();
        while (len)
        {
            size_t toRead = len;
            if (toRead > 512)
            {
                toRead = 512;
            }
            file.read(buf, toRead);
            len -= toRead;
        }
        end = millis() - start;
        Serial.printf("%u bytes read for %u ms\n", flen, end);
        file.close();
    }
    else
    {
        Serial.println("Failed to open file for reading");
    }

    file = fs.open(path, FILE_WRITE);
    if (!file)
    {
        Serial.println("Failed to open file for writing");
        return;
    }
    size_t i;
    start = millis();
    for (i = 0; i < 2048; i++)
    {
        file.write(buf, 512);
    }
    end = millis() - start;
    Serial.printf("%u bytes written for %u ms\n", 2048 * 512, end);
    file.close();
}
