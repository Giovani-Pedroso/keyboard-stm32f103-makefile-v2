#ifndef KEYS_CONFIG_H_
#define KEYS_CONFIG_H_

//Use this values to configure an special key
// 232 - right gui - aka win button or super
// 233 - right alt
// 234 - right shift
// 235 - right ctrl
// 236 - left gui 
// 237 - left alt
// 238 - left shift
// 239 - left  ctrl

//240 - alt function layer

// For more information about the codes that you can used in the keys configuration
// see the pages 88-94 of the document:
// https://usb.org/sites/default/files/hut1_3_0.pdf
// //------------------------------------
//Left side
//------------------------------------
#define KL_C0_L0 0x34//`- ~ 
#define KL_C0_L1 0x2B//tab
#define KL_C0_L2 0x39//caps-lock
#define KL_C0_L3 0x31//\ and |
#define KL_C0_L4 240//fn

#define KL_C1_L0 0x1E//1 - !
#define KL_C1_L1 0x14//q - Q
#define KL_C1_L2 0x04//a - A
#define KL_C1_L3 0x1D//z -Z
#define KL_C1_L4 239//ctrl

#define KL_C2_L0 0x1F//2 - @
#define KL_C2_L1 0x1a//w - W
#define KL_C2_L2 0x15//r - R
#define KL_C2_L3 0x1b//x - X
#define KL_C2_L4 238//shift

#define KL_C3_L0 0x20//3 - #
#define KL_C3_L1 0x09//f - F
#define KL_C3_L2 0x16//s- S
#define KL_C3_L3 0x06//c - C
#define KL_C3_L4 236//gui

#define KL_C4_L0 0x21//4 - $
#define KL_C4_L1 0x13//p - P
#define KL_C4_L2 0x17//t - T
#define KL_C4_L3 0x07//d - d
#define KL_C4_L4  237//alt

#define KL_C5_L0 0x22//5 - %
#define KL_C5_L1 0x05//b - B
#define KL_C5_L2 0x0a//g - G
#define KL_C5_L3 0x19//v - V
#define KL_C5_L4 0x2C//space bar

//------------------------------------
//Right side
//------------------------------------
#define KR_C0_L0 0x23//6 - "
#define KR_C0_L1 0x0D//j - J
#define KR_C0_L2 0x10//m - M
#define KR_C0_L3 0x0E//k - K
#define KR_C0_L4 0x2C//space bar

#define KR_C1_L0 0x24//7 - &
#define KR_C1_L1 0x0F//l - L
#define KR_C1_L2 0x11//n - N
#define KR_C1_L3 0x0B//h - H
#define KR_C1_L4 233//alt

#define KR_C2_L0 0x25//8 - *
#define KR_C2_L1 0x18//u - U
#define KR_C2_L2 0x08//e - E
#define KR_C2_L3 0x36//, - <   
#define KR_C2_L4 232 //gui

#define KR_C3_L0 0x26//9 - (
#define KR_C3_L1 0x1C//y - Y
#define KR_C3_L2 0x0C//i - I 
#define KR_C3_L3 0x37//. - >
#define KR_C3_L4 234 //shift

#define KR_C4_L0 0x27//0 - )
#define KR_C4_L1 0x33//: - :
#define KR_C4_L2 0x12//o _ O 
#define KR_C4_L3 0x38/// _ ?
#define KR_C4_L4 235//ctrl

#define KR_C5_L0 0x2A//backspace 
#define KR_C5_L1 0x28//enter
#define KR_C5_L2 0x4C//delete
#define KR_C5_L3 0x35//` - ~ 
#define KR_C5_L4 240//fn

//------------------------------------
//Left side SPC
//-----------------------------------
#define KL_C0_L0_SPC 0x29//esc
#define KL_C0_L1_SPC KL_C0_L1
#define KL_C0_L2_SPC KL_C0_L2
#define KL_C0_L3_SPC KL_C0_L3
#define KL_C0_L4_SPC KL_C0_L4

#define KL_C1_L0_SPC 0x3A//f1
#define KL_C1_L1_SPC KL_C1_L1
#define KL_C1_L2_SPC KL_C1_L2
#define KL_C1_L3_SPC KL_C1_L3
#define KL_C1_L4_SPC KL_C1_L4//

#define KL_C2_L0_SPC 0x3B//f2
#define KL_C2_L1_SPC KL_C2_L1
#define KL_C2_L2_SPC KL_C2_L2
#define KL_C2_L3_SPC KL_C2_L3
#define KL_C2_L4_SPC KL_C2_L4

#define KL_C3_L0_SPC 0x3C//f3
#define KL_C3_L1_SPC KL_C3_L1
#define KL_C3_L2_SPC KL_C3_L2
#define KL_C3_L3_SPC KL_C3_L3
#define KL_C3_L4_SPC KL_C3_L4

#define KL_C4_L0_SPC 0x3D//f4
#define KL_C4_L1_SPC KL_C4_L1
#define KL_C4_L2_SPC KL_C4_L2
#define KL_C4_L3_SPC KL_C4_L3
#define KL_C4_L4_SPC KL_C4_L4

#define KL_C5_L0_SPC 0x3E//f5
#define KL_C5_L1_SPC KL_C5_L1
#define KL_C5_L2_SPC KL_C5_L2
#define KL_C5_L3_SPC KL_C5_L3
#define KL_C5_L4_SPC KL_C5_L4

//--------------_SPC---------------------
//Right side		_SPC
//--------------_SPC---------------------
#define KR_C0_L0_SPC 0x3F//f6
#define KR_C0_L1_SPC KR_C0_L1
#define KR_C0_L2_SPC 0x4A//Home 
#define KR_C0_L3_SPC KR_C0_L3
#define KR_C0_L4_SPC KR_C0_L4

#define KR_C1_L0_SPC 0x40//f7
#define KR_C1_L1_SPC 0x2F//[ - {
#define KR_C1_L2_SPC 0x50//left arrow
#define KR_C1_L3_SPC KR_C1_L3
#define KR_C1_L4_SPC KR_C1_L4

#define KR_C2_L0_SPC 0x41//f8
#define KR_C2_L1_SPC 0x2D//- - _
#define KR_C2_L2_SPC 0x51//down arrow
#define KR_C2_L3_SPC 0x4E//page down
#define KR_C2_L4_SPC KR_C2_L4

#define KR_C3_L0_SPC 0x42//f9
#define KR_C3_L1_SPC 0x2E//= - +
#define KR_C3_L2_SPC 0x52//up arrow
#define KR_C3_L3_SPC 0x4B//page up
#define KR_C3_L4_SPC KR_C3_L4

#define KR_C4_L0_SPC 0x43//f10
#define KR_C4_L1_SPC 0x30//] - }
#define KR_C4_L2_SPC 0x4F//right
#define KR_C4_L3_SPC KR_C4_L3
#define KR_C4_L4_SPC KR_C4_L4

#define KR_C5_L0_SPC 0x44//f11
#define KR_C5_L1_SPC 0x45//f12
#define KR_C5_L2_SPC 0x4D//End
#define KR_C5_L3_SPC KR_C5_L3
#define KR_C5_L4_SPC KR_C5_L4

#endif
