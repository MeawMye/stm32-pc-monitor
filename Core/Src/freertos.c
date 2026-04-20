/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <string.h>
#include <stdio.h>
#include "packet_parser.h"
#include "usart.h"
#include "ui.h"

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define RX_BUF_SIZE 128
#define COMM_PACKET_READY_SIGNAL  (0x01)
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */
extern uint8_t rxByte;
extern char rxPacketBuf[RX_BUF_SIZE];
extern char rxWorkedBuf[RX_BUF_SIZE];
extern HAL_StatusTypeDef ret;
extern SystemStatus systemStatus;
extern volatile uint16_t rxIndex;

extern DSI_HandleTypeDef hdsi_discovery;
extern GraphHistory graphHistory;
//extern volatile uint8_t packet_ready;

extern char msg[64];

/* USER CODE END Variables */
osThreadId defaultTaskHandle;
osThreadId CommTaskHandle;
osThreadId uiTaskHandle;

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */
extern void LCD_UI_Update(SystemStatus *status);
/* USER CODE END FunctionPrototypes */

void StartDefaultTask(void const * argument);
void StartCommTask(void const * argument);
void StartUI_Task(void const * argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/* GetIdleTaskMemory prototype (linked to static allocation support) */
void vApplicationGetIdleTaskMemory( StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize );

/* USER CODE BEGIN GET_IDLE_TASK_MEMORY */
static StaticTask_t xIdleTaskTCBBuffer;
static StackType_t xIdleStack[configMINIMAL_STACK_SIZE];

void vApplicationGetIdleTaskMemory( StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize )
{
  *ppxIdleTaskTCBBuffer = &xIdleTaskTCBBuffer;
  *ppxIdleTaskStackBuffer = &xIdleStack[0];
  *pulIdleTaskStackSize = configMINIMAL_STACK_SIZE;
  /* place for user code */
}
/* USER CODE END GET_IDLE_TASK_MEMORY */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* definition and creation of defaultTask */
  osThreadDef(defaultTask, StartDefaultTask, osPriorityNormal, 0, 512);
  defaultTaskHandle = osThreadCreate(osThread(defaultTask), NULL);

  /* definition and creation of CommTask */
  osThreadDef(CommTask, StartCommTask, osPriorityNormal, 0, 512);
  CommTaskHandle = osThreadCreate(osThread(CommTask), NULL);

  /* definition and creation of uiTask */
  osThreadDef(uiTask, StartUI_Task, osPriorityIdle, 0, 512);
  uiTaskHandle = osThreadCreate(osThread(uiTask), NULL);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

}

/* USER CODE BEGIN Header_StartDefaultTask */
/**
  * @brief  Function implementing the defaultTask thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_StartDefaultTask */
void StartDefaultTask(void const * argument)
{
  /* USER CODE BEGIN StartDefaultTask */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END StartDefaultTask */
}

/* USER CODE BEGIN Header_StartCommTask */
/**
* @brief Function implementing the CommTask thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartCommTask */
void StartCommTask(void const * argument)
{
  /* USER CODE BEGIN StartCommTask */
  /* Infinite loop */
  for(;;)
  {
    osSignalWait(0x01, osWaitForever);

    systemStatus.cpu_valid = 0;
    systemStatus.ram_valid = 0;
    systemStatus.net_valid = 0;

    printf("PACKET = %s\r\n", rxPacketBuf);
    ParsePacket(rxPacketBuf, &systemStatus);
    PrintStatus(&huart1, &systemStatus);

    // test code
    GraphHistory_Push(&graphHistory, systemStatus.cpu, systemStatus.ram, systemStatus.net);
    UI_DrawCPU(&graphHistory);
    UI_DrawRAM(&graphHistory);
    UI_DrawNet(&graphHistory);

    HAL_DSI_Refresh(&hdsi_discovery);

    osDelay(1);
  }
  /* USER CODE END StartCommTask */
}

/* USER CODE BEGIN Header_StartUI_Task */
/**
* @brief Function implementing the uiTask thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartUI_Task */
void StartUI_Task(void const * argument)
{
  /* USER CODE BEGIN StartUI_Task */

  /* Infinite loop */
  for(;;)
  {
    osSignalWait(0x01, osWaitForever);

    LCD_UI_Update(&systemStatus);

    osDelay(200);
  }
  /* USER CODE END StartUI_Task */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

/* USER CODE END Application */

