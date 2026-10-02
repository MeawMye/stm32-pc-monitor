/*
 * ui.h
 *
 *  Created on: Apr 13, 2026
 *      Author: y6484
 */


/* UI have to "Do NOT know the real data set.
     must access function like GetCpuAt() */
#ifndef INC_UI_H_
#define INC_UI_H_

#include <stdio.h>
#include "graph_history.h"
#include "stm32f769i_discovery_lcd.h"

void UI_DrawCPU(const GraphHistory *history);
void UI_DrawRAM(const GraphHistory *history);
void UI_DrawNet(const GraphHistory *history);
void UI_DrawGraph(const GraphHistory *history);

#endif /* INC_UI_H_ */
