#ifndef BIT_MATH_H
#define BIT_MATH_H

#define SET_BIT(REG,BIT_NUM)  REG|=1<<BIT_NUM

		/* Clear Bit */
#define CLR_BIT(REG,BIT_NUM)  REG&=~(1<<BIT_NUM)

		/* Toggle Bit */
#define TOGGLE_BIT(REG,BIT_NUM)  REG^=(1<<BIT_NUM)

		/* GET_BIT */
#define GET_BIT(REG,BIT_NUM)   ((REG>>BIT_NUM)&1)


#endif 
