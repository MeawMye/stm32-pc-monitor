/*
 * ui.c
 *
 *  Created on: Apr 13, 2026
 *      Author: y6484
 */

#include "ui.h"


void UI_DrawCPU(const GraphHistory *history)
{
  int graph_x =30;
  int graph_y = 100;
  int graph_w = 320;
  int graph_h = 120;
  uint8_t value;

  int i;
  int count;
  int x, y, prev_x, prev_y;

  if (history == NULL) return;

  count = history->count;
  if (count < 2) return;

  //value = GraphHistory_GetCpuAt(history, count-1);

  BSP_LCD_SetTextColor(LCD_COLOR_BLACK);
  BSP_LCD_FillRect(graph_x, graph_y, graph_w, graph_h);

  BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
  BSP_LCD_DrawRect(graph_x, graph_y, graph_w, graph_h);

  value = GraphHistory_GetCpuAt(history, 0);
  prev_x = graph_x;
  prev_y = graph_y + graph_h - (value*graph_h) / 100;

  BSP_LCD_SetTextColor(LCD_COLOR_GREEN);

  for(i=1; i<count; i++)
  {
    value = GraphHistory_GetCpuAt(history, i);

    x = graph_x + (i * graph_w) / (count - 1);
    y = graph_y + graph_h - (value * graph_h) / 100;

    BSP_LCD_DrawLine(prev_x, prev_y, x, y);

    prev_x = x;
    prev_y = y;
  }

}

void UI_DrawRAM(const GraphHistory *history)
{

}

void UI_DrawGraph(const GraphHistory *history)
{

}
