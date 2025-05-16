/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
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
#include "lvgl.h"
#include "screens.h"
#include "SLM_App.h"
#include "app_can.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */

/* USER CODE END Variables */
/* Definitions for lvgl_meter */
osThreadId_t lvgl_meterHandle;
const osThreadAttr_t lvgl_meter_attributes = {
  .name = "lvgl_meter",
  .stack_size = 512 * 4,
  .priority = (osPriority_t) osPriorityLow,
};
/* Definitions for lvgl */
osThreadId_t lvglHandle;
const osThreadAttr_t lvgl_attributes = {
  .name = "lvgl",
  .stack_size = 1024 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};
/* Definitions for ws2812b */
osThreadId_t ws2812bHandle;
const osThreadAttr_t ws2812b_attributes = {
  .name = "ws2812b",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityLow,
};
/* Definitions for lvgl_mutex */
osMutexId_t lvgl_mutexHandle;
const osMutexAttr_t lvgl_mutex_attributes = {
  .name = "lvgl_mutex"
};
/* Definitions for Upld_data_event */
osEventFlagsId_t Upld_data_eventHandle;
const osEventFlagsAttr_t Upld_data_event_attributes = {
  .name = "Upld_data_event"
};

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

void entry_lvgl_meter(void *argument);
void entry_lvgl(void *argument);
void entry_ws2812b(void *argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */

  /* USER CODE END Init */
  /* Create the mutex(es) */
  /* creation of lvgl_mutex */
  lvgl_mutexHandle = osMutexNew(&lvgl_mutex_attributes);

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
  /* creation of lvgl_meter */
  lvgl_meterHandle = osThreadNew(entry_lvgl_meter, NULL, &lvgl_meter_attributes);

  /* creation of lvgl */
  lvglHandle = osThreadNew(entry_lvgl, NULL, &lvgl_attributes);

  /* creation of ws2812b */
  ws2812bHandle = osThreadNew(entry_ws2812b, NULL, &ws2812b_attributes);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

  /* creation of Upld_data_event */
  Upld_data_eventHandle = osEventFlagsNew(&Upld_data_event_attributes);

  /* USER CODE BEGIN RTOS_EVENTS */
  /* add events, ... */
  /* USER CODE END RTOS_EVENTS */

}

/* USER CODE BEGIN Header_entry_lvgl_meter */
/**
  * @brief  Function implementing the lvgl_meter thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_entry_lvgl_meter */
void entry_lvgl_meter(void *argument)
{
  /* USER CODE BEGIN entry_lvgl_meter */
  uint32_t r_event;
  /* Infinite loop */
  for(;;)
  {
      r_event = osEventFlagsWait(Upld_data_eventHandle,GUI_UPDATE_EVENT,osFlagsWaitAll,osWaitForever);
      osMutexWait(lvgl_mutexHandle, osWaitForever);
      if(r_event) {
          lv_label_set_text_fmt(objects.speed,"%02d",racingCarData.FrontSpeed);
          //lv_label_set_text_fmt(objects.speed,"%02d",racingCarData.Lap);
          lv_label_set_text_fmt(objects.mcu1_temp,"%02d",racingCarData.l_mcu_temp);
          lv_label_set_text_fmt(objects.mcu2_temp,"%02d",racingCarData.r_mcu_temp);
          lv_label_set_text_fmt(objects.speed,"%motor1_temp",racingCarData.l_motor_temp);
          lv_label_set_text_fmt(objects.speed,"%motor2_temp",racingCarData.r_motor_temp);
          //lv_label_set_text_fmt(objects.speed,"%02d",racingCarData.FrontSpeed);
          //lv_label_set_text_fmt(objects.speed,"%02d",racingCarData.FrontSpeed);

          lv_bar_set_value(objects.soc,racingCarData.BatSoc,LV_ANIM_OFF);

          if(racingCarData.l_motor_rpm <= 2000){
              lv_arc_set_value(objects.l_rpm,(int32_t)(racingCarData.l_motor_rpm*1.65));
              lv_image_set_rotation(objects.l_rpm_pt_photo,(int32_t)(racingCarData.r_motor_rpm*0.25));
          }
          else{
              lv_arc_set_value(objects.l_rpm,(int32_t)(racingCarData.l_motor_rpm*0.8+1700));
              lv_image_set_rotation(objects.l_rpm_pt_photo,(int32_t)(racingCarData.r_motor_rpm*0.127+246));
          }
          if(racingCarData.r_motor_rpm <= 2000){
              lv_arc_set_value(objects.r_rpm,(int32_t)(racingCarData.l_motor_rpm*1.65));
              lv_image_set_rotation(objects.l_rpm_pt_photo,(int32_t)(racingCarData.r_motor_rpm*0.25));
          }
          else{
              lv_arc_set_value(objects.r_rpm,(int32_t)(racingCarData.l_motor_rpm*0.8+1700));
              lv_image_set_rotation(objects.l_rpm_pt_photo,(int32_t)(racingCarData.r_motor_rpm*0.127+ 246));
          }

          if(racingCarData.gearMode == 0){
              lv_label_set_text(objects.gear, "N");
          }
          else if(racingCarData.gearMode == 1){
              lv_label_set_text(objects.gear, "AC");
          }
          else if(racingCarData.gearMode == 2){
              lv_label_set_text(objects.gear, "SK");
          }
          else if(racingCarData.gearMode == 3){
              lv_label_set_text(objects.gear,"AU");
          }
          else if(racingCarData.gearMode == 4){
              lv_label_set_text(objects.gear,"EF");
          }
      }
      osMutexRelease(lvgl_mutexHandle);
      osDelay(50);
  }
  /* USER CODE END entry_lvgl_meter */
}

/* USER CODE BEGIN Header_entry_lvgl */
/**
* @brief Function implementing the lvgl thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_entry_lvgl */
void entry_lvgl(void *argument)
{
  /* USER CODE BEGIN entry_lvgl */
  /* Infinite loop */
  for(;;)
  {
      osMutexWait(lvgl_mutexHandle, osWaitForever);
      uint32_t time_till_next = lv_timer_handler();
      if(time_till_next == LV_NO_TIMER_READY) time_till_next = LV_DEF_REFR_PERIOD; /*try again soon because the other thread can make the timer ready*/
      osMutexRelease(lvgl_mutexHandle);
      osDelay(time_till_next); /* delay to avoid unnecessary polling */
  }
  /* USER CODE END entry_lvgl */
}

/* USER CODE BEGIN Header_entry_ws2812b */
/**
* @brief Function implementing the ws2812b thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_entry_ws2812b */
void entry_ws2812b(void *argument)
{
  /* USER CODE BEGIN entry_ws2812b */
    CanFilter_init();
    uint32_t r_event;
  /* Infinite loop */
  for(;;)
  {
      r_event = osEventFlagsWait(Upld_data_eventHandle,GUI_UPDATE_EVENT,osFlagsWaitAll,osWaitForever);
      if(r_event) {
          RPM_LED_Shine();
      }
  }
  /* USER CODE END entry_ws2812b */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

/* USER CODE END Application */

