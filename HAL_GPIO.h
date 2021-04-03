#ifndef HAL_GPIO
#define HAL_GPIO

#include"stm32f1xx.h"
//#include"stm32f10x.h"

#define LOW  0
#define HIGH 1

#define PORTA      GPIOA
#define PORTB      GPIOB
#define PORTC      GPIOC
#define PORTD      GPIOD
#define PORTE      GPIOE
#define PORTF      GPIOF
#define PORTG      GPIOG

// PIN MODE
#define OUTPUT_MODE             ((uint32_t) 0x01)
#define INPUT_MODE              ((uint32_t) 0x02)

// clock enabling
#define GPIO_CLOCK_ENABLE_ALT_FUNC  (RCC->APB2ENR |= (1<<0))
#define GPIO_CLOCK_ENABLE_PORTA     (RCC->APB2ENR |= (1<<2))
#define GPIO_CLOCK_ENABLE_PORTB     (RCC->APB2ENR |= (1<<3))
#define GPIO_CLOCK_ENABLE_PORTC     (RCC->APB2ENR |= (1<<4))
#define GPIO_CLOCK_ENABLE_PORTD     (RCC->APB2ENR |= (1<<5))
//#define GPIO_CLOCK_ENABLE_PORTE     (RCC->APB2ENR |= (1<<6))


// INPUT MODE TYPES
#define INPUT_ANALOG            ((uint32_t) 0x00)
#define INPUT_FLOATING          ((uint32_t) 0x01) // defult at reset  
#define INPUT_PU_PD             ((uint32_t) 0x02) // input with pull up or pull down

// OUTPUT MODE TYPES
#define OUTPUT_GEN_PURPOSE      ((uint32_t) 0x00) // general purpose output 
#define OUTPUT_OD               ((uint32_t) 0x01) // output open drain 
#define OUTPUT_ALT_FUNCTION     ((uint32_t) 0x02) // push pull
#define OUTPUT_ALT_FUNCTION_OD  ((uint32_t) 0x03) // open drain 

// PIN SPEED TYPES/ SLEW RATES
#define SPEED_2MHZ              ((uint32_t) 0x02) 
#define SPEED_10MHZ             ((uint32_t) 0x01) 
#define SPEED_50MHZ             ((uint32_t) 0x03) 


// HIGH BIT POSITION FOR CRH REGISTER CONFIG AND MORE
#define CNF_POS_BIT1            (PINPOS[pinNumber] + 2)
#define CNF_POS_BIT2            (PINPOS[pinNumber] + 3)

//configuration structre 
typedef struct 
{
    GPIO_TypeDef *port;

    uint32_t    pin;
    
    uint32_t    mode;

    uint32_t    mode_type;
    
    uint32_t    pull;

    uint32_t    speed;
    
    uint32_t    alt_func;

} GPIO_TYPE;

// functuion prototypes 
//--------------------------------------------------------
//                      GPIO CONFIGURATION
static void config_pin(GPIO_TypeDef *port, uint32_t pinNumber, uint32_t mode_type);
static void config_pin_speed(GPIO_TypeDef *port, uint32_t pinNumber, uint32_t pinSpeed, uint32_t mode);
//
//--------------------------------------------------------
//                      USER FUNCTIONS
void gpio_write(GPIO_TypeDef *port, uint32_t pinNumber, uint32_t state);
void gpio_toggle(GPIO_TypeDef *port, uint32_t pinNumber);
void gpio_init(GPIO_TYPE gpio_type); // initialises clock for port
//
//--------------------------------------------------------
#endif
