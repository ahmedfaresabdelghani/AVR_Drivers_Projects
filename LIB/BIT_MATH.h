#ifndef BIT_MATH_H
#define BIT_MATH_H


#define		SET_BIT(REG,BIT)		(REG|=(1<<BIT))
#define		CLEAR_BIT(REG,BIT)		(REG&=~(1<<BIT))
#define		GET_BIT(REG,BIT)		((REG >> BIT) & 0x01)
#define     TOOGLE_BIT(VAR,BIT)    (VAR ^=(1<<BIT))



#endif
