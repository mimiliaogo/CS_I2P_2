#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
print error message.
because it uses some special variable, use it carefully.
**/
#define error(fmt, ...) \
printf("**********************************\n"); \
printf("ERROR at '%s'\n => ", input); \
printf(fmt, __VA_ARGS__); \
printf("**********************************\n");

enum code
{
	MOV,ADD,SUB,MUL,DIV,EXIT,AND,OR,XOR
};

enum op_type
{
	REG,CONST,ADDR
};

typedef struct INST
{
	enum code opcode;

	enum op_type op1_type;
	int op1_value;

	enum op_type op2_type;
	int op2_value;

} INST;

void print(const INST *i)
{
	switch(i->opcode)
	{
	case MOV:  printf("MOV  |"); break;
	case ADD:  printf("ADD  |"); break;
	case SUB:  printf("SUB  |"); break;
	case MUL:  printf("MUL  |"); break;
	case DIV:  printf("DIV  |"); break;
	case EXIT: printf("EXIT |"); break;
	case AND:  printf("AND  |"); break;
	case OR:   printf("OR   |"); break;
	case XOR:  printf("XOR  |"); break;
	}

	switch(i->op1_type)
	{
	case REG:   printf(" REG  : %-4d |",i->op1_value); break;
	case CONST: printf(" CONST: %-4d |",i->op1_value); break;
	case ADDR:  printf(" ADDR : %-4d |",i->op1_value); break;
	}

	if(i->opcode!=EXIT)
		switch(i->op2_type)
		{
		case REG:   printf(" REG  : %-4d |",i->op2_value); break;
		case CONST: printf(" CONST: %-4d |",i->op2_value); break;
		case ADDR:  printf(" ADDR : %-4d |",i->op2_value); break;
		}
	else
		printf("             |");
	switch(i->opcode)
	{
	case MOV:
		if(i->op1_type==REG&&(i->op2_type==REG||i->op2_type==CONST))
		{
			printf(" 10cc   |\n");
			break;
		}
		if((i->op1_type==REG && i->op2_type==ADDR)||(i->op1_type==ADDR && i->op2_type==REG))
		{
			printf(" 200cc  |\n");
			break;
		}
	case ADD:  printf(" 10cc   |\n"); break;
	case SUB:  printf(" 10cc   |\n"); break;
	case MUL:  printf(" 30cc   |\n"); break;
	case DIV:  printf(" 50cc   |\n"); break;
	case EXIT: printf(" 20cc   |\n"); break;
	case AND:  printf(" 10cc   |\n"); break;
	case OR:   printf(" 10cc   |\n"); break;
	case XOR:  printf(" 10cc   |\n"); break;
	}
}

/// check the op is register or not
int readREG(const char *op,enum op_type *op_t,int *op_v)
{
	if(strlen(op)>=2&&op[0]=='r')
	{
		if(op[1]>='0' && op[1]<='7')
		{
			*op_t=REG;
			*op_v=op[1]-'0';
			return 1;
		}
		return -1;
	}
	return 0;
}

/// check the op is constant or not
int readCONST(const char *op,enum op_type *op_t,int *op_v)
{
	int i;
	for(i=(op[0]=='-'?1:0); i<strlen(op)&&isdigit(op[i]);++i)
		;
	if(i==strlen(op))
	{
		*op_t=CONST;
		*op_v=atoi(op);
		return 1;
	}
	return 0;
}

int readADDR(const char *op,enum op_type *op_t,int *op_v)
{
	int i;

	if(op[0]=='[' && op[strlen(op)-1]==']')
	{
		for(i=1; i<strlen(op)-1&&isdigit(op[i]);++i)
			;

		if(i==strlen(op)-1)
		{
			if(atoi(op+1)%4==0)
			{
				*op_t=ADDR;
				*op_v=atoi(op+1);
				return 1;
			}
			return -2;
		}
		return  -1;
	}
	return 0;
}

