/*
 * Copyright (c) 2017, ARM Limited, All Rights Reserved
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the "License"); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#define COMPILE_WITH_UVISOR
#ifdef COMPILE_WITH_UVISOR
#include "uvisor-lib/uvisor-lib.h"
#endif
#include "mbed.h"

#ifdef COMPILE_WITH_UVISOR
/* Create ACLs for main box. */
#if defined(TARGET_K64F)
static const UvisorBoxAclItem g_main_acl[] = {
    {SIM,    sizeof(*SIM),    UVISOR_TACLDEF_PERIPH},
    {OSC,    sizeof(*OSC),    UVISOR_TACLDEF_PERIPH},
    {MCG,    sizeof(*MCG),    UVISOR_TACLDEF_PERIPH},
    {PORTA,  sizeof(*PORTA),  UVISOR_TACLDEF_PERIPH},
    {PORTB,  sizeof(*PORTB),  UVISOR_TACLDEF_PERIPH},
    {PORTC,  sizeof(*PORTC),  UVISOR_TACLDEF_PERIPH},
    {PORTD,  sizeof(*PORTD),  UVISOR_TACLDEF_PERIPH},
    {PORTE,  sizeof(*PORTE),  UVISOR_TACLDEF_PERIPH},
    {RTC,    sizeof(*RTC),    UVISOR_TACLDEF_PERIPH},
    {LPTMR0, sizeof(*LPTMR0), UVISOR_TACLDEF_PERIPH},
    {PIT,    sizeof(*PIT),    UVISOR_TACLDEF_PERIPH},
    {SMC,    sizeof(*SMC),    UVISOR_TACLDEF_PERIPH},
    {UART0,  sizeof(*UART0),  UVISOR_TACLDEF_PERIPH},
    {I2C0,   sizeof(*I2C0),   UVISOR_TACLDEF_PERIPH},
    {SPI0,   sizeof(*SPI0),   UVISOR_TACLDEF_PERIPH},
};
#else
#error "Hardware not supported: you need to define the peripheral ACL"
#endif


/* Enable uVisor. */
UVISOR_SET_MODE_ACL(UVISOR_ENABLED, g_main_acl);
  UVISOR_SET_PAGE_HEAP(8 * 1024, 5);

/* Targets with an ARMv7-M MPU needs this space adjustment to prevent a runtime
 * memory overflow error. The code below has been output directly by uVisor. */
#if defined(TARGET_EFM32GG_STK3700) || defined(TARGET_DISCO_F429ZI)
uint8_t __attribute__((section(".keep.uvisor.bss.boxes"), aligned(32))) __boxes_overhead[8064];
#endif

#endif // defined(COMPILE_WITH_UVISOR)

int main(void)
{
    printf("\r\n***** Hello, now I will wait *****\r\n");
    Thread::wait(100);
    printf("\r\n***** Done waiting, world *****\r\n");
    fflush(stdout);
    while(1);
    return 0;
}
