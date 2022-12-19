#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ADC_int.h"
#include "ADC_private.h"
#include "ADC_config.h"
void ADC_VidInit(void)
{
	//AVCC WITH EXTERNAL CAPACITOR AT AREF PIN
	SET_BIT(ADMUX_Reg,ADMUX_REFS0);
	CLR_BIT(ADMUX_Reg,ADMUX_REFS1);

	// ADC Data Right Adjustment
	CLR_BIT(ADMUX_Reg,ADMUX_ADLAR);

	// Prescaler Configuration as 128
   ADCSRA_Reg &= 0b11111000 ;
 //ADCSRA_Reg |= PRE_SCALER_VALUE ;

	/*ADCSRA_Reg &= 0b11111000 ;
		SET_BIT(ADCSRA_Reg,ADCSRA_ADSP0);
		SET_BIT(ADCSRA_Reg,ADCSRA_ADSP1);
		SET_BIT(ADCSRA_Reg,ADCSRA_ADSP2);
		*/
// ENABLE ADC
		SET_BIT(ADCSRA_Reg,ADCSRA_ADEN);

}
u16 ADC_VidRead_ADC_ChannelSync(u8 copy_u8channel)
{
	ADMUX_Reg &= 0b11100000 ; // masking so after that u can or with 0
	ADMUX_Reg |= copy_u8channel ;
	/*start conversation */
	SET_BIT(ADCSRA_Reg, ADCSRA_ADSC) ;
	/* CHECH THAT CONVERSION IS COMPLETED */
	while (GET_BIT(ADCSRA_Reg ,ADCSRA_ADIF) ==0);
	/* CLEAR FLAG */
	SET_BIT(ADCSRA_Reg ,ADCSRA_ADIF);
	return ADCL_Reg ;
}