int readOP(const char *input,char *op,enum op_type *op_t,int *op_v)
{
	/// check op type and read its value,
	/// if success return 1, else return 0

	switch(readREG(op,op_t,op_v))
	{
	case -1: /// REGISTER out of range
		error("register out of range: '%s'\n",op);
		return 0;
	case 1:  /// op is a REGISTER
		return 1;
	case 0:  /// op is not a REGISTER
		break;
	}

	switch(readADDR(op,op_t,op_v))
	{
	case -1: /// ADDRESS out of range
		error("address out of range: '%s'\n",op);
		return 0;
	case -2: /// ADDRESS out of range
		error("address must be multiple of 4 : '%s'\n",op);
		return 0;
	case 1:  /// op is a ADDRESS
		return 1;
	case 0:  /// op is not a ADDRESS
		break;
	}

	switch(readCONST(op,op_t,op_v))
	{
	case 0:  /// op is not a CONSTANT
		error("unknown operand type : '%s'\n",op);
		break;
	case 1:  /// op is a CONSTANT
		return 1;
	}
	return 0;
}

/**
read input from stdin.

return:
 1 : success
 2 : illegal instruction
-1 : input EOF
**/
int readInst(INST **inst)
{
	const char *tok=" ";
	char *chr,*op;
	char input[32]="",decode[32]="";
	if(fgets(input,31,stdin)==NULL||strlen(input)<=3)
		return -1;
	else
	{
		/// replace newline to EOF, if newline exist
		if(input[strlen(input)-1]=='\n')
			input[strlen(input)-1]='\0';

		strcpy(decode,input);

		/// remove ',', if it exist
		chr=strchr(decode,',');
		if(chr!=NULL)
			while(*chr!='\0')
			{
				*chr=*(chr+1);
				++chr;
			}
		op=strtok(decode,tok);
	}

	enum code opcode;
	/// read opcode
	if(strcmp(op,"MOV")==0) opcode=MOV;
	else if(strcmp(op,"ADD")==0) opcode=ADD;
	else if(strcmp(op,"SUB")==0) opcode=SUB;
	else if(strcmp(op,"MUL")==0) opcode=MUL;
	else if(strcmp(op,"DIV")==0) opcode=DIV;
	else if(strcmp(op,"EXIT")==0) opcode=EXIT;
	else if(strcmp(op,"AND")==0) opcode=AND;
	else if(strcmp(op,"OR")==0) opcode=OR;
	else if(strcmp(op,"XOR")==0) opcode=XOR;
	else
	{
		error("un-define opcode: '%s'\n",op);
		return 2;
	}

	enum op_type op1_t;
	int op1_v;
	/// read op1
	op=strtok(NULL,tok);
	if(!readOP(input,op,&op1_t,&op1_v))
		return 2;

	enum op_type op2_t;
	int op2_v;
	/// read op2 except EXIT
	if(opcode!=EXIT)
	{
		op=strtok(NULL,tok);
		if(!readOP(input,op,&op2_t,&op2_v))
			return 2;
	}
	else
	{
		op2_t=CONST;
		op2_v=0;
	}

	/// According to opcode, check op1 and op2
	switch(opcode)
	{
	case MOV:
		if(op1_t==ADDR && op2_t!=REG)
		{
			error("%s\n","At MOV, when op1 is ADDR, op2 is only REG");
			return 2;
		}
		if(op1_t==CONST)
		{
			error("%s\n","op1 of MOV is REG or ADDR"); return 2;
		}
		break;

	case ADD:
		if(op1_t!=REG)
		{
			error("%s\n","op1 of ADD is only REG"); return 2;
		}
		if(op2_t!=REG)
		{
			error("%s\n","op2 of ADD is only REG"); return 2;
		}
		break;

	case SUB:
		if(op1_t!=REG)
		{
			error("%s\n","op1 of SUB is only REG"); return 2;
		}
		if(op2_t!=REG)
		{
			error("%s\n","op2 of SUB is only REG"); return 2;
		}
		break;

	case MUL:
		if(op1_t!=REG)
		{
			error("%s\n","op1 of MUL is only REG"); return 2;
		}
		if(op2_t!=REG)
		{
			error("%s\n","op2 of MUL is only REG"); return 2;
		}
		break;

	case DIV:
		if(op1_t!=REG)
		{
			error("%s\n","op1 of DIV is only REG"); return 2;
		}
		if(op2_t!=REG)
		{
			error("%s\n","op2 of DIV is only REG"); return 2;
		}
		break;

	case AND:
		if(op1_t!=REG)
		{
			error("%s\n","op1 of AND is only REG"); return 2;
		}
		if(op2_t!=REG)
		{
			error("%s\n","op2 of AND is only REG"); return 2;
		}
		break;

	case OR:
		if(op1_t!=REG)
		{
			error("%s\n","op1 of OR is only REG"); return 2;
		}
		if(op2_t!=REG)
		{
			error("%s\n","op2 of OR is only REG"); return 2;
		}
		break;

	case XOR:
		if(op1_t!=REG)
		{
			error("%s\n","op1 of XOR is only REG"); return 2;
		}
		if(op2_t!=REG)
		{
			error("%s\n","op2 of XOR is only REG"); return 2;
		}
		break;

	case EXIT:
		if(op1_t!=CONST||(op1_v!=1&&op1_v!=0))
		{
			error("%s\n","op1 of EXIT is constant 1 or 0");
			return 2;
		}
	}

	(*inst)=(INST*)malloc(sizeof(INST));
	(*inst)->opcode=opcode;
	(*inst)->op1_type=op1_t;
	(*inst)->op2_type=op2_t;
	(*inst)->op1_value=op1_v;
	(*inst)->op2_value=op2_v;

	//    print(*inst);

	return 1;
}

