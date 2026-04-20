

#include "packet_parser.h"

#include <string.h>   // strtok, strcmp
#include <stdlib.h>   // atoi
#include <stdio.h>    // sprintf


#define RX_BUF_SIZE 128


void ParsePacket(char *packet, SystemStatus *status)
{
  char buf[RX_BUF_SIZE];
  char *token;
  char *colon;
  char *key;
  char *value;
  int len;

  strncpy(buf, packet, RX_BUF_SIZE - 1);
  buf[RX_BUF_SIZE - 1] = '\0';

  len = strlen(buf);

  if (len > 0 && buf[0] == '$')
  {
      memmove(buf, buf + 1, len);
  }

  len = strlen(buf);
  if (len > 0 && buf[len - 1] == '#')
  {
      buf[len - 1] = '\0';
  }

  token = strtok(buf, ",");

  while (token != NULL)
  {
      colon = strchr(token, ':');

      if (colon != NULL)
      {
          *colon = '\0';
          key = token;
          value = colon + 1;

          if (strcmp(key, "CPU") == 0)
          {
              status->cpu = atoi(value);
              status->cpu_valid = 1;
          }
          else if (strcmp(key, "RAM") == 0)
          {
              status->ram = atoi(value);
              status->ram_valid = 1;
          }
          else if (strcmp(key, "NET") == 0)
          {
              status->net = atoi(value);
              status->net_valid = 1;
          }
      }

      token = strtok(NULL, ",");
  }
}

void PrintStatus(UART_HandleTypeDef *huart, SystemStatus *status)
{
  char msg[64];
  if (status->cpu_valid)
  {
    sprintf(msg, "CPU=%d ", status->cpu);
    HAL_UART_Transmit(&huart1, (uint8_t*)msg, strlen(msg), 100);
  }

  if (status->ram_valid)
  {
    sprintf(msg, "RAM=%d ", status->ram);
    HAL_UART_Transmit(&huart1, (uint8_t*)msg, strlen(msg), 100);
  }

  if (status->net_valid)
  {
    sprintf(msg, "NET=%d KB/s ", status->net);
    HAL_UART_Transmit(&huart1, (uint8_t*)msg, strlen(msg), 100);
  }

  HAL_UART_Transmit(&huart1, (uint8_t*)"\r\n", 2, 100);
}
