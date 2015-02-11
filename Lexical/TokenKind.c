#include "Lexical.h"





/// ���ݶ��岿��
/**	����������C���ԵĹؼ���***********************************************************************
*** ������Ϣ:
***		�ؼ��ְ����ֵ�˳������, ��26��, ����C99
*** ������Ϣ:
***		2013/8/17-11:57	-=>	����ע�͸�ʽ,
***		2013/8/17-12:05	-=>	sizeof���������Ϊ�ؼ��ִ洢
*************************************************************************************************/
const char keyword[MAX_KEYWORD_COUNT][20] =
{
    "keyword",                  // 0λ��ռλ��

	/// C���еĹؼ���[������]��Ϣ
    "auto",
    "bool", "break",
    "case", "char", "const", "continue",
    "default", "do", "double",
    "else", "enum", "extern",
    "float", "for",
    "goto",
	/*h*/
    "if", "inline", "int",
    /*j-k*/
    "long",
    /*m-n-o-p-q*/
    "register", "restrict", "return",
    "short", "signed", "sizeof", "static", "struct", "switch",
    "typedef",
	"union", "unsigned",
	"void", "volatile",
    "while",
    "_Bool", "_Complex", "_Imaginary",
    /*x-y-z*/
};


/**	����������C���ԵĹؼ���***********************************************************************
*** ������Ϣ:																					*
***		Ԥ����ָ�����Ϣ, ��13��													*
*** ������Ϣ:																					*
***		2013/8/21-10:26	-=>	����ע�͸�ʽ,														*
***		�汾0.4.0											*
*************************************************************************************************/
const char procom[MAX_PROCOM_COUNT][10] =
{
    "procom",           // 0λ��Ϊվλ����
    "",                 // �յ�Ԥ��������Ϣ
    "include", "line",
    "define", "undef",
    "if", "elif", "else",
    "ifdef", "ifndef", "endif",
    "error", "pragma", "import",
};


///	�������
/**	����������C���Եļ��������******************************************************************
***	������Ϣ:																					*
***		�������, Ϊȫ��������ṩ����,															*
***		�ʷ����������յ����ַ��������ݣ�															*
***		�ж����Ƿ����ڼ��������Ȼ���ٴӵ�ǰ�ַ���ʼ����һ�������ж��Ƿ�����ȫ�������			*
***	������Ϣ:																					*
***		2013/8/17-11:48	-=>	������ע����Ϣ�������˲���������ŵ�˳���Ա�֤��TokenKind�������		*
***    2013/8/21-12:13   -=> �޸���(), []��Ϊ�������, ��Ϊ�˷�ʽBUG, �����ڷֽ���У� ��Ϊ�ֽ��������
*************************************************************************************************/
const char operate[MAX_OPERATE_COUNT] =
{
'$',                                // oλ��ռλ��
'.', ',',
'+', '-', '*', '/', '%', '=',
'<', '>',
'|', '&', '!', '^',
'?', ':', //'(', ')', '[', ']',
};


/// ȫ�������
/**	����������C���Ե�ȫ���������******************************************************************
***	������Ϣ��																					*
***		�����C��׼���ܳ��ֵ�ȫ��																	*
***	������Ϣ��																					*
***    2013/8/21-12:13   -=> �޸���(), []��Ϊ�������, ��Ϊ�˷�ʽBUG, �����ڷֽ���У� ��Ϊ�ֽ��������
*************************************************************************************************/
const char allOperator[MAX_OPERATE_COUNT][4] =
{
"$",                                    // oλ��ռλ��
",",                                                                    // 15-level
"=", "+=", "-=", "*=", "/=", "%=", "|=", "^=", "&=", ">>=", "<<=",      // 14-level
"?", ":",                                                               // 13-level
"||",                                                                   // 12-level
"&&",                                                                   // 11-level
"|",                                                                    // 10-level
"^",                                                                    // 09-level
"&",                                                                    // 08-level
"==", "!=",                                                             // 07-level
">", ">=", "<", "<=",                                                   // 06-level
">>", "<<",                                                             // 05-level
"+", "-",                                                               // 04-level
"*", /*"**", "***", "****"*/"/", "%",                                     // 03-level
"!", "~", /*"-", -12*/ "++", "--", /** &,*,��type��, "sizeof",*/     // 02-level
/*"(", ")", "[", "]",*/ ".", "->",                                          // 01-level
"...",                                                                  // 000000000
};

/// ���
/**	����������C���Եķֽ���ŵ���Ϣ****************************************************************
***	������Ϣ��																					*
***		����һ��C��׼�����еķֽ��																*
***	������Ϣ��																					*
****	2013/8/17-12:03	-=>	������ע�͵ĸ�ʽ														*
***		2013/8/17-12:06	-=>	������' '�ո��ַ���Ϊ�ֽ���Ŵ洢										*
***    2013/8/21-12:13   -=> �޸���(), []��Ϊ�������, ��Ϊ�˷�ʽBUG, �����ڷֽ���У� ��Ϊ�ֽ��������
***********************************************************************************************/
const char separator[MAX_SEPARAROR_COUNT] =
{
	'$',                            // oλ��ռλ��
	' ',
	'(', ')', '[', ']',             //
	'{', '}',
	';',
	'#',
	'\'', '\"', '\\',
	'\n', '\t', '\r',
};

