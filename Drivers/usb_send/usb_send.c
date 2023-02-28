#include "usb_send.h"
#include "FreeRTOS.h"
#include "keys_config.h"
#include "projdefs.h"
#include "ssd1306.h"
#include "task.h"
#include "usbd_hid.h"
#include <stdint.h>

/* extern QueueHandle_t usb_send_queue; */
int isFunctionPressed = 0;
extern USBD_HandleTypeDef hUsbDeviceFS;

const uint8_t keyboard_keys_left[5][6] = {
    KL_C0_L0, KL_C1_L0, KL_C2_L0, KL_C3_L0, KL_C4_L0, KL_C5_L0, KL_C0_L1,
    KL_C1_L1, KL_C2_L1, KL_C3_L1, KL_C4_L1, KL_C5_L1, KL_C0_L2, KL_C1_L2,
    KL_C2_L2, KL_C3_L2, KL_C4_L2, KL_C5_L2, KL_C0_L3, KL_C1_L3, KL_C2_L3,
    KL_C3_L3, KL_C4_L3, KL_C5_L3, KL_C0_L4, KL_C1_L4, KL_C2_L4, KL_C3_L4,
    KL_C4_L4, KL_C5_L4
    /* KL_C0_L2, KL_C1_L2, KL_C2_L2, KL_C3_L2, KL_C4_L2, KL_C5_L2, */
};

const uint8_t keyboard_keys_right[5][6] = {
    KR_C0_L0, KR_C1_L0, KR_C2_L0, KR_C3_L0, KR_C4_L0, KR_C5_L0, KR_C0_L1,
    KR_C1_L1, KR_C2_L1, KR_C3_L1, KR_C4_L1, KR_C5_L1, KR_C0_L2, KR_C1_L2,
    KR_C2_L2, KR_C3_L2, KR_C4_L2, KR_C5_L2, KR_C0_L3, KR_C1_L3, KR_C2_L3,
    KR_C3_L3, KR_C4_L3, KR_C5_L3, KR_C0_L4, KR_C1_L4, KR_C2_L4, KR_C3_L4,
    KR_C4_L4, KR_C5_L4
    /* KL_C0_L2, KL_C1_L2, KL_C2_L2, KL_C3_L2, KL_C4_L2, KL_C5_L2, */
};

const uint8_t keyboard_keys_left_spc[5][6] = {
    KL_C0_L0_SPC, KL_C1_L0_SPC, KL_C2_L0_SPC, KL_C3_L0_SPC,
    KL_C4_L0_SPC, KL_C5_L0_SPC, KL_C0_L1_SPC, KL_C1_L1_SPC,
    KL_C2_L1_SPC, KL_C3_L1_SPC, KL_C4_L1_SPC, KL_C5_L1_SPC,
    KL_C0_L2_SPC, KL_C1_L2_SPC, KL_C2_L2_SPC, KL_C3_L2_SPC,
    KL_C4_L2_SPC, KL_C5_L2_SPC, KL_C0_L3_SPC, KL_C1_L3_SPC,
    KL_C2_L3_SPC, KL_C3_L3_SPC, KL_C4_L3_SPC, KL_C5_L3_SPC,
    KL_C0_L4_SPC, KL_C1_L4_SPC, KL_C2_L4_SPC, KL_C3_L4_SPC,
    KL_C4_L4_SPC, KL_C5_L4_SPC
    /* KL_C0_L2, KL_C1_L2, KL_C2_L2, KL_C3_L2, KL_C4_L2, KL_C5_L2, */
};

const uint8_t keyboard_keys_right_spc[5][6] = {
    KR_C0_L0_SPC, KR_C1_L0_SPC, KR_C2_L0_SPC, KR_C3_L0_SPC, KR_C4_L0_SPC,
    KR_C5_L0_SPC, KR_C0_L1_SPC, KR_C1_L1_SPC, KR_C2_L1_SPC, KR_C3_L1_SPC,
    KR_C4_L1_SPC, KR_C5_L1_SPC, KR_C0_L2_SPC, KR_C1_L2_SPC, KR_C2_L2_SPC,
    KR_C3_L2_SPC, KR_C4_L2_SPC, KR_C5_L2_SPC, KR_C0_L3_SPC, KR_C1_L3_SPC,
    KR_C2_L3_SPC, KR_C3_L3_SPC, KR_C4_L3_SPC, KR_C5_L3_SPC, KR_C0_L4_SPC,
    KR_C1_L4_SPC, KR_C2_L4_SPC, KR_C3_L4_SPC, KR_C4_L4_SPC, KR_C5_L4_SPC};

char test_keys[7] = {'0', '1', '2', '3', '4', '5', '6'};
/**
 * @breif - will write in the oled display the oring of the press
 * @parms - keyboard - the side of the keyboard
 * @parms - column - the column of the button
 * @parms - row - the row of the button
 * */
