/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : Cpu.c
**     Project   : TWR_S12G240_FreeRTOS
**     Processor : MC9S12G240CLL
**     Component : MC9S12G240_100
**     Version   : Component 01.000, Driver 02.06, CPU db: 3.00.010
**     Datasheet : MC9S12GRMV1 Rev. 0.50 March 4, 2011
**     Compiler  : CodeWarrior HC12 C Compiler
**     Date/Time : 04.09.2018, 20:29
**     Abstract  :
**         This component "MC9S12G240_100" implements properties, methods,
**         and events of the CPU.
**     Settings  :
**
**     Contents  :
**         EnableInt   - void Cpu_EnableInt(void);
**         DisableInt  - void Cpu_DisableInt(void);
**         SetWaitMode - void Cpu_SetWaitMode(void);
**         SetStopMode - void Cpu_SetStopMode(void);
**
**     Copyright : 1997 - 2011 Freescale Semiconductor, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/

/* MODULE Cpu. */

#include "FRTOS1.h"
#include "RTOSSWI1.h"
#include "TickCntr1.h"
#include "MCUC1.h"
#include "UTIL1.h"
#include "LED1.h"
#include "LEDpin1.h"
#include "LED2.h"
#include "LEDpin2.h"
#include "LED3.h"
#include "LEDpin3.h"
#include "LED4.h"
#include "LEDpin4.h"
#include "Events.h"
#include "Cpu.h"

#define CGM_DELAY  0x02FFU

#pragma DATA_SEG DEFAULT               /* Select data segment "DEFAULT" */
#pragma CODE_SEG DEFAULT


/* Global variables */
volatile byte CCR_reg;                 /* Current CCR reegister */
#pragma CODE_SEG __NEAR_SEG NON_BANKED


/*
** ===================================================================
**     Method      :  Cpu_Cpu_Interrupt (component MC9S12G240_100)
**
**     Description :
**         The method services unhandled interrupt vectors.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
ISR(Cpu_Interrupt)
{
  /*lint -save -e950 Disable MISRA rule (1.1) checking. */
  asm(BGND);
  /*lint -restore Enable MISRA rule (1.1) checking. */
}


#pragma CODE_SEG DEFAULT

/*
** ===================================================================
**     Method      :  Cpu_DisableInt (component MC9S12G240_100)
**
**     Description :
**         Disable maskable interrupts
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
/*
void Cpu_DisableInt(void)

**      This method is implemented as macro in the header module. **
*/

/*
** ===================================================================
**     Method      :  Cpu_EnableInt (component MC9S12G240_100)
**
**     Description :
**         Enable maskable interrupts
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
/*
void Cpu_EnableInt(void)

**      This method is implemented as macro in the header module. **
*/

/*
** ===================================================================
**     Method      :  Cpu_SetStopMode (component MC9S12G240_100)
**
**     Description :
**         Set low power mode - Stop mode.
**         For more information about the stop mode see
**         documentation of this CPU.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
/*
void Cpu_SetStopMode(void)

**      This method is implemented as macro in the header module. **
*/

/*
** ===================================================================
**     Method      :  Cpu_SetWaitMode (component MC9S12G240_100)
**
**     Description :
**         Set low power mode - Wait mode.
**         For more information about the wait mode see
**         documentation of this CPU.
**         Release from Wait mode: Reset or interrupt
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
/*
void Cpu_SetWaitMode(void)

**      This method is implemented as macro in the header module. **
*/

/*
** ===================================================================
**     Method      :  _EntryPoint (component MC9S12G240_100)
**
**     Description :
**         Initializes the whole system like timing and so on. At the end 
**         of this function, the C startup is invoked to initialize stack,
**         memory areas and so on.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
extern void _Startup(void);            /* Forward declaration of external startup function declared in file Start12.c */

/*** !!! Here you can place your own code using property "User data declarations" on the build options tab of the CPU component. !!! ***/


#pragma CODE_SEG __NEAR_SEG NON_BANKED


#pragma NO_FRAME                       /* Suppress generation of frame code */
#pragma NO_EXIT                        /* Suppress generation of exit from a function */
void _EntryPoint(void)
{

  /*** !!! Here you can place your own code using property "User code before PE initialization" on the build options tab of the CPU compoennt. !!! ***/

  /* ### MC9S12G240_100 "Cpu" init code ... */
  /*  PE initialization code after reset */
  /* MMCCTL1: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,NVMRES=0 */
  setReg8(MMCCTL1, 0x00U);              
  /* PKGCR: APICLKS7=0,??=0,??=0,??=0,??=0,PKGCR2=1,PKGCR1=1,PKGCR0=0 */
  setReg8(PKGCR, 0x06U);                
  /* DIRECT: DP15=0,DP14=0,DP13=0,DP12=0,DP11=0,DP10=0,DP9=0,DP8=0 */
  setReg8(DIRECT, 0x00U);               
  /* IVBR: IVB_ADDR=0xFF */
  setReg8(IVBR, 0xFFU);                 
  /* ECLKCTL: NECLK=1,NCLKX2=1,DIV16=0,EDIV4=0,EDIV3=0,EDIV2=0,EDIV1=0,EDIV0=0 */
  setReg8(ECLKCTL, 0xC0U);              
  /*  System clock initialization */
  /* CPMUPROT: ??=0,??=0,??=1,??=0,??=0,??=1,??=1,PROT=0 */
  setReg8(CPMUPROT, 0x26U);            /* Disable protection of clock configuration registers */ 
  /* CPMUCLKS: PSTP=0 */
  clrReg8Bits(CPMUCLKS, 0x40U);         
  /* CPMUCLKS: PLLSEL=1 */
  setReg8Bits(CPMUCLKS, 0x80U);        /* Enable the PLL to allow write to divider registers */ 
  /* CPMUSYNR: VCOFRQ1=0,VCOFRQ0=1,SYNDIV5=0,SYNDIV4=1,SYNDIV3=1,SYNDIV2=0,SYNDIV1=0,SYNDIV0=0 */
  setReg8(CPMUSYNR, 0x58U);            /* Set the multiplier register */ 
  /* CPMUPOSTDIV: ??=0,??=0,??=0,POSTDIV4=0,POSTDIV3=0,POSTDIV2=0,POSTDIV1=1,POSTDIV0=1 */
  setReg8(CPMUPOSTDIV, 0x03U);         /* Set the post divider register */ 
  /* CPMUPLL: ??=0,??=0,FM1=0,FM0=0,??=0,??=0,??=0,??=0 */
  setReg8(CPMUPLL, 0x00U);             /* Set the PLL frequency modulation */ 
  while(CPMUFLG_LOCK == 0U) {          /* Wait until the PLL is within the desired tolerance of the target frequency */
  }
  /* CPMUPROT: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,PROT=0 */
  setReg8(CPMUPROT, 0x00U);            /* Enable protection of clock configuration registers */ 
  /* CPMUCOP: RSBCK=0,WRTMASK=0 */
  clrReg8Bits(CPMUCOP, 0x60U);          
  /*** End of PE initialization code after reset ***/

  /*** !!! Here you can place your own code using property "User code after PE initialization" on the build options tab of the CPU component. !!! ***/

  /*lint -save  -e950 Disable MISRA rule (1.1) checking. */
  __asm("jmp _Startup");               /* Jump to C startup code */
  /*lint -restore Enable MISRA rule (1.1) checking. */
}

