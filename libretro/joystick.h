#ifndef _WINX68K_JOY_H
#define _WINX68K_JOY_H

#include <stdint.h>
#include "common.h"

#define PAD_2BUTTON      0
#define PAD_CPSF_MD      1
#define PAD_CPSF_SFC     2
#define PAD_CYBERSTICK_D 3
#define PAD_CYBERSTICK_A 4

#define	JOY_UP		0x01
#define	JOY_DOWN	0x02
#define	JOY_LEFT	0x04
#define	JOY_RIGHT	0x08
#define	JOY_TRG2	0x20
#define	JOY_TRG1	0x40

#define	JOY_TRG5	0x01
#define	JOY_TRG4	0x02
#define	JOY_TRG3	0x04
#define	JOY_TRG7	0x08
#define	JOY_TRG8	0x20
#define	JOY_TRG6	0x40

/* button combination for start/select button */
#define JOY_SELECT      0x03 /* up + down */
#define JOY_START       0x0c /* left + right */

void Joystick_Init(void);
void Joystick_Cleanup(void);
uint8_t FASTCALL Joystick_Read(uint8_t num);
void FASTCALL Joystick_Write(uint8_t num, uint8_t data);
void FASTCALL Joystick_Update(int is_menu, int key, int port);

uint8_t get_joy_downstate(void);
void reset_joy_downstate(void);

extern uint8_t JoyKeyState;

#endif /* WINX68K_JOY_H */