///**	�жϵ�ǰ���봮�ǲ���һ��ָ�����ͷ���***********************************************************
//***	Function	:	IsPoint
//***	Param		:	token[CHAR*]	�����������봮
//***	Return		:	[BOOL]			�����봮�������'**'�򷵻�true, ���򷵻�false
//***	Description	:	�жϵ�ǰ���봮token�Ƿ���***, ������ʶ����Ĵ���Ϣ��һ��ָ��
//***	Calls		:   NULL
//***	Called By	:	IsAllOperate	�����жϴ��ǲ����������ʱ���жϲ���Ϊ
//***									�ȿ���ǰ�����ַ��ǲ��Ǽ��������Ȼ������ȡһ��������
//***									���ǲ���һ������������ǿ��ܳ�������
//***									��ȡ�����Ĵ������ָ�����ʹ���Ҫ�����жϣ�
//***									Ȼ����ܿ��ǲ���һ��������š�
//***									���磺char **ptr, ptr������Ϊһ��ָ��, ������Ҫ�洢��
//***									����**�����������ֱ�ӽ���������Ŵ������������**���Ŷ�ʧ
//***	Version		:	0.3.8
//***	Warning		:	�ܹ�������ָ�����������������ޡ�
//*************************************************************************************************/
//int IsPoint(char *token)           // ��ȡ�������������
//{
//    int i = 0;
//    while(token[i] != '\0' && token[i] == '*')  // the point is define as anyone "*"
//    {
//        i++;
//    }
//
//    if(token[i] == '\0')
//    {
//        return i;           // return the count of the '*' in the token
//    }
//    else
//    {
//        return NOT_FIND;    // the token is not a pointer...
//    }
//}



/**	�жϵ�ǰ��������ǲ��Ƿֽ����*****************************************************************
***	Function	:	IsSeparator																	*
***	Param		:	now[CHAR]	�����������봮													*
***	Return		:	[INT]		��������������Ƿֽ�����򷵻���λ��,	���򷵻�NOT_FIND(-1)			*
***	Description	:	�жϵ�ǰ�ַ��ǲ��Ƿֽ���ţ����ǲ���separator[MAX_SEPARAROR]��������			*
***	Calls		:   NULL																		*
***	Called By	:																				*
***	Version		:	0.3.8																		*
***	Warning		:	�ѿո����ֽ���Ŵ���														*
***					���뱣֤�ֽ�������˳����ToekKind.h�еĶ���˳����ͬ�Ǹ�						*
*************************************************************************************************/
int IsSeparator(const char now)
{
    //int i;
    for(int i = 1; i < MAX_SEPARAROR_COUNT; i++)  //�������еķָ���
    {
        if(now == separator[i])    //�ָ�������-separator[i]
        {
            return i;
        }
    }
    return NOT_FIND;
}


/**	�жϵ�ǰ��������ǲ��Ǽ��������*************************************************************
***	Function	:	IsOperate																	*
***	Param		:	now[CHAR]	�����������봮													*
***	Return		:	[INT]		��������������Ǽ�������ŷ��򷵻���λ��,���򷵻�NOT_FIND(-1)	*
***	Description	:	�жϵ�ǰ�ַ��ǲ��Ǽ�����������ǲ���operate[MAX_OPERATE]��������				*
***	Calls		:   NULL																		*
***	Called By	:																				*
***	Version		:	0.3.8																		*
***	Warning		:																				*
*************************************************************************************************/
int IsOperate(const char now)
{
    for(int i = 1; i < MAX_OPERATE_COUNT; i++)
    {
      if(now == operate[i])
      {
            return i;
      }
    }
    return NOT_FIND;
}

/**	�жϵ�ǰ���봮�ǲ��Ƿ���C��׼���������********************************************************
*	Function	:	IsAllOperate
*	Param		:	token[CHAR*]�����������봮
*	Return		:	[INT]		��������������Ǽ�������ŷ��򷵻���λ��,���򷵻�NOT_FIND(-1)
*	Description	:	�жϵ�ǰ�ַ��ǲ��Ǽ�����������ǲ���allOperate[MAX_OPERATE]��������
*	Calls		:   NULL
*	Called By	:
*	Version	:	0.3.8
*				    ���뱣֤������ŵ�˳����TokenKind.h�еĶ���˳����ͬ
*                 ������ָ����������¶���
*                 char **str   -=> ** ��Ӧ DMUL_OPERATE
*                 char ***str   -=> *** ��Ӧ TMUL_OPERATE
*                 char ****str -=>  **** ��Ӧ fMUL_OPERATE
*                 ��ʱֻ֧������ָ�룬����Ϊ����ָ���ṩ��Ԥ��λ��
*************************************************************************************************/
int IsAllOperate(const char *token)
{
    int keyCode = NOT_FIND;
    for(int pos = 1; pos < MAX_OPERATE_COUNT; pos++)
    {
        if(strcmp(token, allOperator[pos]) == 0)
        {
            //printf("%s == %s %d\n", token, allOperator[pos], pos);
            keyCode = pos;
            break;
        }
    }

    return keyCode;
}



