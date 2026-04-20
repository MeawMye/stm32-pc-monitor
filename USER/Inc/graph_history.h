/*
 * graph_history.h
 *
 *  Created on: Apr 13, 2026
 *      Author: y6484
 */
// .h is Interface, .c is implement.
#ifndef INC_GRAPH_HISTORY_H_
#define INC_GRAPH_HISTORY_H_

#include <stdint.h>
#include <stddef.h>

#define HISTORY_LEN 100

typedef struct
{
  uint8_t cpu[HISTORY_LEN];
  uint8_t ram[HISTORY_LEN];
  uint16_t net[HISTORY_LEN];
  uint16_t head;
  uint16_t count;
} GraphHistory;

void GraphHistory_Init(GraphHistory *history);
void GraphHistory_Push(GraphHistory *history, uint8_t cpu, uint8_t ram, uint16_t net);
uint8_t GraphHistory_GetCpuAt(const GraphHistory *history, uint16_t index);
uint8_t GraphHistory_GetRamAt(const GraphHistory *history, uint16_t index);
uint16_t GraphHistory_GetNetAt(const GraphHistory *history, uint16_t index);


#endif /* INC_GRAPH_HISTORY_H_ */
