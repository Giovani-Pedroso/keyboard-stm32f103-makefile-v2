#include "usb_send.h"
#include "FreeRTOS.h"
#include "keys_config.h"
#include "projdefs.h"
#include "ssd1306.h"
#include "task.h"
#include "usbd_hid.h"
#include <stdint.h>

int isFunctionPressed = 0;
extern USBD_HandleTypeDef hUsbDeviceFS;

const uint8_t keyboard_keys_left[5][6] = {
    KL_C0_L0, KL_C1_L0, KL_C2_L0, KL_C3_L0, KL_C4_L0, KL_C5_L0,
    KL_C0_L1, KL_C1_L1, KL_C2_L1, KL_C3_L1, KL_C4_L1, KL_C5_L1,
    KL_C0_L2, KL_C1_L2, KL_C2_L2, KL_C3_L2, KL_C4_L2, KL_C5_L2,
    KL_C0_L3, KL_C1_L3, KL_C2_L3, KL_C3_L3, KL_C4_L3, KL_C5_L3,
    KL_C0_L4, KL_C1_L4, KL_C2_L4, KL_C3_L4, KL_C4_L4, KL_C5_L4};

const uint8_t keyboard_keys_right[5][6] = {
    KR_C0_L0, KR_C1_L0, KR_C2_L0, KR_C3_L0, KR_C4_L0, KR_C5_L0,
    KR_C0_L1, KR_C1_L1, KR_C2_L1, KR_C3_L1, KR_C4_L1, KR_C5_L1,
    KR_C0_L2, KR_C1_L2, KR_C2_L2, KR_C3_L2, KR_C4_L2, KR_C5_L2,
    KR_C0_L3, KR_C1_L3, KR_C2_L3, KR_C3_L3, KR_C4_L3, KR_C5_L3,
    KR_C0_L4, KR_C1_L4, KR_C2_L4, KR_C3_L4, KR_C4_L4, KR_C5_L4};

const uint8_t keyboard_keys_left_spc[5][6] = {
    KL_C0_L0_SPC, KL_C1_L0_SPC, KL_C2_L0_SPC, KL_C3_L0_SPC, KL_C4_L0_SPC,
    KL_C5_L0_SPC, KL_C0_L1_SPC, KL_C1_L1_SPC, KL_C2_L1_SPC, KL_C3_L1_SPC,
    KL_C4_L1_SPC, KL_C5_L1_SPC, KL_C0_L2_SPC, KL_C1_L2_SPC, KL_C2_L2_SPC,
    KL_C3_L2_SPC, KL_C4_L2_SPC, KL_C5_L2_SPC, KL_C0_L3_SPC, KL_C1_L3_SPC,
    KL_C2_L3_SPC, KL_C3_L3_SPC, KL_C4_L3_SPC, KL_C5_L3_SPC, KL_C0_L4_SPC,
    KL_C1_L4_SPC, KL_C2_L4_SPC, KL_C3_L4_SPC, KL_C4_L4_SPC, KL_C5_L4_SPC};

const uint8_t keyboard_keys_right_spc[5][6] = {
    KR_C0_L0_SPC, KR_C1_L0_SPC, KR_C2_L0_SPC, KR_C3_L0_SPC, KR_C4_L0_SPC,
    KR_C5_L0_SPC, KR_C0_L1_SPC, KR_C1_L1_SPC, KR_C2_L1_SPC, KR_C3_L1_SPC,
    KR_C4_L1_SPC, KR_C5_L1_SPC, KR_C0_L2_SPC, KR_C1_L2_SPC, KR_C2_L2_SPC,
    KR_C3_L2_SPC, KR_C4_L2_SPC, KR_C5_L2_SPC, KR_C0_L3_SPC, KR_C1_L3_SPC,
    KR_C2_L3_SPC, KR_C3_L3_SPC, KR_C4_L3_SPC, KR_C5_L3_SPC, KR_C0_L4_SPC,
    KR_C1_L4_SPC, KR_C2_L4_SPC, KR_C3_L4_SPC, KR_C4_L4_SPC, KR_C5_L4_SPC};

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

/**
  @brief This function will write the usb command code into
         a buffer that will be send to the usb latter
         @param - keyboardside - the side of the keyboard(l - left; r right)
         @param - column - the column of the key
         @param - row - the row of the key
 */
