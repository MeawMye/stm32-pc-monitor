/*
 * ui.c
 *
 *  Created on: Apr 13, 2026
 *      Author: y6484
 */

#include "ui.h"

//extern DSI_HandleTypeDef hdsi_discovery;


void UI_DrawCPU(const GraphHistory *history)
{
  int graph_x = 30;
  int graph_y = 100;
  int graph_w = 300;
  int graph_h = 120;
  uint8_t value;

  int i;
  int count;
  int x, y, prev_x, prev_y;

  char buf[20];

  if (history == NULL) return;

  count = history->count;
  if (count < 2) return;

  //value = GraphHistory_GetCpuAt(history, count-1);

  // 제목
  BSP_LCD_SetBackColor(LCD_COLOR_BLACK);
  BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
  BSP_LCD_DisplayStringAt(graph_x, graph_y - 25, (uint8_t *)"CPU", LEFT_MODE);

  // 현재값
  uint8_t latest = GraphHistory_GetCpuAt(history, count - 1);
  sprintf(buf, "%d%%", latest);
  BSP_LCD_DisplayStringAt(graph_x + 60, graph_y - 25, (uint8_t *)buf, LEFT_MODE);


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
   int graph_x = 380;
   int graph_y = 100;
   int graph_w = 300;
   int graph_h = 120;
   uint8_t value;

   int i;
   int count;
   int x, y, prev_x, prev_y;

   char buf[20];

   if (history == NULL) return;

   count = history->count;
   if (count < 2) return;

   //value = GraphHistory_GetCpuAt(history, count-1);

   BSP_LCD_SetBackColor(LCD_COLOR_BLACK);
   BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
   BSP_LCD_DisplayStringAt(graph_x, graph_y - 25, (uint8_t *)"RAM", LEFT_MODE);

   uint8_t latest = GraphHistory_GetRamAt(history, count - 1);
   sprintf(buf, "%d%%", latest);
   BSP_LCD_DisplayStringAt(graph_x + 60, graph_y - 25, (uint8_t *)buf, LEFT_MODE);


   BSP_LCD_SetTextColor(LCD_COLOR_BLACK);
   BSP_LCD_FillRect(graph_x, graph_y, graph_w, graph_h);

   BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
   BSP_LCD_DrawRect(graph_x, graph_y, graph_w, graph_h);

   value = GraphHistory_GetRamAt(history, 0);
   prev_x = graph_x;
   prev_y = graph_y + graph_h - (value*graph_h) / 100;

   BSP_LCD_SetTextColor(LCD_COLOR_CYAN);

   for(i=1; i<count; i++)
   {
     value = GraphHistory_GetRamAt(history, i);

     x = graph_x + (i * graph_w) / (count - 1);
     y = graph_y + graph_h - (value * graph_h) / 100;

     BSP_LCD_DrawLine(prev_x, prev_y, x, y);

     prev_x = x;
     prev_y = y;
   }

}

void UI_DrawNet(const GraphHistory *history)
{
  int graph_x = 30;
  int graph_y = 270;
  int graph_w = 300;
  int graph_h = 120;

  uint16_t value;
  uint16_t latest;
  uint16_t max_net = 1;

  int i;
  int count;
  int x, y, prev_x, prev_y;
  int scaled_h;

  char buf[32];

  if (history == NULL) return;

  count = history->count;
  if (count < 2) return;

  for (i = 0; i < count; i++)
  {
    value = GraphHistory_GetNetAt(history, i);
    if (value > max_net)
    {
      max_net = value;
    }
  }

  BSP_LCD_SetBackColor(LCD_COLOR_BLACK);
  BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
  BSP_LCD_DisplayStringAt(graph_x, graph_y - 25, (uint8_t *)"NET", LEFT_MODE);

  latest = GraphHistory_GetNetAt(history, count - 1);
  sprintf(buf, "%d KB/s", latest);
  BSP_LCD_DisplayStringAt(graph_x + 60, graph_y - 25, (uint8_t *)buf, LEFT_MODE);

  sprintf(buf, "MAX:%d", max_net);
  BSP_LCD_DisplayStringAt(graph_x + 180, graph_y - 25, (uint8_t *)buf, LEFT_MODE);

  BSP_LCD_SetTextColor(LCD_COLOR_BLACK);
  BSP_LCD_FillRect(graph_x, graph_y, graph_w, graph_h);

  BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
  BSP_LCD_DrawRect(graph_x, graph_y, graph_w, graph_h);

  value = GraphHistory_GetNetAt(history, 0);
  scaled_h = ((int)value * graph_h) / max_net;
  if (scaled_h > graph_h)
  {
    scaled_h = graph_h;
  }

  prev_x = graph_x;
  prev_y = graph_y + graph_h - scaled_h;

  BSP_LCD_SetTextColor(LCD_COLOR_DARKYELLOW);

  for (i = 1; i < count; i++)
  {
    value = GraphHistory_GetNetAt(history, i);

    x = graph_x + (i * graph_w) / (count - 1);

    scaled_h = ((int)value * graph_h) / max_net;
    if (scaled_h > graph_h)
    {
      scaled_h = graph_h;
    }

    y = graph_y + graph_h - scaled_h;

    BSP_LCD_DrawLine(prev_x, prev_y, x, y);

    prev_x = x;
    prev_y = y;
  }
}

void UI_DrawGraph(const GraphHistory *history)
{

}
