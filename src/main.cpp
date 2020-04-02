#include "mbed.h"
 
// Sensors drivers present in the BSP library
#include "Drivers/BSP/B-L475E-IOT01/stm32l475e_iot01_tsensor.h"
#include "Drivers/BSP/B-L475E-IOT01/stm32l475e_iot01.h"

int main()
{
    float sensor_value = 0;
    int16_t pDataXYZ[3] = {0};
    float pGyroDataXYZ[3] = {0};

    Led_TypeDef led1 = Led_TypeDef::DISCO_LED_GREEN;

    printf("Start sensor init\n");
 
    BSP_TSENSOR_Init();

    BSP_LED_Init(led1);
 
    while(1) {
        sensor_value = BSP_TSENSOR_ReadTemp();
        printf("\nTEMPERATURE = %.2f degC\n", sensor_value);
        
        BSP_LED_Toggle(led1);

        thread_sleep_for(1000);
    }

    
}