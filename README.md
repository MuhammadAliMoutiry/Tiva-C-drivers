 ># Tiva C drivers 
#### This is a project in which I built Tiva C micro controller ( *ARM_CORTEX M4*) device drivers.
---
## Project Module Files :

>Each Module contains 5 file 
- > **Module_config.h :** 
    - *This file contains the prebuild configurations for a certain module.*
- > **Module_private.h**
    - *This file contains the private functions and preprocessors for the module.*
- > **Module_interface.h**
    - *This files contains the functions prototypes.*
- > **Module_reg.h**
    - *This file contains the registers addresses.*
- > **Module_program.c**
    - *This file contains the functions definitions.*

---
## Project Architecutre Layer :

01. > **LIB** 
   *: This layer Contains Common libraries to all Modules.*
    - ***01- STD_TYPES***
        - STD_TYPES.h
    - ***02- BIT_MATH***
        - BIT_MATH.h
02. > **MCAL**
    *: This layer conains  the device drivers of all the Micro controller peripherals.*
    - ***01- SYSCTRL***
        - SYSCTRL_config.h
        - SYSCTRL_interface.h
        - SYSCTRL_private.h
        - SYSCTRL_reg.h
        - SYSCTRL_program.c
    - 02- ***GPIO***
        - GPIO_config.h
        - GPIO_interface.h
        - GPIO_private.h
        - GPIO_reg.h
        - GPIO_program.c
    - 03- ***NVIC***
        - NVIC_config.h
        - NVIC_interface.h
        - NVIC_private.h
        - NVIC_reg.h
        - NVIC_program.c 
    - 04- ***SYSTICK***
        - SYSTICK_config.h
        - SYSTICK_interface.h
        - SYSTICK_private.h
        - SYSTICK_reg.h
        - SYSTICK_program.c
03. > **HAL**
    *:This layer contains the device drivers for any electronic component.*
04. > **SL**
    *: This layer contains the services provided by this drivers.*
    - NVIC_interruptHandler.c
    - NVIC_interruptHandler.h
05. > **APP**