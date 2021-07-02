#ifndef HAL_GPIO
#define HAL_GPIO

#include <stdbool.h>
#include"stm32f1xx.h" // CUBEIDE
//#include"stm32f10x.h" // KEIL

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
#define SPEED_INPUT				((uint32_t) 0x00)
#define SPEED_2MHZ              ((uint32_t) 0x02) 
#define SPEED_10MHZ             ((uint32_t) 0x01) 
#define SPEED_50MHZ             ((uint32_t) 0x03) 


// HIGH BIT POSITION FOR CRH REGISTER CONFIG AND MORE
#define CNF_POS_BIT1            (PINPOS[pinNumber] + 2)
#define CNF_POS_BIT2            (PINPOS[pinNumber] + 3)

//configuration structure
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


typedef enum
{
	RISING_EDGE,
	FALLING_EDGE,
	RISING_FALLING_EDGE
}edge_select;


// 						function prototypes
//--------------------------------------------------------
//                      GPIO CONFIGURATION
void config_pin(GPIO_TypeDef *port, uint32_t pinNumber, uint32_t mode_type);
void config_pin_speed(GPIO_TypeDef *port, uint32_t pinNumber, uint32_t pinSpeed, uint32_t mode);
//
//--------------------------------------------------------
//                      USER FUNCTIONS
void gpio_write(GPIO_TypeDef *port, uint32_t pinNumber, uint32_t state);
bool gpio_read(GPIO_TypeDef *port, uint32_t pinNumber);
void gpio_toggle(GPIO_TypeDef *port, uint32_t pinNumber);
void gpio_init(GPIO_TYPE gpio_type); // initialises clock for port
//
//--------------------------------------------------------
//                    INTERRUPT FUNCTIONS
void configure_gpio_interrupt(GPIO_TypeDef *port, uint32_t pinNumber, edge_select edge);
void enable_gpio_interrupt(uint32_t pinNumber, IRQn_Type irqNumber);
void clear_gpio_interrupt(uint32_t pinNumber);
//
//--------------------------------------------------------















/*--------------------------------------------------------
 * 							DEMO CODE
 *
 *	  // OUTPUTS
 *    GPIO_TYPE myGPIO; // decalre name for gpio structure first
 *
 *    // next step is to initialise the structure containing all the information for the pin
	  myGPIO.port = PORTB;
	  myGPIO.pin = 8;
	  myGPIO.mode = OUTPUT_MODE;
	  myGPIO.mode_type = OUTPUT_GEN_PURPOSE;
	  myGPIO.speed = SPEED_50MHZ;


	 // pass structure to gpio_init function to initialise the port and clock
  	 gpio_init(myGPIO);

  	 // functions gpuo_toggle and gpio write can then be used like so
     gpio_toggle(PORTB,8);

     gpio_write(PORTB, 8, HIGH); // set pin high
     // or
     gpio_write(PORTB, 8, LOW); // set pun low




      // INPUTS
      GPIO_TYPE myGPIO; // decalre name for gpio structure first

      // next step is to initialise the structure containing all the information for the pin
	  myGPIO.port = PORTB;
	  myGPIO.pin = 8;
	  myGPIO.mode = INPUT_MODE;
	  myGPIO.mode_type = SPEED_INPUT;

	 // pass structure to gpio_init function to initialise the port and clock
  	 gpio_init(myGPIO);

	 gpio_read(PORTB, 8); // set pin high



	// interrupt initialisation and enable
	 *
	configure_gpio_interrupt(PORTB, 4, RISING_EDGE);
	enable_gpio_interrupt(4, EXTI4_IRQn); // find IRQn number in stm32f1xx.h depending on pin chosen and edge type


	// interrupt function to go at end of file

	 void EXTI4_IRQHandler()
	 {
	 	 clear_gpio_interrupt(4); // first thing to do in interrupt function
		// do stuff
	 }



 *
 */
#endif
