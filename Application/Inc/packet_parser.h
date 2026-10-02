/*
 * packet_parser.h
 *
 *  Created on: Mar 29, 2026
 *      Author: y6484
 */

#ifndef PACKET_PARSER_H_
#define PACKET_PARSER_H_

#include <stdint.h>
#include "usart.h"

typedef struct
{

  int cpu;
  int ram;
  int net;

  uint8_t cpu_valid;
  uint8_t ram_valid;
  uint8_t net_valid;

} SystemStatus;


void ParsePacket(char *packet, SystemStatus *status);
void PrintStatus(UART_HandleTypeDef *huart, SystemStatus *status);

#endif /* PACKET_PARSER_H_ */
