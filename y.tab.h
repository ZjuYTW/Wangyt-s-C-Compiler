/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     IDENTIFIER = 258,
     CONSTANT = 259,
     STRING_LITERAL = 260,
     SIZEOF = 261,
     CONSTANT_INT = 262,
     CONSTANT_DOUBLE = 263,
     TRUE = 264,
     FALSE = 265,
     CHAR = 266,
     INT = 267,
     DOUBLE = 268,
     VOID = 269,
     BOOL = 270,
     SUB_ASSIGN = 271,
     LEFT_ASSIGN = 272,
     RIGHT_ASSIGN = 273,
     AND_ASSIGN = 274,
     MUL_ASSIGN = 275,
     DIV_ASSIGN = 276,
     MOD_ASSIGN = 277,
     ADD_ASSIGN = 278,
     XOR_ASSIGN = 279,
     OR_ASSIGN = 280,
     TYPE_NAME = 281,
     CASE = 282,
     IF = 283,
     ELSE = 284,
     SWITCH = 285,
     WHILE = 286,
     DO = 287,
     FOR = 288,
     GOTO = 289,
     CONTINUE = 290,
     BREAK = 291,
     RETURN = 292,
     PTR_OP = 293,
     INC_OP = 294,
     DEC_OP = 295,
     LEFT_OP = 296,
     RIGHT_OP = 297,
     LE_OP = 298,
     GE_OP = 299,
     EQ_OP = 300,
     NE_OP = 301,
     AND_OP = 302,
     OR_OP = 303,
     LOWER_THAN_ELSE = 304
   };
#endif
/* Tokens.  */
#define IDENTIFIER 258
#define CONSTANT 259
#define STRING_LITERAL 260
#define SIZEOF 261
#define CONSTANT_INT 262
#define CONSTANT_DOUBLE 263
#define TRUE 264
#define FALSE 265
#define CHAR 266
#define INT 267
#define DOUBLE 268
#define VOID 269
#define BOOL 270
#define SUB_ASSIGN 271
#define LEFT_ASSIGN 272
#define RIGHT_ASSIGN 273
#define AND_ASSIGN 274
#define MUL_ASSIGN 275
#define DIV_ASSIGN 276
#define MOD_ASSIGN 277
#define ADD_ASSIGN 278
#define XOR_ASSIGN 279
#define OR_ASSIGN 280
#define TYPE_NAME 281
#define CASE 282
#define IF 283
#define ELSE 284
#define SWITCH 285
#define WHILE 286
#define DO 287
#define FOR 288
#define GOTO 289
#define CONTINUE 290
#define BREAK 291
#define RETURN 292
#define PTR_OP 293
#define INC_OP 294
#define DEC_OP 295
#define LEFT_OP 296
#define RIGHT_OP 297
#define LE_OP 298
#define GE_OP 299
#define EQ_OP 300
#define NE_OP 301
#define AND_OP 302
#define OR_OP 303
#define LOWER_THAN_ELSE 304




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 21 "compiler.y"
{
    struct root_Node* rootN;
    struct func_Node* funcN;
    struct ID_Node* IDN;
    struct declaration_Node* declarationN;
    struct declarator_Node* declaratorN;
    struct initializer_Node* initN;
    struct initial_list* initl;
    struct designator* design;
    struct param_Node* paraN;
    struct stat_Node* statN;
    struct block_item* block;
    struct exp_Node* expN;
    enum type_specifer_kind typekind;
    enum assign_kind assignkind;
}
/* Line 1529 of yacc.c.  */
#line 164 "y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