int main(int argc,char **argv)
{
	/// comment here to read input from stander input or file
	/// comment here to read input from stander input or file
	/// comment here to read input from stander input or file
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	INST *inst;
	int r[8],state;
	int mem[64]={0};
	int i;
	for(i=1;i!=argc;++i)
		mem[i-1]=atoi(argv[i]);
	state=1;
	int totalClock=0;

	while(state>0)
	{
		if((state=readInst(&inst))!=1)
			continue;
		print(inst);
		switch(inst->opcode)
		{
		case MOV:
			if(inst->op1_type==REG)
				switch(inst->op2_type)
				{
				case REG:   r[inst->op1_value]=r[inst->op2_value]; totalClock+=10; break;
				case CONST: r[inst->op1_value]=inst->op2_value; totalClock+=10; break;
				case ADDR:   r[inst->op1_value]=mem[inst->op2_value/4]; totalClock+=200; break;
				}
			else
			{
				mem[inst->op1_value/4]=r[inst->op2_value];
				totalClock+=200;
			}
			break;
		case ADD:
			r[inst->op1_value]+=r[inst->op2_value];
			totalClock+=10;
			break;
		case SUB:
			r[inst->op1_value]-=r[inst->op2_value];
			totalClock+=10;
			break;
		case MUL:
			r[inst->op1_value]*=r[inst->op2_value];
			totalClock+=30;
			break;
		case DIV:
			if(r[inst->op2_value]==0)
			{
				printf("**********************************\n");
				printf("ERROR divisor is not equal to 0\n");
				printf("**********************************\n");
			}
			else
				r[inst->op1_value]/=r[inst->op2_value];
			totalClock+=50;
			break;
		case AND:
			r[inst->op1_value]&=r[inst->op2_value];
			totalClock+=10;
			break;
		case OR:
			r[inst->op1_value]|=r[inst->op2_value];
			totalClock+=10;
			break;
		case XOR:
			r[inst->op1_value]^=r[inst->op2_value];
			totalClock+=10;
			break;
		case EXIT:
			printf("-------------------------------------------\n");
			if(inst->op1_value==0)
				printf("exit normally\n");
			else
				printf("the expression cannot be evaluated\n");
			state=0;
			totalClock+=20;
			break;
		}
		free(inst);
	}

	if(state!=0)
	{
		printf("**********************************\n");
		printf("ERROR ending without EXIT\n");
		printf("**********************************\n");
	}

	printf("\n");
	for(i=0;i!=3;++i)
		printf("r[%d] = %d\n",i,r[i]);
	printf("Total clock cycles are %d\n",totalClock);

	return 0;
}
