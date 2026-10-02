/*
 * graph_history.c
 *
 *  Created on: Apr 13, 2026
 *      Author: y6484
 */


#include "graph_history.h"


void GraphHistory_Init(GraphHistory *history)
{
  if(history ==  NULL) return;

  history->head = 0;
  history->count =0;

  int i;

  for(i=0; i< HISTORY_LEN; i++)
  {
    history->cpu[i] =0;
    history->ram[i] =0;
    history->net[i] =0;
  }

}

/* head is next write position. when buffer is FULL,
                 head is the oldest data position.
   example) index = 0 -> the oldest value
            index = count -1 -> the newest value */
void GraphHistory_Push(GraphHistory *history, uint8_t cpu, uint8_t ram, uint16_t net)
{
  history->cpu[history->head] = cpu;
  history->ram[history->head] = ram;
  history->net[history->head] = net;

  history->head = (history->head + 1) % HISTORY_LEN;

  if (history->count < HISTORY_LEN)
  {
      history->count++;
  }
}

uint8_t GraphHistory_GetCpuAt(const GraphHistory *history, uint16_t index)
{
  uint16_t real_index;

  if(history == NULL) return 0;
  if(index >= history->count) return 0;

  if(history->count < HISTORY_LEN)
  {
    return history->cpu[index];
  }
  else
  {
    real_index = (history->head + index) % HISTORY_LEN;
    return history->cpu[real_index];
  }
}

uint8_t GraphHistory_GetRamAt(const GraphHistory *history, uint16_t index)
{
  uint16_t real_index;

  if(history == NULL) return 0;
  if(index >= history->count) return 0;

  if(history->count < HISTORY_LEN)
  {
    return history->ram[index];
  }
  else
  {
    real_index = (history->head + index) % HISTORY_LEN;
    return history->ram[real_index];
  }
}

uint16_t GraphHistory_GetNetAt(const GraphHistory *history, uint16_t index)
{
  uint16_t real_index;

  if(history == NULL) return 0;
  if(index >= history->count) return 0;

  if(history->count < HISTORY_LEN)
  {
    return history->net[index];
  }
  else
  {
    real_index = (history->head + index) % HISTORY_LEN;
    return history->net[real_index];
  }
}
