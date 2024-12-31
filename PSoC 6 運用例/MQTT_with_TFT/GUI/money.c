/*********************************************************************
*            (c) 1998 - 2024 SEGGER Microcontroller GmbH             *
*        Solutions for real time microcontroller applications        *
*                           www.segger.com                           *
**********************************************************************
*                                                                    *
* C-file generated by                                                *
*                                                                    *
*        Bitmap Converter for emWin (Demo version) V6.42.            *
*        Compiled Jun  7 2024, 12:26:27                              *
*                                                                    *
*        (c) 1998 - 2024 SEGGER Microcontroller GmbH                 *
*                                                                    *
*        May not be used in a product                                *
*                                                                    *
**********************************************************************
*                                                                    *
* Source file: money                                                 *
* Dimensions:  30 * 30                                               *
* NumColors:   16bpp: 65536                                          *
* NumBytes:    1820                                                  *
*                                                                    *
**********************************************************************
*/

#include <stdlib.h>

#include "GUI.h"

#ifndef GUI_CONST_STORAGE
  #define GUI_CONST_STORAGE const
#endif

GUI_CONST_STORAGE unsigned short monkey[] = {
  0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE,
  0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE,
  0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE,
  0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xEF9D, 0xE75C, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE,
  0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF79E, 0xF7BE, 0xF7BE, 0xF79E, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xCE79, 0x8C51, 0xF7BE, 0xF7BE, 0xF7BE, 0xF79E, 0xF79E, 0xF7BE, 0xF7BE, 0xF7BE, 0xF79E, 0xF7BE, 0xF7BE, 0xF79E, 0xF7BE, 0xF7BE,
  0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF79E, 0xDEDB, 0xF79E, 0xC638, 0x738E, 0xF79E, 0xE71C, 0xE73C, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE,
  0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xEF5D, 0x738E, 0xDF1B, 0xC638, 0x738E, 0xF7BE, 0x9CF3, 0xA514, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE,
  0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF79E, 0xF7BE, 0xF7BE, 0xF79E, 0xF7BE, 0xF7BE, 0xF7BE, 0xE75C, 0x738E, 0xDF1B, 0xCE79, 0x8410, 0xF7DE, 0x9CF3, 0xA534, 0xF7BE, 0xF79E, 0xF7BE, 0xF7BE, 0xF7BE, 0xF79E, 0xF7BE, 0xF7BE, 0xF79E, 0xF7BE, 0xF7BE,
  0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xDEFB, 0xDEFB, 0xBDD7, 0xA534, 0xCE99, 0xDEFB, 0xE73C, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE,
  0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xEF7D, 0x9CD3, 0x632C, 0x73AE, 0x8410, 0x6B4D, 0x738E, 0xC638, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE,
  0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xEF7D, 0x8410, 0x7BEF, 0xDEDB, 0xE73C, 0xCE79, 0xEF7D, 0xB5B6, 0x5AEB, 0xBDD7, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE,
  0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xA554, 0x7BCF, 0xEF9D, 0xEF7D, 0x8410, 0x4A49, 0xBE17, 0xF7DE, 0xC638, 0x630C, 0xE71C, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE,
  0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF79E, 0xF7BE, 0xF7BE, 0xF79E, 0xF7BE, 0xEF7D, 0x6B4D, 0xCE59, 0xFFDF, 0xB5B6, 0x6B6D, 0xB596, 0x73AE, 0xEF7D, 0xF7BE, 0x8410, 0xAD55, 0xF7DE, 0xF7BE, 0xF7BE, 0xF79E, 0xF7BE, 0xF7BE, 0xF79E, 0xF7BE, 0xF7BE,
  0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xDEFB, 0x6B2D, 0xE75C, 0xF7BE, 0xCE59, 0x630C, 0xA514, 0xC638, 0xF79E, 0xF7DE, 0xAD55, 0x8C51, 0xF7DE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE,
  0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xDEFB, 0x6B4D, 0xE75C, 0xF7BE, 0xE73C, 0xB596, 0x7BEF, 0x7BEF, 0xF79E, 0xF7DE, 0xAD75, 0x8430, 0xF7DE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE,
  0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF79E, 0xF7BE, 0xF7BE, 0xF79E, 0xF7BE, 0xEF7D, 0x6B4D, 0xCE99, 0xF7DE, 0xBDF7, 0x7BEF, 0xB5B6, 0x632C, 0xEF7D, 0xF7DE, 0x8430, 0xA534, 0xF7DE, 0xF7BE, 0xF7BE, 0xF79E, 0xF7BE, 0xF7BE, 0xF79E, 0xF7BE, 0xF7BE,
  0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0x9CF3, 0x8410, 0xF79E, 0xEF5D, 0x7BCF, 0x4A49, 0xBDF7, 0xF7DE, 0xCE99, 0x630C, 0xDEFB, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE,
  0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7DE, 0xF7DE, 0xF7BE, 0xF7BE, 0xE75C, 0x73AE, 0x8C71, 0xE73C, 0xE73C, 0xCE59, 0xF7BE, 0xC638, 0x630C, 0xAD75, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE,
  0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xD6BA, 0xAD75, 0xB596, 0xBE17, 0xEF7D, 0xF79E, 0xDEFB, 0x8C51, 0x6B4D, 0x8410, 0x8C71, 0x73AE, 0x6B2D, 0xB5B6, 0xF79E, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE,
  0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0x8C51, 0x630C, 0x8430, 0x4A49, 0x73AE, 0x738E, 0x6B6D, 0x7BEF, 0x9CD3, 0xA514, 0xA514, 0xBDD7, 0xE73C, 0xF7DE, 0xF7BE, 0xF7BE, 0xF7BE, 0xDF1B, 0xDEFB, 0xF79E, 0xF7BE, 0xF7BE, 0xF79E, 0xF7BE, 0xF7BE,
  0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0x8430, 0xB5B6, 0xF7DE, 0x6B4D, 0x7BEF, 0xCE59, 0xD69A, 0xB596, 0x73AE, 0x6B4D, 0x6B6D, 0x6B6D, 0x738E, 0x94B2, 0xE73C, 0xD69A, 0x8C51, 0x6B4D, 0x5ACB, 0x9CF3, 0xF7BE, 0xF7BE, 0xF79E, 0xF7BE, 0xF7BE,
  0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0x7BEF, 0xB5D6, 0xF7BE, 0x738E, 0xCE99, 0xF7DE, 0xF7BE, 0xF7DE, 0xF79E, 0xDEDB, 0xCE59, 0xCE59, 0xC638, 0x7BCF, 0x52AA, 0x6B4D, 0x9CD3, 0xA534, 0x5ACB, 0x9CD3, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE,
  0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0x7BCF, 0xBDD7, 0xF79E, 0x6B6D, 0xD69A, 0xF7DE, 0xF7BE, 0xF7BE, 0xF7BE, 0xD69A, 0x738E, 0x6B4D, 0x6B6D, 0x5AEB, 0x630C, 0xCE79, 0x8C51, 0x6B4D, 0xC618, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE,
  0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0x73AE, 0xC618, 0xF79E, 0x6B4D, 0xBDF7, 0xCE79, 0xE71C, 0xF7BE, 0xF7DE, 0xF79E, 0xDF1B, 0xDEDB, 0xDEDB, 0xD69A, 0xA514, 0x632C, 0x94B2, 0xE73C, 0xF7DE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE,
  0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF79E, 0x738E, 0xAD75, 0xD6BA, 0x4A69, 0x5AAB, 0x6B6D, 0x632C, 0x7BCF, 0xA534, 0xD69A, 0xEF5D, 0xEF7D, 0xD6BA, 0x7BEF, 0x6B6D, 0xCE59, 0xF7BE, 0xF7BE, 0xF7BE, 0xF79E, 0xF7BE, 0xF7BE, 0xF79E, 0xF7BE, 0xF7BE,
  0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0x94B2, 0x630C, 0x632C, 0x630C, 0xD69A, 0xEF9D, 0xDEFB, 0xB5B6, 0x8C51, 0x6B4D, 0x6B4D, 0x6B4D, 0x6B2D, 0x9D13, 0xEF5D, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE,
  0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF79E, 0xEF7D, 0xE75C, 0xEF7D, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xEF5D, 0xD6BA, 0xD6BA, 0xE75C, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE,
  0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF79E, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF79E, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF79E, 0xF79E, 0xF7BE, 0xF7BE, 0xF7BE, 0xF79E, 0xF7BE, 0xF7BE, 0xF79E, 0xF7BE, 0xF7BE,
  0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE,
  0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE, 0xF7BE
};
/*************************** End of file ****************************/
