# STM32F103C8T6_FreeRTOS
Porting the FreeRTOS embedded operating system to STM32F103C8T6 Micro Control Unit!

利用keil自带模拟仿真调试器可以看到两个线程跑起来
![Snipaste_2024-05-09_22-56-05](https://github.com/0x59950/STM32F103C8T6_FreeRTOS/assets/54783648/e99b65da-0d65-4fde-9195-aa1a5747b20e)

可以看到两个线程每隔200ms分别对变量i和c进行取反和自增1

![Snipaste_2024-05-09_22-55-21](https://github.com/0x59950/STM32F103C8T6_FreeRTOS/assets/54783648/240995f4-8652-4d7d-be50-102923fbf34a)