#pragma CODE_SEG DEFAULT
/*
** ===================================================================
**     Method      :  PE_low_level_init (component MC9S12G240_100)
**
**     Description :
**         Initializes components and provides common register 
**         initialization. The method is called automatically as a part 
**         of the application initialization code.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
void PE_low_level_init(void)
{
  /* Common initialization of the CPU registers */
  /* TSCR1: TEN=0,TSWAI=0,TSFRZ=0,TFFCA=0,PRNT=1,??=0,??=0,??=0 */
  setReg8(TSCR1, 0x08U);                
  /* OCPD: OCPD0=1 */
  setReg8Bits(OCPD, 0x01U);             
  /* PACTL: CLK1=0,CLK0=0 */
  clrReg8Bits(PACTL, 0x0CU);            
  /* OC7M: OC7M0=0 */
  clrReg8Bits(OC7M, 0x01U);             
  /* TIOS: IOS0=1 */
  setReg8Bits(TIOS, 0x01U);             
  /* TCTL2: OM0=0,OL0=0 */
  clrReg8Bits(TCTL2, 0x03U);            
  /* TTOV: TOV0=0 */
  clrReg8Bits(TTOV, 0x01U);             
  /* TSCR2: TOI=0,TCRE=0 */
  clrReg8Bits(TSCR2, 0x88U);            
  /* PTPSR: PTPS7=0,PTPS6=0,PTPS5=0,PTPS4=0,PTPS3=0,PTPS2=0,PTPS1=0,PTPS0=0 */
  setReg8(PTPSR, 0x00U);                
  /* TIE: C0I=0 */
  clrReg8Bits(TIE, 0x01U);              
  /* PTT: PTT7=0,PTT6=0,PTT5=0,PTT4=0 */
  clrReg8Bits(PTT, 0xF0U);              
  /* PERT: PERT7=0,PERT6=0,PERT5=0,PERT4=0 */
  clrReg8Bits(PERT, 0xF0U);             
  /* DDRT: DDRT7=1,DDRT6=1,DDRT5=1,DDRT4=1 */
  setReg8Bits(DDRT, 0xF0U);             
  /* CPMUINT: LOCKIE=0,OSCIE=0 */
  clrReg8Bits(CPMUINT, 0x12U);          
  /* CPMULVCTL: LVIE=0 */
  clrReg8Bits(CPMULVCTL, 0x02U);        
  /* IRQCR: IRQEN=0 */
  clrReg8Bits(IRQCR, 0x40U);            
  /* ### MC9S12G240_100 "Cpu" init code ... */
  /* ### McuLibConfig "MCUC1" init code ... */
  MCUC1_Init();
  /* ### Free running 16-bit counter "TickCntr1" init code ... */
  TickCntr1_Init();
  /* PEX_RTOS_INIT() is a macro should already have been called either from main()
     or Processor Expert startup code. So we don't call it here again. */
  /* PEX_RTOS_INIT(); */ /* ### FreeRTOS "FRTOS1" init code ... */
  /* ### BitIO "LEDpin1" init code ... */
  /* ### LED "LED1" init code ... */
  LED1_Init(); /* initialize LED driver */
  /* ### BitIO "LEDpin2" init code ... */
  /* ### LED "LED2" init code ... */
  LED2_Init(); /* initialize LED driver */
  /* ### BitIO "LEDpin3" init code ... */
  /* ### LED "LED3" init code ... */
  LED3_Init(); /* initialize LED driver */
  /* ### BitIO "LEDpin4" init code ... */
  /* ### LED "LED4" init code ... */
  LED4_Init(); /* initialize LED driver */
  __EI();                              /* Enable interrupts */
}

/*lint -save  -e950 Disable MISRA rule (1.1) checking. */
/* Initialization of the CPU registers in FLASH */
/*lint -restore Enable MISRA rule (1.1) checking. */

/* END Cpu. */

/*
** ###################################################################
**
**     This file was created by Processor Expert 3.03 [04.46]
**     for the Freescale HCS12 series of microcontrollers.
**
** ###################################################################
*/
