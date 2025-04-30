
#ifndef INC_STM32F446XX_GPIO_DRIVER_H_
#define INC_STM32F446XX_GPIO_DRIVER_H_

#include "stm32f446xx.h"



// Structure to configure a GPIO pin
typedef struct {
    uint8_t GPIO_PinNumber;        // GPIO pin number
    uint8_t GPIO_PinMode;          // GPIO pin mode (Input, Output, Alternate, Analog)
    uint8_t GPIO_PinSpeed;         // GPIO pin speed (Low, Medium, High, Very High)
    uint8_t GPIO_PinPuPdControl;   // GPIO pin pull-up/pull-down configuration
    uint8_t GPIO_PinOPType;        // GPIO pin output type (Push-pull or Open-drain)
    uint8_t GPIO_PinAltFunMode;    // GPIO pin alternate function mode
} GPIO_PinConfig_t;

/*
 * This is a handle structure for a GPIO pin
 * It holds the base address of the GPIO port to which the pin belongs,
 * as well as the pin configuration settings.
 */
// handle structure

typedef struct {
    GPIO_RegDef_t *pGPIOx;         // Pointer to GPIO port base address
    GPIO_PinConfig_t GPIO_PinConfig; // GPIO pin configuration settings
} GPIO_Handle_t;

// GPIO Initialization and De-initialization
void GPIO_Init(GPIO_Handle_t *pGPIOHandle); // Initialize the GPIO pin
void GPIO_DeInit(GPIO_RegDef_t *pGPIOx);   // Reset the GPIO port

// Data Read and Write
uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber); // Read data from a specific GPIO pin
uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx);                  // Read data from the entire GPIO port
void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t Value); // Write data to a specific GPIO pin
void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx, uint16_t Value);                  // Write data to the entire GPIO port
void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);                 // Toggle the output state of a GPIO pin

// IRQ Configuration and ISR Handling
void GPIO_IRQConfig(uint8_t IRQNumber, uint8_t IRQPriority, uint8_t EnOrDis); // Configure GPIO interrupt
void GPIO_IRQHandling(uint8_t PinNumber);                                    // Handle GPIO interrupt for a specific pin