void usb_send(char keyboarSide, uint8_t column, uint8_t row) {

  // buffer that will store the command to be send
  extern keyboard_command_t keyboard_commands_to_send;

  // variable that will store the code
  uint8_t key = 0;

  // wil checks if the button came from the left side
  if (keyboarSide == 'l') {

    // checks if the button for the special layler was pressed
    if (isFunctionPressed == 0)
      // will pick the code of a key saved a tabel latter this
      // value will be stored in the buffer
      key = keyboard_keys_left[column][row];
    else
      key = keyboard_keys_left_spc[column][row];

    // checks if the key is a special key (shift, controll,
    // GUI aka windowns key, alt)
    if (key >= 232 && key != 240) {
      // Do the bitwise operation to set the modifier key for more info see:
      // pag -
      // of the document:
      keyboard_commands_to_send.modifier_key |= 1 << (key - 232);
      return;
    }
    // if the key pressed was the special layler key
    // will save the state into a variabe to be use latter
    else if (key == 240) {

      isFunctionPressed = !isFunctionPressed;
      key = 0;
    }
  }

  // The same thing that above but this time with the right
  // side of the keyboard
  else if (keyboarSide == 'r') {
    if (isFunctionPressed == 0)
      key = keyboard_keys_right[column][row];
    else
      key = keyboard_keys_right_spc[column][row];

    if (key >= 232 && key != 240) {
      keyboard_commands_to_send.modifier_key |= 1 << (key - 232);
      return;
    } else if (key == 240) {
			if(isFunctionPressed){
				isFunctionPressed = 0;
			} else isFunctionPressed = 1;
      key = 0;
      vTaskDelay(400 / portTICK_PERIOD_MS);
    }
  }

  // Checks if the key pressed is in the buffer
  if (key == keyboard_commands_to_send.keycode_1 ||
      key == keyboard_commands_to_send.keycode_2 ||
      key == keyboard_commands_to_send.keycode_3 ||
      key == keyboard_commands_to_send.keycode_4 ||
      key == keyboard_commands_to_send.keycode_5) {
    return;
  }

  // Add the key to the buffer if there is a space avalible
  if (!keyboard_commands_to_send.keycode_1) {
    keyboard_commands_to_send.keycode_1 = key;
    return;
  } else if (!keyboard_commands_to_send.keycode_2 &&
             key != keyboard_commands_to_send.keycode_2) {
    keyboard_commands_to_send.keycode_2 = key;
    return;
  } else if (!keyboard_commands_to_send.keycode_3) {
    keyboard_commands_to_send.keycode_3 = key;
    return;
  } else if (!keyboard_commands_to_send.keycode_4) {
    keyboard_commands_to_send.keycode_4 = key;
    return;
  } else if (!keyboard_commands_to_send.keycode_5) {
    keyboard_commands_to_send.keycode_5 = key;
    return;
  }
  /* vTaskDelay(10 / portTICK_PERIOD_MS); */
}

void usb_send_clear_keyboard_command(keyboard_command_t *command) {
  command->keycode_1 = 0;
  command->keycode_2 = 0;
  command->keycode_3 = 0;
  command->keycode_4 = 0;
  command->keycode_5 = 0;
  command->modifier_key = 0;
  ssd1306_UpdateScreen();
}

/**
         @brief - will checks periodically the keyboard_commands_to_send
                                 buffer to send the command to the usb
 */
void usb_send_task(void *vParams) {

  extern keyboard_command_t keyboard_commands_to_send;
  static keyboard_command_t previous_comand;
  uint8_t repeatKey = 0;
  uint8_t prevKey = 0;
  uint8_t jump = 0;

  while (1) {
    // Send the command if a key was pressed
    if (keyboard_commands_to_send.keycode_1 ||
        keyboard_commands_to_send.modifier_key) {

      prevKey = keyboard_commands_to_send.keycode_1;
      USBD_HID_SendReport(&hUsbDeviceFS, &keyboard_commands_to_send,
                          sizeof(keyboard_command_t));

      usb_send_clear_keyboard_command(&keyboard_commands_to_send);
      vTaskDelay(60 / portTICK_PERIOD_MS);

      /* while (prevKey == keyboard_commands_to_send.keycode_1) { */
      /* } */
      // Reset the keyboard commands
      /* usb_send_clear_keyboard_command(&keyboard_commands_to_send); */

      USBD_HID_SendReport(&hUsbDeviceFS, &keyboard_commands_to_send,
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
  /* isFunctionPressed = 0; */
}

void usb_send_task_init() {
  xTaskCreate(&usb_send_task, "usb_send_task", USB_SEND_STACK_SIZE, NULL,
              USB_SEND_PRIORITY, NULL);
}
