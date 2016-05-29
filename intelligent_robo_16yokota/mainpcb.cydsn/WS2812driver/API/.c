/* ========================================
 * File Name: `$INSTANCE_NAME`.c  
 * Version 1.0
 * Copyright betaEncoder, 2014
 * All Rights Reserved
 * This software is released under the MIT License, see LICENSE.txt.
 * ========================================
*/

#include <cytypes.h>
#include <`$INSTANCE_NAME`.h>

/*******************************************************************************
* Function Name: `$INSTANCE_NAME`_write_byte
********************************************************************************
*
* Summary:
*  Write a new value to the FIFO F0 or F1 in datapath.
*  Usually, private function.
*
* Parameters:  
*  buff:  The value to be written to the FIFO.
*  fifo:  The number of FIFO.
*
* Return: 
*  None 
*  
*******************************************************************************/
inline void `$INSTANCE_NAME`_write_byte(unsigned char buff, unsigned char fifo){
    if(fifo==0){
        CY_SET_REG8(`$INSTANCE_NAME`_shifter_u0__F0_REG, buff);
    }else{
        CY_SET_REG8(`$INSTANCE_NAME`_shifter_u0__F1_REG, buff);
    }
}

/*******************************************************************************
* Function Name: Pin_1_Write
********************************************************************************
*
* Summary:
*  Write a data array to the fifo.  
*
* Parameters:  
*  *buff:  The pointer to data array.
*  len :   The length of the array to be written.
*          Length MUST be less than 10.
*
* Return: 
*  None 
*  
*******************************************************************************/
void `$INSTANCE_NAME`_write2fifo(unsigned char* buff, unsigned char len){
    unsigned char i;
    for(i=0;i<len;i++){
        if(i<5){
            `$INSTANCE_NAME`_write_byte(buff[i], FIFO_F0);
        }else{
            `$INSTANCE_NAME`_write_byte(buff[i], FIFO_F1);
        }
    }
}
/* [] END OF FILE */
