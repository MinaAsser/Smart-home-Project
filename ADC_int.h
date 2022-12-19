#ifndef ADC_INT_H
#define ADC_INT_H



#define ADMUX_REFS0       6
#define ADMUX_REFS1       7
#define ADMUX_ADLAR       5
typedef enum
{
	MUX_0 ,
	MUX_1 ,
	MUX_2 ,
	MUX_3 ,
	MUX_4
}et_Mux;
typedef enum {

	 ADC_0 ,
	 ADC_1,
	 ADC_2,
	 ADC_3,
	 ADC_4,
	 ADC_5,
	 ADC_6,
	 ADC_7


}et_channel;
#define ADCSRA_ADEN       7
#define ADCSRA_ADSC       6
#define ADCSRA_ATE        5
#define ADCSRA_ADIF       4
#define ADCSRA_ADIE       3
#define ADCSRA_ADSP2      2
#define ADCSRA_ADSP1      1
#define ADCSRA_ADSP0      0



void ADC_VidInit(void);
u16 ADC_VidRead_ADC_ChannelSync(u8 copy_u8channel);


















#endif
