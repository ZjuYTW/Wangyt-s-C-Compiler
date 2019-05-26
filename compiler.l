%{
    #include "y.tab.h"
    #include <cstdio>
    #include <cstdlib>
    #include <cstring>
    #include "ast.h"
    #include "Praser.h"
    #include <iostream>
    using namespace std;
    
    void count(void);
    void comment();
    int check_type();
    int column = 0;
    
%}

%option yylineno

D            [0-9]
L            [a-zA-Z_]
H            [a-fA-F0-9]
E            ([Ee][+-]?{D}+)
P           ([Pp][+-]?{D}+)
FS            (f|F|l|L)
IS          ((u|U)|(u|U)?(l|L|ll|LL)|(l|L|ll|LL)(u|U))

%%

"/*"            { comment();/*注释*/}
"//"[^\n]*      { /* consume //-comment */ }

"bool"            { count(); return(BOOL);    }
"int"            { count(); return(INT); }
"char"            { count(); return(CHAR); }
"double"        { count(); return(DOUBLE); }
"break"            { count(); return(BREAK); }
"case"            { count(); return(CASE); }
"continue"        { count(); return(CONTINUE); }
"do"            { count(); return(DO); }
"else"            { count(); return(ELSE); }
"for"            { count(); return(FOR); }
"goto"            { count(); return(GOTO); }
"if"            { count(); return(IF); }
"return"        { count(); return(RETURN); }
"switch"        { count(); return(SWITCH); }
"void"            { count(); return(VOID); }
"while"            { count();  return(WHILE); }
"true"            { count(); return(TRUE); }
"false"            { count();  return(FALSE); }

{L}({L}|{D})*     {count(); yylval.gt = create_ID(yylineno);return(check_type());/*IDENTIFIER*/ }

0[xX]{H}+{IS}?    { count(); yylval.gt = create_exp_tree(yylineno,3);return(CONSTANT_INT); /*16进制*/}
0[0-7]*{IS}?    { count(); yylval.gt = create_exp_tree(yylineno,3);return(CONSTANT_INT); /*8进制*/}
[1-9]{D}*{IS}?    { count(); yylval.gt = create_exp_tree(yylineno,3);return(CONSTANT_INT); /*10进制*/}

{D}+{E}{FS}?                { count(); yylval.gt = create_exp_tree(yylineno,3);    return(CONSTANT_DOUBLE); /*浮点数*/}
{D}*"."{D}+{E}?{FS}?        { count(); yylval.gt = create_exp_tree(yylineno,3);    return(CONSTANT_DOUBLE); /*浮点数*/}
{D}+"."{D}*{E}?{FS}?        { count(); yylval.gt = create_exo_tree(yylineno,3);    return(CONSTANT_DOUBLE); /*浮点数*/}
0[xX]{H}+{P}{FS}?            { count(); return(CONSTANT); }
0[xX]{H}*"."{H}+{P}?{FS}?   { count(); return(CONSTANT); }
0[xX]{H}+"."{H}*{P}?{FS}?   { count(); return(CONSTANT); }


">>="    { count(); return(RIGHT_ASSIGN); }
"<<="    { count(); return(LEFT_ASSIGN); }
"+="    { count();  return(ADD_ASSIGN); }
"-="    { count();  return(SUB_ASSIGN); }
"*="    { count();  return(MUL_ASSIGN); }
"/="    { count();  return(DIV_ASSIGN); }
"%="    { count();  return(MOD_ASSIGN); }
"&="    { count();  return(AND_ASSIGN); }
"^="    { count();  return(XOR_ASSIGN); }
"|="    { count(); return(OR_ASSIGN); }
">>"    { count(); return(RIGHT_OP); }
"<<"    { count(); return(LEFT_OP); }
"++"    { count(); return(INC_OP); }
"--"    { count(); return(DEC_OP); }
"->"    { count(); return(PTR_OP); }
"&&"    { count(); return(AND_OP); }
"||"    { count(); return(OR_OP); }
"<="    { count(); return(LE_OP); }
">="    { count(); return(GE_OP); }
"=="    { count(); return(EQ_OP); }
"!="    { count(); return(NE_OP); }
";"        { count(); return(';'); }
","        { count(); return(','); }
":"        { count(); return(':'); }
"="        { count(); return('='); }
"["        { count(); return('['); }
"]"        { count(); return(']'); }
"."        { count(); return('.'); }
"&"        { count(); return('&'); }
"!"        { count(); return('!'); }
"~"        { count(); return('~'); }
"-"        { count(); return('-'); }
"+"        { count(); return('+'); }
"*"        { count(); return('*'); }
"/"        { count(); return('/'); }
"%"        { count(); return('%'); }
"<"        { count(); return('<'); }
">"        { count(); return('>'); }
"^"        { count(); return('^'); }
"|"        { count(); return('|'); }
"?"        { count(); return('?'); }
"{"        { count(); return('{'); }
"}"        { count(); return('}'); }
"("        { count(); return('('); }
")"        { count(); return(')'); }

[\t\v\n\f ]        { count();}
.            { /* Add code to complain about unmatched characters */ }

%%


int yywrap() {
    return 1;
}


void comment() {
    column = 0;
    char c, prev = 0;
    
    while (cin >> c)      /* (EOF maps to 0) */
    {
        if (c == '/' && prev == '*')
        return;
        prev = c;
    }
    printf("unterminated comment");
}



void count(void)
{
    int i;
    
    for (i = 0; yytext[i] != '\0'; i++)
    if (yytext[i] == '\n')
    column = 0;
    else if (yytext[i] == '\t')
    column += 4 - (column % 4);
    else
    column++;
    ECHO;
}


int check_type() {
    /*
     * pseudo code --- this is what it should check
     *
     *    if (yytext == type_name)
     *        return TYPE_NAME;
     *
     *    return IDENTIFIER;
     */
    
    /*
     *    it actually will only return IDENTIFIER
     */
    
    return IDENTIFIER;
}
