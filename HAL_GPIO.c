#include"HAL_GPIO.h"
#include<stdint.h>



/* 
every pin in the high and low control registers has 4 associated bits
thus th position of every pin is shifted 4 bits this array keeps track 
of how much each pin number has to be shifted to be in th eproper bit
*/

uint32_t PINPOS[16] = {
    (0x00), // pin 0
    (0x04), // pin 1
    (0x08), // pin 2
    (0x0C), // pin 3
    (0x10), // pin 4
    (0x14), // pin 5
    (0x18), // pin 6
    (0x1C), // pin 7
    (0x00), // pin 8
    (0x04), // pin 9
    (0x08), // pin 10
    (0x0C), // pin 11
    (0x10), // pin 12
    (0x14), // pin 13
    (0x18), // pin 14
    (0x1C)  // pin 15
};

// FUNCTIONS-----------------------------------------------------------------------------------------
static void config_pin(GPIO_TypeDef *port, uint32_t pinNumber, uint32_t mode_type)
{
    if (pinNumber >= 8) // CONTROL HIGH REGISTER
    {
        switch(mode_type)
        {
            // OUTPUT and input MODES --------------------
            case OUTPUT_GEN_PURPOSE | INPUT_ANALOG:
                port->CRH &= ~( (1<<CNF_POS_BIT1) | (1<<CNF_POS_BIT2) );
            break; 

            case OUTPUT_OD | INPUT_FLOATING:
                port->CRH &= ~(1<<CNF_POS_BIT2);
                port->CRH |=  (1<<CNF_POS_BIT1);
            break; 

            case OUTPUT_ALT_FUNCTION | INPUT_PU_PD:
                port->CRH |= OUTPUT_ALT_FUNCTION<<(CNF_POS_BIT1);
            break; 

            case OUTPUT_ALT_FUNCTION_OD:
                port->CRH |= OUTPUT_ALT_FUNCTION_OD<<(CNF_POS_BIT1);
            break; 
             
        } // end switch
    } // end if
    else             // CONTROL LOW REGISTER
    {
        // OUTPUT and input MODES --------------------
    	 switch(mode_type)
    	 {
            case OUTPUT_GEN_PURPOSE | INPUT_ANALOG:
                port->CRL &= ~( (1<<CNF_POS_BIT1) | (1<<CNF_POS_BIT2) );
            break; 

            case OUTPUT_OD | INPUT_FLOATING:
                port->CRL &= ~(1<<CNF_POS_BIT2);
                port->CRL |=  (1<<CNF_POS_BIT1);
            break; 

            case OUTPUT_ALT_FUNCTION | INPUT_PU_PD:
                port->CRL |= OUTPUT_ALT_FUNCTION<<(CNF_POS_BIT1);
            break; 

            case OUTPUT_ALT_FUNCTION_OD:
                port->CRL |= OUTPUT_ALT_FUNCTION_OD<<(CNF_POS_BIT1);
            break; 
    	 }
    }
} // end config_pin

//---------------------------------------------------------------------------------------------------

static void config_pin_speed(GPIO_TypeDef *port, uint32_t pinNumber, uint32_t pinSpeed, uint32_t mode)
{
    if (pinNumber >= 8)
    {
        if ( mode == INPUT_MODE)
        {
            port->CRH &= ~(1<<(PINPOS[pinNumber]) | 1<<(PINPOS[pinNumber] + 1));
        }
        else 
        {
            port->CRH |= (pinSpeed<<(PINPOS[pinNumber]));
        }

    }
    else
    {
        if ( mode == INPUT_MODE)
        {
            port->CRL &= ~(1<<(PINPOS[pinNumber]) | 1<<(PINPOS[pinNumber] + 1));
        }
        else 
        {
            port->CRL |= (pinSpeed<<(PINPOS[pinNumber]));
        }
    }
}

//---------------------------------------------------------------------------------------------------


void gpio_write(GPIO_TypeDef *port, uint32_t pinNumber, uint32_t state)
{
	if (state)
	{
		port->BSRR = (1<<pinNumber); // set pin
	}
	else
	{
		port->BSRR = (1<<(pinNumber + 16)); // clear pin
	}
}

//---------------------------------------------------------------------------------------------------

void gpio_toggle(GPIO_TypeDef *port, uint32_t pinNumber)
{
	port->ODR ^= (1<<pinNumber);
}

//---------------------------------------------------------------------------------------------------

void gpio_init(GPIO_TYPE gpio_type)
{
	if (gpio_type.port == PORTA)
	{
		GPIO_CLOCK_ENABLE_PORTA;
	}

	if (gpio_type.port == PORTB)
	{
		GPIO_CLOCK_ENABLE_PORTB;
	}

	if (gpio_type.port == PORTC)
	{
		GPIO_CLOCK_ENABLE_PORTC;
	}

	if (gpio_type.port == PORTD)
	{
		GPIO_CLOCK_ENABLE_PORTD;
	}

	config_pin(gpio_type.port, gpio_type.pin, gpio_type.mode_type);
	config_pin_speed(gpio_type.port, gpio_type.pin,gpio_type.speed, gpio_type.mode);
}
