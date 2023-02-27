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

// For more information about the codes used in the keys configuration
// see the pages 53-59 of the document:
//https://www.youtube.com/redirect?event=video_description&redir_token=QUFFLUhqbTFzcEZlMEFaUEpEeHZqMHc5U0wyY2pnYWJnQXxBQ3Jtc0trVUJKSWpmRjh1M1VFUXpldHktUm5ONFZaQ095Mm1nQW0tcHF0ZlB4LWMxelRXYUpqeWJIZ05TZlZPb1pCMUQ5blpDTmpDQW1KZ0dHeEE0blJpYTA1RHM2OE5WRmZzRVllUk1QWUs0X21GRzduM29ncw&q=https%3A%2F%2Fcontrollerstech.com%2Fwp-content%2Fuploads%2F2020%2F09%2Fkeybrd.h&v=tj1_hsQ5PR0 
//------------------------------------
//Left side
//------------------------------------
#define KL_C0_L0 '¨'
#define KL_C0_L1 '¨'
#define KL_C0_L2 '¨'
#define KL_C0_L3 '¨'
#define KL_C0_L4 240//fn

#define KL_C1_L0 0x1e//1 - !
#define KL_C1_L1 0x14//q - Q
#define KL_C1_L2 0x04//a - A
#define KL_C1_L3 0x1d//z -Z
#define KL_C1_L4 239//ctrl

#define KL_C2_L0 0x1f//2 - @
#define KL_C2_L1 0x1a//w - W
#define KL_C2_L2 0x15//r - R
#define KL_C2_L3 0x1b//x - X
#define KL_C2_L4 238//shift

#define KL_C3_L0 0x20//3 - #
#define KL_C3_L1 0x3a//f - F
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
#define KR_C2_L3 0x36//, <
#define KR_C2_L4 232 //gui

#define KR_C3_L0 0x26//9 - (
#define KR_C3_L1 0x1C//y - Y
#define KR_C3_L2 0x49//i - i
#define KR_C3_L3 0x37//. - >
#define KR_C3_L4 234 //shift

#define KR_C4_L0 0x27//0 - )
#define KR_C4_L1 0x33//: - :
#define KR_C4_L2 0xA0//o _ O
#define KR_C4_L3 0x38/// _ ?
#define KR_C4_L4 235//ctrl

#define KR_C5_L0 ' ' 
#define KR_C5_L1 ' ' 
#define KR_C5_L2 ' ' 
#define KR_C5_L3 ' ' 
#define KR_C5_L4 240//fn

//------------------------------------
//Left side SPC
//-----------------------------------
#define KL_C0_L0_SPC '#'
#define KL_C0_L1_SPC '$'
#define KL_C0_L2_SPC '@'
#define KL_C0_L3_SPC '!'
#define KL_C0_L4_SPC 240

#define KL_C1_L0_SPC '1'
#define KL_C1_L1_SPC 'q'
#define KL_C1_L2_SPC 'a'
#define KL_C1_L3_SPC 'z'
#define KL_C1_L4_SPC '*'//

#define KL_C2_L0_SPC '2'
#define KL_C2_L1_SPC 'w'
#define KL_C2_L2_SPC 'r'
#define KL_C2_L3_SPC 'x'
#define KL_C2_L4_SPC ' '

#define KL_C3_L0_SPC '3'
#define KL_C3_L1_SPC 't'
#define KL_C3_L2_SPC 's'
#define KL_C3_L3_SPC 'c'
#define KL_C3_L4_SPC ' '

#define KL_C4_L0_SPC '4'
#define KL_C4_L1_SPC 'p'
#define KL_C4_L2_SPC 'f'
#define KL_C4_L3_SPC 'd'
#define KL_C4_L4_SPC ' '

#define KL_C5_L0_SPC '5'
#define KL_C5_L1_SPC 'b'
#define KL_C5_L2_SPC 'c'
#define KL_C5_L3_SPC 'v'
#define KL_C5_L4_SPC ' '

//--------------_SPC---------------------
//Right side		_SPC
//--------------_SPC---------------------
#define KR_C0_L0_SPC '6'
#define KR_C0_L1_SPC 'j'
#define KR_C0_L2_SPC 'm'
#define KR_C0_L3_SPC 'k'
#define KR_C0_L4_SPC ' '

#define KR_C1_L0_SPC '7'
#define KR_C1_L1_SPC 'l'
#define KR_C1_L2_SPC 'n'
#define KR_C1_L3_SPC 'h'
#define KR_C1_L4_SPC ' '

#define KR_C2_L0_SPC '8'
#define KR_C2_L1_SPC 'u'
#define KR_C2_L2_SPC 'e'
#define KR_C2_L3_SPC ','
#define KR_C2_L4_SPC ' '

#define KR_C3_L0_SPC '9'
#define KR_C3_L1_SPC 'y'
#define KR_C3_L2_SPC 'i'
#define KR_C3_L3_SPC '.'
#define KR_C3_L4_SPC ' '

#define KR_C4_L0_SPC '0'
#define KR_C4_L1_SPC ';'
#define KR_C4_L2_SPC 'o'
#define KR_C4_L3_SPC '/'
#define KR_C4_L4_SPC ' '

#define KR_C5_L0_SPC ' '
#define KR_C5_L1_SPC ' '
#define KR_C5_L2_SPC ' '
#define KR_C5_L3_SPC ' '
#define KR_C5_L4_SPC 240

#endif