void usb_sender_test(char keyboardSide, uint8_t column, uint8_t row) {
  const char test_chars[6] = {'0', '1', '2', '3', '4', '5'};

  ssd1306_Fill(Black);
  ssd1306_SetCursor(0, 0);
  ssd1306_WriteString("K-", Font_7x10, White);
  ssd1306_WriteChar(keyboardSide, Font_7x10, White);
  ssd1306_WriteString(" Row-", Font_7x10, White);
  ssd1306_WriteChar(test_chars[row], Font_7x10, White);
  ssd1306_WriteString(" Col-", Font_7x10, White);
  ssd1306_WriteChar(test_chars[column], Font_7x10, White);
  ssd1306_UpdateScreen();

  vTaskDelay(400 / portTICK_PERIOD_MS);
  ssd1306_Fill(Black);
  ssd1306_UpdateScreen();
}

// This will that a command then saves it into a buffer
void usb_send(char keyboarSide, uint8_t column, uint8_t row) {
  /* usb_sender_test(keyboarSide, test_keys[column], test_keys[row]); */
  extern keyboard_command_t keyboar_commands;
  uint8_t key = 0;
  // usb_sender_test(keyboarSide, column, row);
  if (keyboarSide == 'l') {
    if (isFunctionPressed == 0)
      key = keyboard_keys_left[column][row];
    else
      key = keyboard_keys_left_spc[column][row];

    if (key >= 232 && key != 240) {
      // Do the bitwise operation to set the modifier key for more info see:
      //  pag -
      keyboar_commands.modifier_key |= 1 << (key - 232);
      return;
    } else if (key == 240) {
      isFunctionPressed = 1;
      key = 0;
    }
  } else if (keyboarSide == 'r') {
    if (isFunctionPressed == 0)
      key = keyboard_keys_right[column][row];
    else
      key = keyboard_keys_right_spc[column][row];

    if (key >= 232 && key != 240) {
      keyboar_commands.modifier_key |= 1 << (key - 232);
      return;
    } else if (key == 240) {
      isFunctionPressed = 1;
      key = 0;
    }
  }

  // Checks if the key pressed is in the strunct
  if (key == keyboar_commands.keycode_1 || key == keyboar_commands.keycode_2 ||
      key == keyboar_commands.keycode_3 || key == keyboar_commands.keycode_4 ||
      key == keyboar_commands.keycode_5) {
    return;
  }

  // Add the key to the struct if there is a space avalible
  if (!keyboar_commands.keycode_1) {
    keyboar_commands.keycode_1 = key;
    return;
  } else if (!keyboar_commands.keycode_2 && key != keyboar_commands.keycode_2) {
    keyboar_commands.keycode_2 = key;
    return;
  } else if (!keyboar_commands.keycode_3) {
    keyboar_commands.keycode_3 = key;
    return;
  } else if (!keyboar_commands.keycode_4) {
    keyboar_commands.keycode_4 = key;
    return;
  } else if (!keyboar_commands.keycode_5) {
    keyboar_commands.keycode_5 = key;
    return;
  }
  /* vTaskDelay(10 / portTICK_PERIOD_MS); */
}

void usb_send_task(void *vParams) {

  extern keyboard_command_t keyboar_commands;
  static keyboard_command_t previous_comand;
  uint8_t repeatKey = 0;
  uint8_t prevKey = 0;
  uint8_t jump = 0;

  while (1) {
    jump = 0;
    // Send the command if a key was pressed
    if (keyboar_commands.keycode_1 || keyboar_commands.modifier_key) {

      /*
if (repeatKey == 0 && prevKey == keyboar_commands.keycode_1) {
for (uint8_t i = 0; i < 200; i++) {
if (!keyboar_commands.keycode_1) {
jump = 1;
}
if (prevKey != keyboar_commands.keycode_1)
break;
vTaskDelay(5 / portTICK_PERIOD_MS);
}
repeatKey = 1;
}

if (jump)
continue;
      */
      prevKey = keyboar_commands.keycode_1;
      USBD_HID_SendReport(&hUsbDeviceFS, &keyboar_commands,
                          sizeof(keyboard_command_t));

      vTaskDelay(30 / portTICK_PERIOD_MS);
      // Reset the keyboard commands
      keyboar_commands.keycode_1 = 0;
      keyboar_commands.keycode_2 = 0;
      keyboar_commands.keycode_3 = 0;
      keyboar_commands.keycode_4 = 0;
      keyboar_commands.keycode_5 = 0;
      keyboar_commands.modifier_key = 0;
      isFunctionPressed = 0;

      USBD_HID_SendReport(&hUsbDeviceFS, &keyboar_commands,
                          sizeof(keyboard_command_t));
      vTaskDelay(10 / portTICK_PERIOD_MS);
      /* vTaskDelay(200 / portTICK_PERIOD_MS); */
      /* ssd1306_Fill(Black); */
      /* ssd1306_UpdateScreen(); */
    } else {
      repeatKey = 0;
    }
    vTaskDelay(10 / portTICK_PERIOD_MS);
  }
}

void usb_send_task_init() {
  xTaskCreate(&usb_send_task, "usb_send_task", USB_SEND_STACK_SIZE, NULL,
              USB_SEND_PRIORITY, NULL);
}