/** IsKeyword*****************************************************************
*   \brief  :�жϵ�ǰ�ַ��ǲ���C�ؼ��֣����ǲ���keyWord[MAX_KEYWORD]��������
*   \param  :	token[CHAR*]�����������봮
*   \return :	��������������ǹؼ����򷵻���λ��,���򷵻�NOT_FIND(-1)
*	\bug    :	���뱣֤�ؼ��ֵ�˳����TokenKind.h�еĶ���˳����ͬ
******************************************************************************/
int IsKeyword(const char *token)
{
    for(int pos = 1; pos < MAX_KEYWORD_COUNT; pos++)
    {
        if (strcmp(token, keyword[pos]) == 0)
        {
            #ifdef  LEXICAL_DEBUG_DEFINE
            printf("%s == %s, %d\n", token, keyword[pos], pos);
            #endif // LEXICAL_DEBUG_DEFINE


            return pos;
        }
    }

    return NOT_FIND;
}



/**	IsProCom*********************************************************************************
*	\brief	:	�жϵ�ǰ�ַ��ǲ���Ԥ����ָ��������ǲ���procom[MAX_OPERATE]��������
*	\param		:	token[CHAR*]	�����������봮
*	\return		:	[INT]		���������������Ԥ����ָ����򷵻���λ��,���򷵻�NOT_FIND(-1)
********************************************************************************************/
int IsProCom(const char *token)
{
    for(int i = 1; i < MAX_PROCOM_COUNT; i++)
    {
        if(strcmp(token, procom[i]) == 0)
        {
            return i;
        }
    }

    return NOT_FIND;
}






/**	�жϵ�ǰ���봮�ǲ��ǳ�����Ϣ*******************************************************************
***	Function	:	IsConstant
***	Param		:	str[CHAR*]�����������봮
***	Return		:	[INT]		��������������ǳ������򷵻���λ��,���򷵻�NOT_FIND(-1)
***	Description	:	�жϵ�ǰ���봮�ǲ��ǳ�����Ϣ
***	Calls		:   NULL
***	Called By	:
***	Version		:	0.3.8
***	Warning		:	���뱣֤�ؼ��ֵ�˳����TokenKind.h�еĶ���˳����ͬ
*************************************************************************************************/
TokenKind IsConstant(const char *str)
{
    int     i;              // ѭ���ַ�����ÿһλ
    int     count = 0;         // ���ڱ�ʶ��������С������Ŀ
    //int     flag = -1;           // ���ڱ�ʶ������[0]���Ǹ�����[1]

    #ifdef LEXICAL_DEBUG_DEFINE
    printf("���жϵĳ�����%s\n", str);
    PAUSE( );
    #endif // LEXICAL_DEBUG_DEFINE

    if(str[0] == '0' && (str[1]  == 'x' || str[1] == 'X'))          // �����ǰ���ݿ�����16������
    {
        i = 2;
        //flag = 0;           // ��������һ�����ͳ���
        while(IsHexDigit(str[i]) == true)          // ������ǰ�ַ���ÿһλ�Ƿ��Ƿ���Ҫ���16��������λ
        {
            i++;
        }
        if(str[i] == '\0')          // �����ɹ�����һ�����γ���
        {
            return INT_CONST;
        }
    }
    else if(str[0] == '0')
    {
        i = 1;
        //flag = 0;            // ��������һ�����ͳ���
        while(IsOctDigit(str[i]) == true)           // ������ǰ�ַ�����ÿһλ�Ƿ��Ƿ���Ҫ���8��������λ
        {
            i++;
        }
        if(str[i] == '\0')          // �����ɹ�����һ���˽��Ƴ���
        {
            return INT_CONST;
        }
    }

    i = 0;
    while(IsDigit(str[i]) == true || str[i] == '.')
    {
        if(str[i] == '.')           // ���㸡������С������Ŀ
        {
            count++;
        }
        i++;
    }

    if(count == 0 && str[i] == '\0')          // ���γ���û��һλС����
    {
        return INT_CONST;
    }
    else if(count == 1 && str[i] == '\0')     // ������ֻ��һλС����
    {
        return FLOAT_CONST;
    }
    else
                            // С������Ŀ���󣬶�������
    {
        return TOKEN_NULL;
    }
}
