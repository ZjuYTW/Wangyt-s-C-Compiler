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
     CASE = 271,
     IF = 272,
     ELSE = 273,
     SWITCH = 274,
     WHILE = 275,
     DO = 276,
     FOR = 277,
     GOTO = 278,
     CONTINUE = 279,
     BREAK = 280,
     RETURN = 281,
     PTR_OP = 282,
     INC_OP = 283,
     DEC_OP = 284,
     LEFT_OP = 285,
     RIGHT_OP = 286,
     LE_OP = 287,
     GE_OP = 288,
     EQ_OP = 289,
     NE_OP = 290,
     AND_OP = 291,
     OR_OP = 292,
     SUB_ASSIGN = 293,
     LEFT_ASSIGN = 294,
     RIGHT_ASSIGN = 295,
     AND_ASSIGN = 296,
     MUL_ASSIGN = 297,
     DIV_ASSIGN = 298,
     MOD_ASSIGN = 299,
     ADD_ASSIGN = 300,
     XOR_ASSIGN = 301,
     OR_ASSIGN = 302,
     TYPE_NAME = 303,
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
#define CASE 271
#define IF 272
#define ELSE 273
#define SWITCH 274
#define WHILE 275
#define DO 276
#define FOR 277
#define GOTO 278
#define CONTINUE 279
#define BREAK 280
#define RETURN 281
#define PTR_OP 282
#define INC_OP 283
#define DEC_OP 284
#define LEFT_OP 285
#define RIGHT_OP 286
#define LE_OP 287
#define GE_OP 288
#define EQ_OP 289
#define NE_OP 290
#define AND_OP 291
#define OR_OP 292
#define SUB_ASSIGN 293
#define LEFT_ASSIGN 294
#define RIGHT_ASSIGN 295
#define AND_ASSIGN 296
#define MUL_ASSIGN 297
#define DIV_ASSIGN 298
#define MOD_ASSIGN 299
#define ADD_ASSIGN 300
#define XOR_ASSIGN 301
#define OR_ASSIGN 302
#define TYPE_NAME 303
#define LOWER_THAN_ELSE 304




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
#include "enums_type.h"
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
    enum type_specifier_kind typekind;
    enum assign_kind assignkind;
    enum unary_kind arykind;
}
/* Line 1529 of yacc.c.  */
#line 165 "y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

